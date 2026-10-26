## sub_4E9CE0_004e9ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EC870 (004ec870), sub_4ECA90 (004eca90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x34) | 0x14 | RW | — | [LLM] |
| *(this+0x44) | 0x28 | RW | 0 | [LLM] |
| *(this+0x54) | 0x1C | RW | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x34) 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x44) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x54) 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |
| 007d6b74 | dword_7D6B74 | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004e9fb0 | sub_4E9FB0 | [LLM] |
| 0050ee10 | LinkedListNodeAdvance [exact] | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00592310 | DestroyFree [structural] | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
