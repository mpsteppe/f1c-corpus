## QueuePeek_004b87a0 — QueuePeekTwoValues

**Summary:** Copies two values from this+0xF30 and this+0xF34 to output pointers without modifying the source. Non-destructive queue/position peek.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LoadVehicleEntries (004b70b0), sub_4B9A10 (004b9a10), RangeWidthGetter (004b9c80), PitServiceSteeringAnimationStep (004b9e40), sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF30 | R | — | first queued value (lower bound or parameter) |
| this | 0xF34 | R | — | second queued value (upper bound or parameter) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always copies both values and returns 1.
