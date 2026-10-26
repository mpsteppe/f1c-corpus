## sub_645FAC_00645FAC — Tagged record scanner: header validation, id lookup, data/size outputs

**Summary:** Validates a header DWORD's high word against a fixed set of tags, then scans record entries for a 0xFFFE marker whose encoded count is >1 and whose id word matches a2, returning a pointer to the record data and its byte size (4*count - 4). Returns 1 on terminator 0xFFFF, negative codes on invalid input.

**Called by:** sub_67654F (0067654f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Header DWORD: high word is the tag checked against the allowed set; low word selects the stride mode (>= 0x200) |
| this | 0x4 | R | — | Stream of record DWORDs scanned by the loop (low word = entry type; high bit set = entry skipped) |
| this | 0x8 | R | — | Id word of a scanned record, compared against a2 for the match |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | >= | 512 | Low 16 bits of the header DWORD; when >= 0x200 the scanner advances entries by the encoded stride `(entry >> 24) & 0xF` instead of the 0x51 special case |

**Guard interpretation:** Validation order: `a1 == 0` → -2005530516; `header high word` (`*a1 & 0xFFFF0000`) must equal one of 1180172288 / 1415053312 / 2147352576 / 2147418112 / -131072 / -65536, otherwise -2005529767. Scan loop: entry with bit 0x80000000 set → skipped; low word 0xFFFF → return 1 (terminator, nothing found); low word 0xFFFE → candidate: its encoded count `(entry >> 16) & 0x7FFF` must be > 1 and `entry[1] == a2`, else the scan continues by adding that count; when the header low word >= 512 every entry advances by the nibble `(entry >> 24) & 0xF`, otherwise only entries with low word 81 (0x51) advance 5. On success: `*a3 = &entry[2]`, `*a4 = 4*count - 4`, return 0. Output pointers a3/a4 are cleared at entry when non-null.
