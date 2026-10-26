## sub_4ECCB0_004eccb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4ED7F0 (004ed7f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAC)+0x0) | 0x8 | RW | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0x14 | RW | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0x18 | RW | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0x24 | RW | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0x28 | RW | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x20) | 0x1C | R | — | [LLM] |
| *(this+0x28) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x8 | R | — | [LLM] |
| *(this+0x28) | 0xC | R | — | [LLM] |
| *(this+0x28) | 0x14 | R | — | [LLM] |
| *(this+0x28) | 0x18 | R | — | [LLM] |
| *(this+0x28) | 0x1C | R | — | [LLM] |
| *(this+0x28) | 0x24 | R | — | [LLM] |
| *(this+0x28) | 0x28 | RW | 0 | [LLM] |
| *(this+0xA4) | 0x0 | R | — | [LLM] |
| *(this+0xAC) | 0x0 | R | — | [LLM] |
| *(this+0xAC) | 0x4 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0xA4 | R | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0xAC)+0x0) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0xAC)+0x0) 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0xAC)+0x0) 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0xAC)+0x0) 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0xAC)+0x0) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x28) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00592310 | DestroyFree [structural] | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0xAC)+0x0) | 0x8 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
