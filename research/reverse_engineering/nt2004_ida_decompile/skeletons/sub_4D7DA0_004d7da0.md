## sub_4D7DA0_004d7da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D9EF0 (004d9ef0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x350)+0x4)+0x4) | 0x4 | R | — | [LLM] |
| *(*(*(this+0x350)+0x4)+0x4) | 0x8 | RW | — | [LLM] |
| *(*(this+0x350)+0x4) | 0x4 | RW | 0 | [LLM] |
| *(this+0x350) | 0x4 | R | — | [LLM] |
| *(this+0x350) | 0x8 | RW | — | [LLM] |
| this | 0x350 | RW | — | [LLM] |
| this | 0x354 | RW | — | [LLM] |
| this | 0x358 | RW | — | [LLM] |
| this | 0x35C | R | — | [LLM] |
| this | 0x360 | RW | 1 | [LLM] |
| this | 0x81C | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(*(this+0x350)+0x4)+0x4) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(*(this+0x350)+0x4) 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- *(this+0x350) 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x350: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x354: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x358: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x360: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fc194 | aD_4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d7f60 | sub_4D7F60 | [LLM] |
| 004dbba0 | sub_4DBBA0 | [LLM] |
| 00578600 | StringCopyWithBufferRealloc [structural] | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |
| 005beec8 | _sprintf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
