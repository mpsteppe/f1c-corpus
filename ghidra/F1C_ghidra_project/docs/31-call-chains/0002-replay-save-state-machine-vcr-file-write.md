# Chain: Replay Save State Machine — VCR File Write

Seed: FUN_004b7500  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 19

---

## Overview

Triggered by replay recording request during a race session. Handles saving vehicle state data to VCR replay files. Guards on replay data presence flags at param_1+0x6e4. Two code paths: (1) first-time save with header init and car state capture, or (2) ongoing save appending to existing file via linked list of entries. Displays "Saving Replay" HUD message during write. Uses Miles Sound System (MSS) file I/O wrappers for cross-platform file operations. Calls FUN_004b5f60 for cleanup after save completes.

## Call Tree

```
FUN_004b7500 — Replay Save State Machine  [trigger: param_1+0x700==1 (first save) or param_1+0x6d0!=0 (ongoing)]
  +-- FUN_004b52a0 — [undocumented replay util]
  +-- FUN_004b6190 — Car State Capture  [iterated 0x68 times]
  +-- FUN_004b7a00 — Replay Header Init  [writes file header data]
  +-- FUN_00423a00 — String Copy  [for "Saving Replay" message]
  +-- FUN_004a0e70 — Message Display  ["Saving Replay" HUD message]
  +-- FUN_00566940 — File I/O Status Check
  |     +-- FUN_00566b90 — File Close  [MSS]
  |     +-- FUN_005668d0 — Unlock  [MSS AIL_unlock]
  +-- FUN_00566b90 — File Close  [MSS]
  +-- FUN_005668d0 — Unlock  [MSS AIL_unlock]
  +-- FUN_004b6a10 — Lap Data Write
  +-- FUN_00566b20 — Stream Open  [MSS file open/stream start]
  |     +-- [path: FUN_00566650 — Path Registry]
  |     +-- FUN_00566c00 — Stream Read  [MSS packet streaming]
  |     +-- FUN_00566bd0 — Stream  [MSS streaming helper]
  +-- FUN_00566c00 — Stream Read  [MSS — reads recorded state]
  +-- FUN_00566bd0 — Stream  [MSS — streaming data]
  +-- FUN_004b8010 — Replay Save Finalize
  +-- FUN_00566650 — Path Registry  [path prep for output file]
  +-- FUN_00566db0 — Entry Write  [writes single replay entry]
  +-- FUN_004b5f60 — Cleanup  [post-save cleanup]
```

## Step-by-Step Trace

### Level 0: FUN_004b7500 — Replay Save State Machine

**Trigger:** Called during replay recording (race session active, replay buffer non-empty).
**Called by:** Parent replay manager; callers: 2 (from callers.json).
**Purpose:** Serializes vehicle/race state to VCR replay file on disk.

**Key actions:**
1. Guards on param_1+0x6e4 (replay data present flag)
2. **First-time path** (param_1+0x700==1):
   - 0x68 iterations of FUN_004b6190 (car state capture)
   - Calls FUN_004b7a00 (replay header init)
   - If session not in state 4 AND replay duration threshold met AND param_2 != 0:
     - Displays "Saving Replay" + Sleep(100ms)
     - Opens output file via FUN_00566940 with subfolder index (0-4 from param_1+0x9a4)
     - Writes lap data via FUN_004b6a10
     - Streams car state: FUN_00566b20 + read loop FUN_00566c00/FUN_00566bd0
     - Closes file
   - Calls FUN_004b8010 (replay save finalize)
3. **Ongoing path** (param_1+0x700!=1 AND param_1+0x6d0!=0):
   - Clears flag at param_1+0x6d0
   - Displays "Saving Replay" + Sleep(100ms)
   - Opens output file from param_1+0xf94 path
   - Writes header: FUN_00566650 (path prep) + FUN_004b6a10 (lap data)
   - Iterates linked list at param_1+0x714: writes each entry via FUN_00566db0 + streaming
   - Closes file
4. Final: clears param_1+0x700, calls FUN_004b5f60

**Data passed to callees:** param_1 replay struct (offset 0x6e4/0x700/0x6d0 flags, 0xf94 filepath, 0x714 linked list head), param_2 state flag

### Level 1: FUN_004b7a00 — Replay Header Init

**Trigger:** Called on first-time save path to write header.
**Purpose:** Initializes VCR file header structure with replay metadata.

### Level 1: FUN_00566940 — File I/O Status Check

**Trigger:** Called to verify file handle and status before streaming.
**Purpose:** Wraps MSS AIL file status operations.
**Data passed down:** file handle from open, buffer pointers for state data.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b7500 | param_1+0x700 | Check first-save flag | Branch path selection |
| FUN_004b6190 | car state array | 0x68 iterations capture | state structs to VCR |
| FUN_004b7a00 | header template | Write replay header | VCR file header |
| FUN_004b6a10 | lap data | Write lap data block | VCR lap section |
| FUN_00566db0 | entry nodes | Linked list serialize per entry | VCR data entries |
| FUN_004b5f60 | cleanup params | Post-write cleanup | Resources freed |

## Globals Written in This Chain

None identified — operates on param_1 struct fields only.

## Notes

- Two distinct save paths: first-time (header + bulk capture) vs ongoing (append entries from linked list)
- Uses Sleep(100ms) before write — likely to let disk catch up
- MSS file wrappers (FUN_00566xxx series) abstract cross-platform file I/O
- The car state capture (FUN_004b6190) is called 0x68 = 104 times, one per vehicle slot

---

---
