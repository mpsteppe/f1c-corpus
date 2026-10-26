// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FB260
// Canonical corpus name: sub_4FB260
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FB260_004fb260.c

void UnknownObject::PropagateLerpedPhysicsState()
{
    // Lerp-interpolates a base value between two prior float fields by factor a2, stores the base at this+0xA0, then writes three coefficient-scaled plus bias-adjusted outputs to this+0x94, this+0x98 and this+0x9C. Returns the float bits of the this+0x9C output. Per-frame physics state propagation with distance/time falloff.
    // CALCULATION: v3 = (1.0 - a2) * v2[-30] + a2 * v2[-31], a linear interpolation between two prior float fields (indexes v2-31 and v2-30) by factor a2. [source:raw]
    // ASSIGNMENT: v2[3] = v3, storing the interpolated base at this+0xA0. [field:this:0x000000A0, source:raw]
    // CALCULATION: v6 = v3 * v2[-29] + v2[-37]; v7 = v3 * v2[-28] + v2[-36]; v8 = v3 * v2[-27] + v2[-35]; each output is the interpolated base scaled by a coefficient field plus a bias field. [source:raw]
    // ASSIGNMENT: *v2 = v6, writing the first output to this+0x94. [field:this:0x00000094, source:raw]
    // ASSIGNMENT: v2[1] = v7, writing the second output to this+0x98. [field:this:0x00000098, source:raw]
    // ASSIGNMENT: v2[2] = v8, writing the third output to this+0x9C. [field:this:0x0000009C, source:raw]
    // RETURN: Returns LODWORD(v8), the integer bit pattern of the float written to this+0x9C. [source:raw]

    // Conservative worker pseudocode:
    //   float* v2 = this + 37;
    //   float base = (1.0f - a2) * v2[-30] + a2 * v2[-31];
    //   v2[3] = base;
    //   float out0 = base * v2[-29] + v2[-37];
    //   float out1 = base * v2[-28] + v2[-36];
    //   float out2 = base * v2[-27] + v2[-35];
    //   v2[0] = out0; v2[1] = out1; v2[2] = out2;
    //   return bit_cast<int>(out2);
    // UNRESOLVED: All four outputs (0x94/0x98/0x9C/0xA0) are recalculated every frame, so external pokes do not persist.
    // UNRESOLVED: Input coefficient/bias offsets (v2-37..v2-27 range) are not in the packet field list; their exact absolute offsets are not asserted here.
    // UNRESOLVED: Global flt_59E43C is listed as read but does not appear in the raw source.
}
