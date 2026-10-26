## CObjectConstructorWithVtable_0059ae7d — logic_error exception object constructor

**Summary:** Constructs `std::logic_error` exception object. Copies source string via StrlenAllocCopyConstructorPattern, transfers a byte flag from source to new object at offset 0xC, initializes SEH handler, replaces string buffer via sub_59A9CA, and sets vtable.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CThrowWithException_ae07 (0059ae07), VTableConstructor (0059af50), ObjectInitWithVTable_b038 (0059b038)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0xC | R | — | Source flag byte at offset 12, copied to new object |
| this | 0x8 | R | — | Pointer to source argument (input param) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d588 | loc_59D588 | R | SEH continuation/landing pad address |
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |
| 005b9d7c | ??_7logic_error@std@@6B@ | R | VTable_std_logic_error [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | Initialize SEH handler frame on stack |
| 005993af | ReferenceCountDecrementWithConditionalFree | Release reference count on internal buffer (this+3) |
| 0059a9ca | sub_59A9CA | Copy subrange from source buffer to destination buffer |
| 0059bf56 | StrlenAllocCopyConstructorPattern | Allocate and copy string (strlen + alloc + memcpy pattern) |

**Guard conditions:** No explicit guard conditions — full sequence always executes.
