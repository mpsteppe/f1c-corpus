// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C898
// Canonical corpus name: AddByteAtOffset51
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AddByteAtOffset51_0049c898.c

void UnknownObject::AddByteAtOffset51()
{
    // Adds a single-byte argument value to the byte at displacement 51 of the a2 object, then returns 0 unconditionally. The a3 and a4 parameters are unused by the raw body. Object and field identity are unknown.
    // ASSIGNMENT: Accumulate a1 into the byte at a2 + 51: *(_BYTE *)(a2 + 51) += a1 [source:raw, abi:lead]
    // RETURN: Return 0 unconditionally after the byte update [source:raw]

    // Conservative worker pseudocode:
    //   int AddByteAtOffset51(char a1, int a2, int a3, int a4) {
    //     *(_BYTE *)(a2 + 51) += a1;
    //     return 0;
    //   }
    // UNRESOLVED: The identity of the object referenced by a2 and the meaning of the byte at +51 are unknown.
    // UNRESOLVED: The a3 and a4 parameters are not referenced in the raw body; their purpose is unknown.
}
