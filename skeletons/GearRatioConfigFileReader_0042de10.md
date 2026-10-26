## GearRatioConfigFileReader_0042de10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ReplayStateCopy (0042ecc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0042dc20 | byte_42DC20 | R | [LLM] |
| 005c36c0 | aBevel | R | GraphicsParam_Bevel [DERIVED] |
| 005c36c8 | aFinalDrive | R | String_FinalDrive [DERIVED] |
| 005c36d8 | aRatio | R | RatioString [DERIVED] |
| 005c36e0 | aGearRatios | R | GearRatiosString [DERIVED] |
| 005c36f0 | aR | R | Token_R [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042ddd0 | ScoreSlotDeallocator | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565760 | sub_565760 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ca0 | FileReadUntilNewline | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587f64 | sub_587F64 | [LLM] |
| 005890aa | sub_5890AA | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
