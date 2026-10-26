## CameraViewSetupFromVehiclePosition_0045af50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x28 | R | — | [LLM] |
| this | 0x50 | RW | 9 | [LLM] |
| this | 0x58 | R | — | [LLM] |
| this | 0x5C | RW | 0 | [LLM] |
| this | 0xCC | RW | — | [LLM] |
| this | 0x180 | R | — | [LLM] |
| this | 0x318 | RW | — | [LLM] |
| this | 0x320 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0xCC: [LLM: once/conditional? does external poke survive?]
- this 0x318: [LLM: once/conditional? does external poke survive?]
- this 0x320: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e880 | dbl_59E880 | R | HalfStep [DERIVED] (also: ` — lower threshold constant) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004dd550 | BoundingBoxComputation | [LLM] |
| 0054f830 | VertexParticleBufferAllocator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
