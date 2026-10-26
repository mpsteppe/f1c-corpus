## sub_5BA7B0_005ba7b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5BA8B0 (005ba8b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| ff00000000005e86 | byte_FF00000000005E86 | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bac40 | MathDispatchWithErrorFallback [structural] | [LLM] |
| 005bdb90 | NetworkStartup [exact] | [LLM] |
| 005d26c8 | htonl [exact] | [LLM] |
| 005d26ce | getsockname [exact] | [LLM] |
| 005d26d4 | ntohs [exact] | [LLM] |
| 005d26da | socket [exact] | [LLM] |
| 005d26ec | bind [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
