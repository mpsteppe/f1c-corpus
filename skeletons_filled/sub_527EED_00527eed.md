## sub_527EED_00527eed — ResourceBufferFreeCleanup

**Summary:** Free resource buffer struct and its sub-allocations via callback-based deallocator. Calls sub_52765A reset, then frees variable buffer, secondary buffer, and struct itself in order.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5179A2 (005179a2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | R | — | Secondary fixed buffer pointer (passed to free callback) |
| this | 0x28 | R | — | Variable buffer pointer (passed to free callback) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052765a | sub_52765A | Reset struct state before deallocation (clears fields, invokes final callback) |

**Guard conditions:** None — all three frees execute unconditionally in sequence.
