## ObjectInitWithVTableState_0046eec0 — Object init with vtable and sentinel state

**Summary:** Calls sub_4893C0 for base initialization, sets vtable to off_59FED0, sets signed DWORD field at offset 0x174 to -1 (sentinel/invalid state), then returns constructed object pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_59FED0 | vtable pointer — set to off_59FED0 after base initialization |
| this | 0x174 | RW | -1 (0xFFFFFFFF) | signed DWORD field at offset 372 (this[93]) — initialized to -1 as sentinel/invalid state |

**Written-by note (persistence):**
- this 0x0: once — written by this function, persists until object destroyed or vtable swapped
- this 0x174: once — written by this function, persists until explicitly modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059fed0 | off_59FED0 | R | vtable reference assigned to object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base initializer for object |

**Guard conditions:** No guards. Always runs sub_4893C0, sets vtable, sets sentinel value, returns this.
