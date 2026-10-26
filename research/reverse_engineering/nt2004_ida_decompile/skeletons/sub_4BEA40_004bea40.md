## sub_4BEA40_004bea40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BDDB0 (004bddb0), sub_4C1830 (004c1830)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB4 | RW | 2 | [LLM] |
| this | 0xCC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54c0 | dbl_5D54C0 | R | [LLM] |
| 00628f60 | flt_628F60 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f90 | sub_404F90 | [LLM] |
| 00579100 | EulerToRotationMatrix [exact] | [LLM] |
| 00579c10 | sub_579C10 | [LLM] |
| 0059e050 | ThreeFieldSetterWithSubCall [structural] | [LLM] |
| 0059e0f0 | sub_59E0F0 | [LLM] |
| 005c05d0 | __CIasin | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
