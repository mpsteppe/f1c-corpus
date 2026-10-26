"use strict";

// F1 Challenge 99-02 — Comprehensive 10-minute trace agent
// Strategy: log FIRST CALL of every function, state changes via polling,
// periodic call-count summaries + memory snapshots. NOT per-call logging.
// Designed for ~50K lines over 10 minutes instead of billions.

const IMAGE_BASE = ptr("0x00400000");

// ── ALL hooks: confirmed names from trace_rename_table.csv + prior agent ────
// Format: [address, "RealName", "subsystem"]

const ALL_HOOKS = [
    // === Lifecycle (66 confirmed names) ===
    [0x004040a0, "AIDatabase::Init", "lifecycle"],
    [0x0040c920, "CamMan::Init", "lifecycle"],
    [0x0040c9e0, "CamMan::Restart", "lifecycle"],
    [0x0040cce0, "CamMan::Post", "lifecycle"],
    [0x0042c130, "DynMan::Enter", "lifecycle"],
    [0x0042c170, "DynMan::Setup", "lifecycle"],
    [0x0042c1a0, "DynMan::Init", "lifecycle"],
    [0x0042c3b0, "DynMan::Restart", "lifecycle"],
    [0x0042c9f0, "DynMan::Post", "lifecycle"],
    [0x0042ca70, "DynMan::Exit", "lifecycle"],
    [0x0042d370, "Game::Enter", "lifecycle"],
    [0x0042d5d0, "Game::Setup", "lifecycle"],
    [0x0042d6b0, "Game::Init", "lifecycle"],
    [0x0042d7a0, "Game::Restart", "lifecycle"],
    [0x0042da30, "Game::Post", "lifecycle"],
    [0x0042db20, "Game::Exit", "lifecycle"],
    [0x00455bf0, "HWInput::Enter", "lifecycle"],
    [0x00455c60, "HWInput::Setup", "lifecycle"],
    [0x00455d50, "HWInput::Init", "lifecycle"],
    [0x00455da0, "HWInput::Restart", "lifecycle"],
    [0x00455e70, "HWInput::Post", "lifecycle"],
    [0x00455f00, "HWInput::Exit", "lifecycle"],
    [0x00460520, "NetComm::SetSelfAsReady", "lifecycle"],
    [0x00492160, "Options_OSC_Reader::ReadOptionsObject", "lifecycle"],
    [0x0049ef40, "OnScreen::Enter", "lifecycle"],
    [0x0049ef70, "OnScreen::Setup", "lifecycle"],
    [0x0049efa0, "OnScreen::Init", "lifecycle"],
    [0x0049f000, "OnScreen::Restart", "lifecycle"],
    [0x0049f0d0, "OnScreen::Post", "lifecycle"],
    [0x0049f120, "OnScreen::Exit", "lifecycle"],
    [0x004a0eb0, "Options::Setup", "lifecycle"],
    [0x004a18d0, "OSMan::Enter", "lifecycle"],
    [0x004b1820, "PlayerFile::Enter", "lifecycle"],
    [0x004b1870, "PlayerFile::Setup", "lifecycle"],
    [0x004b18d0, "PlayerFile::Restart", "lifecycle"],
    [0x004b1900, "PlayerFile::Post", "lifecycle"],
    [0x004b4030, "Render::Init", "lifecycle"],
    [0x004b4060, "Render::Restart", "lifecycle"],
    [0x004b4170, "Render::Post", "lifecycle"],
    [0x004c8a20, "Sound::Enter", "lifecycle"],
    [0x004c8ab0, "Sound::Setup", "lifecycle"],
    [0x004c8ae0, "Sound::Init", "lifecycle"],
    [0x004c8b20, "Sound::Restart", "lifecycle"],
    [0x004c8ca0, "Sound::Post", "lifecycle"],
    [0x004c8d00, "Sound::Exit", "lifecycle"],
    [0x004cee90, "SpecialFX::Enter", "lifecycle"],
    [0x004ceec0, "SpecialFX::Setup", "lifecycle"],
    [0x004cf070, "SpecialFX::Init", "lifecycle"],
    [0x004cfc90, "SpecialFX::Restart", "lifecycle"],
    [0x004cfed0, "SpecialFX::Post", "lifecycle"],
    [0x004cfff0, "SpecialFX::Exit", "lifecycle"],
    [0x004d36d0, "Steward::Setup", "lifecycle"],
    [0x004d38f0, "Steward::Init", "lifecycle"],
    [0x004d3cf0, "Steward::Restart", "lifecycle"],
    [0x004d4600, "Steward::Post", "lifecycle"],
    [0x004fa000, "VidMan::Enter", "lifecycle"],
    [0x004fa2f0, "VidMan::Setup", "lifecycle"],
    [0x004fa320, "VidMan::Init", "lifecycle"],
    [0x004fa640, "VidMan::Restart", "lifecycle"],
    [0x004fac00, "VidMan::Post", "lifecycle"],
    [0x004fad00, "VidMan::Exit", "lifecycle"],
    [0x0052da30, "CMpegBase::ProcessHeader", "lifecycle"],
    [0x0052dc90, "CMpegFilePlayer::DecodeHeader", "lifecycle"],
    [0x0052e090, "CMpegBase::Open", "lifecycle"],
    [0x0052e1d0, "CMpegFilePlayer::Open", "lifecycle"],

    // === Main loop ===
    [0x0045b200, "GameMainEntry", "main_loop"],
    [0x0042d8a0, "Game::PostLoop", "main_loop"],
    [0x004f9f00, "FrameStart", "main_loop"],
    [0x00461cd0, "SessionStateCheck", "main_loop"],
    [0x004a0fd0, "SessionStateMachine", "main_loop"],
    [0x004f9f30, "FrameEnd", "main_loop"],
    [0x004a1830, "WinMsgPump", "main_loop"],

    // === Per-frame dispatch ===
    [0x004ba180, "ConditionalMultiPath", "frame"],
    [0x004ba150, "ConditionalStateUpdate", "frame"],
    [0x004b3b40, "BufferReset", "frame"],
    [0x00404460, "AIMainDispatch", "frame"],
    [0x004d4580, "Steward::Update", "frame"],
    [0x00455e50, "HWInput::FrameUpdate", "frame"],
    [0x0042c690, "DynMan::PhysicsDispatch", "frame"],
    [0x004b3ba0, "VehicleIterator", "frame"],
    [0x00463cd0, "CollisionResponse", "frame"],
    [0x004ba6c0, "TimingScoring", "frame"],

    // === Race / session ===
    [0x004b9890, "RaceTickAdvance", "race"],
    [0x004b8ae0, "StateTriggerCheck", "race"],
    [0x004c6b60, "SessionTickUpdate", "race"],
    [0x004b9a00, "RaceTickMode2", "race"],
    [0x004ef930, "RaceStartCountdown", "race"],
    [0x004a5e10, "SessionTransitionDispatch", "race"],
    [0x004c29f0, "UpdateRaceStateScoring", "race"],
    [0x00464290, "NetComm::SynchronizeWithServer", "race"],
    [0x004a40f0, "Steward::RaceControl", "race"],
    [0x004a0fb0, "RaceTimer", "race"],
    [0x004ba460, "Replay::Restart", "race"],
    [0x004bc320, "VehiclePlacement", "race"],
    [0x004c6f10, "GridSetup", "race"],

    // === Physics (sampled — NOT per-step) ===
    [0x004e4930, "VehiclePhysicsDispatcher", "physics"],
    [0x00441650, "VehiclePhysicsIntegStep", "physics"],
    [0x004441f0, "VehicleMainPhysicsUpdate", "physics"],
    [0x0043ef20, "EngineStressSimulation", "physics"],
    [0x00442060, "SteeringGeometry", "physics"],
    [0x0043e6a0, "RigidBodyTransform", "physics"],
    [0x0056f020, "IteratePhysicsBodies", "physics"],
    // [0x004e6d93, "WheelContactForce", "physics"], // odd address, likely mid-function — crashes
    [0x004e9600, "SuspensionState", "physics"],
    [0x004ed810, "WheelTireForce", "physics"],
    [0x00575bbd, "LDLtFactorize", "physics"],
    [0x0056fa96, "BlockSparseLDLt", "physics"],
    [0x00579ccf, "PhysicsWorkspaceZero", "physics"],
    [0x00578f76, "SkeletonIdentityInit", "physics"],

    // === AI ===
    [0x00424e70, "AI::MainUpdate", "ai"],
    [0x004bf0a0, "AI::BehaviorInit", "ai"],
    [0x004bf4f0, "AI::TickUpdate", "ai"],
    [0x00424cd0, "AI::CommandDispatch", "ai"],
    [0x004a5d10, "AI::StateUpdate", "ai"],
    [0x004024f0, "AIDatabase::LoadWaypoints", "ai"],
    [0x004333e0, "AI::SettingsReload", "ai"],

    // === Rendering ===
    [0x004c8b70, "Render::TickUpdate", "render"],
    [0x004c6d90, "Scene::RenderUpdate", "render"],
    [0x004950e0, "Render::FrameWrapper", "render"],
    [0x004661b0, "GameObject::UpdateFrame", "render"],
    [0x004c97b0, "Render::SceneNode", "render"],
    [0x0040ca30, "CameraDirector::Update", "render"],
    [0x004cfcc0, "Weather::ParticleUpdate", "render"],
    [0x00476d70, "UI::RenderChain", "render"],

    // === State machines ===
    [0x0040d100, "GameStateBranch", "state"],
    [0x0040d240, "GameStateChain", "state"],
    [0x0040d1b0, "SessionPhaseDispatch", "state"],
    [0x004a0590, "SessionTypeDispatch", "state"],
    [0x004a0df0, "SessionStateDispatch", "state"],
    [0x00411bf0, "RaceEventDispatch", "state"],
    [0x005544c0, "GameStateVtable", "state"],

    // === Audio ===
    [0x00448330, "Audio::DSPUpdate", "audio"],
    [0x004532d0, "Audio::SceneLoop", "audio"],
    [0x00411e90, "Sound::EventDispatch", "audio"],

    // === Timing ===
    [0x004d3740, "FrameRateThrottle", "timing"],

    // === Network ===
    [0x004b54e0, "Net::MessageDispatch", "network"],
    [0x00461de0, "Net::StartUpdate", "network"],
    [0x004c7ca0, "Net::ReceiveDispatch", "network"],
    [0x00462c00, "Net::JoinRequest", "network"],
    [0x00462e20, "Net::QualifyView", "network"],
    [0x00463160, "Net::ConfigSetup", "network"],
    [0x004637a0, "Net::AutoJoin", "network"],

    // === Input ===
    [0x0044f150, "ForceFeedback::Input", "input"],
    [0x0045f4a0, "Input::CommandDispatch", "input"],

    // === File I/O (trace caller strings showed these) ===
    [0x00421cd0, "Config::ParseIni", "fileio"],
    [0x0042fd00, "Garage::Setup", "fileio"],
    [0x0043c250, "HDVehicle::LoadTires", "fileio"],
    [0x004c3200, "Setup::Load", "fileio"],
    [0x004c3d80, "Setup::LoadVehicles", "fileio"],
    [0x004c52c0, "Setup::LoadScenes", "fileio"],
    [0x004d5ee0, "TireManager::Init", "fileio"],
    [0x004d7660, "TireManager::LoadBrands", "fileio"],
    [0x004f3240, "VehLoad::Main", "fileio"],
    [0x004ddf90, "VehGfx::Load", "fileio"],
    [0x004fe820, "Weather::Init", "fileio"],
    [0x004ba1f0, "Replay::Load", "fileio"],
    [0x004bdc10, "SearchGrid::Init", "fileio"],
    [0x0045d890, "NetComm::LoadTerrain", "fileio"],

    // === Pitcrew ===
    [0x004a2010, "Pitcrew::Func1", "pitcrew"],
    [0x004a22d0, "Pitcrew::Func2", "pitcrew"],
    [0x004a2a90, "Pitcrew::Func3", "pitcrew"],

    // === Misc known ===
    [0x00449a80, "HTree::GaussianElim", "math"],
    [0x00439210, "HDVehicle::InertiaCheck", "vehicle"],
    [0x0043af50, "HDVehicle::SuspensionBar", "vehicle"],
    [0x0043b040, "HDVehicle::Steering5Link", "vehicle"],
    [0x0043da10, "HDVehicle::TireCamber", "vehicle"],
    [0x004dc770, "Util::Misc", "util"],
    [0x004f9310, "VidMan::InternalInit", "render"],
];

