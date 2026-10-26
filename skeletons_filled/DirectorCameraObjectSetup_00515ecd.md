## DirectorCameraObjectSetup_00515ecd — SetupInternalDispatchObject

**Summary:** Allocates a 24-byte dispatch sub-object via virtual allocator at *(this+4), stores result at this+0x18C. Populates it with UIScreenStateMachine pointer, three function pointers (ArithmeticComparison_5e85, VtableDelegateDispatch, VtableFunctionPointerWrite), clears two byte flags, and sets enable byte to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_50F632 (0050f632)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | vtable entry 0 of allocator/dispatcher object, called to allocate sub-object (size 24) |
| this | 0x4 | R | — | pointer to allocator/dispatcher object used to create sub-object |
| this | 0x18C | RW | — | stores the newly allocated/initialized dispatch sub-object |

**Written-by note (persistence):**
- this 0x18C: written once with allocated pointer, persists until replaced or freed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00515db8 | VtableDelegateDispatch | R | function pointer stored as dispatch table entry +4 in sub-object |
| 00515df2 | UIScreenStateMachine | R | data pointer stored as first field of sub-object |
| 00515e85 | ArithmeticComparison_5e85 | R | function pointer stored as dispatch table entry +8 in sub-object |
| 00515ebc | VtableFunctionPointerWrite | R | function pointer stored as dispatch table entry +12 in sub-object |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No conditional branches — always executes unconditionally.
