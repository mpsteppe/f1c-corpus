// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00438130
// Canonical corpus name: VehicleDynamicsForceAccumulatorIntegration
// Owner: F1CVehicle [DERIVED]
// Raw source: functions/VehicleDynamicsForceAccumulatorIntegration_00438130.c

void F1CVehicle::VehicleDynamicsForceAccumulatorIntegration()
{
    // Per-frame vehicle brake/tire thermal integration and wear simulation, called by the vehicle physics integration step. Converts brake force, slip, and angular velocity into per-wheel heat, integrates temperatures with ambient Kelvin offsets (flt_8AFEF0/flt_8AFEF4 + 273.16), clamps the integrated temperature into a safe range, and computes a wear/degradation term from torque and slip ratio. On extreme slip it triggers a blowout-style transition that scales down the brake/tire force fields and resets degradation, and it dispatches pit-state or AI-phase transitions (AISessionPhaseCounter / PitStateSlotActivation) based on slip classification.
    // CALCULATION: Ambient reference temperatures: v33 = flt_8AFEF4 + 273.16 and v36 = flt_8AFEF0 + 273.16 (Kelvin offsets used as convection targets). [global:0x008AFEF4, global:0x008AFEF0]
    // GUARD: Brake heat source v3 gated by this+0x324 (804): if not positive, heat is 0; otherwise v3 = fabs(this+0xBC) * this+0x3A4 * this+0x324. [field:this:0x00000324, field:this:0x000000BC, field:this:0x000003A4]
    // GUARD: Brake thermal input gated by this+0x31C (796): if not positive, v28 and v4 are 0; otherwise v28 = (1.0 - this+0x14C) * this+0x268 * this+0x31C and v4 = v28 * this+0x3AC. [field:this:0x0000031C, field:this:0x0000014C, field:this:0x00000268, field:this:0x000003AC]
    // CALCULATION: Speed term v5 = this+0x314 (788) * 5.555555555555555, clamped to [-1, 1] as a blend factor. [field:this:0x00000314]
    // CALCULATION: Slip term v32 = this+0x344 * this+0x31C + this+0x33C; v9 = (v32 - this+0x374) * 0.02777777777777778, clamped to [-1, 1]. [field:this:0x00000344, field:this:0x0000031C, field:this:0x0000033C, field:this:0x00000374]
    // CALCULATION: Angular-velocity magnitude of the sub-object at this+0x15C from doubles at +0x64, +0x6C and +0x74 (sqrt of sum of squares), scaled by this+0x3C4 and offset this+0x3BC, then by v16 = flt_8AFEE4 + this+0x270 + 1.0; v17 = v16 * this+0x3B4. [field:this:0x0000015C, field:*(this+0x15C):0x00000064, field:*(this+0x15C):0x0000006C, field:*(this+0x15C):0x00000074, field:this:0x000003C4, field:this:0x000003BC, global:0x008AFEE4, field:this:0x00000270, field:this:0x000003B4]
    // LOOP: Three-element integration loop over the temperature copy sourced from this+0x34C: accumulate the v3/v4 heat terms weighted by the v38/v39 blend factors and frame time a2, add ambient convection toward v33/v36 scaled by v17, and subtract the drain term v20 = (v18 - v40) * a2 * 0.005 from this+0x364 (868). [field:this:0x0000034C, field:this:0x00000364]
    // GUARD: Clamp the integrated temperature this+0x364 (868): below 273.16 set this+0x368 to 1081152143 and this+0x364 to 1546188227; above 546.3200000000001 set this+0x368 to 1082200719 and repeat the low clamp. [field:this:0x00000364, field:this:0x00000368]
    // CALL: Compute force/torque products via TorqueForceProductComputation(this). [callee:0x00438100]
    // CALCULATION: Average torque v34 = (this+0x35C + this+0x354 + *v21) * 0.3333333333333333; wear term v31 = (fabs(v26) + fabs(v30) + 4.0) * 0.1666666666666667 * this+0x3CC * (v34 / this+0x334)^2 * v28 * a2. [field:this:0x0000035C, field:this:0x00000354, field:this:0x000003CC, field:this:0x00000334]
    // GUARD: Debug/telemetry gate: slip-state classification only runs when dword_7D0308 is set and flt_7CF3C8 is non-zero. [global:0x007D0308, global:0x007CF3C8]
    // STATE_TRANSITION: Slip classification from this+0x394 (916): v27 = (this+0x394 - 0.75) * 4.0, v29 = (this+0x394 - v31 - 0.75) * 4.0; if v27 equals 1.0 clear dword_5EC3BC[this+0x78]; else if v27 > 0.4 and v29 <= 0.4 call PitStateSlotActivation(dword_5EB978, this+0x78); otherwise AISessionPhaseCounter(dword_5EB978, this+0x78). [field:this:0x00000394, field:this:0x00000078, global:0x005EC3BC, global:0x005EB978, callee:0x0041AB30, callee:0x0041AA10]
    // GUARD: Blowout/lock transition: while this+0x394 (916) exceeds 0.75 subtract v31; when it drops to <= 0.75 zero this+0x394, write 1072168960 to this+0x398, scale this+0x384 by 0.18, this+0x234 by 4.0, and this+0x44C/this+0x278/this+0x454/this+0x288 each by 0.7; then this+0x36C = min(this+0x37C * 0.25, 10.0) * 0.002778858444950814. [field:this:0x00000394, field:this:0x00000398, field:this:0x00000384, field:this:0x00000234, field:this:0x0000044C, field:this:0x00000278, field:this:0x00000454, field:this:0x00000288, field:this:0x0000037C, field:this:0x0000036C]
    // CALCULATION: Load factor v25 = fabs(v34 - this+0x334) / this+0x334 * 0.9 + fabs(this+0x374 - v32) / v32 * 0.6, clamped to [0, 1]; final write this+0x39C = (1.0 - v25*v25*0.5) * this+0x394. [field:this:0x00000334, field:this:0x00000374, field:this:0x0000039C, field:this:0x00000394]
    // RETURN: Void return. [function:0x00438130, source:raw]

    // Conservative worker pseudocode:
    //   v33 = flt_8AFEF4 + 273.16; v36 = flt_8AFEF0 + 273.16;
    //   heat = this[0x324] <= 0 ? 0 : fabs(this[0xBC]) * this[0x3A4] * this[0x324];
    //   brake_in = this[0x31C] <= 0 ? 0 : (1 - this[0x14C]) * this[0x268] * this[0x31C];
    //   integrate per-wheel temperature with ambient convection and drain;
    //   clamp temperature range; on slip classification dispatch pit/AI phase.
    //   if degradation > 0.75 then scale thermal fields by 0.7 (blowout).
    // UNRESOLVED: Twenty-four dbl_59E* globals (0x0059E420-0x0059EB90) are listed as read globals in the packet but do not appear in the rendered decompiled source; their role in this function is unknown.
    // UNRESOLVED: Owner proposed as F1CVehicle (DERIVED) from the calling context (VehiclePhysicsIntegrationStep) and vehicle subsystem tag; not independently confirmed.
    // UNRESOLVED: The average-torque read *v21 (edx) has no explicit packet field evidence; treated as part of the this+0x354/0x35C averaging.
}
