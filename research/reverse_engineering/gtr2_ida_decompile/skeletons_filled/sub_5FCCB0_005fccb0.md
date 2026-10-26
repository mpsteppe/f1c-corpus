## sub_5FCCB0_005fccb0 — Guarded index dispatch (multi-argument variant)

**Summary:** Same guarded-forwarding shape as its sibling: when a2 is below the bound at this+0x2C it tail-calls the global function pointer off_16C92DC with (a2, a3, a4, a5) and returns that result; when a2 is at or above the bound the call is skipped and the return value is undefined in the decompilation.

**Called by:** sub_5438E0 (005438e0), sub_543B10 (00543b10), sub_543C80 (00543c80), sub_543E60 (00543e60), sub_544320 (00544320), sub_548230 (00548230), sub_548800 (00548800), sub_54A630 (0054a630)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | R | — | Upper bound/element count (this[11]) compared against a2 before dispatch |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c92dc | off_16C92DC | R | Function-pointer slot invoked with (a2, a3, a4, a5) when the index is in range; the resolved target is listed as sub_5D7330 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7330 | sub_5D7330 | Handler reached through off_16C92DC; processes the index plus a3/a4/a5 arguments |

**Guard conditions:** One gate: `a2 < this[11]` (index below the bound at this+0x2C). PASS: `off_16C92DC(a2, a3, a4, a5)` is executed and its value returned. BLOCKED (a2 >= this[11]): the callback is never invoked; the function returns whatever the result register happens to hold (no defined value in the decompiled code).
