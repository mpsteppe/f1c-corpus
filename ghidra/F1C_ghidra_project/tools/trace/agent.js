"use strict";

// F1 Challenge 99-02 Runtime Trace Agent
// Hooks key functions to capture frame execution order, timing, and thread info.
// No ASLR — addresses match Ghidra directly (ImageBase = 0x00400000).

const IMAGE_BASE = ptr("0x00400000");

// ── Hook targets ────────────────────────────────────────────────────────────
// Organized by subsystem. Each entry: [address, short_name]
const HOOKS = {
    // ── Main Loop (game.cpp) ──
    main_loop: [
        [0x0045b200, "GameMainEntry"],
        [0x0042d8a0, "MainLoop_game.cpp"],
        [0x004f9f00, "FrameStart"],
        [0x00461cd0, "SessionStateCheck"],
        [0x004a0fd0, "SessionStateMachine"],
        [0x004f9f30, "FrameEnd"],
        [0x004a1830, "WinMsgPump"],
    ],

    // ── Per-frame dispatch (called from main loop) ──
    frame_dispatch: [
        [0x004ba180, "ConditionalMultiPath"],
        [0x004ba150, "ConditionalStateUpdate"],
        [0x004b3b40, "BufferReset"],
        [0x00404460, "MultiPhaseStateMachine"],
        [0x004d4580, "StewardUpdate"],
        [0x00455e50, "CollisionGlobalBroadcast"],
        [0x0042c690, "PhysicsDispatchChain"],
        [0x004b3ba0, "IterateVehicles"],
        [0x00463cd0, "CollisionResponseStatus"],
        [0x004ba6c0, "TwoPathDispatch"],
    ],

    // ── Race / Session tick ──
    race_tick: [
        [0x004b9890, "RaceTickAdvance"],
        [0x004b8ae0, "StateTriggerCheck"],
        [0x004c6b60, "SessionTickUpdate"],
        [0x004b9a00, "RaceTickMode2"],
        [0x004ef930, "RaceStartCountdown"],
        [0x004a5e10, "SessionTransitionDispatch"],
        [0x004c29f0, "UpdateRaceStateScoring"],
    ],

    // ── Physics ──
    physics: [
        [0x004e4930, "VehiclePhysicsDispatcher"],
        [0x00441650, "VehiclePhysicsIntegStep"],
        [0x00441600, "PhysicsStepFrame"],
        [0x004441f0, "VehicleMainPhysicsUpdate"],
        [0x0043ef20, "EngineStressSimulation"],
        [0x00442060, "SteeringGeometryUpdate"],
        [0x0043e6a0, "RigidBodyTransformUpdate"],
        [0x0056f020, "IteratePhysicsBodies"],
        [0x004e6d93, "WheelContactForce"],
        [0x004e9600, "SuspensionStateUpdate"],
        [0x004ed810, "WheelTireForceUpdate4"],
    ],

    // ── AI ──
    ai: [
        [0x00424e70, "AIMainUpdate"],
        [0x004bf0a0, "AIBehaviorInitTick"],
        [0x004bf4f0, "AITickUpdate"],
        [0x00424cd0, "AICommandDispatcher"],
        [0x004a5d10, "AIStateUpdate"],
    ],

    // ── Rendering ──
    render: [
        [0x004c8b70, "RenderTickUpdate"],
        [0x004c6d90, "SceneRenderUpdate"],
        [0x004950e0, "RenderFrameWrapper"],
        [0x004661b0, "GameObjectUpdateFrame"],
        [0x004c97b0, "RendererSceneNodeUpdate"],
        [0x0040ca30, "MainCameraDirectorUpdate"],
        [0x004cfcc0, "WeatherParticleUpdate"],
        [0x00476d70, "UIRenderUpdateChain"],
    ],

    // ── State machines ──
    state: [
        [0x0040d100, "GameStateBranchDispatch"],
        [0x0040d240, "GameStateDispatchChain"],
        [0x0040d1b0, "SessionPhaseDispatch"],
        [0x004a0590, "SessionTypeDispatch"],
        [0x004a0df0, "SessionStateDispatch"],
        [0x00411bf0, "RaceEventMsgDispatcher"],
        [0x005544c0, "GameStateSetViaVtable"],
    ],

    // ── Audio ──
    audio: [
        [0x00448330, "AudioDSPStateUpdate"],
        [0x004532d0, "AudioSceneUpdateLoop"],
        [0x00411e90, "SoundEventDispatcher"],
    ],

    // ── Timing / Heartbeat ──
    timing: [
        [0x004d3740, "FrameRateThrottle"],
        [0x0054ead0, "HeartbeatLoop1024"],
        [0x005568e0, "HeartbeatLoop512"],
        [0x00568cf0, "HighResTimerDelta"],
        [0x005564b0, "QPCWrapperModeDispatch"],
    ],

    // ── Network ──
    network: [
        [0x004b54e0, "NetworkMessageDispatch"],
        [0x00461de0, "StartNetworkUpdate"],
        [0x004c7ca0, "NetworkMsgReceiveDispatch"],
    ],

    // ── Input ──
    input: [
        [0x0044f150, "ForceFeedbackInput"],
        [0x0045f4a0, "InputCommandDispatch"],
    ],
};

// ── Configuration ───────────────────────────────────────────────────────────

let traceEnabled = false;
let traceDepth = {};          // per-thread call depth
let frameCount = 0;
let maxFrames = 0;            // 0 = unlimited
let logBuffer = [];
let flushInterval = null;
let startTime = 0;
let hookedCount = 0;
let subsystemFilter = null;   // null = all, or Set of subsystem names

// ── Logging ─────────────────────────────────────────────────────────────────

function getThreadId() {
    return Process.getCurrentThreadId();
}

