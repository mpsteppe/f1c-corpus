## BoundsCheckedIndexSetter_6760_004c6760 — Set list index with bounds check

**Summary:** Sets an index field (0x18) in the structure if the provided value is within valid range [0, count-1]. Returns the input value unchanged regardless of whether the set succeeds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RandomVehicleSelector (004c5070), GuardedListAccessor (004c50e0), LinkedListRandomAccess (004c6780)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | Count of items (upper bound for index validation) |
| this | 0x18 | RW | — | Target index field; written only if a2 is in valid range |

**Written-by note (persistence):**
- this 0x18: written only if a2 >= 0 AND a2 < this[5] (count); survives external pokes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Only writes to this[6] when `a2 >= 0` AND `a2 < this[5]` (list count). Otherwise returns a2 without modifying anything.
