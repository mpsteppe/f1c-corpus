## _setvbuf_005d2c96 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5D0664 (005d0664), sub_5D178A (005d178a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ff178 | dword_7FF178 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c130a | BufferFlushWrite [structural] | [LLM] |
| 005c1a4e | _malloc | [LLM] |
| 005c32b5 | __lock_file | [LLM] |
| 005c3307 | __unlock_file | [LLM] |
| 005c3515 | __freebuf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
