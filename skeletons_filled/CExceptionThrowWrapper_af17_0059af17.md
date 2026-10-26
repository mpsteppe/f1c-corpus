## CExceptionThrowWrapper_af17_0059af17 — C++ exception throw wrapper for std::length_error

**Summary:** Throws `std::length_error` exception. Calls VTableConstructor to build the exception, invokes CxxThrowException8 with length_error type info, then runs ExceptionDestructor cleanup. If the stack buffer flag bit 0 is set, frees allocated memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bb890 | __TI3?AVlength_error@std@@ | R | Excep_LengthErrorTypeInfo [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory |
| 0059aeda | ExceptionDestructor | Destroy logic_error base with vtable reset |
| 0059af50 | VTableConstructor | Construct length_error exception with vtable |
| 0059bfc3 | CxxThrowException8 | Invoke _CxxThrowException with type info |

**Guard conditions:** `if ((v5[4] & 1) != 0)` — PASSES when allocation flag bit 0 set → calls FreeWrapper_7bcf. BLOCKED when bit 0 clear → skip free.
