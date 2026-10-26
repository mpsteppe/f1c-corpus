## CinematicEventStateMachine_0040ddf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateMachineInitializer (0040dcd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709551615 | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x98 | RW | 0 | [LLM] |
| this | 0x9C | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x98: [LLM: once/conditional? does external poke survive?]
- this 0x9C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040de4c | jpt_40DE02 | R | [LLM] |
| 0040de54 | byte_40DE54 | R | [LLM] |
| 005beb50 | aCinematicevent | R | CinematicEventField [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d4c0 | RaceCommentaryDirectorSystem | [LLM] |
| 005679c0 | StringKeyedLinkedListSearch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
