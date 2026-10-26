## SuspensionFloatClamp_0047a290 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xB4 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007d17cc | unk_7D17CC | R | SuspensionFloatArray (stride 0x6c) [DERIVED] |
| 007d1b2c | flt_7D1B2C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466910 | SetupValueDisplayFormatter | [LLM] |
| 00490190 | ZeroCheckGetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
