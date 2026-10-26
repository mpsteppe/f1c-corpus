## sub_4CDDE0_004cdde0 — ResetStateBlock

**Summary:** Straight-line initializer/reset of a state block at 0x10C–0x11C: zeroes three dwords, sets one byte to 1, clears two bytes, stores 2 into the last dword. Returns 0.

**Called by:** CallWrapperReturning0 [exact] (00491aa0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10C | RW | 0 | Dword reset to 0 (counter/pointer in the state block) |
| this | 0x110 | RW | 0 | Dword reset to 0 (counter/pointer in the state block) |
| this | 0x114 | RW | 0 | Dword reset to 0 (counter/pointer in the state block) |
| this | 0x118 | RW | 1 | Byte set to 1 (enable/active flag) |
| this | 0x119 | RW | 0 | Byte cleared to 0 (sub-flag) |
| this | 0x11A | RW | 0 | Byte cleared to 0 (sub-flag) |
| this | 0x11C | RW | 2 | Dword set to 2 (mode/state value) |

**Written-by note (persistence):**
- this 0x10C: Written unconditionally to 0 each invocation — an external poke survives only until the next call
- this 0x110: Written unconditionally to 0 each invocation — an external poke survives only until the next call
- this 0x114: Written unconditionally to 0 each invocation — an external poke survives only until the next call
- this 0x118: Written unconditionally to 1 each invocation — an external poke survives only until the next call
- this 0x119: Written unconditionally to 0 each invocation — an external poke survives only until the next call
- this 0x11A: Written unconditionally to 0 each invocation — an external poke survives only until the next call
- this 0x11C: Written unconditionally to 2 each invocation — an external poke survives only until the next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no branches. All seven fields are written with constants on every call (three dwords cleared, flag bytes = 1/0/0, mode dword = 2); the function always returns 0.
