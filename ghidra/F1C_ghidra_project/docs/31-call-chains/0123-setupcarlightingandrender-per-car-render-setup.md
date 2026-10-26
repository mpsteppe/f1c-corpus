# Chain: SetupCarLightingAndRender — Per-Car Render Setup

Seed: FUN_004c71c0  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 16

---

## Overview

Per-frame render setup for each vehicle. Configures lighting (diffuse, specular, environment), LOD parameters, world/view matrices, wheel positions with rotation, transparency/alpha flags, and triggers shadow pass rendering. Called from the per-frame render chain after visibility sorting.

## Call Tree

```
FUN_004c71c0 — SetupCarLightingAndRender  [trigger: per-frame, per-visible-vehicle]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [encodes progress/event state into bitfield]
  +-- FUN_004b2310 — Float-to-Short Normalized Conversion  [converts float to normalized short]
  +-- FUN_004b2480 — General utility  [float processing]
  +-- FUN_004b25d0 — Float-to-Fixed-Point with Clamping  [quantizes floats to shorts]
  +-- FUN_004b2750 — Float-to-Short Clamped Conversion  [clamped float→short]
  +-- FUN_004b2840 — Float-to-Byte/Short Encoding  [encodes float to byte/short for vertex]
  +-- FUN_004b2930 — Float-to-Bitfield Pack  [packs float into bitfield]
  +-- FUN_004b29b0 — Bitfield Insert (Bits 12-16)  [inserts value into bitfield range]
  +-- FUN_004b2a10 — Short Computation / Bitfield Manipulation  [bitfield ops]
  +-- FUN_004b2a40 — Float-to-Bitfield Encoder  [encodes float into bitfield]
  +-- FUN_004b2aa0 — Bitfield Set/Clear by Index  [sets/clears bit by index]
  +-- FUN_004b2ae0 — Bitfield Flag XOR Setter  [XOR toggle of flags]
  +-- FUN_004b2b10 — Forwarding call  [pass-through]
  +-- FUN_004b2b60 — 15-bit Field Setter  [writes 15-bit value at +0x30]
  +-- FUN_004c7c00 — Constant 5  [returns constant 5]
```

## Key Actions

1. Sets LOD parameters per vehicle distance
2. Writes world matrix (struct +0x744) and view matrix (+0x704)
3. Loops 4 wheels at stride 0x128 (struct +0x83c) for wheel position + rotation
4. Sets diffuse (+0x34f8), specular (+0x3510), environment map (+0x3540) colors
5. Encodes render state bitflags: transparency, alpha blend, player flag
6. Triggers shadow volume pass via render state
7. All 15 callees are leaf utility functions (float encoding, bitfield packing)

## Globals Written

None directly — writes to vehicle struct offsets only.

## Data Flow Summary

| Input | Operation | Output |
|-------|-----------|--------|
| Vehicle struct ptr | Read +0x704/0x744/0x83c | World/view matrices, wheel pos |
| Lighting params | Set +0x34f8/0x3510/0x3540 | Diffuse/specular/env colors |
| Render flags | Encode via 15 bitfield callees | Render state bitflags |
| LOD params | Distance-based selection | LOD level |

## Notes

- All 15 callees are leaf functions with 0 sub-callees — pure utility/encoding
- Heavy use of float-to-fixed-point and float-to-bitfield encoding for GPU vertex format
- Called per visible vehicle per frame (renderer hot path)

---
