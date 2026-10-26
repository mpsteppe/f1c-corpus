# Chain: Main View / Tracking Camera Scene Loader — Camera definition parser

Seed: FUN_0040b850  |  System: docs/10-vehicle-physics.md  |  Depth: 4  |  Functions: ~14

---

## Overview

Main View / Tracking Camera Scene Loader (FUN_0040b850) reads MAINVIEW and TRACKINGCAM camera definitions from a scene file. It opens the scene file, reads up to 128 camera definitions (each 0xd0 bytes), allocates a camera array, and calls per-camera post-init setup. Struct fields: +0x04=camera count, +0x0c=camera array ptr, +0x10=second count, +0x14=current index. Same pattern as FUN_00408e20 but for two fixed camera types.

## Call Tree

```
FUN_0040b850 — Main View / Tracking Camera Scene Loader  [trigger: scene load]
  +-- FUN_005881c0 — Stack Probe / alloca  [stack init]
  +-- FUN_005668b0 — Zero-Init Small Struct  [open file]
  +-- FUN_00544f50 — Two-Level Wide-String Search  [camera count]
  +-- FUN_00566b20 — AudioStreamOpen  [file check]
  |     +-- FUN_00566b90 — File Close with Flag Dispatch
  |     +-- FUN_00568620 — Buffer Alloc
  |     +-- FUN_00534b00 — Single Call Wrapper
  |     +-- FUN_00566650 — String Copy with Buffer Realloc
  +-- FUN_00566cc0 — Conditional Dispatch Based on Flag  [tokenizer]
  +-- FUN_005651b0 — Script Preprocessor/Tokenizer  [line read]
  +-- FUN_00565520 — INI Field Reader  [field read]
  +-- FUN_004585e0 — Camera Init  [init per camera]
  +-- FUN_004583b0 — 3D Transform Object Init (Type 2)  [camera alloc]
  +-- FUN_00459330 — Camera Viewport Parameter Copy  [camera setup]
  +-- FUN_005668d0 — Sub-Call with Conditional Field Free  [close file]
```

## Step-by-Step Trace

### Level 0: FUN_0040b850 — Main View / Tracking Camera Scene Loader

**Trigger:** Scene file loading during camera system setup
**Called by:** Not in callers.json (likely called from camera manager init)
**Purpose:** Parse MAINVIEW and TRACKINGCAM camera definitions from scene file

**Key actions:**
1. Stack init via FUN_005881c0
2. Open scene file via FUN_005668b0
3. Read camera count via FUN_00544f50
4. File check via FUN_00566b20, tokenizer via FUN_00566cc0
5. Read lines/fields via FUN_005651b0 / FUN_00565520
6. Allocate camera array: operator_new(count * 0xd0 + 4), stride 0xd0
7. Per-camera init via FUN_004585e0, alloc via FUN_004583b0, setup via FUN_00459330
8. Close file via FUN_005668d0

**Data passed to callees:** param_1 = camera struct with fields at +0x04 (count), +0x0c (array ptr), +0x10 (count2), +0x14 (current idx)

## Notes

- All callees are utility functions — no deep call chain
- FUN_00566b20 (AudioStreamOpen) is reused from chain 204 (replay init) and chain 210 (HTree loader)
- Scene file format: text-based with MAINVIEW/TRACKINGCAM sections, parsed by tokenizer/line reader
- Count read from FUN_00544f50 (Two-Level Wide-String Search — counts matching section entries)

---
