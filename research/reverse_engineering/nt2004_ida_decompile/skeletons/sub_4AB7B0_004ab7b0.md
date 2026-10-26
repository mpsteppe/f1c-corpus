## sub_4AB7B0_004ab7b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x4)+0x0)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x15C)+0x4) | 0x4 | R | — | [LLM] |
| *(*(this+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(this+0x138) | 0x8 | R | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0xC | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0x104 | RW | 0 | [LLM] |
| this | 0x138 | RW | 0 | [LLM] |
| this | 0x13C | RW | 0 | [LLM] |
| this | 0x140 | RW | 0 | [LLM] |
| this | 0x144 | RW | 0 | [LLM] |
| this | 0x15C | RW | 0 | [LLM] |
| this | 0x160 | RW | 0 | [LLM] |
| this | 0x164 | RW | 0 | [LLM] |
| this | 0x168 | RW | 0 | [LLM] |
| this | 0x174 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x104: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x138: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x13C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x140: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x144: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x15C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x160: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x164: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x168: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea21c | off_5EA21C | R | [LLM] |
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004aa6c0 | sub_4AA6C0 | [LLM] |
| 004af7d0 | sub_4AF7D0 | [LLM] |
| 004af810 | sub_4AF810 | [LLM] |
| 004af860 | LinkedListDestroy [structural] | [LLM] |
| 004b11a0 | sub_4B11A0 | [LLM] |
| 004daeb0 | LinkedListDestructor_b400 [structural] | [LLM] |
| 00506920 | sub_506920 | [LLM] |
| 00506c70 | sub_506C70 | [LLM] |
| 00592c40 | sub_592C40 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0x4) | 0xC | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
