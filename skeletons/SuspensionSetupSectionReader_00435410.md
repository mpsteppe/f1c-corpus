## SuspensionSetupSectionReader_00435410 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_438F00 (00438f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xAC | RW | — | [LLM] |
| obj | 0xB4 | RW | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x7C | RW | — | [LLM] |
| this | 0x84 | RW | — | [LLM] |
| this | 0x8C | RW | — | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0x98 | R | — | [LLM] |
| this | 0x9C | RW | — | [LLM] |

**Written-by note (persistence):**
- obj 0xAC: recalc every frame — external poke does NOT persist
- obj 0xB4: recalc every frame — external poke does NOT persist
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x64: recalc every frame — external poke does NOT persist
- this 0x6C: recalc every frame — external poke does NOT persist
- this 0x74: recalc every frame — external poke does NOT persist
- this 0x7C: recalc every frame — external poke does NOT persist
- this 0x84: recalc every frame — external poke does NOT persist
- this 0x8C: recalc every frame — external poke does NOT persist
- this 0x94: recalc every frame — external poke does NOT persist
- this 0x9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059eae8 | dbl_59EAE8 | R | PhysicsDoubleConst_59EAE8 [DERIVED] |
| 005c4098 | aSpringparams | R | SpringParams [DERIVED] |
| 005c40a8 | aSpringcolllen | R | SpringCollLenField [DERIVED] |
| 005c40b8 | aSpringbody | R | SpringBodyString [DERIVED] |
| 005c40c4 | aSpringhead | R | SpringheadString [DERIVED] |
| 005c40d0 | aSpringdir | R | SpringDirString [DERIVED] |
| 005c40dc | aFreedamping | R | Str_FreeDamping [DERIVED] |
| 005c40e8 | aNormal | R | StringNormal [DERIVED] |
| 005c40f0 | aSliding | R | StringSliding [DERIVED] |
| 005c40f8 | aSpring | R | SpringString [DERIVED] |
| 005c4100 | aMaxori | R | MaxOriString [DERIVED] |
| 005c4108 | aMinori | R | MinoriString [DERIVED] |
| 005c4110 | aMaxpos | R | MaxPosConfigStr [DERIVED] |
| 005c4118 | aMinpos | R | MinPosString [DERIVED] |
| 005c4120 | aHeadinertia | R | HeadInertiaField [DERIVED] |
| 005c412c | aHeadmass | R | SetupParam_HeadMass [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00435390 | CategoryScoringStateInitializer | [LLM] |
| 004358f0 | PhysicsBufferClear | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00565aa0 | sub_565AA0 | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566b20 | AudioStreamOpen | [LLM] |
| 00566cc0 | ConditionalDispatchBasedOnFlag | [LLM] |
| 005697a0 | StructCopyWithReciprocalDivision | [LLM] |
| 0056bd40 | EulerAnglesTo33RotationMatrix | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x98 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
