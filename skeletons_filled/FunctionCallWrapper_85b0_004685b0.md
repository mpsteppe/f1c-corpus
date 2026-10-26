## FunctionCallWrapper_85b0_004685b0 — ObjectConstructorWithVTableInit

**Summary:** Constructs an object by calling a base initializer, setting vtable pointer, zeroing a command/state field, and setting a field to -1 sentinel value. Belongs to object construction system (render/entity subsystem based on vtable).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonDatabaseObjectFactory (0047f440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_59F718) |
| this | 0x174 | RW | 0 | command/state field (this[93]); zeroed |
| this | 0x178 | RW | 18446744073709551615 | sub-type/ID field (this[94]); set to -1 sentinel |

**Written-by note (persistence):**
- this 0x0: set to off_59F718 on every call.
- this 0x174: written to 0 on every call.
- this 0x178: written to -1 on every call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f718 | off_59F718 | R | RenderEntityVTable_59F718 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004893c0 | sub_4893C0 | performs base initialization of the object |
| 0048a3b0 | ByteSetterAt0xe0 | sets a byte at offset 0xE0 in some global/context to 0 |

**Guard conditions:** No guard conditions — unconditional initialization of all fields.
