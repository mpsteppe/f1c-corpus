# Chain: NetComm Session Message Dispatcher — Multiplayer Packet Dispatch

Seed: FUN_0045d890  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 21 callees

---

## Overview

FUN_0045d890 is the central network message handler for multiplayer sessions. Called by FUN_0045f710 (NetComm session update loop) when a network packet arrives. Decodes a 32-bit header from param_2: bits 29-31 = base type, bits 18-23 = 6-bit message subtype. Dispatches to case handlers that manage session setup (case 2), player grid data (3), server verify (4), next track (5), track start/load (6), player disconnect (0x20), file mismatch check (0x24), track file transfer (0x27), and sync/timeout (0x2a). Modifies DAT_008aff00 (session ready flag), DAT_005f0774 (network buffer), and per-slot struct fields. Produces [name] messages via message buffer FUN_004a0e70 and display FUN_0045bd10. On disconnect, triggers cleanup via FUN_0057a660 and displays "[name] was removed from the game".

## Call Tree

```
FUN_0045d890 — NetComm Session Message Dispatcher  [trigger: network packet arrives]
  +-- FUN_00460710 — Conditional Render State Update  [session sync, case 2]
  |     +-- FUN_00461470 — Thunk to FUN_00461480  [buffer write init]
  |     +-- FUN_004623e0 — Forwards call  [buffer lock]
  |     +-- FUN_004614f0 — Bitfield Set/Clear  [flag set/message type]
  |     +-- FUN_004623b0 — Short Computation  [buffer unlock]
  |     +-- FUN_004b0170 — Empty Stub (vtable slot)  [game state update]
  +-- FUN_00423a00 — Binary Search in String Table  [string lookup for messages]
  |     +-- FUN_00588410 — [leaf]  [string compare]
  +-- FUN_004a0e70 — Session Type Guard  [message buffer poll]
  |     +-- FUN_004989e0 — [leaf]
  +-- FUN_0045bd10 — Text Line Wrapping and Rendering  [message display]
  |     +-- FUN_0045bb60 — ID to Color Mask Mapper  [color conversion]
  |     +-- FUN_0045b9c0 — General utility  [text render]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [progress bar, code 4/6]
  +-- FUN_0045e5f0 — Array Scan for Match  [slot allocation]
  +-- FUN_0045e5b0 — Searches int array for -1  [find empty slot]
  +-- FUN_0045e5d0 — Short Computation  [array setter]
  +-- FUN_00462250 — Texture Creation Wrapper  [buffer write / packet send]
  |     +-- FUN_00587bcf — Free Wrapper  [cleanup]
  +-- FUN_00460520 — NetComm::SetSelfAsReady  [register self with server]
  |     +-- FUN_0057a810 — Single Function Call Wrapper  [self node ID]
  +-- FUN_00462300 — Single Function Dispatch  [local player ID lookup]
  +-- FUN_0045eb50 — Node ID to Player Name Lookup  [name formatting]
  |     +-- FUN_004d7a50 — String Split Loop  [parse]
  |     +-- FUN_004d7aa0 — Debug Log Write  [output]
  +-- FUN_0057a660 — Dual Virtual Dispatch Wrapper  [disconnect/cleanup]
  +-- FUN_00462460 — Copies driver data block  [track data prep]
  +-- FUN_0045bc50 — String Copy with Format Query  [deserialize]
  |     +-- FUN_0045bc10 — String Format Wrapper
  +-- FUN_00566650 — String Copy with Buffer Realloc  [path registry]
  +-- FUN_00434030 — Doubly-Linked List Append  [list mgmt]
  +-- FUN_0045ebd0 — Linked List Purge  [network cleanup]
  +-- FUN_004b3a90 — Arithmetic/Comparison  [message process]
```

## Step-by-Step Trace

### Level 0: FUN_0045d890 — NetComm Session Message Dispatcher

**Trigger:** Network packet received by FUN_0045f710 (NetComm session update loop)
**Called by:** FUN_0045f710 (NetComm update)
**Purpose:** Main network message handler; dispatches by message type encoded in header bits 18-23

**Key actions:**
1. Reads `*param_2` header: bits 29-31 = base type, bits 18-23 = 6-bit subtype
2. Dispatches to 12+ case handlers based on subtype
3. Case 3: iterates VehiclePtrArray (DAT_007c54f0), reads TeamID (+0x4894) and BestLapTime (+0x409c), sets DAT_008aff00=1
4. Case 0x20: calls FUN_0045eb50 for name lookup, FUN_0057a660 for disconnect
5. Case 0x24: validates 5 files against host, calls FUN_004b33b0 progress bar
6. Case 0x2a: manages sync state transitions, adjusts timeout accumulator +0x390

**Data passed to callees:** param_1 (session struct), param_2 (packet data pointer)

### Level 1: Key Callees

**FUN_00460520 — NetComm::SetSelfAsReady**
- Registers self as server node or client slot
- Calls FUN_00461470/FUN_004623e0 for buffer init/lock
- Sets DAT_007d0e50 readiness flag
- On host: allocates slot via FUN_0045e5b0/FUN_0045e5d0
- On client: uses server-assigned slot ID

**FUN_0045bd10 — Text Line Wrapping and Rendering**
- Formats and renders message text
- Calls FUN_0045bb60 for color mask mapping
- Calls FUN_0045b9c0 for general text rendering utility

**FUN_0045eb50 — Node ID to Player Name Lookup**
- Resolves node/player ID to display string
- Calls FUN_004d7a50 for string split/parse
- Calls FUN_004d7aa0 for debug logging

**FUN_004b33b0 — ProgressBarEventEncode**
- Updates progress bar display for file transfers
- Code 4: file mismatch, Code 6: track file transfer

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045d890 | Network packet header | Decode bits 18-23 | Case dispatch |
| Case 3 | VehiclePtrArray | Iterate by TeamID (+0x4894) | Grid data at DAT_005f0774 |
| Case 3 | BestLapTime (+0x409c) | Copy to network buffer | Grid lap data |
| Case 0x24 | 5 file paths | Compare vs host | Mismatch linked list |
| Case 0x2a | +0x390 accumulator | Adjust timeout | Sync state transition |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008aff00 | SessionReadyFlag | FUN_0045d890 (case 3) | Set to 1 when grid data received |
| DAT_005f0774 | NetBufferData | FUN_0045d890 (case 4) | Shared network data buffer stride 0x1230 |
| DAT_007d0e50 | ReadinessFlag | FUN_00460520 | Self-registered as ready |
| DAT_007d2e50 | SessionMsgCounter | FUN_0045d890 (default) | Incremented per message |
| DAT_0083ee54 | SessionDataOffset | FUN_0045d890 (default) | Incremented by stride 0x1b0 |

## Notes

- Most callees are leaf utilities (string copy, list append, array scan) — the real work is in the switch cases themselves
- Case dispatch reads the header directly from param_2; session data buffer at DAT_005f0774 is stride 0x1230
- Progress bar callbacks (FUN_004b33b0) are used for file transfer status display
- Player name formatting uses FUN_0045eb50 for node ID-to-name resolution
- Cross-system: message display (FUN_0045bd10) is renderer/UI, file mismatch involves file system access

---
