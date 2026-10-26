## FloatThresholdCheck_00499a50 — Float field positive check

**Summary:** Checks if float value at this+0x8 is greater than 0.0. Returns BOOL result. Used as guard/predicate in caller logic.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_495B60 (00495b60), UITextDialogRendering (00495bd0), SpriteTextureEnumeration (00498950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | float value compared against 0.0 threshold |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] — reference for zero comparison |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** returns TRUE when `this+0x8 > 0.0f`; FALSE otherwise. Pure predicate, no side effects.
