## sub_60FCA0_0060fca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x254C)+0x0) | 0xE4 | R | — | [LLM] |
| *(this+0x254C) | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x2334 | RW | 1 | [LLM] |
| this | 0x2338 | RW | — | [LLM] |
| this | 0x233C | RW | — | [LLM] |
| this | 0x2340 | RW | — | [LLM] |
| this | 0x2344 | RW | — | [LLM] |
| this | 0x2348 | RW | — | [LLM] |
| this | 0x254C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2334: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2338: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x233C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2340: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2344: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2348: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00ffffff | byte_FFFFFF | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005dce60 | sub_5DCE60 | [LLM] |
| 005dceb0 | sub_5DCEB0 | [LLM] |
| 005dcec0 | sub_5DCEC0 | [LLM] |
| 005dced0 | sub_5DCED0 | [LLM] |
| 005dcee0 | ?GetGroup@ScheduleGroupSegmentBase@details@Concurrency@@QBEPAVScheduleGroupBase@23@XZ | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
