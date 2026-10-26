# Chain: FIA Short Bink Video — Pre-race intro video playback

Seed: FUN_004a00a0  |  System: docs/06-session-race-logic.md  |  Depth: 4  |  Functions: ~16

---

## Overview

FIA Short Bink Video (FUN_004a00a0) plays the `"FIAShort.bik"` intro video before a race session. Called during race UI setup. It hides the cursor, checks if mode==4 (race) and session==7 (race session) and videos enabled (DAT_007d032c==1), then builds a path from `<track_path>\FIAShort.bik` and plays via FUN_004f9b70 (Bink playback with retry UI). After playback, performs camera/viewport setup and cleanup.

## Call Tree

```
FUN_004a00a0 — FIA Short Bink Video  [trigger: race UI setup, pre-race]
  +-- FUN_004f9b70 — Bink Play (with retry UI)  [play FIAShort.bik]
  |     +-- FUN_004d7a50 — String Split Loop  [assert/scope]
  |     +-- FUN_005881c0 — Stack Probe / alloca  [stack init]
  |     +-- FUN_005668b0 — Zero-Init Small Struct  [file open]
  |     +-- FUN_00566b20 — AudioStreamOpen  [file check]
  |     |     +-- FUN_00566b90 — File Close with Flag Dispatch  [close previous]
  |     |     +-- FUN_00568620 — Buffer Alloc  [undocumented]
  |     |     +-- FUN_00534b00 — Single Call Wrapper  [stream open]
  |     |     +-- FUN_00566650 — String Copy with Buffer Realloc  [header read]
  |     +-- FUN_00568540 — File Attributes/Existence Check  [timer/sync]
  |     +-- FUN_00566c00 — File Write with Backend Dispatch  [packet stream]
  |     |     +-- FUN_0058803f — Thread-Safe Read Wrapper  [lock/read/unlock]
  |     |     +-- FUN_00534f90 — Buffered File Reader  [alt sink]
  +-- FUN_00463e00 — Conditional Dispatch on state==3  [video state check]
  +-- FUN_004a0d30 — Global State Setter  [state update]
  +-- FUN_0042d210 — undocumented
  +-- FUN_00453560 — Camera/Viewport Config Batch  [camera setup]
  +-- FUN_00434000 — File Load with Flag Preserve  [load]
  +-- FUN_004c6d90 — SceneRenderUpdate  [scene update]
  +-- FUN_004efa40 — VehicleClimbAdjust  [pit state]
  +-- FUN_004e4910 — Collision Wrapper with Lock  [collision]
  +-- FUN_004d4a80 — Telemetry Data Dump  [finalize]
  +-- FUN_004a4000 — General Utility  [unknown]
  +-- FUN_004a3b50 — Camera / Position Animation  [camera anim]
```

## Step-by-Step Trace

### Level 0: FUN_004a00a0 — FIA Short Bink Video

**Trigger:** Race UI setup — called before race session display
**Called by:** Not in callers.json (likely called via UI state machine)
**Purpose:** Play FIAShort.bik intro video with state management

**Key actions:**
1. Hide cursor via ShowCursor(0) loop
2. Check mode==4 (RaceMode), session==7 (SessionType), DAT_007d032c==1 (videos enabled)
3. Build `<track_path>\FIAShort.bik` path, call FUN_004f9b70 to play
4. Set DAT_007c54e0 (current driver) and DAT_007c54dc (current index)
5. Call various cleanup and camera setup functions
6. If escape not pressed: file load, scene render, pit state, collision, telemetry

**Data passed to callees:** Various params including track path, driver reference

### Level 1: FUN_004f9b70 — Bink Play with Retry UI

**Trigger:** Called from FIA Short Bink Video with video file path
**Called by:** FUN_004a00a0
**Purpose:** Loads a Bink video file with retry loop and progress UI display

**Key actions:**
1. Stack init via FUN_005881c0
2. File open + existence check via FUN_00566b20 / FUN_00568540
3. File streaming via FUN_00566c00
4. State checks and retry logic

## Notes

- FUN_004f9b70 subtrees reuse common file I/O wrappers (FUN_00566b20, FUN_00566c00, FUN_00568540) that recur in chains 210 and 212
- This is an entry-point function (no callers in callers.json) — called directly by UI state machine

---
