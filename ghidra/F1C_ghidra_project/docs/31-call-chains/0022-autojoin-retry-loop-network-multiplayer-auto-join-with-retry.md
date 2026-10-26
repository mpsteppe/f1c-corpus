# Chain: AutoJoin Retry Loop — Network multiplayer auto-join with retry loop

Seed: FUN_004637a0  |  System: docs/09-track-system.md  |  Depth: 5  |  Functions: 43

---

## Overview

AutoJoin Retry Loop implements the multiplayer session auto-join flow in NetComm.cpp. Called when a client attempts to join a network session, it initializes the join attempt, polls session state in a retry loop with frame timing, and either transitions to `Client Team Select` on success or navigates to `AutoJoin Failure Page` on failure. It reads timeout values from globals, manages session state transitions, cleans up stale vehicles on successful join, and sets the session active flag.

## Call Tree

```
FUN_004637a0 — AutoJoin Retry Loop  [trigger: client join request]
  +-- FUN_00463750 — AutoJoin Init  [resets join state] LEAF
  +-- FUN_00462ce0 — Join Attempt  [sends join request]
  |     +-- FUN_0057a580 — VTable Call via Offset 0x6c  [network dispatch] LEAF
  +-- FUN_00461cd0 — Session State Query  [checks connection state]
  |     +-- FUN_0057a900 — Single Delegation Call
  |           +-- FUN_00585d20 — Mutex-Protected Pointer Read + Release  LEAF
  +-- FUN_004630d0 — Join Complete Check  [reads config/ID after connect]
  |     +-- FUN_0057a880 — VTable Query with Stack Buffer  LEAF
  |     +-- FUN_0057a8e0 — COM VTable Call via +0xc4  LEAF
  |     +-- FUN_0057a230 — Byte-Aligned Memory Copy from Struct  LEAF
  |     +-- FUN_0057a8b0 — VTable Call via Offset 0x7c  LEAF
  +-- FUN_00461550 — Session Finalize
  |     +-- FUN_00461560 — Struct Init with Default Values  LEAF
  +-- FUN_004ef5a0 — Vehicle Unload / Scene Clear
  |     +-- FUN_004efb20 — 3D Transform with Matrix Multiply  LEAF
  |     +-- FUN_004ef7c0 — AI Vehicle Path Position Tracking
  |     |     +-- FUN_00566e40 — EulerToRotationMatrix  LEAF
  |     |     +-- FUN_004ef680 — RideHeightDelta  LEAF
  |     |     +-- FUN_004e9bd0 — 3x3 Matrix Transform with Translation  LEAF
  |     |     +-- FUN_0043e4b0 — RigidBodyConstraintSolve
  |     |           +-- ... (4 callees, docs/18)
  |     +-- FUN_00447780 — Suspension Force Computation
  |           +-- FUN_00447e00 — Position/Lap State Update
  |           |     +-- FUN_004f89a0 — [undocumented] (2 sub-callees)
  |           +-- FUN_004471f0 — SuspensionVibration  LEAF
  |           +-- FUN_00569280 — Copy 6 Dwords to Struct  LEAF
  |           +-- FUN_0056bde0 — [undocumented]  LEAF
  |           +-- FUN_005692a0 — Quadric/Tensor Math (Double)  LEAF
  +-- FUN_0042bc80 — Vehicle Array Rebuild  LEAF
  +-- FUN_00497940 — Page Navigate (UI)
  |     +-- FUN_004976c0 — UI List Search by Name (Extended)
  |     |     +-- FUN_00588410 — [undocumented]  LEAF
  |     +-- FUN_00497890 — General Utility (undocumented)  LEAF
  +-- FUN_00466080 — Join Failure Check
  |     +-- FUN_00566650 — String Copy with Buffer Realloc  LEAF
  +-- FUN_00462da0 — Failure Reason String  LEAF
  +-- FUN_004b0170 — Game State Update  LEAF
  +-- FUN_00568ba0 — Frame Poll  LEAF
  +-- FUN_00568be0 — Frame Poll  LEAF
  +-- FUN_00568c60 — Frame Poll  LEAF
  +-- FUN_00568cf0 — Frame Poll
  |     +-- FUN_00568cb0 — QPC Timestamp Read Wrapper  LEAF
  +-- FUN_00568d90 — Frame Poll / Current Time
        +-- FUN_00568cb0 — QPC Timestamp Read Wrapper  LEAF
```

## Step-by-Step Trace

### Level 0: FUN_004637a0 — AutoJoin Retry Loop

**Trigger:** client-side join request in NetComm multiplayer flow
**Called by:** network state machine
**Purpose:** orchestrates auto-join with retry loop

**Key actions:**
1. Checks flag at param_1+0xc6 — returns immediately if zero
2. Selects timeout from DAT_007d0410/DAT_007d0418/DAT_007d041c
3. Calls FUN_00463750 (init) + FUN_00462ce0 (join attempt)
4. On failure: logs "Could not autojoin session"
5. On success: enters retry loop displaying "Joining Session"
6. Checks session state via FUN_00461cd0 — if state==3: calls FUN_004630d0
7. On connect success: cleans up vehicles (FUN_004ef5a0), rebuilds array (FUN_0042bc80), sets DAT_007c5690=1, DAT_007c56a0=2
8. Navigates to Client Team Select (FUN_00497940) on success, AutoJoin Failure Page on failure

### Level 1: Important Sub-callees

**FUN_004ef5a0 — Vehicle Unload:** Deepest branch (depth 5). Calls scene clear + AI position tracking + suspension math. FUN_00447780 (Suspension Force Computation) has 7 callees of its own including Position/Lap State Update (docs/06).

**FUN_00497940 — Page Navigate:** UI navigation with list search (FUN_004976c0 -> FUN_00588410, both leaves).

**FUN_00466080 — Join Failure Check:** Delegates to FUN_00566650 (string copy).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00463750 | param_1+0xc6 flag | reset/init join state | ready for join |
| FUN_00462ce0 | session target info | network send join request | pending join |
| FUN_00461cd0 | session handle | poll state via vtable | state==3 connected |
| FUN_004630d0 | session handle | read config/ID | session config |
| FUN_004ef5a0 | vehicle array | unload + scene clear | empty scene |
| FUN_0042bc80 | global array | rebuild vehicle array | fresh array |
| FUN_00497940 | page target ID | UI navigate | new page active |
| DAT_007c5690=1 | session active | global write | session active flag |
| DAT_007c56a0=2 | session type=Client Team Select | global write | session type |

## Globals Written

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007c5690 | InitStateFlag | FUN_004637a0 | 1 = session active |
| DAT_007c56a0 | MultiplayerFlags | FUN_004637a0 | 2 = Client Team Select |
| DAT_007d0410 | RaceMode | Read | timeout selection |
| DAT_007d0418 | SessionTimeoutOverride | Read | alternate timeout |
| DAT_007cc9e8 | SessionInitState | Read | exit/cancel flag |
| DAT_007d0f28 | AutoJoinTimeout | Read | join timeout threshold |

## Notes

- **16 direct callees** — largest fan-out in NetComm subsystem
- **5 sub-chains:** join init, session polling, vehicle cleanup (deepest, depth 5), UI navigation, frame timing loop
- **Deepest path:** FUN_004637a0 -> FUN_004ef5a0 -> FUN_00447780 -> FUN_00447e00 -> FUN_004f89a0 (depth 5)
- **Convergence:** FUN_00568cb0 (QPC timestamp) called from 2 frame poll callees
- **Doc span:** docs/02, docs/06, docs/09, docs/10, docs/18, docs/19, docs/20

---
