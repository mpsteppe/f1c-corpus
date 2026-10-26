## InitWithVTableParam_00498d20 — Object Initializer With VTable and Param

**Summary:** Initializes an object by calling parent constructor, setting the vtable pointer to off_5AC9E8, running multi-field struct initialization, and storing a parameter value at offset 0x44.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConstructorWithVTableAndSubInit_9140 (00499140)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Vtable pointer set to off_5AC9E8 during initialization |
| this | 0x44 | RW | — | Initialization parameter stored from argument a2 |

**Written-by note (persistence):**
- this 0x0: Written once during construction (vtable); persists for object lifetime
- this 0x44: Written during construction; persists until explicitly modified

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ac9e8 | off_5AC9E8 | R | Vtable assigned to this object at offset 0x0 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00498df0 | MultiFieldStructInit | Zero-initializes or sets default values for multiple struct fields |
| 0049a930 | ConstructorWith1Sentinels | Parent class constructor with sentinel initialization |

**Guard conditions:** (none — always executes unconditionally)
