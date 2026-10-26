## sub_51DFCB_0051dfcb — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 56 | [LLM] |
| obj | 0x18 | RW | 256 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x4C | RW | 2 | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1A8 | RW | — | [LLM] |
| this | 0x1AC | RW | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1C0 | RW | 0 | [LLM] |
| this | 0x1C4 | RW | — | [LLM] |
| this | 0x1C8 | RW | 0 | [LLM] |
| this | 0x1CC | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1AC: [LLM: once/conditional? does external poke survive?]
- this 0x1C0: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]
- this 0x1C8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051d1db | TrackSurfaceHeightmapIncrement | R | [LLM] |
| 0051dc01 | PackedPixelCopyWithPaletteLookup | R | [LLM] |
| 0051dcaa | BlockTextureDecompression | R | [LLM] |
| 0051dfa8 | VehicleUpdateFrameSetup | R | [LLM] |
| 0051dfca | nullsub_4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | [LLM] |
| 0051df18 | SymmetricArrayInit | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x4C | == | 0 | [LLM] |
| this | 0x4C | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
