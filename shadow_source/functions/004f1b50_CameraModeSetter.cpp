// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F1B50
// Canonical corpus name: CameraModeSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraModeSetter_004f1b50.c

void UnknownObject::CameraModeSetter()
{
    // Sets the global camera view mode (dword_7C74F8) and, on the enabled-with-state path, clears three render-offset fields (0x34EC/0x34F0/0x34F4) to 0. The branch taken depends on the input flag a2 and the internal state flag at this[3247] (offset 0x32BC). Used during pit stop camera transitions by PitStopReadyCheck and PitStopProgress.
    // ASSIGNMENT: Initialize result to 0 and read the internal camera-state flag v3 from this[3247] (offset 0x32BC). [source:raw, field:this:0x000032BC, function:0x004F1B50]
    // GUARD: Branch on the enable flag a2 being non-zero (camera change requested); otherwise take the a2 == 0 path. [source:raw, caller:0x004A6200, caller:0x004A68B0]
    // GUARD: Within the enabled path, branch on the internal state flag v3: when set, clear render offsets; when clear, set the view-mode global instead. [source:raw, field:this:0x000032BC]
    // ASSIGNMENT: Clear the three render-offset fields 0x34EC, 0x34F0 and 0x34F4 to 0. [source:raw, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4]
    // ASSIGNMENT: On the enabled path with v3 clear, set the camera view mode global dword_7C74F8 to 2. [source:raw, global:0x007C74F8]
    // GUARD: On the a2 == 0 (disable) path, act only when the internal state flag v3 is also clear. [source:raw, field:this:0x000032BC]
    // ASSIGNMENT: Set the camera view mode global dword_7C74F8 to 0 on the disable path. [source:raw, global:0x007C74F8]
    // RETURN: Return 0. [source:raw, function:0x004F1B50]

    // Conservative worker pseudocode:
    //   int sub_4F1B50(_DWORD *this, char a2) {
    //     int result = 0;
    //     int state = this[3247];
    //     if (a2) {
    //       if (state) {
    //         this[3387] = 0;
    //         this[3388] = 0;
    //         this[3389] = 0;
    //       } else {
    //         dword_7C74F8 = 2;
    //       }
    //     } else if (!state) {
    //       dword_7C74F8 = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The identity of the state flag at offset 0x32BC (camera/pit-stop condition) is unknown; the owner object is unknown.
    // UNRESOLVED: Whether this function acts on the player camera object or the active-slot camera is unresolved.
}
