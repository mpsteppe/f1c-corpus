## GrowDynamicElementArray_0059b530 — GrowElementArray

**Summary:** Grows the clip-rect/element array (2 WORDs per entry) when current count+1 exceeds capacity, using stride-based geometric growth.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BitmapAllocationTracker (0059b5c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Array pointer (updated on realloc) |
| this | 0xC | RW | — | Array capacity in elements (updated on realloc) |
| this | 0x14 | R | — | Current count of elements in use (used+1 triggers growth) |
| this | 0x1C | R | — | Growth stride (added each iteration to reach needed size) |

**Written-by note (persistence):**
- this 0x8: written on realloc (new array pointer)
- this 0xC: written on realloc (new capacity)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free old array buffer after realloc |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate new larger element array |

**Guard conditions:** If `this[5] + 1 <= this[3]` (current count+1 fits within capacity), returns 1 immediately (no growth). If allocation fails, returns 0.