function getDepth(tid) {
    return traceDepth[tid] || 0;
}

function logEntry(name, subsystem, tid) {
    if (!traceEnabled) return;
    const depth = getDepth(tid);
    traceDepth[tid] = depth + 1;
    const elapsed = (Date.now() - startTime);
    const indent = "  ".repeat(Math.min(depth, 20));
    logBuffer.push(`${elapsed}|${tid}|${indent}> ${name} [${subsystem}]`);
}

function logExit(name, subsystem, tid) {
    if (!traceEnabled) return;
    const depth = getDepth(tid) - 1;
    traceDepth[tid] = Math.max(0, depth);
    const elapsed = (Date.now() - startTime);
    const indent = "  ".repeat(Math.min(depth, 20));
    logBuffer.push(`${elapsed}|${tid}|${indent}< ${name} [${subsystem}]`);
}

function flushLog() {
    if (logBuffer.length === 0) return;
    send({ type: "trace", lines: logBuffer.splice(0) });
}

// ── Frame counting (hook WinMsgPump — called once per main loop iteration) ──

let doneSent = false;

function onFrameTick() {
    if (!traceEnabled) return;
    frameCount++;
    if (maxFrames > 0 && frameCount > maxFrames && !doneSent) {
        traceEnabled = false;
        doneSent = true;
        flushLog();
        send({ type: "done", frames: frameCount - 1 });
    }
}

// ── Hook installation ───────────────────────────────────────────────────────

function installHooks() {
    for (const [subsystem, entries] of Object.entries(HOOKS)) {
        if (subsystemFilter && !subsystemFilter.has(subsystem)) continue;

        for (const [addr, name] of entries) {
            const target = ptr(addr);
            try {
                Interceptor.attach(target, {
                    onEnter: function (_args) {
                        const tid = getThreadId();
                        logEntry(name, subsystem, tid);
                        if (addr === 0x004a1830) onFrameTick();
                    },
                    onLeave: function (_retval) {
                        logExit(name, subsystem, getThreadId());
                    }
                });
                hookedCount++;
            } catch (e) {
                send({ type: "error", msg: `Hook failed @ 0x${addr.toString(16)}: ${e.message}` });
            }
        }
    }
    send({ type: "ready", hooks: hookedCount });
}

// ── State variable watchers ─────────────────────────────────────────────────
// Watch writes to key globals to capture state transitions

const STATE_GLOBALS = [
    [0x007d00ec, "GameState",    4],
    [0x007c56a4, "SessionType",  4],
    [0x007c56a8, "RacePhase",    4],
    [0x007cf080, "WeatherMode",  4],
    [0x007d0410, "RaceMode",     4],
    [0x007d0308, "RaceActiveFlag", 4],
];

let stateWatchers = [];

function installStateWatchers() {
    for (const [addr, name, size] of STATE_GLOBALS) {
        const target = ptr(addr);
        try {
            const currentVal = target.readU32();
            send({ type: "state_init", name: name, addr: "0x" + addr.toString(16), value: currentVal });

            MemoryAccessMonitor.enable([{base: target, size: size}], {
                onAccess: function (details) {
                    if (details.operation === "write") {
                        const newVal = target.readU32();
                        const tid = getThreadId();
                        const elapsed = (Date.now() - startTime);
                        const from = details.from;
                        send({
                            type: "state_change",
                            name: name,
                            addr: "0x" + addr.toString(16),
                            newValue: newVal,
                            writer: from.toString(),
                            thread: tid,
                            time: elapsed
                        });
                    }
                }
            });
            stateWatchers.push(name);
        } catch (e) {
            send({ type: "error", msg: `State watch failed for ${name}: ${e.message}` });
        }
    }
    if (stateWatchers.length > 0) {
        send({ type: "state_watchers", names: stateWatchers });
    }
}

// ── RPC commands from Python controller ─────────────────────────────────────

rpc.exports = {
    start: function (frames) {
        maxFrames = frames || 0;
        frameCount = 0;
        doneSent = false;
        traceDepth = {};
        logBuffer = [];
        startTime = Date.now();
        traceEnabled = true;
        flushInterval = setInterval(flushLog, 200);
        send({ type: "started", maxFrames: maxFrames });
    },

    stop: function () {
        traceEnabled = false;
        if (flushInterval) {
            clearInterval(flushInterval);
            flushInterval = null;
        }
        flushLog();
        send({ type: "stopped", frames: frameCount });
    },

    status: function () {
        return {
            enabled: traceEnabled,
            frames: frameCount,
            hooks: hookedCount,
            bufferSize: logBuffer.length,
            watchers: stateWatchers
        };
    },

    setFilter: function (subsystems) {
        if (!subsystems || subsystems.length === 0) {
            subsystemFilter = null;
        } else {
            subsystemFilter = new Set(subsystems);
        }
    },

    readState: function () {
        const result = {};
        for (const [addr, name, _size] of STATE_GLOBALS) {
            try {
                result[name] = ptr(addr).readU32();
            } catch (e) {
                result[name] = "read_error";
            }
        }
        return result;
    },

    readGlobal: function (address) {
        try {
            return ptr(address).readU32();
        } catch (e) {
            return "read_error: " + e.message;
        }
    },

    snapshot: function () {
        const result = {};
        for (const [_subsystem, entries] of Object.entries(HOOKS)) {
            for (const [addr, name] of entries) {
                try {
                    const bytes = ptr(addr).readByteArray(4);
                    result[name] = Array.from(new Uint8Array(bytes)).map(
                        b => b.toString(16).padStart(2, "0")
                    ).join(" ");
                } catch (e) {
                    result[name] = "read_error";
                }
            }
        }
        return result;
    }
};

// ── Auto-init ───────────────────────────────────────────────────────────────
installHooks();
installStateWatchers();
