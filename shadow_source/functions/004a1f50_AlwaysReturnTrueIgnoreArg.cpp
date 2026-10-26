// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1F50
// Canonical corpus name: sub_4A1F50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A1F50_004a1f50.c

void UnknownObject::AlwaysReturnTrueIgnoreArg()
{
    // Trivial __stdcall leaf function accepting a single argument a1 but never reading it, and returning the constant 1 unconditionally. The ignored argument and the meaning of the constant are not established by the packet; the function may be a boolean/flag helper or a residual sentinel.
    // RETURN: Return constant 1 unconditionally; argument a1 is never read and no state is touched. [function:0x004A1F50, source:raw]

    // Conservative worker pseudocode:
    //   char AlwaysReturnTrueIgnoreArg(int a1) {
    //     return 1;
    //   }
    // UNRESOLVED: Purpose of the ignored argument a1 is unknown (semantic meaning of the constant 1 also unknown).
}
