## sub_65EDD0_0065edd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_660C6A (00660c6a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | RW | — | [LLM] |
| this | 0x44 | RW | — | [LLM] |
| this | 0x48 | RW | — | [LLM] |
| this | 0x54 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x44: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x48: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x54: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00737e10 | off_737E10 | R | [LLM] |
| 00737e14 | dword_737E14 | R | [LLM] |
| 00737e18 | dword_737E18 | R | [LLM] |
| 007394b0 | dword_7394B0 | R | [LLM] |
| 00739c78 | aTexcoord_0 | R | [LLM] |
| 00739e30 | aLe | R | [LLM] |
| 00739e34 | aNe | R | [LLM] |
| 00739e38 | aLt | R | [LLM] |
| 00739e3c | aGe | R | [LLM] |
| 00739e40 | aEq | R | [LLM] |
| 00739e44 | aGt | R | [LLM] |
| 00739e48 | aSample_0 | R | [LLM] |
| 00739e50 | aDepth_0 | R | [LLM] |
| 00739e58 | off_739E58 | R | [LLM] |
| 00739e5c | aColor_1 | R | [LLM] |
| 00739e64 | aPositiont_0 | R | [LLM] |
| 00739e70 | aTessfactor_0 | R | [LLM] |
| 00739e7c | aBinormal_0 | R | [LLM] |
| 00739e88 | aTangent_0 | R | [LLM] |
| 00739e90 | aPsize_0 | R | [LLM] |
| 00739e98 | aNormal_1 | R | [LLM] |
| 00739ea0 | aBlendindices_0 | R | [LLM] |
| 00739eb0 | aBlendweight_0 | R | [LLM] |
| 00739ebc | aPosition_0 | R | [LLM] |
| 00739ec8 | aPp | R | [LLM] |
| 00739ecc | aVolume_0 | R | [LLM] |
| 00739ed4 | aCube | R | [LLM] |
| 00739edc | a2d_0 | R | [LLM] |
| 00739ee0 | aD8 | R | [LLM] |
| 00739ee4 | aD4 | R | [LLM] |
| 00739ee8 | aD2 | R | [LLM] |
| 00739eec | aX2 | R | [LLM] |
| 00739ef0 | aX4 | R | [LLM] |
| 00739ef4 | aX8 | R | [LLM] |
| 00739ef8 | aCentroid | R | [LLM] |
| 00739f04 | off_739F04 | R | [LLM] |
| 01000000 | dword_1000000 | R | [LLM] |
| 016c979c | off_16C979C | R | [LLM] |
| 02000000 | dword_2000000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00631abd | j__atol | [LLM] |
| 00633848 | sub_633848 | [LLM] |
| 00633887 | StringComparisonWithConstantDispatch [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `texcoord`
- `texcoord`
- `sample`
- `sample`
- `depth`
- `depth`
- `fog`
- `fog`
- `color`
- `color`
- `positiont`
- `positiont`
- `tessfactor`
- `tessfactor`
- `binormal`
- `binormal`
- `tangent`
- `tangent`
- `psize`
- `psize`
- … +12 more
