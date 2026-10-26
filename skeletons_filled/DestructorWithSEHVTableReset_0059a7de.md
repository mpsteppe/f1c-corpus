## DestructorWithSEHVTableReset_0059a7de — Exception destructor with vtable reset and SEH

**Summary:** Destructor for `std::runtime_error` exception object. Resets vtable to runtime_error, decrements reference count on internal buffer, and chains to MSVCExceptionDestructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CExceptionThrowWrapper (0059a81b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d4b4 | loc_59D4B4 | R | SEH continuation/landing pad address |
| 005b9d28 | ??_7runtime_error@std@@6B@ | R | RuntimeErrorVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release reference count on internal string buffer |
| 0059bfa0 | MSVCExceptionDestructor | Chain to MSVC exception destructor for cleanup |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
