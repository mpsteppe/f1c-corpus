## RendererAlphaBlendSetter_00498030 — Alpha Blend State Configuration

**Summary:** Computes a clamped alpha/color-intensity value from a DSP transform parameter (flt_7CF2CC) and calls a virtual method (vtable offset 4) on a renderer object to apply the alpha blend state along with an identity transform.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimedAnimationTrigger (00486730), UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4 | R | — | unknown — not directly referenced in decompiled C |
| this | 0x0 | R | — | Vtable pointer of the renderer object |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005cc9e0 | dword_5CC9E0 | RW | Flt_UIColorIntensity [DERIVED] (also: ` — working alpha intermediate (render state) |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:**
- `a1 == NULL` → skip all processing, return uninitialized value (BLOCKED: null renderer object)
- `a1 != NULL` → copy flt_7CF2CC into dword_5CC9E0, clamp alpha to [0.0, 1.0], then call vtable method (PASSES)
- `flt_7CF2CC <= 1.0`: if alpha < 0.0, clamp to 0 (PASSES: normal range, just clamp negative)
- `flt_7CF2CC > 1.0`: set alpha to 1.0 (PASSES: overflow clamp)
