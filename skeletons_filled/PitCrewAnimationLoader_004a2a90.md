## PitCrewAnimationLoader_004a2a90 — PitCrewAnimationFileParser

**Summary:** Parses pit crew animation definition files (.ANM): reads ACTOR/MESH/POSITION/MOVE/ROTATE directives, allocates actor entry array (120 bytes per actor, 30 dwords), maps wheel-on/off MTS meshes to mode-dependent subsystem calls, and initializes rendering resources.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PITANIMSMASAnimationFileLoader (004a3220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | loadedFlag (set to 1 when animation load completes successfully) |
| this | 0xC | RW | 0 | actorCount (this[3], incremented for each ACTOR directive parsed) |
| this | 0x10 | RW | — | actorArrayPtr (this[4], pointer to heap-allocated array of actor entries, 120 bytes each) |
| this | 0x14 | R | — | collisionGeometryHandle (this[5], passed to MeshResourceAllocator and ActorNodeLinkedListAppend) |

**Written-by note (persistence):**
- this 0x0: written once per file load — external poke survives until next load overwrites
- this 0xC: written once per file load — external poke survives until next load overwrites
- this 0x10: written once per file load — external poke survives until next load overwrites

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e65c | flt_59E65C | R | CameraShakeMultiplier [DERIVED] (also: ` — camera shake multiplier / conversion factor (docs/09, 19) |
| 0059e7d8 | dbl_59E7D8 | R | ThermalInflectionThreshold [DERIVED] (also: ` — inflection point threshold) |
| 005be690 | aRt | R | Str_RT [DERIVED] |
| 005c59d4 | aPosition | R | StrPosition [DERIVED] |
| 005cd174 | aDDevF119992002_2 | R | Str_DDevF119992002 [DERIVED] |
| 005cd33c | aUnableToSetupA | R | UnableToSetupAIString [DERIVED] |
| 005cd360 | aRotateF | R | RotateFString [DERIVED] |
| 005cd36c | aRotate | R | RotateString [DERIVED] |
| 005cd374 | aSAnm | R | SAnmStr [DERIVED] |
| 005cd37c | aMoveSSF | R | MoveSSFString [DERIVED] |
| 005cd38c | aMove | R | MoveField [DERIVED] |
| 005cd394 | aPositionFFF | R | PositionFFF [DERIVED] |
| 005cd3a8 | aRrwheelonMts | R | String_RrWheelOnMts [DERIVED] |
| 005cd3b8 | aRrwheeloffMts | R | RrwheeloffMtsString [DERIVED] |
| 005cd3c8 | aLrwheelonMts | R | LrwheelonMtsString [DERIVED] |
| 005cd3d8 | aLrwheeloffMts | R | LrWheelOffMtsString [DERIVED] |
| 005cd3e8 | aRfwheelonMts | R | String_RfWheelOnMts [DERIVED] |
| 005cd3f8 | aRfwheeloffMts | R | s_RFWheelOffMTS [DERIVED] |
| 005cd408 | aLfwheelonMts | R | LfWheelOnMts [DERIVED] |
| 005cd418 | aLfwheeloffMts | R | LfWheelOffMtsField [DERIVED] |
| 005cd428 | aMeshS | R | MeshFormatString [DERIVED] |
| 005cd430 | aMesh | R | MeshString [DERIVED] |
| 005cd438 | aDetailD | R | DetailDString [DERIVED] |
| 005cd444 | aDetail | R | Str_Detail [DERIVED] |
| 005cd44c | aLollipop | R | StringLollipop [DERIVED] |
| 005cd458 | aLman | R | LManString [DERIVED] |
| 005cd460 | aActorS | R | ActorSString [DERIVED] |
| 005cd46c | aActor | R | StrActor [DERIVED] |
| 005cd474 | aFuelrigMts | R | FuelRigMtsString [DERIVED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe88 | dword_8AFE88 | R | CollisionGeometryHandle [DERIVED] (also: ` — global collision geometry handle) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a21d0 | StringCopyWithReverse | Copies mesh string with reverse/transform into actor entry |
| 004a2220 | sub_4A2220 | Initializes one actor entry (120 bytes) to defaults |
| 004a22d0 | sub_4A22D0 | Processes MOVE directive: stores animation file reference and float param |
| 004a2770 | ModeDependentSubsystemCall | Dispatches wheel-on/off MTS mesh to appropriate subsystem (wheel index + on/off flag) |
| 004a27d0 | ConditionalDispatch_27d0 | Conditional dispatch per actor entry after load complete |
| 004a2a40 | QuoteStrippingCopy | Strips quotes from string and copies result |
| 004a3320 | sub_4A3320 | Post-load processing with two 12-byte buffers |
| 004a3440 | FlagBasedLoopConditionalCall | Loop-conditional call on this with flag |
| 004d1100 | ConditionalDelegateDispatch | Conditional delegate dispatch on player vehicle ptr |
| 004d7a50 | StringSplitLoop | String split for debug log check |
| 004d7aa0 | DebugLogWrite | Writes debug message on setup failure |
| 0053c5b0 | StringRelocationCopy | Copies/relocates string (called on vertex buffer failure) |
| 00543fa0 | VertexBufferResourceAllocation | Allocates vertex buffer resources for collision geometry |
| 005450e0 | MeshResourceAllocator | Allocates mesh resources for fuel rig MTS (20 entries) |
| 00545250 | ActorNodeLinkedListAppend | Appends collision geometry to actor linked list |
| 00545930 | LinkedListNodeInsert_5930 | Inserts node into linked list at index 0 |
| 0054c030 | FlagFieldBitManipulation | Manipulates flag/bit field with parameters |
| 0054c230 | LinkedListIndexedAccessor_c230 | Accesses linked list node by index, scales float field by 4.0 |
| 005651b0 | sub_5651B0 | Checks if line is section header or empty |
| 00587c03 | OperatorNewNhMallocWrapper | Allocates actor entry array (120*count+4 bytes) |
| 00587c20 | sub_587C20 | Case-insensitive string prefix match for directive detection |
| 00587ca0 | FileReadUntilNewline | Reads one line from animation file |
| 00587d02 | FileCloseWithLock | Closes file handle |
| 00587db0 | sub_587DB0 | Opens animation file for reading |
| 00587f64 | sub_587F64 | Seeks file to beginning (rewind for second pass) |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats ANM filename string |
| 005887ed | StrlenFormatCallWrapper | sscanf-style format string parsing from file line |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | > | 0 | actorCount (PASSES into per-actor dispatch loop; 0 actors = skip loop) |

**Guard interpretation:** this+0xC (actorCount) > 0: enters for-loop calling ConditionalDispatch_27d0 on each actor entry (stride 120 bytes, count = actorCount). If actorCount is 0, the dispatch loop is skipped entirely.