// ── State globals to poll ──────────────────────────────────────────────────
const STATE_GLOBALS = [
    [0x007d00ec, "GameState", 4],
    [0x007c56a4, "SessionType", 4],
    [0x007c56a8, "RacePhase", 4],
    [0x007cf080, "WeatherMode", 4],
    [0x007d0410, "RaceMode", 4],
    [0x007d0308, "RaceActiveFlag", 4],
    [0x007c56ac, "PauseFlag", 4],
    [0x007cebc4, "FormationLap", 1],
    [0x007c569c, "InternalState", 4],
    [0x007ced8c, "UIRacePhaseFlag", 4],
    [0x007cee88, "PhaseGateFlag", 4],
    [0x007ce25d, "ExitFlag", 1],
    [0x007ce258, "SessionSubState", 4],
    [0x007ce264, "SessionMode", 4],
    [0x007c56b0, "SessionState2", 4],
    [0x005c329c, "VehicleCount", 4],
    [0x007d00f4, "GameStateMin", 4],
    [0x007d00f8, "GameStateMax", 4],
    [0x007cea5c, "EngineWearMode", 4],
    [0x008ab6e4, "TimingMode", 4],
    [0x007cc520, "MultiplayerFlag", 4],
    [0x007ce254, "NetworkActive", 1],
    [0x007ce269, "TimerActive", 1],
    [0x007c54e8, "PlayerVehPtr", 4],
    [0x007c54f0, "VehArrayPtr", 4],
    [0x007d01a0, "AIDifficultySlider", 4],
    [0x007d0c60, "TireWearMultiplier", 4],
    [0x008acf9c, "TotalRaceLaps", 4],
    [0x007c5690, "DedicatedServerFlag", 4],
    [0x007c5694, "DynManState1", 4],
    [0x007c5698, "DynManState2", 4],
];

