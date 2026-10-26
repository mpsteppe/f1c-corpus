// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FE10
// Canonical corpus name: StructInitWithZeroFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithZeroFill_0054fe10.c

void UnknownObject::StructInitWithZeroFill()
{
    // Constructor/initializer. Calls GlobalZeroInit_c2a0(this) for the parent-object zeroing, zero-fills 0x40 bytes starting at this+4 (memset(this + 1, 0, 0x40)), then writes eight fields explicitly: this+0x0, this+0x44, this+0x48, this+0x54, this+0x58 and this+0x5C are set to 0 while this+0x4C and this+0x50 are set to 1. Called from nine construction sites including vehicle-node creation (0049E930) and audio-sound creation (0049E9A0), so the object type is shared; its identity is not named by the packet.
    // CALL: Calls GlobalZeroInit_c2a0(this) to zero-initialize the parent object [callee:0x0053C2A0, source:raw]
    // ASSIGNMENT: Zero-fills 0x40 bytes starting at this+4 via memset(this + 1, 0, 0x40) [source:raw]
    // ASSIGNMENT: Writes 0 into field this+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Writes 0 into field this+0x44 (source renders this[17]) [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Writes 0 into field this+0x48 (source renders this[18]) [field:this:0x00000048, source:raw]
    // ASSIGNMENT: Writes 1 into field this+0x4C (source renders this[19]); this field is one of two defaulted to a non-zero literal [field:this:0x0000004C, source:raw]
    // ASSIGNMENT: Writes 1 into field this+0x50 (source renders this[20]); this field is the second defaulted to a non-zero literal [field:this:0x00000050, source:raw]
    // ASSIGNMENT: Writes 0 into field this+0x54 (source renders this[21]) [field:this:0x00000054, source:raw]
    // ASSIGNMENT: Writes 0 into field this+0x58 (source renders this[22]) [field:this:0x00000058, source:raw]
    // ASSIGNMENT: Writes 0 into field this+0x5C (source renders this[23]) [field:this:0x0000005C, source:raw]
    // RETURN: Returns the initialized object pointer in EAX [function:0x0054FE10, source:raw]

    // Conservative worker pseudocode:
    //   GlobalZeroInit_c2a0(this);
    //   memset(this + 1, 0, 0x40);
    //   *this = 0;
    //   this[17] = 0; this[18] = 0;
    //   this[19] = 1; this[20] = 1;
    //   this[21] = 0; this[22] = 0; this[23] = 0;
    //   return this;
    // UNRESOLVED: The object type is not named; the packet shows nine callers including vehicle-node creation (0049E930) and audio-sound creation (0049E9A0), but the shared layout's identity is not established
    // UNRESOLVED: The roles of the fields defaulted to 1 at this+0x4C and this+0x50 are unknown; the template prelabel classifies the whole function as ctor_init (DERIVED)
}
