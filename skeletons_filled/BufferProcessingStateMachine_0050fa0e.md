## BufferProcessingStateMachine_0050fa0e — Buffer processing state machine with batch dispatch

**Summary:** Processes data buffers in state 204, tracking progress via counter (offset 0x78) against a limit (offset 0x60). For each chunk, calls a callback object (at this+0x8) and a processing function (at this+0x180+4). When batch completes, flushes via this+0x17C functions and resets counter. When processing flag clears, transitions to state 205 or 206.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineWithDispatch (0050fb3b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x17C) | 0x0 | R | — | Init/reset function (called when state != 204 to reinitialize) |
| *(this+0x17C) | 0x4 | R | — | End-of-batch flush function (called after each batch completes) |
| *(this+0x17C) | 0x8 | R | — | Processing active flag (when zero, batch processing is complete) |
| *(this+0x180) | 0x4 | R | — | Data processing function (advances counter for each chunk) |
| *(this+0x8) | 0x0 | R | — | Callback function (called per chunk if callback object exists) |
| *(this+0x8) | 0x4 | RW | — | Counter value written to callback object per chunk |
| *(this+0x8) | 0x8 | RW | — | Limit value written to callback object per chunk |
| this | 0x8 | R | — | Pointer to callback object (called per chunk if non-null) |
| this | 0x10 | RW | 204 | State variable (204 = active processing; 205/206 = completion) |
| this | 0x41 | R | — | Flag byte determining final state (205 if nonzero, 206 if zero) |
| this | 0x60 | R | — | Limit/capacity value (maximum counter before batch flush) |
| this | 0x78 | RW | 0 | Counter value (current progress, incremented by processing function) |
| this | 0x17C | R | — | Pointer to batch processing control block (init, flush, active flag) |
| this | 0x180 | R | — | Pointer to data processing control block (processing function at +4) |

**Written-by note (persistence):**
- *(this+0x8) 0x4: conditional write (each chunk, if callback exists) — external poke does not survive
- *(this+0x8) 0x8: conditional write (each chunk, if callback exists) — external poke does not survive
- this 0x10: unconditional write (204 on init, 205/206 on completion) — external poke does not survive
- this 0x78: unconditional write (0 after init, 0 after batch flush, updated during processing) — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | != | 204 | State variable — if not 204, reinitialize and reset to 204 |
| this | 0x41 | != | 0 | Flag byte at offset 0x41 — determines final state: 205 if nonzero, 206 if zero |

**Guard interpretation:** If `this+0x10 != 204`, the state machine is reinitialized (call init function, zero counter, set state to 204) — this BLOCKS processing until state is correctly 204. If `*(this+0x17C)+0x8` flag is set, processing loops continue (chunk callback and data processing); when flag clears, transition to completion state 205/206 based on `this+0x41` — a nonzero byte produces state 205, zero produces state 206.
