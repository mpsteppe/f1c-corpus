## sub_48CAD0_0048cad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xAC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5914 | flt_5D5914 | R | [LLM] |
| 005fd8ac | aD | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 0076ad70 | flt_76AD70 | RW | [LLM] |
| 0076ad78 | flt_76AD78 | R | [LLM] |
| 0076ad7c | flt_76AD7C | R | [LLM] |
| 0076aeb4 | flt_76AEB4 | RW | [LLM] |
| 0076aebc | flt_76AEBC | R | [LLM] |
| 0076aec0 | dword_76AEC0 | R | [LLM] |
| 0076afd4 | dword_76AFD4 | R | [LLM] |
| 0076b1cc | flt_76B1CC | RW | [LLM] |
| 0076b1d4 | flt_76B1D4 | R | [LLM] |
| 0076b1d8 | dword_76B1D8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466720 | FloatClamp [exact] | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `%d%%`
