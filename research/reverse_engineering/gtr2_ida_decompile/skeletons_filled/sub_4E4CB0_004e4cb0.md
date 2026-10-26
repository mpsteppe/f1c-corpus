## sub_4E4CB0_004e4cb0 — Indicator bitmask query (blink pattern / threshold ladder)

**Summary:** Returns a status bitmask (values 0,1,2,3,4,7,8,15) for a UI/indicator consumer: either a time-based blink pattern (parity toggle or a 6-phase walk 1,2,4,8,4,2 driven by dbl_FB1D18), or a progressive threshold ladder derived from the ratio of two floats in the dword_91E07C block (0.9/0.93/0.96/0.977 breakpoints).

**Called by:** sub_564A10 (00564a10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004e4db4 | jpt_4E4D29 | R | jump table for the switch on (dbl_FB1D18 * 3 mod 6) |
| 006f2320 | flt_6F2320 | R | float constant read by this region; one of the ratio-ladder thresholds (exact literal not attributable in the decompiled listing) |
| 006f3254 | flt_6F3254 | R | float constant read by this region; one of the ratio-ladder thresholds (exact literal not attributable in the decompiled listing) |
| 006f3464 | flt_6F3464 | R | float constant read by this region; one of the ratio-ladder thresholds (exact literal not attributable in the decompiled listing) |
| 00713274 | flt_713274 | R | float constant read by this region; one of the ratio-ladder thresholds (exact literal not attributable in the decompiled listing) |
| 00713278 | flt_713278 | R | float constant read by this region; one of the ratio-ladder thresholds (exact literal not attributable in the decompiled listing) |
| 0091e078 | dword_91E078 | R | element index added to the dword_91E088 base for the first compared object |
| 0091e07c | dword_91E07C | R | base pointer of a large data block: queried via sub_5785A0(+16) and read as floats at indices 4307/4308 |
| 0091e080 | dword_91E080 | R | element index added to the dword_91E088 base for the second compared object |
| 0091e088 | dword_91E088 | R | base pointer of an object array; the field at +22468 is compared between the two selected elements |
| 00b682e8 | dword_B682E8 | R | flag gating the time-based blink-pattern branch |
| 00fb1d18 | dbl_FB1D18 | R | double time/accumulator: ×2 parity for the toggle and ×3 mod 6 for the 6-phase blink walk |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005785a0 | sub_5785A0 | query called with (dword_91E07C + 16, this); a non-zero byte result short-circuits the function into the time-parity return |
| 0063099c | __ftol2 | compiler runtime truncating the double expressions (time×3, time×2) to integers |

**Guard conditions:** First gate: if sub_5785A0(dword_91E07C+16, this) returns non-zero, the function immediately returns 15 or 0 depending on the parity of (dbl_FB1D18+dbl_FB1D18) — nothing else runs. Second gate: the blink-pattern branch requires the +22468 field of two array elements (indices dword_91E078 / dword_91E080) to be equal AND dword_B682E8 to be non-zero. Otherwise the ratio branch runs: ratio = float[4307] / float[4308] of dword_91E07C — below 0.9 → 0, 0.9..0.93 → 1, 0.93..0.96 → 3, >=0.96 → 7, and >=0.977 → 15.

**String literals referenced (deterministic):**

- `fff?333?` — literal data bytes referenced by this region; its use is not visible in the decompiled body shown.
