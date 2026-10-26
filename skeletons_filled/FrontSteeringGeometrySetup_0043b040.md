## FrontSteeringGeometrySetup_0043b040 — Front steering geometry setup

**Summary:** Sets up front steering geometry for left and right wheels. Searches suspension component arrays for matching pairs, computes steering transforms, finds closest geometry pairs, applies steering angle via tan formula, and updates rotation matrices. Part of vehicle steering initialization.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsInitializer (00439210)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x15C4 | R | — | Number of suspension component elements |
| this | 0x15C8 | R | — | Pointer to suspension component array (stride 72) |
| this | 0x15F0 | R | — | Suspension geometry identifier for matching |

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
| 0043aee0 | TransformApply3D | Applies 3D position/rotation transform between elements |
| 004d7a50 | StringSplitLoop | Formats debug log source file path |
| 004d7aa0 | DebugLogWrite | Writes debug error message to log |
| 00588410 | sub_588410 | Compares component name string for matching |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x15C4 | <= | 0 | Number of suspension component elements |

**Guard interpretation:** If this->componentCount (0x15C4) <= 0, skip steering geometry processing and log "sorry only support" error message.
