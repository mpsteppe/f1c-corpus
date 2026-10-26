## CMpegBase_ProcessHeader_0052da30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MediaFileDecodeHeader (0052dc90), BitstreamDecoder_dd50 (0052dd50), NetworkPacketSend (0052ddc0), NetworkColorIsDefault (0052de00), ArithmeticComparison_de40 (0052de40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2484 | RW | — | [LLM] |
| this | 0x2488 | RW | — | [LLM] |
| this | 0x2490 | RW | — | [LLM] |
| this | 0x2494 | RW | — | [LLM] |
| this | 0x2498 | RW | — | [LLM] |
| this | 0x24BD | RW | 1 | [LLM] |
| this | 0x24BE | RW | 1 | [LLM] |
| this | 0x24BF | RW | — | [LLM] |
| this | 0x24C1 | RW | — | [LLM] |
| this | 0x24C2 | RW | — | [LLM] |
| this | 0x24C3 | RW | — | [LLM] |
| this | 0x24C4 | RW | — | [LLM] |
| this | 0x24C5 | RW | — | [LLM] |
| this | 0x24C6 | RW | — | [LLM] |
| this | 0x24C7 | RW | — | [LLM] |
| this | 0x24C8 | RW | — | [LLM] |
| this | 0x24C9 | RW | — | [LLM] |
| this | 0x24CC | RW | — | [LLM] |
| this | 0x24D0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x2484: [LLM: once/conditional? does external poke survive?]
- this 0x2488: [LLM: once/conditional? does external poke survive?]
- this 0x2490: [LLM: once/conditional? does external poke survive?]
- this 0x2494: [LLM: once/conditional? does external poke survive?]
- this 0x2498: [LLM: once/conditional? does external poke survive?]
- this 0x24BD: [LLM: once/conditional? does external poke survive?]
- this 0x24BE: [LLM: once/conditional? does external poke survive?]
- this 0x24BF: [LLM: once/conditional? does external poke survive?]
- this 0x24C1: [LLM: once/conditional? does external poke survive?]
- this 0x24C2: [LLM: once/conditional? does external poke survive?]
- this 0x24C3: [LLM: once/conditional? does external poke survive?]
- this 0x24C4: [LLM: once/conditional? does external poke survive?]
- this 0x24C5: [LLM: once/conditional? does external poke survive?]
- this 0x24C6: [LLM: once/conditional? does external poke survive?]
- this 0x24C7: [LLM: once/conditional? does external poke survive?]
- this 0x24C8: [LLM: once/conditional? does external poke survive?]
- this 0x24C9: [LLM: once/conditional? does external poke survive?]
- this 0x24CC: [LLM: once/conditional? does external poke survive?]
- this 0x24D0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b4684 | word_5B4684 | R | Unknown_Word_5B4684 [DERIVED] |
| 005b4764 | dword_5B4764 | R | Dword_EncodingConstant [DERIVED] |
| 005da564 | aSDS_0 | R | sSDS_Format [DERIVED] |
| 005da574 | aDDevAudiodevSh | R | AudioDevicePath [DERIVED] |
| 005da5a4 | aCmpegbaseProce | R | CmpegBaseProceString [DERIVED] |
| 005da5e0 | aAudioAssert | R | StrAudioAssert [DERIVED] |
| 005da714 | off_5DA714 | R | AssertHaltFuncPtr [DERIVED] |
| 005da718 | off_5DA718 | R | FileStreamVTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052e4e0 | sub_52E4E0 | [LLM] |
| 0052e520 | HaltAssertHandler | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24BE | != | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
