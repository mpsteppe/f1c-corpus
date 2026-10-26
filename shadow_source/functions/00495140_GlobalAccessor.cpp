// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495140
// Canonical corpus name: GlobalAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalAccessor_00495140.c

void UnknownObject::GlobalAccessor()
{
    // Tiny global reader: returns the current int value of dword_7CDE20 (0x007CDE20) with no parameters, no writes, and no callees. Its only known caller is FileLoadWithRetryLoop (0x004F9B70), so the returned value is plausibly consumed as a load/retry state flag, but the meaning of the global is not evidenced here.
    // RETURN: Read the dword at global 0x007CDE20 (dword_7CDE20) and return it as int; a pure read with no side effects [global:0x007CDE20, function:0x00495140, source:raw]

    // Conservative worker pseudocode:
    //   int GlobalAccessor()
    //   {
    //     return dword_7CDE20;
    //   }
    // UNRESOLVED: Purpose and writer of dword_7CDE20 are unidentified; whether the returned value is a state flag, counter, or object pointer is not evidenced
    // UNRESOLVED: The consumer FileLoadWithRetryLoop (0x004F9B70) uses the value, but its exact role is outside this packet
}
