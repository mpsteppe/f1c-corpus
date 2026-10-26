## SEHUnwindHandler_0058a331 — SEHUnwindWithCleanup

**Summary:** SEH unwind handler that calls RtlUnwind to a known landing pad, clears UNWIND bit (0x02) in ExceptionFlags, and updates the exception list pointer. Standard CRT SEH unwind helper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RenderStateSetupWithFlagChecks (0058a4e5), MultiArgRenderingDispatchWithLayout (00593839)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | ExceptionList pointer (a1@ebx): updated with current TEB exception list |

**Written-by note (persistence):**
- this 0x0: Written once; stores current NtTib.ExceptionList value back to caller's pointer

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0058a359 | loc_58A359 | R | Landing pad address for RtlUnwind (continuation point after unwind) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059b24a | RtlUnwind | Unwind stack frames up to TargetFrame, jumping to loc_58A359 |

**Guard conditions:** None — function always executes all steps (RtlUnwind, flag clear, list update).
