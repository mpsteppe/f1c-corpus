## MouseInputHandler_0045f030 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0x1B780)+0x4)+0x0) | 0x0 | R | — | [LLM] |
| *(*(this+0x1B780)+0x4) | 0x0 | R | — | [LLM] |
| *(*(this+0x1B780)+0x4) | 0x4 | R | — | [LLM] |
| this | 0x384 | RW | — | [LLM] |
| this | 0x1B780 | R | — | [LLM] |
| this | 0x1B78C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x384: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0045f278 | jpt_45F095 | R | [LLM] |
| 0059f114 | flt_59F114 | R | AIOvertakeDetection [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cb21c | word_7CB21C | R | InputActionMap [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045bc50 | StringCopyWithFormatQuery | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 00462250 | TextureCreationWrapper | [LLM] |
| 004a0df0 | SessionStateDispatch | [LLM] |
| 004b0b20 | sub_4B0B20 | [LLM] |
| 004b33b0 | ProgressBarEventEncode | [LLM] |
| 00587dd0 | sub_587DD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
