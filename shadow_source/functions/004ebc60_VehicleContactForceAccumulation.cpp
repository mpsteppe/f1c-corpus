// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EBC60
// Canonical corpus name: VehicleContactForceAccumulation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleContactForceAccumulation_004ebc60.c

void UnknownObject::VehicleContactForceAccumulation()
{
    // Per-frame contact-impulse accumulation for a vehicle. Transforms the local contact basis (via sub_4EA930) and the local impulse a2[8..10] through the rotation matrix at this+0x34B0..0x34D0, accumulates world-space linear (this+0x34EC..0x34F4 from this+0x34F8..0x3500) and angular (this+0x3504..0x350C from cross-product terms scaled by this+0x3528..0x3530) impulses, then dispatches on the mode selector at this+0x32BC: mode 0 feeds a physics impulse (F_6FieldStructInit + AccumulateAngularImpulse), modes 0..1 with the a3 enable flag spawn collision sparks (CollisionSparkParticleEffects), and mode 2 resolves an object pointer (ConditionalStridePointerComputation), converts its short-vector, scales and adds the impulse, and processes it (UtilityFunction_2480). Returns the mode-dependent result byte.
    // CALL: Transform the local contact basis: sub_4EA930(a2 + 5, (float*)this + 3381, v33) returns a pointer to the basis components v7, v8, v27 and stores the result in v33. [callee:0x004EA930, source:raw]
    // CALCULATION: World-transform the linear impulse: combine the sub_4EA930 basis components (v7, v8, v27) with the rotation matrix at this+0x34B0..0x34D0 (float indices 3372..3380) into the linear components v28/v29/v30. [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Compute angular contributions v11, v12 and v34 by applying the transposed rotation matrix (this+0x34B0..0x34D0) to the local impulse a2[8..10], with a2[1] as the scale factor. [field:this:0x000034B0, field:this:0x000034B4, field:this:0x000034B8, field:this:0x000034BC, field:this:0x000034C0, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034CC, field:this:0x000034D0, source:raw]
    // CALCULATION: Scale the components by a2[1] into v25/v26/v27 (v33[0..1]), then by the frame factor this+0x3518 (float index 3398) into v31[1]/v32, and accumulate into this+0x34F8..0x3500 (float indices 3390..3392). [field:this:0x00003518, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, source:raw]
    // CALCULATION: Accumulate world-space linear impulse: write this+0x34EC..0x34F4 (float indices 3387..3389) by transposing the accumulated local components this+0x34F8..0x3500 through the rotation matrix. [field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4, field:this:0x000034F8, field:this:0x000034FC, field:this:0x00003500, source:raw]
    // CALCULATION: Accumulate angular impulse: build cross-product terms v32/v14/v25 from the linear components, scale them by this+0x3528..0x3530 (float indices 3402..3404), and add into this+0x3504..0x350C (float indices 3393..3395). [field:this:0x00003504, field:this:0x00003508, field:this:0x0000350C, field:this:0x00003528, field:this:0x0000352C, field:this:0x00003530, source:raw]
    // GUARD: Mode guard: if the contact-processing mode at this+0x32BC (DWORD index 3247) is zero, run the physics-impulse branch. [field:this:0x000032BC, source:raw]
    // CALL: Initialize a six-field vector from the scaled contact velocity: F_6FieldStructInit(v17 * a2[8], v17 * a2[9], v17 * a2[10]) where v17 = a2[1] * 40.0. [callee:0x004EC050, source:raw]
    // CALL: Feed the accumulated angular impulse to the physics object: AccumulateAngularImpulse(&dbl_7C7428, v35, &v31). [callee:0x0043E5D0, global:0x007C7428, source:raw]
    // ASSIGNMENT: Re-read the mode selector: v18 = *(DWORD*)(this + 0x32BC). [field:this:0x000032BC, source:raw]
    // GUARD: Dispatch on the mode selector: modes 0..1 use the spark-particle path, mode 2 uses the pointer-chain path, otherwise return v18 unchanged. [field:this:0x000032BC, source:raw]
    // CALL: Spawn contact spark effects when the a3 enable flag is non-zero: CollisionSparkParticleEffects(&v28, v33, a2[1]); otherwise v18 = a3. [callee:0x004EC1A0, source:raw]
    // CALL: Mode-2 path: resolve an object pointer via ConditionalStridePointerComputation(dword_7CD25C, *(DWORD*)(*(DWORD*)this + 0x4894)), reading the base-object field through the object pointer stored at this+0x0. [callee:0x00463DC0, global:0x007CD25C, field:this:0x00000000, field:obj:0x00004894, source:raw]
    // CALL: Convert a short-vector at the resolved object + 8 to floats with scale: ShortVectorToFloatWithScale(v18 + 8, &v25). [callee:0x004B2580, source:raw]
    // CALL: Scale the local impulse vector: Vector3ScalarMultiply(a2 + 8, v35, a2[1] * *(float*)(this + 0x3518)) and copy the result into v31/v32. [callee:0x0045EB00, field:this:0x00003518, source:raw]
    // CALL: Add the scaled vector in place: F_3DVectorAddition(&v31). [callee:0x004EC020, source:raw]
    // CALL: Process the short-vector result: UtilityFunction_2480(v19, &v25); its return value becomes v18. [callee:0x004B2480, source:raw]
    // RETURN: Return v18, the mode-dependent result byte. [function:0x004EBC60, source:raw]

    // Conservative worker pseudocode:
    //   char VehicleContactForceAccumulation(void* this, float* a2, char a3) {
    //     float* basis = sub_4EA930(a2 + 5, (float*)this + 3381, v33);
    //     // v7,b8,v27 = basis; world-transform linear components v28/v29/v30
    //     //   from rotation matrix this+3372..3380;
    //     // accumulate world-space linear this+3387..3389 from this+3390..3392;
    //     // accumulate angular this+3393..3395 from cross products scaled by this+3402..3404
    //     if (*(int*)((char*)this + 0x32BC) == 0) {
    //       F_6FieldStructInit(v17 * a2[8], v17 * a2[9], v17 * a2[10]); // v17 = a2[1] * 40.0
    //       AccumulateAngularImpulse(&dbl_7C7428, v35, &v31);
    //     }
    //     int mode = *(int*)((char*)this + 0x32BC);
    //     if (mode <= 1) {
    //       if (a3) result = CollisionSparkParticleEffects(&v28, v33, a2[1]);
    //     } else if (mode == 2) {
    //       result = ConditionalStridePointerComputation(dword_7CD25C, *(int*)(*(int*)this + 0x4894));
    //       if (result) {
    //         ShortVectorToFloatWithScale(result + 8, &v25);
    //         Vector3ScalarMultiply(a2 + 8, v35, a2[1] * *(float*)((char*)this + 0x3518));
    //         F_3DVectorAddition(&v31);
    //         result = UtilityFunction_2480(result + 8, &v25);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Global flt_59E86C is listed in the packet's globals but does not appear in the raw source text; its role here is unknown.
    // UNRESOLVED: The rotation-matrix layout at this+0x34B0..0x34D0 and the accumulator semantics at this+0x34EC..0x350C are derived from float-index arithmetic (4N byte offsets); the vehicle-struct layout for these rows is not confirmed.
    // UNRESOLVED: Existing analysis labels this+0x34B8 as elapsedTime [CONFIRMED], but the raw source uses float index 3374 (= this+0x34B8) as a rotation-matrix element in the transform; the conflict is not resolved here.
    // UNRESOLVED: The mode-selector values (0 = physics impulse, <=1 = spark effects, 2 = pointer chain) are inferred from the guard structure and existing analysis, not confirmed.
    // UNRESOLVED: The 40.0 multiplier on a2[1] and the scale factor at this+0x3518 (elapsed-time-like) are unproven.
    // UNRESOLVED: Decompiler temporaries v25..v37 and the a2 float array have no owner evidence; the resolved object's short-vector structure (offset +8) is unproven.
}
