## StringFormatReplaceOperation_00422fd0 — PrependBasePathToString

**Summary:** Prepends base path from this[32] (offset 0x80) to a2 string using format "%s%s". Returns 1 on success, 0 if a2 is null or base path equals default.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileLoadWithRetryLoop (004f9b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x80 | R | — | Base directory path to prepend to output string |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058815f | StringFormatWithBufferOverflowCheck | Format "%s%s" with base path and original string, write result into a2 buffer |
| 00588410 | sub_588410 | String equality check (returns 0 when strings match) |

**Guard conditions:** this[32] is NULL: fall back to byte_5EA438 default path. a2 is NULL: return 0 (block). sub_588410(v3, &byte_5EA438) returns 0 (v3 equals default path): return 0 (block — no replacement needed). Passes when a2 is non-null and base path differs from default path.
