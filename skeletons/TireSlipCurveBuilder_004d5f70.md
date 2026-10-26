## TireSlipCurveBuilder_004d5f70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TireBrandFileParser (004d7150)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | [LLM] |
| *(this+0x14) | 0x8 | R | — | [LLM] |
| *(this+0x14) | 0x10 | R | — | [LLM] |
| *(this+0x14) | 0x18 | R | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 0059e7e0 | dbl_59E7E0 | R | LookupThreshold_14 [DERIVED] |
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |
| 0059ec10 | dbl_59EC10 | R | DoublePhysicsZero [DERIVED] |
| 005d45e4 | aDDevF119992002_4 | R | SourcePath_F1_1999_2002_4 [DERIVED] |
| 005d4610 | aFirstDataPoint | R | FirstDataPointString [DERIVED] |
| 005d4648 | aNeedAtLeastDDa | R | Str_NeedAtLeastDDa [DERIVED] |
| 005d4684 | aTireSlipCurveS | R | StringTireSlipCurveS [DERIVED] |
| 005d46bc | aSkippingUnexpe | R | SkippingUnexpectedString [DERIVED] |
| 005d46f8 | off_5D46F8 | R | VTable_5D46F8 [DERIVED] |
| 005d46fc | unk_5D46FC | R | UnknownPtr_5D46FC [DERIVED] |
| 005d4700 | aData | R | [LLM] |
| 005d4708 | aStep | R | StepStr [DERIVED] |
| 005d4710 | aName | R | Str_Name [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 005654a0 | sub_5654A0 | [LLM] |
| 00565aa0 | sub_565AA0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 005677b0 | sub_5677B0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 005887ed | StrlenFormatCallWrapper | [LLM] |
| 005897ca | sub_5897CA | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x10 | <= | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
