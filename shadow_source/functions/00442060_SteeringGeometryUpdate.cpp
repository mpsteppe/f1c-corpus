// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00442060
// Canonical corpus name: SteeringGeometryUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringGeometryUpdate_00442060.c

void UnknownObject::SteeringGeometryUpdate()
{
    // Per-wheel steering geometry update. Scales the steering input to radians, adds a deterministic noise perturbation from the trig lookup table (indexed by dword_8AAE70, incremented each call), and accumulates it into the per-wheel steering angles with the sign depending on wheel id (a2==0 or a2==3). Accumulated angles are clamped to +/-10 degrees and a clamp flag is written on overflow. Frees the physics sub-object, then transforms the wheel contact geometry through the coordinate frames of the matching contact bodies for each wheel-body contact, accumulating the steering angle; when the accumulated angle exceeds 0.015 rad, writes state flag 4 to the secondary state structure.
    // CALCULATION: Convert steering input a3 to radians: v28 = a3 * 0.08726646259971647. [source:raw]
    // ASSIGNMENT: Set the low-activity flag byte at this[281*a2+276] (offset of the per-wheel entry) to 1. [source:raw]
    // CALCULATION: Look up noise angle from trig table: v5 = flt_8AAE74[(u8)dword_8AAE70] * PI, then increment dword_8AAE70. [global:0x008AAE70, global:0x008AAE74, source:raw]
    // CALCULATION: Compute sine/cosine perturbation scaled by v28 and accumulate into the wheel steering angle at this[281*a2+279] (sin) and this[281*a2+281] (cos); sign of the sin accumulation depends on wheel id (a2==0 or a2==3). [source:raw]
    // GUARD: Clamp each accumulated angle to the +/-0.1745329251994329 rad (+/-10 degrees) window; on overflow write the float clamp bound and the clamp flag at this[281*a2+280]/this[281*a2+282]. [source:raw]
    // CALL: Call PhysicsSubObjectFree(this) to release the wheel's physics sub-object. [callee:0x00441450, source:raw]
    // GUARD: Guard on wheel-body contact count this+0x15BC > 0; enables the contact-array scan loop. [guard:0, field:this:0x000015BC, source:raw]
    // LOOP: Iterate contact entries (base this+0x15C0, stride 48), matching each contact's body id (+4) or id3 (+12) against the wheel's expected body id; non-matching entries are skipped. [field:this:0x000015C0, field:this:0x0000141C, source:raw]
    // CALL: Transform the contact's position vector through the body coordinate frame via Matrix3x3VectorMultiply. [callee:0x00435E00, source:raw]
    // CALL: Transform the intermediate vector into the wheel geometry frame via Mat3x3MulVec. [callee:0x004388D0, source:raw]
    // CALCULATION: Compose the 3x3 orientation of the wheel geometry from the body and wheel frame matrices (row/column dot products over the transformed basis). [source:raw]
    // CALL: Apply F_3x3MatrixInverseCoordinateTransform to the contact entry after the forward transforms. [callee:0x0056D020, source:raw]
    // ASSIGNMENT: Load the secondary-state pointer from this+0x1F00 for the steering-threshold check. [field:this:0x00001F00, source:raw]
    // CALCULATION: Accumulate the noise-scaled steering angle v28 into the per-wheel accumulated angle at wheel+480. [source:raw]
    // GUARD: If the accumulated angle exceeds 0.015 rad and the secondary state's event counter at +0x4068 is zero, write state flag 4 to the secondary state (steering state/flag at this 0x5F68). [field:this:0x00005F68, source:raw]

    // Conservative worker pseudocode:
    //   void SteeringGeometryUpdate(this, int wheel, float input) {
    //     double rad = input * DEG2RAD;
    //     setActivityFlag(this[281*wheel+276]);
    //     double ang = flt_8AAE74[(u8)dword_8AAE70++] * PI;
    //     double s = sin(ang) * rad;
    //     this[281*wheel+279] += (wheel==0 || wheel==3) ? s : -s;
    //     clampTo10Deg(this[281*wheel+279], this[281*wheel+280]);
    //     this[281*wheel+281] += cos(ang) * rad;
    //     clampTo10Deg(this[281*wheel+281], this[281*wheel+282]);
    //     PhysicsSubObjectFree(this);
    //     if (this->contactCount(0x15BC) > 0)
    //       for (c = this->contacts(0x15C0); ; c += 48) {
    //         if (c->id == wheelBodyId) break;
    //         if (c->id3 != wheelBodyId) continue;
    //         if (c->pos && c->mat) {
    //           Matrix3x3VectorMultiply(bodyFrame, c->pos, tmp);
    //           Mat3x3MulVec(wheelFrame, tmp, c->out);
    //           ... compose orientation ...
    //           F_3x3MatrixInverseCoordinateTransform(c);
    //         }
    //       }
    //     double acc = this[281*wheel+...] + rad;
    //     this[281*wheel+...] = acc;
    //     if (acc > 0.015) {
    //       state = this->secondary(0x1F00);
    //       if (*(state+0x4068) == 0) *(state+0x4068) = 4;
    //     }
    //   }
    // UNRESOLVED: Semantics of read-only globals dbl_59E890, dbl_59ED60, dbl_59ED68, dbl_59ED70, dbl_59ED78; not present in the raw source text (likely steering/suspension geometry constants).
    // UNRESOLVED: Fields this+0x1438..0x1478 are reported as accessed but do not appear as explicit expressions in the raw source; likely suspension data pointers consumed inside the matrix-transform helpers.
    // UNRESOLVED: Mapping of the loop constants v7==96 and v7==144 to specific wheel indices is not derivable from this function alone.
    // UNRESOLVED: Exact float bit patterns written to clamp flags (1069963032 / -1077520616) were not decoded; clamp bounds 0.1745329251994329 rad are the readable constants.
    // UNRESOLVED: The clamps and 0.015 threshold constants may alias the dbl_59E8x/59EDx globals in the original build, but the raw source inlines the literals.
}
