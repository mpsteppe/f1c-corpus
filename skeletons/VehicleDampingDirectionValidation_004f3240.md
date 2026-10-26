## VehicleDampingDirectionValidation_004f3240 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004f3474 | jpt_4F327C | R | [LLM] |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 005d536c | aZForceAppliedW_0 | R | ZForceAppliedWField [DERIVED] |
| 005d539c | aZForceAppliedW | R | ZForceAppliedString [DERIVED] |
| 005d53cc | aYForceAppliedW_0 | R | YForceAppliedWString [DERIVED] |
| 005d53fc | aYForceAppliedW | R | YForceAppliedWString [DERIVED] |
| 005d542c | aXForceAppliedW_0 | R | Str_XForceAppliedW [DERIVED] |
| 005d545c | aXForceAppliedW | R | StringXForceAppliedW [DERIVED] |
| 005d548c | aDDevF119992002_7 | R | DefaultScenePath7 [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00565aa0 | sub_565AA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
