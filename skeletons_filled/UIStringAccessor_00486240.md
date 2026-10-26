## UIStringAccessor_00486240 — UIStringAccessor

**Summary:** Returns a string pointer from an optional sub-object at this+0xC8. If the sub-object or its string field at +0x18 is null, falls back to a global default path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | R | — | pointer to sub-object containing a string field |
| this | 0xE0 | R | — | unused in this function (present in struct layout) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[50] (offset 0xC8) != NULL → if null, returns 0 immediately (BLOCKED). Then checks the string pointer at subobject+0x18 != NULL → if null, returns byte_5EA438 fallback (BLOCKED). Otherwise PASSES and returns the sub-object's string.
