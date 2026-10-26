// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2310
// Canonical corpus name: sub_4B2310
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B2310_004b2310.c

void UnknownObject::FloatToShortNormalizedConversion()
{
    // Copies three dwords from source a2 into output this, then converts three float inputs a3[0..2] into signed 16-bit values stored at this+0xC/0xE/0x10. Each float is clamped to the symmetric range guarded by flt_5ACC90/flt_5ACC94, scaled by 2048.0 (flt_59E714), truncated to int16, and saturated to -32767/0x7FFF on out-of-range inputs. Returns the final converted value.
    // ASSIGNMENT: Copy the three source dwords a2[0], a2[1], a2[2] into this[0], this[1], this[2]. [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // GUARD: Clamp guard for a3[0]: if it exceeds the upper clamp limit (flt_5ACC94) saturate to 0x7FFF; if below the lower clamp limit (flt_5ACC90) saturate to -32767. [source:raw, global:0x005ACC90, global:0x005ACC94]
    // CALCULATION: Scale the in-range a3[0] value by the quant scale 2048.0 (flt_59E714) and truncate the product to int16. [source:raw, global:0x0059E714]
    // ASSIGNMENT: Store the converted first value as a 16-bit word at this+0xC. [source:raw, field:this:0x0000000C]
    // GUARD: Clamp guard for a3[1]: same upper/lower saturation to 0x7FFF / -32767 against flt_5ACC94 / flt_5ACC90. [source:raw, global:0x005ACC90, global:0x005ACC94]
    // CALCULATION: Scale the in-range a3[1] value by 2048.0 (flt_59E714) and truncate the product to int16. [source:raw, global:0x0059E714]
    // ASSIGNMENT: Store the converted second value as a 16-bit word at this+0xE. [source:raw, field:this:0x0000000E]
    // GUARD: Clamp guard for a3[2]: saturate to 0x7FFF / -32767 using flt_5ACC94 / flt_5ACC90, and mirror the saturated value into the return result. [source:raw, global:0x005ACC90, global:0x005ACC94]
    // CALCULATION: Scale the in-range a3[2] value by 2048.0 (flt_59E714), truncate to int16, and use it as the return result. [source:raw, global:0x0059E714]
    // ASSIGNMENT: Store the converted third value as a 16-bit word at this+0x10. [source:raw, field:this:0x00000010]
    // RETURN: Return the third converted value (saturated -32767 / 0x7FFF or the scaled int16 result). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B2310(_DWORD *out, _DWORD *src, float *in) {
    //     out[0] = src[0]; out[1] = src[1]; out[2] = src[2];
    //     out[3] = clamp_scale_int16(in[0]);
    //     out[3+1] = clamp_scale_int16(in[1]);
    //     int last = clamp_scale_int16(in[2]);
    //     ((_WORD *)out)[8] = last;
    //     return last;
    //   }
    //   // clamp_scale_int16: saturate to -32767/0x7FFF, else truncate(in * 2048.0)
    // UNRESOLVED: Semantic type of the 3 dwords copied verbatim and the 3 float-to-int16 values (candidate: packed vertex/vector data) is not determined by this function alone.
    // UNRESOLVED: Whether the -32767/0x7FFF saturation endpoints are exact hardware or convention-dependent is unverified.
}
