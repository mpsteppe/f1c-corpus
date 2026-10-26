## MemoryAllocation_d900_004bd900 — DynamicArrayPushAlt

**Summary:** Appends a value to a dynamic integer array (capacity at this+0xC, count at this+0x10, data at this+0x14); grows capacity by 8 when full — same logic as DynamicArrayPush_004bd860 but uses different field offsets.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4BE010 (004be010)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | array capacity (grows by 8 when full) |
| this | 0x10 | R | — | current element count |
| this | 0x14 | RW | — | pointer to array data buffer |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free old array buffer on reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocate new larger array buffer |

**Guard conditions:** none — always pushes. Capacity auto-grows when count == capacity.
