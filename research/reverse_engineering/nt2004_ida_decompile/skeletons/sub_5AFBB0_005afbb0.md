## sub_5AFBB0_005afbb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5AF330 (005af330)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x50)+0x4) | 0xAC | R | — | [LLM] |
| *(*(this+0x50)+0x4) | 0xB0 | R | — | [LLM] |
| *(*(this+0x50)+0xC) | 0x0 | RW | 1028443341 → 0.05f | [LLM] |
| *(*(this+0x50)+0xC) | 0x4 | RW | 1028443341 → 0.05f | [LLM] |
| *(*(this+0x50)+0xC) | 0x8 | RW | 1028443341 → 0.05f | [LLM] |
| *(*(this+0x50)+0xC) | 0x18 | RW | — | [LLM] |
| *(*(this+0x50)+0xC) | 0x24 | RW | 18446744072590511309 → -0.05f | [LLM] |
| *(*(this+0x50)+0xC) | 0x28 | RW | 18446744072590511309 → -0.05f | [LLM] |
| *(*(this+0x50)+0xC) | 0x2C | RW | 1028443341 → 0.05f | [LLM] |
| *(*(this+0x50)+0xC) | 0x3C | RW | — | [LLM] |
| *(this+0x50) | 0x0 | RW | 0 | [LLM] |
| *(this+0x50) | 0x4 | RW | — | [LLM] |
| *(this+0x50) | 0x8 | RW | — | [LLM] |
| *(this+0x50) | 0xC | RW | — | [LLM] |
| *(this+0x50) | 0x10 | RW | — | [LLM] |
| *(this+0x50) | 0x14 | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | 8 | [LLM] |
| this | 0x28 | RW | 36 | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x3C | RW | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x4C | RW | 1 | [LLM] |
| this | 0x50 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x50)+0xC) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x50)+0xC) 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x50) 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x34: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x3C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x50: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007e8e5c | dword_7E8E5C | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005918b0 | GlobalZeroInit_c2a0 [exact] | [LLM] |
| 00598170 | sub_598170 | [LLM] |
| 00599620 | sub_599620 | [LLM] |
| 005997a0 | TwoCounterIncrements [exact] | [LLM] |
| 005998d0 | ResourceObjectCreationWithConfig [structural] | [LLM] |
| 0059a570 | sub_59A570 | [LLM] |
| 0059a660 | sub_59A660 | [LLM] |
| 005a1c40 | FieldSetterAt0x80 [exact] | [LLM] |
| 005a1c50 | sub_5A1C50 | [LLM] |
| 005af260 | StructInitWithVTableColor [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005c0803 | __strupr | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(*(this+0x50)+0x4) | 0xAC | > | 0 | [LLM] |
| this | 0x2C | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
