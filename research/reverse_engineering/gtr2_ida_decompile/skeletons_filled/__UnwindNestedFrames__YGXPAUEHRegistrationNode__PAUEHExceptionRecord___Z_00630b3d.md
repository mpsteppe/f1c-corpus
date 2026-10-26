## ?_UnwindNestedFrames@@YGXPAUEHRegistrationNode@@PAUEHExceptionRecord@@@Z_00630b3d — _UnwindNestedFrames (unwind nested EH registration frames)

**Summary:** MSVC C++ EH helper: unwinds the nested registration frames down to TargetFrame via RtlUnwind (resuming at the internal continuation label), clears the unwind-in-progress flag on the exception record, then refreshes the caller-visible exception chain head from the TEB. Called by TranslatorGuardHandler and CatchIt during nested exception propagation.

**Called by:** ?TranslatorGuardHandler@@YA?AW4_EXCEPTION_DISPOSITION@@PAUEHExceptionRecord@@PAUTranslatorGuardRN@@PAX2@Z (00630cc7), ?CatchIt@@YAXPAUEHExceptionRecord@@PAUEHRegistrationNode@@PAU_CONTEXT@@PAXPBU_s_FuncInfo@@PBU_s_HandlerType@@PBU_s_CatchableType@@PBU_s_TryBlockMapEntry@@H1E@Z (006362a7)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Exception record's flags dword — modified after unwinding |

**Written-by note (persistence):**
- this 0x0: modified unconditionally when the function runs: the value-2 (unwind-in-progress) bit is cleared. Any external poke of that bit is overwritten on the next unwind.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00630b66 | loc_630B66 | R | Continuation label immediately after the RtlUnwind call — supplied as RtlUnwind's resume address |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00643d44 | RtlUnwind [exact] | Unwinds the target frame chain to TargetFrame, invoking handlers, then returns control at &loc_630B66 |

**Guard conditions:** None — unconditional sequence: RtlUnwind(TargetFrame, &loc_630B66, ExceptionRecord, 0) runs, then the exception record's value-2 flag bit is cleared (`&= ~2`), then the caller-provided pointer (a1, in EBX) is updated with the current TEB ExceptionList head. No values checked; nothing skipped or blocked.
