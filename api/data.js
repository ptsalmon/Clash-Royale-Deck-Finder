const { fstat } = require('fs')
const fs = require('fs')
const { MIN_VALUE } = require('long')
const { syncBuiltinESMExports } = require('module')
const request = require('request')
const { pathToFileURL } = require('url')
const key = "eyJ0eXAiOiJKV1QiLCJhbGciOiJIUzUxMiIsImtpZCI6IjI4YTMxOGY3LTAwMDAtYTFlYi03ZmExLTJjNzQzM2M2Y2NhNSJ9.eyJpc3MiOiJzdXBlcmNlbGwiLCJhdWQiOiJzdXBlcmNlbGw6Z2FtZWFwaSIsImp0aSI6ImE4YmIyN2Y1LWYxMzgtNGU1Ni1iZjYyLTA1MmNmNTk3MTA4YSIsImlhdCI6MTY1MDMyMDA2Niwic3ViIjoiZGV2ZWxvcGVyL2IwNjA0OTAzLWQzMjItYmZlOC00NjcwLTA1NDkwN2MwZjI0MiIsInNjb3BlcyI6WyJyb3lhbGUiXSwibGltaXRzIjpbeyJ0aWVyIjoiZGV2ZWxvcGVyL3NpbHZlciIsInR5cGUiOiJ0aHJvdHRsaW5nIn0seyJjaWRycyI6WyIxMjguMjI3LjEzMC43OSJdLCJ0eXBlIjoiY2xpZW50In1dfQ.f7M7ju7TagdNMShN-p0Fkd-yrlNUP_VcoCdt6LT7RvA8ef1VfFtXcfrqVXpoqNopYtWATttQhn9aBNKcL5H_Ag"
base = "https://api.clashroyale.com/v1/"

function sleep (time) {
    return new Promise((resolve) => setTimeout(resolve, time));
}

const write = (stream, text) => {
    return new Promise( async (res, rej) => {
        stream.write(text, "utf8", () => res())
    })
}
getWinner = game => game.team[0].crowns > game.opponent[0].crowns ? game.team[0].tag : game.opponent[0].tag;

function topClans() {
    request({
        url: base + "clans?minScore=60000&limit=500",
        json: true,
        'auth': {
            "bearer": key
        }
    }, (err, res, body) => {
        stuff = body.items
        console.log(stuff.length)
        clans = []
        stuff.forEach(clan => {
            clans.push(clan.tag)
        })

        x = JSON.stringify(clans)
        fs.writeFileSync("clans.cr", x, "utf-8")
    })
}

async function iterateClans() {
    clans = await fs.readFileSync("./clans.cr")
    clans = await JSON.parse(clans)
    n = 0
    a = -1
    players = []
    clans.forEach(async clan => {
        n++
        if (n % 5 == 0)
            a++
        setTimeout(() => {
            clan = clan.replace("#", "%23")
            request({
                url: base + "clans/" + clan,
                json:true,
                "auth": {
                    "bearer": key
                }
            }, (err, res, body) => {
                if (!err && res.statusCode == 200) {
                    members = body.memberList
                    members.forEach(member => {
                        players.push(member.tag)
                        console.log(member.tag)
                    })
                }
                else {
                    for (let i = 0; i < 50; i++) console.log("=")
                    console.log("error")
                    for (let i =0; i < 50; i++) console.log("=")
                    console.log("\n")
                    console.log(err)
                    console.log("status code: " + res.statusCode)
                }
            })
        }, a * 1500)
    })
    sleep(a * 1500 + 10 * 1000).then(() => {
        x = JSON.stringify(players)
        //fs.writeFileSync("players.cr", x, "utf-8")
        console.log("done")
    })
}

async function iteratePlayers() {
    players = await fs.readFileSync("./players.cr")
    players = await JSON.parse(players)
    battles = new Map()
    console.log("start")
    ply = []
    for (let n = 0; n < 5000; n++) {
        ply.push(players[n]);
    }
    n = 0
    a = -1
    ply.forEach(async player => {
        n++
        if (n % 5 == 0)
            a++
        setTimeout(() => {
            player = player.replace("#", "%23")
            request({
                url: base + "players/" + player + "/battlelog",
                json: true,
                "auth": {
                    "bearer": key
                }
            }, (err, res, body) => {
                if (!err && res.statusCode == 200) {
                    bats = body.filter(battle => battle.type == "PvP")
                    bats.forEach(battle => {
                        myCards = battle.team[0].cards.map(card => card.name).sort()
                        theirCards = battle.opponent[0].cards.map(card => card.name).sort()
                        output = {
                            "id": battle.battleTime,
                            "setup": [[battle.team[0].tag, myCards], [battle.opponent[0].tag, theirCards]],
                            "winner": getWinner(battle)
                        }
                        h = [battle.team[0].tag, battle.opponent[0].tag].sort()
                        battles.set(output["id"] + "," + h[0] + "," + h[1], output)
                    })
                }
                else {
                    console.log("error at n=" + n)
                }
            })
        }, a * 2000)
    })
    sleep(a * 2000 + 5 * 1000).then(() => {
        x = []
        for (let [key, value] of battles) {
            x.push(value)
        }
        p = JSON.stringify(x)
        fs.writeFileSync("output.cr", p, "utf-8")
        console.log("done")
    })

}

function formatData() {
    battles = fs.readFileSync("output.cr")
    battles = JSON.parse(battles)

    fs.writeFileSync("data.txt", "", "utf8")
    battles.forEach(battle => {
        text = "" + battle.id + " " + battle.setup[0][0] + " " + battle.setup[1][0] + " " + battle.winner
        text += " [" + battle.setup[0][1].join(",") + "] [" + battle.setup[1][1].join(",") + "]"
        fs.appendFileSync("data.txt", text + "\n")
    })
}

function getCardList() {
    battles = fs.readFileSync("output.cr")
    battles = JSON.parse(battles)

    cards = new Set()

    battles.forEach(battle => {
        battle.setup[0][1].forEach(card => {
            cards.add(card)
        })
        battle.setup[1][1].forEach(card => {
            cards.add(card)
        })
    })

    console.log(cards)
    console.log(cards.size)
}
