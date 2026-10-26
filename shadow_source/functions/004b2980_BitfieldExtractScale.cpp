// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2980
// Canonical corpus name: BitfieldExtractScale
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitfieldExtractScale_004b2980.c

void UnknownObject::BitfieldExtractScale()
{
    // Extracts the upper 15 bits of the bitfield dword at this+0x2C by shifting right 17, converts the remaining unsigned value to double, and scales it by 0.1 (1/10). Returns the scaled double. Called per-frame from vehicle physics timestep, vector-to-short conversion and audio cross-fade paths; the skeleton fill treats it as the inverse of a float-to-bitfield pack.
    // CALCULATION: Read the bitfield dword at this+0x2C and extract bits 17-31 by shifting right 17, yielding a 15-bit unsigned value [field:this:0x0000002C, source:raw]
    // CALCULATION: Convert the extracted value to double and scale it by 0.1, the read-only float constant backed by a module global [global:0x0059E84C, source:raw]
    // RETURN: Return the scaled double; no guard conditions, reads directly. Called from VectorToShort3Conversion, VehiclePhysicsTimeStep and AudioSampleCrossFadeInterpolation [caller:0x004B2C80, caller:0x004C73F0, caller:0x004FF8F0, function:0x004B2980, source:raw]

    // Conservative worker pseudocode:
    //   return (double)(this[11] >> 17) * 0.1;
    // UNRESOLVED: The purpose of the packed 15-bit value (its source field and what the 0.1 scale maps back from) is not documented in this function's own evidence; the skeleton fill's inverse-of-pack claim is external prose, not packet evidence
}
