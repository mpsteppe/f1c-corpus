// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D230
// Canonical corpus name: StructInitWithFloatDefaults_d230
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithFloatDefaults_d230_0055d230.c

void UnknownObject::initializeStructWithFloatDefaults()
{
    // Constructor/initializer. Calls GlobalZeroInit_c2a0(this) to zero-initialize the object, then explicitly re-zeroes a subset of dword fields (+0x8..+0x10, +0x38..+0x44, +0x4C..+0x54 and +0x68/+0x6C, plus the byte at +0x58), sets the field at +0x0 to 384, initializes nine consecutive floats (+0x14..+0x34) to 1.0f, sets the float at +0x48 to -1.0f, and returns this.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the object before the explicit field writes. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Zero the byte at +0x58 via *((_BYTE *)this + 88) = 0. [field:this:0x00000058]
    // ASSIGNMENT: Zero dwords +0x8, +0xC and +0x10 (this[2..4]). [field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010]
    // ASSIGNMENT: Zero dwords +0x38..+0x44 (this[14..17]). [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044]
    // ASSIGNMENT: Zero dwords +0x4C, +0x50 and +0x54 (this[19..21]). [field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054]
    // ASSIGNMENT: Zero dwords +0x68 and +0x6C (this[26..27]). [field:this:0x00000068, field:this:0x0000006C]
    // ASSIGNMENT: Set the field at +0x0 to 384 (*this = 384). [field:this:0x00000000]
    // ASSIGNMENT: Initialize nine consecutive floats +0x14..+0x34 (this[5..13]) to 1065353216 (1.0f). [field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034]
    // ASSIGNMENT: Set the float at +0x48 (this[18]) to -1082130432, i.e. -1.0f. [field:this:0x00000048]
    // RETURN: Return the initialized object pointer (this). [function:0x0055D230, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   *((_BYTE *)this + 88) = 0;
    //   this[2] = 0; this[3] = 0; this[4] = 0;
    //   this[14] = 0; this[15] = 0; this[16] = 0; this[17] = 0;
    //   this[19] = 0; this[20] = 0; this[21] = 0;
    //   this[26] = 0; this[27] = 0;
    //   *this = 384;
    //   this[5] = 1.0f; this[6] = 1.0f; this[7] = 1.0f; this[8] = 1.0f; this[9] = 1.0f;
    //   this[10] = 1.0f; this[11] = 1.0f; this[12] = 1.0f; this[13] = 1.0f;
    //   this[18] = -1.0f;
    //   return this;
    // UNRESOLVED: The owning class is unknown; the struct is constructed from the caller sub_545430 but no type identity is established from the packet.
    // UNRESOLVED: The meaning of the 384 value at +0x0 (size/count/type tag) and of the -1.0f default at +0x48 (sentinel/no-value marker) is DERIVED, not confirmed.
    // UNRESOLVED: GlobalZeroInit_c2a0 already zeroes the object, making the explicit re-zero writes redundant at runtime; the explicit writes may reflect per-field intent that the packet does not evidence.
}
