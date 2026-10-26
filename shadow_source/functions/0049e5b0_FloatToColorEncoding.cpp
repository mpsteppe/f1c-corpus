// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E5B0
// Canonical corpus name: FloatToColorEncoding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToColorEncoding_0049e5b0.c

void UnknownObject::FloatToColorEncoding()
{
    // Maps a float in the range 30.0..150.0 to a 32-bit ARGB gradient color: low values encode blue, mid-range values encode green, high values encode red. Out-of-range inputs are clamped to 30.0 or 150.0 before the channel is computed via CRTFtol.
    // GUARD: Clamp an input below 30.0 up to 30.0 before encoding the low (blue) range. [source:raw]
    // GUARD: Clamp an input above 150.0 down to 150.0 before encoding the high (red) range. [source:raw]
    // CALCULATION: Low (blue) range branch: CRTFtol((value - 30.0) * 0.025 * 255.0) shifted left 16 bits combined with 0xFF0000FF. [callee:0x00587BDC, source:raw]
    // CALCULATION: High (red) range branch: CRTFtol((value - 110.0) * 0.025 * 255.0) combined with 0xFFFFFF00 then shifted left 8 bits. [callee:0x00587BDC, source:raw]
    // GUARD: Select the blue-gradient branch when the value is between 30.0 and 70.0 (below 70.0). [source:raw]
    // GUARD: Select the red-gradient branch when the value is 110.0 or greater. [source:raw]
    // CALCULATION: Mid-range green branch: CRTFtol((1.0 - (value - 70.0) * 0.025) * 255.0) combined with 0xFFFF0000. [callee:0x00587BDC, source:raw]

    // Conservative worker pseudocode:
    //   value = a1
    //   if value < 30.0:
    //       value = 30.0
    //       return (CRTFtol((value - 30.0) * 0.025 * 255.0) << 16) | 0xFF0000FF
    //   if value > 150.0:
    //       value = 150.0
    //       return (CRTFtol((value - 110.0) * 0.025 * 255.0) | 0xFFFFFF00) << 8
    //   if value < 70.0:
    //       return (CRTFtol((value - 30.0) * 0.025 * 255.0) << 16) | 0xFF0000FF
    //   if value >= 110.0:
    //       return (CRTFtol((value - 110.0) * 0.025 * 255.0) | 0xFFFFFF00) << 8
    //   return CRTFtol((1.0 - (value - 70.0) * 0.025) * 255.0) | 0xFFFF0000
    // UNRESOLVED: All seven read-only float globals (flt_59E43C, flt_59E468, flt_59E87C, flt_59FEC8, flt_5ACB00, flt_5ACB04, flt_5ACB08) are referenced by the packet but absent from the raw source, which shows inlined float literals; the exact global-to-literal mapping is not derivable from this packet's evidence.
    // UNRESOLVED: The caller SuspensionCornerCheck (0x0049E570) feeds a suspension quantity; whether this function encodes a full ARGB color or a single per-channel value is unverified.
}
