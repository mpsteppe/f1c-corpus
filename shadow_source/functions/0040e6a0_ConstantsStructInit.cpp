// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E6A0
// Canonical corpus name: ConstantsStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConstantsStructInit_0040e6a0.c

void UnknownObject::ConstantsStructInit()
{
    // Constructor-style initializer that writes seven consecutive dword fields of the object to built-in float literals: 10.0 (0x0), 1.0 (0x4), 1.0 (0x8), 1.0 (0xC), 2500.0 (0x10), 60.0 (0x14) and 0.7 (0x18). Returns the this pointer. Called from ConstructorZeroInitSubCalls (0x004F2430); on the frame path.
    // ASSIGNMENT: Write *this (offset 0x0) = 1092616192 (10.0 float) [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write this[1] (offset 0x4) = 1065353216 (1.0 float) [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write this[2] (offset 0x8) = 1065353216 (1.0 float) [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write this[3] (offset 0xC) = 1065353216 (1.0 float) [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write this[4] (offset 0x10) = 1159479296 (2500.0 float) [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write this[5] (offset 0x14) = 1114636288 (60.0 float) [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write this[6] (offset 0x18) = 1060320051 (0.7 float) [field:this:0x00000018, source:raw]
    // CALL: Invoked from ConstructorZeroInitSubCalls (0x004F2430) as part of object construction [caller:0x004F2430]
    // RETURN: Return the this pointer as the result [function:0x0040E6A0, source:raw]

    // Conservative worker pseudocode:
    //   DWORD* ConstantsStructInit(DWORD* this) {
    //     this[0] = 10.0f;   // 1092616192
    //     this[1] = 1.0f;    // 1065353216
    //     this[2] = 1.0f;    // 1065353216
    //     this[3] = 1.0f;    // 1065353216
    //     this[4] = 2500.0f; // 1159479296
    //     this[5] = 60.0f;   // 1114636288
    //     this[6] = 0.7f;    // 1060320051
    //     return this;
    //   }
    // UNRESOLVED: Object class and the meaning of each constant field are not established from the packet alone.
}
