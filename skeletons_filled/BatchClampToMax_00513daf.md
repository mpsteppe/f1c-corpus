## BatchClampToMax_00513daf — BatchUnpremultiplyAlphaClamp

**Summary:** Batch process 16 float4 RGBA pixels: if alpha==0, zero RGB; if 0<alpha<1, scale RGB by 1/alpha clamped to max 1.0 (un-premultiply with clamp). If alpha>=1, leave unchanged.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileOpenAndValidate (00515869), sub_51588C (0051588c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | float R — clamped/scaled red channel |
| this | 0x4 | RW | — | float G — clamped/scaled green channel |
| this | 0x8 | RW | — | float B — clamped/scaled blue channel |
| this | 0xC | R | — | float A — alpha used as divisor/clamp threshold (read only) |

**Written-by note (persistence):**
- this 0x0: overwritten each iteration when alpha != 0.0; survives until overwritten
- this 0x4: same as R
- this 0x8: same as R

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always processes 16 elements unconditionally. Per-element branch:
- alpha == 0.0 → zero R,G,B
- 0.0 < alpha < 1.0 → scale R,G,B by 1/alpha, clamp at 1.0
- alpha >= 1.0 → skip (leave R,G,B unchanged)
