## CMpegBase_Open_0052e090 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x248C | R | — | [LLM] |
| this | 0x24A0 | RW | — | [LLM] |
| this | 0x24A4 | RW | 0 | [LLM] |
| this | 0x24B0 | RW | — | [LLM] |
| this | 0x24D4 | R | — | [LLM] |
| this | 0x24D8 | R | — | [LLM] |
| this | 0x24DC | R | — | [LLM] |
| this | 0x24E0 | R | — | [LLM] |
| this | 0x24EC | RW | 1 | [LLM] |
| this | 0x24F0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x24A0: [LLM: once/conditional? does external poke survive?]
- this 0x24A4: [LLM: once/conditional? does external poke survive?]
- this 0x24B0: [LLM: once/conditional? does external poke survive?]
- this 0x24EC: [LLM: once/conditional? does external poke survive?]
- this 0x24F0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005da564 | aSDS_0 | R | sSDS_Format [DERIVED] |
| 005da574 | aDDevAudiodevSh | R | AudioDevicePath [DERIVED] |
| 005da5e0 | aAudioAssert | R | StrAudioAssert [DERIVED] |
| 005da674 | aCmpegbaseOpenG | R | CmpegBaseOpenGLString [DERIVED] |
| 005da714 | off_5DA714 | R | AssertHaltFuncPtr [DERIVED] |
| 005da718 | off_5DA718 | R | FileStreamVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052da10 | sub_52DA10 | [LLM] |
| 0052de40 | ArithmeticComparison_de40 | [LLM] |
| 0052de60 | AudioNetworkBufferTimingCalc | [LLM] |
| 0052e080 | F_64BitIntegerDivision | [LLM] |
| 0052e2f0 | LapPerformanceStateReset | [LLM] |
| 0052e320 | DeferredDeactivation | [LLM] |
| 0052e4e0 | sub_52E4E0 | [LLM] |
| 0052e520 | HaltAssertHandler | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
