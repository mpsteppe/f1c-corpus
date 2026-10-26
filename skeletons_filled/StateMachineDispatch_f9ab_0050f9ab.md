## StateMachineDispatch_f9ab_0050f9ab — State machine dispatch wrapper with extended result handling

**Summary:** Wraps `StateMachineDispatch` (sub_50F86A) with additional handling for result code 2: optionally dispatches vtable opcode 50 based on `a2` flag, then calls `VirtualDispatchConditionalValue`. Also vtable-dispatches opcode 18 for states other than 200/201 before delegating to inner state machine.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Target vtable pointer (for opcode dispatch) |
| obj | 0x14 | RW | 50 | Operation code written before result-2 dispatch |
| obj | 0x18 | RW | — | State value written as parameter (for opcode-50 dispatch) |
| this | 0x0 | R | — | State machine vtable pointer |
| this | 0x10 | R | — | State variable (checked for 200/201 to skip pre-dispatch) |

**Written-by note (persistence):**
- obj 0x14: conditional write (only on non-200/201 state, and on result==2 with a2 set) — external poke survives otherwise
- obj 0x18: conditional write (only on non-200/201 state) — external poke survives otherwise

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050f86a | StateMachineDispatch | Inner state machine dispatcher (handles states 200-202+ processing) |
| 00516937 | VirtualDispatchConditionalValue | Called when inner dispatch returns 2 (completion with condition) |

**Guard conditions:** If state is 200 or 201, skip the initial vtable opcode-18 dispatch (these states are handled by the inner StateMachineDispatch). If inner dispatch returns 1, return immediately. If inner dispatch returns 2 and `a2` is set, additionally dispatch vtable opcode 50 before `VirtualDispatchConditionalValue`.
