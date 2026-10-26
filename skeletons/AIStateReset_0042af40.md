## AIStateReset_0042af40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitCrewStateMachine (004bbfc0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4410 | RW | 1 | RetiredFlag [FACT] |
| this | 0x45F4 | RW | 0 | ActiveFlag [FACT] |

**Written-by note (persistence):**
- this 0x4410: [LLM: once/conditional? does external poke survive?]
- this 0x45F4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a5c80 | StateChangeNotify | [LLM] |
| 004efac0 | ConditionalGate | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
