// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED0F0
// Canonical corpus name: AccumulatorClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AccumulatorClamp_004ed0f0.c

void UnknownObject::AccumulatorClamp()
{
    // Accumulates the input scaled by 0.225 into the float accumulator at this+0x3A6C, caps it at this[0x3A78] + 0.45, then applies hysteresis clamping: when this[0x3A78] + 0.15 falls below the accumulator, the flag dword at this+0x3D60 is set and the output at this+0x3A70 is reduced toward the average of this[0x3A80] and this[0x3A70]; when this[0x3A78] + 0.3 falls below the accumulator, this[0x3A80] is copied raw into this[0x3A70]. Finally dispatches TireBrushModelForceSolver(this, 0).
    // CALCULATION: Accumulate: this[0x3A6C] = a2 * 0.225 + this[0x3A6C]. [field:this:0x00003A6C, source:raw]
    // GUARD: Upper clamp: if this[0x3A6C] exceeds this[0x3A78] + 0.45, set this[0x3A6C] to this[0x3A78] + 0.45. [field:this:0x00003A6C, field:this:0x00003A78, source:raw]
    // GUARD: Lower hysteresis threshold: when this[0x3A78] + 0.15 is less than the accumulator at this[0x3A6C], enter the reduction block. [field:this:0x00003A78, field:this:0x00003A6C, source:raw]
    // ASSIGNMENT: Set the flag dword at this+0x3D60 to 1 if it is currently 0. [field:this:0x00003D60, source:raw]
    // CALCULATION: Reduce the output: compute (this[0x3A80] + this[0x3A70]) * 0.5 and if that average is smaller than this[0x3A70], store the average into this[0x3A70]. [field:this:0x00003A80, field:this:0x00003A70, source:raw]
    // GUARD: Upper hysteresis threshold: when this[0x3A78] + 0.3 is less than the accumulator at this[0x3A6C], copy this[0x3A80] into this[0x3A70] as a raw dword copy. [field:this:0x00003A78, field:this:0x00003A6C, field:this:0x00003A80, field:this:0x00003A70, source:raw]
    // CALL: TireBrushModelForceSolver(this, 0) is dispatched after the clamping; it is named in the raw source but the packet records no callee address for it. [source:raw]

    // Conservative worker pseudocode:
    //   void AccumulatorClamp(int this, float a2) {
    //     float acc = *(float*)(this + 0x3A6C) + a2 * 0.225f;
    //     *(float*)(this + 0x3A6C) = acc;
    //     float upper = *(float*)(this + 0x3A78) + 0.45f;
    //     if (acc > upper) *(float*)(this + 0x3A6C) = upper;
    //     if (*(float*)(this + 0x3A78) + 0.15f < *(float*)(this + 0x3A6C)) {
    //       if (!*(int*)(this + 0x3D60)) *(int*)(this + 0x3D60) = 1;
    //       float avg = (*(float*)(this + 0x3A80) + *(float*)(this + 0x3A70)) * 0.5f;
    //       if (avg < *(float*)(this + 0x3A70)) *(float*)(this + 0x3A70) = avg;
    //     }
    //     if (*(float*)(this + 0x3A78) + 0.3f < *(float*)(this + 0x3A6C))
    //       *(int*)(this + 0x3A70) = *(int*)(this + 0x3A80);
    //     TireBrushModelForceSolver(this, 0);
    //   }
    // UNRESOLVED: The globals flt_59E450, flt_59E868, flt_59E8B4, flt_59E8FC and flt_5ACEE8 are listed as accessed but do not appear in the raw source; the compiler may have folded them into the inline literals (0.225/0.45/0.15/0.3), or the raw source rendering omitted them.
    // UNRESOLVED: TireBrushModelForceSolver is called per the raw source but is not recorded as a callee in the packet, so no callee address is available.
    // UNRESOLVED: The semantic role of the two hysteresis thresholds (+0.15 and +0.3 relative to this[0x3A78]) and the meaning of the accumulator at this+0x3A6C are not established by the packet alone.
}
