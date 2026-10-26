## FrontSteeringGeometrySetup_0043b040 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15C4 | R | — | [LLM] |
| this | 0x15C8 | R | — | [LLM] |
| this | 0x15F0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 005c41bc | aFrSteering | R | ParamName_FrSteering [DERIVED] |
| 005c41c8 | aFlSteering | R | StrFLSteering [DERIVED] |
| 005c421c | aDDevF119992002 | R | SourcePathPrefix [DERIVED] |
| 005c4270 | aSorryOnlySuppo | R | String_SorryOnlySupport [DERIVED] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0043aee0 | TransformApply3D | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15C4 | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
