## FileTellSeekPositionQuery_00587f90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_587F64 (00587f64)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x18 | RW | 512 | [LLM] |

**Written-by note (persistence):**
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a05a | BufferFlushWrite | [LLM] |
| 0058ad08 | sub_58AD08 | [LLM] |
| 0058afcf | TLSOffsetGetter | [LLM] |
| 0058c724 | sub_58C724 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
