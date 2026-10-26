// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499A20
// Canonical corpus name: FloatFieldDecrement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatFieldDecrement_00499a20.c

void UnknownObject::FloatFieldDecrement()
{
    // Subtracts the float argument a2 from the float field this[2] (byte offset 0x8) in place and returns void. A minimal in-place float field decrement with no guards and no callees; its sole caller is sub_495B60.
    // CALCULATION: Read the float field this[2] (byte offset 0x8), subtract the argument a2, and store the result back into the same field. [field:this:0x00000008, source:raw]

    // Conservative worker pseudocode:
    //   void floatFieldDecrement(float* this, float a2) {
    //     this[2] = this[2] - a2;
    //   }
    // UNRESOLVED: The owning object is unidentified; the float field this[2] (offset 0x8) has no known semantic meaning.
    // UNRESOLVED: The purpose of the decrement (e.g. a timer, temperature, or fuel quantity) is not confirmed from the evidence packet.
}
