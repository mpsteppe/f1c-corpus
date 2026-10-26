## MaterialShaderReactionEffectParser_004ca480 — ReactionEffectConfigParser

**Summary:** Parses a reaction effect configuration block from a data stream, determining the effect type (dust, smoke, flames, skid, spray, etc.) and associated material shader properties including texture paths, vertex/pixel shader flags, blend modes, chromakey, and particle settings. Builds a renderer sub-object with all parsed parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SpecialFX_Init (004cf070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x50) | 0x20 | RW | 0 | sub-object particle flags bitmask (plane, cross, mtsfile, stamps, billboards, deformable, singlesided, alphafade) |
| *(this+0x50) | 0x38 | RW | 0 | sub-object MTS filename buffer (56 bytes, .MTS appended if no extension) |
| *(this+0x50) | 0x58 | RW | 0 | sub-object vertex shader flags bitmask (noshade=4, flatshade=8, gouraud=16, alphachannel=32, specular=64, envirmap=128, globalshadow=16384) |
| *(this+0x50) | 0x5C | RW | 0 | sub-object pixel shader flags (noreducedetail=1, chromakey=128) |
| *(this+0x50) | 0x60 | RW | 18446744071578845183 | sub-object color value (ARGB, init 0x80FF00FF: alpha=128, red=255, blue=255, green=0) |
| *(this+0x50) | 0x64 | RW | 0 | sub-object blend mode low word (srcblend assigned to lower 16 bits via OR) |
| *(this+0x50) | 0x66 | RW | 0 | sub-object blend mode high byte (destblend shifted into upper bits of +0x64) |
| *(this+0x50) | 0x68 | RW | — | sub-object chromakey color value (parsed from hex string) |
| *(this+0x50) | 0x70 | RW | 0 | sub-object texture/BMP filename buffer (112 bytes, .BMP appended if no extension) |
| *(this+0x50) | 0x90 | RW | 0 | sub-object environment map filename buffer (144 bytes, .BMP appended) |
| this | 0x4 | RW | 13 | effect type ID (0=dust,1=whitesmoke,2=bluesmoke,3=blacksmoke,4=flames,5=spray,6=skid,7=softskid,8=wetskid,9=groove,10=wetgroove,11=particle,12=spark,13=rain default) |
| this | 0x30 | RW | — | duration float value (parsed from config) |
| this | 0x34 | RW | — | ASD envelope attack value (float) |
| this | 0x38 | RW | — | ASD envelope sustain value (float) |
| this | 0x3C | RW | — | ASD envelope decay value (float) |
| this | 0x48 | RW | — | ramp speed value (float, clamped to [1.0, FLT_MAX]) |
| this | 0x50 | RW | 0 | pointer to allocated sub-object (176-byte renderer material struct) |
| this | 0x58 | RW | — | waypoints count / computed numeric value (from Numwaypoints or parsed string-to-int) |

**Written-by note (persistence):**
- *(this+0x50) 0x20: once per init; set from particle token parsing; survives until sub-object freed
- *(this+0x50) 0x38: conditional; set when MTS_0 token found; survives until sub-object freed
- *(this+0x50) 0x58: conditional; set when Vertex token found (bitmask ORs); survives
- *(this+0x50) 0x5C: conditional; set when Pixel token found; survives
- *(this+0x50) 0x60: once per init (set to default 0x80FF00FF); overwritten by Color token hex parsing; survives
- *(this+0x50) 0x64: conditional; overwritten by Srcblend/Destblend token parsing; survives
- *(this+0x50) 0x66: once per init (zeroed); survives
- *(this+0x50) 0x68: conditional; set when Chroma token found; survives
- *(this+0x50) 0x70: conditional; set when Mts_0 token found; survives
- *(this+0x50) 0x90: conditional; set when Emap token found; survives
- this 0x4: once per init; set from Reaction token string comparison; persists across calls (mutable state)
- this 0x30: conditional; set when Duration token parsed; survives
- this 0x34: conditional; set when AsdEnvelope token parsed; survives
- this 0x38: conditional; set when AsdEnvelope token parsed; survives
- this 0x3C: conditional; set when AsdEnvelope token parsed; survives
- this 0x48: conditional; set when Rampspeed token parsed (with clamp); survives
- this 0x50: once per init; allocated by OperatorNewNhMallocWrapper; old value freed first; survives across calls until next parse
- this 0x58: conditional; set when Numwaypoints/value token parsed; survives

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
| 004b0170 | EmptyStub_0170 | no-op stub (possibly debug hook) |
| 004ca430 | FloatStructInitializer | zero-initializes the effect struct fields |
| 004cad30 | HexStringParser | parses hex color string (e.g. "FF8000FF") into 32-bit ARGB value |
| 004cada0 | sub_4CADA0 | parses blend mode string (srcblend/destblend) into numeric blend constant |
| 004d7a50 | StringSplitLoop | splits source path string for error reporting |
| 004d7aa0 | DebugLogWrite | writes "Unrecognized Reaction" message to debug buffer |
| 004f9230 | PathDispatch | gets current race phase timer value (used for Spray scaling decision) |
| 00557350 | sub_557350 | initializes the allocated sub-object (176-byte material struct) |
| 00565520 | sub_565520 | reads token value from config stream into buffer |
| 00565870 | sub_565870 | parses float values from config stream (up to 4 floats) |
| 00566810 | sub_566810 | string contains/substring check against given keyword |
| 00587bcf | FreeWrapper_7bcf | frees previously allocated memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocates 176 bytes for sub-object |
| 00587c20 | sub_587C20 | checks if string contains a path separator (extension check) |
| 00587ece | sub_587ECE | string-to-integer conversion for numeric config values |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4 | == | 5 | effect type ID check — when type is 5 (Spray), ASD envelope values are conditionally scaled down by 0.3x |

**Guard interpretation:** The check `*(_DWORD *)(this + 4) == 5` tests whether the parsed effect type is "Spray" (type ID 5). When this condition PASSES (type == 5) AND `PathDispatch(&unk_8AFE18) < 24` (race phase timer less than 24), the three ASD envelope values (attack, sustain, decay) are each multiplied by 0.3 to reduce the spray effect intensity during early race phases. When BLOCKED (type != 5), the envelope values are used as-is with no scaling.
