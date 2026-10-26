// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A6DB0
// Canonical corpus name: VehicleControlEnabled
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleControlEnabled_004a6db0.c

void UnknownObject::VehicleControlEnabled()
{
    // Predicate returning whether vehicle controls may be enabled. Control is granted only when the session type is 0 or 7, all eight health/damage indicator fields on the vehicle object are non-zero (or the dword_7CE814 bypass flag is set), the car control mode field at obj+0x4064 is neither 1 nor 3 (value 2 does not disable), and the force-feedback state check succeeds.
    // ASSIGNMENT: Dereference this to obtain the vehicle object pointer v1 = *this. [field:this:0x00000000, source:raw]
    // GUARD: Session-type gate: the global session mode must be exactly 7 or zero for controls to be enabled. [global:0x007C56A4, source:raw]
    // CALCULATION: Test the eight health/damage indicator fields on the object: four dwords at obj+0x834/0x95C/0xA84/0xBAC and four bytes at obj+0x874/0x99C/0xAC4/0xBEC. v2 is set to 1 when any of them is zero, otherwise 0. [field:obj:0x00000834, field:obj:0x00000874, field:obj:0x0000095C, field:obj:0x0000099C, field:obj:0x00000A84, field:obj:0x00000AC4, field:obj:0x00000BAC, field:obj:0x00000BEC, source:raw]
    // GUARD: Health-field gate: the condition (dword_7CE814 || !v2) passes only when the bypass global is set or all eight health fields are non-zero. [global:0x007CE814, source:raw]
    // GUARD: Car control mode gate: the dword at obj+0x4064 must be neither 1 nor 3; value 2 does NOT disable controls. [field:obj:0x00004064, source:raw]
    // CALL: Call sub_4D21D0 on the force-feedback base global; its non-zero byte result is required for controls to be enabled. [callee:0x004D21D0, global:0x008ACEE0, source:raw]
    // RETURN: Return the conjunction of every gate above: session type, health/bypass, control mode, and force-feedback check. [source:raw]

    // Conservative worker pseudocode:
    //   bool VehicleControlEnabled(int *this) {
    //     int obj = *this;
    //     int healthy = (*(obj + 0x834) && *(byte*)(obj + 0x874)
    //                 && *(obj + 0x95C) && *(byte*)(obj + 0x99C)
    //                 && *(obj + 0xA84) && *(byte*)(obj + 0xAC4)
    //                 && *(obj + 0xBAC) && *(byte*)(obj + 0xBEC)) ? 0 : 1;
    //     int mode = *(obj + 0x4064);
    //     return (dword_7C56A4 == 7 || dword_7C56A4 == 0)
    //         && (dword_7CE814 || healthy == 0)
    //         && mode != 1 && mode != 3
    //         && (unsigned char)sub_4D21D0(&dword_8ACEE0) != 0;
    //   }
    // UNRESOLVED: Exact physical meaning of the eight health/damage fields (which pair maps to which wheel or damage region) is not confirmed.
    // UNRESOLVED: dword_7CE814 role is DERIVED as a qualifying/DSQ bypass; whether it genuinely elides the health check needs runtime evidence.
    // UNRESOLVED: Semantics of the control-mode values at obj+0x4064 (1/3 disabled, 2 enabled) are not confirmed independently.
    // UNRESOLVED: The object type reachable through this+0 is unnamed.
}
