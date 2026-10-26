## GameMode_0046d6d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x40 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0046d7d0 | jpt_46D704 | R | [LLM] |
| 005c5f5c | aMpclientgrid | R | MpClientGrid [DERIVED] |
| 005c65ec | aSelectcircuitp | R | SelectCircuitPrompt [DERIVED] |
| 005c6bf8 | aChResume | R | [LLM] |
| 005cc9e8 | dword_5CC9E8 | W | SessionInitState [CONFIRMED] (also: ` — multiplayer active flag) |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004186a0 | BufferInitWith10fDefaults | [LLM] |
| 00461550 | FAILWRONGDESCRIPTION | [LLM] |
| 00461900 | SessionConfigWriteback | [LLM] |
| 00461cd0 | SessionStateCheck | [LLM] |
| 004627c0 | NetworkEntrantSetupWithIDCheck | [LLM] |
| 00477640 | SeasonSceneNameAccessor | [LLM] |
| 00477680 | TrackSceneConfigLoader | [LLM] |
| 00486aa0 | GuardedFunctionDispatch | [LLM] |
| 00497940 | LookupDispatch | [LLM] |
| 004a0630 | SessionSceneInitChain | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
