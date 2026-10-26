# Chain: SessionTickUpdate — Per-Frame Session Dispatch

Seed: FUN_004c6b60  |  System: docs/06-session-race-logic.md  |  Depth: 4  |  Functions: 10

---

## Overview

Per-frame session update function with no tracked callers (possibly called via vtable or thunk from the main loop). Dispatches timer updates, track position checks, AI driver updates, pit state handling during race sessions. Most complex sub-branch handles jumped start / grid penalty detection with 8 callees. Secondary branches handle AI path tracking and camera viewport init.

## Call Tree

```
FUN_004c6b60 — SessionTickUpdate  [trigger: per-frame, no tracked callers]
  +-- FUN_004bc9b0 — JumpedStartPenaltyDetection  [8 callees]
  |     +-- FUN_004d10e0 — Grid Position Lookup
  |     +-- FUN_004efb20 — Vehicle World Position
  |     +-- FUN_004bbd60 — ApplyStopGoPenalty
  |     +-- FUN_004bc0e0 — ApplyJumpedStartPenalty
  |     +-- FUN_0045bd10 — HUD Display
  |     +-- FUN_0045bde0 — Warning Display
  |     +-- FUN_00566e40 — Track Data
  |     +-- FUN_00423a00 — String Copy
  +-- FUN_004ef7c0 — AIVehiclePathPositionTracking  [4 callees, 9 offsets]
  +-- FUN_00424b20 — CameraViewportFrustumInit  [4 callees]
  +-- FUN_004e9600 — SuspensionStateUpdate  [2 callees]
  +-- FUN_0040d100 — GameStateBranchDispatch  [2 callees]
  +-- 6 additional leaf callees omitted
```

## Step-by-Step Trace

### Level 0: FUN_004c6b60 — SessionTickUpdate

**Trigger:** No tracked callers in call_graph (callers=0 per function.json — possibly vtable/thunk dispatch)
**Called by:** Unknown (callers.json has no entries for this address)
**Purpose:** Per-frame session update — timer, track pos, AI, pit handling.

**Key actions:**
1. Calls timer, track position, pause check
2. On-track: AI driver update, player-specific update
3. Off-track: AI recovery
4. If session 7 + phase 3/4: pit update

**Data passed to callees:** Session state, vehicle array, race phase.

### Level 1: FUN_004bc9b0 — JumpedStartPenaltyDetection

**Trigger:** Called during race phase transitions (phase 3/4)
**Purpose:** Detects jumped starts and improper grid alignment. Deployed during race start.

**Key actions:**
1. Reads vehicle velocity from +0x3500/0x34fc/0x34f8
2. If param_2 == 0 (jumped start check):
   - Compares velocity to threshold
   - Computes position relative to grid via FUN_004d10e0 and FUN_004efb20
   - Dot product of movement direction vs grid forward direction
   - If velocity > threshold + forward movement: displays warning, applies stop-go penalty
3. If param_2 != 0 (grid alignment check):
   - Compares velocity and position offset to thresholds
   - If off-grid: displays "Not Lined Up Properly" warning

**Globals:** DAT_007cef84 (PenaltiesEnabled), DAT_005ec4cc (MessageBuffer)

**Struct offsets:** +0x34f8 (Velocity Z), +0x34fc (Velocity Y), +0x3500 (Velocity X), +0x34c4 (Grid direction X)

### Level 2: FUN_004d10e0 — Grid Position Lookup

**Trigger:** Called from penalty detection
**Purpose:** Looks up vehicle grid position from grid array.

### Level 2: FUN_004efb20 — Vehicle World Position

**Trigger:** Called from penalty detection
**Purpose:** Gets vehicle's current world position for grid alignment check.

### Level 2: FUN_004bbd60 — ApplyStopGoPenalty

**Trigger:** Called from penalty detection when jumped start confirmed
**Purpose:** Applies 10-second stop-go penalty to vehicle.

### Level 2: FUN_004bc0e0 — ApplyJumpedStartPenalty

**Trigger:** Called from penalty detection
**Purpose:** Applies jumped start penalty (alternative to stop-go).

### Level 2: FUN_0045bd10 — HUD Display

**Trigger:** Called from penalty detection
**Purpose:** Updates HUD display with penalty information.

### Level 1: FUN_004ef7c0 — AIVehiclePathPositionTracking

**Trigger:** Called during AI update phase
**Purpose:** Tracks AI vehicle position along track path. 9 struct offsets for path data.

### Level 1: FUN_00424b20 — CameraViewportFrustumInit

**Trigger:** Called during session update
**Purpose:** Initializes camera viewport and frustum parameters. 4 callees.

### Level 1: FUN_004e9600 — SuspensionStateUpdate

**Trigger:** Called during physics update phase
**Purpose:** Updates suspension state per vehicle.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004c6b60 | Session state, race phase | Phase dispatch | Per-system updates |
| FUN_004bc9b0 | Vehicle velocity, grid pos | Velocity/direction checks | Penalty or clear |
| FUN_004d10e0 | Grid array | Position lookup | Grid position index |
| FUN_004efb20 | Vehicle struct | Position read | World position |
| FUN_004bbd60 | Penalty reason | State set | Stop-go penalty active |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007cef84 | PenaltiesEnabled | FUN_004bc9b0 (reader) | If != 0, penalties applied |
| DAT_005ec4cc | MessageBuffer | FUN_004bc9b0 (writer via warning) | Warning message text |

## Notes

- The seed has no tracked callers in call_graph (0 entries in callers.json) — likely dispatched via vtable or inlined thunk
- Most complex callee is FUN_004bc9b0 (JumpedStartPenaltyDetection) with 8 sub-callees, all documented
- Penalty thresholds referenced: _DAT_0059e43c (velocity), _DAT_005acd70 (stopped), _DAT_0059f124 (forward), _DAT_0059e908 (reverse), _DAT_0059e920 (speed limit)
- 6 additional leaf callees omitted from call tree

---
