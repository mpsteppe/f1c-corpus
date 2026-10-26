## AddressRangeCriticalSectionLeave_0058c203 — Stream critical section leave dispatch

**Summary:** Leaves the critical section protecting a file stream. Mirror of StreamBufferLockViaCriticalSection: for CRT global array streams uses indexed CritSectLeave; for external streams calls LeaveCriticalSection on embedded CRITICAL_SECTION at offset +0x20.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** FileReadUntilNewline (00587ca0), FileCloseWithLock (00587d02), sub_587D7F (00587d7f), sub_587F64 (00587f64), ThreadSafeReadWrapper_803f (0058803f), FileReadWrapperWithLock (00588678), StringFormatWithNestedIO (005887b1), BufferedCharacterWriteWithOverflowHandling (00589898), StreamGetcWithUnderflowHandler (00589fcc), LockCallUnlockWrapper (00589ffd), FileWriteWrapperWithLock (0058a163), FileSizeQueryWrapper (0058ace6), sub_58AE69 (0058ae69), sub_58AFE1 (0058afe1), StringWriteToFile (0058babb), FileIOThreeStepSequence (0058c7fc), FileIOWrapperWithLock (0059685f), sub_59BB00 (0059bb00), ThreeStepStreamQuery (0059bbaf), StreamReadWrapperWithLockUnlock (0059bcd2), IOFormatWrapper (0059bde9), ThreadSafeWrapper (0059c127)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e170 | LeaveCriticalSection | R | Win32 LeaveCriticalSection function pointer |
| 005e6748 | off_5E6748 | R | Base address of CRT's internal file stream array |
| 005e69a8 | unk_5E69A8 | R | End bound of CRT's internal file stream array |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058e04b | CritSectLeave | Leave lazy-initialized critical section by index (for CRT array streams) |

**Guard conditions:** If a1 is within [off_5E6748, unk_5E69A8] (CRT's global stream array), computes CS index as ((a1 - base) >> 5) + 28 and uses indexed CritSectLeave. If outside range (external stream), calls LeaveCriticalSection on the embedded CRITICAL_SECTION at a1+32.
