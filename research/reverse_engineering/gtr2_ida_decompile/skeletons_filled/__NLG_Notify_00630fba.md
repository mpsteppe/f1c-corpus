## __NLG_Notify_00630fba — _NLG_Notify (saves notify state)

**Summary:** CRT/NLG helper used during SEH handling: captures the notify value (EAX), the frame pointer (EBP) and the frame's dword at +8 into the global NLG state block, then returns the value unchanged. Called by __except_handler3 and the MSVCRT SEH frame unwinder.

**Called by:** MSVCRTSEHFrameUnwinder [structural] (00630f26), __except_handler3 (00631f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00912870 | unk_912870 | R | NLG notify state storage — this routine saves the notify argument, frame pointer and frame's +8 dword into the state block |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — unconditional: three stores (frame's dword at +8, the result value, the frame pointer) into the NLG state block, then return the result. The a3 argument is unused and no values are checked.
