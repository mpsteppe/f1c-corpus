// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C22A0
// Canonical corpus name: FAILWRONGTRIAGECATEGORY
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILWRONGTRIAGECATEGORY_004c22a0.c

void UnknownObject::WriteOptionsOnAudioStreamOpen()
{
    // Conditional wrapper: if argument a2 is non-zero, zero-initialize a small stack struct, open an audio stream for a2, and only if that open succeeds call GameOptionsWriter(this, struct), store its result as the return flag, and conditionally close the file handle through ConditionalFileHandleCloseWithFlagDispatch. Always runs SubCallWithConditionalFieldFree on the struct before returning the stored flag (zero when a2 was null or the stream failed to open).
    // GUARD: Guard on a2 being non-zero; the whole body (stream open, options write, cleanup) is skipped when a2 is null and the function returns the default flag 0. [source:raw]
    // CALL: Zero-initialize the small stack struct v5 (7 dwords) before use. [callee:0x005668B0, source:raw]
    // CALL: Open an audio stream for a2; the boolean result gates the options write. [callee:0x00566B20, source:raw]
    // GUARD: Guard on AudioStreamOpen(a2, 1) returning non-zero; only then are the options written and the handle closed. [callee:0x00566B20, source:raw]
    // ASSIGNMENT: Store the GameOptionsWriter(this, v5) result into v2, which becomes the function return value. [callee:0x004C1E80, source:raw]
    // CALL: Conditionally close the file handle carried by v5, dispatched on a flag. [callee:0x00566B90, source:raw]
    // CALL: Clean up v5's conditional fields unconditionally before the function returns. [callee:0x005668D0, source:raw]
    // RETURN: Return v2: the GameOptionsWriter flag, or 0 when a2 was null or the stream open failed. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4C22A0(void *this, int a2) {
    //     char result = 0;
    //     _DWORD v5[7];
    //     if (a2) {
    //       ZeroInitSmallStruct(v5);
    //       if ((unsigned __int8)AudioStreamOpen(a2, 1)) {
    //         result = GameOptionsWriter((int)this, v5);
    //         ConditionalFileHandleCloseWithFlagDispatch(v5);
    //       }
    //       SubCallWithConditionalFieldFree(v5);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of a2: the value passed to AudioStreamOpen and gated for non-zero is not further identified by any field or global evidence in the packet.
    // UNRESOLVED: The meaning of the literal 1 argument to AudioStreamOpen is unknown (mode/flag), not backed by packet evidence.
    // UNRESOLVED: Whether GameOptionsWriter returns a success/error flag is DERIVED from its value being stored to and returned as v2.
    // UNRESOLVED: The prelabel structural-twin relationship to MemoryAllocation_5160 (00405160) is DERIVED cluster-copy evidence only; no shared implementation or layout is confirmed.
    // UNRESOLVED: Single caller F_5StepInit (004B0720) is recorded but contributes no type or field information to this function.
}
