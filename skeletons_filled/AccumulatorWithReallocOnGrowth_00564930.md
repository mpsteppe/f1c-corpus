## AccumulatorWithReallocOnGrowth_00564930 — realloc buffer with growth increment

**Summary:** Grows dynamic audio buffer: adds growth increment to capacity, calls sub_58B5D4 (realloc) to resize buffer, updates capacity (offset 0x4) and buffer pointer (offset 0x14). Called by AudioStackPushWithOverflowRealloc when buffer is full.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioStackPushWithOverflowRealloc (005648d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | current capacity, updated to capacity + growth increment |
| this | 0x8 | R | — | element size stride (multiplier for new capacity) |
| this | 0xC | R | — | growth increment added to capacity each expansion |
| this | 0x14 | RW | — | buffer pointer, replaced by new allocation |

**Written-by note (persistence):**
- this 0x4: unconditionally overwritten each call; external poke survives only if value matches new capacity
- this 0x14: unconditionally overwritten each call; external poke lost

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058b5d4 | sub_58B5D4 | memory reallocation (realloc equivalent) |

**Guard conditions:** None — caller (AudioStackPushWithOverflowRealloc) checks capacity before calling.
