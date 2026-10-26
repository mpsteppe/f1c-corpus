// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2B80
// Canonical corpus name: BitfieldExtract_2b80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldExtract_2b80_004b2b80.c

void UnknownObject::GetField30Bits15to21()
{
    // thiscall getter. Reads this[12] (dword at offset 0x30), shifts it right by 15 and masks with 0x7F, returning 7 bits (bits 15-21) of field 0x30. No side effects. Called from VehiclePhysicsTimeStep.
    // CALCULATION: Shift this[12] (field at offset 0x30) right by 15. [field:this:0x00000030, source:raw]
    // CALCULATION: Mask the shifted value with 0x7F, isolating 7 bits (bits 15-21) of field 0x30. [field:this:0x00000030, source:raw]
    // RETURN: Return the extracted 7-bit value. [function:0x004B2B80, source:raw]

    // Conservative worker pseudocode:
    //   return (this[12] >> 15) & 0x7F;
    // UNRESOLVED: Semantic meaning of the 7-bit subfield (bits 15-21) of field 0x30 is not evidenced.
    // UNRESOLVED: Owner class unknown; no callee or guard evidence exists in the packet.
}
