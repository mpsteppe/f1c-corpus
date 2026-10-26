// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C7C0
// Canonical corpus name: ShortToFloatConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortToFloatConversion_0045c7c0.c

void UnknownObject::ShortToFloatConversion()
{
    // Converts a 16-bit signed value a1 into a float scaled by 0.001 (the constant at flt_59E600) and stores the result through output pointer a2. Also returns the sign-extended integer form of a1. Called from terrain roughness/height sampling paths, suggesting a scaled unit conversion for short-encoded terrain data.
    // CALCULATION: Store (double)a1 * 0.001 as a float into *a2, reading the scale constant 0.001 from flt_59E600. [global:0x0059E600, source:raw]
    // RETURN: Return a1 sign-extended to int (result initialized from a1). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_45C7C0(__int16 a1, float *a2) {
    //     *a2 = (float)((double)a1 * 0.001);
    //     return (int)a1;
    //   }
    // UNRESOLVED: Physical meaning of the 0.001 scale (e.g. meters per short unit, or a general per-caller scale) is not established.
    // UNRESOLVED: Whether the integer return value is used by callers or only the out-parameter matters is unknown.
    // UNRESOLVED: The two callers (TerrainSurfaceRoughnessHeightSampling 0x0045CA20, ShortArrayLookupAndZeroCheck 0x0045CBF0) are unverified-name functions.
}
