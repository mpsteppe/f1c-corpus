## StateMachineDispatcher_0050f904 — State machine dispatcher with processing loop and polling

**Summary:** State machine using `this+0x10` as state (205/206, 207, 210, other). Handles state transitions to 210, then enters a do-while loop polling a processing function pointer at `this+0x18C` until completion flag at offset 0x11 is set, triggering a final dispatch.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ImageTextureDecompressor (00501722)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x18 | R | — | Function pointer at target+24, called when processing flag is set (final dispatch) |
| *(this+0x17C) | 0x4 | R | — | Function pointer at a1[95]+4, called during state 205/206 transition |
| *(this+0x18C) | 0x0 | R | — | Processing function pointer (polled in do-while loop) |
| *(this+0x18C) | 0x11 | R | — | Completion flag byte at target+17; when set triggers final dispatch |
| obj | 0x0 | R | — | Target vtable pointer (for state dispatch calls) |
| obj | 0x14 | RW | 18 | Operation code written before default dispatch |
| obj | 0x18 | RW | — | State value written as parameter before default dispatch |
| this | 0x0 | R | — | State machine vtable pointer |
| this | 0x10 | RW | 210 | State variable (205/206 → 210, 207 → 210, 210 processed, other → vtable dispatch) |
| this | 0x14 | R | — | Pointer at a1[5] (contains function slot at +24 for final dispatch) |
| this | 0x40 | R | — | Flag at offset 0x40; when zero enables 205/206 transition path |
| this | 0x60 | R | — | Counter/limit at offset 0x60 (compared with offset 0x78 for conditional opcode-66 dispatch) |
| this | 0x78 | R | — | Counter/value at offset 0x78 (compared with offset 0x60) |
| this | 0x17C | R | — | Pointer at a1[95] (contains function slot at +4 for state transition) |
| this | 0x18C | R | — | Pointer at a1[99] (contains processing function pointer and completion flag) |

**Written-by note (persistence):**
- obj 0x14: conditional write (only on default state case) — external poke survives otherwise
- obj 0x18: conditional write (only on default state case) — external poke survives otherwise
- this 0x10: unconditional write to 210 for states 205/206/207 — external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516937 | VirtualDispatchConditionalValue | Called during final dispatch when processing flag is set |

**Guard conditions:** If state is 205 or 206 and `this+0x40` is zero: optionally dispatch vtable with opcode 66 (when `this+0x78 < this+0x60`), call function from `this+0x17C+4`, then set state to 210. State 207 immediately transitions to 210. State 210 skips state handling and enters processing loop. All other states dispatch through vtable with opcode 18. After state handling, a do-while loop polls `*(this+0x18C)+0x11` completion flag; if set, calls function from `this+0x14+24` and `VirtualDispatchConditionalValue`, returning 1. The loop continues while the processing function at `*(this+0x18C)` returns nonzero.
