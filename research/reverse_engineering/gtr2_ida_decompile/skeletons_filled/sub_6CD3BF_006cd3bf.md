## sub_6CD3BF_006cd3bf — Compute object offsets and balance totals

**Summary:** Walks the caller's object list (+0x38 count, +0x3C list) and for each listed object writes a running offset into array +0x2C and a zeroed counter into array +0x28, then adjusts the counter by counting incoming links (object field +0x58 equal to the object index) and outgoing links (object field +0x5C non-zero) found through the two per-object index arrays. Returns the accumulated total in *a2 and the largest per-object offset in *a3.

**Called by:** sub_6CD4DC (006cd4dc), sub_6CD96E (006cd96e)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | pointer to shared world/context struct whose +0x14 and +0x18 arrays hold per-object records |
| this | 0x8 | R | — | per-object count N used for the object's first index list |
| this | 0xC | R | — | per-object start index into the index array at +0x10 |
| this | 0x10 | R | — | index array holding the first list of related object indices |
| this | 0x18 | R | — | unknown (not traceable to a use in this decompilation) |
| this | 0x1C | R | — | per-object count of the second index list |
| this | 0x20 | R | — | per-object start index into the index array at +0x24 |
| this | 0x24 | R | — | index array holding the second list of related object indices |
| this | 0x28 | R/W | — | per-object balance counter: zeroed, decremented per incoming link, incremented per outgoing link |
| this | 0x2C | W | — | per-object running offset (accumulated base position) written for every listed object |
| this | 0x38 | R | — | number of entries in the object list at +0x3C |
| this | 0x3C | R | — | array of object indices to process |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** for objects in the list, the counter/total logic runs only if `(*(_WORD *)(object + 2) & 0xFFF0) != 0` — objects whose word at +2 has none of bits 4..15 set are skipped (only the +0x28 zeroing and +0x2C offset write happen). The incoming-link scan runs only when count `*(object + 0x8)` is non-zero (v13, do/while); the outgoing-link scan only when count `*(object + 0x1C)` is non-zero. Output writes are optional: *a2 only when a2 non-null, *a3 only when a3 non-null.
