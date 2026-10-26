// Frida agent v4: correct offsets confirmed via delta capture.
// AI sub-object = vehPtr+0 (no offset). Physics sub-object = vehPtr+0xC.
'use strict';

const pVehicleArray  = ptr('0x007c54f0');
const pVehicleCount  = ptr('0x005c329c');
const pRacePhase     = ptr('0x007c56a8');
const pGameState     = ptr('0x007d00ec');

// Correct offsets from vehicle array pointer (vehPtr + 0 = AI base)
const AI = {
  aiDriving:    0x45F4,  // 0=simplified, 1=full (confirmed: AI funcs use vehPtr+0)
  guard4410:    0x4410,  // if 1, blocks AI enable
  storedPhase:  0x44CC,  // stored RacePhase in AI
  aiState:      0x4510,  // AI state machine
  field4424:    0x4424,  // cleared by AI_ENABLE
};

// Physics sub-object at vehPtr+0xC (STATE_SET this = vehPtr+0xC)
const PHYS = {
  physState:    0x32C8,  // 0xCAF from this: (vehPtr+0xC)+0x32BC = vehPtr+0x32C8
};

function getVehPtrs() {
  const count = pVehicleCount.readU32();
  const ptrs = [];
  for (let i = 0; i < count && i < 24; i++) {
    ptrs.push(pVehicleArray.add(i * 4).readPointer());
  }
  return ptrs;
}

function vehStr(v) {
  const phys = v.add(PHYS.physState).readU32();
  const aiDrv = v.add(AI.aiDriving).readU8();
  const guard = v.add(AI.guard4410).readU8();
  const stPh = v.add(AI.storedPhase).readU32();
  const aiSt = v.add(AI.aiState).readU32();
  return 'phys=' + phys + ' aiDrv=' + aiDrv + ' guard=' + guard +
    ' stPh=' + stPh + ' aiSt=' + aiSt;
}

function dumpAll(tag) {
  const ph = pRacePhase.readU32();
  const gs = pGameState.readU32();
  const ptrs = getVehPtrs();
  console.log('\n=== ' + tag + ' === Phase=' + ph + ' GState=' + gs +
    ' count=' + ptrs.length);
  for (let i = 0; i < Math.min(ptrs.length, 6); i++) {
    console.log('  [' + i + '] ' + vehStr(ptrs[i]));
  }
}

// --- Hooks ---

// Replay Enter
Interceptor.attach(ptr('0x004b87c0'), {
  onEnter() { dumpAll('REPLAY ENTER'); },
  onLeave() { dumpAll('REPLAY ENTER (done)'); }
});

// Replay Exit
Interceptor.attach(ptr('0x004b8940'), {
  onEnter() { dumpAll('REPLAY EXIT (start)'); },
  onLeave() {
    dumpAll('REPLAY EXIT (done)');
    startSnapshots();
  }
});

// AI Reset — fires during replay data loading
Interceptor.attach(ptr('0x00424790'), {
  onEnter(args) {
    this.ecx = ptr(this.context.ecx.toString());
    const aiDrv = this.ecx.add(AI.aiDriving).readU8();
    const p2 = args[0].toInt32();
    console.log('[AI_RESET] p2=' + p2 + ' aiDrv_before=' + aiDrv);
  },
  onLeave() {
    const aiDrv = this.ecx.add(AI.aiDriving).readU8();
    const stPh = this.ecx.add(AI.storedPhase).readU32();
    console.log('[AI_RESET] done aiDrv=' + aiDrv + ' stPh=' + stPh);
  }
});

// AI Enable
let enableCount = 0;
Interceptor.attach(ptr('0x0042adb0'), {
  onEnter() {
    this.ecx = ptr(this.context.ecx.toString());
    const guard = this.ecx.add(AI.guard4410).readU8();
    const aiDrv = this.ecx.add(AI.aiDriving).readU8();
    if (enableCount < 30) {
      enableCount++;
      console.log('[AI_ENABLE] guard=' + guard + ' aiDrv_before=' + aiDrv);
    }
  },
  onLeave() {
    const aiDrv = this.ecx.add(AI.aiDriving).readU8();
    if (enableCount <= 30) {
      console.log('[AI_ENABLE] done aiDrv=' + aiDrv);
    }
  }
});

// Vehicle State Setter — transitions involving replay state (3)
let stateCount = 0;
Interceptor.attach(ptr('0x004ef5a0'), {
  onEnter(args) {
    this.physEcx = ptr(this.context.ecx.toString()); // vehPtr + 0xC
    this.newSt = args[0].toInt32();
    this.oldSt = this.physEcx.add(0x32BC).readU32();
    if ((this.oldSt === 3 || this.newSt === 3) && stateCount < 10) {
      stateCount++;
      console.log('[STATE_SET] ' + this.oldSt + '->' + this.newSt);
    }
  }
});

// FUN_004b8da0 — Replay data loading (triggers AI reset when replay runs out of data)
Interceptor.attach(ptr('0x004b8da0'), {
  onEnter() {
    console.log('[REPLAY_LOAD] Phase=' + pRacePhase.readU32());
  }
});

// Snapshots after replay exit
let snapTimer = null;
let snapN = 0;
function startSnapshots() {
  snapN = 0;
  enableCount = 0;  // reset for post-replay enables
  if (snapTimer) clearInterval(snapTimer);
  snapTimer = setInterval(function () {
    snapN++;
    if (snapN > 15) { clearInterval(snapTimer); snapTimer = null; return; }
    const ph = pRacePhase.readU32();
    const ptrs = getVehPtrs();
    let line = 't+' + snapN + 's Ph=' + ph;
    for (let i = 0; i < Math.min(ptrs.length, 3); i++) {
      const v = ptrs[i];
      line += ' v' + i + ':[' + v.add(PHYS.physState).readU32() + '/' +
        v.add(AI.aiDriving).readU8() + '/' + v.add(AI.guard4410).readU8() + ']';
    }
    console.log(line);
  }, 1000);
}

console.log('\n[replay_diag] v4 — CORRECT OFFSETS (AI=vehPtr+0, Phys=vehPtr+0xC)');
console.log('[replay_diag] IMPORTANT: To reproduce bug, press replay DURING THE LIGHTS');
console.log('[replay_diag]   or within 1-2 seconds after lights out. NOT mid-race.');
console.log('[replay_diag] Snapshots show [physState/aiDrv/guard] per vehicle.\n');
