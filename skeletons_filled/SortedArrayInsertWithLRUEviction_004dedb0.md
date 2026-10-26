## SortedArrayInsertWithLRUEviction_004dedb0 — SortedLRUArrayInsert

**Summary:** Inserts 9-float entry into sorted array with LRU eviction when full (max 20 entries). Checks for duplicates first, then finds eviction candidate if full, shifts entries to fill slot, then inserts in sorted position by a2[1] key. Returns insertion result via sub_4DF110. Part of spatial/scene cache system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4DEF70 (004def70), sub_4DF030 (004df030), ConditionalRenderCall (004df0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x18 | R | — | current element count in sorted array |
| this | 0x1C | R | — | first entry data (9 floats), key field for compare |
| this | 0x20 | R | — | first entry additional float fields |
| this | 0x24 | R | — | first entry additional float fields |
| this | 0x28 | R | — | first entry additional float fields |
| this | 0x2C | R | — | first entry additional float fields |
| this | 0x30 | R | — | first entry additional float fields |
| this | 0x34 | R | — | first entry additional float fields |
| this | 0x38 | R | — | first entry additional float fields |
| this | 0x3C | R | — | first entry additional float fields |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 005ad140 | flt_5AD140 | R | PitSelectionCost [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004df110 | sub_4DF110 | notify/report insertion result with entry key and position index |

**Guard conditions:** None that block execution entirely—internal guards control duplicate check, eviction, and sorted insertion.
