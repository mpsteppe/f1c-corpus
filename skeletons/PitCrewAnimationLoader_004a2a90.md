## PitCrewAnimationLoader_004a2a90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PITANIMSMASAnimationFileLoader (004a3220)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x14 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

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
| 004a21d0 | StringCopyWithReverse | [LLM] |
| 004a2220 | sub_4A2220 | [LLM] |
| 004a22d0 | sub_4A22D0 | [LLM] |
| 004a2770 | ModeDependentSubsystemCall | [LLM] |
| 004a27d0 | ConditionalDispatch_27d0 | [LLM] |
| 004a2a40 | QuoteStrippingCopy | [LLM] |
| 004a3320 | sub_4A3320 | [LLM] |
| 004a3440 | FlagBasedLoopConditionalCall | [LLM] |
| 004d1100 | ConditionalDelegateDispatch | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 0053c5b0 | StringRelocationCopy | [LLM] |
| 00543fa0 | VertexBufferResourceAllocation | [LLM] |
| 005450e0 | MeshResourceAllocator | [LLM] |
| 00545250 | ActorNodeLinkedListAppend | [LLM] |
| 00545930 | LinkedListNodeInsert_5930 | [LLM] |
| 0054c030 | FlagFieldBitManipulation | [LLM] |
| 0054c230 | LinkedListIndexedAccessor_c230 | [LLM] |
| 005651b0 | sub_5651B0 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 00587c20 | sub_587C20 | [LLM] |
| 00587ca0 | FileReadUntilNewline | [LLM] |
| 00587d02 | FileCloseWithLock | [LLM] |
| 00587db0 | sub_587DB0 | [LLM] |
| 00587f64 | sub_587F64 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 005887ed | StrlenFormatCallWrapper | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
