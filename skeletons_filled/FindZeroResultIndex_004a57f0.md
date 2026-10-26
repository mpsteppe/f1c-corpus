## FindZeroResultIndex_004a57f0 — ValidPartCountFinder

**Summary:** Iterates through valid part indices by calling NthValidPartLookup(i) until it returns 0 (no part at that index). Stores the count (first index returning 0) in `this[42]`. Requires at least one valid part to complete (i > 0 guard prevents premature exit on initial index 0).

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitPartStateCopy (004a5330), UtilityFunction_5750 (004a5750), IndexDecrementWithBoundsWrap (004a57a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA8 | W | — | Stores the count of valid parts found |

**Written-by note (persistence):**
- this 0xA8: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5820 | NthValidPartLookup | Returns part identifier for index i; returns 0 when index exceeds valid part count |

**Guard conditions:** No explicit guard on this fields. The loop exits when NthValidPartLookup returns 0 AND i > 0 (at least one valid part found). If no valid parts at all (first call returns 0), the loop would continue incrementing until i > 0, then exit.