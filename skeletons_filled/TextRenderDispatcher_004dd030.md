## TextRenderDispatcher_004dd030 — Dispatch text rendering with bounds clipping and truncation

**Summary:** Renders a text string with scale, alignment, and bounds-aware clipping; queries text surface size, computes aligned position against object bounds, truncates overflowing text (left or right) using "AbCd" measurement heuristic, then delegates to ScaledTextureRender.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionDamageDecayProcessor (0045b840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | Font/device string pointer (fallback for a9) |
| this | 0x30 | RW | — | Scale X factor; updated to a7 if a7 > 0.0 |
| this | 0x34 | RW | — | Scale Y factor; updated to a8 if a8 > 0.0 |

**Written-by note (persistence):**
- this 0x30: written when a7 > 0.0; persists until overwritten
- this 0x34: written when a8 > 0.0; persists until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005d4c04 | dword_5D4C04 | R | Dword_5D4C04 [DERIVED] |
| 005d4c08 | byte_5D4C08 | R | ByteFontData [DERIVED] |
| 005ea438 | byte_5EA438 | R | Default font/path buffer for text rendering fallback |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dc340 | AlignmentPositionSwitch | Compute aligned text position from dimensions and alignment flags |
| 004dc600 | SurfaceSizeQuery | Query rendered text surface dimensions (width, height) for given font |
| 004dc660 | ScaledTextureRender | Render text texture with scale at computed position |
| 004dcf30 | TwinFieldGetter_cf30 | Retrieve object width (offset +0x14) and height (offset +0x18) |
| 004dcf50 | TripleFieldGetter | Retrieve object X (offset +0x08), Y (offset +0x0C), Z (offset +0x10) |
| 00587dd0 | sub_587DD0 | Copy string with length limit (strncpy-like) |

**Guard conditions:** Top-level guard: `a2` (input string) must be non-null, otherwise function returns immediately. Inside: if `v40[0]` (copied text) is empty at any point, returns. Loop guard: if computed position exceeds object bounds (left overflow or bottom overflow), returns. Individual position checks within loop can also cause early return when text overflows clip region.
