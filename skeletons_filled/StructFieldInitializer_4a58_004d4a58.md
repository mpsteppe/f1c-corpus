## StructFieldInitializer_4a58_004d4a58 — StructFieldInit_4

**Summary:** Initializes two fields at offsets 4 and 8 of a struct to literal values 4 and 0. Constructor helper for a small struct.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 4 | counter or type/category ID initialized to 4 |
| this | 0x8 | RW | 0 | pointer or sub-count initialized to 0 (null/empty) |

**Written-by note (persistence):**
- this 0x4: written once (literal 4); unconditional init, survives external poke
- this 0x8: written once (literal 0); unconditional init, survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — unconditional field writes, no branches.
