## StateMachineWithDispatch_0050fb3b — State machine with dispatch loop

**Summary:** Multi-state processing function for image/texture decompression. Handles state 202 (initialize → constructor, early-exit check, transition to 203/207), state 203 (dispatch loop with callback and counter management), and fallback states (unknown → buffer processing).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x18C) | 0x0 | R | — | dispatch object vfunc 0 entry point |
| *(this+0x18C) | 0x10 | R | — | flag byte — enables the dispatch loop when set |
| *(this+0x8) | 0x0 | R | — | callback function pointer |
| *(this+0x8) | 0x4 | R | — | callback counter (function pointer at offset 0) |
| *(this+0x8) | 0x8 | RW | — | callback limit — increased when counter reaches it |
| obj | 0x0 | R | — | state dispatcher vtable base |
| obj | 0x14 | RW | 18 | state code written on unknown-state path |
| obj | 0x18 | RW | — | copy of current state value on unknown-state path |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x8 | R | — | callback object pointer (function + counter + limit) |
| this | 0x10 | RW | 203 | state variable — 202=init, 203=dispatch, 204=other, 207=done |
| this | 0x40 | R | — | early-exit flag byte — if set, skips to state 207 |
| this | 0x7C | R | — | source limit value copied to 0x84 at LABEL_17 |
| this | 0x84 | RW | — | target limit register for buffer processing |
| this | 0x118 | R | — | increment value added to callback limit when exceeded |
| this | 0x18C | R | — | dispatch object pointer (vfunc + flag byte) |

**Written-by note (persistence):**
- *(this+0x8) 0x8: increased by this+0x118 when counter reaches limit in dispatch loop
- obj 0x14: written once on unknown state path (state != 203, != 204)
- obj 0x18: written once from this+0x10 on unknown state path
- this 0x10: state transitions: 202→207 (early exit), 202→203 (normal init), unknown→204 (external)
- this 0x84: set from this+0x7C at LABEL_17 before buffer processing

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050fa0e | BufferProcessingStateMachine | processes buffered data after state transitions |
| 00516f76 | ObjectConstructor_6f76 | constructs/initializes object on state 202 entry |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | == | 202 | state variable — initialization request |

**Guard interpretation:** If this+0x10 == 202 (PASS): run constructor, check early-exit flag (this+0x40), transition to 207 or 203. If this+0x10 != 202 (BLOCKED): skip initialization and proceed directly to state dispatch logic.
