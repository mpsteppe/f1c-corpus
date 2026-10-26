## sub_5EC2A0_005ec2a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5DAF80 (005daf80), sub_5F3D00 (005f3d00), sub_5FF0E0 (005ff0e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb27a8 | dword_FB27A8 | R | [LLM] |
| 016c97e0 | off_16C97E0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d7810 | sub_5D7810 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
