## AIDriverSorting_004bf390 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EngineFailureCheck (004bec55), AIBehaviorInitialization (004bf0a0), AITickUpdate (004bf4f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x403C | R | — | lapNumber [CONFIRMED] |
| this | 0x4060 | R | — | position [CONFIRMED] |
| this | 0x4098 | R | — | totalTimeOnFinishLine [CONFIRMED] |
| this | 0x409C | R | — | bestLap [CONFIRMED] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bc2f0 | ConditionalFieldSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
