## StringCopyWithReturn_0042f140 — ValidatedStringCopy

**Summary:** Searches for source string a2 in string table; if found, copies a2 to this+0xC buffer (or clears buffer if a2 is null). Returns pointer to destination buffer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42ED70 (0042ed70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | 0 | stringCopyBuffer |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Looks up string in table; returns non-zero if found |

**Guard conditions:** Only copies a2 to buffer if BinarySearchInStringTable lookup succeeds. If lookup fails, returns buffer pointer unchanged (contents not modified).
