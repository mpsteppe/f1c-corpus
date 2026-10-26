## ShortFieldAccessor_005439f0 — UIPositionGetter

**Summary:** Reads three 16-bit UI position values (X, Y, Z at offsets 0x188, 0x18A, 0x18C) and stores them into caller-provided output pointers if non-null. Complement to UIElementPositionSetter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCAA0 (004fcaa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x188 | R | — | UI element X position (16-bit) |
| this | 0x18A | R | — | UI element Y position (16-bit) |
| this | 0x18C | R | — | UI element Z position (16-bit) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2, a3, a4) is checked individually — BLOCKED (skip write) when NULL.
