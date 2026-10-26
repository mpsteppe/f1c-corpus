## CExceptionThrowWrapper_0059a81b — C++ exception throw wrapper for ios_base::failure

**Summary:** Throws `std::ios_base::failure` exception. Calls sub_59A854 to construct the exception, invokes CxxThrowException8 with the failure type info, then runs destructor cleanup. If the stack buffer flag bit 0 is set, frees allocated memory.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bb668 | __TI3?AVfailure@ios_base@std@@ | R | TypeInfo_IOSFailure [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free heap-allocated memory |
| 0059a7de | DestructorWithSEHVTableReset | Destroy runtime_error base with vtable reset |
| 0059a854 | sub_59A854 | Construct ios_base::failure exception object |
| 0059bfc3 | CxxThrowException8 | Invoke _CxxThrowException with type info |

**Guard conditions:** `if ((v5[4] & 1) != 0)` — PASSES when allocation flag bit 0 set → calls FreeWrapper_7bcf. BLOCKED when bit 0 clear → skip free.
