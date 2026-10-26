## ShortComputation_e7d0_0046e7d0 — Constructor with vtable and field reset

**Summary:** Calls sub_4893C0 for base initialization, sets vtable pointer to off_59FE18, zeroes byte field at offset 372 (this[372]), then returns constructed object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FE18 | vtable pointer — set to off_59FE18 after base initialization |
| this | 0x174 | RW | 0 | byte field at offset 372 — explicitly zeroed after construction |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped
- this 0x174: once — written by this function, persists until explicitly modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fe18 | off_59FE18 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base initializer for object |

**Guard conditions:** No guards. Always runs sub_4893C0, sets vtable, zeroes field, returns this.
