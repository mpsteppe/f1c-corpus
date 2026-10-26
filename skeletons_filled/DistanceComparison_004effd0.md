## DistanceComparison_004effd0 — DistanceComparison

**Summary:** Performs 3D transform and render call, returning boolean comparison result. Part of rendering/distance culling system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AISteeringRacingLineCorrection (0042b0e0), LoopOverTwoParallelArrays (004d1030), VelocityThresholdCheck (004f1aa0), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Pointer to render object (passed to RenderCallWithGuard) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d1140 | RenderCallWithGuard | Performs render operation with guard condition |
| 004efb20 | F_3DTransformWithMatrixMultiplication | Applies 3D transform matrix multiplication |

**Guard conditions:** None — always computes both calls and returns comparison result.
