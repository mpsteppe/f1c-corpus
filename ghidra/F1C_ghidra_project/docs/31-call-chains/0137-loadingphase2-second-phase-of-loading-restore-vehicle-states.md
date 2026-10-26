# Chain: LoadingPhase2 — Second phase of loading: restore vehicle states after load

Seed: FUN_004b8940  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 11

---

## Overview

Second phase of the loading sequence. After initial load completes, this function restores vehicle states, seeds the RNG, loads chunks, restores textures and appearance variants, and finalizes loading. Called from the main loading sequence (FUN_004b9890). Seeds RNG with scaled time, restores vehicle state from +0x734 array, restores textures via FUN_004c7aa0, and calls FUN_00411120 to finalize. Releases time handle at end.

## Call Tree

```
FUN_004b8940 — LoadingPhase2  [trigger: post-load completion, second phase]
  +-- FUN_00408450 — SafeDivisionWithZeroGuard  [tick/time scaling for RNG seed]  [leaf]
  +-- FUN_004b8ae0 — StateTriggerCheck  [state machine gating, 15 callees]
  |     +-- [subtree: 15 callees — docs/06, state machine dispatch]
  +-- FUN_004b86e0 — AngleClampWrap  [angle clamping utility]  [leaf]
  +-- FUN_004ef5a0 — SessionStateTransition  [session state transition, 6 callees]
  |     +-- [subtree: 6 callees — docs/06]
  +-- FUN_004e19a0 — UIElementIterateUpdate  [update UI elements, 1 callee]
  +-- FUN_004e0ed0 — AudioSoundEffectController  [audio playback, 4 callees]
  |     +-- [subtree: 4 callees — docs/19]
  +-- FUN_004e3a50 — MultiObjectRemove  [remove objects from scene, 1 callee]
  +-- FUN_004c7aa0 — SetDriverVisibility  [restore driver textures/visibility, 2 callees]
  |     +-- FUN_004c7b20 — [undocumented]
  |     +-- FUN_00587b8a — [undocumented]
  +-- FUN_00411120 — SessionStructureCleanup  [finalize/cleanup session, 1 callee]
  +-- FUN_004c8dc0 — GuardedVirtualCall  [virtual dispatch with null check]  [leaf]
  +-- FUN_00566db0 — StateCheckLookupWrapper  [state check wrapper, 2 callees]
```

## Step-by-Step Trace

### Level 0: FUN_004b8940 — LoadingPhase2

**Trigger:** Post-initial load — called after phase 1 loading is complete
**Called by:** FUN_004b9890 (from callers.json — main loading sequencer)
**Purpose:** Restores vehicle states after initial load — textures, audio, UI, session state.

**Key actions:**
1. Seeds RNG with scaled time (FUN_00408450 divides tick count)
2. Loads chunks via FUN_004b8ae0 (state trigger check with 15 callees)
3. Restores vehicle states from +0x734 array
4. Restores textures and driver appearance variants (FUN_004c7aa0)
5. Calls FUN_00411120 (session structure finalize)
6. Releases time handle
7. Updates audio (FUN_004e0ed0), UI elements (FUN_004e19a0), session state (FUN_004ef5a0)

**Data passed to callees:** loading state struct, vehicle array pointers, scene/texture handles

### Level 1-2: Key callee subtrees

**FUN_004b8ae0 — StateTriggerCheck (15 callees)**
Entry to a large state machine with 15 children. Manages loading/state transition triggers. Cross-system handoff to docs/06-session-race-logic.md.

**FUN_004ef5a0 — SessionStateTransition (6 callees)**
Transitions session between states during loading (e.g., unloaded → loaded → ready). Used to advance the loading pipeline.

**FUN_004e0ed0 — AudioSoundEffectController (4 callees)**
Initializes/restores audio state — reloads sound effects for the session.

**FUN_004c7aa0 — SetDriverVisibility (2 callees)**
Restores driver/car textures and visibility settings after load.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| RNG seed | tick count | safe divide + seed | RNG initialized |
| State restore | vehicle array | copy from +0x734 | vehicles restored |
| Texture restore | driver list | visibility set | textures rendered |
| Session finalize | session state | cleanup/finalize | session ready |
| Audio init | audio state | restart/init | audio ready |

## Globals Read in This Chain

- DAT_008afea0 — session time (RNG seed)
- DAT_007c54f0 — VehiclePtrArray (state restore)

## Notes

- The +0x734 offset in vehicle struct stores pre-load state snapshots for restoration
- FUN_004b8ae0 (15 callees) is the largest subtree — driving most of the loading state machine
- FUN_004e0ed0 audio controller appears in multiple chains (also in pit chain) — shared utility
- FUN_00408450 (safe division) ensures RNG seed never divides by zero

---
