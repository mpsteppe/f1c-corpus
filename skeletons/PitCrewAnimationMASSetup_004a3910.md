## PitCrewAnimationMASSetup_004a3910 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A4900 (004a4900)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x74) | 0x10 | R | — | [LLM] |
| *(this+0x74) | 0x2C | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x70 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x80 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x7C: [LLM: once/conditional? does external poke survive?]
- this 0x80: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] |
| 005cd480 | aPitanimsMas | R | StringPitAnimsMas [DERIVED] |
| 005cd490 | byte_5CD490 | R | UnknownByteConstant [DERIVED] |
| 005cd49c | aAnm | R | Ext_Anm [DERIVED] |
| 005cd4a4 | byte_5CD4A4 | R | UnknownByteFlag [DERIVED] |
| 005cd4b0 | aLeft | R | LeftString [DERIVED] |
| 005cd4b8 | aPits_0 | R | Str_Pits_0 [DERIVED] |
| 005cd4c0 | aPitguycMts | R | StringPitGuyCMts [DERIVED] |
| 005ea3ec | byte_5EA3EC | R | LeftHandPitFlag [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec420 | dword_5EC420 | R | TrackDir [DERIVED] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a1fd0 | RangeProportionInitializer | [LLM] |
| 004a21d0 | StringCopyWithReverse | [LLM] |
| 004a22d0 | sub_4A22D0 | [LLM] |
| 004a3b50 | Camera | [LLM] |
| 004a3fe0 | ShortComputation_3fe0 | [LLM] |
| 0053c800 | StringRegistry | [LLM] |
| 0053c900 | StringMatchWithFlagSet | [LLM] |
| 0053cbc0 | sub_53CBC0 | [LLM] |
| 0053ce40 | PhysicsObjectLinkedListRemoval | [LLM] |
| 005665b0 | sub_5665B0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x70 | > | 0 | [LLM] |
| this | 0x70 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
