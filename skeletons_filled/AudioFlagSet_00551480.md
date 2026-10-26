## AudioFlagSet_00551480 — AudioTimerFlagSet

**Summary:** Sets flag bit 0x1000 and clears bits 0x7000 on the entity flags, then returns the accumulated QPC timer value.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TimerBasedStateUpdateWithCap (005514c0), LinkedListStringKeyRemoval (00551790), SceneNode (0055a910)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | QueryPerformanceCounter handle (for timer accumulation) |
| this | 0x4 | RW | — | Flags — set bit 0x1000, clear bits 0x7000 (audio timer state) |

**Written-by note (persistence):**
- this 0x4: Written with mask+set; external poke partially survives (only bits 0x7000 cleared)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** none — always executes unconditionally.
