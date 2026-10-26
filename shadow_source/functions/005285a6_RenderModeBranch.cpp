// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005285A6
// Canonical corpus name: RenderModeBranch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderModeBranch_005285a6.c

void UnknownObject::RenderModeBranch()
{
    // Structural twin of RenderingBranchOnDAT005d79dc (packet 0052855a): branches between two audio codec transforms (QuaternionMultiplySurfaceSample and MPEGAudioLayer3IMDCT_b206) on the same global flag byte_5D79DC. Reads an output buffer offset from a1+0x11C and adds 128, reads an input value from a2+80, and returns the selected transform's result.
    // CALCULATION: v7 = *(DWORD*)(a1 + 0x11C) + 128; reads field this+0x11C and adds 128 to form the output buffer offset used as the final argument of both transforms [field:this:0x0000011C, source:raw]
    // CALCULATION: v6 = *(DWORD*)(a2 + 80); reads an input value from an unmodeled second base and forwards it to the selected transform [source:raw]
    // GUARD: Tests global byte_5D79DC; nonzero selects QuaternionMultiplySurfaceSample, zero selects MPEGAudioLayer3IMDCT_b206 [global:0x005D79DC, function:0x005285A6, source:raw]
    // CALL: When byte_5D79DC is nonzero: QuaternionMultiplySurfaceSample(a3, v8, v6, a4, a5, v7) [callee:0x0052B561, source:raw]
    // CALL: When byte_5D79DC is zero: MPEGAudioLayer3IMDCT_b206(a3, v8, v6, a4, a5, v7) [callee:0x0052B206, source:raw]
    // RETURN: Returns the selected transform's result directly [function:0x005285A6, source:raw]

    // Conservative worker pseudocode:
    //   v7 = *(DWORD*)(a1 + 0x11C) + 128;
    //   v6 = *(DWORD*)(a2 + 80);
    //   if (byte_5D79DC) return QuaternionMultiplySurfaceSample(a3, v8, v6, a4, a5, v7);
    //   return MPEGAudioLayer3IMDCT_b206(a3, v8, v6, a4, a5, v7);
    // UNRESOLVED: The callee names QuaternionMultiplySurfaceSample and MPEGAudioLayer3IMDCT_b206 are legacy ABI labels; their real audio decode roles are not confirmed by this packet
    // UNRESOLVED: The exact meaning of byte_5D79DC is DERIVED from its branch position; no writer evidence in this packet
    // UNRESOLVED: The a2+80 read (v6) and the a3/a4/a5 argument roles have no field evidence refs; semantics inferred only from call order
    // UNRESOLVED: The v8[136] scratch buffer's role is not evidenced
    // UNRESOLVED: No callers recorded; frame-path relationship unknown
}
