## AIShiftPattern_0042b8d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_42C440 (0042c440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] (also: ` — UI/text handle) |
| 005c32a4 | off_5C32A4 | R | RegisteredDataPtr [DERIVED] (also: registered) |
| 005c32a8 | aHigh | R | RegisteredCtrlPtr [DERIVED] (also: registered) |
| 005c32b0 | aUpshifts | R | UpshiftsString [DERIVED] |
| 005c32bc | aDownshifts | R | DownshiftsConfigString [DERIVED] |
| 005c32c8 | aOn | R | UIStringHandle [DERIVED] (also: ` — UI/text handle (near VehicleCount) |
| 005c32cc | aDisallowed | R | DisallowedString [DERIVED] |
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007ce498 | byte_7CE498 | R | AutoLoadConfigFile [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 00438cc0 | BrakeBiasSetup | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 0045bdf0 | ShortComputation_bdf0 | [LLM] |
| 004b15d0 | BitmaskStateTest | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
