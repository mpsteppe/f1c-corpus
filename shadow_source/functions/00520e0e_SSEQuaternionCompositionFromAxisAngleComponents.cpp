// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00520E0E
// Canonical corpus name: SSEQuaternionCompositionFromAxisAngleComponents
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEQuaternionCompositionFromAxisAngleComponents_00520e0e.c

void UnknownObject::SSEQuaternionCompositionFromAxisAngleComponents()
{
    // Packs three unsigned axis-angle float component inputs (a2, a3, a4) together with constant dword_8D62C0 into an SSE register, multiplies by constant xmmword_8D62B0, invokes sub_528CC0 as the composition helper, then completes the quaternion with a shuffle/multiply/add/xor sequence against sign mask xmmword_8D62A0 and stores the result at a1[0]. Unconditional straight-line computation.
    // ASSIGNMENT: Unpack the three component inputs (a2, a3, a4) and constant dword_8D62C0 into a packed SSE vector and multiply by constant xmmword_8D62B0, storing into local v10. [source:raw, global:0x008D62C0, global:0x008D62B0]
    // CALL: Call sub_528CC0 with v10 as in-place source/destination and v11 as intermediate output buffer. [callee:0x00528CC0]
    // CALCULATION: Shuffle and permute the converted v10/v11[0] components into per-component temporaries v4, v5, v6, v7, v8. [source:raw]
    // CALCULATION: Compute the final quaternion component by multiplying permuted temporaries and XORing the sign mask xmmword_8D62A0 before the final add, producing v10. [source:raw, global:0x008D62A0]
    // ASSIGNMENT: Store the resulting __m128 v10 into the output buffer a1 at offset 0x0. [field:this:0x00000000]
    // RETURN: Return the output buffer pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   v10 = pack_and_scale(a2, a3, a4, dword_8D62C0, xmmword_8D62B0);
    //   sub_528CC0(v10, v10, v11);
    //   a1[0] = final_quaternion_shuffle(v10, v11[0], xmmword_8D62A0);
    //   return a1;
    // UNRESOLVED: Subsystem role of sub_528CC0 (name unknown beyond address) limits the confidence of the quaternion-composition interpretation.
    // UNRESOLVED: Owner is UNKNOWN; no static callers and no frame-path evidence identify the containing object.
}
