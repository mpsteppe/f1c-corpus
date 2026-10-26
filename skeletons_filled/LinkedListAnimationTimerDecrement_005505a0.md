## LinkedListAnimationTimerDecrement_005505a0 — AnimationTrackValueDecrement

**Summary:** Walks linked list of animation nodes, decrementing track values by the entry's step value for tracks referencing a specific animation data entry, gated by entry type and timer threshold.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioDSPStateUpdate (00448330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x204 | R | — | Animation node linked list head |
| this | 0x224 | R | — | Animation system field |
| this | 0x32C | R | — | Animation system field |
| this | 0x330 | R | — | Animation system field |
| this | 0x364 | RW | — | Animation system field (written indirectly through track updates) |

**Written-by note (persistence):**
- this 0x364: Updated indirectly when animation node track values are decremented; external poke may be overwritten on next update cycle

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** 
- a2 == 0: skip entire function (no animation data reference). PASS when non-null.
- a3 > *(a2 + 164): entry index out of bounds. PASS when ≤ bound.
- *(v3 + 72) ≤ 1: entry type is terminal/single-frame (v4[18] ≤ 1). PASS when > 1.
- i[70] == 0: node has no tracks to process. PASS when non-zero.
- *(v5 - 12) != a2: track does not reference this animation data. PASS when equal (decrement runs).
- *v5 < *(v3 + 80): track value below step threshold — skip decrement. PASS when ≥ (decrement runs).
