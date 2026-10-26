## SceneNode_0055a910 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SceneFileTopLevelParser (0055b200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x13C | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e234 | InterlockedDecrement | R | [LLM] |
| 005c596c | aTrue | R | sTrue [DERIVED] |
| 005cd46c | aActor | R | StrActor [DERIVED] |
| 005cd5f4 | aShadowobject | R | ShadowObjectKey [DERIVED] |
| 005cd604 | aLodout | R | StringLODOut [DERIVED] |
| 005cd60c | aLodin | R | StringLODIn [DERIVED] |
| 005cd614 | aMeshfile | R | Key_MeshFile [DERIVED] |
| 005cd620 | aInstance | R | StringInstance [DERIVED] |
| 005dc228 | aOrient | R | String_Orient [DERIVED] |
| 005dc230 | off_5DC230 | R | ViewVTable [DERIVED] |
| 005dc2a0 | aResponse | R | ResponseString [DERIVED] |
| 005dc2ac | aHatactor | R | HatactorString [DERIVED] |
| 005dc2b8 | aPlanes | R | PlanesString [DERIVED] |
| 005dc2c0 | aSpecial2 | R | Str_Special2 [DERIVED] |
| 005dc2cc | aSpecial1 | R | StringSpecial1 [DERIVED] |
| 005dc2d8 | aChange | R | ChangeString [DERIVED] |
| 005dc2e0 | aRender | R | RenderString [DERIVED] |
| 005dc2e8 | aBillboard | R | BillboardString [DERIVED] |
| 005dc2f4 | aStamp | R | StampStr [DERIVED] |
| 005dc2fc | aMoveable | R | MoveableString [DERIVED] |
| 005dc308 | aLightobject | R | LightObjectField [DERIVED] |
| 005dc314 | aMorphtarget | R | StrMorphtarget [DERIVED] |
| 005dc320 | aReflector | R | String_Reflector [DERIVED] |
| 005dc32c | aShadowreceiver | R | ShadowReceiverString [DERIVED] |
| 005dc33c | aShadowcaster | R | ShadowcasterString [DERIVED] |
| 005dc34c | aZbuffer | R | ZBufferString [DERIVED] |
| 005dc354 | aSpheretarget | R | String_SphereTarget [DERIVED] |
| 005dc364 | aColltarget | R | aColltarget [DERIVED] |
| 005dc370 | aHattarget | R | HatTarget [DERIVED] |
| 005dc37c | aAutostart | R | AutostartField [DERIVED] |
| 005dc388 | aAnimfile | R | AnimFileString [DERIVED] |
| 005dc394 | aVisgroups | R | VisgroupsString [DERIVED] |
| 008b8ee0 | dword_8B8EE0 | R | AudioSystemFlags [DERIVED] |
| 008b8ee8 | dword_8B8EE8 | R | AudioBufferSize [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00545250 | ActorNodeLinkedListAppend | [LLM] |
| 00545930 | LinkedListNodeInsert_5930 | [LLM] |
| 00545f50 | AudioVolumeLoadComputation | [LLM] |
| 0054a600 | sub_54A600 | [LLM] |
| 0054a710 | TwoFunctionCallChain | [LLM] |
| 0054a730 | SelfCopyStringWithValidation | [LLM] |
| 0054a770 | SceneGraph | [LLM] |
| 0054b4d0 | sub_54B4D0 | [LLM] |
| 0054ba00 | DoublyLinkedListNodeMover | [LLM] |
| 0054bb40 | UIListNodeManager | [LLM] |
| 0054c110 | RenderFlagSetter | [LLM] |
| 0054d4e0 | ConditionalFloatFieldSetter | [LLM] |
| 00551480 | AudioFlagSet | [LLM] |
| 00551560 | sub_551560 | [LLM] |
| 00551790 | LinkedListStringKeyRemoval | [LLM] |
| 005518a0 | sub_5518A0 | [LLM] |
| 00559820 | sub_559820 | [LLM] |
| 005598b0 | sub_5598B0 | [LLM] |
| 00559a70 | LineReaderFromBuffer | [LLM] |
| 00559e20 | sub_559E20 | [LLM] |
| 00559f00 | sub_559F00 | [LLM] |
| 00559fb0 | PRNG4UniformFloatsFromSeed | [LLM] |
| 0055a910 | SceneNode | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
