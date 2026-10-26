// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC850
// Canonical corpus name: sub_4FC850
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FC850_004fc850.c

void UnknownObject::FloatFieldInitWithDefaults()
{
    // Constructor-style initializer on a 6-dword (24-byte) object: zeroes the dword fields at +0, +4, +8, +0xC and initializes the two float fields at +0x10 and +0x14 to the literal 1101004800 (float 20.0). Returns the `this` pointer unchanged.
    // ASSIGNMENT: Zero the first four dword fields: *this = 0, this[1] = 0, this[2] = 0, this[3] = 0. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set the float field at +0x10 (this[4]) to the literal 1101004800, interpreted as float 20.0. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set the float field at +0x14 (this[5]) to the literal 1101004800, interpreted as float 20.0. [field:this:0x00000014, source:raw]
    // RETURN: Return the `this` pointer unchanged as the result of the initializer. [function:0x004FC850, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   this[3] = 0;
    //   this[4] = 1101004800; /* float 20.0 * /
    //   this[5] = 1101004800; /* float 20.0 * /
    //   return this;
    // UNRESOLVED: The object owning these six fields is unnamed in the corpus; the ABI label Float_Field_Init_with_Defaults (LEGACY) and the template classification ctor_init (DERIVED) are the only owner signals.
    // UNRESOLVED: The meaning of the 20.0 default in both trailing floats (a dimension, range, or similar scalar default) is not established by this function alone.
    // UNRESOLVED: Called by StructInitWithFloatDefaults (sub_4FC9C0); no frame path confirmed.
}