// ── Vehicle struct snapshot offsets (from docs/13) ─────────────────────────
const VEH_SNAPSHOT_OFFSETS = [
    [0x0000, "vtable_ptr", 4],
    [0x0044, "position_x", "f"],
    [0x0048, "position_y", "f"],
    [0x004c, "position_z", "f"],
    [0x00b0, "speed_ms", "f"],
    [0x1330, "rpm", "d"],
    [0x1338, "throttle", "d"],
    [0x1340, "brake", "d"],
    [0x1530, "gear", 4],
    [0x0730, "tire_FL_wear", "d"],
    [0x0828, "tire_FR_wear", "d"],
    [0x0920, "tire_RL_wear", "d"],
    [0x0a18, "tire_RR_wear", "d"],
    [0x48A4, "lap_count", 4],
    [0x48A8, "position_race", 4],
];

// ── Runtime state ──────────────────────────────────────────────────────────
let startTime = 0;
let running = false;
let hookedCount = 0;
let pollTimer = null;
let summaryTimer = null;
let snapshotTimer = null;

// Per-hook tracking
let callCounts = {};      // name -> count since last summary
let totalCounts = {};     // name -> total count
let firstCallTime = {};   // name -> elapsed_ms of first call (null if not yet called)
let lastSummaryTime = 0;

