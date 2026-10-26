## PitStallProximityCheck_004b5da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B4 | R | — | [LLM] |
| this | 0x9B8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e8a4 | flt_59E8A4 | R | ReverseGearThrottleMult [DERIVED] (also: ` â€” reverse gear throttle multiplier) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b48e0 | CollisionObjectInsertion | [LLM] |
| 004b68c0 | CircularBufferCheck | [LLM] |
| 004b6920 | IndexedPointerLookup | [LLM] |
| 004b6940 | PitstopActionSet | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
