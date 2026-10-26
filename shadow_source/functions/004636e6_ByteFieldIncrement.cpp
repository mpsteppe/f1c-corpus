// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004636E6
// Canonical corpus name: ByteFieldIncrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteFieldIncrement_004636e6.c

void UnknownObject::ByteFieldIncrement()
{
    // Increments the byte at offset 94 of the object pointed to by argument a2 by the value of argument a1, then returns a1 unchanged. The __userpurge ABI carries a1 in BL and a2 in EDI; argument a3 is unused. The legacy ABI name is Byte_Field_Increment.
    // ASSIGNMENT: *(_BYTE *)(a2 + 94) += a1 increments the byte field at offset 94 of the object at a2 by a1. [source:raw]
    // RETURN: Return a1 unchanged as the function result in AL. [source:raw]

    // Conservative worker pseudocode:
    //   char __userpurge ByteFieldIncrement(char a1, int a2, int a3) {
    //       *(_BYTE *)(a2 + 94) += a1;
    //       return a1;
    //   }
    // UNRESOLVED: The owning class and the meaning of the byte field at offset 94 are not documented by the packet.
    // UNRESOLVED: Argument a3 is unused by the body; its purpose and the identity of the calling convention payload are unknown.
    // UNRESOLVED: Why the function returns the increment amount (a1) rather than the resulting byte value is caller-context dependent.
}
