## sub_4FB0E0_004fb0e0 — nearest entity to reference

**Summary:** Finds the entity closest to `this[a2]` by scanning the pointer array `this[]` in parallel with a global record array (stride 5654 dwords, from dword_9248F4 to dword_B62CB4), scoring each candidate with sub_41FB10 and keeping the smallest positive score; returns the winning object pointer or 0.

**Called by:** sub_422140 (00422140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | base of the candidate pointer array; `this[a2]` is the reference entity (null → return 0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00731ce8 | String2 | R | string constant; not directly dereferenced in the listing (possibly a debug tag used by a callee) |
| 009248f4 | dword_9248F4 | R | start of the global candidate record array walked in parallel with this[] |
| 00b62cb4 | dword_B62CB4 | R | end pointer of the global candidate array (loop terminator) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041fb10 | sub_41FB10 | scores a candidate against the reference entity; only values in (0, best) are accepted |
| 00422780 | sub_422780 | extracts the candidate value from a non-null this[] entry before scoring |

**Guard conditions:** (1) `this[a2]` must be non-null or the function returns 0 immediately. (2) Per iteration, a non-null this[] slot is scored; an empty slot is only considered when the parallel global record's flag at (v4-668) is not equal to 1. (3) A candidate replaces the current best only when its score is strictly positive AND strictly smaller than the running best (initialized to 99999.0). The scan ends when the record cursor reaches dword_B62CB4.
