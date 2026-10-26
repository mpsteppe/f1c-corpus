## sub_4BF6A0_004bf6a0 — Season audio parameter lookup

**Summary:** Looks up a season-specific audio parameter (volume/pitch) by audio channel key string. Computes a float value from season data entry with randomized noise, returns 1.0 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AIOpponentSelection (004bf790), AIPathPerformanceFunction (004bfa00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 005acdbc | flt_5ACDBC | R | UnknownRenderFloat_5ACDBC [DERIVED] |
| 005d263c | off_5D263C | R | season data linked list head |
| 008aae70 | dword_8AAE70 | RW | ring buffer counter for noise table index |
| 008aae74 | flt_8AAE74 | R | 256-entry trig/noise lookup table |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567970 | DataEntryAccessor | access data entry structure from linked list node |
| 005679c0 | StringKeyedLinkedListSearch | find linked list node matching string key a1 |
| 00568210 | AudioChannelStop | check if audio channel matching a1 is active/playing |
| 0058850f | sub_58850F | read season scoring parameter from data entry |

**Guard conditions:** Returns 1.0 if a1 is NULL or empty string. Returns 1.0 if AudioChannelStop(a1) returns false (channel not active). Returns 1.0 if StringKeyedLinkedListSearch returns 0 (key not found in season data list).
