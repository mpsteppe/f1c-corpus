## ExceptionCleanupWithDestructorCall_0059a728 — Exception cleanup with runtime_error vtable and destructor

**Summary:** Sets vtable to std::runtime_error, decrements reference count on embedded sub-object at offset 0xC with conditional free flag, then calls MSVCExceptionDestructor to finalize exception object cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DestructorPatternWithConditionalFree (0059a765)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d48c | loc_59D48C | R | address of exception handler code registered by SEHHandlerInit |
| 005b9d28 | ??_7runtime_error@std@@6B@ | R | RuntimeErrorVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 005993af | ReferenceCountDecrementWithConditionalFree | decrements reference count on embedded sub-object at this+0xC with free flag=1 |
| 0059bfa0 | MSVCExceptionDestructor | final destructor call for MSVC exception object |

**Guard conditions:** None — unconditional.
