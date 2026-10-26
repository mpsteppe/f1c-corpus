## sub_4FBE60_004fbe60 — attach/replace second object pointer (this+0x8) with hook on collision

**Summary:** Single-slot object attach: stores `a2` into the pointer field at `this+0x8` only when that slot is empty (calling sub_4F7EC0 on the new object with two zero arguments). If a different object is already assigned, the store is refused and the incoming object is forwarded to the global function pointer off_16C9294 instead.

**Called by:** sub_4FEFE0 (004fefe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | — | Pointer to the currently attached object (`this[2]`); read for comparison on every call, written only on the empty-slot path. |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?] — Conditional single write: only when the slot currently equals 0 and `a2` is nonzero (`this[2] = a2`). If the slot is already occupied by a different pointer, this function never overwrites it (it diverts to off_16C9294), so an external poke of a nonzero value survives this routine; an externally poked 0 will be replaced by the next attach call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 016c9294 | off_16C9294 | R | Global function pointer invoked with `a2` on the "slot already occupied" path; its target is assigned at runtime and is not resolved in this body (the callee table's sub_4FA870 entry is the only candidate for this indirect target). |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f7ec0 | sub_4F7EC0 | Called as `sub_4F7EC0(a2, 0, 0)` immediately after storing `a2` into the empty slot — initialization/registration of the newly attached object with two zero parameters. |
| 004fa870 | sub_4FA870 | Unknown — not present in the emitted body; listed by the callee table as an indirect target of this routine (plausibly via off_16C9294). |

**Guard conditions:**
- `a2 == 0`: nothing happens — no store, no call (early no-op).
- `a2 == this[2]`: nothing happens — the assignment is a no-op and the function returns.
- `this[2] != 0` and `a2 != this[2]`: store is BLOCKED; control goes to off_16C9294(a2) and that pointer's return value is returned.
- `this[2] == 0` and `a2 != 0`: the only PASS path that writes — sets `this[2] = a2`, then calls sub_4F7EC0(a2, 0, 0).
