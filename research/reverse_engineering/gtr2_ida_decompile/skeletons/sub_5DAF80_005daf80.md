## sub_5DAF80_005daf80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_405990 (00405990), sub_5FBB60 (005fbb60), sub_5FBCC0 (005fbcc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a8 | dword_FB27A8 | R | [LLM] |
| 01000000 | dword_1000000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7810 | sub_5D7810 | [LLM] |
| 005ec2a0 | sub_5EC2A0 | [LLM] |
| 005ec2f0 | sub_5EC2F0 | [LLM] |
| 005ec450 | sub_5EC450 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
