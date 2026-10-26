## OBBFittingAndProjection_0051427f — OBBFittingAndQuantization

**Summary:** Compute oriented bounding box of 16 float4 vertices, then iteratively refine projection bounds for quantization to N levels. Outputs min and max float3 bounds. Used for spline/texture coordinate bound fitting.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureFilterAndLayerCompositing (005147ea)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output float — min bound X of fitted OBB |
| this | 0x4 | RW | — | output float — min bound Y |
| this | 0x8 | RW | — | output float — min bound Z |

**Written-by note (persistence):**
- this 0x0-0x8: overwritten each call with refined min bounds; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | near-zero threshold for physics clamp |
| 0059e450 | flt_59E450 | R | degrees-to-radians conversion constant |
| 0059e4e0 | flt_59E4E0 | R | scroll auto-repeat threshold (delta time gate) |
| 0059e670 | flt_59E670 | R | sentinel flag constant |
| 005ad1b8 | flt_5AD1B8 | R | moment arm constant |
| 005adb14 | flt_5ADB14 | R | 360.0 — degree wrap constant |
| 005ade40 | flt_5ADE40 | R | near-zero epsilon pointer |
| 005af5dc | flt_5AF5DC | R | render matrix coefficient (5) |
| 005af5e0 | unk_5AF5E0 | R | texture row start data table (a4 != 3) |
| 005af5f0 | unk_5AF5F0 | R | renderer matrix constant table (a4 != 3) |
| 005af600 | unk_5AF600 | R | D3D vertex constant array (a4 == 3) |
| 005af60c | unk_5AF60C | R | texture coordinate normalize data (a4 == 3) |
| 005d79bc | flt_5D79BC | R | BVH min bounds — initial min X |
| 005d79c0 | flt_5D79C0 | R | — initial min Y |
| 005d79c4 | flt_5D79C4 | R | — initial min Z |
| 005d79c8 | unk_5D79C8 | R | — initial max bounds integer data |
| 008b00a0 | dword_8B00A0 | R | FPU control word store |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513e5d | FPUControlWordMerger | set FPU rounding mode for quantization arithmetic |

**Guard conditions (deterministic — field vs literal):**

| Param | Test | Value | Meaning |
|-------|------|-------|---------|
| a4 | == | 3 | texture coordinate quantization (3 levels) — uses specific coefficient tables |
| a4 | != 3 | — | general quantization — uses alternate coefficient tables |
| variance (v69) | < | 0.00024414062 | near-zero spread → skip iterative refinement, emit raw AABB |

**Guard interpretation:** Function always executes. If input spread (v69) < 1/4096, skip OBB refinement (goto LABEL_19) — output raw axis-aligned bounds. Otherwise run up to 8 iterations of Lloyd-Max refinement. Early exit when error gradient squared < 1.5259e-5.
