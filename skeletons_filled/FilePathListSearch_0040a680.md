## FilePathListSearch_0040a680 — FilePath List Search

**Summary:** Searches a hybrid list (8 fixed entries + variable-length array) of file path entries for a match against given path string a2. Returns pointer to first matching entry or 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | File path entry 0 (fixed) |
| this | 0x14 | R | — | File path entry 1 (fixed) |
| this | 0x18 | R | — | File path entry 2 (fixed) |
| this | 0x1C | R | — | File path entry 3 (fixed) |
| this | 0x20 | R | — | Base pointer for variable-length file path array (stride 200) |
| this | 0x24 | R | — | File path entry 5 (fixed, index 4 skipped) |
| this | 0x28 | R | — | File path entry 6 (fixed) |
| this | 0x2C | R | — | File path entry 7 (fixed) |
| this | 0x30 | R | — | File path entry 8 (fixed) |
| this | 0x34 | R | — | Unused in this function (index this[13] not referenced) |
| this | 0x38 | R | — | Count of variable-length array entries (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default fallback file path string when entry's own path is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00588410 | sub_588410 | String comparison function (returns 0 on match) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x38 | > | 0 | Variable array entry count |

**Guard interpretation:** a2 parameter must be non-null or function returns 0 immediately. Each entry pointer (this[4..7], this[9..12]) must be non-null to be checked. Variable array loop runs 0..this[14]-1 entries only when this[14] > 0. The entry's path string at +4 defaults to byte_5EA438 if null.
