// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2750
// Canonical corpus name: FloatToShortClampedConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToShortClampedConversion_004b2750.c

void UnknownObject::FloatToShortClampedConversion()
{
    // Converts two floats from a caller-supplied array (a2[0] and a2[2]) into signed 16-bit fixed-point shorts stored at this[20] (offset 0x28) and this[21] (offset 0x2A). Each float is two-sided range checked against 63.998047; in-range values are multiplied by 512.0 and truncated, out-of-range values clamp to 0x7FFF or -32767. The middle element a2[1] is not read.
    // GUARD: Upper-range check on a2[0]: if *a2 > 63.998047 take the high-clamp branch (0x7FFF). [source:raw, global:0x005ACCBC]
    // GUARD: Lower-range check on a2[0]: if *a2 < -63.998047 take the low-clamp branch (-32767). [source:raw, global:0x005ACCB8]
    // CALCULATION: In-range path for a2[0]: v6 = *a2 * 512.0, then truncate to a short via (int) cast. [source:raw, global:0x005ACCB4]
    // ASSIGNMENT: Write the encoded/clamped short for a2[0] into this[20] at offset 0x28 (written unconditionally). [source:raw, field:this:0x00000028]
    // GUARD: Upper-range check on a2[2]: if a2[2] > 63.998047 take the high-clamp branch (0x7FFF). [source:raw, global:0x005ACCBC]
    // GUARD: Lower-range check on a2[2]: if a2[2] < -63.998047 take the low-clamp branch (-32767). [source:raw, global:0x005ACCB8]
    // CALCULATION: In-range path for a2[2]: v7 = a2[2] * 512.0, then truncate to a short via (int) cast. [source:raw, global:0x005ACCB4]
    // ASSIGNMENT: Write the encoded/clamped short for a2[2] into this[21] at offset 0x2A (written unconditionally). [source:raw, field:this:0x0000002A]
    // RETURN: Return the second encoded short value as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   short sub_4B2750(unsigned short *out, float *src) {
    //     short result;
    //     float scaled;
    //     if (*src > 63.998047) result = 0x7FFF;
    //     else if (*src < -63.998047) result = -32767;
    //     else { scaled = *src * 512.0; result = (short)(int)scaled; }
    //     out[20] = result;
    //     if (src[2] > 63.998047) result = 0x7FFF;
    //     else if (src[2] < -63.998047) result = -32767;
    //     else { scaled = src[2] * 512.0; result = (short)(int)scaled; }
    //     out[21] = result;
    //     return result;
    //   }
    // UNRESOLVED: a2[1] is not processed; only a2[0] and a2[2] are converted.
    // UNRESOLVED: Identity and layout of the destination object are unknown (owner UNKNOWN); offsets 0x28 and 0x2A hold 16-bit shorts.
    // UNRESOLVED: The three float globals (flt_5ACCB4, flt_5ACCB8, flt_5ACCBC) back the scale/clamp constants, but their values are inlined as literals in the raw source.
    // UNRESOLVED: Callers VehicleOrientationFromEulerAngles (0x004B2DD0), sub_4B32A0 (0x004B32A0) and SetupCarLightingAndRender (0x004C71C0) all write the same fields; semantic reuse is caller-dependent.
}
