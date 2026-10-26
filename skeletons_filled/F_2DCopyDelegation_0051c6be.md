## F_2DCopyDelegation_0051c6be — 2D copy delegation to array block copy

**Summary:** Thin wrapper that delegates a 2D rectangular copy to F_2DArrayBlockCopy with reordered parameters. Reads row width from struct offset 0x5C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | R | — | Row width/stride — passed to F_2DArrayBlockCopy as copy size per row |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051593f | F_2DArrayBlockCopy | Core 2D rectangular block copy — copies a rectangular region of pixel data |

**Guard conditions:** No guards — unconditional delegation to F_2DArrayBlockCopy.
