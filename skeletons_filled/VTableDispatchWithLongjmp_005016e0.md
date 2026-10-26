## VTableDispatchWithLongjmp_005016e0 — ExceptionSafeVtableDispatch

**Summary:** Calls a vtable function at offset 8, then performs a longjmp to a recovery/jump buffer at offset 132 in the vtable data area. If longjmp returns, restores context state by copying offset 28→0 and 32→4 of a secondary context struct. A fiber/yield or SEH recovery pattern.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | Vtable function pointer at offset 8 (dispatch target before longjmp) |
| this | 0x0 | R | — | First DWORD (vtable pointer / dispatch table base) |
| this | 0x14 | RW | — | Context pointer (v1) loaded for state restoration |
| this | 0x18 | RW | — | Secondary context pointer (not directly used by this function) |
| this | 0x30 | R | — | v1[7] source value for context restoration (copied to v1[0]) |
| this | 0x34 | R | — | v1[8] source value for context restoration (copied to v1[1]) |

**Written-by note (persistence):**
- this 0x14: Not written directly; pointer stored here (v1) has its target fields updated
- this 0x18: Not written directly by this function

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a770 | LongjmpMSVCCRT | Longjmp to recovery buffer (MSVCRT longjmp wrapper) |

**Guard conditions:** None. Always calls vtable function then longjmps. If longjmp returns (buffer set to 0?), copies state and returns 1.
