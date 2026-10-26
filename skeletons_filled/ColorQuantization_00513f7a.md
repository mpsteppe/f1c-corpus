## ColorQuantization_00513f7a — QuantizeColorBounds

**Summary:** Find optimal min/max bounds for quantizing 16 float samples to N levels (6 or 8). Uses Lloyd-Max style iterative refinement with coefficient tables; outputs clamped [0,1] bounds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_515417 (00515417)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | output float — quantized minimum bound (clamped to [0,1]) |

**Written-by note (persistence):**
- this 0x0: written once per call — survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | float threshold for physics contact aging overflow |
| 0059e440 | flt_59E440 | R | near-zero threshold for physics clamp |
| 0059e450 | flt_59E450 | R | degrees-to-radians conversion constant |
| 0059e778 | flt_59E778 | R | spread scale factor 2 |
| 005ac988 | flt_5AC988 | R | UV coordinate scale factor |
| 005adb14 | flt_5ADB14 | R | 360.0 — degree wrap constant |
| 005af56c | unk_5AF56C | R | spline coefficient table (a4 != 6) |
| 005af58c | unk_5AF58C | R | color quantization coefficient table (a4 != 6) |
| 005af5ac | unk_5AF5AC | R | base color table (a4 == 6) |
| 005af5c4 | unk_5AF5C4 | R | remap coefficient table (a4 == 6) |
| 008b00a0 | dword_8B00A0 | R | FPU control word store |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513e5d | FPUControlWordMerger | set FPU rounding mode for quantization arithmetic |

**Guard conditions (deterministic — field vs literal):**

| Param | Test | Value | Meaning |
|-------|------|-------|---------|
| a4 | == | 6 | use 6-level quantization tables (color table + remap table) |
| a4 | == | 8 | use 8-level quantization tables (includes extreme 0/1 values in min/max) |
| a4 | != 6 | else | use 6-element coefficient tables with modified min/max bounds (exclude 0/1) |

**Guard interpretation:** Function always executes. Selects coefficient tables based on a4 (6 vs other). Min/max range finding differs: a4==8 includes full [0,1] range; a4!=8 excludes extremes. Iterative refinement runs up to 8 iterations, early exit when error squared < 1/64.
