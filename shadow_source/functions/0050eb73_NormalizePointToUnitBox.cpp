// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050EB73
// Canonical corpus name: sub_50EB73
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50EB73_0050eb73.c

void UnknownObject::NormalizePointToUnitBox()
{
    // Normalizes three input components from a2 into a1 so the result is centered on a unit range, driven by scale/min-max terms read from a box/range struct at a3. The x and y components are centered to [-1,1] by a (value - origin) * 2 / scale form, while the z component is scaled into [0,1] between two float bounds at a3+16 and a3+20. A flag switch built from a4/a5/a6 selects which of two transformation thunks run before the normalization: non-zero flag combinations dispatch through jump table jpt_50EBB0 to conditionally call ThunkToFUN0050cba3 and/or ThunkToFUN0050d0afViaGlobalPointer. A final transform thunk ThunkToThunkFUN0050c5b0 always runs and the output pointer a1 is returned.
    // GUARD: Dispatches on the combined flag (a4!=0) | (2*((a5!=0) | (2*(a6!=0)))) through the jump table jpt_50EBB0; the default case runs no conditional transform [global:0x0050ECF9, source:raw]
    // CALL: Flag-dependent transform ThunkToFUN0050cba3 runs once for combined values 3/5/6 and twice for value 7, never for 1/2/4 [callee:0x0050CBB0, source:raw]
    // CALL: ThunkToFUN0050d0afViaGlobalPointer runs for every non-default non-zero combined flag value (1/2/3/4/5/6/7) [callee:0x0050D0BC, source:raw]
    // GUARD: Normalization block executes only when a3 is non-null [source:raw]
    // CALCULATION: x component: v6 = a2[0] - *(unsigned int*)a3; a1[0] = v6/(double)*(unsigned int*)(a3+8) + v6/(double)*(unsigned int*)(a3+8) - 1.0, writing field base this+0 [field:this:0x00000000, source:raw]
    // CALCULATION: y component: v7 = a2[1] - *(unsigned int*)(a3+4); a1[1] = -(v7/(double)*(unsigned int*)(a3+12) + v7/(double)*(unsigned int*)(a3+12) - 1.0), writing field base this+4 [field:this:0x00000004, source:raw]
    // CALCULATION: z component: a1[2] = (a2[2] - *(float*)(a3+16)) / (*(float*)(a3+20) - *(float*)(a3+16)), writing field base this+8 [field:this:0x00000008, source:raw]
    // CALL: Always-called transform thunk ThunkToThunkFUN0050c5b0 runs after the normalization block [callee:0x0050C5BD, source:raw]
    // RETURN: Returns a1, the output vector holding the normalized components [source:raw]

    // Conservative worker pseudocode:
    //   combined = (a4 != 0) | (2 * ((a5 != 0) | (2 * (a6 != 0))));
    //   switch (combined) {
    //     case 1: case 2: case 4: ThunkToFUN0050d0afViaGlobalPointer(); break;
    //     case 3: case 5: case 6: ThunkToFUN0050cba3(); ThunkToFUN0050d0afViaGlobalPointer(); break;
    //     case 7: ThunkToFUN0050cba3(); ThunkToFUN0050cba3(); ThunkToFUN0050d0afViaGlobalPointer(); break;
    //     default: break;
    //   }
    //   if (a3) {
    //     v6 = a2[0] - *(unsigned int*)a3;
    //     a1[0] = v6/(double)*(unsigned int*)(a3+8) + v6/(double)*(unsigned int*)(a3+8) - 1.0;
    //     v7 = a2[1] - *(unsigned int*)(a3+4);
    //     a1[1] = -(v7/(double)*(unsigned int*)(a3+12) + v7/(double)*(unsigned int*)(a3+12) - 1.0);
    //     a1[2] = (a2[2] - *(float*)(a3+16)) / (*(float*)(a3+20) - *(float*)(a3+16));
    //   }
    //   ThunkToThunkFUN0050c5b0();
    //   return a1;
    // UNRESOLVED: Two read-only globals (flt_59E43C, flt_5ADB14) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them a physics threshold and 360.0 degree wrap, neither verifiable from this packet
    // UNRESOLVED: The identity of the transformation thunks (FUN0050cba3, FUN0050d0afViaGlobalPointer, FUN0050c5b0) is unknown; whether they operate on a1, a2 or a3 is not resolvable from this function alone
    // UNRESOLVED: The a3 range/scale struct element types are mixed unsigned int (origins/scales) and float (z bounds) per the raw source; this layout is taken verbatim and not independently verified
}
