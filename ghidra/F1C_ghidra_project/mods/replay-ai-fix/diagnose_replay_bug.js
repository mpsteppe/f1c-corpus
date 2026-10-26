// Frida diagnostic: trace AI state during replay enter/exit.
// Run on UNPATCHED exe: frida -p <F1C pid> -l diagnose_replay_bug.js
//
// Reproduces: start race, press instant replay early, exit replay.
// Script logs vehicle field values at each critical moment.
'use strict';

const BASE = ptr('0x00400000');

// Globals
const pVehicleArray = ptr('0x007c54f0');  // int*[] — vehicle pointer array
const pVehicleCount = ptr('0x005c329c');  // int
const pRacePhase    = ptr('0x007c56a8');  // int
const pInternalState= ptr('0x007c569c');  // int
const pGameState    = ptr('0x007d00ec');  // int

// Vehicle struct field offsets (byte)
const OFF_PHYSICS_STATE = 0x32BC;  // param_1[0xCAF] — 0=inactive, 1=active, 3=replay
const OFF_AI_GATE       = 0x32C8;  // param_1[0xCB2] — entry gate in AI Main Update
const OFF_AI_DRIVING    = 0x45F4;  // param_1[0x117D] — 0=simplified, 1=full AI
const OFF_STORED_PHASE  = 0x44CC;  // param_1[0x1113] — stored RacePhase in AI
const OFF_AI_TIMER      = 0x4448;  // param_1[0x1112] — phase transition timer
const OFF_THROTTLE_OUT  = 0x3584;  // param_1[0xD61] — throttle output
const OFF_STEER_OUT     = 0x357C;  // param_1[0xD5F] — steering output
const OFF_BRAKE_OUT     = 0x3580;  // param_1[0xD60] — brake output
const OFF_AI_STATE      = 0x4510;  // param_1[0x1144] — AI state machine

function readVehicle(idx) {
  const count = pVehicleCount.readU32();
  if (idx >= count) return null;
  return pVehicleArray.add(idx * 4).readPointer();
}

function dumpVehicle(veh, label) {
  const physState  = veh.add(OFF_PHYSICS_STATE).readU32();
  const aiGate     = veh.add(OFF_AI_GATE).readU32();
  const aiDriving  = veh.add(OFF_AI_DRIVING).readU8();
  const storedPh   = veh.add(OFF_STORED_PHASE).readU32();
  const aiTimer    = veh.add(OFF_AI_TIMER).readFloat();
  const throttle   = veh.add(OFF_THROTTLE_OUT).readFloat();
  const steer      = veh.add(OFF_STEER_OUT).readFloat();
  const brake      = veh.add(OFF_BRAKE_OUT).readFloat();
  const aiState    = veh.add(OFF_AI_STATE).readU32();
  console.log(label +
    ' phys=' + physState +
    ' gate=' + aiGate +
    ' aiDrv=' + aiDriving +
    ' storedPh=' + storedPh +
    ' timer=' + aiTimer.toFixed(3) +
    ' thr=' + throttle.toFixed(2) +
    ' str=' + steer.toFixed(3) +
    ' brk=' + brake.toFixed(2) +
    ' aiSt=' + aiState);
}

function dumpAllVehicles(tag) {
  const count = pVehicleCount.readU32();
  const phase = pRacePhase.readU32();
  const istate = pInternalState.readU32();
  const gstate = pGameState.readU32();
  console.log('\n=== ' + tag + ' === RacePhase=' + phase +
    ' InternalState=' + istate + ' GameState=' + gstate +
    ' VehicleCount=' + count);
  const n = Math.min(count, 4);  // first 4 vehicles
  for (let i = 0; i < n; i++) {
    const veh = readVehicle(i);
    if (veh) dumpVehicle(veh, '  veh[' + i + ']');
  }
}

