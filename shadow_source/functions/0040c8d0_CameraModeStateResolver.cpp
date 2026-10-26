// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040C8D0
// Canonical corpus name: StateCheckWithTernaryLogic
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateCheckWithTernaryLogic_0040c8d0.c

void UnknownObject::CameraModeStateResolver()
{
    // Resolves a camera-mode state value with fallback: reads the primary value from this+0xC; when zero, reads a fallback value from offset 52 of the sub-object pointed to by this+0x18. Returns 3 when both are zero, 1 when the resolved value is 1, (dword_7CFCC8 == 0) when the resolved value is 2, and 0 otherwise. Called from CameraTargetUpdateOnPlayerChange (0x0040C7A0) and SetDriverVisibility (0x004C7AA0).
    // ASSIGNMENT: Read the primary camera-mode state value from this+0xC. [field:this:0x0000000C, source:raw]
    // GUARD: When the primary value is zero, fall back to the sub-object state value read from offset 52 of *(this+0x18). [field:this:0x00000018, source:raw]
    // RETURN: Return 3 when the fallback value is also zero. [field:this:0x00000018, source:raw]
    // CALCULATION: Compute v2 = v1 - 1, mapping a resolved value of 1 to 0 and a resolved value of 2 to 1. [source:raw]
    // RETURN: Return 1 when the resolved value is 1. [source:raw]
    // RETURN: Return (dword_7CFCC8 == 0) when the resolved value is 2, i.e. the queue-dependent flag decides the result. [global:0x007CFCC8, source:raw]
    // RETURN: Return 0 for any resolved value other than 1 or 2. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_40C8D0(_DWORD *this) {
    //     int v1 = this[3];
    //     if (!v1) {
    //       v1 = *(_DWORD *)(this[6] + 52);
    //       if (!v1) return 3;
    //     }
    //     int v2 = v1 - 1;
    //     if (!v2) return 1;
    //     if (v2 == 1) return dword_7CFCC8 == 0;
    //     return 0;
    //   }
    // UNRESOLVED: The field at this+0x4C is recorded as a struct field but is not accessed by this function.
    // UNRESOLVED: The exact meaning of the returned code (3, 1, queue-dependent boolean, 0) depends on the camera-mode state convention of the callers.
}
