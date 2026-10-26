## ConstructorWithVTableAndFloatInit_00466a30 — ConstructorWithVTableFloatAndIndex

**Summary:** Constructor. Calls InitVTableSet(this, a3, a4), sets vtable to off_59F380, initializes field 0x104 to 0.5f, clears byte at 0x100, and stores a2 at 0x108.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer, set to off_59F380 |
| this | 0x100 | RW | 0 | byte flag cleared to 0 |
| this | 0x104 | RW | 1056964608 → 0.5f | field index 66 — default multiplier 0.5 |
| this | 0x108 | RW | — | field index 67 — stored parameter a2 (index/ID) |

**Written-by note (persistence):**
- this 0x0: once (constructor). External poke overwrites.
- this 0x100: once (constructor). External poke survives.
- this 0x104: once (constructor). External poke survives.
- this 0x108: once (constructor). External poke survives.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f380 | off_59F380 | R | alternate UI vtable pointer |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004668e0 | InitVTableSet | base init with vtable and params |

**Guard conditions:** None — unconditional.
