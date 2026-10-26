# Chain 191: AIOutOfTrackEvent — Audio Trigger for Off-Track AI

Seed: FUN_0041a0c0  |  System: docs/02-ai-system.md  |  Depth: 2  |  Functions: 4

---

## Overview

Triggers audio when an AI vehicle goes off-track. Performs guard checks, then plays audio event 0x108 (off-track sound) with full audio emit including driver index.

## Call Tree

```
FUN_0041a0c0 — AIOutOfTrackEvent  [called when AI vehicle leaves track limits]
  +-- FUN_00418a20 — Boolean OR of Two Checks  [guard condition check]
  +-- FUN_004144d0 — Struct Init with Sentinel Values  [audio struct init]
  +-- FUN_004144f0 — Driver Data Table Lookup and Time Conversion  [looks up driver data from table]
  +-- FUN_00418560 — InsertDriverTableEntry  [3 callees — audio event submission]
        +-- FUN_00418b90 — [unnamed — audio helper]
        +-- FUN_00418b70 — [unnamed — audio helper]
        +-- FUN_004145c0 — [unnamed — audio helper]
```

## Step-by-Step Trace

### Level 0: FUN_0041a0c0 — AIOutOfTrackEvent

**Trigger:** Called when an AI vehicle is detected off-track (track limits detection system).

**Called by:** AI track limits subsystem (callers show 0 callers in graph — likely called from track/position update code).

**Purpose:** Triggers audio when AI goes off-track. Guard checks, then full audio emit with driver index.

**Key actions:**
1. Guard checks via FUN_00418a20
2. Initializes audio struct via FUN_004144d0
3. Looks up driver data via FUN_004144f0
4. Emits audio event 0x108 via FUN_00418560 (off-track sound)

### Level 1: Callees

**FUN_00418a20 — Boolean OR of Two Checks**
- Leaf function (docs/20-math-utilities.md)
- Performs guard condition check
- Returns boolean OR of two conditions
- If true, allows audio trigger to proceed

**FUN_004144d0 — Struct Init with Sentinel Values**
- Leaf function (docs/20-math-utilities.md)
- Initializes audio event struct with default/sentinel values
- Prepares the sound event parameters

**FUN_004144f0 — Driver Data Table Lookup and Time Conversion**
- Leaf function (docs/02-ai-system.md)
- Looks up driver data from DriverDataTable (DAT_005bf9b0)
- Converts time value for audio parameter
- Reads driver-specific data from table with stride

**FUN_00418560 — InsertDriverTableEntry**
- 3 callees (FUN_00418b90, FUN_00418b70, FUN_004145c0)
- Submits the audio event to the sound system
- Inserts event data into the audio event table
- Called with audio event type 0x108 (off-track)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Guard check | AI state flags | FUN_00418a20 OR check | Proceed/block |
| Audio init | event struct | FUN_004144d0 sentinel init | Initialized params |
| Driver lookup | driver index | FUN_004144f0 table query | Driver time data |
| Event submit | event type 0x108 | FUN_00418560 insert | Audio event queued |

## Notes

- This is a dedicated off-track audio trigger for AI vehicles only
- Audio event type 0x108 likely maps to "car off track" or "grass/gravel" sound
- The guard check prevents audio spam (limits trigger rate)
- Driver index is included in the audio emit for positional audio (3D panning)
- All 4 callees are from the audio driver/table subsystem

---
