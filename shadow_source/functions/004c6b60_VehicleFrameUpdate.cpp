// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C6B60
// Canonical corpus name: sub_4C6B60
// Owner: VehicleObject [DERIVED]
// Raw source: functions/sub_4C6B60_004c6b60.c

void VehicleObject::VehicleFrameUpdate()
{
    // Per-vehicle per-frame update (thiscall on the vehicle struct). Resets the vehicle substate at this+4109, dispatches the render/session guard sub_4D1180 into two 12-byte scratch buffers, then, when the a2 flag is set or the substate check sub_4BC9B0 fails, tracks the AI path position, updates suspension state, issues a conditional buffer call keyed on the sub_4D1180 result, and either clears or advances the vehicle state machine at this+3251; on the advance path it dispatches the game state branch when this vehicle's +0x4894 slot matches the current vehicle's +0x4894 value. Finally initializes camera viewport/frustum and, for session type 7 with race phase 3 or 4, returns a vehicle climb adjust result.
    // CALL: Reset the vehicle substate at this + 4109 via sub_4BB8E0 before the update block. [callee:0x004BB8E0, source:raw]
    // CALL: Dispatch sub_4D1180(this, v9, v8); its char result v4 selects the state path below. [callee:0x004D1180, source:raw]
    // GUARD: If a2 is non-zero OR sub_4BC9B0(v3, 0, 0) returns 0 (substate not active/ready), run the path/suspension/state block. [callee:0x004BC9B0, source:raw]
    // CALL: Track the AI vehicle path position from the v9/v8 buffers via AIVehiclePathPositionTracking. [callee:0x004EF7C0, source:raw]
    // CALL: Update suspension physics state for the this + 3 substruct via SuspensionStateUpdate. [callee:0x004E9600, source:raw]
    // ASSIGNMENT: Set v5 = (v4 == 0) and call ConditionalBufferCall(v5), a conditional buffer flush keyed on whether the sub_4D1180 result was zero. [callee:0x004F1C00, source:raw]
    // GUARD: If v4 (sub_4D1180 result) is non-zero clear the object state, otherwise advance the state machine on the this + 3251 substruct. [source:raw]
    // CALL: When v4 is non-zero, clear the vehicle object state via ObjectStateClear(this + 3251). [callee:0x004A5E80, source:raw]
    // CALL: When v4 is zero, advance the vehicle state machine via StatePhaseSetter(this + 3251). [callee:0x004A5E60, source:raw]
    // GUARD: If this[4645] (field +0x4894) equals the value read at *(dword_7C54F0[dword_7C54E4] + 18580) (the current vehicle's +0x4894 slot), dispatch the game state branch. [field:this:0x00004894, global:0x007C54E4, global:0x007C54F0, source:raw]
    // CALL: Branch the game state to the next phase via GameStateBranchDispatch(&dword_5EA510) when the +0x4894 compare matches. [callee:0x0040D100, global:0x005EA510, source:raw]
    // CALL: Initialize the camera viewport/frustum for this vehicle via CameraViewportFrustumInitialization(this); the result is the default return value. [callee:0x00424B20, source:raw]
    // GUARD: If session type dword_7C56A4 == 7 and race phase dword_7C56A8 is 3 or 4, return VehicleClimbAdjust(1) instead of the camera result. [global:0x007C56A4, global:0x007C56A8, source:raw]
    // CALL: Adjust the vehicle climb/height via VehicleClimbAdjust(1) on the race-phase 3/4 branch. [callee:0x004EFA40, source:raw]
    // RETURN: Return the CameraViewportFrustumInitialization result, or the VehicleClimbAdjust result when the dword_7C56A8 == 3/4 branch fired. [source:raw]
    // CALL: Called by sub_42D140 (0x0042D140) and SceneRenderUpdate (0x004C6D90) as part of the per-frame vehicle update path. [caller:0x0042D140, caller:0x004C6D90, source:raw]

    // Conservative worker pseudocode:
    //   v3 = this + 4109;
    //   sub_4BB8E0(v3);
    //   v4 = sub_4D1180(this, v9, v8);
    //   if (a2 || !sub_4BC9B0(v3, 0, 0)) {
    //       AIVehiclePathPositionTracking(v9, v8);
    //       SuspensionStateUpdate(this + 3);
    //       ConditionalBufferCall(v4 == 0);
    //       if (v4) {
    //           ObjectStateClear(this + 3251);
    //       } else {
    //           StatePhaseSetter(this + 3251);
    //           if (this[4645] == *(_DWORD*)(dword_7C54F0[dword_7C54E4] + 18580))
    //               GameStateBranchDispatch(&dword_5EA510);
    //       }
    //   }
    //   result = CameraViewportFrustumInitialization(this);
    //   if (dword_7C56A4 == 7 && (dword_7C56A8 == 3 || dword_7C56A8 == 4))
    //       return VehicleClimbAdjust(1);
    //   return result;
    // UNRESOLVED: dword_8ACEE0 (global:0x008ACEE0) is listed as read but does not appear in the raw pseudocode; it is presumably read inside a callee (the corpus fill identifies it as the force-feedback base).
    // UNRESOLVED: Semantics of sub_4BB8E0, sub_4BC9B0, sub_4D1180, StatePhaseSetter, ObjectStateClear and GameStateBranchDispatch come from the corpus fill; the packet does not define their behavior.
    // UNRESOLVED: The this + 3 and this + 3251 int-index substructs are used by the raw source but have no field evidence refs; their contents are not described by the packet.
    // UNRESOLVED: Exact meaning of the a2 parameter and of the constant arguments (0, 0) to sub_4BC9B0 is not confirmed by the packet.
    // UNRESOLVED: The dword_7C56A4 == 7 session-type value and the dword_7C56A8 3/4 race-phase values are not defined by the packet.
    // UNRESOLVED: Layout of the 12-byte v9/v8 scratch buffers and how sub_4D1180 / AIVehiclePathPositionTracking consume them are unknown.
}
