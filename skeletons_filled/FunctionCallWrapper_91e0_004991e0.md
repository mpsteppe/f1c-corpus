## FunctionCallWrapper_91e0_004991e0 — UI element constructor / registrar

**Summary:** Constructor for a UI element: zeroes sentinel/index fields, sets vtable to off_5ACA74 (UIElementVTable), and registers with system via sub_4992E0. Part of UI element creation pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_492710 (00492710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | off_5ACA74 | vtable pointer — UIElementVTable |
| this | 0x40 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x44 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x48 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x50 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x54 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x58 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x5C | RW | -1 (0xFFFFFFFF) | terminal/end sentinel — set to -1 |
| this | 0x60 | RW | 0 | sentinel/counter — zeroed on init |
| this | 0x64 | RW | -1 (0xFFFFFFFF) | terminal/end sentinel — set to -1 |

**Written-by note (persistence):**
- this 0x0: written once unconditionally in constructor; vtable persists for object lifetime
- this 0x40: written once unconditionally; zero init in constructor
- this 0x44: written once unconditionally; zero init in constructor
- this 0x48: written once unconditionally; zero init in constructor
- this 0x50: written once unconditionally; zero init in constructor
- this 0x54: written once unconditionally; zero init in constructor
- this 0x58: written once unconditionally; zero init in constructor
- this 0x5C: written once unconditionally; -1 sentinel init in constructor
- this 0x60: written once unconditionally; zero init in constructor
- this 0x64: written once unconditionally; -1 sentinel init in constructor

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005aca74 | off_5ACA74 | R | UIElementVTable [DERIVED] — assigned to this+0x0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004992e0 | sub_4992E0 | registers/creates object with system, called with parameter a2 |
| 0049a930 | ConstructorWith1Sentinels | base class constructor with sentinel initialization |

**Guard conditions:** none — unconditional constructor sequence
