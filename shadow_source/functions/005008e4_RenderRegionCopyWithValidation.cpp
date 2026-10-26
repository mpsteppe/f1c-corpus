// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005008E4
// Canonical corpus name: sub_5008E4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5008E4_005008e4.c

void UnknownObject::RenderRegionCopyWithValidation()
{
    // Validated render-region copy. Initializes a 21-dword local state buffer, then guards that the three driver pointers a1, a4 and a5 are non-null. Negotiates the surface format via DirectXSurfaceFormatNegotiation(a4, a5, a9, 1). When negotiation succeeds, copies a 4-int source rectangle from a6 (or from buffer defaults when a6 is null) and bounds-checks it against the buffer's stored extents, returning the HRESULT-style error -2005530516 on a failed bounds check. Performs the actual copy through NetworkPacketSendReceive and returns 0 on success. Always tears down the local buffer with ArithmeticComparison_0f55 before returning.
    // CALL: Call F_7FieldInitializer on the local 21-dword buffer v12 to establish its default extents and state. [callee:0x00500F3C, source:raw]
    // GUARD: Guard that a1, a4 and a5 are all non-null; any null pointer jumps to the error path returning -2005530516. [source:raw, function:0x005008E4]
    // CALL: Negotiate the surface format with DirectXSurfaceFormatNegotiation(a4, a5, a9, 1); a negative result falls through to the error return. [callee:0x00502A15, source:raw]
    // ASSIGNMENT: When a6 is non-null, copy the four rectangle coordinates from a6[0..3] into v13..v16. [source:raw]
    // GUARD: Bounds-check the copied rectangle: any of v13<0, v15>v12[3], v13>v15, v14<0, v16>v12[4] or v14>v16 selects the error path (-2005530516). [source:raw, abi:lead]
    // ASSIGNMENT: When a6 is null, default the rectangle coordinates from the initialized buffer v12[6..9]. [source:raw]
    // CALL: Perform the region copy via NetworkPacketSendReceive(a1, a2, a3, v12[1], v12[0], v12[12], v12[2], &v13, a7, a8). [callee:0x0050070D, source:raw]
    // RETURN: Return 0 when the copy succeeded; otherwise return the propagated error code (v9 or -2005530516). [source:raw, caller:0x0053FED0]
    // CALL: Teardown: call ArithmeticComparison_0f55 on the local buffer v12 on every exit path. [callee:0x00500F55, source:raw]

    // Conservative worker pseudocode:
    //   int RenderRegionCopyWithValidation(a1, a2, a3, a4, a5, a6, a7, a8, a9) {
    //     int v12[21];
    //     int result;
    //     F_7FieldInitializer(v12);
    //     if (!a1 || !a4 || !a5) result = -2005530516;
    //     else {
    //       int v9 = DirectXSurfaceFormatNegotiation(a4, a5, a9, 1);
    //       if (v9 >= 0) {
    //         int v13, v14, v15, v16;
    //         if (a6) {
    //           v13 = a6[0]; v14 = a6[1]; v15 = a6[2]; v16 = a6[3];
    //           if (v13 < 0 || v15 > v12[3] || v13 > v15 || v14 < 0 || v16 > v12[4] || v14 > v16)
    //             result = -2005530516;
    //           else result = v9;
    //         } else {
    //           v13 = v12[6]; v14 = v12[7]; v15 = v12[8]; v16 = v12[9];
    //           result = v9;
    //         }
    //         if (v9 >= 0) {
    //           v9 = NetworkPacketSendReceive(a1, a2, a3, v12[1], v12[0], v12[12], v12[2], &v13, a7, a8);
    //           if (v9 >= 0) result = 0; else result = v9;
    //         }
    //       } else result = v9;
    //     }
    //     ArithmeticComparison_0f55(v12);
    //     return result;
    //   }
    // UNRESOLVED: Role of a2 and a3 in NetworkPacketSendReceive is caller-supplied and not identifiable here.
    // UNRESOLVED: The local buffer v12 is owned by F_7FieldInitializer/ArithmeticComparison_0f55; its field layout is external to this function.
    // UNRESOLVED: ABI lead name 'Render_Region_Copy_with_Validation' is LEGACY trust and matches the observed structure but is not independently confirmed.
}
