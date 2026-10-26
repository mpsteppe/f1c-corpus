## VTableDispatchWithConditionalCall_00585380 — ConditionalListAppendThenVTableDispatch

**Summary:** Conditionally appends an item to a list via ThreadSafeCallWithMutex (if a2 non-NULL), then always dispatches via vtable+0x38. Returns 0 if appended, 2 if skipped.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationTimingUpdateWithParamSet (0057a5a0), NetworkSendDispatch (0057a6a0), NetworkSessionStart (0057f2b0), sub_584230 (00584230), sub_585270 (00585270), sub_585870 (00585870), sub_587730 (00587730), sub_5878A0 (005878a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x38 | R | — | vtable+56 dispatch, called unconditionally |
| this | 0x0 | R | — | vtable pointer |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00584c70 | ThreadSafeCallWithMutex | thread-safe list append (only if a2 non-NULL) |

**Guard conditions:** a2 must be non-NULL — PASSES (calls ThreadSafeCallWithMutex). NULL — BLOCKED (skips list append). Vtable+56 always called regardless.
