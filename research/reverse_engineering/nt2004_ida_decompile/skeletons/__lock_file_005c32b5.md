## __lock_file_005c32b5 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** FileReadUntilNewline [structural] (005be980), FileCloseWithLock [structural] (005be9e2), _fseek (005bec94), sub_5BED6F (005bed6f), _ftell (005bf3bf), _rewind (005bf542), sub_5BF5A6 (005bf5a6), StringFormatWithNestedIO [structural] (005bf6df), _fputc (005c07c8), StreamGetcWithUnderflowHandler [structural] (005c127c), LockCallUnlockWrapper [structural] (005c12ad), FileWriteWrapperWithLock [structural] (005c1413) … +8 more

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x20 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d51e8 | EnterCriticalSection | R | [LLM] |
| 006253f8 | off_6253F8 | R | [LLM] |
| 00625658 | stru_625658 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005c52b4 | CriticalSectionLazyInitEnter [structural] | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
