## FileStreamCleanup_004a1f10 — DualPathResourceCleanup

**Summary:** Performs resource cleanup by calling ResourceLookupWithDualPath on three paths. Uses this+0x4 as a custom path if non-null, otherwise falls back to default application directory. Always returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | custom file path pointer; if NULL, uses default directory |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c30b4 | word_5C30B4 | R | ConfigSubstringToken [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566cf0 | ResourceLookupWithDualPath | Opens/looks up resource with dual-path (custom + default) resolution |

**Guard conditions:** No guard on the first and third ResourceLookupWithDualPath calls. The second call uses this[1] if non-null, falls back to byte_5EA438 if null. Always returns 1.
