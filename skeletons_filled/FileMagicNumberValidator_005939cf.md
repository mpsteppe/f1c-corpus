## FileMagicNumberValidator_005939cf — CppExceptionRecordValidate

**Summary:** Validates that a double-indirected pointer points to a well-formed C++ exception record: checks exception code 0xE06D7363, NumberParameters == 3, magic 0x19930520, and no nested continuation (ExceptionInformation[2] == 0).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SEHWrapperAroundCRTFunctionCall (005938b4)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | ExceptionCode from EXCEPTION_RECORD |
| obj | 0x10 | R | — | NumberParameters from EXCEPTION_RECORD |
| obj | 0x14 | R | — | ExceptionInformation[0] — magic value 0x19930520 |
| obj | 0x1C | R | — | ExceptionInformation[2] — nested continuation pointer |
| this | 0x0 | R | — | The exception record pointer (*a1) being validated |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x0 | == | 18446744073179853667 | ExceptionCode == 0xE06D7363 (CPP_EXCEPTION) |
| obj | 0x10 | == | 3 | NumberParameters == 3 |
| obj | 0x14 | == | 429065504 | ExceptionInformation[0] == 0x19930520 |

**Guard interpretation:** Returns TRUE only when ALL checks pass: ExceptionCode == 0xE06D7363, NumberParameters == 3, ExceptionInformation[0] == 0x19930520, AND ExceptionInformation[2] == 0 (no nested continuation). Returns FALSE if any check fails, blocking dispatch through the C++ exception path.
