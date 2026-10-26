## SEHProtectedDataCopy_0057a760 — SEHProtectedDataCopyWithValidation

**Summary:** SEH-guarded data copy operation. Validates state via sub_5853B0; on success copies bounded data from a3 to a2, stores result size in a3 and state dword in a4. Returns 0 on success, 11 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TeamRadioNetworkMessageProcessing (0045f710)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | ULONG_PTR value passed as context to sub_5853B0 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059c778 | SEH_57A760 | R | SEH exception registration/dispatch table for this function |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005853b0 | sub_5853B0 | predicate — validates state context, returns bool; gates the copy |
| 00586700 | SEHProtectedDirectXRenderStateSetup | initializes SEH-protected state buffer on stack |
| 005867b0 | SEHGuardedFunctionWithExceptionHandling | cleans up / finalizes SEH scope |
| 00586a10 | BoundedMemoryCopyWithSizeValidation | copies data from source to dest with size bounds checking |

**Guard conditions:** sub_5853B0(v6, v10) return non-zero → PASSES (perform copy, return 0). Return zero → BLOCKED (skip copy, return 11).

