## sub_60CAA0_0060caa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x254C) | 0x170 | R | — | [LLM] |
| *(this+0x254C) | 0x1AC | R | — | [LLM] |
| this | 0x254C | R | — | [LLM] |
| this | 0x25AC | RW | 0 | [LLM] |
| this | 0x25B0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x25AC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x25B0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00fb40cc | dword_FB40CC | R | [LLM] |
| 00fb40d0 | dword_FB40D0 | R | [LLM] |
| 00fb40d4 | dword_FB40D4 | R | [LLM] |
| 00fb40d8 | dword_FB40D8 | R | [LLM] |
| 00fb40dc | dword_FB40DC | R | [LLM] |
| 00fb40e0 | dword_FB40E0 | R | [LLM] |
| 00fb40e4 | dword_FB40E4 | R | [LLM] |
| 00fb40e8 | dword_FB40E8 | R | [LLM] |
| 00fb40ec | dword_FB40EC | R | [LLM] |
| 00fb40f0 | dword_FB40F0 | R | [LLM] |
| 00fb40f4 | dword_FB40F4 | R | [LLM] |
| 00fb40f8 | dword_FB40F8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0060c8d0 | sub_60C8D0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
