// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C77D0
// Canonical corpus name: TireTemperatureSimStep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TireTemperatureSimStep_004c77d0.c

void UnknownObject::TireTemperatureSimStep()
{
    // Per-frame tire temperature simulation on a vehicle. Skips entirely for vehicle types greater than 1. Gated by SessionStateCheckWrapper on the session state object dword_7CD25C. Clamps the temperature field this+0x48B8 to [0.0, 5.0], subtracts the cooling rate dbl_8AFE90, and when the result drops to zero recovers it via ClampedPhysicsScaleWithThreshold using the team field this+0x4894, choosing the larger of -scale and scale+temp. Then dispatches car lighting/render through a 432-byte-strided ring buffer (dword_83EE60 count, dword_8AAE64 write pointer) and runs sub_4EF2E0 on this+3. Called by IterateVehicles (004B3BA0).
    // GUARD: Skips the function entirely when the vehicle type this+0x32C8 is greater than 1 (only types 0 and 1 simulated) [guard:0, field:this:0x000032C8, source:raw]
    // CALL: SessionStateCheckWrapper on dword_7CD25C gates the temperature simulation on active session state; when it returns zero the simulation is skipped [callee:0x00461DB0, global:0x007CD25C, source:raw]
    // CALCULATION: Clamps the tire temperature field this+0x48B8 into [0.0, 5.0] [field:this:0x000048B8, source:raw]
    // CALCULATION: Subtracts the cooling rate dbl_8AFE90 from the temperature and stores the result back to this+0x48B8 [field:this:0x000048B8, global:0x008AFE90, source:raw]
    // CALCULATION: When the cooled temperature is <= 0, computes a clamped physics scale via ClampedPhysicsScaleWithThreshold using the team field this+0x4894 and -1.0, then recovers the temperature to max(-scale, scale + temp) [callee:0x00462FF0, global:0x007CD25C, field:this:0x00004894, field:this:0x000048B8, source:raw]
    // CALL: Ring-buffer dispatch: count dword_83EE60 is capped at 1023; otherwise it increments and the write pointer dword_8AAE64 advances by 432 bytes, then SetupCarLightingAndRender runs on the selected entry [global:0x0083EE60, global:0x008AAE64, callee:0x004C71C0, source:raw]
    // CALL: Follow-up call to sub_4EF2E0 on the sub-object at this+3 after the lighting/render dispatch [source:raw]
    // CALL: Invoked by IterateVehicles (004B3BA0) as part of the per-frame vehicle pass [caller:0x004B3BA0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0x32C8/4] > 1) return;
    //   if (!SessionStateCheckWrapper(dword_7CD25C)) goto render;
    //   t = this[0x48B8/4];
    //   t = (t < 0.0) ? 0.0 : (t > 5.0 ? 5.0 : t);
    //   t = t - dbl_8AFE90;
    //   if (t <= 0.0) {
    //     s = ClampedPhysicsScaleWithThreshold(dword_7CD25C, this[0x4894/4], -1.0);
    //     t = (s + t > -s) ? s + t : -s;
    //   }
    //   this[0x48B8/4] = t;
    //   render:
    //   if (dword_83EE60 >= 1023) {
    //     SetupCarLightingAndRender(this, dword_8AAE64);
    //   } else {
    //     ++dword_83EE60;
    //     SetupCarLightingAndRender(this, dword_8AAE64);
    //     dword_8AAE64 += 432;
    //   }
    //   sub_4EF2E0(this + 3);
    // UNRESOLVED: flt_59E440 is flagged in the packet globals but appears nowhere in the raw decompiled source; the skeleton fill labels it ZeroThreshold
    // UNRESOLVED: flt_59E7EC is flagged in the packet globals but appears nowhere in the raw decompiled source; the skeleton fill labels it ZeroConstant and claims it encodes the 5.0 comparison constant indirectly, unverifiable from this packet
    // UNRESOLVED: The clamp bounds 0.0 and 5.0 and the -1.0 threshold are inline literals; their linkage to the flagged globals is not evidenced here
}
