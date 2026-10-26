## sub_6A3C8C_006a3c8c — ValidateChunkPatterns

**Summary:** Validates the descriptor staged at this[0x100]: splits it into v54 chunks of v50 elements, decodes each chunk's category row (control byte bit 0 decides category vs entry+16), matches rows against the global 5-row table via sub_6A326C, and depending on the category layout either registers 3/4-element pattern rows via sub_6C5456 or falls back to sub_681C03; clears the staged pointer at this[0x100] on success. Part of the object/asset graph building system.

**Called by:** sub_6AD36C (006ad36c)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | base table of the two-level indirection whose control byte bit 0 selects category v15 vs entry+16 |
| this | 0x14 | R | — | base of the entry pointer array indexed by ids taken from the descriptor's lists |
| this | 0xC8 | R | — | low 16 bits compared against 260; when != 260 the extra sub_6A32C7 category scan runs and can set v46/v51 |
| this | 0x100 | RW | 0 | staged descriptor pointer processed by this routine; first dword cleared to 0 on successful completion |
| this | 0x104 | R | — | unknown — not visibly referenced in this decompiled body |
| this | 0x108 | R | — | unknown — not visibly referenced in this decompiled body |
| this | 0x10C | R | — | unknown — not visibly referenced in this decompiled body |
| this | 0x110 | R | — | unknown — not visibly referenced in this decompiled body |

**Written-by note (persistence):**
- this 0x100: cleared (written 0) on each successful completion of this routine, both on the early sub_681C03 path and at LABEL_106; an external poke would be overwritten the next time this function processes a staged descriptor, so it only survives until the next call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00681c03 | sub_681C03 | generic descriptor processing path, used when the type is 0x50000000/count mismatch and when no chunk pattern matches; negative result aborts |
| 006a326c | sub_6A326C | wildcard-tolerant row match against the global table; returns 0 marks "no match" and sets v51 / clears v55 in the pattern loops |
| 006a32c7 | sub_6A32C7 | partial category coverage check on the descriptor; when true the entry list is scanned for category 3 to set v51/v46 |
| 006c5456 | sub_6C5456 | registers a pattern row (row pointer, chunk count v54, mode 3 or 4); negative result aborts |

**Guard conditions:** Early-out when the staged descriptor (this[0x100]) is null or its first dword is 0 → return 0. If the descriptor type is 0x50000000 or v2[3] != v50 (element count mismatch) → sub_681C03 path, clear staged pointer, return. The extra category scan only runs when (unsigned __int16)this[0xC8] != 260; if it is 260, v46/v51 stay 0. Per chunk, when sub_6A326C(v34 chunk, &v35, 5) returns 0 the "no pattern" flag v51 is set. When v51 == 0 the function calls sub_681C03, clears the staged pointer and returns 0; when v51 != 0 the pattern analysis runs and registers rows via sub_6C5456 — any negative return BLOCKS with that error. The v46 flag forces failure of candidate patterns (v55 = 1) in the v50==4 and v50==3 branches.
