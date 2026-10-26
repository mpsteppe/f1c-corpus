// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00430750
// Canonical corpus name: sub_430750
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_430750_00430750.c

void UnknownObject::TireForceWithQuaternionTransform()
{
    // Per-wheel tire contact-patch force computation. Guards on tire-brand and compound lookups, then combines two suspension/load force terms read from the vehicle object, aggregates wheel forces, applies a tire-model polynomial over clamped deflection inputs, runs quaternion transforms on compound data, and returns the summed aggregate force normalized by the total load term v21. The vehicle is identified only by its object offset layout (all reads read-only); the owning class is not established by this packet.
    // GUARD: Guard: TireBrandLookup(&unk_8ADB88); when the lookup fails, return 0.0 immediately. [callee:0x004D7880, global:0x008ADB88, source:raw]
    // GUARD: Guard: CompoundIndexLookup(*(this+0xBC4)) using the tire compound index at this+0xBC4; when the entry pointer is null, return 0.0 immediately. [callee:0x004D7570, field:this:0x00000BC4, source:raw]
    // CALCULATION: First force term: v20 = (double)*(int)(this+0xC44) * *(double)(this+0xC38) + *(double)(this+0xC30); residual v18 = 1.0 - v20. [field:this:0x00000C30, field:this:0x00000C38, field:this:0x00000C44, source:raw]
    // CALL: WheelForceAggregate(this, &dword_8ADB00, &v17, &v16): aggregate wheel forces into the v16/v17 outputs using the tire-model constants at dword_8ADB00. [callee:0x00430600, global:0x008ADB00, source:raw]
    // CALCULATION: Second force term: v21 = ((double)*(int)(this+0xCC4) * *(double)(this+0xCB8) + *(double)(this+0xCB0)) * 0.75 + dbl_8ADB40. [field:this:0x00000CB0, field:this:0x00000CB8, field:this:0x00000CC4, global:0x008ADB40, source:raw]
    // CALCULATION: Vertical force v19 = v21 * 9.81 - (float)v16 * a2 * a2; then split v19 into components via v20/v18 and compute v6 from v16*v4[44] + v19*v18*v4[3], scaled by (dbl_8ADB60 + 0.02500000037252903) * 1.176470588235294. [global:0x008ADB60, source:raw]
    // CALCULATION: Compute deflection terms v17/v18 from (v5 - v19) and (v19 + v5) halved, clamping v17 at zero and folding the deficit back into v18 when v17 is negative. [source:raw]
    // CALCULATION: Compute second deflection terms v19/v16 from (v16 - v20) and (v20 + v16) halved, clamping v19 at zero and folding the deficit back into v16 when v8 is negative. [source:raw]
    // CALL: QuaternionTransformComputation(v4[13], v4[14], v4[15]): quaternion transform on the compound entry's first triplet. [callee:0x004D5C70, source:raw]
    // CALL: QuaternionTransformComputation(v4[54], v4[55], v4[56]): quaternion transform on the compound entry's second triplet. [callee:0x004D5C70, source:raw]
    // CALCULATION: Tire polynomial: for each clamped deflection (min(v17, v26), min(v18, v26), min(v19, v31), min(v16, v31)) evaluate a degree-4 polynomial with stack coefficients v22..v30 scaled by v4[3] or v4[44], producing v10/v12/v14 and the v16 force product. [source:raw]
    // RETURN: Return the summed force (v10 + polynomial*v4[44]*v16 + v14 + v12) divided by the total load term v21. [function:0x00430750, source:raw]

    // Conservative worker pseudocode:
    //   if (!TireBrandLookup(&unk_8ADB88)) return 0.0;
    //   compound = CompoundIndexLookup(this->tireCompound);
    //   if (!compound) return 0.0;
    //   v20 = (double)this->intC44 * this->dblC38 + this->dblC30;
    //   v18 = 1.0 - v20;
    //   WheelForceAggregate(this, &dword_8ADB00, &v17, &v16);
    //   v21 = ((double)this->intCC4 * this->dblCB8 + this->dblCB0) * 0.75 + dbl_8ADB40;
    //   v19 = v21 * 9.81 - (float)v16 * a2 * a2;
    //   v16 = v19 * v20;
    //   v6 = (v16 * compound[44] + v19 * v18 * compound[3]) * (dbl_8ADB60 + 0.025f) * 1.17647f;
    //   v19 = v18 * v6; v20 = v6 * v20;
    //   v17 = (v5 - v19) * 0.5; v18 = (v19 + v5) * 0.5;
    //   if (v17 < 0) { v18 += v17; v17 = 0; }
    //   v8 = (v16 - v20) * 0.5; v19 = v8; v16 = (v20 + v16) * 0.5;
    //   if (v8 < 0) { v16 += v8; v19 = 0; }
    //   QuaternionTransformComputation(compound[13], compound[14], compound[15]);
    //   QuaternionTransformComputation(compound[54], compound[55], compound[56]);
    //   v10 = v17 * poly(v22..v25, min(v17, v26)) * compound[3];
    //   v12 = v18 * poly(v22..v25, min(v18, v26)) * compound[3];
    //   v14 = v19 * poly(v27..v30, min(v19, v31)) * compound[44];
    //   return (v10 + poly(v27..v30, min(v16, v31)) * compound[44] * v16 + v14 + v12) / v21;
    // UNRESOLVED: The tire polynomial coefficients v22-v31 are uninitialized in the raw decompilation; eight read-only globals (dbl_59E420, dbl_59E430, dbl_59E880, dbl_59EA48, dbl_59EA50, dbl_59EA58, dbl_59EA60, dword_8AD254) are recorded by the packet as read but their loads are not visible as distinct reads in this source. They likely feed the folded polynomial constants, but the association is not grounded in this packet.
    // UNRESOLVED: Compound entry indexing (v4[3], v4[13..15], v4[44], v4[54..56]) reads an external tire-compound structure whose layout is outside this function.
    // UNRESOLVED: The a2 argument (likely a vertical-load/velocity scale) is read-only and its semantic name is caller-defined.
    // UNRESOLVED: Vehicle object identity is unknown; owner proposal would need corroborating struct evidence.
}
