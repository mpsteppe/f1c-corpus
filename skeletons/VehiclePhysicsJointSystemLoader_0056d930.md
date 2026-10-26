## VehiclePhysicsJointSystemLoader_0056d930 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsBodyNameMapping (00438da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | 0 | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | 0 | [LLM] |
| this | 0x1C | RW | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x2C | RW | — | [LLM] |
| this | 0x30 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x4: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x1C: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x2C: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c36f0 | aR | R | Token_R [DERIVED] |
| 005e5248 | aPmodelErrorTxt | R | StringPmodelErrorTxt [DERIVED] |
| 005e5260 | aInvalidBodyNam | R | String_InvalidBodyNam [DERIVED] |
| 005e528c | aInvalidCopyBod | R | InvalidCopyBodyString [DERIVED] |
| 005e52bc | aTwoBodiesNamed | R | TwoBodiesNamedString [DERIVED] |
| 005e52d4 | aBodyDMustBeNam | R | BodyDMustBeNamedString [DERIVED] |
| 005e52ec | off_5E52EC | R | VTable_FUN_0056d930 [DERIVED] |
| 005e52f0 | aAxis | R | aAxis [DERIVED] |
| 005e52f8 | aNegbody | R | NegBody [DERIVED] |
| 005e5300 | aPosbody | R | PosBodyField [DERIVED] |
| 005e5308 | off_5E5308 | R | MemoryOpJumpTable [DERIVED] |
| 005e530c | off_5E530C | R | VTablePtr12 [DERIVED] |
| 005e5310 | off_5E5310 | R | FileOpVTable [DERIVED] |
| 005e5314 | off_5E5314 | R | Ptr_VTable_5E5314 [DERIVED] |
| 005e5318 | aInertia_0 | R | StringInertia [DERIVED] |
| 005e5320 | aMass_0 | R | MassString [DERIVED] |
| 005e5328 | aName_0 | R | NameString [DERIVED] |
| 005e5330 | aJointHinge | R | JointHingeString [DERIVED] |
| 005e5340 | aBar | R | BarStr [DERIVED] |
| 005e5348 | aHinge | R | HingeString [DERIVED] |
| 005e5350 | aJoint | R | JointField [DERIVED] |
| 005e5358 | aBody_1 | R | StrBody [DERIVED] |
| 005e5360 | aCouldNotOpenS_0 | R | String_CouldNotOpenS_0 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534b00 | sub_534B00 | [LLM] |
| 005351d0 | LineInputReader | [LLM] |
| 00535390 | AudioStreamBufferRead | [LLM] |
| 005355a0 | StreamFileTypeCheckWithDispatch | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00565520 | sub_565520 | [LLM] |
| 00565aa0 | sub_565AA0 | [LLM] |
| 00568e30 | ShortComputation_8e30 | [LLM] |
| 00568e70 | sub_568E70 | [LLM] |
| 005691d0 | F_3x3RotationTensorMatrixTransform | [LLM] |
| 00569280 | Copy6DwordsToStructCall | [LLM] |
| 005697f0 | TripleBufferAllocation | [LLM] |
| 00569860 | F_3DPositionDeltaToBodyFrameVectorTransform | [LLM] |
| 005698e0 | BufferEntryAppendWithMatrixInit | [LLM] |
| 00569990 | F_3DVectorTransformWithBufferWrite | [LLM] |
| 0056c830 | sub_56C830 | [LLM] |
| 0056cf70 | F_3x3MatrixVectorMultiply | [LLM] |
| 0056d020 | F_3x3MatrixInverseCoordinateTransform | [LLM] |
| 0056d2d0 | sub_56D2D0 | [LLM] |
| 0056d430 | sub_56D430 | [LLM] |
| 0056d880 | ZeroFillArraysAndCallInitRoutineRepeatedly | [LLM] |
| 0056d8f0 | sub_56D8F0 | [LLM] |
| 0056e970 | sub_56E970 | [LLM] |
| 00579f89 | sub_579F89 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 00588410 | sub_588410 | [LLM] |
| 0058986e | FileDeleteWithErrorHandling | [LLM] |
| 00589901 | sub_589901 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | [LLM] |
| this | 0x8 | > | 0 | [LLM] |
| this | 0x10 | > | 0 | [LLM] |
| this | 0x18 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
