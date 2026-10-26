# Chain: AI Command/Message Queue Dispatcher — AI Driver Communication

Seed: 0x00424cd0  |  System: docs/02-ai-system.md  |  Depth: 4  |  Functions: 5

---

## Overview

Dispatches commands to AI driver and maintains command queue. Triggered by AI events (lap validation, pit flag clear, timestamps, pit state logic). Appends (command, value) pairs to a queue with dedup, then processes via command response handler. Output: AI driver state updates based on queued commands.

## Call Tree

```
0x00424cd0 — AI Command/Message Queue Dispatcher  [trigger: AI event — lap, pit, timestamp]
  +-- 0x004a46f0 — Indexed Field Setter with Flag  [queue field init, leaf]
  +-- 0x0042adb0 — Session Cleanup Flag Clear  [leaf]
  +-- 0x004c6d90 — SceneRenderUpdate  [leaf]
  +-- 0x004a5c80 — StateChangeNotify  [docs/02, 2 sub-calls]
  |     +-- 0x004b33b0 — Notification/Log  [leaf]
  |     +-- 0x004a5d10 — Ring Buffer Process  [docs/02, 9 sub-calls — AI state machine]
  |           +-- (9 sub-calls — complex AI state update)
  +-- 0x00429ee0 — Command Queue Response Handler  [docs/02, 4 sub-calls]
        +-- 0x0042adb0 — Session Cleanup Flag Clear  [leaf]
        +-- 0x0042ac90 — WrapPlayerCallback  [docs/02, 1 sub-call]
        |     +-- 0x0042aa50 — [leaf]
        +-- 0x0042acd0 — [leaf]
        +-- 0x0042aca0 — AISpeedDeltaSetter  [docs/02, 1 sub-call]
              +-- 0x0042aad0 — [leaf]
```

## Step-by-Step Trace

### Level 0: 0x00424cd0 — AI Command/Message Queue Dispatcher

**Trigger:** AI event — valid lap completed (4), clear pit flag (5), store timestamp (1), pit state logic (0xf).
**Called by:** 0x00424790, 0x00426430 (component event log), 0x004a68b0, 0x00424b20.
**Purpose:** Dispatches commands to AI driver, maintains command queue.

**Key actions:**
1. Branches on param_2: 4=valid lap, 5=clear pit flag, 1=store timestamp, 0xf=pit state logic
2. Queue management at +0x112a (array), +0x112c (count), +0x112b (capacity)
3. Appends (param_2, param_3) pair with dedup check
4. Calls FUN_00429ee0 to process queued command

**Data passed to callees:** AI driver struct pointer (param_1), command ID (param_2), command value (param_3).

### Level 1: Key Sub-functions

**0x004a5c80 — StateChangeNotify**
Notifies state change. Logs notification, then processes through ring buffer (0x004a5d10 — 9 sub-calls, AI state machine update).

**0x00429ee0 — Command Queue Response Handler**
4 sub-calls. Processes the queued command: wraps player callback, sets AI speed delta, clears session flags.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00424cd0 | ai ptr, cmd, val | branch on cmd ID | queue append |
| FUN_004a5c80 | ai ptr, cmd | state change notify | log + ring buffer |
| FUN_00429ee0 | ai ptr | cmd processing | player callback, speed delta |

## Globals Written in This Chain

None documented — all mutations through AI driver struct fields.

## Notes

Chain reaches depth 4 through the ring buffer processor (0x004a5d10) which has 9 sub-calls for full AI state machine update. Four different callers invoke this dispatcher from different AI subsystems (event log, timer, pit logic). The dedup queue prevents duplicate commands from stacking.

---
