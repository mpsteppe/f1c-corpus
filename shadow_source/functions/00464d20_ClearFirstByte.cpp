// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464D20
// Canonical corpus name: sub_464D20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_464D20_00464d20.c

void UnknownObject::ClearFirstByte()
{
    // Byte zeroer: unconditionally clears the byte at this[0] to 0 and returns the this pointer. No static callers are recorded, so the containing object type and the meaning of the cleared byte are unknown.
    // ASSIGNMENT: Set *this, the byte at offset 0 of the object, to 0. [field:this:0x00000000, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   _BYTE *sub_464D20(_BYTE *obj) {
    //     *obj = 0;
    //     return obj;
    //   }
    // UNRESOLVED: The object type and the meaning of the cleared byte at offset 0 are unknown (no static callers recorded).
}
