# Chain: Vertex Buffer Transform — Scene graph hierarchy vertex transform pipeline

Seed: FUN_0054c6c0  |  System: docs/19-renderer.md  |  Depth: 3  |  Functions: 14

---

## Overview

Vertex Buffer Transform transforms vertex buffer positions and normals through the scene graph hierarchy. Called per-frame from the renderer, it checks a dirty flag at param_1+0x14 bit 26 (skips if already transformed), pushes/pops transform matrices via matrix stack, and processes vertices in batches from a linked list (stride 0x40, head at param_1+0x11c). Two transform paths exist: non-skinned (3-float vertex + 3-float normal) and skinned (7-float homogenous). The chain is shallow with many leaf utility functions and three non-leaf callees (OBB computation -> QR decomposition, flag loop -> value getter, constructor -> zero init).

## Call Tree

```
FUN_0054c6c0 — Vertex Buffer Transform  [trigger: per-frame render, dirty flag set]
  |
  +-- FUN_0053b130 — Push Transform Matrix  [matrix stack push] LEAF
  +-- FUN_0053b200 — Set World Matrix  [world transform] LEAF
  +-- FUN_0053b240 — Set Camera/View Matrix  [view transform] LEAF
  +-- FUN_0054b4d0 — [PARTIAL] Unknown  [docs/20] LEAF
  +-- FUN_0054d520 — 3D Bounding-Box Extents Computation  [docs/19] LEAF
  +-- FUN_0054e270 — Bounding-Box from Vertex Data  [docs/19]
  |     +-- FUN_0053b6f0 — QR Decomposition / Givens Rotation (3x3 Double)  LEAF
  +-- FUN_0054d080 — [undocumented]  LEAF
  +-- FUN_0054e080 — FlagSetLoop (bitmask OR on objects)  [docs/06]
  |     +-- FUN_00545f40 — Value Getter  LEAF
  +-- FUN_0055d200 — Struct Zero-Init with Base Call  [docs/20]
  |     +-- FUN_0053c2a0 — Global Zero Init  LEAF
  +-- FUN_0053b160 — Empty Stub  [dead code] LEAF
```

## Step-by-Step Trace

### Level 0: FUN_0054c6c0 — Vertex Buffer Transform

**Trigger:** per-frame render pass; dirty flag (bit 26 at +0x14) set by scene graph update
**Called by:** render transform pipeline (1 caller in graph)
**Purpose:** transform vertex buffer from local to world/view space through scene graph

**Key actions:**
1. Checks param_1+0x14 bit 26 — return immediately if already transformed
2. Calls FUN_0053b130 (push transform) + FUN_0053b200/FUN_0053b240 (world/camera set)
3. Branches on flag bit 23 at +0x14:
   - Path 0 (non-skinned): stride 0xc (3-float vertex + 3-float normal), transforms through DAT_008b8f24 vtable
   - Path 1 (skinned): stride 0x10 (7-float vertex), full homogenous transform
4. Iterates linked list at param_1+0x11c in batches of stride 0x40
5. Copies 2 previous-frame positions to +0x8/+0x9 for velocity computation
6. Allocates 8 new transform result slots at end of each batch

### Level 1-2: Non-leaf Callees

**FUN_0054e270 — Bounding-Box from Vertex Data:** Computes OBB from covariance matrix -> QR decomposition (FUN_0053b6f0 — Givens rotation, 3x3 double precision). Used for frustum culling or collision.

**FUN_0054e080 — FlagSetLoop (bitmask OR on objects):** Sets flags on objects in a loop via FUN_00545f40 (value getter). Used for marking transform dirty state.

**FUN_0055d200 — Struct Zero-Init with Base Call:** Initializes a new transform result slot to zero via FUN_0053c2a0 (global zero init).

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| param_1+0x14 bit 26 | dirty flag | check | skip if clean |
| FUN_0053b130 | matrix stack | push | saved state |
| FUN_0053b200 | world matrix | set transform | world space |
| FUN_0053b240 | view matrix | set transform | view space |
| DAT_008b8f24 vtable | vertex data | transform | screen-space |
| FUN_0054e270 | vertex positions | covariance -> QR | OBB extents |
| FUN_0055d200 | result slot | zero init | clean slot |

## Globals Written

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008b8f24 | D3DDeviceWrapperPtr | Read-only | Scene graph vtable for coordinate transforms |

## Notes

- **Depth limited to 3:** all Level 2 callees are leaves (QR decomposition, value getter, zero init)
- **D3D COM vtable dispatch** (DAT_008b8f24) at +4 and +8 not tracked in call_graph — noted but not recursed
- **FUN_0053b160 confirmed dead stub** — bare return, no instructions
- **Two transform paths** based on skinned vs non-skinned vertex format (flag bit 23)
- **10 of 14 functions are leaves** (no outgoing calls)
- **Doc span:** 10 in docs/20, 2 in docs/19, 1 in docs/06, 1 in docs/17
