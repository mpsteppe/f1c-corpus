// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005887B1
// Canonical corpus name: StringFormatWithNestedIO
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringFormatWithNestedIO_005887b1.c

void UnknownObject::StringFormatWithNestedIO()
{
    // Varargs formatted-write wrapper around a stream/buffer object a1 with a format string a2. Enters the stream's critical section via StreamBufferLockViaCriticalSection, captures buffer state with sub_58E41B, performs the formatted write with the va_list through sub_58D04D, conditionally clears struct fields via ClearStructFieldsIfFlagSet using the captured state, leaves the critical section with AddressRangeCriticalSectionLeave, and returns the formatted-write result.
    // CALL: Enter the stream's critical section with StreamBufferLockViaCriticalSection(a1) [callee:0x0058C1B1, source:raw]
    // CALL: Capture the buffer/struct state from a1 with sub_58E41B, stored in v2 [callee:0x0058E41B, source:raw]
    // CALL: Run the formatted write sub_58D04D(a1, a2, va) with the varargs list; its result is kept in v3 [callee:0x0058D04D, source:raw]
    // CALL: When the captured state's flag is set, clear struct fields via ClearStructFieldsIfFlagSet(v2, a1) [callee:0x0058E4A8, source:raw]
    // CALL: Leave the critical section with AddressRangeCriticalSectionLeave(a1) [callee:0x0058C203, source:raw]
    // RETURN: Return v3, the formatted-write result [source:raw]
    // CALL: Used by logging and file-writer paths including TraceLogInit, ResourcePathBuilder, SceneFileTEAMDIRVEHDIRNOTSPINWriter and WeatherConditionsFileWriter [caller:0x004D7960, caller:0x00493E20, caller:0x004DDF90, caller:0x004FE820, source:raw]

    // Conservative worker pseudocode:
    //   va_start(va, a2);
    //   StreamBufferLockViaCriticalSection(a1);
    //   v2 = sub_58E41B(a1);
    //   v3 = sub_58D04D(a1, a2, va);
    //   ClearStructFieldsIfFlagSet(v2, a1);
    //   AddressRangeCriticalSectionLeave(a1);
    //   return v3;
    // UNRESOLVED: The callees sub_58E41B and sub_58D04D define the captured-state and formatted-write semantics, but neither is in this packet
    // UNRESOLVED: The flag and fields manipulated by ClearStructFieldsIfFlagSet belong to a1's structure, which is not identified
    // UNRESOLVED: The packet's prelabel suggests a structural twin of MemoryAllocation_5160 (00405160), but no in-packet evidence supports that owner claim
}
