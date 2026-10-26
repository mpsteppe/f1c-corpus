## ExceptionObjectConstructor_0059a781 — Exception object constructor with string copy and flag transfer

**Summary:** Constructs `std::runtime_error` exception object. Copies source string via StrlenAllocCopyConstructorPattern, transfers a byte flag from source to new object at offset 0xC, initializes SEH handler, and sets vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CThrowWithException (0059a70b), sub_59A854 (0059a854)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xC | R | — | Source flag byte at offset 12, copied to new object |
| this | 0x8 | R | — | Pointer to source argument (input param) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d4a0 | loc_59D4A0 | R | SEH continuation/landing pad address |
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |
| 005b9d28 | ??_7runtime_error@std@@6B@ | R | RuntimeErrorVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release reference count on internal buffer (this+3) |
| 0059a9ca | sub_59A9CA | Copy subrange from source buffer to destination buffer |
| 0059bf56 | StrlenAllocCopyConstructorPattern | Allocate and copy string (strlen + alloc + memcpy pattern) |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
