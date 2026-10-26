## sub_4BF6A0_004bf6a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

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
| 005d263c | off_5D263C | R | Off_5D263C_Season [DERIVED] |
| 008aae70 | dword_8AAE70 | RW | RingBufferCounter (QA/weather noise) [DERIVED] |
| 008aae74 | flt_8AAE74 | R | TrigLookup256 [DERIVED] (also: ` — 256-entry trig lookup table) |
| 008ad3b4 | dword_8AD3B4 | R | GameDataDir [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00567970 | DataEntryAccessor | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |
| 00568210 | AudioChannelStop | [LLM] |
| 0058850f | sub_58850F | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
