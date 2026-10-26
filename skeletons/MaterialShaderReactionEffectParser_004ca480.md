## MaterialShaderReactionEffectParser_004ca480 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x20 | RW | 0 | [LLM] |
| *(this+0x50) | 0x38 | RW | 0 | [LLM] |
| *(this+0x50) | 0x58 | RW | 0 | [LLM] |
| *(this+0x50) | 0x5C | RW | 0 | [LLM] |
| *(this+0x50) | 0x60 | RW | 18446744071578845183 | [LLM] |
| *(this+0x50) | 0x64 | RW | 0 | [LLM] |
| *(this+0x50) | 0x66 | RW | 0 | [LLM] |
| *(this+0x50) | 0x68 | RW | — | [LLM] |
| *(this+0x50) | 0x70 | RW | 0 | [LLM] |
| *(this+0x50) | 0x90 | RW | 0 | [LLM] |
| this | 0x4 | RW | 13 | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |
| this | 0x58 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x50) 0x20: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x38: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x58: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x5C: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x60: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x64: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x66: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x68: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x70: [LLM: once/conditional? does external poke survive?]
- *(this+0x50) 0x90: [LLM: once/conditional? does external poke survive?]
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x58: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e8b4 | flt_59E8B4 | R | ClampUpperThreshold [DERIVED] |
| 0059eae0 | flt_59EAE0 | R | FLT_MAX_Infinity [DERIVED] (also: ` — infinity/FLT_MAX return value) |
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005c57f4 | aColor | R | StrColor [DERIVED] |
| 005c67a8 | off_5C67A8 | R | VTable_Renderer_67A8 [DERIVED] |
| 005cc79c | dword_5CC79C | R | HashTableHead [DERIVED] |
| 005cc7a0 | byte_5CC7A0 | R | FileExtSCNByte [DERIVED] |
| 005cd5ec | aMts | R | aMts [DERIVED] |
| 005cd5f0 | byte_5CD5F0 | R | Unknown_VehicleSetup_Value [DERIVED] |
| 005d3498 | aSrcblend | R | SrcBlendField [DERIVED] |
| 005d34a4 | aDestblend | R | DestBlendKeyword [DERIVED] |
| 005d34b0 | aAlphafade | R | String_AlphaFade [DERIVED] |
| 005d34bc | aSinglesided | R | SingleSidedString [DERIVED] |
| 005d34c8 | aDeformable | R | DeformableString [DERIVED] |
| 005d34d4 | aBillboards | R | BillboardsString [DERIVED] |
| 005d34e0 | aStamps | R | String_Stamps [DERIVED] |
| 005d34e8 | aMtsfile | R | MTSFileString [DERIVED] |
| 005d34f0 | aCross | R | Cross [DERIVED] |
| 005d34f8 | off_5D34F8 | R | Off_5D34F8 [DERIVED] |
| 005d34fc | aPlane | R | PlaneString [DERIVED] |
| 005d3504 | aChroma | R | ChromaString [DERIVED] |
| 005d350c | aChromakey | R | ChromakeyString [DERIVED] |
| 005d3518 | aNoreducedetail | R | Str_NoReduceDetail [DERIVED] |
| 005d3528 | aPixel | R | StringPixel [DERIVED] |
| 005d3530 | aGlobalshadow | R | GlobalshadowString [DERIVED] |
| 005d3540 | aEnvirmap | R | EnvirMapString [DERIVED] |
| 005d354c | aSpecular | R | SpecularString [DERIVED] |
| 005d3558 | aAlphachannel | R | AlphaChannelStr [DERIVED] |
| 005d3568 | aGouraudshade | R | GouraudShadeString [DERIVED] |
| 005d3578 | aFlatshade | R | FlatShadeField [DERIVED] |
| 005d3584 | aNoshade | R | NoShadeKeyword [DERIVED] |
| 005d358c | aVertex | R | String_Vertex [DERIVED] |
| 005d3594 | aEmap | R | EmapString [DERIVED] |
| 005d359c | aMts_0 | R | StringMts_0 [DERIVED] |
| 005d35a0 | off_5D35A0 | R | off_5D35A0 [DERIVED] |
| 005d35a4 | aNumwaypoints | R | NumWaypointsString [DERIVED] |
| 005d35b4 | aOffsetvel | R | String_OffsetVel [DERIVED] |
| 005d35c0 | aRampspeed | R | RampSpeedString [DERIVED] |
| 005d35cc | aPower | R | Power [DERIVED] |
| 005d35d4 | aAsdenvelope | R | AsdEnvelopeField [DERIVED] |
| 005d35e0 | aDuration | R | DurationString [DERIVED] |
| 005d35ec | aGrowthvel | R | GrowthvelString [DERIVED] |
| 005d35f8 | aGrowth | R | GrowthString [DERIVED] |
| 005d3600 | aScale | R | Str_Scale [DERIVED] |
| 005d3608 | aUnrecognizedRe | R | StringUnrecognizedRe [DERIVED] |
| 005d3624 | aDDevF119992002_25 | R | SourcePath_25 [DERIVED] |
| 005d3650 | aRain | R | RainString [DERIVED] |
| 005d3658 | aSpark | R | SparkString [DERIVED] |
| 005d3660 | aParticle | R | ParticleString [DERIVED] |
| 005d366c | aWetgroove | R | WetGrooveStr [DERIVED] |
| 005d3678 | aGroove | R | GrooveString [DERIVED] |
| 005d3680 | aWetskid | R | WetSkidField [DERIVED] |
| 005d3688 | aSpray | R | SprayKeyword [DERIVED] |
| 005d3690 | aSoftskid | R | String_SoftSkid [DERIVED] |
| 005d369c | aSkid | R | SkidString [DERIVED] |
| 005d36a4 | aFlames | R | FlamesString [DERIVED] |
| 005d36ac | aBlacksmoke | R | BlackSmokeString [DERIVED] |
| 005d36b8 | aBluesmoke | R | String_BlueSmoke [DERIVED] |
| 005d36c4 | aWhitesmoke | R | WhiteSmokeString [DERIVED] |
| 005d36d0 | aDust | R | Dust [DERIVED] |
| 005d36d8 | aReaction | R | String_Reaction [DERIVED] |
| 005ea3f0 | dword_5EA3F0 | R | RaycastMaxIterMult [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004ca430 | FloatStructInitializer | [LLM] |
| 004cad30 | HexStringParser | [LLM] |
| 004cada0 | sub_4CADA0 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9230 | PathDispatch | [LLM] |
| 00557350 | sub_557350 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00565870 | sub_565870 | [LLM] |
| 00566810 | sub_566810 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ece | sub_587ECE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 5 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
