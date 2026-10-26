## sub_4F8BD0_004f8bd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4F91E0 (004f91e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x4)+0x124) | 0xF0 | R | — | [LLM] |
| *(*(this+0x4)+0x124) | 0xFC | R | — | [LLM] |
| *(*(this+0x4)+0x124) | 0x100 | R | — | [LLM] |
| *(*(this+0x4)+0x124) | 0x104 | R | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xD4 | RW | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xD8 | RW | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xDC | RW | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xE0 | RW | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xE4 | RW | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xE8 | RW | — | [LLM] |
| *(*(this+0x8C)+0x8) | 0xEC | RW | — | [LLM] |
| *(this+0x4) | 0x0 | R | — | [LLM] |
| *(this+0x4) | 0xC4 | R | — | [LLM] |
| *(this+0x4) | 0xC8 | R | — | [LLM] |
| *(this+0x4) | 0xCC | R | — | [LLM] |
| *(this+0x4) | 0xD0 | R | — | [LLM] |
| *(this+0x4) | 0xD4 | R | — | [LLM] |
| *(this+0x4) | 0xD8 | R | — | [LLM] |
| *(this+0x4) | 0x124 | R | — | [LLM] |
| *(this+0x8C) | 0x8 | R | — | [LLM] |
| *(this+0xA0) | 0x58 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0x9 | R | — | [LLM] |
| this | 0xE | RW | 1 | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x8C | R | — | [LLM] |
| this | 0xA0 | R | — | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF8 | RW | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x104 | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x8C)+0x8) 0xD4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x8C)+0x8) 0xD8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x8C)+0x8) 0xDC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x8C)+0x8) 0xE0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x8C)+0x8) 0xE4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x8C)+0x8) 0xE8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x8C)+0x8) 0xEC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xE: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x104: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x108: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16b8 | flt_6F16B8 | R | [LLM] |
| 006f16c8 | flt_6F16C8 | R | [LLM] |
| 006f16d0 | flt_6F16D0 | R | [LLM] |
| 006f30dc | flt_6F30DC | R | [LLM] |
| 006f5088 | flt_6F5088 | R | [LLM] |
| 00731ce8 | String2 | R | [LLM] |
| 00757c1c | dword_757C1C | R | [LLM] |
| 0091e084 | dword_91E084 | R | [LLM] |
| 016c9414 | off_16C9414 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00405250 | sub_405250 | [LLM] |
| 00405f00 | sub_405F00 | [LLM] |
| 004f09d0 | sub_4F09D0 | [LLM] |
| 004f21d0 | sub_4F21D0 | [LLM] |
| 004f26b0 | sub_4F26B0 | [LLM] |
| 004f7bf0 | sub_4F7BF0 | [LLM] |
| 004f7c90 | sub_4F7C90 | [LLM] |
| 004f7dd0 | sub_4F7DD0 | [LLM] |
| 005a988b | sub_5A988B | [LLM] |
| 005bc080 | sub_5BC080 | [LLM] |
| 005db5a0 | sub_5DB5A0 | [LLM] |
| 00614a90 | EulerToRotationMatrix [exact] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
