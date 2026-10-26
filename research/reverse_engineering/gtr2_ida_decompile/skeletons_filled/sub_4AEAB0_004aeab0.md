## sub_4AEAB0_004aeab0 — Countdown tick with list sync and event post

**Summary:** Per-call tick: decrements the countdown at this+0x254 and, when it reaches exactly 0, calls sub_49A6B0(ebp_arg, 1); then either runs the alternate handler sub_49A2A0 when this+0x258 >= 0, or runs the list synchronizer sub_4AE810(this, 0) and, if this+0x260 is set, posts event (2, 6/7) via sub_4D41C0. __usercall (this in ecx, extra argument in ebp).

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x254 | RW | — | Countdown counter; decremented while > 0, hitting 0 fires sub_49A6B0(a2, 1) |
| this | 0x258 | R | — | Signed selector; >= 0 routes to sub_49A2A0, < 0 routes to the sync + event path |
| this | 0x260 | R | — | Flag byte; when clear the event post is skipped, when set sub_4D41C0(2, 6/7) is called |

**Written-by note (persistence):**
- this 0x254: decremented by 1 on every call while positive and latched at 0 afterwards; an external poke installs a new countdown that then decays one per call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075b17c | dword_75B17C | R | Global mode/suppress flag; when it equals 1 the function returns after the countdown handling, skipping the sub_49A2A0/sub_4AE810 paths |
| 00b722e4 | byte_B722E4 | R | Selects the sub_4D41C0 second argument: nonzero → 7, zero → 6 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049a2a0 | sub_49A2A0 | Alternate handler run when this+0x258 >= 0 (this pointer passed) |
| 0049a6b0 | sub_49A6B0 | Fired with (a2, 1) when the 0x254 countdown reaches exactly 0 |
| 004ae810 | sub_4AE810 | List synchronizer called with a2 = 0 when this+0x258 < 0 |
| 004d41c0 | sub_4D41C0 | Posts event (2, 6) or (2, 7) at the end when this+0x260 is set |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x258 | >= | 0 | Non-negative selects the sub_49A2A0 path; negative (skips it) proceeds to sub_4AE810 + event post |

**Guard interpretation:** Countdown decrement runs first and is unconditional for values > 0; reaching 0 fires sub_49A6B0 once. dword_75B17C == 1 blocks everything after the countdown (early return). this+0x258 >= 0 → sub_49A2A0 runs and the function returns (sync and event post are BLOCKED); only when this+0x258 < 0 does sub_4AE810(this, 0) run, and the trailing sub_4D41C0(2, 6/7) only fires when this+0x260 != 0 (flag byte_B722E4 picks 7 over 6).
