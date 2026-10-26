## ??1ios_base@std@@UAE@XZ_005d1ce4 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ??_Gios_base@std@@UAEPAXI@Z (005d1d34)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x24 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d46ab | loc_5D46AB | R | [LLM] |
| 005f76cc | off_5F76CC | R | [LLM] |
| 007ff8ec | byte_7FF8EC | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c1db0 | __EH_prolog | [LLM] |
| 005d00e8 | ??1locale@std@@QAE@XZ | [LLM] |
| 005d1df8 | ?_Tidy@ios_base@std@@AAEXXZ | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
