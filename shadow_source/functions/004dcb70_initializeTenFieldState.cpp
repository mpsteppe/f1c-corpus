// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCB70
// Canonical corpus name: ShortComputation_cb70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_cb70_004dcb70.c

void UnknownObject::initializeTenFieldState()
{
    // Constructor/initializer on an unknown __thiscall object (called by ShortComputation_b360 0045b360 and sub_49B0A0). Zero-fills the first eight dwords (offsets 0x0 through 0x1C), writes 1065353216 (single-precision 1.0) into offsets 0x20 and 0x24, and returns 1065353216. No reads and no globals.
    // ASSIGNMENT: Zero the first eight dwords of the object: this[0] through this[7] (offsets 0x0 through 0x1C). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, function:0x004DCB70, source:raw]
    // ASSIGNMENT: Write 1065353216 (the single-precision bit pattern of 1.0) into this[8] at offset 0x20. [field:this:0x00000020, function:0x004DCB70, source:raw]
    // ASSIGNMENT: Write 1065353216 (single-precision 1.0) into this[9] at offset 0x24. [field:this:0x00000024, function:0x004DCB70, source:raw]
    // RETURN: Return 1065353216 to the caller. [function:0x004DCB70, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0;
    //   this[1] = 0;
    //   this[2] = 0;
    //   this[3] = 0;
    //   this[4] = 0;
    //   this[5] = 0;
    //   this[6] = 0;
    //   this[7] = 0;
    //   this[8] = 1065353216; /* float 1.0 * /
    //   this[9] = 1065353216; /* float 1.0 * /
    //   return 1065353216;
    // UNRESOLVED: The object type is unidentified; the write-only pattern is consistent with a constructor/initializer (prelabel category ctor_init) but no owner identity is evidenced.
    // UNRESOLVED: The meaning of the eight zeroed fields and the two fields initialized to 1.0 is unknown.
    // UNRESOLVED: The purpose of returning 1065353216 is not evidenced; the value may be a decompiler artifact of the register that held the last write.
}
