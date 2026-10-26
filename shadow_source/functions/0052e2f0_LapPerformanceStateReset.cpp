// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E2F0
// Canonical corpus name: LapPerformanceStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LapPerformanceStateReset_0052e2f0.c

void UnknownObject::LapPerformanceStateReset()
{
    // Straight-line state reset on an MPEG-audio lap/performance tracking object: copies the current frame/buffer-level value from field +0x249C into the tracking field +0x24E8, then zeroes the frame bit-position, stream bit-position, accumulated byte-position, and frame-count fields (+0x24A8, +0x24AC, +0x24B4, +0x24E4). Returns constant 0. Called during decoder open paths by CMpegBase_Open and CMpegFilePlayer_Open.
    // ASSIGNMENT: Copy this[2343] (+0x249C) into this[2362] (+0x24E8): the tracking field takes the current frame/buffer-level value before the counters are cleared [field:this:0x0000249C, field:this:0x000024E8, source:raw]
    // ASSIGNMENT: Set this[2347] (+0x24AC) to 0: stream bit position reset [field:this:0x000024AC, source:raw]
    // ASSIGNMENT: Set this[2346] (+0x24A8) to 0: bit position in current frame reset [field:this:0x000024A8, source:raw]
    // ASSIGNMENT: Set this[2361] (+0x24E4) to 0: frame count reset [field:this:0x000024E4, source:raw]
    // ASSIGNMENT: Set this[2349] (+0x24B4) to 0: accumulated byte position reset [field:this:0x000024B4, source:raw]
    // RETURN: Return constant 0; no guard gates any of the writes, so every field is always reset [source:raw]
    // CALL: Invoked by CMpegBase_Open (0052e090) during the decoder-open path [caller:0x0052E090, source:raw]
    // CALL: Invoked by CMpegFilePlayer_Open (0052e1d0) during the file-player open path [caller:0x0052E1D0, source:raw]

    // Conservative worker pseudocode:
    //   this[2362] = this[2343];
    //   this[2347] = 0;
    //   this[2346] = 0;
    //   this[2361] = 0;
    //   this[2349] = 0;
    //   return 0;
    // UNRESOLVED: The object type and the semantic role of the +0x249C source value versus the +0x24E8 tracking field are not evidenced here; the MPEG lap/performance naming is inherited from the prelabel and the fill prose, not from the raw body
}
