// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E663
// Canonical corpus name: SetFourDwords
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetFourDwords_0049e663.c

void UnknownObject::SetFourDwords()
{
    // Writes the same int value (result) into four consecutive dword slots a2[20], a2[21], a2[22] and a2[23], then returns that value. A compact bulk-initializer for a small run of dwords inside an unknown object. Object and field identity are unknown.
    // ASSIGNMENT: Write result into a2[20] [source:raw]
    // ASSIGNMENT: Write result into a2[21] [source:raw]
    // ASSIGNMENT: Write result into a2[22] [source:raw]
    // ASSIGNMENT: Write result into a2[23] [source:raw]
    // RETURN: Return the same value (result) that was written to the four dword slots [source:raw]

    // Conservative worker pseudocode:
    //   int SetFourDwords(int result, _DWORD *a2) {
    //     a2[20] = result;
    //     a2[21] = result;
    //     a2[22] = result;
    //     a2[23] = result;
    //     return result;
    //   }
    // UNRESOLVED: The object owning the a2 dword array and the semantic role of the four written slots are unknown.
    // UNRESOLVED: Why the caller reuses the written value as the return value is unknown.
}
