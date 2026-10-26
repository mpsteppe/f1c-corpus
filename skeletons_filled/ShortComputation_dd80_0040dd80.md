## ShortComputation_dd80_0040dd80 — ShortComputation_dd80

**Summary:** State machine with 7 states: states -1/0/1/5 block (return 0), states 2/3 dispatch a virtual call and transition to state 4 (return 1), state 4 is active (return 1). Default transitions to error state -1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | state field, switch dispatch value |
| this | 0x4 | R | — | pointer passed to VirtualDispatchHelper for virtual call dispatch |
| this | 0x8C | RW | — | destination for VirtualDispatchHelper result (first slot) |
| this | 0x90 | RW | — | destination for VirtualDispatchHelper result (second slot, same value) |
| this | 0x94 | RW | — | written with dword_7C54DC (CurrentPlayerIndex) on transition |

**Written-by note (persistence):**
- this 0x0: state transitions — written to 4 (from 2/3) or -1 (from default) — final value persists
- this 0x8C: written unconditionally when state is 2 or 3 — survives
- this 0x90: written unconditionally when state is 2 or 3 — survives
- this 0x94: written unconditionally when state is 2 or 3 — survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040ddc8 | jpt_40DD8B | R | jump table for switch statement |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED], stored into this+0x94 on state 2/3 transition |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040c870 | VirtualDispatchHelper | dispatches virtual call via pointer this+0x4, returns result stored in this+0x8C and this+0x90 |

**Guard conditions:**
- this+0x0 == -1, 0, 1, 5 → BLOCKED (goto LABEL_5, return 0, no state change).
- this+0x0 == 2 or 3 → PASSES (dispatch virtual call, store results, set state=4, return 1).
- this+0x0 == 4 → PASSES (state already active, return 1 directly).
- this+0x0 == any other value → BLOCKED (default: set state=-1, return 0).
