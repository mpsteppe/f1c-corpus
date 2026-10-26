## VtableDelegateDispatch_00515db8 — VtableDelegateDispatch

**Summary:** Sequence three operations: audio channel allocation, buffer copy/validation, then two vtable dispatches (a1+0x194, a1+0x184). Copies field at offset 4 from second dispatch result to pointer at a1+0x18C.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIScreenStateMachine (00515df2)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x184) | 0x0 | R | — | vtable base of delegate at slot 0x184 |
| *(this+0x184) | 0x4 | R | — | field read after delegate dispatch — copied to destination |
| *(this+0x18C) | 0x0 | RW | — | destination pointer — written with value from *(this+0x184)+4 |
| *(this+0x194) | 0x0 | R | — | vtable base of delegate at slot 0x194 |
| this | 0x184 | R | — | vtable slot 0x184 — second delegate function pointer |
| this | 0x18C | R | — | destination pointer slot — where result field gets copied |
| this | 0x194 | R | — | vtable slot 0x194 — first delegate function pointer |

**Written-by note (persistence):**
- *(this+0x18C) 0x0: overwritten each call; survives until overwritten

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00515bb0 | AudioVoiceChannelAllocation | allocate audio voice channels for this context |
| 00515d26 | ObjectBufferCopyWithValidation | allocate and copy object data buffers |

**Guard conditions (deterministic — field vs literal):**

No guard conditions — function always executes full sequence unconditionally.
