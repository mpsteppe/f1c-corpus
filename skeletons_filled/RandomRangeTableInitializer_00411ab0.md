## RandomRangeTableInitializer_00411ab0 — DriverRandomRangeInitializer

**Summary:** Two-phase initialization of 537 two-word entries. Phase 1: sets all pairs to (1, 0). Phase 2: overwrites pairs (except edge indices 0, 290-292, 536) with random values derived from driver data tables. Looks up range from word_5BEBB0 (indices 1-290) or word_5BF2F8 (indices 293-535), computes range size, generates random offset via RandLCGRandomNumberGenerator, and stores (range, random_offset) into each pair.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** WrapperReturning0 (004116b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bebb0 | word_5BEBB0 | R | DriverDataTable [DERIVED] — lookup table for indices 1-290 (range boundaries) |
| 005bf2f8 | word_5BF2F8 | R | DriverDataTable2 [DERIVED] — lookup table for indices 293-535 (range boundaries) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144c0 | TableLookupByIndex | looks up index j in driver data tables to get range offset |
| 005884ed | RandLCGRandomNumberGenerator | LCG random number generator providing randomized offset within range |

**Guard conditions:** indices 0, 290, 291, 292, 536 are skipped (keep default (1,0)). If TableLookupByIndex returns < 0 for an index → skip that entry. If range size (table[j+1] - table[j]) <= 0 → skip.
