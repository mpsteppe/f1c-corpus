## __global_unwind2_00630ee4 — _global_unwind2 (RtlUnwind wrapper)

**Summary:** CRT wrapper around RtlUnwind: unwinds the frame chain up to TargetFrame with no exception record or return value, resuming at the _gu_return label. Used by __except_handler3 for SEH (__try/__except) unwinding.

**Called by:** __except_handler3 (00631f40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00630efc | _gu_return | R | Continuation label passed to RtlUnwind as the address to resume at after the unwind |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00643d44 | RtlUnwind [exact] | OS unwind service — walks and unwinds frames to TargetFrame, then transfers control to &gu_return |

**Guard conditions:** None — unconditional RtlUnwind(TargetFrame, &gu_return, 0, 0); no values checked, nothing skipped or blocked.
