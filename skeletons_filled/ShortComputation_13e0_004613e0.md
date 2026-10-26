## ShortComputation_13e0_004613e0 — CollisionBroadcastLoop

**Summary:** Iterates over driver entries broadcasting collision events to network when flag bit test passes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkUIUpdate (00462848)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3C74 | R | — | Array count (number of active entries to iterate) |
| this | 0x3E14 | R | — | Derived field used for stride/index computation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461530 | FlagBitTest | Test flag bit at offset 2 on entry structure |
| 00462940 | CollisionEventNetworkBroadcast | Broadcast collision event over network for entry |

**Guard conditions:** Loop body skipped when FlagBitTest(2) returns non-zero (bit set means skip broadcast).
