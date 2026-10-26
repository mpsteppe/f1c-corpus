// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00423CA0
// Canonical corpus name: ShortComputation_3ca0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_3ca0_00423ca0.c

void UnknownObject::ShortComputation_3ca0()
{
    // Decomposes a target vehicle velocity into longitudinal and lateral components relative to the direction vector (a2, a4). Loads the target velocity via the this[0] indirection pointer (obj+0x34F8, obj+0x3500), computes a projection factor against the squared direction norm (guarded on zero), writes the signed longitudinal magnitude minus offset a5 into this[6] and the signed perpendicular magnitude into this[4]. Called every frame from AISteering (004270a0).
    // CALCULATION: Load target velocity through the this[0] indirection: vx from obj+0x34F8 and vy from obj+0x3500 [field:this:0x00000000, field:obj:0x000034F8, field:obj:0x00003500]
    // CALCULATION: v19 = a4*a4 + a2*a2, the squared norm of the direction vector used as the projection denominator [source:raw]
    // GUARD: If v19 == 0.0 the projection factor v7 is forced to 0.0; otherwise v7 = (a4*vy + a2*vx) / v19 (normalized dot product) [source:raw]
    // CALCULATION: Longitudinal result: build v20=a2*v7, v22=a4*v7, take the signed sqrt of (v22*v22 + v20*v20) (sign from compare flags), store into this[6], then subtract a5 from this[6] [field:this:0x00000018, source:raw]
    // CALCULATION: Lateral result: v13 = (a2*vy - a4*vx) / v19 (cross term), then v21=-a4*v13, v23=a2*v13, store the sign-inverted sqrt of (v23*v23 + v21*v21) into this[4] [field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   vx = *(obj + 0x34F8); vy = *(obj + 0x3500); // obj = *(void**)this
    //   v19 = a4*a4 + a2*a2;
    //   v7 = (v19 == 0.0) ? 0.0 : (a4*vy + a2*vx) / v19;
    //   this[6] = signflag ? -sqrt((a4*v7)^2 + (a2*v7)^2) : sqrt(...);
    //   this[6] -= a5;
    //   v13 = (v19 == 0.0) ? 0.0 : (a2*vy - a4*vx) / v19;
    //   this[4] = signflag ? sqrt((a2*v13)^2 + (-a4*v13)^2) : -sqrt(...);
    // UNRESOLVED: The +sqrt / -sqrt selection depends on compare-result flags (v10|v11, v16|v17) computed from the squared term against zero; the exact branch intent is not determinable from the raw source
    // UNRESOLVED: Global flt_59E440 (0059E440) is flagged by the packet facts but appears nowhere in the raw decompiled source text; the skeleton fill labels it a zero threshold, unverifiable from this packet
    // UNRESOLVED: Parameter a3 is unused in the raw source
}
