/*
 * trace_retirement.js — Frida script to trace the retirement sequence
 *
 * Monitors key vehicle struct offsets for changes when a car retires.
 * Watches: FinishState, ReasonCode, RetiredFlag, ActiveFlag, PitState,
 *          SpeedCap, render position Y, physics position Y, AIMode
 *
 * Usage:
 *   frida -p <PID> -l trace_retirement.js
 *
 * Then crash a car in-game and watch the log.
 */

var VehiclePtrArray = ptr(0x007C54F0);
var VehicleCount = ptr(0x005C329C);
var PlayerVehiclePtr = ptr(0x007C54E8);

var OFFSETS = {
    PhysX:       0x001C,
    PhysY:       0x0020,
    PhysZ:       0x0024,
    AIMode:      0x3450,
    PitState:    0x4040,
    QualPos:     0x4058,
    RacePos:     0x4060,
    FinishState: 0x4064,
    ReasonCode:  0x4068,
    RetiredFlag: 0x4410,
    SpeedCap:    0x453C,
    ActiveFlag:  0x45F4,
    RenderX:     0x34F0,
    RenderY:     0x34F4,
    RenderZ:     0x34F8
};

var watchedVehicles = {};
var prevValues = {};

function getDriverName(vehPtr) {
    // Driver name is typically at an offset in the vehicle struct
    // For now just use the pointer address
    return "veh_" + vehPtr.toString(16);
}

function scanAllVehicles() {
    var count = VehicleCount.readU32();
    var player = PlayerVehiclePtr.readPointer();

    for (var i = 0; i < count && i < 26; i++) {
        var veh = VehiclePtrArray.add(i * 4).readPointer();
        if (veh.isNull() || veh.equals(player)) continue;

        var key = veh.toString();
        if (!prevValues[key]) {
            prevValues[key] = {};
            for (var name in OFFSETS) {
                var off = OFFSETS[name];
                if (name === "RetiredFlag" || name === "ActiveFlag") {
                    prevValues[key][name] = veh.add(off).readU8();
                } else if (name === "SpeedCap" || name.indexOf("Phys") === 0 || name.indexOf("Render") === 0) {
                    prevValues[key][name] = veh.add(off).readFloat();
                } else {
                    prevValues[key][name] = veh.add(off).readS32();
                }
            }
        }
    }
}

function pollChanges() {
    var count = VehicleCount.readU32();
    var player = PlayerVehiclePtr.readPointer();
    var now = Date.now();

    for (var i = 0; i < count && i < 26; i++) {
        var veh = VehiclePtrArray.add(i * 4).readPointer();
        if (veh.isNull() || veh.equals(player)) continue;

        var key = veh.toString();
        if (!prevValues[key]) continue;

        for (var name in OFFSETS) {
            var off = OFFSETS[name];
            var val;
            if (name === "RetiredFlag" || name === "ActiveFlag") {
                val = veh.add(off).readU8();
            } else if (name === "SpeedCap" || name.indexOf("Phys") === 0 || name.indexOf("Render") === 0) {
                val = veh.add(off).readFloat();
            } else {
                val = veh.add(off).readS32();
            }

            var prev = prevValues[key][name];

            // For floats, use threshold to avoid noise
            if (typeof val === "number" && (name === "SpeedCap" || name.indexOf("Phys") === 0 || name.indexOf("Render") === 0)) {
                if (Math.abs(val - prev) > 0.5) {
                    // Only log position changes if FinishState or RetiredFlag also changed recently
                    // or if the change is very large (teleport)
                    if (name.indexOf("Phys") === 0 || name.indexOf("Render") === 0) {
                        if (Math.abs(val - prev) > 50.0) {
                            console.log("[" + now + "] car" + i + " " + name + ": " + prev.toFixed(1) + " -> " + val.toFixed(1) + " (TELEPORT)");
                        }
                    } else {
                        console.log("[" + now + "] car" + i + " " + name + ": " + prev.toFixed(4) + " -> " + val.toFixed(4));
                    }
                    prevValues[key][name] = val;
                }
            } else if (val !== prev) {
                console.log("[" + now + "] car" + i + " " + name + ": " + prev + " -> " + val);
                prevValues[key][name] = val;
            }
        }
    }
}

console.log("[TRACE] Retirement sequence tracer loaded. Scanning vehicles...");
scanAllVehicles();
console.log("[TRACE] Watching " + Object.keys(prevValues).length + " AI vehicles. Crash one to see the sequence.");

setInterval(pollChanges, 10);  // 100Hz polling
