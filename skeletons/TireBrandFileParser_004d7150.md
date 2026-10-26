## TireBrandFileParser_004d7150 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TireBrandLoader (004d7660)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6810 | aCouldNotOpenS | R | Str_CouldNotOpenS [DERIVED] |
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d4880 | aBadSyntaxInFil_1 | R | BadSyntaxInFileString [DERIVED] |
| 005d48a8 | aBadSyntaxInFil_0 | R | BadSyntaxInFileString [DERIVED] |
| 005d48e0 | aBadSyntaxInFil | R | BadSyntaxString [DERIVED] |
| 005d491c | aNoCompoundsFou | R | NoCompoundsFoundStr [DERIVED] |
| 005d4938 | aCompound | R | CompoundString [DERIVED] |
| 005d4944 | aSlipcurve | R | SlipCurveField [DERIVED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d5f70 | TireSlipCurveBuilder | [LLM] |
| 004d68a0 | PhysicsStateStructureInitializer | [LLM] |
| 004d6b00 | sub_4D6B00 | [LLM] |
| 004d7050 | ArrayBlockCleanup | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 00566d30 | ConditionalAllocInitDispatch | [LLM] |
| 00568a60 | UtilityFunction_8a60 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
