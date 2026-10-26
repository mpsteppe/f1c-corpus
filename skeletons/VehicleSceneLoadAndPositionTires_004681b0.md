## VehicleSceneLoadAndPositionTires_004681b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x134)+0x4C) | 0x4C | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | RW | — | [LLM] |
| this | 0x128 | R | — | [LLM] |
| this | 0x134 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xF0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 005be860 | aSS | R | PathFormatString [DERIVED] (also: ` â€” format string for path construction) |
| 005c6754 | aLftire | R | NodeNameLFTire [DERIVED] |
| 005c675c | aRftire | R | aRftire [DERIVED] |
| 005c6764 | aLrtire | R | LRTire [DERIVED] |
| 005c676c | aRrtire | R | TireName_RR [DERIVED] |
| 005c6774 | aMirror | R | String_Mirror [DERIVED] |
| 005c677c | aCockpit | R | Cockpit [DERIVED] |
| 005c6784 | aSSS_0 | R | sFormatPath [DERIVED] |
| 005c678c | aVviewScn | R | VviewScnString [DERIVED] |
| 005c6798 | aTmpvehicleScn | R | TmpvehicleScnString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d8 | dword_5EC3D8 | R | SeasonDir [DERIVED] |
| 005ec428 | dword_5EC428 | R | SeasonName [DERIVED] |
| 005ec440 | dword_5EC440 | R | SettingsDirectory [DERIVED] |
| 007cfe0c | dword_7CFE0C | R | VehicleSkinOverridePath [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040e1f0 | GlobalVectorOffsetUpdate | [LLM] |
| 00466300 | StateInitializerWithFlagCheck | [LLM] |
| 004ddf70 | ZeroInitWrapper | [LLM] |
| 004ddf90 | SceneFileTEAMDIRVEHDIRNOTSPINWriter | [LLM] |
| 00545340 | LinkedListNodeFinder | [LLM] |
| 005453a0 | EvaluateSceneNodeProperty | [LLM] |
| 0054b3f0 | OffsetDispatch | [LLM] |
| 0054b420 | TripleFieldQuery | [LLM] |
| 0054b450 | sub_54B450 | [LLM] |
| 0054c030 | FlagFieldBitManipulation | [LLM] |
| 005506a0 | sub_5506A0 | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |
| 0058986e | FileDeleteWithErrorHandling | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x128 | >= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
