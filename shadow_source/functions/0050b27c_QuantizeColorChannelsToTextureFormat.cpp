// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B27C
// Canonical corpus name: TextureDimensionSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureDimensionSetup_0050b27c.c

void UnknownObject::QuantizeColorChannelsToTextureFormat()
{
    // Quantizes four float RGBA channel values to a fixed-point texture format. Reads the format identifier at this+4; if it equals 844388420 or 861165636 the per-channel maximum is 15.0, otherwise 255.0, stored at this+4204 (0x106C) with its reciprocal at this+4208 (0x1070). The R channel (this+28) is quantized to 5 bits (round(value*31+0.5) scaled by 1/31), G (this+32) to 6 bits (round(value*63+0.5) scaled by 1/63), B (this+36) to 5 bits, and A (this+40) to the format maximum (round(max*value+0.5) scaled by the reciprocal). Returns the this pointer.
    // ASSIGNMENT: Read the format identifier dword from this+4. [source:raw, field:this:0x00000004]
    // GUARD: Format gate: if the identifier equals 844388420 or 861165636 the channel maximum is 15.0, else 255.0. [source:raw]
    // ASSIGNMENT: Store the selected channel maximum at this+4204 (0x106C). [source:raw, field:this:0x0000106C]
    // CALCULATION: Store the reciprocal: this+4208 (0x1070) = 1.0 / this+4204. [source:raw, field:this:0x0000106C, field:this:0x00001070]
    // CALCULATION: Quantize R: v7 = this+28 * 31.0 + 0.5; this+28 = trunc(v7) * 0.032258064 (5-bit round-trip). [source:raw, field:this:0x0000001C]
    // CALCULATION: Quantize G: v4 = this+32 * 63.0 + 0.5; this+32 = trunc(v4) * 0.015873017 (6-bit round-trip). [source:raw, field:this:0x00000020]
    // CALCULATION: Quantize B: v5 = this+36 * 31.0 + 0.5; this+36 = trunc(v5) * 0.032258064 (5-bit round-trip). [source:raw, field:this:0x00000024]
    // CALCULATION: Quantize A: v6 = this+4204 * this+40 + 0.5; this+40 = trunc(v6) * this+4208 (quantized to the format maximum). [source:raw, field:this:0x00000028, field:this:0x0000106C, field:this:0x00001070]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int fmt = this->formatId;  // field 0x4
    //   float maxValue = (fmt == 844388420 || fmt == 861165636) ? 15.0 : 255.0;
    //   this->maxChannelValue = maxValue;       // field 0x106C
    //   this->reciprocalMax = 1.0 / maxValue;   // field 0x1070
    //   this->r = (float)(int)(this->r * 31.0 + 0.5) * 0.032258064;   // 5-bit, field 0x1C
    //   this->g = (float)(int)(this->g * 63.0 + 0.5) * 0.015873017;   // 6-bit, field 0x20
    //   this->b = (float)(int)(this->b * 31.0 + 0.5) * 0.032258064;   // 5-bit, field 0x24
    //   this->a = (float)(int)(maxValue * this->a + 0.5) * this->reciprocalMax;  // field 0x28
    //   return this;
    // UNRESOLVED: Seven read-only float globals (flt_59E450, flt_59E8D8, flt_59FEC8, flt_5ACCD0, flt_5ACCD4, flt_5ACCD8, flt_5ACCDC) are flagged by packet facts but appear nowhere in the raw decompiled source; the quantization literals (31.0, 63.0, 0.032258064, 0.015873017, 15.0, 255.0, 0.5) may have been hoisted from them by the original compiler, but that is not verifiable here.
    // UNRESOLVED: The format identifiers 844388420 and 861165636 are treated as opaque; their FourCC-like meaning (selecting 4-bit vs 8-bit alpha) is inferred, not evidenced.
    // UNRESOLVED: The target texture format the quantized channels feed and the consuming renderer are unknown.
}
