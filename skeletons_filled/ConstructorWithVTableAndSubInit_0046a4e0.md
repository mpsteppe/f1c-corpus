## ConstructorWithVTableAndSubInit_0046a4e0 — SeasonDatabaseObjectConstructor

**Summary:** Constructor for season database object. Calls base initializer sub_4893C0, zeros field at 0x174, sets field at 0x178 to -1, sets vtable to off_59F938, clears byte at 0xe0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer |
| this | 0x174 | RW | 0 | season state/counter, initialized to 0 |
| this | 0x178 | RW | 18446744073709551615 | season identifier/index, initialized to -1 (max) |

**Written-by note (persistence):**
- this 0x0: set to vtable once during construction; survives
- this 0x174: set to 0 once during construction; survives
- this 0x178: set to -1 once during construction; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f938 | off_59F938 | R | vtable for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base/sub-object constructor |
| 0048a3b0 | ByteSetterAt0xe0 | clears byte at offset 0xe0 to 0 |

**Guard conditions:** None — unconditional constructor, no branch conditions.