// State tracking
let lastStateValues = {};

// ── Logging ────────────────────────────────────────────────────────────────
let logBuffer = [];

function elapsed() {
    return Date.now() - startTime;
}

function log(msg) {
    logBuffer.push(msg);
}

function flushLog() {
    if (logBuffer.length === 0) return;
    send({ type: "trace", lines: logBuffer.splice(0) });
}

// ── Hook installation ──────────────────────────────────────────────────────
// Only logs FIRST call per function + counts subsequent calls

function installHooks() {
    for (const [addr, name, subsystem] of ALL_HOOKS) {
        const target = ptr(addr);
        callCounts[name] = 0;
        totalCounts[name] = 0;
        firstCallTime[name] = null;

        try {
            Interceptor.attach(target, {
                onEnter: function (_args) {
                    if (!running) return;

                    callCounts[name]++;
                    totalCounts[name]++;

                    // Log first call with full detail
                    if (firstCallTime[name] === null) {
                        firstCallTime[name] = elapsed();
                        const tid = Process.getCurrentThreadId();
                        log(`[FIRST] ${elapsed()}ms | ${name} [${subsystem}] | thread=${tid} | addr=0x${addr.toString(16)}`);
                    }
                }
            });
            hookedCount++;
        } catch (e) {
            send({ type: "error", msg: `Hook failed @ 0x${addr.toString(16)} (${name}): ${e.message}` });
        }
    }
    send({ type: "ready", hooks: hookedCount });
}

// ── State polling (every 50ms) ─────────────────────────────────────────────

