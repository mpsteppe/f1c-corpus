## SuspensionSetupSectionReader_00435410 — SuspensionSetupSectionReader

**Summary:** Reads suspension setup configuration from a file section: parses spring parameters (collision length, stiffness/damping, direction, head/body anchors), head mass/inertia, and min/max position/orientation limits into the vehicle suspension data structure.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_438F00 (00438f00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xAC | RW | — | head mass (double) |
| obj | 0xB4 | RW | — | reciprocal of head mass (1.0/headMass) |
| this | 0x0 | RW | — | setup/vehicle index ID |
| this | 0x4 | R | — | spring body anchor position X (double, from a4) |
| this | 0xC | R | — | spring body anchor position Y (double, from a4) |
| this | 0x14 | R | — | spring body anchor position Z (double, from a4) |
| this | 0x64 | RW | — | min orientation X (radians, converted from degrees) |
| this | 0x6C | RW | — | min orientation Y (radians, converted from degrees) |
| this | 0x74 | RW | — | min orientation Z (radians, converted from degrees) |
| this | 0x7C | RW | — | max orientation X (radians, converted from degrees) |
| this | 0x84 | RW | — | max orientation Y (radians, converted from degrees) |
| this | 0x8C | RW | — | max orientation Z (radians, converted from degrees) |
| this | 0x94 | RW | — | spring array capacity (allocated count) |
| this | 0x98 | R | — | current spring count |
| this | 0x9C | RW | — | pointer to spring data array (100 bytes per spring) |

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
| 00435390 | CategoryScoringStateInitializer | initialize one spring data entry (100 bytes) to zero/default |
| 004358f0 | PhysicsBufferClear | clear physics scratch buffer before parsing |
| 005651b0 | sub_5651B0 | read next configuration line/token from file |
| 00565520 | sub_565520 | parse a named section from the configuration stream |
| 00565aa0 | sub_565AA0 | parse a named numeric field (up to 4 doubles) from config |
| 005668b0 | ZeroInitSmallStruct | zero-initialize small local struct |
| 005668d0 | SubCallWithConditionalFieldFree | cleanup scratch struct and free conditional resources |
| 00566b20 | AudioStreamOpen | open configuration file/stream for reading |
| 00566cc0 | ConditionalDispatchBasedOnFlag | check buffer bounds / read more data if needed |
| 005697a0 | StructCopyWithReciprocalDivision | copy inertia values with reciprocal division |
| 0056bd40 | EulerAnglesTo33RotationMatrix | convert Euler angles to 3x3 rotation matrix |
| 00587bcf | FreeWrapper_7bcf | free previously allocated spring array memory |
| 00587c03 | OperatorNewNhMallocWrapper | allocate new spring array (100 * capacity bytes) |
| 00588410 | sub_588410 | string comparison helper for spring type classification |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x98 | > | 0 | current spring count > 0: PASSES enables per-spring parameter parsing (direction, head, body, collision length, params) |

**Guard interpretation:** If spring count (this+0x98) > 0, the last-added spring's parameters are parsed (spring direction, head/body world positions via rotation matrix transform, collision length, stiffness/damping params). If count is 0, the per-spring parsing BLOCKED (skipped) and the loop continues to next config line.
