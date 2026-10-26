"use strict";

// Lightweight state-only trace agent.
// Polls state globals every 50ms instead of MemoryAccessMonitor (avoids guard page limits).
// Output: [STATE] lines only. Tiny output files.

const STATE_GLOBALS = [
    // Primary state machines
    [0x007d00ec, "GameState",      4],
    [0x007c56a4, "SessionType",    4],
    [0x007c56a8, "RacePhase",      4],
    [0x007cf080, "WeatherMode",    4],
    [0x007d0410, "RaceMode",       4],
    [0x007d0308, "RaceActiveFlag", 4],
    [0x007c56ac, "PauseFlag",      4],
    [0x007cebc4, "FormationLap",   1],
    // Internal dispatch / sub-states
    [0x007c569c, "InternalState",  4],   // returned by SessionStateMachine, drives main loop
    [0x007ced8c, "UIRacePhaseFlag",4],   // gates GREEN_FLAG->RACING in steward
    [0x007cee88, "PhaseGateFlag",  4],   // gates phase advance in steward dispatch
    [0x007ce25d, "ExitFlag",       1],   // triggers game exit (return 4)
    [0x007ce258, "SessionSubState",4],   // sub-state in SessionStateMachine (1=ready, 2=transitioning)
    [0x007ce264, "SessionMode",    4],   // session mode check in SessionStateMachine
    [0x007c56b0, "SessionState2",  4],   // near SessionType, session management
    // Context (integers)
    [0x005c329c, "VehicleCount",   4],   // number of active vehicles
    [0x007d00f4, "GameStateMin",   4],   // GameState clamp lower bound
    [0x007d00f8, "GameStateMax",   4],   // GameState clamp upper bound
    // Race/session control
    [0x007cea5c, "EngineWearMode", 4],   // 0/2/3
    [0x008ab6e4, "TimingMode",     4],   // branched in steward (2 = special)
    [0x007cc520, "MultiplayerFlag",4],   // checked in post-race steward
    [0x007ce254, "NetworkActive",  1],   // network activity flag in SessionStateMachine
    [0x007ce269, "TimerActive",    1],   // countdown timer flag in SessionStateMachine
    // Player vehicle pointer (changes on session init)
    [0x007c54e8, "PlayerVehPtr",   4],   // PlayerVehiclePtr
    [0x007c54f0, "VehArrayPtr",    4],   // VehiclePtrArray base
];

// Float globals tracked separately (only ones that change at meaningful moments, NOT per-frame)
const FLOAT_GLOBALS = [
    [0x008acf9c, "TotalRaceLaps"],
    [0x007d0c60, "TireWearMult"],        // tire wear multiplier
];

let startTime = Date.now();
let pollTimer = null;
let lastValues = {};

function readAllState() {
    const result = {};
    for (const [addr, name, size] of STATE_GLOBALS) {
        try {
            const p = ptr(addr);
            result[name] = size === 1 ? p.readU8() : p.readU32();
        } catch (e) {
            result[name] = -1;
        }
    }
    for (const [addr, name] of FLOAT_GLOBALS) {
        try {
            result[name] = Math.round(ptr(addr).readFloat() * 100) / 100;
        } catch (e) {
            result[name] = -1;
        }
    }
    return result;
}

function initState() {
    lastValues = readAllState();
    for (const [addr, name] of STATE_GLOBALS) {
        send({ type: "state_init", name: name, addr: "0x" + addr.toString(16), value: lastValues[name] });
    }
}

function pollState() {
    const current = readAllState();
    const elapsed = Date.now() - startTime;
    for (const name in current) {
        if (current[name] !== lastValues[name]) {
            send({
                type: "state_change",
                name: name,
                addr: "",
                newValue: current[name],
                oldValue: lastValues[name],
                writer: "poll",
                thread: 0,
                time: elapsed
            });
            lastValues[name] = current[name];
        }
    }
}

rpc.exports = {
    start: function () {
        startTime = Date.now();
        lastValues = readAllState();
        pollTimer = setInterval(pollState, 20);
        send({ type: "started", maxFrames: 0 });
    },

    stop: function () {
        if (pollTimer) {
            clearInterval(pollTimer);
            pollTimer = null;
        }
        send({ type: "stopped", frames: 0 });
    },

    status: function () {
        return { polling: pollTimer !== null, values: readAllState() };
    },

    readState: function () {
        return readAllState();
    },

    readGlobal: function (address) {
        try {
            return ptr(address).readU32();
        } catch (e) {
            return "read_error: " + e.message;
        }
    }
};

initState();
send({ type: "ready", hooks: 0 });
