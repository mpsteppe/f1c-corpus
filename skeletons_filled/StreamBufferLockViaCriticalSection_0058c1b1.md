## StreamBufferLockViaCriticalSection_0058c1b1 — Stream critical section enter dispatch

**Summary:** Enters the critical section guarding a file stream. For streams in the CRT global array, computes index from array offset and uses lazy-init indexed CS. For external streams (outside array range), calls EnterCriticalSection on embedded CRITICAL_SECTION at offset +0x20.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FileReadUntilNewline (00587ca0), FileCloseWithLock (00587d02), sub_587F64 (00587f64), ThreadSafeReadWrapper_803f (0058803f), FileReadWrapperWithLock (00588678), StringFormatWithNestedIO (005887b1), BufferedCharacterWriteWithOverflowHandling (00589898), StreamGetcWithUnderflowHandler (00589fcc), LockCallUnlockWrapper (00589ffd), FileWriteWrapperWithLock (0058a163), FileSizeQueryWrapper (0058ace6), sub_58AFE1 (0058afe1), StringWriteToFile (0058babb), FileIOThreeStepSequence (0058c7fc), FileIOWrapperWithLock (0059685f), sub_59BB00 (0059bb00), ThreeStepStreamQuery (0059bbaf), StreamReadWrapperWithLockUnlock (0059bcd2), IOFormatWrapper (0059bde9), ThreadSafeWrapper (0059c127)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e174 | EnterCriticalSection | R | Win32 EnterCriticalSection function pointer |
| 005e6748 | off_5E6748 | R | Base address of CRT's internal file stream array |
| 005e69a8 | unk_5E69A8 | R | End bound of CRT's internal file stream array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058dfea | CriticalSectionLazyInitEnter | Enter lazy-initialized critical section by index (for CRT array streams) |

**Guard conditions:** If a1 is within [off_5E6748, unk_5E69A8] (CRT's global stream array range), computes CS index as ((a1 - base) >> 5) + 28 and uses lazy-init path. If outside that range (user-allocated or external stream), calls EnterCriticalSection directly on the CRITICAL_SECTION at a1+32.
