## UIScrollListUpdate_0048a8d0 — Scroll list animation update tick

**Summary:** Per-frame scroll list update: reads timing values, updates animation counter (this[0x148]), clamps pixel scroll position (this[0x150]), dispatches navigation advance or counter decrement based on byte flags. Called each frame for smooth scrolling.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1C | R | — | vtable method offset 28 — returns dimension for position clamp lower bound |
| obj | 0x24 | R | — | vtable method offset 36 — returns dimension for position clamp upper bound |
| obj | 0x2C | R | — | vtable method offset 44 — refresh call with arg 1 |
| this | 0x0 | R | — | vtable pointer |
| this | 0x40 | R | — | this[16] — argument passed to FunctionCallWrapper_8940 for animation calc |
| this | 0x144 | R | — | byte flag — if set, calls DecrementCounterVirtualCall (scroll backward) |
| this | 0x145 | R | — | byte flag — if set, calls UINavigationAdvanceHandler (scroll forward) |
| this | 0x146 | R | — | byte flag — if set AND this[0x160] > 0, enables position clamp logic |
| this | 0x148 | RW | — | this[82] — float animation timer/counter from FunctionCallWrapper_8940 |
| this | 0x150 | RW | — | this[84] — pixel scroll position, clamped within bounds |
| this | 0x15C | R | — | this[87] — offset value subtracted in position calculation |
| this | 0x160 | R | — | this[88] — max scroll content height (guard for clamp logic) |

**Written-by note (persistence):**
- this 0x148: written every call unconditionally (animation timer); survives until next frame
- this 0x150: written conditionally when scroll flag (0x146) and content height (0x160) > 0; clamped within dimension bounds; survives until next frame

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489500 | DecrementCounterVirtualCall | decrements scroll counter (scroll backward/move up) |
| 00489530 | UINavigationAdvanceHandler | advances navigation index (scroll forward/move down) |
| 00489ee0 | ShortComputation_9ee0 | recomputes scroll index from clamped pixel position |
| 00498880 | DualFieldRead | reads dual frame-timing values for animation |
| 00498940 | FunctionCallWrapper_8940 | computes animation timer value from this[16] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x160 | > | 0 | this[88] — max scroll / content height |

**Guard interpretation:** Position clamp logic only runs if byte at this[0x146] is non-zero AND this[0x160] (content height) > 0. Then if timer (this[0x148]) > 0.25, dispatch depends on byte flags: this[0x144] → DecrementCounterVirtualCall, this[0x145] → UINavigationAdvanceHandler.
