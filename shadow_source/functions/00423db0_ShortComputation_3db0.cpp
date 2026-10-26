// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423DB0
// Canonical corpus name: ShortComputation_3db0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_3db0_00423db0.c

void UnknownObject::ShortComputation_3db0()
{
    // Decomposes the position difference between a target vehicle and a reference point (a5, a7) into longitudinal and lateral components relative to the direction vector (a2, a4). Loads the target position through the this[0] indirection pointer (obj+0x34E0, obj+0x34E8), subtracts the reference, writes the signed longitudinal distance into this[3] and the signed lateral distance into this[1]. Called every frame from AISteering (004270a0).
    // CALCULATION: Load target position through the this[0] indirection (px from obj+0x34E0, py from obj+0x34E8) and subtract the reference point: v7 = px - a5, v8 = py - a7 [field:this:0x00000000, field:obj:0x000034E0, field:obj:0x000034E8]
    // CALCULATION: v9 = a4*v8 + a2*v7, the dot product of the offset vector against the direction [source:raw]
    // CALCULATION: Longitudinal distance: build v21=a2*v9, v24=a4*v9, store the signed sqrt of (v24*v24 + v21*v21) into this[3] (sign from compare flags) [field:this:0x0000000C, source:raw]
    // CALCULATION: Lateral distance: v15 = a2*v8 - a4*v7 (cross term), then v22=-a4, v23=v22*v15, v25=a2*v15, store the sign-inverted sqrt of (v25*v25 + v23*v23) into this[1] [field:this:0x00000004, source:raw]

    // Conservative worker pseudocode:
    //   px = *(obj + 0x34E0); py = *(obj + 0x34E8); // obj = *(void**)this
    //   v7 = px - a5; v8 = py - a7;
    //   v9 = a4*v8 + a2*v7;
    //   this[3] = signflag ? -sqrt((a4*v9)^2 + (a2*v9)^2) : sqrt(...);
    //   v15 = a2*v8 - a4*v7;
    //   this[1] = signflag ? sqrt((a2*v15)^2 + (-a4*v15)^2) : -sqrt(...);
    // UNRESOLVED: The +sqrt / -sqrt selection depends on compare-result flags (v12|v13, v18|v19) computed from the squared term against zero; the exact branch intent is not determinable from the raw source
    // UNRESOLVED: Global flt_59E440 (0059E440) is flagged by the packet facts but appears nowhere in the raw decompiled source text; the skeleton fill labels it a zero threshold, unverifiable from this packet
    // UNRESOLVED: Parameters a3 and a6 are unused in the raw source
}