function initState() {
    for (const [addr, name, size] of STATE_GLOBALS) {
        try {
            const p = ptr(addr);
            const val = size === 1 ? p.readU8() : p.readU32();
            lastStateValues[name] = val;
            log(`[STATE_INIT] ${name} = ${val}`);
        } catch (e) {
            lastStateValues[name] = -1;
        }
    }
}

function pollState() {
    if (!running) return;
    const t = elapsed();
    for (const [addr, name, size] of STATE_GLOBALS) {
        try {
            const p = ptr(addr);
            const val = size === 1 ? p.readU8() : p.readU32();
            if (val !== lastStateValues[name]) {
                const old = lastStateValues[name];
                log(`[STATE] ${t}ms | ${name}: ${old} -> ${val}`);
                lastStateValues[name] = val;
            }
        } catch (e) {}
    }
}

// ── Call count summary (every 5 seconds) ───────────────────────────────────

function emitSummary() {
    if (!running) return;
    const t = elapsed();
    const dt = t - lastSummaryTime;
    lastSummaryTime = t;

    // Group by subsystem, only show non-zero
    const bySubsystem = {};
    for (const [_addr, name, subsystem] of ALL_HOOKS) {
        const count = callCounts[name];
        if (count > 0) {
            if (!bySubsystem[subsystem]) bySubsystem[subsystem] = [];
            bySubsystem[subsystem].push([name, count]);
        }
    }

    if (Object.keys(bySubsystem).length === 0) {
        log(`[SUMMARY] ${t}ms | dt=${dt}ms | no calls`);
    } else {
        log(`[SUMMARY] ${t}ms | dt=${dt}ms |`);
        for (const sub of Object.keys(bySubsystem).sort()) {
            const entries = bySubsystem[sub];
            const parts = entries.map(([n, c]) => `${n}=${c}`).join(", ");
            log(`  [${sub}] ${parts}`);
        }

        // Compute rates for key subsystems
        const dtSec = dt / 1000;
        if (dtSec > 0) {
            const physCount = totalCounts["VehiclePhysicsIntegStep"] || 0;
            const aiCount = totalCounts["AI::MainUpdate"] || 0;
            const frameCount = totalCounts["FrameStart"] || 0;
            const physRate = (callCounts["VehiclePhysicsIntegStep"] || 0) / dtSec;
            const aiRate = (callCounts["AI::MainUpdate"] || 0) / dtSec;
            const frameRate = (callCounts["FrameStart"] || 0) / dtSec;
            log(`  [RATES] physics=${physRate.toFixed(1)}Hz ai=${aiRate.toFixed(1)}Hz render=${frameRate.toFixed(1)}Hz`);
        }
    }

    // Reset interval counts
    for (const name in callCounts) {
        callCounts[name] = 0;
    }

    flushLog();
}

// ── Vehicle memory snapshot (every 10 seconds) ────────────────────────────

function readVehicleAt(vehPtr, label, t) {
    log(`[${label}] ${t}ms | ptr=${vehPtr} |`);
    for (const [offset, name, type] of VEH_SNAPSHOT_OFFSETS) {
        try {
            const p = vehPtr.add(offset);
            let val;
            if (type === "f") val = Math.round(p.readFloat() * 1000) / 1000;
            else if (type === "d") val = Math.round(p.readDouble() * 10000) / 10000;
            else val = p.readU32();
            log(`  +0x${offset.toString(16).padStart(4, "0")} ${name} = ${val}`);
        } catch (e) {
            log(`  +0x${offset.toString(16).padStart(4, "0")} ${name} = READ_ERROR`);
        }
    }
}

function snapshotVehicle() {
    if (!running) return;
    const t = elapsed();

    // Vehicle array is at DAT_007c54f0 — array of pointers, stride 4 bytes
    // In noplayer mode, PlayerVehPtr may be 0 or point to array base (not a vehicle).
    // Read from array directly instead.
    let vehArray, vehCount;
    try {
        vehArray = ptr(0x007c54f0).readPointer();
        vehCount = ptr(0x005c329c).readU32();
    } catch (e) {
        log(`[VEHICLE] ${t}ms | array read failed`);
        return;
    }

    if (vehArray.isNull() || vehCount === 0) {
        log(`[VEHICLE] ${t}ms | no vehicles (array=${vehArray}, count=${vehCount})`);
        return;
    }

    // Snapshot vehicle 0 (leader / first in array)
    try {
        const veh0 = vehArray.add(0).readPointer();
        if (!veh0.isNull()) {
            readVehicleAt(veh0, "VEH_0", t);
        }
    } catch (e) {}

    // Snapshot vehicle 1 if exists
    if (vehCount > 1) {
        try {
            const veh1 = vehArray.add(4).readPointer();
            if (!veh1.isNull()) {
                readVehicleAt(veh1, "VEH_1", t);
            }
        } catch (e) {}
    }

    // Also snapshot mid-pack vehicle for comparison
    if (vehCount > 10) {
        try {
            const midIdx = Math.floor(vehCount / 2);
            const vehMid = vehArray.add(midIdx * 4).readPointer();
            if (!vehMid.isNull()) {
                readVehicleAt(vehMid, `VEH_${midIdx}`, t);
            }
        } catch (e) {}
    }
}

