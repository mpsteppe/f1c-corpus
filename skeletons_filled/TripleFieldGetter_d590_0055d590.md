## TripleFieldGetter_d590_0055d590 — Read vector components from struct

**Summary:** Reads three consecutive fields at offsets 0x44/0x48/0x4C (this[17/18/19]) and writes to output pointers a2, a3, a4 if non-null. Getter counterpart to sub_55D460 vector store.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_560C10 (00560c10), sub_560FE0 (00560fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x44 | R | — | Float X component of vector (this[17]) — output to a2 |
| this | 0x48 | R | — | Float Y component of vector (this[18]) — output to a3 |
| this | 0x4C | R | — | Float Z component of vector (this[19]) — output to a4 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Each output pointer (a2/a3/a4): NULL → skip writing that field. Non-null → write field value.
