## sub_663ABB_00663abb — Resolve versioned resource entry and upload its 4 parameters

**Summary:** Walks the resource-version chain hanging off the manager object (head at *(this+0x0)+0x3C, nodes linked via +0x28), grouping same-name entries by case-insensitive name compare and parsing each version string; picks the entry whose parsed version best matches this+0x10 (exact dword match preferred, else high-word match), creates the resource via sub_681A51(name, 2897, 1, 4), then feeds the entry's four doubles at +0x8 through four sub_681AAA calls. Returns 0 on completion or -2147024882 (E_OUTOFMEMORY / 0x8007000E) when creation or parameter setting fails.

**Called by:** sub_672E89 (00672e89)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x3C)+0x28) | 0x28 | R | — | next-node link of the chain entry, used to advance the scan (C: v2 = *(v2 + 40)) |
| *(obj+0x3C) | 0x0 | R | — | entry's version string pointer fed to sub_6460B4 for version parsing (C: *(v2)) |
| *(obj+0x3C) | 0x4 | R | — | entry's name string pointer (C: *(v2+4)) — stricmp grouping and the name passed to sub_681A51 |
| *(obj+0x3C) | 0x8 | R | — | first of the four doubles at entry+8..+0x17 uploaded via sub_681AAA (pointer walks +8, +0x10, +0x18, +0x20) |
| obj | 0x3C | R | — | chain-head pointer field of the manager object (obj = *(this+0x0)), loaded once as the scan start |
| this | 0x0 | R | — | pointer to the manager object; its +0x3C field is the resource-chain head (C: *this) |
| this | 0x10 | R | — | reference version dword (C: this[4]) — exact/high-word compared against each parsed entry version |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631c0d | __stricmp | case-insensitive name compare used to keep scanning only entries sharing the first entry's name |
| 006460b4 | sub_6460B4 | parses the entry's version string into v8/v9; negative return means the version is not usable |
| 00681a51 | sub_681A51 | resource creation/open call sub_681A51(name, 2897, 1, 4); returns handle or -1 on failure |
| 00681aaa | sub_681AAA | parameter setter called 4× as (handle, 0, index, double value) with the entry's doubles; -1 marks failure |

**Guard conditions:** If the chain head is NULL (v2 == 0), returns 0. Name grouping: when _stricmp of the current entry name against the group's first name differs, the inner scan breaks (group boundary). Version filtering: parse result < 0 → entry ignored; parsed == this+0x10 → kept as exact match (first only); else high word == this+0x10 high word → kept as partial match (first only). After a group: exact match wins and stops the outer scan; a partial match is used as v4 and also stops the scan; if neither, the scan continues with the next chain node. Create/set stage: if sub_681A51 returns -1 the upload is skipped and the function returns -2147024882; if any of the four sub_681AAA calls returns -1 the function returns -2147024882; when all four succeed the scan restarts (goto LABEL_18) and eventually returns 0 when the chain is exhausted.
