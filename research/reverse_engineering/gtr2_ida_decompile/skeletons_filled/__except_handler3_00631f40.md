## __except_handler3_00631f40 — MSVC C SEH handler (_except_handler3)

**Summary:** MSVC C runtime structured exception handling entry point `_except_handler3`: on non-unwind passes it walks the SEH scope table of the target frame, invokes filter expressions, and executes the matching handler after unwinding. On unwind passes it simply continues the unwind.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | — | ExceptionRecord->ExceptionFlags (a1+4): bits 0x2/0x4 detected as an unwind/exit-unwind pass; bit 0x8 set when `_ValidateEH3RN` rejects the registration |

**Written-by note (persistence):**
- this 0x4: conditionally rewritten — `|= 8` only when scope-table validation fails; otherwise the flags word is untouched by this function.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630ee4 | __global_unwind2 | Global unwind to the target frame before executing the handler |
| 00630f26 | MSVCRTSEHFrameUnwinder [structural] | Local unwind of inner frames — called for the fast unwind pass and again before the selected handler runs |
| 00630fba | __NLG_Notify | Notifies the debugger/NLG hooks that the handler at the selected scope-table entry is about to execute |
| 006396f0 | __ValidateEH3RN | Validates the EH3 registration record (scope table sanity) before it is walked |

**Guard conditions:** `if ((*(a1+4) & 6) != 0)` — unwind/exit-unwind pass: local-unwinds the target frame and returns 1 (continue search). Else builds a dispatcher context, reads `TargetFrame[3]` (scope index) and `TargetFrame[2]` (scope table) and calls `_ValidateEH3RN`; if invalid, sets ExceptionFlags bit 0x8 and returns 1. Walk loop: starts at scope index v5 and continues `while (v5 != -1)`; each entry's filter function pointer at `v6 + 12*v5 + 4` is called — if it returns nonzero: negative (CONTINUE_EXECUTION) returns 0 immediately; positive leads to unwind + NLG notify + handler invocation. Loop advances via `v5 = *(v6 + 12*v5)` (next scope entry).
