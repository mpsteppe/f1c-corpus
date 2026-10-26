## SessionPhaseDispatchWithCascadeChecks_0040d1b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraDirectorResetInit (0040da30), sub_40DE60 (0040de60), EngineGuardedInitializer (004347c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0x10 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x2C | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x2C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040a910 | MenuSlotActionDispatch | [LLM] |
| 0040b450 | LookupWithOptionalCallback | [LLM] |
| 0040bcd0 | ResourceLookupWithOptionalVTableDispatch | [LLM] |
| 0040cd60 | SessionPhaseDecode | [LLM] |
| 0040cdd0 | SimpleSetter | [LLM] |
| 0040cde0 | GameActionStateMachine | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
