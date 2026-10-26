// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB0B0
// Canonical corpus name: InitTwoFieldsToZero
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitTwoFieldsToZero_004db0b0.c

void UnknownObject::InitTwoFieldsToZero()
{
    // Thiscall initializer that clears two integer fields of the object at offsets 0x10 and 0x14 (this[4], this[5]) to zero and returns 0. Unconditional writes; likely a sub-object reset/init helper. The owning class and both field roles are unidentified.
    // ASSIGNMENT: Write 0 to this[0x10] (field at offset 0x10), unconditional. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write 0 to this[0x14] (field at offset 0x14), unconditional. [field:this:0x00000014, source:raw]
    // RETURN: Return integer literal 0. [function:0x004DB0B0, source:raw]

    // Conservative worker pseudocode:
    //   int __thiscall InitTwoFieldsToZero(_DWORD *this)
    //   {
    //     this[4] = 0;  // +0x10
    //     this[5] = 0;  // +0x14
    //     return 0;
    //   }
    // UNRESOLVED: Owning class of the object is unknown; offsets 0x10 and 0x14 are treated as opaque integer fields, not typed counters.
    // UNRESOLVED: No callers in the packet, so call context (init vs reset) is not established.
}
