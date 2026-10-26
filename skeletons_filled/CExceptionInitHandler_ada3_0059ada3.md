## CExceptionInitHandler_ada3_0059ada3 — C++ logic_error exception initializer

**Summary:** Constructs a `std::logic_error` exception object. Copies a string from byte_5EA438 via StringCopyConstructor, transfers a flag byte from the parameter struct to new object at offset 0xC, replaces the string buffer with a copy from the parameter, and sets vtable to std::logic_error.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59AD49 (0059ad49), sub_59AF68 (0059af68)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | Source flag byte (first byte of parameter), copied to new object |
| this | 0x8 | R | — | Pointer to source parameter struct |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d560 | loc_59D560 | R | SEH continuation/landing pad address |
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |
| 005b9d7c | ??_7logic_error@std@@6B@ | R | VTable_std_logic_error [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release reference on existing buffer at this+3 |
| 0059a9ca | sub_59A9CA | Copy subrange from source buffer to destination buffer |
| 0059bf19 | StringCopyConstructor | Allocate and copy string from global byte_5EA438 |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
