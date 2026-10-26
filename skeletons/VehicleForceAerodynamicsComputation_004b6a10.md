## VehicleForceAerodynamicsComputation_004b6a10 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7500 (004b7500), sub_4B7DE0 (004b7de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x714)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x714)+0x0) | 0x8 | R | — | [LLM] |
| *(this+0x48) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| *(this+0x6C0) | 0x0 | R | — | [LLM] |
| *(this+0x6C8) | 0x4 | R | — | [LLM] |
| *(this+0x714) | 0x0 | R | — | [LLM] |
| *(this+0x71C) | 0x0 | R | — | [LLM] |
| *(this+0x71C) | 0x4 | R | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x6C0 | R | — | [LLM] |
| this | 0x6C8 | RW | — | [LLM] |
| this | 0x6CC | R | — | [LLM] |
| this | 0x714 | R | — | [LLM] |
| this | 0x71C | RW | — | [LLM] |
| this | 0x724 | R | — | [LLM] |
| this | 0x72C | R | — | [LLM] |
| this | 0xF1C | R | — | [LLM] |
| this | 0xF20 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x6C8: [LLM: once/conditional? does external poke survive?]
- this 0x71C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d2434 | off_5D2434 | R | SerializeMagic [DERIVED] |
| 005d2438 | flt_5D2438 | R | CheckpointTime [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b41e0 | FileStreamWriter | [LLM] |
| 004b4fb0 | sub_4B4FB0 | [LLM] |
| 004b5e30 | sub_4B5E30 | [LLM] |
| 00566bd0 | ConditionalDispatch_6bd0 | [LLM] |
| 00566d30 | ConditionalAllocInitDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
