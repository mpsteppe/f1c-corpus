## Accumulator_004c2be0 — FieldAccumulator

**Summary:** Adds the input value a2 to a running total stored at this+0x24. Returns the input value unchanged. Used to accumulate laps, points, or other session counters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonScoringInfoUpdater (004c2a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24 | RW | — | running total accumulator field, incremented by a2 each call |

**Written-by note (persistence):**
- this 0x24: incremented unconditionally each call — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard — always adds a2 to this[9] unconditionally.
