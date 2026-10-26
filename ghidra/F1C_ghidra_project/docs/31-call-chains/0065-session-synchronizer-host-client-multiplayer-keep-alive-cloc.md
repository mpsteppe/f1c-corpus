# Chain: Session Synchronizer (Host/Client) — Multiplayer Keep-Alive & Clock Sync

Seed: FUN_0045f950  |  System: docs/09-track-system.md  |  Depth: 2  |  Functions: 12 callees

---

## Overview

FUN_0045f950 handles multiplayer session synchronization. Called by FUN_00463cd0 (NetComm session update). Has two modes: Host (type 1/2) sends periodic keep-alive packets — accumulates frame time into +0x38c, when it exceeds DAT_0059e7ec timeout, iterates all player slots, checks each via FUN_0045ca20 (ping), and sends type-2 packets via FUN_00462250. Client (type 3) manages clock sync — decrements +0x10 by frame time, when <= 0 refills from +0xc, checks clock offset via FUN_0057a610, displays "Synchronizing game (%d ms)" message via FUN_0045bd10 if offset exceeds threshold, adjusts game time via FUN_0042bda0 if offset is large, and syncs clock via FUN_004f9fc0/FUN_004f9f60. Also handles session reload (FUN_0042cf10) and screen update (FUN_004a0da0) on session type change.

## Call Tree

```
FUN_0045f950 — Session Synchronizer (Host/Client)  [trigger: per-frame NetComm update]
  +-- FUN_00461530 — Slot Active Check  [iterates player slots]
  +-- FUN_0045ca20 — Ping/Terrain Surface Sample  [ping check per slot]
  |     [see Chain 72 for subtree]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [sync progress display]
  +-- FUN_00462250 — Texture Creation Wrapper  [sends keep-alive packet]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_0057a610 — Clock Sync Read  [reads remote clock]
  +-- FUN_0042cf10 — Session Reload  [reinitializes session state]
  +-- FUN_004a0da0 — Screen Update  [updates display state]
  +-- FUN_0045e570 — Open Init  [track open signal]
  +-- FUN_0045bd10 — Text Line Wrapping and Rendering  [sync message display]
  |     +-- FUN_0045bb60 — Color Mapper
  |     +-- FUN_0045b9c0 — Text Utility
  +-- FUN_0042bda0 — Time Adjust  [adjusts game time for clock offset]
  +-- FUN_004f9fc0 — Clock Sync  [synchronizes clock with server]
  +-- FUN_004f9f60 — Clock Read  [reads local clock]
```

## Step-by-Step Trace

### Level 0: FUN_0045f950 — Session Synchronizer (Host/Client)

**Trigger:** Per-frame, called by FUN_00463cd0 (NetComm session update)
**Called by:** FUN_00463cd0
**Purpose:** Host sends keep-alive packets; client syncs clock with server

**Key actions:**
- Host: accumulates param_2 into +0x38c, checks DAT_0059e7ec threshold, iterates slots via FUN_00461530, pings each via FUN_0045ca20, sends keep-alive packet via FUN_00462250
- Client: decrements +0x10 by param_2, checks clock sync via FUN_0057a610, displays sync message, adjusts time via FUN_0042bda0, syncs clock via FUN_004f9fc0

### Level 1: Key Callees

**FUN_0045ca20 — Terrain Surface Roughness/Height Sampling**
- Used as ping check in host mode for each player slot
- Returns surface validity for slot position
- [See Chain 72 for full details]

**FUN_004f9fc0 — Clock Sync**
- Synchronizes local clock with server reference
- Paired with FUN_004f9f60 (clock read)

**FUN_0042bda0 — Time Adjust**
- Adjusts game time when clock offset exceeds large threshold
- Converts offset to integer and applies via FUN_005895a2

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Host: | param_2 (frame time) | Accumulate into +0x38c | Keep-alive timer |
| Host: | +0x38c > DAT_0059e7ec | Send packet | Keep-alive to each slot |
| Client: | param_2 (frame time) | Decrement +0x10 | Timeout check |
| Client: | Clock offset | Compare threshold | "Synchronizing game (%d ms)" |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_0059f0ac | NetTimeoutInterval | (read by) | Timer reset value for +0x1c |
| DAT_0059e7ec | KeepAliveInterval | (read by) | Host keep-alive threshold |
| DAT_007c56a4 | SessionType | (read by) | Session type check |

## Notes

- Host mode iterates all active player slots each keep-alive cycle
- Client mode has two timeout thresholds: display threshold and large-offset threshold
- DAT_0059e7ec is the host keep-alive interval, DAT_0059ea08 is clock sync tolerance
- Cross-system: FUN_0042bda0 (time adjust) is documented in docs/06-session-race-logic.md
- FUN_004f9fc0/FUN_004f9f60 are clock sync utilities (docs/20-math-utilities.md)

---
