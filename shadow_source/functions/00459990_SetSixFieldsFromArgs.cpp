// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00459990
// Canonical corpus name: F_6FieldBulkSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_6FieldBulkSetter_00459990.c

void UnknownObject::SetSixFieldsFromArgs()
{
    // Trivial bulk setter: writes the six parameters a2..a7 into six consecutive dword fields this[10]..this[15] (byte offsets 0x28 through 0x3C) and returns a6, the value stored into this[14]. No guards, no calls, no globals, no branches.
    // ASSIGNMENT: Write a2 into this[10] (this+0x28). [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Write a3 into this[11] (this+0x2C). [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Write a4 into this[12] (this+0x30). [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write a5 into this[13] (this+0x34). [field:this:0x00000034, source:raw]
    // ASSIGNMENT: Write a6 into this[14] (this+0x38); a6 is also the value returned. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Write a7 into this[15] (this+0x3C). [field:this:0x0000003C, source:raw]
    // RETURN: Return a6, the value just stored into this[14]. [field:this:0x00000038, source:raw]

    // Conservative worker pseudocode:
    //   this[10] = a2;
    //   this[11] = a3;
    //   this[12] = a4;
    //   this[13] = a5;
    //   this[14] = a6;
    //   this[15] = a7;
    //   return a6;
    // UNRESOLVED: The role and meaning of the six written fields are unknown; the caller set suggests grouped configuration/float initialisation but that is not evidenced in this packet.
    // UNRESOLVED: Why the function returns a6 specifically is unexplained by this packet.
}
