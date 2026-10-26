## CExceptionInitHandler_0059a69a — C++ runtime_error exception init handler

**Summary:** Initializes a C++ std::runtime_error exception object: copies string from byte_5EA438, stores first byte from caller-provided buffer at this+0xC, decrements reference count on embedded sub-object at this+0xC, calls sub_59A9CA, and sets vtable to runtime_error.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_59A5FE (0059a5fe)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x0 | R | — | first byte of caller-provided buffer, copied to this+0xC |
| this | 0x8 | R | — | pointer to caller-provided byte buffer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d478 | loc_59D478 | R | address of exception handler code registered by SEHHandlerInit |
| 005b9c38 | dword_5B9C38 | R | SetupConstantValue [DERIVED] (also: setup constant) |
| 005b9d28 | ??_7runtime_error@std@@6B@ | R | RuntimeErrorVTable [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a5d8 | SEHHandlerInit | registers SEH exception handler for frame |
| 005993af | ReferenceCountDecrementWithConditionalFree | decrements reference count on embedded sub-object at this+0xC |
| 0059a9ca | sub_59A9CA | processes/releases caller-provided buffer pointer |
| 0059bf19 | StringCopyConstructor | copies string into exception object |

**Guard conditions:** None — unconditional.
