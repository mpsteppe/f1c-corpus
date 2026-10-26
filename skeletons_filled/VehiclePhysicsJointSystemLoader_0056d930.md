## VehiclePhysicsJointSystemLoader_0056d930 — Physics Joint System File Parser and Solver Initializer

**Summary:** Parses a vehicle physics joint-system configuration file (bodies, joints, hinges, bars), allocates arrays for each entity type, populates their geometric/constraint data, and initializes the physics solver matrix. Part of the vehicle physics joint-constraint system loader.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehiclePhysicsBodyNameMapping (00438da0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | body count (incremented per "Body" keyword) |
| this | 0x4 | RW | — | body array pointer (580-byte entries each) |
| this | 0x8 | RW | 0 | joint count (incremented per "Joint" keyword) |
| this | 0xC | RW | — | joint array pointer (48-byte entries each) |
| this | 0x10 | RW | 0 | hinge count (incremented per "Hinge" keyword) |
| this | 0x14 | RW | — | hinge array pointer (48-byte entries each) |
| this | 0x18 | RW | 0 | bar count (incremented per "Bar" keyword) |
| this | 0x1C | RW | — | bar array pointer (72-byte entries each) |
| this | 0x20 | RW | — | total DOF/entity count (returned by sub_56D430) |
| this | 0x24 | RW | 0 | solver matrix buffer (8 * N * N bytes, N = DOF count) |
| this | 0x28 | RW | — | matrix row-pointer array (4 * N bytes) |
| this | 0x2C | RW | — | solver solution/result vector (8 * N bytes) |
| this | 0x30 | RW | 0 | solver instance pointer (from sub_579F89, NULL if not found) |

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
| 00534b00 | sub_534B00 | open file / initialize stream (returns file handle) |
| 005351d0 | LineInputReader | read next line from file into buffer |
| 00535390 | AudioStreamBufferRead | seek/reset stream to beginning |
| 005355a0 | StreamFileTypeCheckWithDispatch | close file stream / finalize |
| 005651b0 | sub_5651B0 | check if line is a section header/separator token |
| 00565520 | sub_565520 | parse key=value from line (name lookup, writes to dest) |
| 00565aa0 | sub_565AA0 | parse numeric vector/array from line (up to 3 components) |
| 00568e30 | ShortComputation_8e30 | initialize body entry to default values |
| 00568e70 | sub_568E70 | set body properties: name string, mass, inertia tensor |
| 005691d0 | F_3x3RotationTensorMatrixTransform | transform 3x3 rotation/inertia matrix by body orientation |
| 00569280 | Copy6DwordsToStructCall | copy 24 bytes (6 dwords) into struct field |
| 005697f0 | TripleBufferAllocation | allocate body's internal triple-buffer data |
| 00569860 | F_3DPositionDeltaToBodyFrameVectorTransform | transform position delta to body-local frame |
| 005698e0 | BufferEntryAppendWithMatrixInit | append entry to joint/hinge buffer with rotation matrix init |
| 00569990 | F_3DVectorTransformWithBufferWrite | transform 3D vector and write to buffer |
| 0056c830 | sub_56C830 | compute solver constraint matrix entries (LCP setup) |
| 0056cf70 | F_3x3MatrixVectorMultiply | multiply 3x3 matrix by 3D vector |
| 0056d020 | F_3x3MatrixInverseCoordinateTransform | inverse coordinate transform via 3x3 rotation matrix |
| 0056d2d0 | sub_56D2D0 | setup bar-specific constraint data (position/velocity anchors) |
| 0056d430 | sub_56D430 | compute total DOF count from body/joint/hinge/bar counts |
| 0056d880 | ZeroFillArraysAndCallInitRoutineRepeatedly | zero-fill solver matrix and vectors, initialize repeatedly |
| 0056d8f0 | sub_56D8F0 | error cleanup: free all allocated memory, close file |
| 0056e970 | sub_56E970 | reset/clear internal state before parsing |
| 00579f89 | sub_579F89 | get physics solver object by index (iterates solver registry) |
| 00587bcf | FreeWrapper_7bcf | memory free wrapper (null-check + free) |
| 00587c03 | OperatorNewNhMallocWrapper | allocate memory with operator new, null-check |
| 00587c20 | sub_587C20 | string comparison / keyword match (case-insensitive prefix) |
| 0058815f | StringFormatWithBufferOverflowCheck | formatted string with buffer overflow protection |
| 00588410 | sub_588410 | exact string equality check (case-sensitive compare) |
| 0058986e | FileDeleteWithErrorHandling | delete file (error log), handle failure silently |
| 00589901 | sub_589901 | copy/trim string (strips whitespace or copies to buffer) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | > | 0 | body count > 0: gate body array iteration |
| this | 0x8 | > | 0 | joint count > 0: gate joint array iteration |
| this | 0x10 | > | 0 | hinge count > 0: gate hinge array iteration |
| this | 0x18 | > | 0 | bar count > 0: gate bar array iteration |

**Guard interpretation:** All guards test if the entity count is positive before iterating over the corresponding allocated array. PASSES when count > 0 (entities exist, loop body executes). BLOCKED/SKIPPED when count == 0 (no entities of that type, loop body skipped entirely).
