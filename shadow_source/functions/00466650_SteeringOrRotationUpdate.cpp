// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00466650
// Canonical corpus name: sub_466650
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_466650_00466650.c

void UnknownObject::SteeringOrRotationUpdate()
{
    // Per-frame update of a steering/rotation damping state. Guarded by a nonzero dword at this+0xF0. Accumulates elapsed time into this+0x10C (clamped at 3.0), reads a float via FloatFieldAccessor and a dual field via DualFieldRead, runs a DualMatrixTransformMultiply, then applies a correction term this+0x110 either through a brake/reset path (flag byte this+0xF4 set) or a smooth damping path. Ends by invoking a vtable+44 virtual call and writing the accumulated correction and saved position targets back to this+0x114, this+0x104, this+0x108.
    // GUARD: Read dword at this+0xF0 (field 60); if zero, return immediately without updating. [field:this:0x000000F0]
    // ASSIGNMENT: Zero local accumulators v21, v20, v19 (ints) and v18, v14, v17 (floats) before reading state. [source:raw]
    // CALL: DualFieldRead(&v22, &v23) reads a dual (X/Y) field value into locals v22/v23. [callee:0x00498880]
    // CALL: FloatFieldAccessor on the object pointer stored at this+0x40 returns a float v15 (e.g. elapsed delta). [callee:0x00498730, field:this:0x00000040]
    // CALCULATION: Accumulate v15 into this+0x10C (field 67); clamp this+0x10C to 3.0 when the sum exceeds 3.0. [field:this:0x0000010C]
    // CALL: DualMatrixTransformMultiply(&v21,&v20,&v19,&v18,&v14,&v17) transforms the dual values into six local outputs. [callee:0x0054B530]
    // GUARD: Byte at this+0xF4 selects the brake/reset path (nonzero) versus the smooth damping path (zero). [field:this:0x000000F4]
    // CALL: Brake path: FieldSetterCall(3) issues a setter, and this+0x10C is reset to 0.0. [callee:0x004988A0, field:this:0x0000010C]
    // CALCULATION: Brake path: when v15 is nonzero, recompute the error term this+0x110 as (v22 - saved_at_0x104) / v15 * 0.5. [field:this:0x00000110, field:this:0x00000104]
    // CALCULATION: Brake path: correction increment v9 = sqrt(this[68] * this[68]) * 0.00030000001; subtract it when the position delta is positive, add it when negative. [field:this:0x00000110]
    // CALL: Brake path: invoke the vtable method at (this+0x0)+44 on `this` with argument 1. [field:this:0x00000000]
    // CALL: sub_54B4D0(v21, v20, v19, v18, v14, v17) writes the final six output values. [callee:0x0054B4D0]
    // ASSIGNMENT: Persist results: this+0x114 = accumulated correction v14; this+0x104 = v22; this+0x108 = v23 (saved position targets). [field:this:0x00000114, field:this:0x00000104, field:this:0x00000108]
    // CALCULATION: Smooth path: when this+0x110 is beyond +-20.0 (and this+0x10C below 3.0) add half of v15 (optionally plus a decay term sqrt(this[68]^2) * 0.00019999999 * (1.0 - this[67] * 0.33333334)); otherwise step toward v15/2. [field:this:0x00000110, field:this:0x0000010C]

    // Conservative worker pseudocode:
    //   if (dword[this+0xF0] == 0) return 0;
    //   DualFieldRead(&v22, &v23);
    //   v15 = FloatFieldAccessor(dword[this+0x40]);
    //   this[0x10C] = clamp(this[0x10C] + v15, 0, 3.0);
    //   DualMatrixTransformMultiply(&v21, &v20, &v19, &v18, &v14, &v17);
    //   if (byte[this+0xF4]) {
    //     FieldSetterCall(3);
    //     this[0x10C] = 0.0;
    //     if (v15 != 0.0) this[0x110] = (double)(v22 - dword[this+0x104]) / v15 * 0.5;
    //     corr = sqrt(this[0x110]*this[0x110]) * 0.00030000001;
    //     v14 = (v22 - dword[this+0x104] < 0) ? v14 + corr : v14 - corr;
    //     (vtable[this+0x0]+44)(this, 1);
    //   } else {
    //     step = (this[0x110] > 20.0 && this[0x10C] < 3.0) ? v15/2 + decay : v15/2;
    //     v14 = (this[0x110] < 0.0) ? v14 + step : v14 - step;
    //     (vtable[this+0x0]+44)(this, 1);
    //   }
    //   sub_54B4D0(v21, v20, v19, v18, v14, v17);
    //   this[0x114] = v14; dword[this+0x104] = v22; dword[this+0x108] = v23;
    // UNRESOLVED: field:obj:0x2C is not directly referenced in the raw source text; it is likely consumed inside FloatFieldAccessor / DualFieldRead, so its role here stays unproven.
    // UNRESOLVED: All nine read-only globals are absent from the raw source text and are presumably consumed by the helper callees (FloatFieldAccessor, DualFieldRead, DualMatrixTransformMultiply); their constants cannot be tied to a specific operation here.
    // UNRESOLVED: Exact semantics of DualFieldRead, DualMatrixTransformMultiply and sub_54B4D0 helper contracts are not established from this function alone.
    // UNRESOLVED: Meaning of the flag byte at this+0xF4 (brake/reset vs smooth) and of the vtable+44 virtual method argument 1 is not confirmed.
}
