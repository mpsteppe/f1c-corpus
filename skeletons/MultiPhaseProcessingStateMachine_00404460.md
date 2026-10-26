## MultiPhaseProcessingStateMachine_00404460 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x130 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |
| this | 0x16C | RW | 1 | [LLM] |
| this | 0x170 | RW | — | [LLM] |
| this | 0x174 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x16C: [LLM: once/conditional? does external poke survive?]
- this 0x170: [LLM: once/conditional? does external poke survive?]
- this 0x174: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e480 | dbl_59E480 | R | PhysicsTolerance [DERIVED] (also: ` — multiplier/tolerance) |
| 008afee8 | flt_8AFEE8 | R | TrackGripBase [DERIVED] |
| 008afeec | flt_8AFEEC | R | TrackGripComparison [DERIVED] (also: ` — additive globals) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004faf60 | sub_4FAF60 | [LLM] |
| 004fb260 | sub_4FB260 | [LLM] |
| 004fb2e0 | VehicleProximity | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x174 | != | 18446744073709551615 | [LLM] |
| this | 0x174 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
