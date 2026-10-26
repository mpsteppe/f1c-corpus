## ExceptionThrowWrapper_0059afff — C++ exception throw wrapper for std::out_of_range

**Summary:** Throws `std::out_of_range` exception. Calls ObjectInitWithVTable_b038 to build the exception, invokes CxxThrowException8 with out_of_range type info, then runs ExceptionObjectDestructorWithSEH cleanup. If the stack buffer flag bit 0 is set, frees allocated memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bb9b8 | __TI3?AVout_of_range@std@@ | R | TypeInfo_out_of_range [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory |
| 0059afc2 | ExceptionObjectDestructorWithSEH | Destroy logic_error base with vtable reset |
| 0059b038 | ObjectInitWithVTable_b038 | Construct out_of_range exception with vtable |
| 0059bfc3 | CxxThrowException8 | Invoke _CxxThrowException with type info |

**Guard conditions:** `if ((v5[4] & 1) != 0)` — PASSES when allocation flag bit 0 set → calls FreeWrapper_7bcf. BLOCKED when bit 0 clear → skip free.
