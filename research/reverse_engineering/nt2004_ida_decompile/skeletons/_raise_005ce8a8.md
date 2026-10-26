## _raise_005ce8a8 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** _abort (005ce891)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |
| this | 0x58 | RW | 140 | [LLM] |

**Written-by note (persistence):**
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00626550 | dword_626550 | R | [LLM] |
| 00626554 | dword_626554 | R | [LLM] |
| 007ff498 | dword_7FF498 | R | [LLM] |
| 007ff49c | dword_7FF49C | R | [LLM] |
| 007ff4a0 | dword_7FF4A0 | R | [LLM] |
| 007ff4a4 | dword_7FF4A4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c0b89 | __exit | [LLM] |
| 005c5128 | __getptd | [LLM] |
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | [LLM] |
| 005c5315 | __unlock | [LLM] |
| 005cea2a | _siglookup | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
