## HashTableIDResolution_00495890 — StringHashIDResolve

**Summary:** Formats an input string into a global format buffer (unk_7CDE38), then resolves it via ShortComputation_4fb0 to verify it exists in a hash/ID table. Returns the original string on success (resolved) or NULL on failure. Part of the asset/hash-table name resolution system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_497AD0 (00497ad0), sub_497BA0 (00497ba0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c2c18 | aS_4 | R | FmtStr_PercentS — "%s" format string used for safe string copy into buffer |
| 007cde00 | unk_7CDE00 | R | Unknown render/data region — accessed via ShortComputation_4fb0 during hash/ID lookup |
| 007cde38 | unk_7CDE38 | R | StringFormatBuffer — global temporary buffer for formatted/intermediate strings |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00494fb0 | ShortComputation_4fb0 | Hash table ID computation/lookup: validates string against registered entries, returns 0 if found |
| 0058815f | StringFormatWithBufferOverflowCheck | Safe sprintf with overflow check, copies input string into global format buffer |

**Guard conditions:** ShortComputation_4fb0 return value == 0 → PASS (return original string). Non-zero → BLOCKED (return NULL).
