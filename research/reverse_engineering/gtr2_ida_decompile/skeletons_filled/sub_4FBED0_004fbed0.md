## sub_4FBED0_004fbed0 — set state mode (1/2) and result fields, gated by owner flag at +0x54AC

**Summary:** Small mode/state setter: inspects a byte flag on the owner object (`*this + 0x54AC`) and writes mode 2 + the caller's argument into this[10..12] when the flag is set, or mode 1 + zero when it is not. The chosen value is duplicated into two follow-on fields (0x2C, 0x30) and returned.

**Called by:** sub_4759A0 (004759a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x54AC | R | — | Byte flag on the owner/manager object (pointed to by `*this`); nonzero selects mode 2 with the incoming value, zero selects mode 1 with value 0. |
| this | 0x0 | R | — | Pointer to the owner object whose +0x54AC byte is tested. |
| this | 0x28 | RW | 1 | Mode field (this[10]): set to 2 when the owner flag is set, 1 otherwise. |
| this | 0x2C | RW | — | Result field (this[11]): receives the same value as this[10]'s companion (a2 or 0). |
| this | 0x30 | RW | — | Second result field (this[12]): mirrors this[11]. |

**Written-by note (persistence):**
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?] — Unconditional write on every invocation (value 1 or 2 selected by the owner flag); a poke would only survive until the next call, and call frequency is not determinable from this function alone.
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?] — Same as 0x28: unconditionally rewritten each call (a2 or 0).
- this 0x30: [LLM: written once/conditional/recalc every frame? would an external poke survive?] — Same as 0x28/0x2C: unconditionally rewritten each call (a2 or 0).

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Only branch is `*(BYTE *)(*this + 21676)` (owner flag at +0x54AC). Nonzero PASSES: mode (this[10]) becomes 2 and the result fields receive `a2`. Zero BLOCKS the argument from propagating: mode becomes 1 and result fields are set to 0 (a2 discarded).
