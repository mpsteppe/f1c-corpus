## TextureSurfaceValidator_005159f5 — Texture Surface Format Validator

**Summary:** Validates texture surface dimensions and format parameters against allowed limits, then computes pixel-aligned layout descriptors (stride, dimensions) for each sub-surface. Sets up surface descriptor fields with aligned dimensions for rendering.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenStateMachine (00515df2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x10 | RW | 0 | output surface active flag — set to 0 (disabled) when sub-surface count insufficient or needs refresh |
| *(this+0xC4) | 0xC | R | — | sub-surface width scaling factor (input) |
| *(this+0xC4) | 0x1C | RW | — | computed aligned width (ceiling division result) |
| *(this+0xC4) | 0x20 | RW | — | computed aligned height (ceiling division result) |
| *(this+0xC4) | 0x24 | RW | 8 | output surface pixel format / bit depth — initialized to 8 |
| *(this+0xC4) | 0x28 | RW | — | padded stride width (aligned to format boundary) |
| *(this+0xC4) | 0x2C | RW | — | padded stride height (aligned to format boundary) |
| *(this+0xC4) | 0x30 | RW | 1 | output surface stride valid/needs-recalc flag — set to 1 |
| *(this+0xC4) | 0x4C | RW | 0 | surface dirty/modified flag — set to 0 after recalculation |
| obj | 0x0 | R | — | pointer to error-reporting vtable (used to signal failures) |
| obj | 0x14 | RW | 16 | error code slot (set to 16 on dimension validation failure) |
| obj | 0x18 | RW | 65500 | error detail slot — written with offending dimension value |
| obj | 0x1C | RW | 10 | error code slot (set to 10 on format mismatch) |
| this | 0x0 | R | — | vtable/object pointer (used for error callback dispatch) |
| this | 0x18 | R | — | texture total width (in pixels?) |
| this | 0x1C | R | — | texture total height (in pixels?) |
| this | 0x20 | R | — | number of sub-surfaces (surface count) |
| this | 0xC0 | R | — | expected pixel format value (must equal 8) |
| this | 0xC4 | R | — | pointer to sub-surface descriptor array |
| this | 0xC8 | R | — | pointer to additional surface data |
| this | 0x10C | RW | 1 | max horizontal scale factor (tracked across sub-surfaces) |
| this | 0x110 | RW | 1 | max vertical scale factor (tracked across sub-surfaces) |
| this | 0x114 | RW | 8 | output surface pixel format (tracked across all sub-surfaces) |
| this | 0x118 | RW | — | total aligned height (ceiling division of height by vertical factor) |
| this | 0x120 | R | — | sub-surface count (for output state comparison) |
| this | 0x18C | R | — | pointer to output surface state structure |

**Written-by note (persistence):**
- *(this+0x18C) 0x10: written once during validation pass — external poke would NOT survive since it's recomputed when this is called
- *(this+0xC4) 0x1C: written once per sub-surface during validation — external poke does NOT survive across validation calls
- *(this+0xC4) 0x20: written once per sub-surface — external poke does NOT survive
- *(this+0xC4) 0x24: written once per sub-surface (8) — external poke does NOT survive
- *(this+0xC4) 0x28: written once per sub-surface — external poke does NOT survive
- *(this+0xC4) 0x2C: written once per sub-surface — external poke does NOT survive
- *(this+0xC4) 0x30: written once per sub-surface (1) — external poke does NOT survive
- *(this+0xC4) 0x4C: written once per sub-surface (0) — external poke does NOT survive
- obj 0x14: written only on error path (conditional) — if no error, external poke could persist until overwritten by error
- obj 0x18: written only on error path (conditional) — same as above
- obj 0x1C: written only on error path (conditional) — same as above
- this 0x10C: written during validation, updated once — external poke does NOT survive across validation calls
- this 0x110: written during validation, updated once — external poke does NOT survive
- this 0x114: written during validation (8) — external poke does NOT survive
- this 0x118: written during validation — external poke does NOT survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515917 | CeilingDivision | performs (a + b - 1) / b integer ceiling division for pixel-aligned dimension calculations |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xC4) | 0xC | <= | 0 | sub-surface width factor: if zero or negative, FAILS validation |
| *(this+0xC4) | 0xC | > | 4 | sub-surface width factor: if exceeds 4, FAILS validation |
| this | 0x18 | > | 65500 | total texture width: if exceeds 65500, FAILS — clamps to 65500 |
| this | 0x1C | > | 65500 | total texture height: if exceeds 65500, FAILS — clamps to 65500 |
| this | 0x20 | <= | 0 | sub-surface count: if zero or negative, skip all sub-surface processing |
| this | 0x20 | > | 10 | sub-surface count: if exceeds 10, FAILS — clamps to 10 |
| this | 0xC0 | != | 8 | pixel format mismatch: if not equal to 8, FAILS validation |

**Guard interpretation:** PASSES when texture dimensions (width/height) are ≤ 65500, sub-surface count is 1-10, pixel format equals 8, and each sub-surface has width/height factors in range 1-4. BLOCKED (error callback invoked) when any of these checks fail — the function aborts early and reports the error code via the obj->vtable callback.