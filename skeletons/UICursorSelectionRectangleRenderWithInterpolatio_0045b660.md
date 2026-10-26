## UICursorSelectionRectangleRenderWithInterpolatio_0045b660 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CollisionDamageDecayProcessor (0045b840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x324 | RW | — | [LLM] |
| this | 0x328 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x324: [LLM: once/conditional? does external poke survive?]
- this 0x328: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 0059e8c8 | flt_59E8C8 | R | Physics_ConvergenceThreshold [DERIVED] (also: ` — convergence threshold (terminates iteration) |
| 0059f078 | flt_59F078 | R | PenaltyScaleFactor [DERIVED] |
| 0059f088 | dbl_59F088 | R | ThresholdFloat [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045b5c0 | sub_45B5C0 | [LLM] |
| 0045bb00 | FloatArrayThresholdSearch | [LLM] |
| 00494c20 | FloatVectorWithConditionalTransform | [LLM] |
| 004dcd60 | ConditionalCall | [LLM] |
| 004dcda0 | FloatToIntConversionDispatch | [LLM] |
| 004dcee0 | sub_4DCEE0 | [LLM] |
| 004dcf30 | TwinFieldGetter_cf30 | [LLM] |
| 004dcf50 | TripleFieldGetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
