# Chain: TimedAudioEventPlayback — Plays timed events from sorted linked list schedule

Seed: FUN_004b9510  |  System: docs/21-audio-network-internals.md  |  Depth: 2  |  Functions: 5

---

## Overview

Plays timed audio events from a sorted linked list schedule, iterating over a time range. Early-out if param_2 == param_3 (no range). Adjusts range bounds by lookahead/latency offset based on playback direction. Maintains cursor at param_1 + 0x71c (current position in linked list). Walks linked list to find first event with time >= param_2, then iterates events while within range dispatching callbacks.

## Call Tree

```
FUN_004b9510 — TimedAudioEventPlayback  [trigger: per-frame during audio event processing]
  +-- FUN_00566db0 — StateCheckLookupWrapper  [state validation, 2 callees]
  |     +-- [subtree: 2 callees — docs/20]
  +-- FUN_004b4450 — WrapperPassThrough  [event dispatch wrapper, 1 callee]
  |     +-- FUN_00587bcf — FreeWrapper [leaf]
  +-- FUN_004b44a0 — FileOperationOpenWrite  [file/buffer operation, 2 callees]
  |     +-- [subtree: 2 callees — docs/20]
  +-- FUN_004b4360 — StreamReadConditionalScale  [reads from stream, scales by constant]  [leaf]
  +-- FUN_004b3a90 — StructCopyWithHeaderSize  [struct copy with header]  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004b9510 — TimedAudioEventPlayback

**Trigger:** Per-frame during audio event processing — iterates scheduled events
**Called by:** FUN_004b9b80 (from callers.json)
**Purpose:** Play timed audio events from sorted linked list schedule within a time range.

**Key actions:**
1. Early-out if param_2 == param_3 (empty time range)
2. Adjusts range bounds by lookahead/latency offset (direction-dependent)
3. Maintains cursor at param_1 + 0x71c (current list position)
4. Walks linked list to find first event with timestamp >= param_2
5. Iterates events while timestamp within range, dispatching audio callbacks
6. Uses FUN_004b4450 for event dispatch, FUN_004b44a0 for buffer operations

**Data passed to callees:** event list pointer, time range (param_2, param_3), audio callback data

### Level 1: Callees

**FUN_00566db0 — StateCheckLookupWrapper (2 callees)**
Validates audio system state before dispatching events. Returns whether audio is ready.

**FUN_004b4450 — WrapperPassThrough (1 callee)**
Dispatches the audio event callback — calls the registered handler for the event type.

**FUN_004b44a0 — FileOperationOpenWrite (2 callees)**
Handles buffer/file operations — likely for audio sample data access.

**FUN_004b4360 — StreamReadConditionalScale [leaf]**
Reads from audio stream, optionally scales value by constant. Used for audio sample processing.

**FUN_004b3a90 — StructCopyWithHeaderSize [leaf]**
Copies audio event struct with header size adjustment.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Range check | param_2, param_3 | == check | skip or proceed |
| Adjust | range + offset | lookahead/latency | adjusted range |
| Seek | cursor +0x71c | list walk | first event in range |
| Iterate | event list | while time < param_3 | dispatched events |
| Dispatch | event data | callback | audio played |

## Notes

- The lookahead/latency offset adjustment allows pre-loading audio events before their exact timestamp
- Cursor at +0x71c maintains state between frames — avoids re-scanning entire list each frame
- FUN_004b3a90 (struct copy) suggests events are copied to a processing queue before dispatch

---
