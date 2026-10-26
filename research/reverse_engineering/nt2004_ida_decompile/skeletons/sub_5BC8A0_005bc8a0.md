## sub_5BC8A0_005bc8a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5BC800 (005bc800), sub_5BD4F0 (005bd4f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00577650 | sub_577650 | [LLM] |
| 005bdb30 | LocaleAwareStringFormat [structural] | [LLM] |
| 005be160 | BatchLoopWithMemoryCleanup [structural] | [LLM] |
| 005be1b0 | LinearInterpolation [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
