## sub_4CAA80_004caa80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_485F00 (00485f00), sub_4CA940 (004ca940)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3D0 | RW | 0 | [LLM] |
| this | 0x3D8 | R | — | [LLM] |
| this | 0x3DC | R | — | [LLM] |
| this | 0x418 | RW | 2 | [LLM] |
| this | 0x420 | R | — | [LLM] |
| this | 0x424 | R | — | [LLM] |
| this | 0x43C | RW | 0 | [LLM] |
| this | 0x444 | R | — | [LLM] |
| this | 0x448 | R | — | [LLM] |
| this | 0x460 | RW | 2 | [LLM] |
| this | 0x468 | R | — | [LLM] |
| this | 0x46C | R | — | [LLM] |
| this | 0x484 | RW | 0 | [LLM] |
| this | 0x48C | R | — | [LLM] |
| this | 0x490 | R | — | [LLM] |
| this | 0x4A8 | RW | 0 | [LLM] |
| this | 0x4B0 | R | — | [LLM] |
| this | 0x4B4 | R | — | [LLM] |
| this | 0x4CC | RW | 0 | [LLM] |
| this | 0x4D4 | R | — | [LLM] |
| this | 0x4D8 | R | — | [LLM] |
| this | 0x4F0 | RW | 0 | [LLM] |
| this | 0x4F8 | R | — | [LLM] |
| this | 0x4FC | R | — | [LLM] |
| this | 0x514 | RW | 0 | [LLM] |
| this | 0x51C | R | — | [LLM] |
| this | 0x520 | R | — | [LLM] |
| this | 0x538 | RW | 1 | [LLM] |
| this | 0x540 | R | — | [LLM] |
| this | 0x544 | R | — | [LLM] |
| this | 0x598 | RW | 1 | [LLM] |
| this | 0x5A0 | R | — | [LLM] |
| this | 0x5A4 | R | — | [LLM] |
| this | 0x5EC | RW | 3 | [LLM] |
| this | 0x5F4 | R | — | [LLM] |
| this | 0x5F8 | R | — | [LLM] |
| this | 0x225C | R | — | [LLM] |
| this | 0x2280 | RW | 1048576000 → 0.25f | [LLM] |
| this | 0x2288 | R | — | [LLM] |
| this | 0x228C | R | — | [LLM] |
| this | 0x22A4 | RW | 95 | [LLM] |
| this | 0x22AC | R | — | [LLM] |
| this | 0x22B0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x3D0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x418: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x43C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x460: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x484: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4A8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4CC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4F0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x514: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x538: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x598: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5EC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2280: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x22A4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004cb208 | jpt_4CAA98 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466720 | FloatClamp [exact] | [LLM] |
| 004cef90 | sub_4CEF90 | [LLM] |
| 004cf370 | sub_4CF370 | [LLM] |
| 004cf410 | ClampByRange [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
