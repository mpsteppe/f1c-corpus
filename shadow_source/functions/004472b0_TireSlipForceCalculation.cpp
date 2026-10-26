// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004472B0
// Canonical corpus name: TireSlipForceCalculation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireSlipForceCalculation_004472b0.c

void UnknownObject::TireSlipForceCalculation()
{
    // Per-wheel tire force and contact-effect computation for a 4-wheel vehicle on the frame path. Loop 1 (4 wheels) computes per-wheel slip factors and force slots from a per-wheel table (base unk_7C7810, 1124-byte stride) into an output float array (a2+61, 74-float stride), calling CRTFtol and dispatching CollisionEffectDispatch for wheels with a contact object. Loop 2 computes a longitudinal force modifier from this+0x8, this+0x1C5C, this+0x1CDC and writes a2[38]/a2[43]/a2[48], dispatching ParticleCollisionEffect through the vehicle transform at this+0x15F0. Loop 3 checks per-wheel contact offsets (arrays at this+0x16E0/0x16F0) and flags distant contacts via SetWheelContactFlags. Loop 4 normalizes a per-wheel value from this+0x690 into [0,1]. Reads many read-only constant-pool doubles/floats per the deterministic facts. Called from sub_4EE2D0.
    // LOOP: Per-wheel slip loop over 4 wheels (v46 = 4): per-wheel table pointer v3 starts at unk_7C7810 and advances 1124 bytes per wheel; per-wheel float output pointer v4 = a2 + 61 advances 74 floats per wheel. [global:0x007C7810, source:raw]
    // CALCULATION: Compute slip factor v5: if the double at (v3 - 4 doubles) is <= 0.0 then 0.0, else 1.0 - double at (v3 - 2 doubles); both accesses relative to the per-wheel table base. [global:0x007C7810, source:raw]
    // CALCULATION: First piecewise force slot: store at *(v4 - 1) the value (v5 - 0.66000003) * 2.941176697457143 when v5 > 0.66000003, else 0.0. [source:raw]
    // CALCULATION: Second piecewise force slot: store at *v4 the value (v5 - 0.38999999) * 1.639344223850808 when v5 > 0.38999999, else 0.0. [source:raw]
    // ASSIGNMENT: Pack wheel outputs: v4[3] = *v4; *(v4 + 2) = *(v4 - 1); *(v4 + 5) = CRTFtol(*v4 * 16.0); v4[1] = v8 where v8 is 0.0 when the (v3 - 4 doubles) table value is <= 0.0 else the double at v3 + 276; v4[4] = 0.0; and when v8 > 0.0 clear *(v4 - 1), v4[2], v4[3]. [callee:0x00587BDC, source:raw]
    // CALL: For each wheel whose contact index v9 = dword at (v3 + 66 dwords) is nonzero: build the contact position/direction from the wheel surface object at *v3 and the collision position double at this+0x60, then dispatch CollisionEffectDispatch((v4 - 8 floats), this+0x60, contactPos, contactDir, v9, *(*(this+0x1F00) + 0x4894)). [callee:0x004CE3E0, field:this:0x00000060, field:this:0x00001F00, field:*(this+0x1F00):0x00004894, source:raw]
    // GUARD: Post-loop guard: if this+0x1DE4, this+0x1DEC and this+0x1DF4 (three per-axis doubles) are all 0.0, zero the three output slots a2[38], a2[43], a2[48]. [field:this:0x00001DE4, field:this:0x00001DEC, field:this:0x00001DF4, source:raw]
    // CALL: Else transform the center of mass: TransformApply3D((v16 + 28), (v16 + 4), (this + 7676 doubles), &v55) where v16 = *(this+0x15F0) is the vehicle transform pointer; the transform position start is v16 + 4. [callee:0x0043AEE0, field:this:0x000015F0, field:*(this+0x15F0):0x00000004, field:*(this+0x15F0):0x0000000C, field:*(this+0x15F0):0x00000014, source:raw]
    // CALCULATION: Build the transformed center-of-mass position vector &v51 from v55/v56/v57 and the direction vector &v48 from the transform doubles v16 + 100, v16 + 108, v16 + 116. [field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, source:raw]
    // CALCULATION: Compute longitudinal force modifier v19 = -1.0 / double(this+0x1CDC) * double(this+0x1C5C) * double(this+0x8), clamped into [-1.0, 0.0]. [field:this:0x00001CDC, field:this:0x00001C5C, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the three clamped output slots: a2[38] = (this+0x1DE4 <= 0.0) ? v19 * double(this+0x1DE4) : double(this+0x1DE4), a2[43] likewise from this+0x1DEC, a2[48] likewise from this+0x1DF4. [field:this:0x00001DE4, field:this:0x00001DEC, field:this:0x00001DF4, source:raw]
    // CALL: Dispatch ParticleCollisionEffect((a2 + 38), this+0x60, &v51, &v48, *(*(this+0x1F00) + 0x4894)). [callee:0x004CE930, field:this:0x00000060, field:this:0x00001F00, field:*(this+0x1F00):0x00004894, source:raw]
    // LOOP: Wheel-contact skid loop over 4 wheels (v23 from 0 to 4): v44 walks the per-wheel double array at this+0x16F0, v45 walks the per-wheel dword array at this+0x16E0, v47 walks per-wheel 3-double vectors at this+5728. [field:this:0x000016F0, field:this:0x000016E0, source:raw]
    // GUARD: Per-wheel contact guard: when double at this+0x16F0 (*v44) < 0.0, the dword at this+0x16E0 (*(v45)) is nonzero, and the surface flag *(*(*(v45) + 84) + 40) (i.e. *(*(this+0x16E0) + 0x54) + 0x28) is nonzero, proceed to evaluate the contact offset. [field:this:0x000016F0, field:this:0x000016E0, field:*(this+0x16E0):0x00000054, field:*(*(this+0x16E0)+0x54):0x00000028, source:raw]
    // CALL: TransformApply3D((v24 + 28), (v24 + 4), v47, v58) with v24 = *(this+0x15F0) reloaded as the vehicle transform pointer. [callee:0x0043AEE0, field:this:0x000015F0, source:raw]
    // CALCULATION: Compute the world-space delta v25/v26/v27 between the transformed v58 vector and the transform position (v24 + 4, + 12, + 20), then the offset vector v55/v56/v29 = cross products against the transform doubles v24 + 124/+132/+140 summed with v24 + 100/+108/+116. [field:*(this+0x15F0):0x00000004, field:*(this+0x15F0):0x0000000C, field:*(this+0x15F0):0x00000014, field:*(this+0x15F0):0x0000007C, field:*(this+0x15F0):0x00000084, field:*(this+0x15F0):0x0000008C, field:*(this+0x15F0):0x00000064, field:*(this+0x15F0):0x0000006C, field:*(this+0x15F0):0x00000074, source:raw]
    // CALL: When the squared offset magnitude (v55*v55 + v56*v56 + v29*v29) exceeds 25.0, build the half-scaled position v54 (×0.5, y + 3.0) and call SetWheelContactFlags(v23, 15, 10, v54). [callee:0x004EF560, source:raw]
    // LOOP: Normalization loop over 4 wheels (v33): v32 walks the per-wheel double array at this+0x690 (1124-byte stride), output pointer v31 = a2 + 122 advances 74 floats per wheel. [field:this:0x00000690, source:raw]
    // CALCULATION: Compute v35 = (*v32 - 1023.16) * 0.004, clamp into [0.0, 1.0], and store *v31 = v35. [source:raw]
    // CALL: Called from sub_4EE2D0, the vehicle physics tick, on the frame path. [caller:0x004EE2D0]
    // RETURN: Return the caller-propagated result (high word of a2). [function:0x004472B0, source:raw]

    // Conservative worker pseudocode:
    //   int TireSlipForceCalculation(int this, float *a2) {
    //     // Loop 1: per-wheel slip/force slots (4 wheels)
    //     v3 = (char *)&unk_7C7810; v4 = a2 + 61;
    //     for (w = 4; w; --w) {
    //       v5 = (*(double *)(v3 - 32) <= 0.0) ? 0.0 : 1.0 - *(double *)(v3 - 16);
    //       *(v4 - 1) = (v5 > 0.66000003) ? (v5 - 0.66000003) * 2.941176697457143 : 0.0;
    //       *v4 = (v5 > 0.38999999) ? (v5 - 0.38999999) * 1.639344223850808 : 0.0;
    //       v8 = (*(double *)(v3 - 32) <= 0.0) ? 0.0 : *(double *)(v3 + 276);
    //       v4[3] = *v4; *(DWORD *)(v4 + 2) = *(DWORD *)(v4 - 1);
    //       *(DWORD *)(v4 + 5) = CRTFtol(*v4 * 16.0);
    //       v4[1] = v8; v4[4] = 0.0;
    //       if (v8 > 0.0) { *(v4 - 1) = 0.0; v4[2] = 0.0; v4[3] = 0.0; }
    //       if (*(DWORD *)(v3 + 264)) CollisionEffectDispatch((v4 - 8), *(double *)(this + 96), &v51, &v48, v9, *(DWORD *)(*(DWORD *)(this + 7936) + 18580));
    //       v3 += 1124; v4 += 74;
    //     }
    //     // Loop 2: center-of-mass longitudinal force modulation
    //     if (*(double *)(this + 7652) == 0.0 && *(double *)(this + 7660) == 0.0 && *(double *)(this + 7668) == 0.0) {
    //       a2[38] = 0.0; a2[43] = 0.0; a2[48] = 0.0;
    //     } else {
    //       TransformApply3D((v16 + 28), (v16 + 4), (this + 7676), &v55);
    //       v19 = clamp(-1.0 / *(double *)(this + 7388) * *(double *)(this + 7260) * *(double *)(this + 8), -1.0, 0.0);
    //       a2[38] = (*(double *)(this + 7652) <= 0.0) ? v19 * *(double *)(this + 7652) : *(double *)(this + 7652);
    //       a2[43] = (*(double *)(this + 7660) <= 0.0) ? v19 * *(double *)(this + 7660) : *(double *)(this + 7660);
    //       a2[48] = (*(double *)(this + 7668) <= 0.0) ? v19 * *(double *)(this + 7668) : *(double *)(this + 7668);
    //       ParticleCollisionEffect((a2 + 38), *(double *)(this + 96), &v51, &v48, *(DWORD *)(*(DWORD *)(this + 7936) + 18580));
    //     }
    //     // Loop 3: wheel-contact offset flagging (4 wheels)
    //     for (v23 = 0; v23 < 4; ++v23) {
    //       if (*(double *)(this + 5872 + v23 * 8) < 0.0 && *(DWORD *)(this + 5856 + v23 * 4) &&
    //           *(DWORD *)(*(DWORD *)(*(DWORD *)(this + 5856 + v23 * 4) + 84) + 40)) {
    //         TransformApply3D((v24 + 28), (v24 + 4), v47, v58);
    //         // compute cross-product offset vector; when magnitude^2 > 25.0
    //         v54[0] = v55 * 0.5; v54[1] = v56 * 0.5 + 3.0; v54[2] = v29 * 0.5;
    //         SetWheelContactFlags(v23, 15, 10, v54);
    //       }
    //     }
    //     // Loop 4: normalize per-wheel value into [0,1]
    //     for (v33 = 4; v33; --v33) {
    //       v35 = (*v32 - 1023.16) * 0.004;
    //       *v31 = (v35 < 0.0) ? 0.0 : ((v35 > 1.0) ? 1.0 : v35);
    //       v32 = (double *)((char *)v32 + 1124); v31 += 74;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The read-only constant globals dbl_59E420, dbl_59E428, dbl_59E430, flt_59E43C, flt_59E440, dbl_59E7E0, dbl_59E880, flt_59E974, dbl_59ECA8, dbl_59EEC0, dbl_59EEC8, flt_59EED0, dbl_59EED8, flt_59EEE0, dbl_59EEE8 and dword_8ACEA0 are reported read by the deterministic facts but are not referenced by name in the decompiled body; they are presumed constant-pool operands of the arithmetic (0.66000003, 2.941176697457143, 0.38999999, 1.639344223850808, 16.0, 1023.16, 0.004, 25.0, 3.0, 0.5), but the exact constant-to-global mapping is not established.
    // UNRESOLVED: The per-wheel table (base unk_7C7810, 1124-byte stride) and the surface objects referenced by *v3 are not type-identified; their layout is inferred only from the double/dword reads.
    // UNRESOLVED: The a2 output array roles (slots a2[38]/a2[43]/a2[48] and *(a2 + 122)) as per-axis force/velocity and normalized temperature outputs are inferred from call context, not established.
    // UNRESOLVED: Field roles for this+0x1DE4/0x1DEC/0x1DF4 (clamped outputs) and this+0x1C5C/0x1CDC (force-modifier denominators) are DERIVED from the arithmetic shape only.
    // UNRESOLVED: The CollisionEffectDispatch/SetWheelContactFlags constant arguments (15, 10, and the effect id v9) have unestablished enum meanings.
}
