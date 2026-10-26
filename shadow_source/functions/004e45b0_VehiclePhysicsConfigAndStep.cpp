// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E45B0
// Canonical corpus name: LargeConfigFunctionWithPhysicsConstants
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeConfigFunctionWithPhysicsConstants_004e45b0.c

void UnknownObject::VehiclePhysicsConfigAndStep()
{
    // Per-frame vehicle physics configuration and one integration step. Calls sub_4E4790 first, then runs on a mode flag at this+0x32BC: value 0 triggers one-time TireModelInit into the global dbl_7C7428 buffer, values 1..3 run the step, any other value returns early. Parses the vehicle HDV file twice via TheSvmHdvVehicleFileParser, clamps an integration sub-step count at this+0x3498 to [1,64], derives four step-size fields from it, runs SuspensionAndWheelPhysics and TireBrushModelForceSolver, then frees the temporary heap allocations and returns the leftover allocation pointer.
    // CALL: Call sub_4E4790(this): pre-step wheel-state reset on the same object. [callee:0x004E4790, field:this:0x00000000, source:raw]
    // GUARD: Mode flag guard on this+0x32BC: if the flag is zero, run one-time TireModelInit((int)&dbl_7C7428, *(_DWORD *)this) using the global double buffer at 0x007C7428; otherwise if the flag is out of range [1,3] (<= 0 or > 3) return immediately. [field:this:0x000032BC, field:this:0x00000000, callee:0x0043E050, global:0x007C7428, source:raw]
    // CALL: Initialize the session struct buffer v16 via SessionStructInit and the tire model data buffer v8 via TireModelDataInit. [callee:0x0042E320, callee:0x004F34E0, source:raw]
    // CALCULATION: Resolve the vehicle HDV file path: pointer at 1060 * *(_DWORD *)(*(_DWORD *)this + 18584) + dword_8AC394 + 8, falling back to byte_5EA438 when null. [field:this:0x00000000, global:0x008AC394, global:0x005EA438, source:raw]
    // CALL: Parse the vehicle file twice: TheSvmHdvVehicleFileParser(v3, v16, 0) with the resolved path, then TheSvmHdvVehicleFileParser(*(_DWORD *)this + 18324, v16, 1) with the inline setup offset. [callee:0x004F4270, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the requested integration sub-step count into this+0x3498, then clamp it: force 1 when below 1, force 64 when above 64. [field:this:0x00003498, source:raw]
    // CALCULATION: Compute this+0x349C = v15 * v15 (squared step-size input from the stack variable v15). [field:this:0x0000349C, source:raw]
    // CALCULATION: Compute step-size fields from the clamped count v6: this+0x34A0 = 1.0 / (double)(40 * v6) and this+0x34A8 = the same value; this+0x34A4 = 1.0 / (double)(8 * (5 * v6 + 5)). [field:this:0x000034A0, field:this:0x000034A4, field:this:0x000034A8, source:raw]
    // ASSIGNMENT: Write this+0x34AC = dbl_8AFEA0 (session/race-time value from the global double). [field:this:0x000034AC, global:0x008AFEA0, source:raw]
    // CALL: Run the physics step: SuspensionAndWheelPhysics(v16, v8) followed by TireBrushModelForceSolver(0). [callee:0x004E5F60, callee:0x004E8010, source:raw]
    // LOOP: Free the temporary heap allocations returned by the initializers: FreeWrapper_7bcf each of v13, v12, v11, v10, v9 and v8[0] when non-null. [callee:0x00587BCF, source:raw]
    // CALL: Call ScoreSlotDeallocator(v18) on the 235-dword stack score-slot buffer. [callee:0x0042DDD0, source:raw]
    // CALL: Compiler-inserted __alloca_probe for the large stack frame of locals. [callee:0x005881C0, source:raw]
    // RETURN: Return the leftover allocation pointer v17; when non-null, free it via FreeWrapper_7bcf and return its result. [callee:0x00587BCF, function:0x004E45B0, source:raw]

    // Conservative worker pseudocode:
    //   int VehiclePhysicsConfigAndStep(vehicle) {
    //     sub_4E4790(vehicle);
    //     int mode = vehicle.field_32BC;
    //     if (mode == 0) TireModelInit(&dbl_7C7428, *(int*)vehicle);
    //     else if (mode <= 0 || mode > 3) return mode;
    //     SessionStructInit(sessionBuf); TireModelDataInit(tireData);
    //     char* hdv = *(char**)(1060 * *(int*)(*(int*)vehicle + 18584) + dword_8AC394 + 8);
    //     if (!hdv) hdv = byte_5EA438;
    //     TheSvmHdvVehicleFileParser(hdv, sessionBuf, 0);
    //     TheSvmHdvVehicleFileParser(*(int*)vehicle + 18324, sessionBuf, 1);
    //     vehicle.field_3498 = clamp(requested, 1, 64);
    //     vehicle.field_349C = v15 * v15;
    //     vehicle.field_34A0 = vehicle.field_34A8 = 1.0 / (40 * count);
    //     vehicle.field_34A4 = 1.0 / (8 * (5 * count + 5));
    //     vehicle.field_34AC = dbl_8AFEA0;
    //     SuspensionAndWheelPhysics(sessionBuf, tireData);
    //     TireBrushModelForceSolver(0);
    //     FreeEach(v13, v12, v11, v10, v9, v8[0]);
    //     ScoreSlotDeallocator(scoreBuf);
    //     if (v17) return FreeWrapper_7bcf(v17);
    //     return v17;
    //   }
    // UNRESOLVED: The value v15 feeding this+0x349C is read from the stack frame but its producer inside this function is not visible; it is presumed written by one of the initialization helpers (sub_4E4790 or the parser calls).
    // UNRESOLVED: The sub_4E4790 callee's own identity is only known by address; its behavior is not in this packet.
    // UNRESOLVED: The exact semantics of the five global constants (dbl_7C7428, dbl_8AFEA0, dword_8AC394 entry stride 1060, and the fallback byte_5EA438 path) are not established.
    // UNRESOLVED: field:obj:0x00004898 is listed in the packet field table but no obj-based access appears in the raw source; the base may belong to a caller-side object view.
    // UNRESOLVED: global:0x0059E43C is listed in the packet global table but does not appear in the raw source text.
}
