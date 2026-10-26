# Chain: Audio Mixer Polling/Update Loop — Audio Mixer Drain

Seed: 0x00564390  |  System: docs/21-audio-network-internals.md  |  Depth: 3  |  Functions: 4

---

## Overview

Audio Mixer Polling/Update Loop is the background audio mixer drain loop. No callers documented — likely runs as a background thread or is called from the main audio update. It polls a pending-work function and processes audio mix chunks in pairs until the queue is empty. The chain covers work polling, mix-required check, dual-channel mixing operations, and error-handled function pointer dispatch.

## Call Tree

```
FUN_00564390 — Audio Mixer Polling/Update Loop  [trigger: background audio mix tick]
  +-- FUN_00564220 — String tokenizer (strtok-like)  [poll for pending work — leaf]
  +-- FUN_00564410 — [check if mix operation needed — not in functions.json]  [leaf]
  +-- FUN_00564270 — mix operation (called in pairs — L/R channel)
  |     +-- FUN_005647d0 — Callback + Check
  |     +-- FUN_00564690 — String Malloc + Copy (strdup)
  |     +-- FUN_00564780 — Function Pointer Call with Error Handling
  |           +-- FUN_00564a20 — Buffer Index Computation with Stride Division
  |           +-- FUN_005648c0 — Single Function Call Wrapper (error path)
  |           +-- FUN_005649d0 — Call Chain Wrapper (success path)
  +-- FUN_00564780 — Function Pointer Call with Error Handling
        +-- FUN_00564a20 — Buffer Index Computation with Stride Division
        +-- FUN_005648c0 — Single Function Call Wrapper (error path)
        +-- FUN_005649d0 — Call Chain Wrapper (success path)
```

## Step-by-Step Trace

### Level 0: FUN_00564390 — Audio Mixer Polling/Update Loop

**Trigger:** Called per audio update tick (background thread or main update)
**Called by:** No callers documented
**Purpose:** Polling loop that processes audio mixer chunks until queue is empty.

**Key actions:**
1. Calls FUN_00564220 — poll for pending work (advance mixer state)
2. Loop: calls FUN_00564220 (advance/update), then checks FUN_00564410
3. If FUN_00564410 returns non-zero: performs FUN_00564270 twice + FUN_00564780 (mix operation)
4. Continues until FUN_00564220 returns 0 (queue drained)
5. Standard audio mixer pattern: drain pending chunks with conditional mixing

**Data passed to callees:** mixer state pointers, audio buffer handles

### Level 1: FUN_00564220 — Poll for Pending Work

**Trigger:** Called at start of loop and each iteration
**Purpose:** Checks if work remains in mixer queue, advances state. Uses DAT_008cfae4 (state). Returns 0 when drained.

### Level 1: FUN_00564410 — Check if Mix Operation Needed

**Trigger:** Called each iteration after work check
**Purpose:** Returns non-zero if a mix operation should be performed (buffer ready, format conversion needed)

### Level 1: FUN_00564270 — Mix Operation

**Trigger:** Called in pairs (likely left/right stereo channels) when mix needed
**Purpose:** Performs audio mixing operation — combines source audio chunks into output buffer
**Key actions:**
1. FUN_005647d0 — callback + check (validates parameters)
2. FUN_00564690 — string malloc + copy (strdup for buffer labels)
3. FUN_00564780 — function pointer call with error handling (dispatches to mixer backend)

### Level 1: FUN_00564780 — Function Pointer Call with Error Handling

**Trigger:** Called from mix operation and directly from main loop
**Purpose:** Dispatches function pointer call with error handling wrapper
**Key actions:**
1. FUN_00564a20 — buffer index computation with stride-based division
2. FUN_005648c0 — single function call wrapper (error path — handles failures)
3. FUN_005649d0 — call chain wrapper (success path — normal dispatch)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Poll check | mixer state | FUN_00564220 | work available (0 = done) |
| Mix check | buffer state | FUN_00564410 | mix needed (0 = skip) |
| Mix operation | audio chunks ×2 | FUN_00564270 ×2 | mixed output buffers |
| Error handling | function ptr | FUN_00564780 | dispatched call + error guard |

## Globals Written in This Chain

- `DAT_008cfae4` — mixer state string tokenization state (used by FUN_00564220)

## Notes

- FUN_00564220 is documented as "string tokenizer (strtok-like)" — uses mixer state as tokenization context for chunk processing
- FUN_00564270 called in pairs → stereo channel processing (left/right)
- FUN_00564780 serves dual role: both called from mix operation (level 2) AND directly from main loop (level 1) — shared error-handled dispatch utility
- Standard audio mixer drain pattern: poll → check → process → repeat until empty
- FUN_00564410 not in functions.json — undocumented check function
- FUN_00564690 (strdup) suggests buffer labeling/debugging in the audio pipeline

---
