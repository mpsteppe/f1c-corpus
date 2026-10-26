## sub_591EDF_00591edf — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 005921c5 | LazyInitSingletonWithFlagGuard | [LLM] |
| 0059247a | CriticalSectionGuardedCall | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
