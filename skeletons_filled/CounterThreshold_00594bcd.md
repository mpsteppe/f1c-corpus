## CounterThreshold_00594bcd — AllocatorPageCounterAndTrim

**Summary:** Adds a byte value to a per-page counter in the allocator tracking array. When the counter reaches 240 and the total live page count hits 32, triggers a page trim (sub_594AB4 with limit 16). Clears the source byte after adding.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_58AA6F (0058aa6f), sub_58B5D4 (0058b5d4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | base address used to compute page index from offset |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d41b8 | dword_8D41B8 | RW | LivePageCounter [DERIVED] — tracks total allocated live pages; triggers trim at threshold 32 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00594ab4 | sub_594AB4 | trim/decommit free pages from allocator contexts (limit 16) |

**Guard conditions:** Always executes (adds byte value, clears input). Conditional guard: trim triggered only when `*v3 == 240` (per-page counter saturated) AND `++dword_8D41B8 == 32` (total live page count reaches threshold).
