// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BAF0
// Canonical corpus name: SmallStructInit_baf0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructInit_baf0_0055baf0.c

void UnknownObject::SmallStructInit_baf0()
{
    // Initializes a 36-byte structure: writes zero to this+0x0, this+0x8, this+0xC, this+0x10, this+0x14, this+0x18, this+0x1C and this+0x20, sets this+0x4 to the sentinel value -1 (decimal 18446744073709551615), and returns the this pointer. No reads, no globals and no callees.
    // ASSIGNMENT: Zeroes the first DWORD at this+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Sets this+0x4 to the sentinel -1 (decimal 18446744073709551615) rather than a zeroed field [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zeroes this+0x8 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zeroes this+0xC [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zeroes this+0x10 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Zeroes this+0x14 [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zeroes this+0x18 [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Zeroes this+0x1C [field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Zeroes this+0x20, the last field of the 36-byte structure [field:this:0x00000020, source:raw]
    // RETURN: Returns the this pointer [source:raw]
    // CALL: Invoked by sub_55BC00 (0x0055BC00) [caller:0x0055BC00, source:raw]

    // Conservative worker pseudocode:
    //   this->field0 = 0;
    //   this->field4 = -1;
    //   this->field8 = 0;
    //   this->fieldC = 0;
    //   this->field10 = 0;
    //   this->field14 = 0;
    //   this->field18 = 0;
    //   this->field1C = 0;
    //   this->field20 = 0;
    //   return this;
    // UNRESOLVED: The identity of the 36-byte structure and the meaning of the -1 sentinel at this+0x4 are not determinable from this packet
    // UNRESOLVED: The template prelabel classifies this as a ctor_init, which is consistent but offers no object identity
}
