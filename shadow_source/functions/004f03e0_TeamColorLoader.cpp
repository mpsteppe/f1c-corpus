// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F03E0
// Canonical corpus name: TeamColorLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TeamColorLoader_004f03e0.c

void UnknownObject::TeamColorLoader()
{
    // Calls UtilityFunction_3d50(dword_7CD25C, *(_DWORD*)(*this + 18580), v3, a2) to resolve a per-object parameter (object-relative offset *this + 18580 = this+0x4894) into a local buffer v3; if the utility returns nonzero, calls VehiclePhysicsTimeStep(*this, v3, a2). The 108-dword local buffer v3 is the only channel between the two calls.
    // CALL: Call UtilityFunction_3d50(dword_7CD25C, *(_DWORD*)(*this + 18580), v3, a2); the object field read at *this + 18580 corresponds to the packet field base obj at this+0x4894. [callee:0x00463D50, global:0x007CD25C, field:obj:0x00004894, field:this:0x00000000, source:raw]
    // GUARD: If UtilityFunction_3d50 returns nonzero, proceed to the physics step; otherwise return without calling VehiclePhysicsTimeStep. [callee:0x00463D50, source:raw]
    // CALL: Call VehiclePhysicsTimeStep(*this, v3, a2) with the object pointer *this and the resolved buffer v3. [callee:0x004C73F0, field:this:0x00000000, source:raw]

    // Conservative worker pseudocode:
    //   void step(this, a2) {
    //     int v3[108];
    //     if (UtilityFunction_3d50(dword_7CD25C, *(_DWORD*)(*this + 18580), v3, a2))
    //       VehiclePhysicsTimeStep(*this, v3, a2);
    //   }
    // UNRESOLVED: Contents and layout of the 108-dword local buffer v3 are not in the packet; it is the sole data channel between UtilityFunction_3d50 and VehiclePhysicsTimeStep.
    // UNRESOLVED: Meaning of the float argument a2 is unknown.
    // UNRESOLVED: The object field at *this + 18580 (this+0x4894) is read as a pointer-sized value only; its type and purpose are not evidenced.
    // UNRESOLVED: Whether this function really relates to team color is a legacy ABI label (Team_Color_Loader); the raw source does not state it.
}
