## TwoFieldGetter_005424c0 — Get two fields at offsets 0x6C, 0x70

**Summary:** Reads values at offsets 0x6C and 0x70 and writes them through output pointers a2, a3 respectively. Each output pointer is null-guarded.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5550E0 (005550e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6C | R | — | first float field |
| this | 0x70 | R | — | second float field |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer individually guarded: if null, that field is skipped.
