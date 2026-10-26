## ShortComputation_a990_0049a990 — DestructorWithVTableSetAndFree

**Summary:** Sets the vtable pointer at offset 0x00 to off_5ACAB0, conditionally frees a pointer at offset 0x34 if non-NULL via FreeWrapper_7bcf, then calls EmptyStub_0170 on sub-object at offset 0x24 for further cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer set to off_5ACAB0 |
| this | 0x34 | R | — | pointer field conditionally freed |

**Written-by note (persistence):**
- this 0x0: vtable written once; external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005acab0 | off_5ACAB0 | R | VTable_5ACAB0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | free wrapper for field at offset 0x34 |

**Guard conditions:** this[13] (offset 0x34) checked non-NULL — if non-NULL, freed via FreeWrapper_7bcf.
