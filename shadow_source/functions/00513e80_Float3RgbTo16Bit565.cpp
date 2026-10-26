// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513E80
// Canonical corpus name: sub_513E80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_513E80_00513e80.c

void UnknownObject::Float3RgbTo16Bit565()
{
    // Converts three floats at this+0x0/+0x4/+0x8 (red, green, blue) into a packed 16-bit 5:6:5 colour. Each component is clamped to the [0,1] range, quantized to its bit depth with a +0.5 rounding offset (R and B scale by 31, G by 63), and the results are combined as (R<<11)|(G<<5)|B. A call to FPUControlWordMerger() controls the FPU rounding mode used during the float-to-int truncations.
    // GUARD: Clamp red at this+0x0: values below 0.0 are forced to 0.0, values above 1.0 are forced to 1.0, otherwise the value passes through unchanged [field:this:0x00000000, source:raw]
    // GUARD: Clamp green at this+0x4: values below 0.0 are forced to 0.0, values above 1.0 are forced to 1.0, otherwise the value passes through unchanged [field:this:0x00000004, source:raw]
    // GUARD: Clamp blue at this+0x8: values below 0.0 are forced to 0.0, values above 1.0 are forced to 1.0, otherwise the value passes through unchanged [field:this:0x00000008, source:raw]
    // CALL: FPUControlWordMerger() establishes the FPU rounding mode before the float-to-integer quantizations; the fill ties it to the FPU control-word store at dword_8B00A0 [callee:0x00513E5D, global:0x008B00A0, source:raw]
    // CALCULATION: Quantize clamped red to 5 bits: floor(v6 * 31.0 + 0.5) where 31.0 is the 5-bit scale factor (flt_5ACCD0 per the fill) [field:this:0x00000000, global:0x005ACCD0, source:raw]
    // CALCULATION: Quantize clamped green to 6 bits: floor(v7 * 63.0 + 0.5) where 63.0 is the 6-bit scale factor (flt_5ACCD8 per the fill) [field:this:0x00000004, global:0x005ACCD8, source:raw]
    // CALCULATION: Quantize clamped blue to 5 bits: floor(v8 * 31.0 + 0.5) using the same 5-bit scale factor as red [field:this:0x00000008, global:0x005ACCD0, source:raw]
    // RETURN: Pack the three quantized components into one 16-bit 5:6:5 value: (blue) | ((green | (red << 6)) << 5), i.e. R occupies bits 11-15, G bits 5-10, B bits 0-4; used by TextureFilterAndLayerCompositing (005147ea) [function:0x00513E80, caller:0x005147EA, source:raw]

    // Conservative worker pseudocode:
    //   float r = clamp01(this[0]);
    //   float g = clamp01(this[1]);
    //   float b = clamp01(this[2]);
    //   FPUControlWordMerger();
    //   int r5 = (int)(r * 31.0 + 0.5);
    //   int g6 = (int)(g * 63.0 + 0.5);
    //   int b5 = (int)(b * 31.0 + 0.5);
    //   return (r5 << 11) | (g6 << 5) | b5;
    // UNRESOLVED: Three read-only globals (flt_59E43C, flt_59E440, flt_59E450) are flagged by packet facts but appear nowhere in the raw decompiled source; the fill labels them as physics contact thresholds and a degrees-to-radians constant, which look unrelated to colour quantization and cannot be verified from this packet
}
