## ShortComputation_f0b0_0048f0b0 — ClippedRenderBoundsForwarder

**Summary:** Computes clipped viewport rendering bounds: clips source rectangle against offset/scroll position, computes visible x/y dimensions and offsets, retrieves a global rendering value, and forwards all calculated parameters to F_10ParamForwarder for rendering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE4) | 0x1C | R | — | source rectangle x position from referenced object |
| *(this+0xE4) | 0x20 | R | — | source rectangle width from referenced object |
| this | 0xE4 | R | — | pointer to source bounds object |
| this | 0x120 | R | — | viewport horizontal offset / scroll position |
| this | 0x124 | R | — | viewport vertical offset / scroll position |
| this | 0x140 | R | — | total source width / max x bound |
| this | 0x144 | R | — | total source height / max y bound |
| this | 0x17C | R | — | boolean flag enabling the computation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494a30 | F_10ParamForwarder | forward computed render parameters for drawing |
| 00495150 | GlobalAccessor_5150 | retrieve global rendering state value |

**Guard conditions:**
- Outer: if a2 (second arg) is zero → BLOCKED (return 0)
- Inner: if byte at this+380 (offset 0x17C) is zero → BLOCKED (return 0)
- Scale guard: if a3 < this+288 (offset 0x120) → PASS (clip x offset); else set x offset to 0
- Clip guard: if a4 >= this+320 (offset 0x140) - 10 → set y offset to 0; else clip y offset
- Bounds clipping: adjust source rectangle dimensions against viewport bounds
- All PASS → call F_10ParamForwarder with computed clip values
