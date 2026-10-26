## sub_5ACEB0_005aceb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5ACC30 (005acc30)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 007f5e68 | dword_7F5E68 | RW | [LLM] |
| 007f5e6c | dword_7F5E6C | RW | [LLM] |
| 007f5e74 | dword_7F5E74 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0059d490 | ArithmeticComparison_a5c0 [exact] | [LLM] |
| 005acb30 | sub_5ACB30 | [LLM] |
| 005acb70 | StructInitWithVtableZero [structural] | [LLM] |
| 005acb90 | ??0_ReaderWriterLock@details@Concurrency@@QAE@XZ | [LLM] |
| 005b1340 | sub_5B1340 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005bec94 | _fseek | [LLM] |
| 005bed6f | sub_5BED6F | [LLM] |
| 005bf3bf | _ftell | [LLM] |
| 005c0803 | __strupr | [LLM] |
| 005d2750 | sub_5D2750 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
