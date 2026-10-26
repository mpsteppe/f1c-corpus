## sub_5BC8F0_005bc8f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5B9C40 (005b9c40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005ba080 | ObjectConstructor_9872 [structural] | [LLM] |
| 005bc800 | sub_5BC800 | [LLM] |
| 005bda60 | sub_5BDA60 | [LLM] |
| 005be160 | BatchLoopWithMemoryCleanup [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
