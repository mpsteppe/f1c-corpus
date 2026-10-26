# Known Bugs — F1 Challenge 99-02

Bugs found through static analysis and runtime tracing of the decompiled binary.
Each entry includes root cause, reproduction steps, and fix status.

---

## BUG-001: AI Simplified Driving After Instant Replay

**Severity:** High — AI vehicles crash at first corner after replay exit
**Reproducibility:** 100% with early replay; present but less visible with late replays
**Affected versions:** All (original bug in shipping binary)
**Fix status:** ROOT CAUSE IDENTIFIED — no working patch yet

### Reproduction

1. Start a race (any track, any car count)
2. Immediately after lights out, press Instant Replay
3. Replay has little data, rewinds to grid start
4. Exit replay — race restarts from grid
5. Lights go out — AI cars accelerate but drive straight into first corner

Worst on short tracks (Monaco). On long straights (Monza), AI recovers before
first corner via the backup enable timer.

### Observed Behavior

AI vehicles accelerate normally on straights but cannot steer through corners.
They go straight, miss apexes, and crash heavily. Driving is visibly "simplified" —
no racing line following, no braking zones, no overtake logic.

### Runtime-Confirmed Vehicle Struct Layout

Frida traces (v3/v4) revealed the vehicle struct uses sub-objects at different
offsets from the vehicle array pointer (DAT_007c54f0):

**AI sub-object = vehPtr + 0 (no offset):**
All AI functions (FUN_00424e70 AI Update, FUN_00424790 AI Reset, FUN_0042adb0
AI Enable) receive ECX = vehicleArrayPtr directly. Confirmed by delta capture:
`[AI_UPDATE] ECX=0x5ec6d8 delta=0` matching `veh[0] ptr=0x5ec6d8`.

**Physics sub-object = vehPtr + 0xC:**
FUN_004ef5a0 (Vehicle State Setter) receives ECX = vehicleArrayPtr + 12.
Confirmed: `[STATE_SET] ECX=0x5ec6e4 delta_from_vehPtr=12`.

**Back-pointer at physics sub-object offset 0:**
`*(vehPtr + 0xC) == vehPtr`. The first 4 bytes of the physics sub-object point
back to the base vehicle object. FUN_004ef5a0 uses `mov ecx, [esi]` before
calling FUN_0042adb0, dereferencing through this back-pointer.

**Vehicle stride:** 0x48C0 bytes (confirmed: 0x5f0f98 - 0x5ec6d8 = 0x48C0).

| Absolute offset | Int index | Sub-object | Field | Values |
|-----------------|-----------|------------|-------|--------|
| vehPtr+0x32C8 | phys+0x32BC | Physics | Vehicle Physics State | 0=inactive, 1=active, 3=replay |
| vehPtr+0x45F4 | ai+0x45F4 | AI (base) | AI Driving Active | 0=simplified, 1=full racing |
| vehPtr+0x4410 | ai+0x4410 | AI (base) | AI Enable Guard | 0=allow, 1=block FUN_0042adb0 |

Note: storedPhase (param_1[0x1113]) and aiState (param_1[0x1144]) offsets from
the decompiler are INT-indexed from the AI this pointer. Byte offsets
0x1113×4=0x444C and 0x1144×4=0x4510 were NOT verified at runtime. The values
read at those offsets during traces looked like float bit patterns (e.g.
1065353216 = 0x3F800000 = 1.0f), suggesting the int-index multiply may be wrong
for these fields or they store floats.

### Root Cause (Confirmed via Runtime Tracing)

**InternalState gate in FUN_004ef5a0 blocks AI re-enable during early replay.**

#### The Gate (FUN_004ef5a0, disassembly at 0x004ef623)

```asm
004ef623: 83 3d 9c567c00 05   cmp dword [007c569c], 5    ; InternalState == 5?
004ef62a: 75 46               jne short 004ef672          ; if not → RETURN
; --- AI_ENABLE path (only reachable when InternalState == 5) ---
004ef62c: 83 ff 01            cmp edi, 1                  ; old physState == 1?
004ef62f: 74 41               je  short 004ef672          ; yes → skip (already active)
004ef631: 83 be bc320000 01   cmp [esi+0x32BC], 1         ; new physState == 1?
004ef638: 75 38               jne short 004ef672          ; no → skip
; Falls through to call FUN_0042adb0 (AI Enable)
004ef64d: 8b 0e               mov ecx, [esi]              ; ECX = *this = vehPtr (back-pointer)
004ef64f: e8 5cb7f3ff         call FUN_0042adb0           ; AI Enable
```

When `param_3 == 0` (used by both replay exit AND normal startup), code jumps
directly to 004ef623. If InternalState != 5, function returns without reaching
AI_ENABLE.

#### Why Mid-Race Replay Works

- InternalState == 5 during mid-race → gate passes → AI_ENABLE fires for all
  22 AI vehicles during 3→1 transition → aiDrv restored to 1 immediately
- Runtime confirmed: all AI vehicles show `aiDrv=1` in snapshots after replay exit

#### Why Early Replay Breaks

