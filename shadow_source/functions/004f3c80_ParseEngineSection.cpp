// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F3C80
// Canonical corpus name: EngineSectionParser
// Owner: Engine_Section_Parser [DERIVED]
// Raw source: functions/EngineSectionParser_004f3c80.c

void Engine_Section_Parser::ParseEngineSection()
{
    // Parses the [ENGINE] section of a vehicle engine configuration stream: opens the engine file in binary-read mode, iterates its tokenized lines, and stores fuel, inertia, idle/launch/rev-limit, RPM-torque curve, lifetime and thermal parameters into the vehicle engine setup struct (this). RPM values are converted to rad/s (scale 0.1047197551196598) and a few temperatures offset to Kelvin (+273.16). Validates idle/launch RPM ordering, RPM-torque curve ordering and point count, logging diagnostics in non-server sessions. Ends with stream cleanup and a count of parsed RPM-torque points.
    // GUARD: Initialize local state: zero-init v17 via ZeroInitSmallStruct, clear the 384-byte token buffer, zero counters and set a running flag. Open the engine stream with AudioStreamOpen(a2, 0); if it fails, free v17 via SubCallWithConditionalFieldFree and return -1. [callee:0x005668B0, callee:0x00566B20, callee:0x005668D0, source:raw]
    // LOOP: Outer parse loop gated by ConditionalDispatchBasedOnFlag on the 384-byte buffer: decode each line's token type with sub_5651B0 (0=data line, 1=end-of-section -> break); data lines populate engine fields and then call EngineMapSetupFieldDefinitions; continue while ConditionalDispatchBasedOnFlag returns true. [callee:0x00566CC0, callee:0x005651B0, source:raw]
    // CALL: Parse fuel and inertia scalars via sub_565AA0 into this-relative slots: FuelConsumption -> this+1652, FuelEstimate -> this+1660, EngineInertia -> this+1668. [global:0x005D572C, global:0x005D571C, global:0x005D570C, callee:0x00565AA0, source:raw]
    // CALL: Parse IdleThrottle into this+1692 (field 0x69C) and clamp it to [0.0, 1.0]: if the value is below 0.0 write 0 to both this+1696 dwords; if above 1.0 write 1072693248 to this+1696 (field 0x6A0) and 0 to this+1692. [global:0x005D56FC, callee:0x00565AA0, field:this:0x0000069C, field:this:0x000006A0, source:raw]
    // CALL: Parse IdleRPMLogic pair into this+1676 (field 0x68C) and this+1684 (field 0x694); multiply both by 0.1047197551196598 (RPM to rad/s). If the max is not above the min and session type is not 5 (dword_7C569C) and StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 599) holds, emit the BadEngineIdleR message via DebugLogWrite. [global:0x005D56EC, global:0x007C569C, global:0x008AD25C, global:0x005D548C, global:0x005D56D4, callee:0x00565AA0, callee:0x004D7A50, callee:0x004D7AA0, field:this:0x0000068C, field:this:0x00000694, source:raw]
    // CALL: Parse LaunchEfficiency into this+1700, then LaunchRPMLogic pair into this+1708 (field 0x6AC) and this+1716 (field 0x6B4), scaling both by 0.1047197551196598. If max is not above min and session is not 5 (dword_7C569C) and StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, 611) holds, emit the BadEngineLaunch message via DebugLogWrite. [global:0x005D56C0, global:0x005D56B0, global:0x007C569C, global:0x008AD25C, global:0x005D548C, global:0x005D5698, callee:0x00565AA0, callee:0x004D7A50, callee:0x004D7AA0, field:this:0x000006AC, field:this:0x000006B4, source:raw]
    // CALL: Parse RevLimitLogic into this+1724 (field 0x6BC) and scale it by 0.1047197551196598. [global:0x005D5688, callee:0x00565AA0, field:this:0x000006BC, source:raw]
    // CALCULATION: Parse RPMTorque curve points with sub_565AA0 into the array rooted at v16 = this+1736 (field 0x6C8), three doubles per point: RPM at v16[0], throttle torque at this+0x6D0, brake torque at this+0x6D8. Scale the RPM by 0.1047197551196598. Diagnostics gated on session != 5 (dword_7C569C) and StringSplitLoop(dword_8AD25C, 1, aDDevF119992002_7, line): warn at >=127 points, brake-below-throttle (v16[2] < v16[1]), and non-monotonic curve (previous point RPM >= current). Each parse increments v15 and advances v16 by 3 doubles. After the loop, if v15 > 0, write the point count to this+1732 (field 0x6C4). [global:0x005D567C, global:0x007C569C, global:0x008AD25C, global:0x005D548C, callee:0x00565AA0, callee:0x004D7A50, callee:0x004D7AA0, field:this:0x000006C4, field:this:0x000006C8, field:this:0x000006D0, field:this:0x000006D8, source:raw]
    // CALCULATION: Parse lifetime engine RPM pair into this+4880 (field 0x1310) and this+4888 (field 0x1318), scaling both by 0.1047197551196598; parse lifetime oil temperature pair into this+4896 (field 0x1320) and this+4904, offsetting by 273.16. [global:0x005D5600, global:0x005D55F0, callee:0x00565AA0, field:this:0x00001310, field:this:0x00001318, field:this:0x00001320, source:raw]
    // CALL: Parse lifetime statistics scalars via sub_565AA0: LifetimeAvg -> this+4912, LifetimeVar -> this+4920, EngineEmission triple -> this+4928/this+4936/this+4944. [global:0x005D55E4, global:0x005D55D8, global:0x005D55C8, callee:0x00565AA0, source:raw]
    // CALL: Parse starter configuration: OnboardStarter via sub_5655F0 into this+4952; StarterTiming triple via sub_565AA0 into this+4956/this+4964/this+4972. [global:0x005D55B8, global:0x005D55A8, callee:0x005655F0, callee:0x00565AA0, source:raw]
    // CALL: Parse thermal parameters via sub_565AA0: OptimumOilTemp into this+4808 (field 0x12C8) offset by 273.16; CombustionHeat -> this+4816; EngineSpeedHeat -> this+4824; OilMinimumCool -> this+4832; OilWaterHeatTransfer pair -> this+4840/this+4848; WaterMinimumCool -> this+4856; RadiatorCooling pair -> this+4864/this+4872. [global:0x005D5598, global:0x005D5588, global:0x005D5578, global:0x005D5564, global:0x005D554C, global:0x005D5538, global:0x005D5528, callee:0x00565AA0, field:this:0x000012C8, source:raw]
    // CALL: Set up the engine map field definitions with EngineMapSetupFieldDefinitions(v18, a3) after each parsed data line. [callee:0x004F3C10, source:raw]
    // RETURN: On success: close the stream with ConditionalFileHandleCloseWithFlagDispatch, free v17 via SubCallWithConditionalFieldFree, and return 0. Invoked by TheSvmHdvVehicleFileParser for the engine .ini during vehicle config load. [callee:0x00566B90, callee:0x005668D0, caller:0x004F4270, function:0x004F3C80, source:raw]

    // Conservative worker pseudocode:
    //   init(); if (!AudioStreamOpen(a2, 0)) { free(v17); return -1; }
    //   count = 0;
    //   while (ConditionalDispatchBasedOnFlag(buf, 384)) {
    //       if (sub_5651B0(line) == 1) break;
    //       if (sub_5651B0(line) == 0) {
    //           parse_fuel_inertia();
    //           parse_idle_throttle_clamped();
    //           parse_idle_rpm_log(dword_7C569C, dword_8AD25C);
    //           parse_launch_rpm_log(dword_7C569C, dword_8AD25C);
    //           parse_rev_limit();
    //           parse_rpm_torque_curve(&count, dword_7C569C, dword_8AD25C);
    //           parse_lifetime();
    //           parse_starter();
    //           parse_thermal();
    //           EngineMapSetupFieldDefinitions(v18, a3);
    //       }
    //   }
    //   if (count > 0) *(this + 1732) = count;
    //   close(v17); free(v17); return 0;
    // UNRESOLVED: The read-only double globals dbl_59E420, dbl_59E430, dbl_59EA38, dbl_59EAC8 and dbl_5AD258 are not visible as direct references in the decompiled body; they are likely constant operands (e.g. the 0.1047197551196598 rad/s scale, 9.549296585513721, or 273.16) forwarded into the helper routines, but their exact mapping is unconfirmed.
    // UNRESOLVED: The string globals aRpmTorqueCurve, aRpmTorqueBrake and aTooManyRpmTorq are listed as referenced but do not appear directly in the decompiled body; the curve diagnostics use inline literals, so these globals' exact role is unconfirmed.
    // UNRESOLVED: Owner identity is DERIVED from the LEGACY ABI lead Engine_Section_Parser; no confirmed class symbol is present in the packet.
}
