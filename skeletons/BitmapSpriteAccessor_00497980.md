## BitmapSpriteAccessor_00497980 — GetSpriteBitmapName

**Summary:** Retrieves name string from a bitmap/sprite descriptor structure. Reads sprite base pointer from this+0x18, validates fields at offsets 0x48 and 0x50, then reads name string at offset 0x34 from the sub-descriptor. Returns name string or default byte_5EA438 if null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_404B60 (00404b60), KeyBindingUIPressKeyOrController (0046b0c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x68) | 0x34 | R | — | Name string at sub-descriptor offset 0x34 |
| this | 0x18 | R | — | Sprite/bitmap base pointer (v1 = this[6]) |
| this | 0x60 | R | — | Guard field at v1+0x48 — must be non-null to proceed |
| this | 0x68 | R | — | Pointer at v1+0x50 — sub-descriptor containing name |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default name returned when sprite name is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this+0x18 (this[6]) must be non-null AND the field at this+0x60 (v1[18]) must be non-null. If either fails, returns 0.
