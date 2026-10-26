## sub_54FAA0_0054faa0 — Random-record eligibility check triggering sub_41D240

**Summary:** Rolls a random index (< 2048); when the index is below 104, the matching 22616-byte record's first dword is zero, and a global state pair passes its condition, it invokes sub_41D240, then always releases this[5] via sub_5ED990 and returns 0.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | this[5] handed to sub_5ED990 (cleanup/release target) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0091cb98 | flt_91CB98 | R | unknown (not visibly referenced in decompiled body) |
| 00923e84 | dword_923E84 | R | Base of stride-5654-dword (22616-byte) records; first dword of record [5654*v3] must be 0 |
| 00b640c8 | dword_B640C8 | R | Pointer to a global state dword; value != 6 is one branch of the trigger condition |
| 00b64134 | dword_B64134 | R | Global counter; value == 5 is the alternative branch of the trigger condition |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d240 | sub_41D240 | No-argument action executed only when the full condition passes |
| 005da960 | sub_5DA960 | Fills int out-param with a random/bounded value (second arg 2048); called twice (v3, v4) |
| 005ed990 | sub_5ED990 | Called with this[5] on exit (release/cleanup) |

**Guard conditions:** Trigger requires ALL of: v3 < 104 AND dword_923E84[5654*v3] == 0 AND (*(DWORD*)dword_B640C8 != 6 OR dword_B64134 == 5). PASSES → sub_41D240() runs. BLOCKED (any of): v3 >= 104, record slot nonzero, state == 6 with dword_B64134 != 5. In every case the function still calls sub_5ED990(this[5]) and returns 0.
