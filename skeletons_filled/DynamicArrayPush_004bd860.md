## DynamicArrayPush_004bd860 — DynamicArrayPush

**Summary:** Appends a value to a dynamic integer array (capacity at this[0], count at this[1], data at this[2]); grows capacity by 8 when full by allocating a new buffer, copying existing elements, and freeing the old buffer.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BDE20 (004bde20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | array capacity (grows by 8 when full) |
| this | 0x4 | R | — | current element count |
| this | 0x8 | RW | — | pointer to array data buffer |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free old array buffer on reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocate new larger array buffer |

**Guard conditions:** none — always pushes. Capacity auto-grows when this[1] == this[0].
