## GetOrientationAngleValues_00543a30 — GetOrientationAngleValues

**Summary:** Copies two orientation/angle values (offsets 0x194 and 0x198) from the object into caller-provided output pointers. Non-null pointers are written; null pointers are skipped.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x194 | R | — | left/orientation angle value (written to a2) |
| this | 0x198 | R | — | right/orientation angle value (written to a3) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3) checked individually — BLOCKED (skip write) when NULL.
