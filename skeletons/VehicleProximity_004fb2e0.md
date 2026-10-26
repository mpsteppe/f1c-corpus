## VehicleProximity_004fb2e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiPhaseProcessingStateMachine (00404460), CountedLoopCallToElementUpdate (004047d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10C) | 0x94 | R | — | [LLM] |
| *(this+0x10C) | 0x9C | R | — | [LLM] |
| *(this+0x10C) | 0xA4 | R | — | [LLM] |
| *(this+0x10C) | 0xAC | R | — | [LLM] |
| *(this+0x110) | 0x94 | R | — | [LLM] |
| *(this+0x110) | 0x9C | R | — | [LLM] |
| *(this+0x110) | 0xA4 | R | — | [LLM] |
| *(this+0x110) | 0xAC | R | — | [LLM] |
| *(this+0x110) | 0x110 | R | — | [LLM] |
| *(this+0x114) | 0x0 | R | — | [LLM] |
| *(this+0x114) | 0x8 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x9C | R | — | [LLM] |
| this | 0xA4 | R | — | [LLM] |
| this | 0xAC | R | — | [LLM] |
| this | 0xB0 | RW | 0 | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0x10C | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xB0: [LLM: once/conditional? does external poke survive?]
- this 0xB4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ad278 | dbl_5AD278 | R | FrictionAngleClampHigh [DERIVED] |
| 005ad280 | dbl_5AD280 | R | LineIntersectionThreshold [DERIVED] (also: ` — steering alignment lower threshold) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
