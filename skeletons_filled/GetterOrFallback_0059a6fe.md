## GetterOrFallback_0059a6fe — Getter with null fallback to sentinel

**Summary:** Returns pointer at this+0x10 if non-null, otherwise returns fallback sentinel &unk_5B9D34 (null-string placeholder).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | pointer to stored data/string; checked before returning |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9d34 | unk_5B9D34 | R | Buf_NullStringSentinel [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** If this[4] (offset 0x10) is null, returns &unk_5B9D34 as empty/default string sentinel. If non-null, returns the pointer directly.
