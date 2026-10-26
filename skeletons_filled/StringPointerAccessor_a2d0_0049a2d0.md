## StringPointerAccessor_a2d0_0049a2d0 — StringPointerWithDefaultFallback

**Summary:** Returns the string pointer stored at offset 0x08. If that pointer is NULL, returns a default directory path string (byte_5EA438) as fallback.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringNormalizeLookup_a460 (0049a460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | string pointer; if NULL, returns default |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** this[2] (offset 0x08) checked NULL — if NULL, return global default byte_5EA438; if non-NULL, return the field value.
