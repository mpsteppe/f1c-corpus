// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438690
// Canonical corpus name: PhysicsCollisionDamageDNFDetection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsCollisionDamageDNFDetection_00438690.c

void UnknownObject::AccumulateCollisionDamageWithDnf()
{
    // Per-frame collision damage accumulation with DNF detection. Computes impact-energy and thermal damage terms from the vehicle's force/velocity fields, integrates them into the damage accumulator, and when the accumulator overflows marks the first non-DNF vehicle as DNF (state 5) and resets the damage state. Otherwise it applies a cosine-modulated damage response and writes the reciprocal damage output.
    // CALCULATION: Compute impact-energy base: v20 = fabs(this+0xBC) * this+0x3D4, then v18 = v20 * this+0x414. [field:this:0x000000BC, field:this:0x000003D4, field:this:0x00000414, source:raw]
    // CALL: Transform the contact frame at a3+100 via Mat3x3MulVec into the local buffer v22. [callee:0x004388D0, source:raw]
    // CALCULATION: Compute the thermal damage term from the average of the two temperature globals (flt_8AFEF0, flt_8AFEF4, each plus 273.16) minus this+0x404, scaled by (abs(Z)*this+0x424 + this+0x41C), and add v18. [field:this:0x00000404, field:this:0x0000041C, field:this:0x00000424, global:0x008AFEF0, global:0x008AFEF4, source:raw]
    // GUARD: When the accumulator this+0x42C is at or below the threshold this+0x444, use the simple damage ratio v5 / this+0x444. [field:this:0x0000042C, field:this:0x00000444, source:raw]
    // CALCULATION: Above the threshold: decrement the accumulator by this+0x404 cubed times this+0x43C times v20 times a2, writing the result back to this+0x42C. [field:this:0x0000042C, field:this:0x00000404, field:this:0x0000043C, source:raw]
    // GUARD: Branch on the FPU overflow flags (v8|v9) raised by the accumulator update: true selects the DNF path, false selects the partial-damage response path. [source:raw]
    // LOOP: DNF path: scan the active grid dword_7C54F0[0..dword_5C329C) for the first vehicle whose DNF flag at +13000 is unset. [global:0x007C54F0, global:0x005C329C, source:raw]
    // ASSIGNMENT: DNF path: mark the first non-DNF vehicle as DNF by writing 5 to the field at veh+16436+52 when its state word at veh+16488 is zero. [global:0x007C54F0, source:raw]
    // ASSIGNMENT: DNF path: reset the damage state to zero at this+0x42C, this+0x430, this+0x3E4 and this+0x3E8. [field:this:0x0000042C, field:this:0x00000430, field:this:0x000003E4, field:this:0x000003E8, source:raw]
    // CALCULATION: Partial-damage path: use the damage ratio v19 = v5 / v6 and compute the thermal magnitude |this+0x404 - this+0x40C|. [field:this:0x00000404, field:this:0x0000040C, source:raw]
    // GUARD: When the thermal magnitude is within this+0x3F4, write the cosine-modulated damage this+0x3E4 = (cos(magnitude*this+0x3FC)*0.25 + 0.75) * this+0x3EC. [field:this:0x000003E4, field:this:0x000003F4, field:this:0x000003FC, field:this:0x000003EC, source:raw]
    // CALL: When the cosine path is skipped and the damage this+0x3E4 still exceeds half the threshold this+0x3EC, notify via DisplayMessage0x4a. [field:this:0x000003E4, field:this:0x000003EC, callee:0x0041B200, source:raw]
    // ASSIGNMENT: Floor the partial damage response: this+0x3E4 = this+0x3EC * 0.5. [field:this:0x000003E4, field:this:0x000003EC, source:raw]
    // CALCULATION: Integrate the thermal component forward: this+0x404 += v14 * a2. [field:this:0x00000404, source:raw]
    // CALCULATION: Copy the damage source block from *(this+0x15C)+188 (qmemcpy of 24 bytes) and compute v24[0] = this+0x434 * this+0x42C + this+0xCC. [field:this:0x0000015C, field:this:0x00000434, field:this:0x0000042C, field:this:0x000000CC, source:raw]
    // CALL: Write the reciprocal damage output: call StructCopyWithReciprocalDivision(v24), then this+0xD4 = 1.0 / v24[0]. [callee:0x005697A0, field:this:0x000000D4, source:raw]
    // UNKNOWN: Identity: ABI label Physics_Collision_Damage_DNF_Detection (LEGACY) tags this function at 0x00438690. [abi:lead, function:0x00438690, source:raw]
    // UNKNOWN: Invocation context: called per-frame from VehiclePhysicsIntegrationStep. [caller:0x00441650, source:raw]

    // Conservative worker pseudocode:
    //   int sub_438690(F1CVehicle* this, double a2, int a3) {
    //     double base = fabs(this.force_BC) * this.scale_3D4;
    //     double impact = base * this.scale_414;
    //     Mat3x3MulVec(a3 + 100, local);
    //     double thermal = ((flt_8AFEF0 + 273.16f + flt_8AFEF4 + 273.16f) * 0.5f - this.temp_404)
    //                    * (|local.Z| * this.scale_424 + this.offset_41C) + impact;
    //     if (this.damage_42C <= this.threshold_444) {
    //       ratio = thermal / this.threshold_444;
    //     } else {
    //       this.damage_42C -= this.temp_404^3 * this.scale_43C * base * a2;
    //       if (overflow) {
    //         veh = FirstActiveWithNoDnfFlag();
    //         if (veh && veh[16488] == 0) veh[16436 + 52] = 5;   // mark DNF
    //         this.damage_42C = 0; this.damage_430 = 0; this.damage_3E4 = 0; this.damage_3E8 = 0;
    //       } else {
    //         ratio = thermal / this.damage_42C;
    //         if (|this.temp_404 - this.ref_40C| <= this.thresh_3F4)
    //           this.damage_3E4 = (cos(diff * this.freq_3FC) * 0.25 + 0.75) * this.damage_3EC;
    //         else {
    //           if (this.damage_3EC * 0.5 < this.damage_3E4) DisplayMessage0x4a();
    //           this.damage_3E4 = this.damage_3EC * 0.5;
    //         }
    //       }
    //     }
    //     this.temp_404 += ratio * a2;
    //     memcpy(out, *(this.ptr_15C) + 188, 24);
    //     out[0] = this.scale_434 * this.damage_42C + this.base_CC;
    //     StructCopyWithReciprocalDivision(out);
    //     this.out_D4 = 1.0 / out[0];
    //   }
    // UNRESOLVED: The six double globals (dbl_59E420, dbl_59E430, dbl_59E880, dbl_59EA60, dbl_59EAC8, dbl_59EB50) and dword_5EB978 are recorded as read in the skeleton facts but do not appear as named references in the decompiled C body; their role is not visible in the raw source.
    // UNRESOLVED: The DNF-flag offsets (+13000, +16436, +16488) are dereferences into dword_7C54F0 grid entries and were not mapped to named vehicle fields in this function.
    // UNRESOLVED: The a3+100 contact-frame block read by Mat3x3MulVec is a caller-owned sub-object whose layout is not resolved here.
}
