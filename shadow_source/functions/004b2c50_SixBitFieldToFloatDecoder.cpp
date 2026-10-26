// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2C50
// Canonical corpus name: sub_4B2C50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B2C50_004b2c50.c

void UnknownObject::SixBitFieldToFloatDecoder()
{
    // Decodes a 6-bit field from the dword at this+0xF: shifts right by 2, masks with 0x3F (isolating bits [7:2] of the byte at this+0xF), multiplies the result by the scale constant 55.549999 (flt_5ACCE4), and returns the product as a double. Straight-line thiscall with no guards. Called by VehicleOrientationFromEulerAngles (0x004B2DD0) and sub_4B32A0 (0x004B32A0).
    // CALCULATION: Read the dword at this+0xF and shift it right by 2 bit positions. [field:this:0x0000000F, source:raw]
    // CALCULATION: Mask the shifted value with 0x3F to isolate a 6-bit field. [source:raw]
    // CALCULATION: Multiply the 6-bit field by the 55.549999 scale constant held in flt_5ACCE4. [global:0x005ACCE4, source:raw]
    // RETURN: Return the scaled value as double. Consumed by VehicleOrientationFromEulerAngles (0x004B2DD0) and sub_4B32A0 (0x004B32A0). [caller:0x004B2DD0, caller:0x004B32A0, function:0x004B2C50]

    // Conservative worker pseudocode:
    //   return (double)((*(unsigned int *)(this + 0xF) >> 2) & 0x3F) * 55.549999;
    // UNRESOLVED: The physical meaning of the 6-bit field and of the 55.549999 scale (flt_5ACCE4) is not determinable from this packet alone; the skeleton fill labels this function SixBitFieldToFloatDecoder (DERIVED) and the raw dword read spans the byte at this+0xF plus the three following bytes, but the 0x3F mask confines the extracted field to bits [7:2] of the byte at this+0xF.
}
