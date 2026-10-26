## RaySphereIntersectionTest_004dc960 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 008b8f24 | dword_8B8F24 | R | D3DDeviceWrapperPtr [DERIVED] (also: ` — D3D device wrapper / scene manager singleton vtable (docs/22) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00542400 | StructFieldArrayCopy | [LLM] |
| 00542460 | TripleFieldGetter_2460 | [LLM] |
| 005424e0 | sub_5424E0 | [LLM] |
| 005425a0 | ViewportPositionClamping | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
