// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C73F0
// Canonical corpus name: VehiclePhysicsTimeStep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehiclePhysicsTimeStep_004c73f0.c

void UnknownObject::VehiclePhysicsTimeStep()
{
    // Per-frame vehicle physics timestep. Computes frame delta time, decodes the packed input packet (orientation, steering, velocity, subsystem bits) via a set of bitfield/short-vector helpers, transforms state into the vehicle struct, runs per-wheel suspension updates, and dispatches mode-specific state machines (mode 2 = full vehicle setup copy + subsystem loop; mode 3 = vibration + subsystem loop). Ends by deriving braking/audio/bit flags from the packet and updating effect fields.
    // CALCULATION: Compute frame delta time v36 = a3 - lastTime (this+0x48B8), then store the new timestamp a3 into this+0x48B8. [field:this:0x000048B8, source:raw]
    // CALL: Decode the packed orientation/input packet at a2+8 into component vectors v37 and v39 via ArithmeticComparison_2420. [callee:0x004B2420, source:raw]
    // CALL: Build a 3x3 rotation matrix v43 from Euler angles v39 via EulerToRotationMatrix. [callee:0x00566E40, source:raw]
    // CALL: Transform orientation components v37 by the rotation matrix v43 via F_3x3MatrixTransform. [callee:0x004E23D0, source:raw]
    // CALL: Extract the steering float from the packed bitfield at a2+8 via BitfieldToFloatConversion into v30. [callee:0x004B2A80, source:raw]
    // GUARD: Clamp steering v30 to the range [-1.0, 1.0] and store the clamped value into this+0x1040. [field:this:0x00001040, source:raw]
    // CALCULATION: Compute steering factor v35 = this+0x1044 * clamped steering v30. [field:this:0x00001044, source:raw]
    // LOOP: For each wheel 0..3: unpack per-wheel data via sub_4B28F0 into v32 and v41[i]; accumulate v34 = v36 * wheelComponent + wheel accumulator at this+0x8C0 (stride 74 dwords); call SuspensionParamUpdate with steering factor v35 for wheels 0/1 and 0.0 for wheels 2/3. [callee:0x004B28F0, callee:0x004E24A0, field:this:0x000008C0, field:this:0x00001044, source:raw]
    // CALL: Unpack velocity from the packed short vector at a2+8 into v38 via ShortVectorToFloatWithScale. [callee:0x004B2580, source:raw]
    // CALL: Truncate packed float data at a2+8 into v42 via FloatTruncation. [callee:0x004B26D0, source:raw]
    // CALL: Unpack short-vector data at a2+8 into raw bytes v40 via ShortToFloatVectorUnpack. [callee:0x004B2800, source:raw]
    // CALL: Extract scaled bitfield value v31 from a2+8 via BitfieldExtractScale. [callee:0x004B2980, source:raw]
    // CALL: Compute speed scalar v32 from a2+8 via ShortComputation_29f0. [callee:0x004B29F0, source:raw]
    // ASSIGNMENT: Write recovered orientation state: this+0xA4 = speed scalar v32; this+0x1C/0x20/0x24 = v37[0..2]. [field:this:0x000000A4, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, source:raw]
    // ASSIGNMENT: Copy the 36-byte rotation matrix v43 into the vehicle's orientation storage at this+52 (qmemcpy 0x24 bytes). [source:raw]
    // ASSIGNMENT: Write velocity vector v38 into this+0x58/0x5C/0x60. [field:this:0x00000058, field:this:0x0000005C, field:this:0x00000060, source:raw]
    // ASSIGNMENT: Write steering scale v31 into this+0xA0. [field:this:0x000000A0, source:raw]
    // ASSIGNMENT: Set byte this+0x1069 = (a2+52 bit 0x80) != 0. [field:this:0x00001069, source:raw]
    // GUARD: Branch on vehicle mode v15 = this+0x32C8: if 2, run the full setup-data path; else if 3, run the vibration path. [field:this:0x000032C8, source:raw]
    // ASSIGNMENT: Mode 2: store clamped steering v30 into this+0x3580. [field:this:0x00003580, source:raw]
    // CALL: Mode 2: BitfieldExtract(a2+8) into v16, then VehicleSetupDataCopy(v37, v39, v43, v38, v42, v40, v16) and EffectParameterSetter(v31, 0.5, v32) to copy setup data into the vehicle. [callee:0x004B2A30, callee:0x004F1650, callee:0x004F17A0, source:raw]
    // LOOP: Mode 2: store per-wheel force values v41[i] into this+0x35BC + i*62 dwords for all 4 wheels. [field:this:0x000035BC, source:raw]
    // CALCULATION: Mode 2: compute v20 = a3 - lastSetupTime (this+0x48B4) and set byte this+0x344C = (a2+56 < 0). [field:this:0x000048B4, field:this:0x0000344C, source:raw]
    // GUARD: Mode 2: if fabs(v20) > 15.0, refresh this+0x48B4 = a3 and drive all 14 subsystem state machines: BitTest(a2+8, i) then SubsystemStateMachine(i, bit). [field:this:0x000048B4, callee:0x004B2AD0, callee:0x004E17C0, source:raw]
    // GUARD: Mode 3: run MatrixVectorSetup(v43, v40), drive all 4 VibrationStateMachine(j, v41[j]), then all 14 subsystem state machines via BitTest(a2+8, k) + SubsystemStateMachine(k, bit). [field:this:0x000032C8, callee:0x004F17D0, callee:0x004E2230, callee:0x004B2AD0, callee:0x004E17C0, source:raw]
    // CALCULATION: Compute braking flag v26 = (a2+56 bit 0x8000000) != 0. [source:raw]
    // GUARD: If stored byte this+0x105D differs from v26, update this+0x105D and call AudioSoundEffectController(this+0x1054) to refresh the audio/render state on change. [field:this:0x0000105D, field:this:0x00001054, callee:0x004E0ED0, source:raw]
    // ASSIGNMENT: Compute v27 = (a2+56 bit 0x4000000) != 0; write this+0x1065 = v27 and set this+0x3584 to 1.0 when v27 is set, else 0. [field:this:0x00001065, field:this:0x00003584, source:raw]
    // ASSIGNMENT: Set byte this+0x1067 = (a2+56 bit 0x2000000) != 0. [field:this:0x00001067, source:raw]
    // CALL: Compute v28 via ShortComputation_2b00(a2+8) and pass it to PropertySetter (both helpers named only in the raw source; no packet callee entries). [source:raw]
    // ASSIGNMENT: Write word this+0x48B0 = BitfieldExtract_2b80(a2+8). [field:this:0x000048B0, source:raw]
    // ASSIGNMENT: Set byte this+0x4024 = (a2+59 bit 1). [field:this:0x00004024, source:raw]
    // ASSIGNMENT: Write float this+0x4028 = BitfieldExtractionWithScale(a2+8). [field:this:0x00004028, source:raw]

    // Conservative worker pseudocode:
    //   void VehiclePhysicsTimeStep(vehicle, packet, time) {
    //     float dt = time - vehicle.lastTime; vehicle.lastTime = time;
    //     ArithmeticComparison_2420(packet+8, &ori, &euler);
    //     EulerToRotationMatrix(euler, &rot); F_3x3MatrixTransform(&ori, &euler, &rot);
    //     float steer = clamp(BitfieldToFloatConversion(packet+8), -1.0, 1.0);
    //     vehicle.steering = steer;
    //     for (w in 0..3) { sub_4B28F0(packet+8, w, &disp, &wheelForce[w]);
    //                      SuspensionParamUpdate(w, disp, dt*wheelForce[w] + vehicle.wheelAccum[w], w < 2 ? steerFactor : 0.0); }
    //     ShortVectorToFloatWithScale(packet+8, &vel); FloatTruncation(packet+8, &trunc);
    //     ShortToFloatVectorUnpack(packet+8, &raw);
    //     float scale = BitfieldExtractScale(packet+8);
    //     float speed = ShortComputation_29f0(packet+8);
    //     vehicle.speed = speed; vehicle.ori[0..2] = ori; copy rot -> vehicle+52;
    //     vehicle.vel[0..2] = vel; vehicle.steerScale = scale;
    //     vehicle.someFlag = (packet[52] & 0x80) != 0;
    //     if (vehicle.mode == 2) {
    //       vehicle.steer = steer;
    //       VehicleSetupDataCopy(&ori, &euler, &rot, &vel, &trunc, &raw, BitfieldExtract(packet+8));
    //       EffectParameterSetter(scale, 0.5, speed);
    //       for (w in 0..3) vehicle.wheelStore[w] = wheelForce[w];
    //       vehicle.someSign = (packet[56] < 0);
    //       if (fabs(time - vehicle.lastSetupTime) > 15.0) {
    //         vehicle.lastSetupTime = time;
    //         for (i in 0..13) SubsystemStateMachine(i, BitTest(packet+8, i)); }
    //     } else if (vehicle.mode == 3) {
    //       MatrixVectorSetup(&rot, &raw);
    //       for (j in 0..3) VibrationStateMachine(j, wheelForce[j]);
    //       for (k in 0..13) SubsystemStateMachine(k, BitTest(packet+8, k)); }
    //     bool brake = (packet[56] & 0x08000000) != 0;
    //     if (vehicle.brakeFlag != brake) { vehicle.brakeFlag = brake; AudioSoundEffectController(vehicle.audioHandle); }
    //     bool v27 = (packet[56] & 0x04000000) != 0;
    //     vehicle.bitFlag = v27; vehicle.someEffect = v27 ? 1.0 : 0.0;
    //     vehicle.otherBit = (packet[56] & 0x02000000) != 0;
    //     PropertySetter(ShortComputation_2b00(packet+8));
    //     vehicle.someWord = BitfieldExtract_2b80(packet+8);
    //     vehicle.tireFlag = packet[59] & 1;
    //     vehicle.tireValue = BitfieldExtractionWithScale(packet+8);
    //   }
    // UNRESOLVED: Raw source calls ShortComputation_2b00, PropertySetter, BitfieldExtract_2b80 and BitfieldExtractionWithScale, but the packet lists no callee entries (and therefore no addresses) for them; they are recorded as named calls with source:raw evidence only.
    // UNRESOLVED: Global reads flt_59E43C / flt_59E670 / flt_59E8D8 are reported by the packet but no use is visible in the recovered raw source; they are likely consumed by inlined helper code not surfaced by the decompiler.
}
