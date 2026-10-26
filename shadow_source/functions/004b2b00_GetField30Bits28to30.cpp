// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2B00
// Canonical corpus name: ShortComputation_2b00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_2b00_004b2b00.c

void UnknownObject::GetField30Bits28to30()
{
    // thiscall getter. Reads this[12] (dword at offset 0x30), shifts it right by 28 and masks with 7, returning bits 28-30 of field 0x30. No side effects. Called from sub_4B3400 and VehiclePhysicsTimeStep.
    // CALCULATION: Shift this[12] (field at offset 0x30) right by 28. [field:this:0x00000030, source:raw]
    // CALCULATION: Mask the shifted value with 7, isolating the top 3 bits (bits 28-30) of field 0x30. [field:this:0x00000030, source:raw]
    // RETURN: Return the extracted 3-bit value. [function:0x004B2B00, source:raw]

    // Conservative worker pseudocode:
    //   return (this[12] >> 28) & 7;
    // UNRESOLVED: Semantic meaning of the 3-bit subfield (bits 28-30) of field 0x30 is not evidenced.
    // UNRESOLVED: Owner class unknown; no callee or guard evidence exists in the packet.
}
