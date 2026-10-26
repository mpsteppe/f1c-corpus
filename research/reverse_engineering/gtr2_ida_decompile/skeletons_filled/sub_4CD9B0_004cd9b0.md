## sub_4CD9B0_004cd9b0 — guarded state advance with context check and broadcast

**Summary:** `__thiscall` orchestration routine: raises the guard byte at this+0x110, consults the context object obtained via sub_4E29F0(state) (only when this[0xF4] is non-zero) and aborts early if that context has a live handle and a different id at +16 than this[0x88]; otherwise it clears the guard and advances the state machine (state 4 → 0 or 2 depending on sub_4CD720, state 3 → 2, state 1 → 0) through virtual slot +0x2C, fetches two values via sub_4DE540, and when byte 0x64 is clear, the virtual +0x14 predicate passes with those values, and virtual +0x94 reports zero, broadcasts via sub_4CD5A0(this, byte+0x111) and returns 0; otherwise returns -1.

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x14 | R | — | Vtable slot +0x14; predicate invoked with the two values returned by sub_4DE540 — must be non-zero for the broadcast path |
| obj | 0x2C | R | — | Vtable slot +0x2C; transition setter invoked with `this` and target state 0 or 2 |
| obj | 0x94 | R | — | Vtable slot +0x94; predicate — must return zero to allow the broadcast (non-zero blocks) |
| this | 0x0 | R | — | Vtable pointer used to resolve slots +0x14, +0x2C and +0x94 |
| this | 0x64 | R | — | Byte flag; must be zero for the state-4 transition and for the final broadcast path |
| this | 0x84 | R | — | State index (this[33]); used both for the sub_4E29F0 context query and the switch (cases 1, 3, 4 act) |
| this | 0x88 | R | — | Identity/id (this[34]) compared against the context object's field +16; mismatch with a live handle aborts early |
| this | 0xF4 | R | — | Enable flag (this[61]); when zero the sub_4E29F0 context query is skipped (context = 0) |
| this | 0x110 | RW | 0 | Guard byte: set to 1 for the context query, cleared to 0 before the switch; remains 1 only on the early-return path |
| this | 0x111 | R | — | Byte payload (this[273]) forwarded to sub_4CD5A0 on the success path |

**Written-by note (persistence):**
- this 0x110: Written every call (1 at entry, 0 after the context check). Cleared to 0 except when the routine returns early on the context mismatch, where it stays 1. An external poke does not survive a full pass; on the early path it is immediately overwritten with 1.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cda98 | jpt_4CDA03 | R | Jump table for the this[0x84] switch dispatch |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004cd5a0 | sub_4CD5A0 | Indirect forwarder (thunk through off_16CA268); invoked with (this, byte at +0x111) on the success path |
| 004cd720 | sub_4CD720 | Predicate consulted in state 4: non-zero selects transition target 2, zero selects 0 |
| 004de540 | sub_4DE540 | Getter writing two int values through out-parameters (&v8, &v7); results feed the virtual +0x14 predicate |
| 004e29f0 | sub_4E29F0 | Context lookup by state this[0x84]; returns a context object (handle at +36, id at +16) or null |

**Guard conditions:** The sub_4E29F0 context query runs only if this[0xF4] != 0 (else context = 0). Early return 0 if the context exists AND its +36 handle is non-zero AND this[0x88] != context+16 (identity mismatch). State-4 transition requires byte 0x64 == 0. Final broadcast requires byte 0x64 == 0 AND virtual +0x14(this, v8, v7) non-zero AND virtual +0x94(this) zero; any other combination falls through to return -1.
