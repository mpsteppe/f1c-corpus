// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556220
// Canonical corpus name: sub_556220
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_556220_00556220.c

void UnknownObject::InitializeObject()
{
    // Constructor-style initializer: calls GlobalZeroInit_c2a0(this) to perform the shared base zero-initialization, then explicitly zeroes 17 DWORD fields of this (offsets 0x0 and 0x8 through 0x44), and returns this.
    // CALL: Call GlobalZeroInit_c2a0(this) to perform the shared zero-initialization of the object. [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Set this[0] (offset 0x0) to 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set this[2] (offset 0x8) to 0. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set this[3] (offset 0xC) to 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set this[4] (offset 0x10) to 0. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set this[5] (offset 0x14) to 0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set this[6] through this[17] (offsets 0x18 through 0x44, twelve consecutive DWORDs) to 0. [field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, source:raw]
    // RETURN: Return this. [function:0x00556220, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   this[0] = 0; this[2] = 0; this[3] = 0; this[4] = 0; this[5] = 0;
    //   for (i = 6; i <= 17; ++i) this[i] = 0;
    //   return this;
    // UNRESOLVED: The object type behind 'this' is unknown; only its zeroed DWORD field layout (0x0, 0x8 through 0x44) is evidenced.
    // UNRESOLVED: GlobalZeroInit_c2a0's exact zeroing scope beyond this function is unknown.
    // UNRESOLVED: Field 0x4 (this[1]) is not written by this function; whether it is zeroed by the callee is unknown.
}
