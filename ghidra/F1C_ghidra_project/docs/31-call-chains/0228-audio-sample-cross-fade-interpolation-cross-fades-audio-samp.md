# Chain: Audio Sample Cross-Fade/Interpolation — Cross-fades audio samples with blending ratio

Seed: FUN_004ff8f0  |  System: docs/21-audio-network-internals.md  |  Depth: 6  |  Functions: ~14

---

## Overview

FUN_004ff8f0 performs cross-fade interpolation between two audio samples (A and B). It is called during audio playback when sample format changes or when blending between two audio sources. The function computes an interpolation ratio, configures output format, applies linear or Hermite interpolation via FUN_004ff3a0, and uses a suite of bitfield packing/unpacking helpers (FUN_004b29xx series) for per-channel gain mixing. All callees are leaf math/conversion functions — no deep recursion.

## Call Tree

```
FUN_004ff8f0 — Audio Sample Cross-Fade/Interpolation  [trigger: audio format change or sample blend]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [leaf: audio format config]
  +-- FUN_004b2580 — Short Vector to Float with Scale  [leaf]
  +-- FUN_004ff3a0 — 3D Hermite/Spline Interpolation  [leaf]
  +-- FUN_00567030 — Quaternion from Euler Angles  [leaf]
  +-- FUN_00567580 — undocumented  [leaf]
  +-- FUN_00567010 — File/Stream Cleanup Wrapper  [sub: 2]
  +-- FUN_005001d0 — FieldCompareConstant  [leaf]
  +-- FUN_004b2a80 — Bitfield to Float Conversion  [leaf]
  +-- FUN_004b2a40 — Float-to-Bitfield Encoder  [leaf]
  +-- FUN_004b29f0 — Short Computation  [leaf]
  +-- FUN_004b29b0 — Bitfield Insert (Bits 12-16)  [leaf]
  +-- FUN_004b2a30 — Bitfield Extract  [leaf]
  +-- FUN_004b2980 — Bitfield Extract + Scale  [leaf]
  +-- FUN_004b2930 — Float-to-Bitfield Pack  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004ff8f0 — Audio Sample Cross-Fade/Interpolation

**Called by:** FUN_00500560 (penetration response), FUN_00500210 (Audio Sample Playback)
**Purpose:** Cross-fades between two audio samples with blending ratio, outputs interpolated frame.

**Key actions:**
1. Computes blend ratio from param_1 relative to source range
2. Configures audio format via FUN_004b33b0 (bit depth, channels, frequency)
3. If blend ratio within transition zone: computes linear interpolation
4. Sets up buffer via FUN_004b2580
5. Interpolates sample via FUN_004ff3a0 at computed ratio
6. Converts float to fixed-point PCM
7. For partial blend: applies per-channel gain mixing via bitfield helpers

**Data passed to callees:** Sample buffer pointers, format parameters, blend ratio

### Level 1: FUN_004ff3a0 — 3D Hermite/Spline Interpolation

**Called by:** FUN_004ff8f0 (sample interpolation)
**Purpose:** Interpolates sample values between keyframes

**Key actions:**
1. Takes input values and interpolation parameter
2. Applies Hermite/spline interpolation
3. Returns interpolated output

### Level 1: Bitfield helpers (FUN_004b2a80, FUN_004b2a40, etc.)

**Called by:** FUN_004ff8f0 (per-channel gain mixing)
**Purpose:** Pack/unpack gain values from bitfield-encoded audio format

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004ff8f0 | Source A, Source B buffers, ratio | Cross-fade interpolation | Interpolated PCM frame |

## Globals Written in This Chain

None documented.

## Notes

- All 14 callees are leaf functions — the chain is wide but shallow (depth 1).
- FUN_004ff8f0 is itself a callee of FUN_00500210 (Audio Sample Playback) for format transition blending.
- The bitfield helper cluster (FUN_004b29xx/FUN_004b2axx) appears to handle a custom packed audio format.

---
