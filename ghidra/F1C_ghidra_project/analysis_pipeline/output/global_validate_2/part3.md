# Global Validate Part 3 — Globals 141–210

<!-- target: docs/12-globals-reference.md -->

| DAT_005d4380 | aPitstop | ui | char* | read | 1 | Pitstop UI string, referenced in menu/garage display |
| DAT_005d438c | off_5D438C | ui | code* | read | 1 | Function pointer or vtable offset, read in FUN_004d3cf0 for UI/garage component |
| DAT_005d43c8 | off_5D43C8 | vehicle | code* | read | 1 | VTable pointer assigned in FUN_004d4860 constructor, set to PTR_FUN_005acf08 |
| DAT_005d44d0 | aFl | game_logic | char* | read | 1 | Format/control string "fl", used in FUN_004d4a80 |
| DAT_007c8310 | SessionStartPaused | game_logic | int | write | 1 | State flag written to 0 in FUN_0059dba9 during session start/reset; paired with DAT_007c8314 (0x3fe80000) |
| DAT_005d4810 | aDamper | vehicle | char* | read | 1 | "Damper" parameter string, used in FUN_004d6b00 for suspension setup |
| DAT_005acf28 | DoubleConst_5ACF28 | vehicle | double | read | 1 | Double constant used in FUN_004d6b00 damper/suspension calculations |
| DAT_007cfea0 | InputDisplayMode | input | int | read | 1 | State flag compared to 0/2 in FUN_004d82d0; controls input display overlays (gear/input bar rendering) |
| DAT_005d4b14 | FormatTimeString | ui | char* | read | 1 | Format string "%2d/%2d/%2d" or "%06.3f" for time display in FUN_004d9690 |
| DAT_005d4c04 | Dword_5D4C04 | ui | int | read | 1 | DWORD constant used in FUN_004dd030 text rendering |
| DAT_007cf818 | Dword_7CF818 | renderer | int | read | 1 | DWORD in renderer function FUN_004ddf90 |
| DAT_005d4dd8 | aCouldNotFindIn | game_logic | char* | read | 1 | Error string "CouldNotFindIn..." used in FUN_004dfce0 error path |
| DAT_008ad3f4 | Dword_8AD3F4 | game_logic | int | write | 1 | DWORD written to in FUN_004dfce0 error handling |
| DAT_007c91dc | DoubleCarOrientationThreshold | vehicle | double | read | 1 | Double threshold compared to _DAT_0059e430 in FUN_004e49b0; controls car orientation/quaternion setup branching |
| DAT_008ad42c | VehicleArrayOffset_PitCrew | vehicle | int | read | 1 | Offset into vehicle data array in FUN_004eb430 pit crew AI logic |
| DAT_005ad238 | WeightTransferMultiplier | vehicle | float | read | 1 | Float multiplier (_DAT_005ad238) in FUN_004f12e0; scales weight transfer in team/driver management physics |
| DAT_005d4f98 | aFrontWingMass | vehicle | char* | read | 1 | Vehicle setup parameter string "FrontWingMass", used in FUN_004f24f0 |
| DAT_005d52b8 | aBumpstopRising | vehicle | char* | read | 1 | Vehicle setup parameter string "BumpstopRising", used in FUN_004f2c60 |
| DAT_005d517c | aCamberRange | vehicle | char* | read | 1 | Vehicle setup parameter string "CamberRange", used in FUN_004f2c60 |
| DAT_005d502c | aBrakePadRange | vehicle | char* | read | 1 | Vehicle setup parameter string "BrakePadRange", used in FUN_004f2c60 |
| DAT_005d571c | aFuelEstimate | vehicle | char* | read | 1 | Vehicle setup parameter string "FuelEstimate", used in FUN_004f3c80 |
| DAT_005d5598 | aOptimumOilTemp | vehicle | char* | read | 1 | Vehicle setup parameter string "OptimumOilTemp", used in FUN_004f3c80 |
| DAT_005d66d8 | aInertia | vehicle | char* | read | 1 | Vehicle setup parameter string "Inertia", used in FUN_004f4270 |
| DAT_005d659c | aDriverName_Aitor | vehicle | char* | read | 1 | Driver name string "AitorQuestab" or similar, used in FUN_004f4270 |
| DAT_005d6470 | aPitstop3Range | vehicle | char* | read | 1 | Vehicle setup parameter string "Pitstop3Range", used in FUN_004f4270 |
| DAT_005d6384 | aRWDragParams | vehicle | char* | read | 1 | Vehicle setup parameter string "RWDragParams", used in FUN_004f4270 |
| DAT_005d6298 | aBodyUp | vehicle | char* | read | 1 | Vehicle setup parameter string "BodyUp", used in FUN_004f4270 |
| DAT_005d6168 | aPhysicalModelFlag | vehicle | char* | read | 1 | Vehicle setup parameter string "PhysicalModelF..." (PhysicalModelFlag), used in FUN_004f4270 |
| DAT_005d5fdc | aFront3rdBumpstop | vehicle | char* | read | 1 | Vehicle setup parameter string "Front3rdBumpst...", used in FUN_004f4270 |
| DAT_005d5e20 | aRightFenderFlap | vehicle | char* | read | 1 | Vehicle setup parameter string "RightFenderFla...", used in FUN_004f4270 |
| DAT_005d5c5c | aFront3rdFastrecovery | vehicle | char* | read | 1 | Vehicle setup parameter string "Front3rdFastre...", used in FUN_004f4270 |
| DAT_005d5aa4 | aAbsGrip | vehicle | char* | read | 1 | Vehicle setup parameter string "AbsGrip", used in FUN_004f4270 |
| DAT_005d5968 | aAllowManualOverride | vehicle | char* | read | 1 | Vehicle setup parameter string "AllowManualOver...", used in FUN_004f4270 |
| DAT_005d582c | aReverseSetting | vehicle | char* | read | 1 | Vehicle setup parameter string "ReverseSetting", used in FUN_004f4270 |
| DAT_005d58cc | aGear9Setting | vehicle | char* | read | 1 | Vehicle setup parameter string "Gear9Setting", used in FUN_004f4270 |
| DAT_005d6ca4 | aPlayerEngineVolume | audio | char* | read | 1 | Audio parameter string "PlayerEngineVol..." used in FUN_004f7460 engine sound setup |
| DAT_005d6b17 | UnnamedString_5D6B17 | audio | char* | read | 1 | Unnamed string (empty IDA name) used in FUN_004f7460 audio/engine setup |
| DAT_005d6983 | UnnamedString_5D6983 | audio | char* | read | 1 | Unnamed string (empty IDA name) used in FUN_004f7460 audio/engine setup |
| DAT_007cf314 | SuspensionDampingMultiplier | vehicle | float | read | 1 | Float multiplier _DAT_007cf314 used in FUN_004f8440; scales suspension damping force (param_1[399] *= _DAT_007cf314 * local_24) |
| DAT_008afeb0 | VehicleDataOffset_8AFEB0 | vehicle | int | read | 1 | DWORD offset into vehicle data, used in FUN_004f9480 |
| DAT_005d6e50 | FlagByte_5D6E50 | game_logic | byte | read | 1 | Byte flag read in FUN_004fa000 |
| DAT_005d6f10 | aCloudRainy | weather | char* | read | 1 | Weather string "Cloud/Rainy" or "Cloudrny", used in FUN_004fba10 weather display |
| DAT_005ad2a0 | FloatConst_5AD2A0 | physics | float | read | 1 | Float constant used in physics function FUN_004fcee0 |
| DAT_005ad314 | TractionControlMultiplier | vehicle | float | read | 1 | Float multiplier _DAT_005ad314 in FUN_004fdeb0; scales stability/traction control decay (fVar3 * _DAT_005ad314 + ...) |
| DAT_005c6eb8 | aMedium | ui | char* | read | 1 | UI string "Medium", used in FUN_004fe2b0 for difficulty/skill level display |
| DAT_005d7088 | aTrackTempFormat | weather | char* | read | 1 | Format string "TrackTemp%d.%d" or "TrackTemp%2f", used in FUN_004fe820 weather display |
| DAT_005ad4e0 | LookupTableEndMarker | game_logic | int* | read | 1 | End marker for lookup table at 0x005ad508; returned by FUN_00500680 when key not found in table (sentinel value) |
| DAT_005ba5e0 | ComInterfaceTable | com | byte[] | read | 1 | Struct/table used in COM interface function FUN_00506003; contains vtable/data for COM interaction |
| DAT_005adc18 | VTablePtr_CoClassA | com | code* | read | 1 | VTable pointer assigned to *param_1 in FUN_0050ab19 COM constructor; set to PTR_FUN_005adc18 |
| DAT_005add2c | VTablePtr_CoClassB | com | code* | read | 1 | VTable pointer assigned to *param_1 in FUN_0050b3b5 COM constructor; set to PTR_FUN_005add2c |
| DAT_005ade3c | EpsilonFloat | math | float | read | 1 | Float threshold _DAT_005ade3c in FUN_0050c042; compared against param_1-param_2 difference for approximate equality test |
| DAT_005d786c | Ptr_FUN_5D786C | game_logic | code* | read | 1 | Function pointer (indirect call target) called via (*(code *)PTR_FUN_005d786c)(...) in FUN_0050d97e; dispatches to parameterized handler |
| DAT_005af2d8 | a113 | game_logic | char* | read | 1 | String "113" or similar identifier, used in FUN_005118e6 |
| DAT_005af438 | AudioCompressionDouble | audio | double | read | 1 | Double constant used in FUN_00513482 audio compression/encoding (sample rate or bitrate constant) |
| DAT_005d79c0 | Audio3DPositionFloat | audio | float | read | 1 | Float constant used in FUN_005147ea 3D audio position calculation |
| DAT_005afb2c | aIgnoringBadAddress | game_logic | char* | read | 1 | Error/debug string "IgnoringBadAddress", used in FUN_00518511 |
| DAT_005afda8 | aInvalidGammaAfter | game_logic | char* | read | 1 | Error/debug string "InvalidGammaAfter", used in FUN_00518c1e |
| DAT_005afb10 | aIdat | game_logic | char* | read | 1 | Debug string "Idat", used in FUN_00519019 |
| DAT_005d8a20 | Xmmword_CrossProductSignFlip | math | __m128 | read | 1 | SIMD XOR mask (xmmword_5D8A20) used in sub_51F0BE cross product; applied via _mm_xor_ps to flip sign of cross product result |
| DAT_005d8b60 | Xmmword_NormalizeCoeffC | math | __m128 | read | 1 | SIMD polynomial coefficient (xmmword_5D8B60) used in sub_51FB1E vector normalization; added as constant term in SSE polynomial evaluation for rsqrt approximation |
| DAT_008d6188 | Dword_NewtonRaphsonConstant | math | int | read | 1 | Newton-Raphson constant for fast inverse sqrt (dword_8D6188) in sub_52035E; part of (float)(dword_8D6184 * v6) * (float)(dword_8D6188 - (v5 * v6) * v6) |
| DAT_005d8c60 | Xmmword_SignNegation | math | __m128 | read | 1 | SIMD XOR mask (xmmword_5D8C60) in sub_520A7E; applied via _mm_xor_ps to negate sign of quaternion/vector components |
| DAT_008d62b0 | Xmmword_QuaternionMultiply | math | __m128 | read | 1 | SIMD multiply constant (xmmword_8D62B0) in sub_520E0E; used with _mm_mul_ps in quaternion multiplication setup |
| DAT_005d8fc0 | Xmmword_3DNowMatrixMask | math | __m128 | read | 1 | SIMD/x86 constant (xmmword_5D8FC0) used in FUN_005289e0 3DNow matrix multiply; accessed both as float __m128 and uint bitmask via PTR_DAT_005d8fc0 |
| DAT_005d9080 | Xmmword_5D9080 | math | __m128 | read | 1 | SIMD constant (xmmword_5D9080) referenced by FUN_00528bd0 or used elsewhere; part of 3DNow SSE constant pool |
| DAT_005d93ac | Dword_3DNowPolyConstant | math | int | read | 1 | DWORD constant (dword_5D93AC) in FUN_00529000; used as packed floating polynomial constant via PackedFloatingADD in MMX/3DNow rsqrt approximation |
| DAT_005b0b38 | aOversubscribed | game_logic | char* | read | 1 | Error string "Oversubscribed" used in FUN_0052a4a5 |
| DAT_005b0b98 | Qword_CompressionTable | audio | ulonglong | read | 1 | QWORD entry in compression/encoding table (qword_5B0B98) used in FUN_0052ab4e Huffman-like encoding |
| DAT_005b4764 | Dword_EncodingConstant | audio | int | read | 1 | DWORD constant (dword_5B4764) used in encoding function FUN_0052da30 |
| DAT_005b6620 | Word_HuffmanTable | audio | ushort | read | 1 | WORD entry in encoding/Huffman table (word_5B6620) used in FUN_00531250 compression/decompression |
