// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C73F0
// Canonical corpus name: VehiclePhysicsTimeStep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehiclePhysicsTimeStep_004c73f0.c

void UnknownObject::VehiclePhysicsTimeStep()
{
    // Per-frame vehicle physics timestep: computes dt from the frame time argument, converts packed wheel/input data into steering, orientation and velocity fields, updates per-wheel suspension state, then runs subsystem/vibration state machines selected by a mode field. Ends by decoding braking, driver-visible and reverse flags from input bits and toggling the audio-effect controller on a state change.
    // ASSIGNMENT: Compute frame delta v36 = a3 - this+0x48B8 (previous time), then store a3 into this+0x48B8. [field:this:0x00018616]
    // CALL: ArithmeticComparison_2420 on input block a2+8 producing v37 and v39. [callee:0x004B2420]
    // CALL: EulerToRotationMatrix(v39, v43) converts the Euler triple into a 36-byte rotation matrix. [callee:0x00566E40]
    // CALL: F_3x3MatrixTransform(v37, v39, v43) transforms the comparison vector through the rotation matrix. [callee:0x004E23D0]
    // CALCULATION: BitfieldToFloatConversion(a2+8) yields steering v30, clamped into [-1, 1]; the clamped value is stored to this+0x1040. [callee:0x004B2A80, field:this:0x00004160]
    // CALCULATION: v35 = this+0x1044 * v30 (damping factor scaled by steering). [field:this:0x00004164]
    // LOOP: For wheels 0..3: sub_4B28F0(v5, i, &v32, &v41[i]) unpacks the wheel word; v34 = v36 * v41[i] + this+0x8C0[i*74]; SuspensionParamUpdate(i, v32, v34, v35 for front wheels i<2, else 0.0). [callee:0x004B28F0, callee:0x004E24A0, field:this:0x00002240]
    // CALL: ShortVectorToFloatWithScale(v5, v38) unpacks the short-vector velocity block. [callee:0x004B2580]
    // CALL: FloatTruncation(v5, v42) produces the truncated float triple. [callee:0x004B26D0]
    // CALL: ShortToFloatVectorUnpack(v5, v40) unpacks the 12-byte short vector. [callee:0x004B2800]
    // CALL: BitfieldExtractScale(v5) produces v31. [callee:0x004B2980]
    // CALL: ShortComputation_29f0(v5) produces v32 (velocity magnitude). [callee:0x004B29F0]
    // ASSIGNMENT: Store unpacked state: this+0x1C/0x20/0x24 = v37[0..2]; this+0x58/0x5C/0x60 = v38[0..2]; this+0xA0 = v31; this+0xA4 = v32; 0x24-byte block copy of v43 to this+0x34. [field:this:0x00000028, field:this:0x00000032, field:this:0x00000036, field:this:0x00000088, field:this:0x00000092, field:this:0x00000096, field:this:0x00000160, field:this:0x00000164]
    // ASSIGNMENT: this+0x1069 = (a2+52 & 0x80) != 0 (single-bit flag from input byte). [field:this:0x00004201]
    // GUARD: Read mode field this+0x32C8 and branch: mode == 2 takes the setup path, mode == 3 the state-machine path. [field:this:0x00013000]
    // STATE_TRANSITION: Mode 2 path: store steering v30 to this+0x3580; BitfieldExtract(v5) feeds VehicleSetupDataCopy(v37, v39, v43, v38, v42, v40, extracted) and EffectParameterSetter(v31, 0.5, v32). [field:this:0x00013696, callee:0x004B2A30, callee:0x004F1650, callee:0x004F17A0]
    // LOOP: Mode 2 path: copy v41[0..3] into this+0x35BC strided by 62 floats across the 4-wheel block. [field:this:0x00013756]
    // GUARD: Mode 2 path: this+0x344C = (a2+56 < 0); if fabs(a3 - this+0x48B4) > 15.0 then this+0x48B4 = a3 and loop 14 subsystem bits: BitTest(v5, i) -> SubsystemStateMachine(i, bit). [field:this:0x00013388, field:this:0x00018612, callee:0x004B2AD0, callee:0x004E17C0]
    // STATE_TRANSITION: Mode 3 path: MatrixVectorSetup(v43, v40); VibrationStateMachine(j, v41[j]) for j 0..3; BitTest(v5, k) -> SubsystemStateMachine(k, bit) for k 0..13. [callee:0x004F17D0, callee:0x004E2230, callee:0x004B2AD0, callee:0x004E17C0]
    // ASSIGNMENT: v26 = (a2+56 & 0x8000000) != 0; if this+0x105D != v26 then set this+0x105D = v26 and call AudioSoundEffectController(this+0x1054) to refresh the audio state. [field:this:0x00004189, field:this:0x00004180, callee:0x004E0ED0]
    // ASSIGNMENT: v27 = (a2+56 & 0x4000000) != 0; store v27 to this+0x1065 and write this+0x3584 = v27 ? 1.0f : 0.0f. [field:this:0x00004197, field:this:0x00013700]
    // ASSIGNMENT: this+0x1067 = (a2+56 & 0x2000000) != 0. [field:this:0x00004199]
    // CALCULATION: Trailing extraction helpers (addresses absent from packet, evidenced only by raw source): ShortComputation_2b00(v5) feeds PropertySetter; BitfieldExtract_2b80(v5) stored as word to this+0x48B0; this+0x4024 = a2+59 & 1; this+0x4028 = BitfieldExtractionWithScale(v5). [field:this:0x00018608, field:this:0x00016420, field:this:0x00016424, source:raw]

    // Conservative worker pseudocode:
    //   dt = a3 - this[0x48B8]; this[0x48B8] = a3;
    //   ArithmeticComparison_2420(a2+8, &q, &euler); EulerToRotationMatrix(euler, &rot); F_3x3MatrixTransform(q, euler, rot);
    //   steer = clamp(BitfieldToFloatConversion(a2+8), -1.0, 1.0); this[0x1040] = steer;
    //   for i in 0..3: sub_4B28F0(a2+8, i, &val, &wheel[i]); SuspensionParamUpdate(i, val, dt*wheel[i] + this[0x8C0 + i*74], i<2 ? this[0x1044]*steer : 0.0);
    //   unpack short vectors; store position/velocity/orientation into this+0x1C..0xA4;
    //   mode = this[0x32C8];
    //   if mode == 2: this[0x3580] = steer; VehicleSetupDataCopy(...); EffectParameterSetter(v31, 0.5, v32); copy wheel values; if fabs(dt_large) > 15.0 run 14 SubsystemStateMachine steps;
    //   elif mode == 3: MatrixVectorSetup(rot, v40); VibrationStateMachine x4; SubsystemStateMachine x14;
    //   brake/driver-visible/reverse flags decoded from a2+56 bits; audio controller refreshed on driver-visible change
    // UNRESOLVED: Global floats flt_59E43C, flt_59E670, flt_59E8D8 are read during the frame but their use sites are not visible in the raw source (likely constants folded inside inlined helper callees).
    // UNRESOLVED: Callers TeamColorLoader (0x004F03E0) and sub_4F0430 (0x004F0430) are inbound context only and not modeled as operations.
    // UNRESOLVED: this+0x34 (0x24-byte block) is written by the qmemcpy from v43 but that offset is not enumerated in the packet field list.
    // UNRESOLVED: The trailing helper calls ShortComputation_2b00, PropertySetter, BitfieldExtract_2b80 and BitfieldExtractionWithScale exist in raw source but have no packet addresses; described from source only.
}
