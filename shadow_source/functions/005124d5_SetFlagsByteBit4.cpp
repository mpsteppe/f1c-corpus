// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005124D5
// Canonical corpus name: sub_5124D5
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5124D5_005124d5.c

void UnknownObject::SetFlagsByteBit4()
{
    // Sets bit 4 (mask 0x10) on the flags byte at offset 0x61 of the object (a1 + 97) and returns the object pointer unchanged. Unconditional bit-set; the persisted flags byte is later cleared by another writer. Called by sub_50210E.
    // ASSIGNMENT: Store the object pointer a1 as the return value (result = a1). [source:raw]
    // CALCULATION: OR the mask 0x10 into the flags byte at offset 0x61 (a1 + 97), setting bit 4. [field:this:0x00000061, source:raw]
    // RETURN: Return the original object pointer a1. [caller:0x0050210E, source:raw]

    // Conservative worker pseudocode:
    //   int SetFlagsByteBit4(int obj) {
    //     *(_BYTE *)(obj + 0x61) |= 0x10;
    //     return obj;
    //   }
    // UNRESOLVED: The semantic meaning of bit 4 on the flags byte at +0x61 is not evidenced; the fill notes the bit persists until cleared by another writer.
    // UNRESOLVED: The owning class is unknown; the single caller sub_50210E does not identify it.
}
