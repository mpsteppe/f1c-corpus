## TeamRadioNetworkMessageProcessing_0045f710 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x388 | RW | 0 | [LLM] |
| this | 0x410 | R | — | [LLM] |
| this | 0x3E14 | R | — | [LLM] |
| this | 0x3FB8 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x388: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ef9a0 | dword_5EF9A0 | R | VEH[0].0x32C8 [LLM: field purpose] |
| 007c87a0 | dword_7C87A0 | R | SuspensionStatePtr [DERIVED] |
| 007cd2a8 | dword_7CD2A8 | R | Unknown_Menu_Struct_7CD2A8 [DERIVED] |
| 007d0e98 | dword_7D0E98 | R | Unknown_Flag_7D0E98 [DERIVED] |
| 007d0f04 | dword_7D0F04 | R | NetCommStateFlag [DERIVED] |
| 007d2e50 | dword_7D2E50 | R | SessionMsgCount [DERIVED] (also: ` — session message counter) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045c8f0 | CollisionContactSolver | [LLM] |
| 0045d890 | NetCommSessionMessageDispatcher | [LLM] |
| 00460c30 | LinearSearchIn104ElementArray | [LLM] |
| 00461440 | ReferencesGlobalState | [LLM] |
| 00461470 | ThunkToFUN00461480 | [LLM] |
| 004614c0 | TwoStageCheck | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 00462300 | SingleFunctionDispatch | [LLM] |
| 004651c0 | ResourceManagerFrameCleanup | [LLM] |
| 004652d0 | ShortComputation_52d0 | [LLM] |
| 00465300 | sub_465300 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004b3af0 | AdvanceRingBuffer | [LLM] |
| 004b3b30 | SessionDataCopy | [LLM] |
| 0057a730 | sub_57A730 | [LLM] |
| 0057a760 | SEHProtectedDataCopy | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
