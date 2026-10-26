// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040ADB0
// Canonical corpus name: CameraShake
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraShake_0040adb0.c

void UnknownObject::CameraShake()
{
    // Camera shake / collision-reaction computation. Selects the current camera entry as a stride-160 element (index = this+0x14, base = this+0xC), negates its position as a reference point, and, when the enable flag this+0x4 is set and the entry flag (byte +0x74 & 4) allows it, scans the vehicle array (count dword_5C329C, pointers dword_7C54F0) for a vehicle whose squared distance is below 250.0 and whose speed (sqrt of velocity at +88) exceeds 35.0. On hit it computes a proximity-derived collision strength and invokes CollisionResponseWithRandomPerturbation; on no hit it falls through to StateActivatedPositionSaveRestore. It then reads the local player vehicle data (dword_7C54E0), dispatches a vtable method at camera-entry dispatch+24, applies position/orientation processing (UtilityFunction_1cd0), converts two angle fields from degrees to radians (0.01745433) and applies them (sub_542050), sets two fields (TwoFieldSetterCall) and returns ConditionalFloatSetter of the entry float at +0x48.
    // CALCULATION: Select current camera entry: v2 = this[5] * 160 (stride 160), entry pointer v5 = this[3] + v2 (base + offset). [field:this:0x0000000C, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Build negated reference position from the camera entry: v29 = -entry[+0xC], v30 = -entry[+0x10], v31 = -entry[+0x14] (v4 = *(float*)(v2+v3+12)). [source:raw]
    // GUARD: Guard on enable flag: if (this[1]) at offset 0x4 is non-zero, proceed; otherwise return uninitialized result. [field:this:0x00000004, source:raw]
    // GUARD: Guard on camera-entry flag: only proceed when (byte at entry +0x74 & 4) is non-zero. [source:raw]
    // LOOP: Scan vehicle array: loop index v7 over 0..dword_5C329C, vehicle pointer v8 = dword_7C54F0[v7]. [global:0x005C329C, global:0x007C54F0, source:raw]
    // CALCULATION: Compute squared distance v17 between the vehicle position (read at v8+1860, v8+1864, v8+1868) and the negated reference position (v29/v30/v31). [source:raw]
    // GUARD: Proximity/speed gate: if v17 < 250.0, read the vehicle velocity (three floats at v8+88) and break when sqrt of its squared magnitude exceeds 35.0. [source:raw]
    // STATE_TRANSITION: If the loop exhausts with no qualifying vehicle, fall through to StateActivatedPositionSaveRestore(0); otherwise break to the collision-response path. [callee:0x00457B00, source:raw]
    // CALCULATION: Derive collision strength from proximity: v18 = 1.0 - v17 * 0.0040000002. [source:raw]
    // CALL: Query scoring gate condition: v16 = ScoringGateConditionCheck(this). [callee:0x0040C780, source:raw]
    // CALL: Invoke collision response: CollisionResponseWithRandomPerturbation(v18, v16). [callee:0x00457A00, source:raw]
    // ASSIGNMENT: Read local player vehicle (dword_7C54E0) position at +1860/+1864/+1868, velocity at +1796/+1800/+1804 and +88/+92/+96 into local buffers (v26..v31). [global:0x007C54E0, source:raw]
    // CALCULATION: Load the camera-entry dispatch/vtable pointer: v10 = *(float*)entry base (entry + 0x0). [source:raw]
    // CALL: Query scoring gate condition again: v15 = ScoringGateConditionCheck(this). [callee:0x0040C780, source:raw]
    // CALL: Compute dispatch float parameter: v13 = ShortComputation_84a0(). [callee:0x004084A0, source:raw]
    // CALL: Indirect __thiscall dispatch via entry vtable (v10 + 24) with arguments (entry, &v26, &v23, &v29, v13, v15) - camera entry method taking position/velocity references and two float params. [source:raw]
    // ASSIGNMENT: Read camera entry position/orientation at entry[+3..+8] (offsets +0xC..+0x20) into v26..v25. [source:raw]
    // CALL: Process entry position/orientation: UtilityFunction_1cd0(v26, v27, v28, v23, v24, v25). [callee:0x00541CD0, source:raw]
    // CALL: Fetch two camera angle fields: DualFieldGetter(&v20, &v19). [callee:0x00456060, source:raw]
    // CALCULATION: Convert the two angle fields to radians: v14 = v19 * 0.01745433, v12 = v20 * 0.01745433. [source:raw]
    // CALL: Fetch two integer camera parameters: ShortComputation_6080(&v22, &v21). [callee:0x00456080, source:raw]
    // CALL: Apply camera rotation from the radian angles: sub_542050(v12, v14, 0). [callee:0x00542050, source:raw]
    // CALL: Set two camera fields: TwoFieldSetterCall(v22, v21). [callee:0x005423C0, source:raw]
    // RETURN: Return ConditionalFloatSetter(entry float at +0x48) (v5[18]); sets a float parameter from the camera entry field and returns its result. [callee:0x00542680, source:raw]

    // Conservative worker pseudocode:
    //   int CameraShake(_DWORD *this) {
    //     int idx = this[5];
    //     float *entry = (float *)this[3] + idx * 160;
    //     float refx = -entry[3], refy = -entry[4], refz = -entry[5];
    //     if (!this[1]) return result;
    //     if (((int)entry[29] & 4) != 0) {
    //       int i = 0;
    //       if (dword_5C329C > 0) {
    //         while (1) {
    //           int v = dword_7C54F0[i];
    //           float dx = *(float*)(v+1868) - refz, dy = *(float*)(v+1864) - refy, dz = *(float*)(v+1860) - refx;
    //           float dist2 = dx*dx + dy*dy + dz*dz;
    //           if (dist2 < 250.0f) {
    //             float vx = *(float*)(v+88), vy = *(float*)(v+92), vz = *(float*)(v+96);
    //             if (sqrt(vx*vx + vy*vy + vz*vz) > 35.0f) break;
    //           }
    //           if (++i >= dword_5C329C) goto no_hit;
    //         }
    //         float strength = 1.0f - dist2 * 0.0040000002f;
    //         CollisionResponseWithRandomPerturbation(strength, ScoringGateConditionCheck(this));
    //       } else {
    //   no_hit:
    //         StateActivatedPositionSaveRestore(0);
    //       }
    //     }
    //     /* read player vehicle data and dispatch camera entry method * /
    //     int p = dword_7C54E0;
    //     v26 = *(int*)(p+1860); v27 = *(int*)(p+1864); v28 = *(float*)(p+1868);
    //     v23 = *(int*)(p+1796); v24 = *(int*)(p+1800); v25 = *(int*)(p+1804);
    //     v29 = *(float*)(p+88); v30 = *(float*)(p+92); v31 = *(float*)(p+96);
    //     float vtable = *entry;
    //     ((void (__thiscall *)(float*, int*, int*, float*, int, int))(vtable + 24))(
    //       entry, &v26, &v23, &v29, ShortComputation_84a0(), ScoringGateConditionCheck(this));
    //     v26 = entry[3]; v27 = entry[4]; v28 = entry[5]; v23 = entry[6]; v24 = entry[7]; v25 = entry[8];
    //     UtilityFunction_1cd0(v26, v27, v28, v23, v24, v25);
    //     DualFieldGetter(&v20, &v19);
    //     ShortComputation_6080(&v22, &v21);
    //     sub_542050(v20 * 0.01745433f, v19 * 0.01745433f, 0);
    //     TwoFieldSetterCall(v22, v21);
    //     return ConditionalFloatSetter(entry[18]);
    //   }
    // UNRESOLVED: `result` is returned without initialization when the enable flag at this+0x4 is zero (compiler artifact / undefined value in the decompilation).
    // UNRESOLVED: Globals flt_59E43C, flt_59E65C, flt_59E670, flt_59E6A0, flt_59E6A4, flt_59E6A8 are listed in the packet/existing analysis but are not referenced by the raw source text; their roles in this function could not be confirmed from the evidence.
    // UNRESOLVED: Vehicle-struct offsets (+88 velocity, +1796/+1800/+1804, +1860/+1864/+1868 position) and the camera-entry stride-160 layout come from the raw source only; field names and types are unproven.
    // UNRESOLVED: The indirect dispatch at entry vtable +24 and the Callee names are semantic proposals; callee identity is confirmed only by the static call/ABI facts.
}
