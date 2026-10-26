## StartAddress_00583d90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC | R | — | [LLM] |
| obj | 0x50 | R | — | [LLM] |
| obj | 0x54 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059d063 | SEH_583D90 | R | [LLM] |
| 0059e208 | SleepEx | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059ed98 | dbl_59ED98 | R | Dbl_Physics_TimingThreshold [DERIVED] |
| 005b8b58 | flt_5B8B58 | R | AudioBufferThreshold [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 005835f0 | TimerInitWithSEH | [LLM] |
| 00583650 | SingleFunctionCallWrapper_3650 | [LLM] |
| 00583660 | FloatSetWithTimingCall | [LLM] |
| 00583680 | FloatAdditionReturnsFUN00568d90Param1 | [LLM] |
| 00583690 | SingleFunctionCallWrapper_3690 | [LLM] |
| 00583d40 | MutexProtectedDataReadWithTimedWait | [LLM] |
| 00583f50 | sub_583F50 | [LLM] |
| 005840d0 | MutexWaitWith1msTimeoutRelease | [LLM] |
| 00584110 | sub_584110 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
