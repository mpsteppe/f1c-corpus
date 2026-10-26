// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C3C0
// Canonical corpus name: TwoByteFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoByteFieldSetter_0045c3c0.c

void UnknownObject::setTwoByteFields()
{
    // Writes two consecutive byte fields of the this object from parameters a2 and a3, returning a2.
    // ASSIGNMENT: Store a2 into the byte field at this offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Store a3 into the byte field at this offset 0x1. [field:this:0x00000001]
    // RETURN: Return a2 as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   *this = a2;
    //   this[1] = a3;
    //   return result;
}
