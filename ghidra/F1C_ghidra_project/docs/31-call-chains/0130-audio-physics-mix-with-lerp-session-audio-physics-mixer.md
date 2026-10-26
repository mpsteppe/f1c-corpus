# Chain: Audio/Physics Mix with Lerp — Session Audio/Physics Mixer

Seed: FUN_0040e2b0  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 9

---

## Overview

Basic session update function that blends audio and physics state using linear interpolation. Called from session race logic when a basic (non-race) update is needed. Reads audio/emitter positions, computes bounding boxes, and does Lerp-based audio parameter blending.

## Call Tree

```
FUN_0040e2b0 — Audio/Physics Mix with Lerp  [trigger: session update, param_1+0x1c in [0..2]]
  +-- FUN_004dd550 — Bounding Box Computation (Min/Max)  [computes AABB for audio emitter]
  +-- FUN_0054c230 — Linked List Indexed Accessor  [indexes into audio emitter list]
  +-- FUN_0054e100 — PackedArrayTotalSize  [reads packed array size for audio data]
  +-- FUN_0054e120 — PackedArrayIndexLookup  [indexed lookup in audio data array]
  +-- FUN_0054b420 — Three-Field Copy  [copies 3 fields from struct to output]
  +-- FUN_0054b3b0 — Three-Field Setter with Sub-Call  [sets 3 audio fields + sub-call]
  |     +-- FUN_0040e1d0 — Callback Registration
  +-- FUN_0040e1f0 — Global Vector Offset Update  [updates global audio/physics offset]
  |     +-- FUN_0040d290 — Camera Target: Race Leader  [reads leader position]
  |     +-- FUN_0040e1d0 — Callback Registration
  |     +-- FUN_00587b3e — Boolean-to-Int Conversion
  |     +-- FUN_00587bcf — Free Wrapper (×2)
  |     +-- [2 more utility callees]
```

## Key Actions

1. Checks param_1+0x1c range [0..2] — gates whether basic update runs
2. Computes bounding box for audio emitter position (FUN_004dd550)
3. Indexes into audio emitter linked list and packed arrays
4. Copies audio state fields via 3-field helpers
5. Updates global audio/physics vector offset (FUN_0040e1f0)
6. Reads race leader position for audio spatialization (FUN_0040d290)

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Audio emitter list | Indexed access | Emitter position data |
| Position data | Bounding box compute | Audio spatial bounds |
| Global offset | Vector update (FUN_0040e1f0) | Audio/physics blend offset |

## Notes

- 7 direct callees, 2 with sub-callees (depth 2)
- References docs/09-track-system.md (camera/leader position) and docs/01 (callback registration)
- Described in docs/06-session-race-logic.md as "basic session update" — called during non-race session states (practice, warmup)
- FUN_0040e1f0 is the main sub-chain with 7 sub-callees

---
