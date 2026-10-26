## sub_4AB6F0_004ab6f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4AB950 (004ab950)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x254 | RW | 0 | [LLM] |
| this | 0x258 | RW | 0 | [LLM] |
| this | 0x25C | RW | — | [LLM] |
| this | 0x260 | RW | 0 | [LLM] |
| this | 0x267 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x254: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x258: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x25C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x260: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x267: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006e29fb | SEH_4AB6F0 | R | [LLM] |
| 006f16bc | WindowName | R | [LLM] |
| 006f2da4 | aSDs | R | [LLM] |
| 006f3b04 | aTrack | R | [LLM] |
| 006fd550 | aFilter_0 | R | [LLM] |
| 006fd558 | aDrivingschool | R | [LLM] |
| 006ff7a8 | aAndSimFull | R | [LLM] |
| 006ff7b8 | off_6FF7B8 | R | [LLM] |
| 006ff7bc | aSSDst | R | [LLM] |
| 0091cac8 | dword_91CAC8 | R | [LLM] |
| 00b6f708 | dword_B6F708 | R | [LLM] |
| 00b6f740 | dword_B6F740 | R | [LLM] |
| 00b761ec | dword_B761EC | R | [LLM] |
| 00be1bd0 | dword_BE1BD0 | W | [LLM] |
| 00be1cdc | unk_BE1CDC | R | [LLM] |
| 00be1ce0 | unk_BE1CE0 | R | [LLM] |
| 00be1cfd | unk_BE1CFD | R | [LLM] |
| 00faec84 | byte_FAEC84 | R | [LLM] |
| 00faecbc | dword_FAECBC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041d810 | sub_41D810 | [LLM] |
| 0041da80 | sub_41DA80 | [LLM] |
| 0048d380 | sub_48D380 | [LLM] |
| 00538790 | sub_538790 | [LLM] |
| 00538860 | sub_538860 | [LLM] |
| 00539ff0 | sub_539FF0 | [LLM] |
| 0053a0e0 | sub_53A0E0 | [LLM] |
| 0053a160 | AIW [structural] | [LLM] |
| 0053ae90 | sub_53AE90 | [LLM] |
| 0053bde0 | sub_53BDE0 | [LLM] |
| 00615860 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 00615d30 | ShortComputation_5f70 [exact] | [LLM] |
| 00615fc0 | sub_615FC0 | [LLM] |
| 00615fe0 | sub_615FE0 | [LLM] |
| 00616630 | sub_616630 | [LLM] |
| 00616840 | FileStreamReader [structural] | [LLM] |
| 00616960 | sub_616960 | [LLM] |
| 00616f90 | sub_616F90 | [LLM] |
| 006308d8 | j_j__free | [LLM] |
| 00630fe0 | sub_630FE0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Track`
- `Filter`
- `DrivingSchool`
- `AND: SIM_FULL`
- `Car`
- `%s%s.dst`
