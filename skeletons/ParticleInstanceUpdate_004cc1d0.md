## ParticleInstanceUpdate_004cc1d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x68 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005d3490 | flt_5D3490 | R | CockpitUIFloat [DERIVED] |
| 005d3494 | flt_5D3494 | R | PhysicsStepAccumulator [DERIVED] |
| 005ece1c | unk_5ECE1C | R | VEH[0].0x744 = coordinatesInTrack.x (replay) [CONFIRMED] |
| 007cf9ec | byte_7CF9EC | R | Byte_RendererFlag_F9EC [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ab6ec | dword_8AB6EC | R | ScoringDataPtr [DERIVED] |
| 008ac4e0 | flt_8AC4E0 | R | SceneObjectPool [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b9ce0 | Delegation | [LLM] |
| 004c9c70 | FindDriversInRange | [LLM] |
| 004cb5a0 | ArrayElementRemoval | [LLM] |
| 004cbdd0 | RaySphereIntersection | [LLM] |
| 00558c60 | TextureLayerFlagSet | [LLM] |
| 00558cb0 | ArrayElementFlagSetWithBoundsCheck | [LLM] |
| 00558cf0 | BoundsCheckedArrayWrite | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
