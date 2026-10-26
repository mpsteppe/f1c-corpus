## UIStringAccessor_6300_00486300 — UIStringAccessorAt0x50

**Summary:** Returns a string pointer from field +0x50 of a sub-object at this+0xC8. Falls back to a global default path if the sub-object or its field is null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC8 | R | — | pointer to sub-object containing string field at +0x50 |
| this | 0x118 | R | — | unused in this function (present in struct layout) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[50] (offset 0xC8) != NULL → if null, returns 0 (BLOCKED). Checks string at subobject+0x50 != NULL → if null, returns byte_5EA438 fallback (BLOCKED). Otherwise returns the string.
