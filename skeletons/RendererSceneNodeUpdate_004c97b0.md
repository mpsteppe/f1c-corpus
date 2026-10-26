## RendererSceneNodeUpdate_004c97b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0x4 | R | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| this | 0x1C | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c9820 | VirtualStateCheckViaIndex | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
