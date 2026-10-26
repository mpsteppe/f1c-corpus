## ConstructorVTableSetInit_0057a160 — PhysicsVtableConstructor

**Summary:** Constructor that sets the PhysicsVtable pointer at offset 0 and calls SmallStructFieldInit to initialize remaining fields. Returns this pointer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BA10 (0057ba10), AudioStreamConstructWithVTableInit (00581e80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | vtable pointer (set to off_5B8A00 PhysicsVtable) |

**Written-by note (persistence):**
- this 0x0: written unconditionally with vtable address; survives as persistent vtable pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8a00 | off_5B8A00 | R | PhysicsVtable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a1e0 | SmallStructFieldInit | initializes struct fields after vtable assignment |

**Guard conditions:** none.
