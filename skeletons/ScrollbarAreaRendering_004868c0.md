## ScrollbarAreaRendering_004868c0 — ScrollbarAreaRender

**Summary:** Renders a scrollbar area (track or thumb) using either a texture blit from a configuration sub-object or a solid color fill. Replaces sentinel value -50000 with instance-default coordinates. Part of UI scrollbar rendering system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** F_2DSurfaceBlitWithViewportClipping (0048a240)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | default left coordinate (replaces sentinel -50000) |
| this | 0x8 | R | — | default right coordinate (replaces sentinel -50000) |
| this | 0xC | R | — | default top coordinate (replaces sentinel -50000) |
| this | 0x10 | R | — | default bottom coordinate (replaces sentinel -50000) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | resolve scrollbar style config from this and a2 |
| 00490920 | Accessor | unknown accessor |
| 00491960 | DualDispatchWithGuard | draw rectangle primitive with clipping guard |
| 00494a30 | F_10ParamForwarder | blit texture sub-rectangle to screen |
| 00495150 | GlobalAccessor_5150 | access global render state from unk_7CDE00 |
| 00497260 | ShortComputation_7260 | fill solid color rectangle (fallback when no texture config) |

**Guard conditions:** 1) If computed height (bottom-top) ≤ 0 or width (right-left) ≤ 0 → return 0 (blocked, degenerate rect). 2) If config object exists → texture blit path; else if a3 (fallback flag) is true → solid color fill path; else → return 1 (no-op success).
