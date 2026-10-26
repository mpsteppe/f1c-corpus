## sub_4FAE10_004fae10 — randomized spawn/action gate with cooldown

**Summary:** Decides whether a vehicle-related action may trigger now: returns 0 while the game clock is past the fade cutoff, validates the primary entity and its camera/state fields (20476 > 2.0, state not 4/5) against the reference record a2, then computes a fill-fraction-based random chance (rand() % int(v21)) and, on success, arms a cooldown timestamp at this+0x1A0 (now+4.0 or now+6.0) and returns 1.

**Called by:** sub_429EF0 (00429ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A0 | RW | — | cooldown timestamp (this[104]): compared against the game clock and set to clock+4.0 or clock+6.0 when the gate passes |

**Written-by note (persistence):**
- this 0x1A0: written only on the success paths (clock+4.0, clock+6.0); an external poke survives until the next successful trigger, and a far-future value blocks the action until the clock catches up.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f16d0 | flt_6F16D0 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f16ec | flt_6F16EC | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f1a30 | flt_6F1A30 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f2320 | flt_6F2320 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f30dc | flt_6F30DC | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f314c | flt_6F314C | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f3154 | flt_6F3154 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 006f3158 | flt_6F3158 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 00714a78 | flt_714A78 | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 00714a7c | flt_714A7C | R | float constant used in the cooldown/ratio math (exact operand not visible in the listing) |
| 00731ce8 | String2 | R | string constant; not directly dereferenced in the listing (possibly a debug tag used by a callee) |
| 00757c10 | dword_757C10 | R | number of entries in the this[] pointer array (loop bound and ratio denominator) |
| 00b640c8 | dword_B640C8 | R | pointer to the current game-state dword; values 2/3/4/6 are branch selectors |
| 00fade1c | flt_FADE1C | R | start of the fade/countdown window; +1300.0 gives the upper limit |
| 00fade20 | flt_FADE20 | R | fade/countdown cutoff time compared against the game clock |
| 00fb1d18 | dbl_FB1D18 | R | current game clock (also used as an epoch in the cooldown compare) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041fb10 | sub_41FB10 | returns a float relation value (tested in the range 0.0 > v >= -55.0) between the reference record and the entity |
| 00422780 | sub_422780 | extracts the value passed to sub_41FB10 from an entity object |
| 004f1ef0 | sub_4F1EF0 | predicate on the object resolved by sub_4FB7D0; true suppresses the main block |
| 004fb7d0 | FieldAccessor [exact] | resolves the inner object from the record field at +14824 (a2+3706 dwords) |
| 0063099c | __ftol2 | float→int conversion for the fill count and the rand()%v21 modulo |
| 00631ba8 | _rand | random source for the probabilistic trigger |

**Guard conditions:** (1) `dbl_FB1D18 > flt_FADE20` → immediate 0 (past the fade window). (2) The main block is skipped (returns 0) when the reference record matches: `a2[5192] == 4` AND sub_4FB7D0(a2+3706) non-null AND sub_4F1EF0(resolved) non-zero. (3) Inside the per-slot scan, a slot object with `+20852` zeroed is cleared (this[i]=0); a slot whose relation value satisfies `0 > v9 > -55.0` returns 0 if its `+20768` field is neither 4 nor 5 and `+20476 > 2.0`. (4) `*dword_B640C8 == 6` → immediate 1. (5) The probability branch requires `a2[5228] > a2[5374]`; the ratio uses 0.8x or 0.9x of dword_757C10 depending on state 2/3/4, clamps v16 to 0.01 minimum, v17 to 0.001 if zero, and duration v20 to at least 1.0. (6) Success paths: if this[104] < clock in the first check → return 1 with clock+4.0; otherwise the rand()%v21==0 case (or state 6, which bypasses the modulo) only returns 1 with clock+6.0 when the clock has reached this[104]; the `v21 < 1.0` fallback also requires this[104] < clock. Everything else falls through to 0.

**String literals referenced (deterministic):**

- `fff?333?
`
