## MultiFieldMembershipCheck_0040a890 — Multi-Entry Membership Check

**Summary:** Checks if given pointer a2 matches any of the stored entries (8 fixed + variable array at this[8] with stride 200). Returns 1 (true) if found, 0 (false) otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Fixed entry 0 for membership check |
| this | 0x14 | R | — | Fixed entry 1 for membership check |
| this | 0x18 | R | — | Fixed entry 2 for membership check |
| this | 0x1C | R | — | Fixed entry 3 for membership check |
| this | 0x20 | R | — | Base pointer for variable-length entry array (stride 200) |
| this | 0x24 | R | — | Fixed entry 5 (index 4 skipped) |
| this | 0x28 | R | — | Fixed entry 6 |
| this | 0x2C | R | — | Fixed entry 7 |
| this | 0x30 | R | — | Fixed entry 8 |
| this | 0x38 | R | — | Count of variable-length array entries (loop bound) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** a2 must be non-null (null returns 0). If a2 matches any fixed entry (this[4..7], this[9..12]), returns 1 immediately skipping variable search. Variable array loop runs while index < this[14]; exits with 0 if all entries checked without match.
