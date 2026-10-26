## sub_591EDF_00591edf — LocalTimeToTimestamp

**Summary:** Converts local date/time components to Unix timestamp with DST adjustment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5896EE (005896ee), sub_59B760 (0059b760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e7758 | dword_5E7758 | R | TimeBias_MinutesBias [DERIVED] |
| 005e775c | dword_5E775C | R | DSTActiveFlag [DERIVED] |
| 005e7760 | dword_5E7760 | R | DSTOffsetSeconds [DERIVED] |
| 005e9b04 | dword_5E9B04 | R | MonthOffsets [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005921c5 | LazyInitSingletonWithFlagGuard | Lazy init timezone singleton data |
| 0059247a | CriticalSectionGuardedCall | Check if DST is active for given date |

**Guard conditions:** If `a1 - 1900 < 70` or `a1 - 1900 > 138` (year out of 1970–2038 range), returns -1 (BLOCKED: year outside valid Unix epoch range).
