## D3DAnimationTimeUpdate_00550310 — AnimationTimerAdvance

**Summary:** Advances per-entry animation timers by delta time, triggering InterruptDispatch on completion and setting/resetting a completion flag bit.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_557120 (00557120)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x134) | 0x15C | R | — | Animation block field (node iteration or entry stride) |
| *(this+0x134) | 0x164 | R | — | Animation count or entry limit |
| *(this+0x134) | 0x168 | R | — | Animation state/control field |
| *(this+0x134) | 0x180 | R | — | Animation data referenced field |
| *(this+0x134) | 0x1A8 | RW | — | Current animation time accumulator per entry |
| *(this+0x134) | 0x1B0 | R | — | Threshold counter (compared > 1 per entry, guards InterruptDispatch) |
| *(this+0x134) | 0x1C0 | R | — | Animation duration/target time per entry |
| *(this+0x134) | 0x1C4 | RW | — | Animation timer value updated each frame |
| this | 0x110 | R | — | Pointer to animation controller / animation block |
| this | 0x134 | R | — | Pointer to animation data block containing entries |

**Written-by note (persistence):**
- *(this+0x134) 0x1A8: Updated each frame when timer advances; external poke overwritten by per-frame update
- *(this+0x134) 0x1C4: Updated conditionally per animation entry; external poke overwritten on next update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058957a | InterruptDispatch | Dispatch callback when animation entry timer reaches/exceeds duration |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x134) | 0x164 | > | 0 | Entry count / loop limit — PASS when > 0 (entries to process), BLOCKED when 0 |
| *(this+0x134) | 0x1B0 | > | 1 | Per-entry repeat counter — PASS when > 1 (process animation), BLOCKED when ≤ 1 |

**Guard interpretation:** 
- *(this+0x134)+0x164 ≤ 0: skip entire animation entry loop (no entries to update). PASS when > 0.
- Each entry v5[2] (int cast, offset +8) ≤ 1: skip that entry's timer update. PASS when > 1 (timer update runs), BLOCKED when ≤ 1.
