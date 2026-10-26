## MeshVertexIndexBufferLoader_00550ad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5508A0 (005508a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 008b8f30 | dword_8B8F30 | RW | TempFileReadBuffer [DERIVED] |
| 008b8f34 | dword_8B8F34 | RW | FileReadBuffer2 [DERIVED] (also: ` — temp file read buffer (secondary) |
| 008b8f3c | dword_8B8F3C | W | GlobalDataBufferPtr [DERIVED] (also: ` — global data buffer pointer (advances on read) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054a5c0 | ArithmeticComparison_a5c0 | [LLM] |
| 005507a0 | sub_5507A0 | [LLM] |
| 005507e0 | StructInitWithVtableZero | [LLM] |
| 00550800 | DualFieldZeroInit | [LLM] |
| 005593b0 | StructZeroInit_93b0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587f64 | sub_587F64 | [LLM] |
| 0058803f | ThreadSafeReadWrapper_803f | [LLM] |
| 00589901 | sub_589901 | [LLM] |
| 0058ace6 | FileSizeQueryWrapper | [LLM] |
| 0059b260 | sub_59B260 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
