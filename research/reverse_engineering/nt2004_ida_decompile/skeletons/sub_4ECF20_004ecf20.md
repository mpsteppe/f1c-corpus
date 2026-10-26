## sub_4ECF20_004ecf20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ArrayScanForValue10 [structural] (004ec7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x8 | RW | — | [LLM] |
| *(obj+0x0) | 0xC | RW | — | [LLM] |
| *(obj+0x0) | 0x10 | RW | — | [LLM] |
| *(obj+0x0) | 0x14 | R | — | [LLM] |
| *(obj+0x0) | 0x18 | RW | — | [LLM] |
| *(obj+0x0) | 0x1C | RW | — | [LLM] |
| *(obj+0x0) | 0x20 | RW | — | [LLM] |
| *(obj+0x0) | 0x24 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |

**Written-by note (persistence):**
- *(obj+0x0) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(obj+0x0) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(obj+0x0) 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(obj+0x0) 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(obj+0x0) 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(obj+0x0) 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004db610 | ShortComputation_ac20 [exact] | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
