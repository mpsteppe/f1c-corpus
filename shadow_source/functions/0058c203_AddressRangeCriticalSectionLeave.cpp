// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058C203
// Canonical corpus name: AddressRangeCriticalSectionLeave
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AddressRangeCriticalSectionLeave_0058c203.c

void UnknownObject::AddressRangeCriticalSectionLeave()
{
    // Critical-section leave dispatch for file/stream objects. If the stream address a1 lies outside the CRT global stream array bounded by off_5E6748..unk_5E69A8, treats a1 as an external stream with an embedded CRITICAL_SECTION at offset +32 and calls LeaveCriticalSection on it. Otherwise a1 is inside the CRT stream array, so the slot index is computed as ((a1 - base) >> 5) + 28 and the lazy-initialized critical section is left through CritSectLeave(index). Mirror of the stream lock/unlock pair used by the CRT file I/O wrappers.
    // GUARD: Range check on a1: if a1 < 0x5E6748 (off_5E6748) or a1 > 0x5E69A8 (unk_5E69A8) take the external-stream branch; otherwise fall through to the CRT array-stream branch. [function:0x0058C203, source:raw, global:0x005E6748, global:0x005E69A8]
    // CALL: External stream: call LeaveCriticalSection (0x0059E170) on the embedded CRITICAL_SECTION located at a1 + 32. [source:raw, global:0x0059E170]
    // CALCULATION: Array stream: compute the CRT stream slot index as ((int)(a1 - 0x5E6748) >> 5) + 28, using 0x20 (32) as the array element stride and 28 as the index base. [source:raw, global:0x005E6748]
    // CALL: Array stream: call CritSectLeave (0x0058E04B) with the computed slot index to leave the lazy-initialized critical section. [source:raw, callee:0x0058E04B]
    // CALL: Called by file/stream I/O wrappers to release the stream lock after read/write/format operations: FileReadUntilNewline (0x00587CA0), FileCloseWithLock (0x00587D02), sub_587D7F (0x00587D7F), sub_587F64 (0x00587F64), ThreadSafeReadWrapper_803f (0x0058803F), FileReadWrapperWithLock (0x00588678), StringFormatWithNestedIO (0x005887B1), BufferedCharacterWriteWithOverflowHandling (0x00589898), StreamGetcWithUnderflowHandler (0x00589FCC), LockCallUnlockWrapper (0x00589FFD), FileWriteWrapperWithLock (0x0058A163), FileSizeQueryWrapper (0x0058ACE6), sub_58AE69 (0x0058AE69), sub_58AFE1 (0x0058AFE1), StringWriteToFile (0x0058BABB), FileIOThreeStepSequence (0x0058C7FC), FileIOWrapperWithLock (0x0059685F), sub_59BB00 (0x0059BB00), ThreeStepStreamQuery (0x0059BBAF), StreamReadWrapperWithLockUnlock (0x0059BCD2), IOFormatWrapper (0x0059BDE9) and ThreadSafeWrapper (0x0059C127). [caller:0x00587CA0, caller:0x00587D02, caller:0x00587D7F, caller:0x00587F64, caller:0x0058803F, caller:0x00588678, caller:0x005887B1, caller:0x00589898, caller:0x00589FCC, caller:0x00589FFD, caller:0x0058A163, caller:0x0058ACE6, caller:0x0058AE69, caller:0x0058AFE1, caller:0x0058BABB, caller:0x0058C7FC, caller:0x0059685F, caller:0x0059BB00, caller:0x0059BBAF, caller:0x0059BCD2, caller:0x0059BDE9, caller:0x0059C127, source:raw]

    // Conservative worker pseudocode:
    //   void sub_58C203(unsigned int a1) {
    //     if (a1 < 0x5E6748 || a1 > 0x5E69A8)
    //       LeaveCriticalSection((LPCRITICAL_SECTION)(a1 + 32));
    //     else
    //       CritSectLeave(((int)(a1 - 0x5E6748) >> 5) + 28);
    //   }
    // UNRESOLVED: The constant 32 (embedded CRITICAL_SECTION offset) and the constants 5 and 28 (stream stride/exponent and index base) come only from the decompiled C and are not independently proven by packet evidence.
    // UNRESOLVED: off_5E6748 / unk_5E69A8 are labeled as the CRT global stream array base and end bound by existing analysis; their element layout is DERIVED, not confirmed.
    // UNRESOLVED: The exact type of a1 (FILE* or equivalent stream handle) is not established by this function alone.
}
