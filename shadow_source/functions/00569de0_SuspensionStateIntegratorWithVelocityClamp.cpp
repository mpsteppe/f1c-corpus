// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00569DE0
// Canonical corpus name: sub_569DE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_569DE0_00569de0.c

void UnknownObject::SuspensionStateIntegratorWithVelocityClamp()
{
    // Vehicle physics suspension integrator on the per-frame tick. First clamps a velocity scale: when the squared displacement of the body position (this+308/+316/+324) from the reference position (this+500/+508/+516) exceeds 0.25 times the reference magnitude squared, the scale is capped to 0.5/sqrt(ratio); a second clamp uses the secondary position (this+332/+340/+348) against the secondary reference (this+524/+532/+540) with a radius equal to the minimum of this+204, this+188 and this+196. The chosen scale is then applied to the linear position, linear velocity, and angular momentum advances (each an a2-scaled Euler step), a 72-byte state block is staged with qmemcpy(this+28, this+380, 0x48), and the inertia tensor transform is run before the result angular velocity is written back. Returns the clamp scale (1.0 when no clamp applied).
    // CALCULATION: Body displacement on three axes: current position this+308/+316/+324 minus reference position this+500/+508/+516, squared magnitude v5 [field:this:0x00000134, field:this:0x0000013C, field:this:0x00000144, field:this:0x000001F4, field:this:0x000001FC, field:this:0x00000204, source:raw]
    // CALCULATION: Reference magnitude squared v6 from the reference position this+500/+508/+516 [field:this:0x000001F4, field:this:0x000001FC, field:this:0x00000204, source:raw]
    // GUARD: First clamp branch entered when v5 > 0.25 * v6; the clamp scale v21 is initialised to 1.0 [source:raw]
    // CALCULATION: Clamp ratio v7 = sqrt(v5) / (sqrt(v6) + this+172 * 128.0); when v7 > 0.5 the scale becomes 0.5 / v7, kept only when smaller than 1.0 [field:this:0x000000AC, source:raw]
    // CALCULATION: Secondary displacement this+332/+340/+348 minus second reference this+524/+532/+540, squared magnitude v13, and second reference magnitude squared v14 [field:this:0x0000014C, field:this:0x00000154, field:this:0x0000015C, field:this:0x0000020C, field:this:0x00000214, field:this:0x0000021C, source:raw]
    // GUARD: Second clamp branch entered when v13 > 0.25 * v14 [source:raw]
    // CALCULATION: Damping radius v15 = min(this+204, this+188, this+196); clamp ratio v16 = sqrt(v13) / (sqrt(v14) + v15 * 128.0); when v16 > 0.5 the scale becomes 0.5 / v16, kept only when smaller than the current scale [field:this:0x000000CC, field:this:0x000000BC, field:this:0x000000C4, source:raw]
    // ASSIGNMENT: Linear position advance: this+4 = a2 * this+100 + this+356; this+12 = a2 * this+108 + this+364; this+20 = a2 * this+116 + this+372 [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000014, field:this:0x00000064, field:this:0x0000006C, field:this:0x00000074, field:this:0x00000164, field:this:0x0000016C, field:this:0x00000174, source:raw]
    // ASSIGNMENT: Linear velocity advance: factor v18 = a2 * this+180; this+100 = v18 * this+308 + this+452; this+108 = v18 * this+316 + this+460; this+116 = v18 * this+324 + this+468 [field:this:0x000000B4, field:this:0x00000064, field:this:0x0000006C, field:this:0x00000074, field:this:0x00000134, field:this:0x0000013C, field:this:0x00000144, field:this:0x000001C4, field:this:0x000001CC, field:this:0x000001D4, source:raw]
    // ASSIGNMENT: Angular momentum scaled into v24: v24[0] = a2 * this+124, v24[1] = a2 * this+132, v24[2] = a2 * this+140 [field:this:0x0000007C, field:this:0x00000084, field:this:0x0000008C, source:raw]
    // ASSIGNMENT: Staging copy of a 72-byte state block: qmemcpy(this+28, this+380, 0x48u) [source:raw]
    // CALL: sub_56C020 invoked with the scaled angular-momentum vector v24 [callee:0x0056C020, source:raw]
    // ASSIGNMENT: Angular momentum advance: this+148 = a2 * this+332 + this+476; this+156 = a2 * this+340 + this+484; this+164 = a2 * this+348 + this+492 [field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x0000014C, field:this:0x00000154, field:this:0x0000015C, field:this:0x000001DC, field:this:0x000001E4, field:this:0x000001EC, source:raw]
    // CALL: F_3x3InertiaTensorTransform transforms the inertia tensor against the momentum state [callee:0x005692A0, source:raw]
    // ASSIGNMENT: Inertia-tensor result written back to angular velocity: this+124 = this+236 * this+148 + this+244 * this+156 + this+252 * this+164; this+132 = this+260 * this+148 + this+268 * this+156 + this+276 * this+164; this+140 = this+284 * this+148 + this+292 * this+156 + this+300 * this+164 [field:this:0x00000094, field:this:0x0000009C, field:this:0x000000A4, field:this:0x000000EC, field:this:0x000000F4, field:this:0x000000FC, field:this:0x00000104, field:this:0x0000010C, field:this:0x00000114, field:this:0x0000011C, field:this:0x00000124, field:this:0x0000012C, source:raw]
    // RETURN: Returns the clamp scale v21 (1.0 when no clamp applied) [source:raw]
    // CALL: Invoked per frame tick by VehiclePhysicsVelocityAngularVelocityIntegrator (00459AE0) and by IterateAndFindMinimumValueFromFunction (0056F090) [caller:0x00459AE0, caller:0x0056F090, source:raw]

    // Conservative worker pseudocode:
    //   scale = 1.0;
    //   dx = this+308 - this+500; dy = this+324 - this+516; dz = this+316 - this+508;
    //   d2 = dx*dx + dy*dy + dz*dz;
    //   ref2 = this+500*this+500 + this+508*this+508 + this+516*this+516;
    //   if (d2 > 0.25 * ref2) {
    //     r = sqrt(d2) / (sqrt(ref2) + this+172 * 128.0);
    //     if (r > 0.5) { s = 0.5 / r; if (s < 1.0) scale = s; }
    //   }
    //   dx2 = this+332 - this+524; dy2 = this+340 - this+532; dz2 = this+348 - this+540;
    //   d3 = dx2*dx2 + dy2*dy2 + dz2*dz2;
    //   ref3 = this+524*this+524 + this+532*this+532 + this+540*this+540;
    //   if (d3 > 0.25 * ref3) {
    //     radius = min(this+204, this+188, this+196);
    //     r2 = sqrt(d3) / (sqrt(ref3) + radius * 128.0);
    //     if (r2 > 0.5) { s2 = 0.5 / r2; if (s2 < scale) scale = s2; }
    //   }
    //   this+4  = a2 * this+100 + this+356;
    //   this+12 = a2 * this+108 + this+364;
    //   this+20 = a2 * this+116 + this+372;
    //   vscale = a2 * this+180;
    //   this+100 = vscale * this+308 + this+452;
    //   this+108 = vscale * this+316 + this+460;
    //   this+116 = vscale * this+324 + this+468;
    //   momentum[3] = { a2 * this+124, a2 * this+132, a2 * this+140 };
    //   copy 72 bytes from this+380 to this+28;
    //   sub_56C020(momentum);
    //   this+148 = a2 * this+332 + this+476;
    //   this+156 = a2 * this+340 + this+484;
    //   this+164 = a2 * this+348 + this+492;
    //   F_3x3InertiaTensorTransform(this);
    //   this+124 = this+236 * this+148 + this+244 * this+156 + this+252 * this+164;
    //   this+132 = this+260 * this+148 + this+268 * this+156 + this+276 * this+164;
    //   this+140 = this+284 * this+148 + this+292 * this+156 + this+300 * this+164;
    //   return scale;
    // UNRESOLVED: Four read-only globals (dbl_59E420, dbl_59E880, dbl_59EB50, dbl_5B89B8) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill implies constants but none are verifiable from this packet
    // UNRESOLVED: The staging copy this+28 from this+380 (0x48 bytes) touches byte offsets that are absent from the packet field table; their purpose is described only from the raw source
    // UNRESOLVED: The suspension node layout behind this+172, this+188..this+204 and the 0.25/0.5/128.0 constants is not defined by this packet
}
