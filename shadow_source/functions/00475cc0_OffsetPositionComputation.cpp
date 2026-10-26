// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475CC0
// Canonical corpus name: OffsetPositionComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OffsetPositionComputation_00475cc0.c

void UnknownObject::OffsetPositionComputation()
{
    // __stdcall helper that fills a two-dword output pair (a4) from an input position a1 and two range endpoints a2/a3. When the first dwords of both endpoints are equal the output is hardcoded to (10, 10); otherwise the first output dword is a1 and the second is a rounded interpolation between a2[1] and a3[1] weighted by (a3[0] - a1) over (a3[0] - a2[0]), using CRTFtol to convert the float result to int. Called by sub_475A90.
    // GUARD: Branch on equality of the first dwords of both endpoints: if *a2 == *a3 take the default branch, else the interpolation branch. [source:raw]
    // ASSIGNMENT: Default branch: write the constant pair (10, 10) into the output buffer a4 and a4[1]. [source:raw]
    // CALCULATION: Interpolation branch: read v4 = a3[1], then compute v5 = v4 - CRTFtol(((v4 - a2[1]) / (a3[0] - a2[0])) * (a3[0] - a1)). [source:raw]
    // CALL: Call CRTFtol (0x00587BDC) with the interpolated float value to obtain the int-truncated term used in v5. [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Interpolation branch: write *a4 = a1 and a4[1] = v5 into the output buffer. [source:raw]
    // RETURN: Return the output buffer pointer a4 in both branches. [source:raw]
    // CALL: Invoked by sub_475A90 (0x00475A90) to compute the offset position pair. [caller:0x00475A90, source:raw]

    // Conservative worker pseudocode:
    //   dword* sub_475CC0(int a1, dword* a2, dword* a3, dword* a4) {
    //     if (*a2 == *a3) {
    //       *a4 = 10; a4[1] = 10;
    //     } else {
    //       int v4 = a3[1];
    //       int v5 = v4 - CRTFtol((double)(v4 - a2[1]) / (double)(*a3 - *a2) * (double)(*a3 - a1));
    //       *a4 = a1; a4[1] = v5;
    //     }
    //     return a4;
    //   }
    // UNRESOLVED: Semantic meaning of the input position a1 and the two endpoint dword pairs a2/a3 (and the hardcoded 10 default) is caller-dependent and not established by this packet.
    // UNRESOLVED: Output pair is written as two dwords; whether it represents a screen or track-space coordinate pair is unknown.
}
