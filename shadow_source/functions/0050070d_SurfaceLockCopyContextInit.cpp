// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050070D
// Canonical corpus name: NetworkPacketSendReceive
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkPacketSendReceive_0050070d.c

void UnknownObject::SurfaceLockCopyContextInit()
{
    // __stdcall routine that locks a D3D texture surface (D3DTextureSurfaceLockCopy), fills a header and payload descriptor from arguments, initializes a D3D context (D3DContextInit), then unconditionally tears down the render resources and dual-vtable objects. Fails fast with -2005530516 when a1 is null or when a4/a8 are null, and propagates negative HRESULT-style results from the two D3D calls. a9 defaults to 524292 when passed as -1.
    // CALL: Call ZeroPairInit on local v20 before use. [callee:0x00502BEA, source:raw]
    // CALL: Call ZeroInit4Ints_64bf on local v19 before use. [callee:0x005064BF, source:raw]
    // ASSIGNMENT: Initialize result v10 to 0 (success default). [source:raw]
    // GUARD: Outer guard on a1: when a1 is null set v10 = -2005530516 (failure). [source:raw]
    // GUARD: Inner guard on a4 and a8: when either is null set v10 = -2005530516. [source:raw]
    // GUARD: Guard on a9: when a9 == -1 substitute the default 524292. [source:raw]
    // CALL: Call D3DTextureSurfaceLockCopy(v13, a1, a2, a3, 0, 0) to lock and copy the surface. [callee:0x00506559, source:raw]
    // GUARD: When the lock/copy result is negative, propagate it into v10. [source:raw]
    // ASSIGNMENT: Fill descriptor header v14: v14[0]=a4, v14[1]=a5, v14[2]=a6, v14[3]=0. [source:raw]
    // ASSIGNMENT: Fill descriptor payload v15 from a8[0..3], then 0 and 1; copy it as 24 bytes into v16. [source:raw]
    // ASSIGNMENT: Store remaining arguments into locals: v17 = a10, v18 = a7. [source:raw]
    // CALL: Call D3DContextInit(v13, v14, a9) to initialize the D3D context with the descriptor. [callee:0x005063A5, source:raw]
    // GUARD: When the context-init result is negative, propagate it into v10. [source:raw]
    // CALL: Call j_RenderResourceTeardown(v19) unconditionally. [callee:0x00506554, source:raw]
    // CALL: Call DualVTableDestructor(v20) unconditionally. [callee:0x00502BF4, source:raw]
    // RETURN: Return v10: 0 on success, -2005530516 on invalid argument, or the propagated negative D3D result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_50070D(int a1, int a2, int a3, int a4, int a5, int a6, int a7,
    //                 _DWORD* a8, int a9, int a10) {
    //     _BYTE v13[76]; _DWORD v14[4]; _DWORD v15[6]; _BYTE v16[24];
    //     _BYTE v19[16]; _BYTE v20[12];
    //     ZeroPairInit(v20);
    //     ZeroInit4Ints_64bf(v19);
    //     int v10 = 0;
    //     if (a1 && a4 && a8) {
    //       if (a9 == -1) a9 = 524292;
    //       int r = D3DTextureSurfaceLockCopy(v13, a1, a2, a3, 0, 0);
    //       if (r < 0) v10 = r;
    //       else {
    //         v14[0] = a4; v14[1] = a5; v14[2] = a6; v14[3] = 0;
    //         v15[0] = a8[0]; v15[1] = a8[1]; v15[2] = a8[2]; v15[3] = a8[3];
    //         v15[4] = 0; v15[5] = 1;
    //         qmemcpy(v16, v15, sizeof(v16));
    //         v17 = a10; v18 = a7;
    //         int r2 = D3DContextInit(v13, v14, a9);
    //         if (r2 < 0) v10 = r2;
    //       }
    //     } else {
    //       v10 = -2005530516;
    //     }
    //     j_RenderResourceTeardown(v19);
    //     DualVTableDestructor(v20);
    //     return v10;
    //   }
    // UNRESOLVED: Meaning of arguments a1..a10 and the descriptor layout v14/v15 is only structurally inferred.
    // UNRESOLVED: Why a9 defaults to 524292 is unknown.
    // UNRESOLVED: Owner object type is unknown; the prelabel structural-twin hint to 00441600 is unverified.
    // UNRESOLVED: Interpretation of v16 (24-byte payload) consumed by D3DContextInit depends on the callee.
}
