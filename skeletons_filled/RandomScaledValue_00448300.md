## RandomScaledValue_00448300 — IndexedTrigScaledValue

**Summary:** Generates a pseudo-random scaled value by indexing a 256-entry trig lookup table with an incrementing ring-buffer counter, multiplying the result by a stored scale factor at this+0x8. Called from Steward_Restart as part of audio/weather noise seeding.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Steward_Restart (004d3cf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | scale factor multiplier |
| this | 0x14 | RW | — | output: scaled trig value (result storage) |

**Written-by note (persistence):**
- this 0x14: overwritten every call with scaled trig value; external poke survives only until next call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No guard. Always executes: reads trig table at counter index, increments counter, writes scaled product to this+0x14.
