## AmbientSoundPlayback_004c9840 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x0 | R | — | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x38: [LLM: once/conditional? does external poke survive?]
- this 0x3C: [LLM: once/conditional? does external poke survive?]
- this 0x40: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005d3448 | aAmbient | R | AmbientString [DERIVED] |
| 005d347c | aPithornWav | R | PithornWavString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3e0 | dword_5EC3E0 | R | AudioDirBasePath [DERIVED] |
| 007cf530 | flt_7CF530 | R | AmbientVolumeScale [DERIVED] |
| 007cf554 | flt_7CF554 | R | AudioVolume_VolumeFade [DERIVED] |
| 007cf578 | dword_7CF578 | R | AudioVolumeFactor [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
