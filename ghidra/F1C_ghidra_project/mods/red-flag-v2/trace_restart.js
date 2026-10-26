/*
 * trace_restart.js — Trace a specific car through retirement AND restart
 *
 * Watches ALL interesting offsets on one car (by index) at high frequency.
 * Run during: crash -> retirement -> red flag -> restart
 *
 * Usage:
 *   frida -p <PID> -l trace_restart.js
 *   Then type: watch(N) to start watching car index N
 *   Type: dump() to dump current state of watched car
 *   Type: scan() to find which car index is Hakkinen (by checking retired state)
 */

var VehiclePtrArray = ptr(0x007C54F0);
var VehicleCount = ptr(0x005C329C);
var PlayerVehiclePtr = ptr(0x007C54E8);
var GameState = ptr(0x007C569C);

var OFFSETS = {
    // Physics body
    PhysX:        { off: 0x001C, type: 'f', threshold: 50.0 },
    PhysY:        { off: 0x0020, type: 'f', threshold: 5.0 },
    PhysZ:        { off: 0x0024, type: 'f', threshold: 50.0 },

    // Scene graph node (vehicle+0x0C base)
    ScenePtr:     { off: 0x000C, type: 'i', threshold: 0 },  // ptr to scene subobj
    RenderX:      { off: 0x34F0, type: 'f', threshold: 50.0 },
    RenderY:      { off: 0x34F4, type: 'f', threshold: 5.0 },
    RenderZ:      { off: 0x34F8, type: 'f', threshold: 50.0 },

    // Scene graph control
    SceneFlag0C:  { off: 0x3504, type: 'i', threshold: 0 },  // this+0x0C + 0x34F8 + nearby
    SceneByte970: { off: 0x097C, type: 'b', threshold: 0 },  // vehicle+0x0C+0x970 area

    // AI state
    AIMode:       { off: 0x3450, type: 'i', threshold: 0 },
    AIState1:     { off: 0x3454, type: 'i', threshold: 0 },
    AIState2:     { off: 0x3458, type: 'i', threshold: 0 },

    // Race state
    PitState:     { off: 0x4040, type: 'i', threshold: 0 },
    PitPhase:     { off: 0x4044, type: 'i', threshold: 0 },
    QualPos:      { off: 0x4058, type: 'i', threshold: 0 },
    RacePos:      { off: 0x4060, type: 'i', threshold: 0 },
    FinishState:  { off: 0x4064, type: 'i', threshold: 0 },
    ReasonCode:   { off: 0x4068, type: 'i', threshold: 0 },

    // Retirement
    RetiredFlag:  { off: 0x4410, type: 'b', threshold: 0 },
    SpeedCap:     { off: 0x453C, type: 'f', threshold: 0.01 },
    ActiveFlag:   { off: 0x45F4, type: 'b', threshold: 0 },

    // Potentially scene-graph visibility related
    Flag4648:     { off: 0x4648, type: 'i', threshold: 0 },  // this[4653] set in SceneRenderUpdate
    Byte0974:     { off: 0x0974, type: 'b', threshold: 0 },  // near respawn area (this[2420] in VehicleRespawnReset)
    Byte0975:     { off: 0x0975, type: 'b', threshold: 0 },
    Byte0979:     { off: 0x0979, type: 'b', threshold: 0 },  // this[2425] in VehicleRespawnReset
    Int094C:      { off: 0x094C, type: 'i', threshold: 0 },  // this+589*4 in VehicleRespawnReset
    Int0950:      { off: 0x0950, type: 'i', threshold: 0 },  // this+590*4
    Int0954:      { off: 0x0954, type: 'i', threshold: 0 },  // this+591*4
    Int0958:      { off: 0x0958, type: 'i', threshold: 0 },  // this+592*4
    Int095C:      { off: 0x095C, type: 'i', threshold: 0 },  // this+593*4
    Short0948:    { off: 0x0948, type: 'h', threshold: 0 },  // this+1188*2 in VehicleRespawnReset
    Int0980:      { off: 0x0980, type: 'i', threshold: 0 },  // this+608*4
    Int0984:      { off: 0x0984, type: 'i', threshold: 0 },  // this+609*4 (set to -8388609 in respawn)
};

var watchIdx = -1;
var prevValues = {};
var startTime = 0;
var logging = false;

function readValue(veh, name, spec) {
    var addr = veh.add(spec.off);
    switch(spec.type) {
        case 'f': return addr.readFloat();
        case 'i': return addr.readS32();
        case 'b': return addr.readU8();
        case 'h': return addr.readS16();
        default: return addr.readS32();
    }
}

