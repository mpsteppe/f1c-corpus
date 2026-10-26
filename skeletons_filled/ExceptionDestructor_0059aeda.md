## ExceptionDestructor_0059aeda — std::logic_error destructor with SEH

**Summary:** Destructor for `std::logic_error` exception object. Resets vtable to logic_error, decrements reference count on internal buffer, and chains to MSVCExceptionDestructor.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CExceptionThrowWrapper_af17 (0059af17)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d59c | loc_59D59C | R | SEH continuation/landing pad address |
| 005b9d7c | ??_7logic_error@std@@6B@ | R | VTable_std_logic_error [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release reference on internal string buffer |
| 0059bfa0 | MSVCExceptionDestructor | Chain to MSVC exception destructor for cleanup |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
