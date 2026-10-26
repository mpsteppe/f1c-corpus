// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6D90
// Canonical corpus name: SceneRenderUpdate
// Owner: VehicleObject [DERIVED]
// Raw source: functions/SceneRenderUpdate_004c6d90.c

void VehicleObject::SceneRenderUpdate()
{
    // Per-vehicle scene render update called every frame from the AI command dispatcher and driver-entry processing. Resets respawn state keyed by the a2 low byte, applies large physics-config constants to the this+3 substruct, delegates to the global instance callback with this+3, dispatches scene grid position and render data through the SingleFunctionDispatch_10e0 / ConditionalDelegateDispatch / RenderCallWithGuard chain into the v4/v3 buffers, optionally resets a vehicle substate and tracks AI path position when the a2 flag is set, initializes the AI driver structure, runs the vehicle frame update with flag 1, clears bit 23 of the render flag bitmask at +0x48B4, updates force feedback on the global base, and runs a collision wrapper when the session-time threshold flt_5EA408 is not positive.
    // CALL: Reset the vehicle respawn state, keyed by the low byte of a2 (SLOBYTE(a2)) via VehicleRespawnReset. [callee:0x004E0800, source:raw]
    // CALL: Apply large physics-config constants to the this+3 substruct via LargeConfigFunctionWithPhysicsConstants. [callee:0x004E45B0, source:raw]
    // CALL: Delegate a call on the global instance dword_5EA560 with this+3 as argument via DelegationWrapperToFUN0040ed10. [callee:0x00410B60, global:0x005EA560, source:raw]
    // GUARD: If the low byte of a2 (LOBYTE(a2)) is set, run the guarded substate reset and path-tracking block below. [source:raw]
    // CALL: Reset the vehicle substate at this+4109 via sub_4BB810, only when the a2 low byte flag is set. [callee:0x004BB810, source:raw]
    // CALL: Dispatch read of grid position data into the v4/v3 buffers via SingleFunctionDispatch_10e0(this, v4, v3). [callee:0x004D10E0, source:raw]
    // CALL: Conditionally recalculate grid position data and copy it via ConditionalDelegateDispatch(this, v4, v3). [callee:0x004D1100, source:raw]
    // CALL: Issue the guarded render call reading indexed struct data via RenderCallWithGuard(this, v4, v3). [callee:0x004D1140, source:raw]
    // GUARD: If the low byte of a2 (LOBYTE(a2)) is set, run sub_4D1180 and AIVehiclePathPositionTracking. [source:raw]
    // CALL: Dispatch sub_4D1180(this, v4, v3) when the a2 low byte flag is set. [callee:0x004D1180, source:raw]
    // CALL: Track the AI vehicle path position from the v4/v3 buffers via AIVehiclePathPositionTracking when the a2 low byte flag is set. [callee:0x004EF7C0, source:raw]
    // CALL: Initialize the AI driver structure for this vehicle via AIDriverStructInit(this, a2). [callee:0x00424790, source:raw]
    // CALL: Run the vehicle frame update via sub_4C6B60(this, 1) with constant flag 1. [callee:0x004C6B60, source:raw]
    // ASSIGNMENT: Write this[4653] (+0x48B4) = -8388609 (as unsigned 18446744073701163007), a render flag bitmask value that clears bit 23 each frame. [field:this:0x000048B4, source:raw]
    // CALL: Update force feedback by calling sub_4D1670 on the global base dword_8ACEE0. [callee:0x004D1670, global:0x008ACEE0, source:raw]
    // GUARD: If the global threshold flt_5EA408 is <= 0.0, run the collision wrapper on the this+3 substruct. [global:0x005EA408, source:raw]
    // CALL: Run the collision check with lock on the this+3 substruct via CollisionWrapperWithLock when the flt_5EA408 guard holds. [callee:0x004E4910, source:raw]

    // Conservative worker pseudocode:
    //   VehicleRespawnReset(SLOBYTE(a2));
    //   LargeConfigFunctionWithPhysicsConstants(this + 3);
    //   DelegationWrapperToFUN0040ed10(dword_5EA560, this + 3);
    //   if (LOBYTE(a2)) sub_4BB810(this + 4109);
    //   SingleFunctionDispatch_10e0(this, v4, v3);
    //   ConditionalDelegateDispatch(this, v4, v3);
    //   RenderCallWithGuard(this, v4, v3);
    //   if (LOBYTE(a2)) { sub_4D1180(this, v4, v3); AIVehiclePathPositionTracking(v4, v3); }
    //   AIDriverStructInit(this, a2);
    //   sub_4C6B60(this, 1);
    //   this[4653] = -8388609;
    //   sub_4D1670(&dword_8ACEE0);
    //   if (flt_5EA408 <= 0.0) CollisionWrapperWithLock(this + 3);
    // UNRESOLVED: flt_59E440 (global:0x0059E440) is listed as read but does not appear in the raw pseudocode; it is presumably read inside one of the callees (zero-threshold physics clamp). Semantic name ZeroThreshold is DERIVED from prior corpus analysis.
    // UNRESOLVED: Exact meaning of the a2 flag (used as SLOBYTE in the respawn reset and LOBYTE in the two guards) is not confirmed by the packet.
    // UNRESOLVED: Purposes of sub_4BB810, sub_4C6B60, sub_4D1180, sub_4D1670, LargeConfigFunctionWithPhysicsConstants and CollisionWrapperWithLock are described from the corpus fill; the packet does not define their behavior.
    // UNRESOLVED: flt_5EA408 semantic role (SessionMaxTime) is DERIVED from prior corpus analysis; the packet only shows the <= 0.0 guard.
    // UNRESOLVED: Layout of the 12-byte v4/v3 buffers and how the SingleFunctionDispatch_10e0 / ConditionalDelegateDispatch / RenderCallWithGuard chain consumes them are unknown.
    // UNRESOLVED: The this+3 and this+4109 substructs (byte offsets 12 and 16436) are used by the packet's raw source but have no packet evidence refs of their own; their contents are not described.
}
