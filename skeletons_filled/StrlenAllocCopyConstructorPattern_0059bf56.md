## StrlenAllocCopyConstructorPattern_0059bf56 — SharedStringCopyCtor

**Summary:** Copy constructor for exception string with conditional deep copy: if source refcount at a2+8 is non-zero, allocates new buffer and copies string; if zero, shares source pointer without copy.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ExceptionObjectConstructor (0059a781), CObjectConstructorWithVtable (0059ae7d)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | VTable pointer (set to exception::`vftable') |
| this | 0x4 | RW | — | String buffer pointer (deep copy or shared from source) |
| this | 0x8 | RW | — | Refcount/copy-mode flag (copied from source a2+8) |

**Written-by note (persistence):**
- this 0x0: written once (vtable assignment)
- this 0x4: written once (new allocation or shared pointer)
- this 0x8: written once (copied from source)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b9dc0 | ??_7exception@@6B@ | R | ExceptionVTable [DERIVED] — MSVC exception vtable |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | Allocate memory for deep string copy |
| 0058e1b0 | Strlen | Get length of source string |
| 0058fca0 | sub_58FCA0 | Initialize/copy string data into allocated buffer |

**Guard conditions:** If this[2] (source refcount) is 0, skips allocation+copy and directly shares the source string pointer at a2+4. If allocation returns null (v5 == 0), skips copy but still returns this.
