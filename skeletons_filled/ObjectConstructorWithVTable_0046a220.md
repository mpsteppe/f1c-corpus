## ObjectConstructorWithVTable_0046a220 — ObjectConstructorWithVTableInit

**Summary:** Constructs an object by calling a base initializer, zeroing two fields, setting a field to -1 sentinel value, and assigning a vtable pointer. Belongs to object construction system (season database objects based on caller).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_59F878) |
| this | 0x344 | RW | 0 | field this[209]; zeroed |
| this | 0x348 | RW | 0 | field this[210]; zeroed |
| this | 0x34C | RW | 18446744073709551615 | field this[211]; set to -1 sentinel (0xFFFFFFFF) |

**Written-by note (persistence):**
- this 0x0: set to off_59F878 on every call.
- this 0x344: written to 0 on every call.
- this 0x348: written to 0 on every call.
- this 0x34C: written to -1 on every call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f878 | off_59F878 | R | VTable_59F878 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c9f0 | ObjectConstructorWithZeroedFields | performs base initialization of the object (zeroes fields) |

**Guard conditions:** No guard conditions — unconditional initialization of all fields.
