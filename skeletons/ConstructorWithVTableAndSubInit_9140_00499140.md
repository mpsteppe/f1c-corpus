## ConstructorWithVTableAndSubInit_9140_00499140 — Constructor with vtable assignment

**Summary:** Constructor: calls base initialization via InitWithVTableParam, then sets vtable pointer to off_5ACA30. Part of object construction chain.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492460 (00492460)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ACA30 | vtable pointer — set to derived vtable after base init |

**Written-by note (persistence):**
- this 0x0: written once unconditionally in constructor; vtable pointer persists for object lifetime

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aca30 | off_5ACA30 | R | PTR_VTABLE_5ACA30 [DERIVED] — derived-class vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498d20 | InitWithVTableParam | base class / parent initialization with parameter |

**Guard conditions:** none — unconditional constructor
