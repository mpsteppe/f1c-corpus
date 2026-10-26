## ArithmeticComparison_d8c0_004bd8c0 — ArrayRemoveByValue

**Summary:** Searches an integer array (count at this[1], data pointer at this[2]) for a matching value; if found, replaces it with the last element and decrements count. Returns the index of the removed element or count if not found.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ArithmeticComparison_df90 (004bdf90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | array element count (decremented on remove) |
| this | 0x8 | R | — | pointer to array data buffer |

**Written-by note (persistence):**
- this 0x4: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** BLOCKED (returns 0) when count <= 0 (empty array). When value found at index, replaces with last element, decrements count. When value not found, returns count (index past end).
