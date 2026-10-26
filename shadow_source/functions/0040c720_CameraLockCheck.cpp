// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C720
// Canonical corpus name: CameraLockCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraLockCheck_0040c720.c

void UnknownObject::CameraLockCheck()
{
    // Camera-lock gate: by default returns 1 (lock allowed). If the occupant identifier stored at (vehicle array slot CurrentVehicleIndex) + 18580 differs from the one at (vehicle array slot CurrentPlayerIndex) + 18580, the camera is treated as unlocked: either the call is blocked (returns 0) when mode index a2 equals 3 and the gate flag byte_7CFE88 is clear while the byte at PlayerVehiclePtr+13388 is set, or the lock mode field at this+0x14 is set to -1 and 1 is returned.
    // ASSIGNMENT: Initialize result to 1 (camera lock allowed) before any comparison. [source:raw]
    // GUARD: Compare the occupant identifier at (dword_7C54F0[dword_7C54E4] + 18580) with the one at (dword_7C54F0[dword_7C54DC] + 18580); the rest of the body runs only when the two differ (player vehicle and current vehicle are different entities). [global:0x007C54E4, global:0x007C54DC, global:0x007C54F0, source:raw]
    // GUARD: Mode-3 block gate: if byte_7CFE88 is zero and the byte at (dword_7C54E0 + 13388) is non-zero and a2 equals 3, return 0 immediately (camera lock denied). [global:0x007CFE88, global:0x007C54E0, function:0x0040C720, source:raw]
    // RETURN: Return 0 when the mode-3 block gate fires, before writing the lock field. [global:0x007CFE88, global:0x007C54E0, source:raw]
    // ASSIGNMENT: When the occupant identifiers differ and the block gate does not fire, set the camera lock mode field at this+0x14 (this[5]) to -1. [field:this:0x00000014, source:raw]
    // RETURN: Return the default result (1, lock allowed) when the occupant identifiers match or the lock field was reset. [function:0x0040C720, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   char CameraLockCheck(this, int mode) {
    //     result = 1;
    //     if (veh[CurrentVehicleIndex].occupant != veh[CurrentPlayerIndex].occupant) {
    //       if (!byte_7CFE88 && *(byte*)(PlayerVehiclePtr + 13388) && mode == 3)
    //         return 0;
    //       this->lockMode = -1;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of the constants 18580 (occupant-identifier offset within a vehicle slot) and 13388 (flag offset within the player vehicle pointer) are not evidenced.
    // UNRESOLVED: The gate flag byte_7CFE88 and the meaning of mode 3 are caller-dependent and not evidenced here.
    // UNRESOLVED: The comparison field at vehicle slots +18580 and the flag at PlayerVehiclePtr+13388 are read via global pointers; the write to this+0x14 is the only local state change.
}
