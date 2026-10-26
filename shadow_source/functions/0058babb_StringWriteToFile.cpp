// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BABB
// Canonical corpus name: StringWriteToFile
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringWriteToFile_0058babb.c

void UnknownObject::StringWriteToFile()
{
    // Writes a length-prefixed string a1 into a buffered stream object a2 under a critical section. Measures the string, locks the stream buffer, fetches a flag/handle from the stream via sub_58E41B, writes the bytes with sub_5886A7, clears stream fields when the flag is set, releases the critical section, and returns 0 when every byte was written or -1 otherwise.
    // CALL: Measure the input string length with Strlen(a1). [source:raw, callee:0x0058E1B0]
    // CALL: Lock the stream buffer via StreamBufferLockViaCriticalSection(a2). [source:raw, callee:0x0058C1B1]
    // CALL: Fetch a per-stream value v3 from sub_58E41B(a2) used to decide field clearing. [source:raw, callee:0x0058E41B]
    // CALL: Write v2 bytes of a1 into the stream via sub_5886A7(a1, 1u, v2, a2); store the number of bytes actually written in v5. [source:raw, callee:0x005886A7]
    // CALL: Clear stream struct fields if the fetched flag is set via ClearStructFieldsIfFlagSet(v3, a2). [source:raw, callee:0x0058E4A8]
    // CALL: Release the buffer critical section via AddressRangeCriticalSectionLeave(a2). [source:raw, callee:0x0058C203]
    // CALCULATION: Return (v5 == v2) - 1: 0 when the full length was written, -1 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   int StringWriteToFile(char *text, void *stream) {
    //     int len = Strlen(text);
    //     StreamBufferLockViaCriticalSection(stream);
    //     int flag = sub_58E41B(stream);
    //     unsigned int written = sub_5886A7(text, 1u, len, stream);
    //     ClearStructFieldsIfFlagSet(flag, stream);
    //     AddressRangeCriticalSectionLeave(stream);
    //     return (written == len) - 1;
    //   }
    // UNRESOLVED: Exact contract of stream object a2 and of the sub_5886A7 write primitive (buffered vs unbuffered, error handling).
    // UNRESOLVED: Semantics of the sub_58E41B return value consumed by ClearStructFieldsIfFlagSet.
}
