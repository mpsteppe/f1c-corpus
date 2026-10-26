// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486EC8
// Canonical corpus name: ByteIncrementHelper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteIncrementHelper_00486ec8.c

void UnknownObject::ByteIncrementHelper()
{
    // Increments a single byte field 94 bytes into the object pointed to by a2 by the signed char amount a1 (passed in bl). The extra userpurge parameters a3/a4 are unused; this is a narrow field-mutating helper on an unknown object.
    // ASSIGNMENT: Add the signed char a1 to the byte at offset 0x5E (94) of the object pointed to by a2, storing the result back into the same byte. [abi:lead, function:0x00486EC8, source:raw]

    // Conservative worker pseudocode:
    //   void ByteIncrementHelper(char a1, int a2, int a3, int a4) {
    //     *(char*)(a2 + 94) += a1;
    //   }
    // UNRESOLVED: The object class containing the byte at offset 0x5E of a2 is not evidenced in this packet; the owner is UnknownObject.
    // UNRESOLVED: The purpose of the unused userpurge parameters a3/a4 is not evidenced here.
}
