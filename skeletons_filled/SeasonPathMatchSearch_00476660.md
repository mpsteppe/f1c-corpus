## SeasonPathMatchSearch_00476660 — SeasonScenePathMatcher

**Summary:** Searches a linked list of season scene nodes for one whose path string matches the global SeasonPath (`dword_7D0434`). Stores the match index at offset 0x174.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonSceneInitialization (00477720)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xF0) | 0x3C | R | — | path string from first list node (season scene name) |
| obj | 0x98 | R | — | unknown |
| this | 0x0 | R | — | vtable pointer (virtual call at offset 152) |
| this | 0xF0 | R | — | linked list head pointer |
| this | 0xF8 | RW | — | linked list traversal cursor (updated each iteration) |
| this | 0xFC | R | — | unknown |
| this | 0x174 | RW | 0 | match result index (set to 0 before search, set to loop count on match) |

**Written-by note (persistence):**
- this 0xF8: written at start and each loop iteration as cursor advances; external poke overwritten on next search
- this 0x174: set to 0 before search, set to match index if found, or remains 0; persists until next search

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007d0434 | dword_7D0434 | R | SeasonPath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | string comparison (returns 0 for match) |

**Guard conditions:** `this[60]` (offset 0xF0) == NULL or `*this[60]` (first node value) == NULL → skip search; `sub_588410` returns 0 (paths match) → break loop, store index; end of list reached without match → call virtual fn at offset 152 (fallback behavior)
