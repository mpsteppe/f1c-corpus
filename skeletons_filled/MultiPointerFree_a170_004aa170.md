## MultiPointerFree_a170_004aa170 — TriplePointerFree

**Summary:** Frees up to three pointers stored at object offsets 0x14, 0xC, and 0x4. Each pointer is null-checked before calling FreeWrapper_7bcf.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StaticInitBulk (004a8b80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | pointer 3 (freed last) |
| this | 0xC | R | — | pointer 2 (freed second) |
| this | 0x14 | R | — | pointer 1 (freed first) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | heap free wrapper, called for each non-null pointer |

**Guard conditions:** Three sequential null checks: offset +0x14 non-null → free it; offset +0xC non-null → free it; offset +0x4 non-null → free it. Null pointers are skipped silently.
