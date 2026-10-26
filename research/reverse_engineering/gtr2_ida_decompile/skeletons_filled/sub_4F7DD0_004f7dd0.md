## sub_4F7DD0_004f7dd0 — find entry by id in slot table

**Summary:** Lookup helper: if the master pointer at this+0x8C is set, checks whether the current entry (this+0xA0) already matches the queried id a2 via its +96/+116 fields; otherwise scans the 120-byte-stride entry array at this+0x9C (count at this+0x98) for an entry whose +116 field equals a2, and on a hit tail-jumps into the shared code at 004F59C0 instead of returning.

**Called by:** sub_4F7EC0 (004f7ec0), sub_4F8030 (004f8030), sub_4F8BD0 (004f8bd0), sub_4FA940 (004fa940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8C | R | — | master/valid pointer gating the lookup; if null the function does nothing |
| this | 0x98 | R | — | number of entries in the slot array (scan limit) |
| this | 0x9C | R | — | base pointer of the slot array; entries are 120 bytes apart |
| this | 0xA0 | R | — | pointer to the current/default entry, compared via its +96 and +116 fields |
| this | 0x100 | R | — | unknown — not directly visible in the provided listing |
| this | 0x110 | R | — | unknown — not directly visible in the provided listing |
| this | 0x114 | R | — | unknown — not directly visible in the provided listing |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** (1) `this[0x8C]` must be non-zero, else immediate return. (2) The current entry at this+0xA0 is accepted only if it is non-null AND one of its id fields (`+96` or `+116`) equals a2 — if so the scan is skipped entirely. (3) Otherwise the scan runs only while `this[0x98] > 0`; each entry (base this+0x9C, stride 120 bytes, stride starts at field +116) is compared to a2 — a match transfers control to 004F59C0 (JUMPOUT, no normal return); no match exhausts the count and returns the count value, while a zero count returns 0.
