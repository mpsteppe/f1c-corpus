## CameraPositionDefinitions_00408870 — CameraViewDefinitionInitializer

**Summary:** Initializes four 3D camera/sound-emitter view definition objects (2-seater, 3-seater, left-of-pits, right-of-pits) with preset FOV, near/far clip, view angles, and positional offsets for the camera system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraViewSystem (00408e20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x24) | 0x0 | R | — | vtable pointer of existing 2-seater view object (call release if non-null) |
| *(this+0x28) | 0x0 | R | — | vtable pointer of existing 3-seater view object (call release if non-null) |
| *(this+0x2C) | 0x0 | R | — | vtable pointer of existing left-of-pits view object (call release if non-null) |
| *(this+0x30) | 0x0 | R | — | vtable pointer of existing right-of-pits view object (call release if non-null) |
| this | 0x24 | RW | — | pointer to 2-seater F_3DSoundEmitter camera definition object |
| this | 0x28 | RW | — | pointer to 3-seater F_3DSoundEmitter camera definition object |
| this | 0x2C | RW | — | pointer to left-of-pits F_3DSoundEmitter camera definition object |
| this | 0x30 | RW | — | pointer to right-of-pits F_3DSoundEmitter camera definition object |
| this | 0x54 | RW | 1114636288 → 60.0f | camera vertical FOV (degrees) |
| this | 0x58 | RW | 1114636288 → 60.0f | camera horizontal FOV (degrees) |
| this | 0x5C | RW | 1114636288 → 60.0f | near clip distance |
| this | 0x60 | RW | 1114636288 → 60.0f | far clip distance |
| this | 0x64 | RW | 1110704128 → 45.0f | secondary FOV angle |
| this | 0x68 | RW | 1114636288 → 60.0f | alternate clip distance |
| this | 0x6C | RW | 1110704128 → 45.0f | view angle parameter |
| this | 0x70 | RW | 1045220557 → 0.2f | near-plane offset fraction |
| this | 0x74 | RW | 1140457472 → 500.0f | maximum view distance |
| this | 0x78 | RW | 1065353216 → 1.0f | view scale X |
| this | 0x7C | RW | 1065353216 → 1.0f | view scale Y |
| this | 0x80 | RW | 1065353216 → 1.0f | view scale Z |
| this | 0x84 | RW | 1056964608 → 0.5f | view offset fraction X |
| this | 0x88 | RW | 1056964608 → 0.5f | view offset fraction Y |
| this | 0x8C | RW | 1 | enabled flag (byte) |
| this | 0x90 | RW | 1 | unknown boolean flag |
| this | 0x94 | RW | 0 | reserved/unused int |
| this | 0x98 | RW | 0 | reserved/unused int |
| this | 0x9C | RW | 0 | reserved/unused int |
| this | 0xA0 | RW | 0 | reserved/unused int |
| this | 0xA4 | RW | 0 | reserved/unused int |
| this | 0xA8 | RW | 0 | reserved/unused int |
| this | 0xAC | RW | 0 | reserved/unused int |
| this | 0xB0 | RW | 0 | reserved/unused int (or 10.0f for pit views) |
| this | 0xB4 | RW | 1092616192 → 10.0f | view angle range parameter |
| this | 0xB8 | RW | 1073741824 → 2.0f | view position offset X multiplier |
| this | 0xBC | RW | 1053609165 → 0.4f | view position offset Y multiplier |
| this | 0xC0 | RW | 1073741824 → 2.0f | view position offset Z multiplier |
| this | 0xC4 | RW | 1054347463 → 0.422f | view orientation angle (radians) |
| this | 0xC8 | RW | 18446744072596547348 → -0.0825f | view position fine-adjust X |
| this | 0xCC | RW | 18446744072619746430 → -0.5425f | view position fine-adjust Y |
| this | 0xD0 | RW | 18446744072620353312 → -0.5787f | view position fine-adjust Z |
| this | 0xD4 | RW | 18446744072620194113 → -0.5692f | view target offset X |
| this | 0xD8 | RW | 18446744072568828166 → -0.0079f | view target offset Y |

**Written-by note (persistence):**
- this 0x24: written once on initialization; external poke overwritten next call (old pointer released first)
- this 0x28: written once on initialization; external poke overwritten next call (old pointer released first)
- this 0x2C: written once on initialization; external poke overwritten next call (old pointer released first)
- this 0x30: written once on initialization; external poke overwritten next call (old pointer released first)
- this 0x54: written once per init; external poke persists until next init call
- this 0x58: written once per init; external poke persists until next init call
- this 0x5C: written once per init; external poke persists until next init call
- this 0x60: written once per init; external poke persists until next init call
- this 0x64: written once per init; external poke persists until next init call
- this 0x68: written once per init; external poke persists until next init call
- this 0x6C: written once per init; external poke persists until next init call
- this 0x70: written once per init; external poke persists until next init call
- this 0x74: written once per init; external poke persists until next init call
- this 0x78: written once per init; external poke persists until next init call
- this 0x7C: written once per init; external poke persists until next init call
- this 0x80: written once per init; external poke persists until next init call
- this 0x84: written once per init; external poke persists until next init call
- this 0x88: written once per init; external poke persists until next init call
- this 0x8C: written once per init; external poke persists until next init call
- this 0x90: written once per init; external poke persists until next init call
- this 0x94: written once per init; external poke persists until next init call
- this 0x98: written once per init; external poke persists until next init call
- this 0x9C: written once per init; external poke persists until next init call
- this 0xA0: written once per init; external poke persists until next init call
- this 0xA4: written once per init; external poke persists until next init call
- this 0xA8: written once per init; external poke persists until next init call
- this 0xAC: written once per init; external poke persists until next init call
- this 0xB0: written once per init; external poke persists until next init call
- this 0xB4: written once per init; external poke persists until next init call
- this 0xB8: written once per init; external poke persists until next init call
- this 0xBC: written once per init; external poke persists until next init call
- this 0xC0: written once per init; external poke persists until next init call
- this 0xC4: written once per init; external poke persists until next init call
- this 0xC8: written once per init; external poke persists until next init call
- this 0xCC: written once per init; external poke persists until next init call
- this 0xD0: written once per init; external poke persists until next init call
- this 0xD4: written once per init; external poke persists until next init call
- this 0xD8: written once per init; external poke persists until next init call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be8b0 | a2seater | R | TwoSeaterString [DERIVED] |
| 005be8b8 | a3seater | R | String_3Seater [DERIVED] |
| 005be8c0 | aLeftOfPits | R | TrackPitExit_LeftOfPits [DERIVED] |
| 005be8d0 | aRightOfPits | R | RightOfPitsField [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456170 | F_3DSoundEmitter | construct a 3D sound emitter / camera view definition object |
| 00456fb0 | ClampedFloatSetter | set a float value with input clamping |
| 00566650 | StringCopyWithBufferRealloc | copy string identifier with buffer reallocation |
| 00587c03 | OperatorNewNhMallocWrapper | allocate 200 bytes for new view definition object |

**Guard conditions:** No conditional branches based on field comparisons; each of the four view objects is unconditionally created if allocation succeeds. The only guard is null-pointer checks on existing objects before calling their destructors.
