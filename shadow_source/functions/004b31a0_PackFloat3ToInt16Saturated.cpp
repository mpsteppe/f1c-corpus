// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B31A0
// Canonical corpus name: FloatToInt16SaturationPack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToInt16SaturationPack_004b31a0.c

void UnknownObject::PackFloat3ToInt16Saturated()
{
    // Converts three float inputs a2[0..2] into int16 values using a 2048.0 scale with saturation at +/-15.999512, storing the results at this+0xC (this[6]), this+0xE (this[7]) and this+0x10 (this[8]). Each component is clamped to 0x7FFF when above 15.999512 and to -32767 when below -15.999512; in-range values are multiplied by 2048.0 and truncated to int16. Returns the third converted value.
    // GUARD: Component 0 upper clamp: if a2[0] > 15.999512, this[0xC] = 0x7FFF. [field:this:0x0000000C, global:0x005ACC94, function:0x004B31A0, source:raw]
    // GUARD: Component 0 lower clamp: if a2[0] < -15.999512, this[0xC] = -32767. [field:this:0x0000000C, global:0x005ACC90, function:0x004B31A0, source:raw]
    // CALCULATION: Component 0 scale: this[0xC] = (int)(a2[0] * 2048.0), truncated to int16. [field:this:0x0000000C, global:0x0059E714, function:0x004B31A0, source:raw]
    // GUARD: Component 1 upper clamp: if a2[1] > 15.999512, this[0xE] = 0x7FFF. [field:this:0x0000000E, global:0x005ACC94, function:0x004B31A0, source:raw]
    // GUARD: Component 1 lower clamp: if a2[1] < -15.999512, this[0xE] = -32767. [field:this:0x0000000E, global:0x005ACC90, function:0x004B31A0, source:raw]
    // CALCULATION: Component 1 scale: this[0xE] = (int)(a2[1] * 2048.0), truncated to int16. [field:this:0x0000000E, global:0x0059E714, function:0x004B31A0, source:raw]
    // GUARD: Component 2 upper clamp: if a2[2] > 15.999512, this[0x10] = 0x7FFF and result = 0x7FFF. [field:this:0x00000010, global:0x005ACC94, function:0x004B31A0, source:raw]
    // GUARD: Component 2 lower clamp: if a2[2] < -15.999512, this[0x10] = -32767 and result = -32767. [field:this:0x00000010, global:0x005ACC90, function:0x004B31A0, source:raw]
    // CALCULATION: Component 2 scale: this[0x10] = (int)(a2[2] * 2048.0), truncated to int16; result = (int16)that value. [field:this:0x00000010, global:0x0059E714, function:0x004B31A0, source:raw]
    // RETURN: Return result, the third converted value. [function:0x004B31A0, source:raw]

    // Conservative worker pseudocode:
    //   comp0 = (a2[0] >  15.999512) ?  0x7FFF
    //        : (a2[0] < -15.999512) ? -32767
    //        : (int16)(a2[0] * 2048.0);
    //   this[0xC] = comp0;
    //   comp1 = (a2[1] >  15.999512) ?  0x7FFF
    //        : (a2[1] < -15.999512) ? -32767
    //        : (int16)(a2[1] * 2048.0);
    //   this[0xE] = comp1;
    //   comp2 = (a2[2] >  15.999512) ?  0x7FFF
    //        : (a2[2] < -15.999512) ? -32767
    //        : (int16)(a2[2] * 2048.0);
    //   this[0x10] = comp2;
    //   return comp2;
    // UNRESOLVED: The raw source renders the clamp and scale values as literals (15.999512, -15.999512, 2048.0); the mapping of the three read-only globals 0x0059E714, 0x005ACC90, 0x005ACC94 to those literals is DERIVED from the existing analysis (FloatToInt16QuantScale / ShortNormMin / VertexShortClampMax) and not established by the packet.
    // UNRESOLVED: The legacy ABI label 'FAIL_4b31a0' (abi:lead) is a failed-name placeholder and is not adopted; the proposed name follows the existing analysis fill (Float3ToInt16SaturationPack).
    // UNRESOLVED: The caller VehicleOrientationFromEulerAngles (004B2DD0) suggests the packed int16 values encode an orientation derived from Euler angles, but the consuming object type is unidentified.
}
