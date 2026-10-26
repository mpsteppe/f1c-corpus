# Chain: Season/Data File Setup Chain — Season initialization

Seed: FUN_0046d060  |  System: docs/08-file-formats.md  |  Depth: 5  |  Functions: ~16

---

## Overview

Season/Data File Setup Chain (FUN_0046d060) initializes session data for a new season. It calls SessionStructInit (FUN_0042e320) to set up session structures, Vehicle Setup File Writer (FUN_0042fd00) to load vehicle setup data from files, and ScoreSlotDeallocator (FUN_0042ddd0) for cleanup. The main subtree is FUN_0042fd00 with 7 callees including file write wrappers, format strings, and file I/O.

## Call Tree

```
FUN_0046d060 — Season/Data File Setup Chain  [trigger: season/race setup]
  +-- FUN_005881c0 — Stack Probe / alloca  [stack init]
  +-- FUN_0042e320 — SessionStructInit  [session struct init]
  |     +-- FUN_0042e1c0 — Struct initializer (28-byte state block)  [sub-array clear]
  |     +-- FUN_0042dc60 — Small Data Struct Init  [session setup]
  |     +-- FUN_0042e400 — PenaltyStructInit  [penalty finalize]
  +-- FUN_0042fd00 — Vehicle Setup File Writer  [vehicle setup file load]
  |     +-- FUN_00566c30 — Buffer Write with String Length Check  [section/value write]
  |     |     +-- FUN_0058a163 — File Write Wrapper with Lock  [string write]
  |     |     |     +-- FUN_0058c1b1 — CritSect Lock
  |     |     |     +-- FUN_0058e41b — File Position
  |     |     |     +-- FUN_0058d04d — Format Engine (vsnprintf)
  |     |     |     +-- FUN_0058e4a8 — Position Update
  |     |     |     +-- FUN_0058c203 — CritSect Unlock
  |     |     +-- FUN_0058ac95 — Safe String Format  [format]
  |     |     |     +-- FUN_0058d04d — Format Engine
  |     |     |     +-- FUN_0058cf35 — Overflow Handler
  |     |     +-- FUN_00535220 — Buffer Fill with Timeout  [alloc]
  |     |           +-- FUN_00588678 — File Read Wrapper with Lock
  |     |           +-- FUN_00535e80 — [undocumented]
  |     |           +-- FUN_00536e90 — [PARTIAL] CRC
  |     +-- FUN_00566b90 — File Close with Flag Dispatch  [file close]
  |     |     +-- [same lock/fclose/unlock pattern as chain 210]
  |     +-- FUN_005668d0 — Sub-Call with Conditional Field Free  [cleanup]
  |     |     +-- FUN_00566b90 — File Close
  |     |     +-- FUN_00587bcf — Free Wrapper
  |     +-- FUN_004d7a50 — String Split Loop  [error logging]
  |     |     +-- FUN_00587c20 — String Compare
  |     |     +-- FUN_004d7aa0 — Debug Log Write
  |     +-- FUN_005668b0 — Zero-Init Small Struct  [file open]
  |     +-- FUN_00566940 — File Status Check
  |     +-- FUN_004d7aa0 — Debug Log Write
  +-- FUN_004b0770 — [undocumented]  [init]
  +-- FUN_0042ddd0 — ScoreSlotDeallocator  [slot free]
  |     +-- FUN_00587bcf — Free Wrapper
  +-- FUN_00587bcf — Free Wrapper
```

## Step-by-Step Trace

### Level 0: FUN_0046d060 — Season/Data File Setup Chain

**Trigger:** Season/race initialization
**Called by:** Not in callers.json (called from setup state machine)
**Purpose:** Initialize session data for a season, load vehicle setups

**Key actions:**
1. Stack init via FUN_005881c0
2. Call FUN_0042e320 (SessionStructInit) — 3 sub-callees for struct clear, session setup, penalty init
3. Call FUN_0042fd00 (Vehicle Setup File Writer) — file open, section/value write, file close, cleanup, error logging
4. Call FUN_004b0770 (undocumented init)
5. Call FUN_0042ddd0 (ScoreSlotDeallocator) — free slot memory
6. Free wrapper cleanup

### Level 1: FUN_0042e320 — SessionStructInit

**Trigger:** Called from Season Setup
**Called by:** FUN_0046d060
**Purpose:** Initialize session data structures

**Key actions:**
1. Clear 28-byte state sub-array via FUN_0042e1c0
2. Init small data struct via FUN_0042dc60
3. Init penalty struct via FUN_0042e400

### Level 1: FUN_0042fd00 — Vehicle Setup File Writer

**Trigger:** Called from Season Setup
**Called by:** FUN_0046d060
**Purpose:** Load vehicle setup from file

**Key actions:**
1. Open file via FUN_005668b0, status check via FUN_00566940
2. Write section/value via FUN_00566c30 — uses locked file I/O with format engine
3. Close file via FUN_00566b90
4. Cleanup via FUN_005668d0
5. Error logging via FUN_004d7a50/004d7aa0

## Notes

- FUN_0058a163 (File Write Wrapper with Lock) repeats the lock → write → unlock pattern seen in chain 210
- FUN_00535220 (Buffer Fill with Timeout) adds CRC computation to the file I/O path
- FUN_004b0770 is undocumented — likely a season config initializer
- DAT_007ce668 (Season/Data path) is the global directory path read by this function

---
