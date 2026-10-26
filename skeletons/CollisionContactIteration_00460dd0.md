## CollisionContactIteration_00460dd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1A3D4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059ea60 | dbl_59EA60 | R | DampingFactorB [DERIVED] (also: ` — angular threshold for partial response) |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54d8 | byte_7C54D8 | R | VehicleArrayEnd [DERIVED] |
| 007d108c | flt_7D108C | R | MinPenetrationLimit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045cbf0 | ShortArrayLookupAndZeroCheck | [LLM] |
| 004c7a70 | VehicleAIControlFlag | [LLM] |
| 004c7aa0 | SetDriverVisibility | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
