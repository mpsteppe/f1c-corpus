# Chain: Replay Playback Loader — Replay VCR File Loading and Initialization

Seed: 0x004ba1f0  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 17

---

## Overview

Triggered by replay init (FUN_0042d6b0) during game state transition into replay/load mode. Loads a VCR replay file from disk, parses packet-stream data into replay buffers, and initializes replay playback state (buffers, seek position, play/pause state). On success transitions replay state machine to "data ready" (state 2). On failure resets to idle (state 0).

Dat_007d0038 and DAT_007d005c gate replay availability; replay struct fields at param_1+0xf94 (VCR file path), param_1[0] (state machine index).

## Call Tree

```
0x004ba1f0 — Replay Playback Loader  [trigger: game enters replay/load state]
  +-- 0x004d7a50 — String Split Loop / assert  [source check, 2 sub-callees]
  +-- 0x00566b20 — AudioStreamOpen  [opens VCR file for reading, 4 sub-callees]
  +-- 0x00566940 — file I/O status  [opens output file]
  +-- 0x00423a00 — string copy  ["Prepping Replay" message]
  +-- 0x004a0e70 — message display  [shows "Prepping Replay"]
  +-- 0x004b9830 — replay buffer  [alloc 0x80 bytes]
  +-- 0x00568540 — File Attributes + Existence Check  [timer/sync, 2 sub-callees]
  +-- 0x004b97d0 — replay data check  [validates data]
  +-- 0x004b9810 — replay flag  [sets flag]
  +-- 0x004b9da0 — MenuActionDispatch  [state update → "data ready", 5 sub-callees]
  +-- 0x004b9820 — post-load config trampoline
  +-- 0x0042bbd0 — post-load config
  +-- 0x0042bc40 — post-load config
  +-- 0x004b87a0 — replay data init trampoline
  +-- 0x004b86e0 — AngleClampWrap / replay data init
  +-- 0x00566c00 — File Write with Backend Dispatch  [packet streaming read, 2 sub-callees]
  +-- 0x00566bd0 — Conditional Dispatch  [packet stream process]
```

## Step-by-Step Trace

### Level 0: 0x004ba1f0 — Replay Playback Loader

**Trigger:** Called by FUN_0042d6b0 (replay init) during game state transition
**Called by:** 0x0042d6b0 (replay init, docs/01-engine-architecture.md)
**Purpose:** State machine that loads VCR replay file and initializes playback buffers

**Key actions:**
1. Reads state at param_1[0]: 0/1 = guard check, 2 = active load
2. State 0/1: checks FUN_00404f10() return, DAT_007d0038, DAT_007d005c — gates replay availability
3. State 2: asserts source, opens VCR file via FUN_00566b20 from path at param_1+0xf94
4. Displays "Prepping Replay" message, allocates 0x80-byte replay buffer
5. Opens output file, reads packets in loop (FUN_00566c00 → FUN_00566bd0)
6. On success: sets state=2, calls FUN_004b9da0(5) → replay data ready
7. Calls FUN_004b86e0 for replay data initialization

**Data passed to callees:** param_1 (replay struct pointer), file paths from struct offsets

### Level 1: 0x004b9da0 — MenuActionDispatch (state update)

**Trigger:** Called by replay loader on successful load (param=5: data ready)
**Called by:** 0x004ba1f0 (Replay Playback Loader)
**Purpose:** Dispatches replay playback state transitions (reset, seek, play, pause, stop)

**Key actions:**
1. Dispatches on param (0-4): reset (0x004b81a0), seek/rewind (0x004b8360), play start (0x004b8480), pause (0x004b84f0), stop (0x004b85d0)
2. Called with param=5 from replay loader to signal data ready

**Data passed to callees:** param_1 (replay struct), action code

### Level 1: 0x00566c00 — File Write with Backend Dispatch

**Trigger:** Called in read loop to stream packet data
**Called by:** 0x004ba1f0 (Replay Playback Loader)
**Purpose:** Read/write abstraction with lock mechanism

**Key actions:**
1. Calls 0x0058803f (lock/write/unlock) for thread safety
2. Calls 0x00534f90 (alt sink) for alternate data routing

**Data passed to callees:** file handle, buffer pointer, size

### Level 1: 0x00568540 — File Attributes + Existence Check

**Trigger:** Called for timer/sync during replay loading
**Called by:** 0x004ba1f0 (Replay Playback Loader)
**Purpose:** Checks file attributes and existence

**Key actions:**
1. Calls 0x0058ba36 (file attribute toggle)
2. Calls 0x0058986e (file delete/check)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x004ba1f0 | param_1[0] (state) | Switch on state | 0/1 = guard, 2 = load |
| 0x004ba1f0 | param_1+0xf94 (path) | File open via 0x00566b20 | VCR file handle |
| 0x004ba1f0 | operator_new(0x80) | Allocate buffer | replay buffer |
| 0x004ba1f0 | file handle | Read loop via 0x00566c00/0x00566bd0 | parsed replay packets |
| 0x004b9da0 | param=5 | Dispatch to data-ready state | playback state = ready |

## Globals Written in This Chain

None (all state changes are on the replay struct at param_1)

## Notes

- 12 of 17 callees are leaf functions (no significant sub-tree)
- The file I/O callees (0x00566b20, 0x00566940, 0x00566c00, 0x00566bd0) are shared with audio/replay/network subsystems
- FUN_004b9da0 is the most complex subtree with 5 playback control callees
- Replay data init (0x004b86e0) is labeled "AngleClampWrap" in graph but described as "replay data init" in the call chain context
---
