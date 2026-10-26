## ColorQuantization_00513f7a — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_515417 (00515417)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e778 | flt_59E778 | R | AngleToRadians [DERIVED] (also: ` — spread scale factor 2) |
| 005ac988 | flt_5AC988 | R | UVCoordScaleFactor [DERIVED] (also: ` — UV coordinate scale factor) |
| 005adb14 | flt_5ADB14 | R | DegreeWrap360 [DERIVED] (also: ` — 360.0 (degree wrap) |
| 005af56c | unk_5AF56C | R | SplineCoeffTable_5AF56C [DERIVED] |
| 005af58c | unk_5AF58C | R | ColorQuantize_Table6 [DERIVED] |
| 005af5ac | unk_5AF5AC | R | ColorTableBase [DERIVED] |
| 005af5c4 | unk_5AF5C4 | R | RemapCoefficientTable [DERIVED] |
| 008b00a0 | dword_8B00A0 | R | FPUControlStore [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00513e5d | FPUControlWordMerger | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
