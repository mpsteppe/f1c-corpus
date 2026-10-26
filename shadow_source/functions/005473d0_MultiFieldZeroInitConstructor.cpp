// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005473D0
// Canonical corpus name: MultiFieldZeroInitConstructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldZeroInitConstructor_005473d0.c

void UnknownObject::MultiFieldZeroInitConstructor()
{
    // Constructor/initializer for an object at this. Calls GlobalZeroInit_c2a0(this) to perform the base zero-init, then explicitly zeroes ten dword fields at offsets 0x8 through 0x2C. Returns this. No reads, no globals.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the base object. [source:raw, callee:0x0053C2A0]
    // ASSIGNMENT: Zero field this+0x8 (this[2]). [source:raw, field:this:0x00000008]
    // ASSIGNMENT: Zero field this+0xC (this[3]). [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Zero field this+0x10 (this[4]). [source:raw, field:this:0x00000010]
    // ASSIGNMENT: Zero field this+0x14 (this[5]). [source:raw, field:this:0x00000014]
    // ASSIGNMENT: Zero field this+0x18 (this[6]). [source:raw, field:this:0x00000018]
    // ASSIGNMENT: Zero field this+0x1C (this[7]). [source:raw, field:this:0x0000001C]
    // ASSIGNMENT: Zero field this+0x20 (this[8]). [source:raw, field:this:0x00000020]
    // ASSIGNMENT: Zero field this+0x24 (this[9]). [source:raw, field:this:0x00000024]
    // ASSIGNMENT: Zero field this+0x28 (this[10]). [source:raw, field:this:0x00000028]
    // ASSIGNMENT: Zero field this+0x2C (this[11]). [source:raw, field:this:0x0000002C]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_5473D0(_DWORD *this) {
    //     GlobalZeroInit_c2a0(this);
    //     for (int i = 2; i <= 11; ++i) this[i] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The object type and the meaning of the ten zeroed fields (0x8..0x2C) are unknown.
    // UNRESOLVED: Relation to the two callers (ObjectAllocationWithInit 0x0053CAC0, sub_54AC70) is unconfirmed.
}
