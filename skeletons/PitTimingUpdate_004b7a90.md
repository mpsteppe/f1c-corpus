## PitTimingUpdate_004b7a90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x9B0 | R | — | [LLM] |
| this | 0x9B8 | R | — | [LLM] |
| this | 0xD28 | RW | — | [LLM] |
| this | 0xD78 | RW | — | [LLM] |
| this | 0xD7C | RW | — | [LLM] |
| this | 0xF78 | R | — | [LLM] |
| this | 0xF7C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xD28: [LLM: once/conditional? does external poke survive?]
- this 0xD78: [LLM: once/conditional? does external poke survive?]
- this 0xD7C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b7c60 | jpt_4B7BDF | R | [LLM] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059ea08 | dbl_59EA08 | R | CollisionSkinThickness [DERIVED] (also: ` — clock sync tolerance) |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3af0 | AdvanceRingBuffer | [LLM] |
| 004b3b30 | SessionDataCopy | [LLM] |
| 004b5c50 | VehicleInstanceListBuilder | [LLM] |
| 004b5da0 | PitStallProximityCheck | [LLM] |
| 004b6190 | sub_4B6190 | [LLM] |
| 004b6940 | PitstopActionSet | [LLM] |
| 004c71c0 | SetupCarLightingAndRender | [LLM] |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | [LLM] |
| 00568d90 | PerformanceCounterDiffWithScaling | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
