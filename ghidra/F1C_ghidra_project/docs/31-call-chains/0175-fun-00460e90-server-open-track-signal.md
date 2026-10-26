# Chain 174: FUN_00460e90 — Server Open Track Signal

Seed: FUN_00460e90  |  System: docs/09-track-system.md  |  Depth: 2  |  Functions: 9

---

## Overview

NetComm server function that sends "opening track" signal to all connected clients during multiplayer session setup. Allocates a message node, formats "*** Opening " string, registers a progress bar event, sends network packets, and appends the message to the server's message linked list. Sets the opening flag at param_1+0x29. Called when server admin opens the track for clients to join.

## Call Tree

```
FUN_00460e90 — Server Open Track Signal  [called by: server admin opening track]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [leaf]
  +-- FUN_0057a680 — COM VTable Call via +0x60  [leaf]
  +-- FUN_0057a6a0 — Network Send Dispatch  [leaf]  [cross-system: docs/21]
  +-- FUN_0057a690 — Virtual Method Dispatch (vtable+100)  [leaf]
  +-- FUN_004c5920 — TrackName Reader  [leaf]  [cross-system: docs/08]
  +-- FUN_00566650 — String Copy with Buffer Realloc  [leaf]
  +-- FUN_004d7a50 — String Split Loop
  |     +-- FUN_00587c20  [undocumented]
  |     +-- FUN_004d7aa0 — Debug Log Write
  +-- FUN_004d7aa0 — Debug Log Write  [leaf]
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)
        +-- FUN_0058aa6f — heap deallocation function
```

## Step-by-Step Trace

### Level 0: FUN_00460e90 — Server Open Track Signal

**Trigger:** Server admin opens track for clients
**Called by:** FUN_00461020 (handler 2), FUN_00463760 (handler 3)
**Purpose:** Broadcasts "track open" signal, allocates message node, logs

**Key actions:**
1. Calls FUN_004b33b0(4,0x26,...) — progress bar event for opening
2. Network send via FUN_0057a680/FUN_0057a6a0/FUN_0057a690 — sends open signal to clients
3. Sets param_1 + 0x29 = 1 (opening flag)
4. Allocates 8-byte message node, fills with 0 and -1
5. Formats "*** Opening " string via FUN_00566650 (string copy)
6. If DAT_007d0398 (network active): appends to param_1 linked list (at +0x1b770 head, +0x1b774 tail, +0x1b77c count)

**Globals read:** DAT_008afea0 (elapsed time), DAT_007c569c (session type), DAT_007d0398 (network active flag)

### Level 1: FUN_0057a6a0 — Network Send Dispatch

**Purpose:** Dispatches network packet send
**Cross-system:** docs/21-audio-network-internals.md

**Key actions:**
- Sends header data for "track open" signal via network layer

### Level 1: FUN_004d7a50 — String Split Loop

**Purpose:** Splits/processes string for debug logging

**Key actions:**
1. Calls FUN_00587c20 (string op)
2. Calls FUN_004d7aa0 to write debug log

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Track open | event code 0x26 | FUN_004b33b0 | progress bar update |
| Network send | header data | FUN_0057a6a0 | packet to clients |
| Message | "*** Opening " + track | FUN_00566650 | formatted string |
| Linked list | +0x1b770/4/c | append node | updated message queue |

## Notes

- Mirror function: FUN_00461020 (Server Close Track Signal) with event code 0x25
- FUN_004c5920 (TrackName Reader) is a cross-system handoff to file formats (docs/08)
- FUN_0057a6a0 (Network Send Dispatch) is cross-system to audio/network (docs/21)
- Most callees are leaf functions — chain is shallow (depth 2 max)

---
