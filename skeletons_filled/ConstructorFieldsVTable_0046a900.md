## ConstructorFieldsVTable_0046a900 — SeasonDatabaseDerivedConstructor

**Summary:** Constructor for a related season database object. Calls base constructor sub_4893C0, zeros fields at offsets 0x1F4/0x1F8/0x1FC/0x200/0x208 and byte at 0x174, sets field at 0x204 to constant 89, sets vtable to off_59F9E8.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x174 | RW | 0 | byte field, initialized to 0 |
| this | 0x1F4 | RW | 0 | field initialized to 0 |
| this | 0x1F8 | RW | 0 | field initialized to 0 |
| this | 0x1FC | RW | 0 | field initialized to 0 |
| this | 0x200 | RW | 0 | field initialized to 0 |
| this | 0x204 | RW | 89 | confidence/threshold constant, initialized to 89 |
| this | 0x208 | RW | 0 | field initialized to 0 |

**Written-by note (persistence):**
- this 0x0: set to vtable once during construction; survives
- this 0x174: set to 0 once; survives
- this 0x1F4: set to 0 once; survives
- this 0x1F8: set to 0 once; survives
- this 0x1FC: set to 0 once; survives
- this 0x200: set to 0 once; survives
- this 0x204: set to 89 once; survives
- this 0x208: set to 0 once; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f9e8 | off_59F9E8 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base/sub-object constructor |

**Guard conditions:** None — unconditional constructor, no branch conditions.
