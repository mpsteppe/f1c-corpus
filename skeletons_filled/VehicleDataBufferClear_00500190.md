## VehicleDataBufferClear_00500190 — VehicleDataBufferClear

**Summary:** Clears a collision/vehicle data buffer region (0x1B0 bytes at offset 0x1B8) and sets a sentinel at offset 0x1BC to -FLT_MAX. Called during list iteration reset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatComparisonListIteration (004b5380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1BC | RW | — | Sentinel value after buffer clear (set to -FLT_MAX) |

**Written-by note (persistence):**
- this 0x1BC: Written once per call to -FLT_MAX sentinel; survives until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad348 | flt_5AD348 | R | SetupDefaultSentinel [DERIVED] (also: ` — default value) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None. Always clears buffer and sets sentinel unconditionally.
