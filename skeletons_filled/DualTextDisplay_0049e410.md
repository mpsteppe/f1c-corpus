## DualTextDisplay_0049e410 — Dual text label/value display

**Summary:** Formats and renders a label/value pair at the same Y position. Label uses sub_49BB40 and renders at first X, value uses sub_49BBB0 and renders at second X.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49D700 (0049d700), UtilityFunction_d8b0 (0049d8b0), TimestampedRenderStringUpdate (0049da60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | render surface pointer (this[2]) |
| this | 0x14 | R | — | display context pointer (this[5]) |
| this | 0x68 | R | — | sub-struct pointer (steering input data) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce048 | dword_7CE048 | R | RaceSessionState [DERIVED] |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049bb40 | sub_49BB40 | formats label text into buffer |
| 0049bbb0 | sub_49BBB0 | formats value text into buffer |
| 0049f6a0 | StringFormatAndRender | renders formatted string to HUD at position |

**Guard conditions:** No internal guards — relies on caller's null checks before invocation.
