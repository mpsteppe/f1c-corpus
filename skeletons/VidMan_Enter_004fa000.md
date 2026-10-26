## VidMan_Enter_004fa000 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** Game_Enter (0042d370)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d0 | CreateProcessA | R | [LLM] |
| 0059e0ec | GetModuleFileNameA | R | [LLM] |
| 005d6dc4 | aDDevF119992002_26 | R | PathPrefix [DERIVED] |
| 005d6e50 | byte_5D6E50 | R | FlagByte_5D6E50 [DERIVED] |
| 005d6e60 | byte_5D6E60 | R | AudioByteFlag [DERIVED] |
| 005d6e6c | aEnteredVidmanE | R | EnteredVidmanEString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |
| 005ec480 | dword_5EC480 | R | Setup_DirectoryPtr_5EC480 [DERIVED] |
| 005ec488 | dword_5EC488 | R | PlayerFile [DERIVED] |
| 005ec48c | dword_5EC48C | R | NetworkPortHandle [DERIVED] |
| 005ec4a4 | byte_5EC4A4 | RW | MessageActiveFlag [DERIVED] (also: ` — input config path) |
| 005ec4b4 | dword_5EC4B4 | R | Dword5EC4B4 [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 007ce2a0 | hinst | R | HInstance [DERIVED] (also: ` — DirectInput instance handle) |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007ce2dc | hWnd | R | HWnd [DERIVED] (also: ` — DirectInput device pointer) |
| 008ad25c | dword_8AD25C | R | DebugMessageBuffer [DERIVED] |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe74 | dword_8AFE74 | R | Net_PacketBufferIndex [DERIVED] |
| 008b78a0 | dword_8B78A0 | R | SoundManager [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |
| ff000000000053de | byte_FF000000000053DE | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00422be0 | sub_422BE0 | [LLM] |
| 00494690 | sub_494690 | [LLM] |
| 004a1200 | sub_4A1200 | [LLM] |
| 004d7a50 | StringSplitLoop | [LLM] |
| 004d7aa0 | DebugLogWrite | [LLM] |
| 004f9160 | UtilityFunction_9160 | [LLM] |
| 004f91b0 | GlobalGuardedFieldReader | [LLM] |
| 004f9310 | sub_4F9310 | [LLM] |
| 004f9420 | sub_4F9420 | [LLM] |
| 004f9f00 | ConditionalInit | [LLM] |
| 004f9f30 | ConditionalStateReset | [LLM] |
| 0053c680 | ThreeGlobalSetter | [LLM] |
| 0053d470 | SystemInitAllocatorWrapper | [LLM] |
| 0053d890 | IndexedArrayAccess_d890 | [LLM] |
| 0053d8e0 | sub_53D8E0 | [LLM] |
| 005408f0 | GraphicsConfigStateSetter | [LLM] |
| 005434a0 | sub_5434A0 | [LLM] |
| 0055c060 | CallWrapper_c060 | [LLM] |
| 0055c330 | sub_55C330 | [LLM] |
| 00568be0 | QPCTimerInitialization | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
