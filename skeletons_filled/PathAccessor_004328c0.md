## PathAccessor_004328c0 — PathFieldAt8Getter

**Summary:** Reads the path string pointer at offset 0x8 from a dereferenced object field. Returns the string or defaults to the application directory if null.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | Path string pointer at offset 8 in target struct |
| this | 0x0 | R | — | Pointer to the target struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If the string pointer at *(this->field0 + 8) is null, returns byte_5EA438 (default application directory) instead.
