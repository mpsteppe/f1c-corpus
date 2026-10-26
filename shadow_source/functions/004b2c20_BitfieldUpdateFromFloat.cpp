// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2C20
// Canonical corpus name: BitfieldUpdateFromFloat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldUpdateFromFloat_004b2c20.c

void UnknownObject::BitfieldUpdateFromFloat()
{
    // Encodes a float argument into a 6-bit field of the byte at this+0x0F. The float is scaled by the constant ~0.0180018 (reciprocal of ~55.55), truncated to integer by CRTFtol, masked to 6 bits, and merged into the field at bits [7:2] via an XOR clear-and-insert, preserving bits [1:0]. Stores the merged value back to this+0x0F and returns it.
    // ASSIGNMENT: Read the current 32-bit word containing the field at offset 0x0F. [field:this:0x0000000F, source:raw]
    // CALCULATION: Multiply the float argument by the constant 0.0180018 (the packed constant referenced by global 0x005ACCE0). [global:0x005ACCE0, source:raw]
    // CALL: Convert the scaled float to an integer via CRTFtol. [callee:0x00587BDC, source:raw]
    // CALCULATION: Mask the integer to 6 bits (value & 0x3F), shift left 2, and XOR-merge into the word after clearing the corresponding bits with mask 0xFFFFFF03. [field:this:0x0000000F, source:raw]
    // ASSIGNMENT: Store the merged value back into this+0x0F. [field:this:0x0000000F, source:raw]
    // RETURN: Return the new merged field word. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_4B2C20(this, float a2) {
    //     int word = *(int*)(this + 0x0F);
    //     int enc = CRTFtol(a2 * 0.0180018) & 0x3F;
    //     unsigned int result = word & 0xFFFFFF03 ^ (enc << 2);
    //     *(int*)(this + 0x0F) = result;
    //     return result;
    //   }
    // UNRESOLVED: Semantic meaning of the 6-bit field (e.g. skidding/state code) is not proven by this function alone.
    // UNRESOLVED: Owner object and the purpose of the caller's 3-short conversion are unknown.
}
