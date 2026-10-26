## ObjectConstructorWithParameterSetup_00467260 — WindowManagerConstructor

**Summary:** Constructor for window manager object. Calls sub_48C070(0), sets vtable to off_59F4F8 (VTable_WindowManager), stores a2 at this[201] as index, computes data table pointer from unk_7C6270 + 64*a2, and initializes fields with defaults (11, 4) and clears byte at 0x305.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F4F8 |
| this | 0x305 | RW | 0 | byte flag cleared to 0 |
| this | 0x31C | RW | — | field 199 — parameter a3 (size/count) |
| this | 0x320 | RW | — | field 200 — computed data table pointer (unk_7C6270 + 64*a2) |
| this | 0x324 | RW | — | field 201 — index a2 |
| this | 0x328 | RW | 11 | field 202 — default value 11 |
| this | 0x32C | RW | 4 | field 203 — default value 4 |

**Written-by note (persistence):**
- this 0x0: once (constructor). External poke overwrites.
- this 0x305: once (constructor). External poke survives.
- this 0x31C: once (constructor). External poke survives.
- this 0x320: once (constructor). External poke survives.
- this 0x324: once (constructor). External poke survives.
- this 0x328: once (constructor). External poke survives.
- this 0x32C: once (constructor). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f4f8 | off_59F4F8 | R | VTable_WindowManager [DERIVED] |
| 007c6270 | unk_7C6270 | R | UIDataTableBase [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0048c070 | sub_48C070 | base initialization with parameter 0 |

**Guard conditions:** None — unconditional.
