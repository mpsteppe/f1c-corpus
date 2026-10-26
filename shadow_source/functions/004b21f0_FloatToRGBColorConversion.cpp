// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B21F0
// Canonical corpus name: FloatToRGBColorConversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToRGBColorConversion_004b21f0.c

void UnknownObject::FloatToRGBColorConversion()
{
    // Converts three float color-channel values (a2[0], a2[1], a2[2]) into a packed 40-bit RGB color stored across three output fields. Each channel is clamped to the interval [-65535.988, 65535.988] using the IDB color constants (flt_5ACC88 clamp lower, flt_5ACC8C clamp max, DERIVED), with out-of-range values saturated to INT_MIN (-2147483647) or INT_MAX (0x7FFFFFFF). In-range channels are scaled by the color-channel multiplier 32768.0 (flt_5ACC84, DERIVED) and truncated to int. The three scaled ints are then bit-packed: word 0 combines channels 0 and 1, word 1 combines channels 1 and 2, and the low byte of word 2 is stored at offset 0x8. Returns the top byte of the third scaled channel.
    // GUARD: Clamp each of the three input channel floats to the interval [-65535.988, 65535.988]; values below the lower bound saturate to INT_MIN (-2147483647) and values above the upper bound saturate to INT_MAX (0x7FFFFFFF). The clamp bounds are supplied by the IDB color constants flt_5ACC88 (clamp lower) and flt_5ACC8C (clamp max). [source:raw, global:0x005ACC88, global:0x005ACC8C]
    // CALCULATION: Scale each in-range channel by the color-channel multiplier 32768.0 (flt_5ACC84) and truncate the product to int, producing the three quantized ints v3, v4, v5. [source:raw, global:0x005ACC84]
    // ASSIGNMENT: Pack word 0 at offset 0x0: *this = ((v4 & 0xFFFFFF00) << 16) + ((v3 >> 8) & 0xFFFFFF), combining the high bits of channel 1 and channel 0. [source:raw, field:this:0x00000000]
    // ASSIGNMENT: Pack word 1 at offset 0x4: this[1] = ((v5 & 0xFFFFFF00) << 8) + HIWORD(v4), combining the high bits of channel 2 and the high word of channel 1. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Store the top byte of the third channel at offset 0x8: *((_BYTE *)this + 8) = v5 >> 24. [source:raw, field:this:0x00000008]
    // RETURN: Return the stored top byte (v5 >> 24) as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   int FloatToRGBColorConversion(int this, float *a2) {
    //     int v3 = (a2[0] > 65535.988) ? 0x7FFFFFFF : (a2[0] < -65535.988) ? -2147483647 : (int)(a2[0] * 32768.0);
    //     int v4 = (a2[1] > 65535.988) ? 0x7FFFFFFF : (a2[1] < -65535.988) ? -2147483647 : (int)(a2[1] * 32768.0);
    //     int v5 = (a2[2] > 65535.988) ? 0x7FFFFFFF : (a2[2] < -65535.988) ? -2147483647 : (int)(a2[2] * 32768.0);
    //     *(int*)this = ((v4 & 0xFFFFFF00) << 16) + ((v3 >> 8) & 0xFFFFFF);
    //     *(int*)(this + 4) = ((v5 & 0xFFFFFF00) << 8) + (v4 >> 16);
    //     *(byte*)(this + 8) = v5 >> 24;
    //     return v5 >> 24;
    //   }
    // UNRESOLVED: The three float constants (65535.988, 32768.0) appear inline in the decompiled body; their mapping to the IDB globals flt_5ACC84/5ACC88/5ACC8C (multiplier, clamp lower, clamp max) is DERIVED from the existing analysis, not stated in the raw source.
    // UNRESOLVED: The destination object (this) is an unknown 40-bit packed-color consumer; no owning class is established.
}
