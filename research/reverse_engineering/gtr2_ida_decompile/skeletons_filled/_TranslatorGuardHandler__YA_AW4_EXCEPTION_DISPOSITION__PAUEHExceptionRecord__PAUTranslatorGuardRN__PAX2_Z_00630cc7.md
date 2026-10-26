## ?TranslatorGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUTranslatorGuardRN@@PAX2@Z_00630cc7 — TranslatorGuardHandler (translator frame handler)

**Summary:** Guard handler installed by _CallSETranslator: recognizes its own registration frame via the dword_912B08 marker, dispatches the catch through sub_6365D0, unwinds nested frames when the frame's done-flag is clear, then returns through the continuation pointer captured by the sentinel _CallSETranslator(0x123) call. On marker mismatch it flags the exception and continues the search.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912b08 | dword_912B08 | R | Marker compared against the guard frame's state field (frame+8) to identify this exception pass |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00630b3d | ?_UnwindNestedFrames@@YGXPAUEHRegistrationNode@@PAUEHExceptionRecord@@@Z | Unwinds nested registration frames when the frame's done-flag (frame+36) is still 0 after dispatch |
| 00630c00 | ?_CallSETranslator@@YAHPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAX2PBU_s_FuncInfo@@H1@Z | Sentinel call (a1 = 0x123) that rewires the frame and captures the continuation pointer v5 |
| 006365d0 | sub_6365D0 | Catch dispatch routine — invoked with the frame's handler/FuncInfo/context to transfer control into the matching catch |

**Guard conditions:** First compares the frame's state dword (TargetFrame+8) with dword_912B08. Mismatch → sets ExceptionFlags |= 8 and returns 1 (ContinueSearch); nothing else runs. Match → checks ExceptionFlags & 0x66: if any of those bits is set, writes 1 to the frame's done-flag (TargetFrame+36) and returns 1 without dispatching. Otherwise it dispatches via sub_6365D0, and only if the done-flag is still 0 afterwards does it call _UnwindNestedFrames; then performs the sentinel _CallSETranslator call and returns v5() (the captured continuation).
