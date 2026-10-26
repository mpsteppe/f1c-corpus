// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042C690
// Canonical corpus name: MainGameTickUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MainGameTickUpdate_0042c690.c

void UnknownObject::MainGameTickUpdate()
{
    // Per-frame main game tick: converts session time (dbl_8AFEA0 * 400) into a tick counter, then runs a fixed tick loop dispatching per-tick and per-multiple-of-10 subsystems — AI updates, vehicle physics dispatch, particle effects, fuel/wear, tire forces, yaw recovery, debug logging — interleaved on tick parity and modulo windows. Wraps the tick counter every 400 ticks, runs the driver input controller when its gate is set, and finishes by returning the per-vehicle camera update iterator result.
    // GUARD: Entry gate: when dword_8AB6E4 == 2 the entire tick body is skipped and control falls to the camera-iterator return. [global:0x008AB6E4, source:raw]
    // CALL: Run the pre-tick helper sub_42C440(). [callee:0x0042C440, source:raw]
    // CALCULATION: Compute the target tick count: v1 = dbl_8AFEA0 * 400.0; feed it to sub_5895A2 and convert with CRTFtol; clamp the counter dword_7C5694 so the pending delta never exceeds 201 ticks (v3 = v2 - 201, dword_7C5694 = v2 - 201). [global:0x008AFEA0, callee:0x005895A2, callee:0x00587BDC, global:0x007C5694, source:raw]
    // LOOP: Tick loop: v15 starts at dword_7C5694 * 0.0025 and advances by 0.0025 each iteration; the loop runs while dword_7C5694 stays below the target v2. [global:0x007C5694, source:raw]
    // CALL: Odd-tick physics dispatch: when dword_7C5698 % 10 is non-zero, and the player vehicle (dword_7C54E8) has no pause flag at +13000, and either dword_7CE958 is clear or the tick parity is even, and the +18620 flag has bit 8 set, call VehiclePhysicsModeDispatcher(v15). [global:0x007C5698, global:0x007C54E8, global:0x007CE958, callee:0x004E4930, source:raw]
    // CALL: 10-tick AI pass: for each of dword_5C329C vehicles in the dword_7C54F0 array call AIMainUpdate(veh); then LoopWithConditionalSkipFunction(dword_5EA560, v15). [global:0x005C329C, global:0x007C54F0, callee:0x00424E70, callee:0x00410980, global:0x005EA560, source:raw]
    // ASSIGNMENT: Zero the twelve scoring/stewarding accumulators dword_7C932C through dword_7C9354 and seed the loop counter dword_7C9358. [global:0x007C932C, global:0x007C9330, global:0x007C9334, global:0x007C9338, global:0x007C933C, global:0x007C9340, global:0x007C9344, global:0x007C9348, global:0x007C934C, global:0x007C9350, global:0x007C9354, global:0x007C9358, source:raw]
    // LOOP: Particle/effect pass over dword_5C329C vehicles in dword_7C54F0: call ParticleEffectUpdateDispatch(veh+12) for each, then sub_4EE2D0(veh+12) for each. [global:0x005C329C, global:0x007C54F0, callee:0x004EB430, callee:0x004EE2D0, source:raw]
    // GUARD: Fuel/wear window: every 400 ticks (dword_7C5698 % 400 == 0), for vehicles whose +13000 flag equals 1, call FuelConsumptionAndWear(1.0). [global:0x007C5698, global:0x005C329C, global:0x007C54F0, callee:0x004ED960, source:raw]
    // GUARD: Tire/lateral window: every 50 ticks (dword_7C5698 % 50 == 0) run AILateralForceComputation(this), VehicleYawRotationRecoveryController(0.125) for every vehicle, and WheelTireForceUpdate(0.125) for vehicles with the +13000 flag set. [global:0x007C5698, callee:0x0042CAA0, callee:0x004F1C40, callee:0x004ED810, global:0x005C329C, global:0x007C54F0, source:raw]
    // CALL: When the player vehicle's +13000 flag is clear, call sub_4BCCC0(0.025). [global:0x007C54E8, callee:0x004BCCC0, source:raw]
    // GUARD: Periodic debug log: every dword_8AD23C ticks call DebugLogInit(&dword_8AD238) when dword_8AD238 is set; on the very first tick (dword_7C5698 == 0) also run sub_4D59B0(&dword_8AD238). [global:0x007C5698, global:0x008AD23C, global:0x008AD238, callee:0x004D5960, callee:0x004D59B0, source:raw]
    // STATE_TRANSITION: Tick wrap: increment dword_7C5698, reset it to 0 when it reaches 400, increment dword_7C5694, and continue the loop while dword_7C5694 < target v2. [global:0x007C5698, global:0x007C5694, source:raw]
    // GUARD: Post-loop input: when dword_7CBF24 is set, call DriverInputController(&unk_7CBB10). [global:0x007CBF24, global:0x007CBB10, callee:0x00451720, source:raw]
    // RETURN: Return PerVehicleCameraUpdateIterator(dword_5EA560, dbl_8AFEA0). [callee:0x004109D0, global:0x005EA560, global:0x008AFEA0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_8AB6E4 == 2) return PerVehicleCameraUpdateIterator(dword_5EA560, dbl_8AFEA0);
    //   sub_42C440();
    //   target = CRTFtol(dbl_8AFEA0 * 400.0);
    //   if (target - dword_7C5694 > 201) dword_7C5694 = target - 201;
    //   t = dword_7C5694 * 0.0025;
    //   while (dword_7C5694 < target) {
    //     t += 0.0025;
    //     if (dword_7C5698 % 10 != 0) {
    //       if (!flag(player_veh, +13000) && (!dword_7CE958 || tick_is_even) && (flag(player_veh, +18620) & 8))
    //         VehiclePhysicsModeDispatcher(t);
    //     } else {
    //       for (veh in vehicles) AIMainUpdate(veh);
    //       LoopWithConditionalSkipFunction(dword_5EA560, t);
    //       zero dword_7C932C..dword_7C9354;
    //       for (veh in vehicles) ParticleEffectUpdateDispatch(veh+12);
    //       for (veh in vehicles) sub_4EE2D0(veh+12);
    //       if (dword_7C5698 % 400 == 0) for (veh where flag(+13000)==1) FuelConsumptionAndWear(1.0);
    //       if (dword_7C5698 % 50 == 0) {
    //         AILateralForceComputation(this);
    //         for (veh in vehicles) VehicleYawRotationRecoveryController(0.125);
    //         for (veh where flag(+13000)==1) WheelTireForceUpdate(0.125);
    //       }
    //       if (!flag(player_veh, +13000)) sub_4BCCC0(0.025);
    //       if (dword_7C5698 % dword_8AD23C == 0) {
    //         if (dword_8AD238) DebugLogInit(&dword_8AD238);
    //         if (dword_7C5698 == 0 && dword_8AD238) sub_4D59B0(&dword_8AD238);
    //       }
    //     }
    //     dword_7C5698++; if (dword_7C5698 >= 400) dword_7C5698 = 0;
    //     dword_7C5694++;
    //   }
    //   if (dword_7CBF24) DriverInputController(&unk_7CBB10);
    //   return PerVehicleCameraUpdateIterator(dword_5EA560, dbl_8AFEA0);
    // UNRESOLVED: The offset literals +13000 and +18620 applied to the player vehicle pointer dword_7C54E8 are direct source literals with no enumerated field evidence refs; their semantics (pause flag, race-state flag) are DERIVED from existing analysis only.
    // UNRESOLVED: The read-only doubles dbl_59E9B0 and dbl_59E9D8 are listed as read by this function but are folded into FPU literals by Hex-Rays and never appear by name in the .c.
    // UNRESOLVED: The object passed to AILateralForceComputation and to the camera iterator (dword_5EA560, and `this` for the lateral computation) is an unproven global instance identity.
}
