## sub_4ED0C0_004ed0c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4ED870 (004ed870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAC)+0x0) | 0x8 | R | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0x24 | R | — | [LLM] |
| *(*(this+0xAC)+0x0) | 0x28 | RW | 0 | [LLM] |
| *(this+0xA4) | 0x0 | R | — | [LLM] |
| *(this+0xAC) | 0x0 | R | — | [LLM] |
| *(this+0xAC) | 0x4 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0xA4 | RW | — | [LLM] |
| this | 0xA8 | RW | — | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0xAC)+0x0) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xAC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004eb570 | sub_4EB570 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005922a0 | sub_5922A0 | [LLM] |
| 00592310 | DestroyFree [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0xAC)+0x0) | 0x8 | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
