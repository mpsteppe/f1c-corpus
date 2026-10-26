## InitWithVTable_be70_0047be70 — ObjectBaseInitWithVTable

**Summary:** Initializes an object by calling base init sub_4893C0, setting the vtable pointer to off_5A6788, and zeroing field at offset 0x174.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_5A6788 |
| this | 0x174 | RW | 0 | counter or flag field, zero-initialized |

**Written-by note (persistence):**
- this 0x0: written once on construction (vtable); persists for object lifetime
- this 0x174: initialized to 0 once; external poke survives unless re-initialized

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a6788 | off_5A6788 | R | vtable pointer for this object type |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | base object initialization / constructor chain |

**Guard conditions:** none — always executes full init, returns this
