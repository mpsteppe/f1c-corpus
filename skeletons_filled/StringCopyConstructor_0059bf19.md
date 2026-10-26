## StringCopyConstructor_0059bf19 — ExceptionStringCopyCtor

**Summary:** Copy constructor for exception string: copies message from source exception into newly allocated buffer, sets vtable (exception vftable) and refcount to 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CExceptionInitHandler (0059a69a), CExceptionInitHandler_ada3 (0059ada3)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (set to exception::`vftable') |
| this | 0x4 | RW | — | Pointer to heap-allocated string copy buffer |
| this | 0x8 | RW | 1 | Ownership/refcount flag (initialized to 1) |

**Written-by note (persistence):**
- this 0x0: written once (vtable assignment)
- this 0x4: written once (allocation result)
- this 0x8: written once (init 1)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9dc0 | ??_7exception@@6B@ | R | ExceptionVTable [DERIVED] — MSVC exception vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory for string copy (len+1) |
| 0058e1b0 | Strlen | Get length of source string |
| 0058fca0 | sub_58FCA0 | Initialize/copy string data into allocated buffer |

**Guard conditions:** No guard — always constructs the object. If allocation returns null, this[1] is set to 0 and function still returns this.
