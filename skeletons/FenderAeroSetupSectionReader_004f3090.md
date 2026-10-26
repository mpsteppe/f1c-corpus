## FenderAeroSetupSectionReader_004f3090 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** TheSvmHdvVehicleFileParser (004f4270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d52fc | aFenderflareran | R | FenderFlareRangeString [DERIVED] |
| 005d5310 | aFenderflareset | R | FenderFlareSettingString [DERIVED] |
| 005d5324 | aFendersideways | R | FendersidewaysString [DERIVED] |
| 005d5334 | aFenderliftpara | R | FenderLiftParamsStr [DERIVED] |
| 005d5348 | aFenderdragpara | R | FenderDragParamString [DERIVED] |
| 005d535c | aFendercenter | R | FenderCenterField [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042e1f0 | CRTMathHelper_e1f0 | [LLM] |
| 005351d0 | LineInputReader | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565aa0 | sub_565AA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
