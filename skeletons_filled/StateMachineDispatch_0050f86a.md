## StateMachineDispatch_0050f86a — State machine dispatch for buffer/resource processing

**Summary:** Drives a state machine using `this+0x10` as state variable. Handles states 200 (init), 201 (process), 202 (done), 203-208/210 (processing via function pointer), and unknown states (dispatched through vtable with opcode 18). Transitions to terminal state 202 on success.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineDispatch_f9ab (0050f9ab)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | Target object vtable pointer (for default-case dispatch) |
| obj | 0x14 | RW | 18 | Operation code written before default dispatch |
| obj | 0x18 | RW | — | State value written as parameter before default dispatch |
| this | 0x0 | R | — | State machine vtable pointer (used for function slot lookups) |
| this | 0x10 | RW | 202 | State variable (200=init, 201=process, 202=done, >202=processing) |
| this | 0x14 | R | — | Function pointer slot (a1[5] + 8 — called during state 200 init) |
| this | 0x1C | R | — | Function pointer at offset 0x1C (a1[7]) |
| this | 0x18C | R | — | Processing function pointer at a1[99] (called for state processing) |
| this | 0x190 | R | — | Processing function pointer at a1[100] (a1[99] + 4) |

**Written-by note (persistence):**
- obj 0x14: conditional write (only on default case) — external poke survives otherwise
- obj 0x18: conditional write (only on default case) — external poke survives otherwise
- this 0x10: unconditional write (advances state or sets to 202) — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0050f6f7 | sub_50F6F7 | Called when processing returns 1 to finalize transition to state 202 |

**Guard conditions:** State 200 runs init calls then falls through to processing. State 201 passes through immediately to processing. State 202 returns 1 immediately (terminal). States 203-208 and 210 dispatch directly to processing function `a1[99]`. All other states use vtable dispatch with opcode 18 and return 0. Processing function at `a1[99]` returning 1 triggers `sub_50F6F7` and state advance to 202.
