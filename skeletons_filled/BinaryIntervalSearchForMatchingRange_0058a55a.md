## BinaryIntervalSearchForMatchingRange_0058a55a — IntervalRangeSearch

**Summary:** Searches a sorted interval table for a value within a range. Walks entries backward from end, finds match where target <= entry upper bound, returns pointer to matching entry. Used for font glyph rendering range lookup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5934E1 (005934e1), FontGlyphRender (00593694)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | Entry count (number of intervals in table) |
| this | 0x10 | R | — | Pointer to interval table (each entry 20 bytes: [lower, upper, ...]) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00593cfd | SEHGuardedFunctionPointerCall | Error handler called on invalid state (v6 == -1, or output bounds mismatch) |

**Guard conditions:** If a2 (remaining depth) starts negative, skips search. Checks v6 == -1: calls error handler. Inside loop: if entry->lower < a3 && a3 <= entry->upper (range match), decrements a2. After loop: validates v8 <= count and v9 <= v8, calls error handler if violated.
