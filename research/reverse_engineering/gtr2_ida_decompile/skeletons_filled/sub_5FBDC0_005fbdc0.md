## sub_5FBDC0_005fbdc0 — Flush object list into global registration pools

**Summary:** Iterates the array at this+0x10 (count at this+0), tests each entry through a virtual call on the global manager dword_FB27A4 (vtable+396), and for qualifying entries registers their sub-records (stride 27 dwords from v5[91]) into global slot pools keyed by bucket index v6[19], appending each sub-record to its owner's array at owner+212 with counter at owner+208. Optionally first calls sub_632C60 to reset the list when a2's low byte is nonzero; returns the element count.

**Called by:** sub_5FBFF0 (005fbff0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Element count; must be > 0 for any work, drives both loops, returned as result |
| this | 0x10 | R | — | Array base (this[4]); each element is 8 bytes with a pointer at +4 loaded as v5 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a4 | dword_FB27A4 | R | Global manager object: virtual test at vtable+396 filters entries; slot allocators/counters at +9100 (free-slot index), +9124 (array base), +9084/+9108 (per-bucket counters/bases) supply pool storage for nodes and sub-records |
| 00fb27ac | dword_FB27AC | R | Global visit/context object; its byte at +200 acts as an already-registered flag and its pointer is appended into the owner's list at owner+772 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eda30 | nullsub_7 | No-op stub (hook/debug placeholder) invoked with &a2 after the linked-list node reshuffle |
| 00632c60 | sub_632C60 | Called with (this[4], *this) when the low byte of a2 is nonzero — apparently resets/clears the list array before the scan |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | Element count; only a positive count lets the body run |

**Guard interpretation:** If the count at this+0 is <= 0 the entire body is blocked and the count is returned unchanged. With count > 0, the optional reset (sub_632C60) runs only when a2's low byte is nonzero. The outer per-element loop runs while v25 < *this, so every listed entry gets the virtual manager test (vtable+396); failing entries skip registration, passing entries proceed. The fresh-registration branch (pool slot + owner list insert) runs only when `(*v5 & 0x40000000) == 0` or the byte at dword_FB27AC+200 is already set — otherwise it is skipped. The inner sub-record loop runs only while v5[90] > 0, appending each stride-27-dword record.