function formatValue(val, spec) {
    if (spec.type === 'f') return val.toFixed(2);
    if (spec.type === 'b') return val.toString();
    return val.toString();
}

function getVeh(idx) {
    return VehiclePtrArray.add(idx * 4).readPointer();
}

function pollChanges() {
    if (watchIdx < 0 || !logging) return;

    var veh = getVeh(watchIdx);
    if (veh.isNull()) return;

    var gs = GameState.readS32();
    var elapsed = ((Date.now() - startTime) / 1000).toFixed(3);

    for (var name in OFFSETS) {
        var spec = OFFSETS[name];
        var val = readValue(veh, name, spec);
        var prev = prevValues[name];

        if (prev === undefined) {
            prevValues[name] = val;
            continue;
        }

        var changed = false;
        if (spec.type === 'f') {
            changed = Math.abs(val - prev) > spec.threshold;
        } else {
            changed = val !== prev;
        }

        if (changed) {
            console.log("[T+" + elapsed + " gs=" + gs + "] " + name + ": " + formatValue(prev, spec) + " -> " + formatValue(val, spec));
            prevValues[name] = val;
        }
    }
}

// Public API
globalThis.watch = function(idx) {
    watchIdx = idx;
    prevValues = {};
    startTime = Date.now();
    logging = true;
    var veh = getVeh(idx);
    console.log("[WATCH] Now watching car" + idx + " at " + veh);

    // Initial dump
    for (var name in OFFSETS) {
        var spec = OFFSETS[name];
        var val = readValue(veh, name, spec);
        prevValues[name] = val;
        console.log("  " + name + " = " + formatValue(val, spec));
    }
};

globalThis.dump = function() {
    if (watchIdx < 0) { console.log("No car watched. Use watch(N)"); return; }
    var veh = getVeh(watchIdx);
    console.log("[DUMP] car" + watchIdx + " at " + veh);
    for (var name in OFFSETS) {
        var spec = OFFSETS[name];
        var val = readValue(veh, name, spec);
        console.log("  " + name + " = " + formatValue(val, spec));
    }
};

globalThis.scan = function() {
    var count = VehicleCount.readU32();
    var player = PlayerVehiclePtr.readPointer();
    console.log("[SCAN] " + count + " vehicles:");
    for (var i = 0; i < count && i < 26; i++) {
        var veh = VehiclePtrArray.add(i * 4).readPointer();
        if (veh.isNull()) continue;
        var isPlayer = veh.equals(player) ? " [PLAYER]" : "";
        var fs = veh.add(0x4064).readS32();
        var ret = veh.add(0x4410).readU8();
        var act = veh.add(0x45F4).readU8();
        var qp = veh.add(0x4058).readS32();
        var rp = veh.add(0x4060).readS32();
        var name = "";
        try { name = veh.add(0x4620).readUtf8String(); } catch(e) {}
        console.log("  [" + i + "] " + name + " FS=" + fs + " Ret=" + ret + " Act=" + act + " QP=" + qp + " RP=" + rp + isPlayer);
    }
};

globalThis.pause = function() { logging = false; console.log("[PAUSED]"); };
globalThis.resume = function() { logging = true; startTime = Date.now(); prevValues = {}; console.log("[RESUMED]"); };

console.log("[TRACE] Restart tracer loaded. Auto-scanning for Hakkinen...");

// Auto-scan and watch Hakkinen
var count = VehicleCount.readU32();
var player = PlayerVehiclePtr.readPointer();
for (var i = 0; i < count && i < 26; i++) {
    var veh = VehiclePtrArray.add(i * 4).readPointer();
    if (veh.isNull() || veh.equals(player)) continue;
    var name = "";
    try { name = veh.add(0x4620).readUtf8String(); } catch(e) {}
    var fs = veh.add(0x4064).readS32();
    var ret = veh.add(0x4410).readU8();
    var act = veh.add(0x45F4).readU8();
    console.log("  [" + i + "] " + name + " FS=" + fs + " Ret=" + ret + " Act=" + act);
    if (name.indexOf("Hakkinen") >= 0 || name.indexOf("akkinen") >= 0) {
        console.log("[AUTO] Found Hakkinen at index " + i + ", watching...");
        watch(i);
    }
}

if (watchIdx < 0) {
    console.log("[AUTO] Hakkinen not found. Watching car index 2 (common slot)...");
    watch(2);
}

// Periodic dump every 30s for reference
var dumpCount = 0;
setInterval(function() {
    if (watchIdx >= 0) {
        dumpCount++;
        if (dumpCount % 6 === 0) {  // every 30s
            dump();
        }
    }
}, 5000);

setInterval(pollChanges, 5);  // 200Hz
