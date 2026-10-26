## sub_4B7DE0_004b7de0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x70C | R | — | [LLM] |
| this | 0x9A4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b8000 | jpt_4B7F31 | R | [LLM] |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 005be714 | FileName | R | serialization constant [DERIVED] |
| 005be718 | byte_5BE718 | R | HotlapDirPath [DERIVED] (also: ` � hot lap directory path) |
| 005c32d8 | word_5C32D8 | R | HotExtension (.HOT) [DERIVED] |
| 005d2454 | aSavingHotlap | R | SavingHotlapString [DERIVED] |
| 005d2464 | aHotLap | R | HotLapString [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 004a0e70 | SessionTypeGuard | [LLM] |
| 004b6a10 | VehicleForceAerodynamicsComputation | [LLM] |
| 004b7c80 | NetworkBufferRead | [LLM] |
| 005668b0 | ZeroInitSmallStruct | [LLM] |
| 005668d0 | SubCallWithConditionalFieldFree | [LLM] |
| 00566940 | sub_566940 | [LLM] |
| 00566b90 | ConditionalFileHandleCloseWithFlagDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