// ── RPC ────────────────────────────────────────────────────────────────────

rpc.exports = {
    installnow: function () {
        if (hookedCount === 0) {
            installHooks();
        }
        return hookedCount;
    },

    start: function (durationSec) {
        if (hookedCount === 0) {
            installHooks();
        }
        startTime = Date.now();
        running = true;
        lastSummaryTime = 0;
        for (const name in callCounts) {
            callCounts[name] = 0;
            totalCounts[name] = 0;
            firstCallTime[name] = null;
        }

        initState();

        pollTimer = setInterval(pollState, 50);
        summaryTimer = setInterval(emitSummary, 5000);
        snapshotTimer = setInterval(snapshotVehicle, 10000);

        // Also flush log periodically
        setInterval(flushLog, 500);

        log(`[START] Comprehensive trace started. ${hookedCount} hooks, ${STATE_GLOBALS.length} state vars, duration=${durationSec}s`);
        flushLog();

        send({ type: "started", maxFrames: 0 });

        // Auto-stop after duration
        if (durationSec > 0) {
            setTimeout(function () {
                if (running) {
                    running = false;
                    emitSummary(); // final summary
                    snapshotVehicle(); // final snapshot

                    // Emit total counts
                    log(`[FINAL] Total call counts over ${durationSec}s:`);
                    const sorted = ALL_HOOKS
                        .map(([_a, name, sub]) => [name, sub, totalCounts[name] || 0])
                        .filter(([_n, _s, c]) => c > 0)
                        .sort((a, b) => b[2] - a[2]);
                    for (const [name, sub, count] of sorted) {
                        const first = firstCallTime[name] !== null ? `first@${firstCallTime[name]}ms` : "never";
                        log(`  ${name} [${sub}]: ${count} calls (${first})`);
                    }

                    // Functions never called
                    const neverCalled = ALL_HOOKS
                        .filter(([_a, name]) => (totalCounts[name] || 0) === 0)
                        .map(([addr, name, sub]) => `${name} [${sub}] 0x${addr.toString(16)}`);
                    if (neverCalled.length > 0) {
                        log(`[NEVER_CALLED] ${neverCalled.length} functions never called:`);
                        for (const n of neverCalled) {
                            log(`  ${n}`);
                        }
                    }

                    flushLog();

                    if (pollTimer) clearInterval(pollTimer);
                    if (summaryTimer) clearInterval(summaryTimer);
                    if (snapshotTimer) clearInterval(snapshotTimer);

                    send({ type: "done", frames: 0 });
                }
            }, durationSec * 1000);
        }
    },

    stop: function () {
        running = false;
        emitSummary();
        flushLog();
        if (pollTimer) clearInterval(pollTimer);
        if (summaryTimer) clearInterval(summaryTimer);
        if (snapshotTimer) clearInterval(snapshotTimer);
        send({ type: "stopped", frames: 0 });
    },

    status: function () {
        return {
            running: running,
            hooks: hookedCount,
            elapsed: elapsed(),
            totalCalls: Object.values(totalCounts).reduce((a, b) => a + b, 0),
        };
    },

    readState: function () {
        const result = {};
        for (const [addr, name, size] of STATE_GLOBALS) {
            try {
                const p = ptr(addr);
                result[name] = size === 1 ? p.readU8() : p.readU32();
            } catch (e) {
                result[name] = "error";
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
    }
};

// ── Auto-init ──────────────────────────────────────────────────────────────
// Hooks are NOT installed on load — wait for start() or installNow() call.
// This prevents crashes during game loading.
send({ type: "ready", hooks: 0 });
