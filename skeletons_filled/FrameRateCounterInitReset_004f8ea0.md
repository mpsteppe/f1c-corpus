## FrameRateCounterInitReset_004f8ea0 — FrameRateCounterInitReset

**Summary:** Resets frame rate counter struct: frees object at offset 0x18, searches for "FTFrameRate" string entry in linked list, and zeros all 13 counter/timer fields (offsets 0x0-0x2C and 0x6C).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VidMan_Post (004fac00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | Frame rate counter field 0 |
| this | 0x4 | RW | 0 | Frame rate counter field 1 |
| this | 0x8 | RW | 0 | Frame rate counter field 2 |
| this | 0xC | RW | 0 | Frame rate counter field 3 |
| this | 0x10 | RW | 0 | Frame rate counter field 4 |
| this | 0x14 | RW | 0 | Frame rate counter field 5 |
| this | 0x18 | RW | 0 | Pointer to allocated object (freed and nulled) |
| this | 0x1C | RW | 0 | Frame rate counter field 7 |
| this | 0x20 | RW | 0 | Frame rate counter field 8 |
| this | 0x24 | RW | 0 | Frame rate counter field 9 |
| this | 0x28 | RW | 0 | Frame rate counter field 10 |
| this | 0x2C | RW | 0 | Byte flag at offset 44 |
| this | 0x6C | RW | 0 | Byte flag at offset 108 |

**Written-by note (persistence):**
- this 0x0 through 0x2C, 0x6C: All zeroed each call; external poke overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d6d78 | aFtframerate | R | String_FTFrameRate [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053d130 | StringCompareLinkedListSearch | Searches linked list for matching frame rate string |
| 0053d1f0 | WideStringLinkedListSearch | Searches wide string linked list for "FTFrameRate" |
| 00557470 | EmptyStub_7470 | NOP/stub call on freed object |
| 00587bcf | FreeWrapper_7bcf | Frees heap object at offset 0x18 |

**Guard conditions:** If `this[6]` (offset 0x18) is non-null, calls EmptyStub_7470 then frees the pointer. String list search only if WideStringLinkedListSearch returns non-null.
