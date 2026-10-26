## StreamBufferLockViaCriticalSection_0058c1b1 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FileReadUntilNewline (00587ca0), FileCloseWithLock (00587d02), sub_587F64 (00587f64), ThreadSafeReadWrapper_803f (0058803f), FileReadWrapperWithLock (00588678), StringFormatWithNestedIO (005887b1), BufferedCharacterWriteWithOverflowHandling (00589898), StreamGetcWithUnderflowHandler (00589fcc), LockCallUnlockWrapper (00589ffd), FileWriteWrapperWithLock (0058a163), FileSizeQueryWrapper (0058ace6), sub_58AFE1 (0058afe1), StringWriteToFile (0058babb), FileIOThreeStepSequence (0058c7fc), FileIOWrapperWithLock (0059685f), sub_59BB00 (0059bb00), ThreeStepStreamQuery (0059bbaf), StreamReadWrapperWithLockUnlock (0059bcd2), IOFormatWrapper (0059bde9), ThreadSafeWrapper (0059c127)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e174 | EnterCriticalSection | R | [LLM] |
| 005e6748 | off_5E6748 | R | DynamicsVTable [DERIVED] |
| 005e69a8 | unk_5E69A8 | R | CriticalSectionRegionEnd [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
