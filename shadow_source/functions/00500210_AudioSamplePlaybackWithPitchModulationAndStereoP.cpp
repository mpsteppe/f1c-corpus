// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00500210
// Canonical corpus name: AudioSamplePlaybackWithPitchModulationAndStereoP
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioSamplePlaybackWithPitchModulationAndStereoP_00500210.c

void UnknownObject::AudioSamplePlaybackWithPitchModulationAndStereoP()
{
    // Audio sample playback update with pitch modulation and stereo panning. Reads a packed control word at this+0x1B8; when its 6-bit mode field is zero it falls back to AudioSampleCrossFadeInterpolation. Otherwise it encodes a progress event via ProgressBarEventEncode, computes a cross-fade blend factor between this+0xC and this+0x1BC driven by the float view of a2, interpolates packed RGB color channels (fields 0x12..0x1C6) and Euler short channels (fields 0x1B..0x1CF), writes the converted RGB through FloatToRGBColorConversion into output+10, clamps and quantizes the three Euler channels into int16 at output+19/+21/+23, copies a short from this+0x1C0 to output+8, and returns 1.
    // CALCULATION: Read packed control word v4 = *(DWORD*)(this+440) and extract the 6-bit mode field v6 = (v4 >> 18) & 0x3F. [field:this:0x000001B8, source:raw]
    // GUARD: When v6 is zero, fall back: return AudioSampleCrossFadeInterpolation(this, a2, this+440, this+8, a3). [callee:0x004FF8F0, field:this:0x000001B8, source:raw]
    // CALL: Encode the playback event: ProgressBarEventEncode(a3, v4>>29, v6, (v4>>8)&0x3FF, low byte of v4, a2, 0). [callee:0x004B33B0, source:raw]
    // CALCULATION: Compute cross-fade blend: v8 = this[12] - this[444]; if v8 is 0 use (v28=0.0, v32=1.0), else v28 = (float a2 - this[444]) / v8 and v32 = 1.0 - v28. [field:this:0x0000000C, field:this:0x000001BC, source:raw]
    // CALCULATION: Assemble packed color words: current v9 = (this[22]<<16) + (this[20]&0xFF00) and target v11 = (this[454]<<16) + (this[452]&0xFF00). [field:this:0x00000014, field:this:0x00000016, field:this:0x000001C4, field:this:0x000001C6, source:raw]
    // CALCULATION: Blend RGB channels scaled by 1/32768: red v25 = (this[18]<<8)*v28 + (this[450]<<8)*v32; green v26 from packed v9/v11; blue v27 from v23 = (byte this[26]<<24)|((v10>>8)&0xFFFF00) and v13 = (byte this[458]<<24)|((this[454]>>8)&0xFFFF00). [field:this:0x00000012, field:this:0x0000001A, field:this:0x000001C2, field:this:0x000001CA, source:raw]
    // CALL: Convert the blended float RGB triple: FloatToRGBColorConversion((_DWORD*)(a3+10), &v25) writes the output color field. [callee:0x004B21F0, source:raw]
    // CALCULATION: Blend Euler short channels scaled by 1/2048: v25 = short this[459]*v32 + short this[27]*v28; v26 = short this[461]*v32 + short this[29]*v28; v27 = short this[463]*v32 + short this[31]*v28. [field:this:0x0000001B, field:this:0x0000001D, field:this:0x0000001F, field:this:0x000001CB, field:this:0x000001CD, field:this:0x000001CF, source:raw]
    // CALCULATION: Clamp and quantize each blended Euler channel: values in [-15.999, 15.999] scale by 2048.0 to int16, out-of-range becomes -32767 or 0x7FFF. [source:raw]
    // ASSIGNMENT: Write the quantized int16 values to the output: *(WORD*)(a3+19), *(WORD*)(a3+21), *(WORD*)(a3+23). [source:raw]
    // ASSIGNMENT: Copy a verbatim short: *(WORD*)(a3+8) = *(WORD*)(this+448). [field:this:0x000001C0, source:raw]
    // RETURN: Return 1 to signal success on the full playback path. [function:0x00500210, source:raw]

    // Conservative worker pseudocode:
    //   char sub_500210(int this, int a2, int a3) {
    //     unsigned v4 = *(DWORD*)(this + 0x1B8);
    //     int mode = (v4 >> 18) & 0x3F;
    //     if (!mode) return AudioSampleCrossFadeInterpolation(this, a2, this + 0x1B8, this + 8, a3);
    //     ProgressBarEventEncode(a3, v4 >> 29, mode, (v4 >> 8) & 0x3FF, (byte)v4, a2, 0);
    //     float t, w;
    //     float span = *(float*)(this + 12) - *(float*)(this + 0x1BC);
    //     if (span == 0.0) { t = 0.0; w = 1.0; }
    //     else { t = (*(float*)&a2 - *(float*)(this + 0x1BC)) / span; w = 1.0f - t; }
    //     // blend packed RGB channels (fields 0x12..0x1C6) scaled by 1/32768
    //     FloatToRGBColorConversion((_DWORD*)(a3 + 10), &rgb);
    //     // blend Euler shorts (fields 0x1B..0x1CF) scaled by 1/2048, clamp to
    //     // [-15.999, 15.999], quantize *2048.0 to int16 into a3+19/+21/+23
    //     *(WORD*)(a3 + 8) = *(WORD*)(this + 0x1C0);
    //     return 1;
    //   }
    // UNRESOLVED: The seven read-only float globals flt_59E43C, flt_59E440, flt_59E714, flt_59E718, flt_59E71C, flt_59E77C, flt_59E780 are flagged by the IDB but do not appear by name in the decompiled body; they presumably back the interpolation literals (1/32768, 1/2048, 15.999, 2048.0) but their exact binding is not shown in the packet source.
    // UNRESOLVED: The short copied verbatim from this+0x1C0 into output+8 is not named by the packet; its meaning (e.g. sample or pitch identifier) is unestablished.
    // UNRESOLVED: The 6-bit mode field (v4>>18)&0x3F selects between the cross-fade fallback and the full playback path, but the packet gives no enum of the mode values.
    // UNRESOLVED: The output object layout a3 (bytes +8..+23, plus the +10 RGB write) and the meaning of each packed color/Euler channel are only partially established by this packet; the three recorded callers are not analyzed here.
}