// Hook FUN_004b87c0 — Replay Enter
Interceptor.attach(ptr('0x004b87c0'), {
  onEnter: function () {
    dumpAllVehicles('REPLAY ENTER');
  },
  onLeave: function () {
    dumpAllVehicles('REPLAY ENTER (after)');
  }
});

// Hook FUN_004b8940 — Replay Exit
Interceptor.attach(ptr('0x004b8940'), {
  onEnter: function () {
    dumpAllVehicles('REPLAY EXIT');
  },
  onLeave: function () {
    dumpAllVehicles('REPLAY EXIT (after)');
  }
});

// Hook FUN_00424790 — AI Reset
Interceptor.attach(ptr('0x00424790'), {
  onEnter: function (args) {
    this.veh = this.context.ecx;  // thiscall, ECX = this
    this.param2 = args[0];
  },
  onLeave: function () {
    const aiDrv = this.veh.add(OFF_AI_DRIVING).readU8();
    const storedPh = this.veh.add(OFF_STORED_PHASE).readU32();
    console.log('[AI_RESET] param2=' + this.param2 +
      ' veh=' + this.veh +
      ' aiDrv_after=' + aiDrv +
      ' storedPh_after=' + storedPh);
  }
});

// Hook FUN_004ef5a0 — Vehicle State Setter (sample only, high frequency)
let stateSetCount = 0;
Interceptor.attach(ptr('0x004ef5a0'), {
  onEnter: function (args) {
    this.veh = this.context.ecx;
    this.newState = args[0].toInt32();
    this.param3 = args[1].toInt32();
    const oldState = this.veh.add(OFF_PHYSICS_STATE).readU32();
    // Only log transitions involving state 3 (replay) or mismatches
    if (oldState === 3 || this.newState === 3 || stateSetCount < 10) {
      stateSetCount++;
      const aiDrv = this.veh.add(OFF_AI_DRIVING).readU8();
      console.log('[STATE_SET] veh=' + this.veh +
        ' old=' + oldState + ' new=' + this.newState +
        ' p3=' + this.param3 + ' aiDrv=' + aiDrv);
    }
  },
  onLeave: function () {
    if (this.newState === 1) {
      const aiDrv = this.veh.add(OFF_AI_DRIVING).readU8();
      console.log('[STATE_SET done] new=1 aiDrv_after=' + aiDrv +
        ' veh=' + this.veh);
    }
  }
});

// Hook FUN_0042adb0 — AI Driving Enable
Interceptor.attach(ptr('0x0042adb0'), {
  onEnter: function () {
    const veh = this.context.ecx;
    const guard = veh.add(0x4410).readU8();
    const before = veh.add(OFF_AI_DRIVING).readU8();
    console.log('[AI_ENABLE] veh=' + veh +
      ' guard_0x4410=' + guard + ' aiDrv_before=' + before);
  },
  onLeave: function () {
    const veh = this.context.ecx;
    const after = veh.add(OFF_AI_DRIVING).readU8();
    console.log('[AI_ENABLE done] aiDrv_after=' + after);
  }
});

// Periodic snapshot — log state every 2 seconds for 30 seconds after replay exit
let snapshotTimer = null;
let snapshotCount = 0;

Interceptor.attach(ptr('0x004b8940'), {
  onLeave: function () {
    snapshotCount = 0;
    if (snapshotTimer) clearInterval(snapshotTimer);
    snapshotTimer = setInterval(function () {
      snapshotCount++;
      if (snapshotCount > 15) {
        clearInterval(snapshotTimer);
        snapshotTimer = null;
        return;
      }
      dumpAllVehicles('SNAPSHOT t+' + (snapshotCount * 2) + 's');
    }, 2000);
  }
});

console.log('\n[replay_diag] Loaded. Reproduce: start race -> instant replay -> exit.');
console.log('[replay_diag] Logging first 4 vehicles at each critical point.');
console.log('[replay_diag] Snapshots every 2s for 30s after replay exit.\n');
