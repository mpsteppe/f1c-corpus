## sub_4AA0A0_004aa0a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4A9940 (004a9940), sub_4AA0A0 (004aa0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1DC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x1DC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 00608ab4 | asc_608AB4 | R | [LLM] |
| 00608ab8 | asc_608AB8 | R | [LLM] |
| 00608c10 | aSurface | R | [LLM] |
| 00608c24 | aPosWH | R | [LLM] |
| 00608c2c | aLocation | R | [LLM] |
| 00608eb0 | aSubanimframe | R | [LLM] |
| 00608ec0 | aAnimrule | R | [LLM] |
| 00608ecc | aAnimdelta | R | [LLM] |
| 00629120 | byte_629120 | R | [LLM] |
| 007656e8 | byte_7656E8 | R | [LLM] |
| 00765880 | Str | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a84a0 | sub_4A84A0 | [LLM] |
| 004aa0a0 | sub_4AA0A0 | [LLM] |
| 004b0f90 | sub_4B0F90 | [LLM] |
| 00577e50 | sub_577E50 | [LLM] |
| 00578220 | sub_578220 | [LLM] |
| 005be8bc | __ftol | [LLM] |
| 005be900 | _strstr | [LLM] |
| 005bebfe | _atol | [LLM] |
| 005bf239 | _atof | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `SURFACE`
- `POS-W-H`
- `LOCATION`
- `SUBANIMFRAME`
- `ANIMRULE`
- `ANIMDELTA`
