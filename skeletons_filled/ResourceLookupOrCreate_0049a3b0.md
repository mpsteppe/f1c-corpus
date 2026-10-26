## ResourceLookupOrCreate_0049a3b0 — IndexedResourceLookupOrCreate

**Summary:** Normalizes a string, validates it, converts to an index via CharToIndexConversion, allocates a 28-byte node, initializes it, and inserts it into an indexed array at `this[result]`. If the slot already holds a list, appends the node to the tail (following offset 0x18 next pointer). Returns the index, or -1 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StringReverseCopyLookup (0049a490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049a250 | PatternedFieldInit | initialize new 28-byte node |
| 0049a2c0 | ThunkToFUN00566650 | process the source string |
| 0049a2e0 | FunctionCallWrapper_a2e0 | process parameter a3 |
| 0049a330 | CharToIndexConversion | convert string to index into this array |
| 0049a520 | sub_49A520 | validate the source string |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 28 bytes for new node |
| 00589901 | sub_589901 | normalize/init the source string |

**Guard conditions:** sub_49A520(lpSrcStr) checked non-zero — if validation fails, return -1. CharToIndexConversion result checked != -1 — if -1, skip allocation and return. v6 (this[result]) checked NULL — if NULL, store new node directly at array slot; if non-NULL, walk to tail via offset 0x18 (next pointer) and append.
