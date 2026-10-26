## InitWrapperCalling3Subroutines_00587b7f — CRT init wrapper with three subroutine calls

**Summary:** CRT initialization stub: calls InitCRTFloatConversionFunctionPointers, stores result of sub_58BCA6 in global dword_8D3E44, calls TwoArgCallWrapper, clears x87 FPU exceptions (fnclex). Returns TwoArgCallWrapper result.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008d3e44 | dword_8D3E44 | W | CRT call result; written with return value from sub_58BCA6 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587b97 | InitCRTFloatConversionFunctionPointers | Initializes CRT float conversion function pointers |
| 0058bc56 | TwoArgCallWrapper | Two-argument call wrapper; return value propagated to caller |
| 0058bca6 | sub_58BCA6 | Returns value stored in dword_8D3E44 (CRT result) |

**Guard conditions:** None — unconditional execution of all three calls plus fnclex.
