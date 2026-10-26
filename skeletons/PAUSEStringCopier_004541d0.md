## PAUSEStringCopier_004541d0 — Copy PAUSE menu key name string

**Summary:** Copies a PAUSE menu key name string from a lookup table based on an index byte at offset 0xC8C. Indexes ≤ 0x5A select from aPause_0 table; indexes > 128 select from aEmpty_0 table via offset. Requires count at 0xC88 > 0 to proceed.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ParameterLookupWithFallback (00454d30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC88 | R | — | Key count/availability — must be > 0 for lookup to proceed |
| this | 0xC8C | R | — | Key index byte — selects string from PAUSE key name table |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c4890 | aPause_0 | R | PauseKey [DERIVED] — table of PAUSE key name strings (16 bytes per entry) |
| 005c4e30 | aEmpty_0 | R | StringEmpty [DERIVED] — secondary string table (16 bytes per entry) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC88 | <= | 0 | Key availability count |

**Guard interpretation:** BLOCKED if count at 0xC88 ≤ 0 → return 0 (no key data). Also BLOCKED if index byte > 0x5A (for primary table) or if index-128 ≥ 0x58 (for secondary table). PASSES only with valid index and available count.
