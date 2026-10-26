## SessionMessageUICommandHandler_00470490 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |
| this | 0x304 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd834 | byte_7CD834 | R | TrackDB_Buffer_7CD834 [DERIVED] |
| 007cd84d | byte_7CD84D | W | FilmModeFlag [DERIVED] |
| 007cd860 | unk_7CD860 | R | TrackDataBuffer [DERIVED] |
| 007cd87f | byte_7CD87F | W | Byte_ReplayFlag [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bc50 | StringCopyWithFormatQuery | [LLM] |
| 00461db0 | SessionStateCheckWrapper | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 004979d0 | FieldGetter_79d0 | [LLM] |
| 004a0df0 | SessionStateDispatch | [LLM] |
| 004b0b20 | sub_4B0B20 | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x304 | == | 435 | [LLM] |
| this | 0x304 | == | 434 | [LLM] |
| this | 0x304 | == | 432 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
