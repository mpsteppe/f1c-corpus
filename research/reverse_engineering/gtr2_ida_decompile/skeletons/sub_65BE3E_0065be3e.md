## sub_65BE3E_0065be3e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_65BE3E (0065be3e), sub_65CBD1 (0065cbd1)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x268)+0x38) | 0x0 | R | — | [LLM] |
| *(*(this+0x268)+0x38) | 0x4 | R | — | [LLM] |
| *(this+0x268) | 0x38 | R | — | [LLM] |
| *(this+0x280) | 0x0 | R | — | [LLM] |
| *(this+0x64) | 0xC | RW | 0 | [LLM] |
| this | 0x40 | RW | 1 | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | 1 | [LLM] |
| this | 0x4C | RW | 1 | [LLM] |
| this | 0x50 | RW | 1 | [LLM] |
| this | 0x58 | RW | 1 | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x268 | R | — | [LLM] |
| this | 0x278 | RW | 12 | [LLM] |
| this | 0x280 | R | — | [LLM] |
| this | 0x281 | R | — | [LLM] |
| this | 0x282 | R | — | [LLM] |
| this | 0x298 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x64) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x278: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00737940 | aError_0 | R | [LLM] |
| 007379a8 | aInvalidOrUnsup | R | [LLM] |
| 00737a98 | aDefined | R | [LLM] |
| 00737aa0 | aDefine_0 | R | [LLM] |
| 00737aa8 | aEndif | R | [LLM] |
| 00737ab0 | aElse | R | [LLM] |
| 00737ab8 | aElif | R | [LLM] |
| 00737ac0 | aInclude | R | [LLM] |
| 00737ac8 | aIfndef | R | [LLM] |
| 00737ad0 | aIfdef | R | [LLM] |
| 00737ad8 | aIf | R | [LLM] |
| 00737adc | aLine_0 | R | [LLM] |
| 00737ae4 | aPragma | R | [LLM] |
| 00737aec | aUndef | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0065b1a2 | IndexDecrementWithBoundsWrap [structural] | [LLM] |
| 0065b5d6 | sub_65B5D6 | [LLM] |
| 0065be3e | sub_65BE3E | [LLM] |
| 0065dd1f | sub_65DD1F | [LLM] |
| 0065e7a1 | sub_65E7A1 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x280) | 0x0 | != | 105 | [LLM] |
| *(this+0x280) | 0x0 | != | 101 | [LLM] |
| *(this+0x280) | 0x0 | == | 100 | [LLM] |
| *(this+0x280) | 0x0 | == | 117 | [LLM] |
| *(this+0x280) | 0x0 | == | 112 | [LLM] |
| *(this+0x280) | 0x0 | == | 108 | [LLM] |
| *(this+0x280) | 0x0 | == | 105 | [LLM] |
| this | 0x44 | == | 0 | [LLM] |
| this | 0x50 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `error`
- `invalid or unsupported integer constant expression`
- `defined`
- `define`
- `endif`
- `endif`
- `else`
- `else`
- `elif`
- `elif`
- `include`
- `ifndef`
- `ifndef`
- `ifdef`
- `ifdef`
- `line`
- `pragma`
- `undef`
