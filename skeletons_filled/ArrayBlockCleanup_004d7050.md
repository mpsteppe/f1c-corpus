## ArrayBlockCleanup_004d7050 — ArrayBlockCleanup

**Summary:** Cleans up a two-part dynamic array block structure. Iterates first array (24-byte entries at this+0xC), calling StructEntryCleanup and freeing sub-pointers; iterates second array (680-byte entries at this+0x14), calling ShortComputation_4370 on fields. Frees both array headers, zeros counters, sets sentinel at 0x20 to -1. Called by multiple teardown paths.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StructInitWithSentinels (004d7020), TireBrandFileParser (004d7150), TextureSurfaceDestroyer (004d7800)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | counter/index (cleared to 0 on cleanup) |
| this | 0xC | RW | 0 | pointer to first dynamic array block (24-byte entries) |
| this | 0x10 | RW | 0 | counter/index (cleared to 0 on cleanup) |
| this | 0x14 | RW | 0 | pointer to second dynamic array block (680-byte entries) |
| this | 0x20 | RW | 18446744073709551615 | sentinel value (set to -1 indicating cleaned state) |

**Written-by note (persistence):**
- this 0x8: cleared unconditionally to 0
- this 0xC: conditionally freed and zeroed (only if non-null pointer to array block 1)
- this 0x10: cleared unconditionally to 0
- this 0x14: conditionally freed and zeroed (only if non-null pointer to array block 2)
- this 0x20: set to -1 unconditionally (sentinel)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | global path/string buffer passed to StringCopyWithBufferRealloc |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00414370 | ShortComputation_4370 | short/value computation helper (called on fields within each 680-byte entry during cleanup) |
| 004d6800 | StructEntryCleanup | per-entry cleanup (zeros fields, frees sub-buffer at +0x14) |
| 00566650 | StringCopyWithBufferRealloc | string copy with reallocation on global buffer |
| 00587bcf | FreeWrapper_7bcf | heap memory deallocation wrapper |

**Guard conditions:** two null-pointer guards: if this+0xC (array block 1) is null, skip first cleanup loop; if this+0x14 (array block 2) is null, skip second cleanup loop. Sentinal at 0x20 set unconditionally.
