## ___crtsetenv_00643ac9 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** ___wtomb_environ (0064357f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f10fc | SetEnvironmentVariableA | R | [LLM] |
| 00fb81b4 | dword_FB81B4 | RW | [LLM] |
| 00fb81b8 | dword_FB81B8 | R | [LLM] |
| 00fb81bc | dword_FB81BC | RW | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00634919 | _free | [LLM] |
| 006349c9 | _realloc | [LLM] |
| 00634c1d | _malloc | [LLM] |
| 006354d0 | sub_6354D0 | [LLM] |
| 00636a70 | _strcpy | [LLM] |
| 0064357f | ___wtomb_environ | [LLM] |
| 00643a1b | F_3DVectorBlend [structural] | [LLM] |
| 00643a68 | _copy_environ | [LLM] |
| 00643cc9 | __mbschr | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
