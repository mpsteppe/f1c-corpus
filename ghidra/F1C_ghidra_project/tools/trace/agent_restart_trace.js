// Trace Y-press restart — hook input dispatcher + transitions
var startTime = Date.now();

function hook(addr, name) {
    try {
        Interceptor.attach(ptr(addr), {
            onEnter: function(args) {
                var e = Date.now() - startTime;
                console.log('+' + e + 'ms ENTER ' + name + ' args=' + args[0] + ',' + args[1]);
            },
            onLeave: function(retval) {
                console.log('         LEAVE ' + name + ' ret=' + retval);
            }
        });
        console.log('Hooked: ' + name);
    } catch(e) { console.log('FAIL: ' + name); }
}

// Input/key dispatcher called by sub_4A0FD0
hook('0x00485B90', 'InputDispatch_485B90');
// Menu transition when hotkey triggers restart
hook('0x00404F30', 'MainMenuTransition_404F30');
// State transition
hook('0x004EF5A0', 'SessionStateTransition_4EF5A0');
// Called when restart gate returns 4
hook('0x0042BC10', 'ScoringGateCheck_42BC10');

// Poll globals at 100ms
var globs = {
    GameState:      {a: ptr('0x007C569C'), s: 4, l: 0},
    RestartFlag:    {a: ptr('0x007CE25E'), s: 1, l: 0},
    PausedFlag:     {a: ptr('0x007CE254'), s: 1, l: 0},
};
for (var k in globs) { var g = globs[k]; g.l = g.s === 1 ? g.a.readU8() : g.a.readU32(); }
console.log('State: GS=' + globs.GameState.l + ' RF=' + globs.RestartFlag.l + ' Paused=' + globs.PausedFlag.l);

setInterval(function() {
    for (var k in globs) {
        var g = globs[k];
        var v = g.s === 1 ? g.a.readU8() : g.a.readU32();
        if (v !== g.l) {
            console.log('*** ' + k + ': ' + g.l + ' -> ' + v);
            g.l = v;
        }
    }
}, 100);

console.log('READY — Press Y in-game to restart race');