- InternalState < 5 during pre-race/early race → gate blocks → AI_ENABLE skipped
- aiDrv stays 0 after AI_RESET (FUN_00424790 line 81 clears it)
- AI runs in simplified mode: full throttle, no steering, no braking

#### Backup Enable (FUN_00424e70, Simplified Branch)

When aiDrv == 0, AI Main Update takes the simplified branch. A backup enable
exists at lines 196-198:

```c
if (DAT_007c56a8 != param_1[0x1113]) {   // phase changed?
    timer -= frame_delta;
    if (timer < threshold) {              // timer expired?
        FUN_00424c80();                   // formation handler (sets param_1+0x4448)
        if ((DAT_007c56a8 == 5) || (DAT_007c56a8 == 1)) {  // phase check
            FUN_0042adb0();               // AI enable
        }
        param_1[0x1113] = DAT_007c56a8;  // update stored phase
    }
}
```

This backup has TWO delays:
1. **Timer delay** (param_1[0x1112]): must count down to threshold before firing
2. **Phase check**: only fires on Phase 5 or 1 (not GREEN_FLAG/Phase 3)

On Monaco (short straight), the timer delay alone is enough to cause crashes.

### Failed Fix Attempts

**Attempt 1 — Save offset change (VA 0x004b87c0):**
Changed displacement to save vehicle[0x32BC] instead of vehicle[0x32C8]. All
cars bunched into one grid slot. The enable path in FUN_004ef5a0 clears
`*vehicle+0x4354/0x4358` (grid positioning fields).

**Attempt 2 — Phase 5→3 comparison (VA 0x00424f0b):**
Changed `cmp eax, 5` to `cmp eax, 3` in backup enable. Partially worked —
AI recovered on Monza but not Monaco. Timer delay left seconds of simplified
driving before enable fired.

**Attempt 3 — NOP jne (VA 0x00424f10):**
NOPed `75 0c` to `90 90`, making FUN_0042adb0 fire unconditionally on any
phase transition in simplified mode. Still doesn't fix Monaco — the timer
delay at param_1[0x1112] introduces a gap before enable fires.

### Proposed Fix (Not Yet Attempted)

**Patch FUN_004ef5a0: NOP the InternalState gate at 0x004ef62a.**

| VA | File Offset | Original | Patched | Effect |
|---|---|---|---|---|
| `0x004ef62a` | `0x0ef62a` | `75 46` | `90 90` | Skip InternalState != 5 return |

This makes the AI_ENABLE path fire on ANY X→1 transition regardless of
InternalState. During replay exit, all vehicles get aiDrv=1 immediately
(no timer delay).

**Risk:** During normal game startup, FUN_004ef5a0(1,0) is called for 0→1
transition. If InternalState isn't 5 at that point (likely — formation phase),
this would also call AI_ENABLE, potentially breaking formation driving by
enabling full AI too early. Side effects include:
- FUN_0042aca0() called with session param
- `*param_1 + 0x4354` and `*param_1 + 0x4358` cleared (grid fields)
- FUN_0042adb0's own guard (0x4410 check) provides partial safety

**Safer alternatives not yet explored:**
1. Patch only the jump target at 004ef5bd (`74 64` → `74 6d`) to skip the
   InternalState check only when param_3==0. But normal startup ALSO uses
   param_3=0, so same risk.
2. Add code cave: check if old physState was 3 (replay) before enabling.
   Only 3→1 transition would bypass the gate; 0→1 (normal start) would not.
3. Patch FUN_00424790 (AI_RESET) to NOT clear aiDrv (NOP line 81). Replay
   would preserve aiDrv=1. Risk: other callers of AI_RESET rely on clearing.
4. Patch the timer value: make param_1[0x1112] start at 0 in AI_RESET,
   so backup enable fires on first frame. Combined with attempt 3 (NOP jne),
   this would recover AI within 1 frame.

### Frida Trace Data (Diagnostic Runs)

**Trace v3 (delta capture):** confirmed AI=vehPtr+0, Physics=vehPtr+0xC.
**Trace v4 (correct offsets):** mid-race replay at Phase=4, all 22 AI vehicles
get aiDrv=1 during replay exit. aiDrv stays 1 in all 15 snapshots. No bug
observed — mid-race replay has InternalState=5, so the gate passes.

Early replay scenario (InternalState < 5) was not captured in any trace.
Frida diagnostic agent is at `tools/trace/agent_replay_diag.js` (v4).

### Cross-References

- AI Main Update: docs/02-ai-system.md (FUN_00424e70)
- AI Reset: FUN_00424790 — clears aiDrv and 40+ other AI state fields
- AI Enable: FUN_0042adb0 — 28-byte function, guard + 2 field writes
- Vehicle State Setter: FUN_004ef5a0 — InternalState gate at 004ef623
- Formation Timer: FUN_00424c80 — writes param_1+0x4448 (randomized delay)
- AI field clear: FUN_0042ae00 — zeroes 20 dwords at param_1+0x4354
- Replay Enter: FUN_004b87c0 — saves physState, calls FUN_004ef5a0(3,0)
- Replay Exit: FUN_004b8940 — restores saved state via FUN_004ef5a0(saved,0)
- Replay Data Load: FUN_004b8da0 — triggers vehicle reset when data runs out
