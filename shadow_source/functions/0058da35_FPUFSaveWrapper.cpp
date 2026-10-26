// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058DA35
// Canonical corpus name: FPUFSaveWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FPUFSaveWrapper_0058da35.c

void UnknownObject::FPUFSaveWrapper()
{
    // __usercall FPU-state wrapper. Saves the x87 state with fsave into a stack buffer (save area at buffer+8), calls sub_58DE2C with arguments (a2, a1) and a pointer to the buffer, then restores the x87 state with frstor. Returns the first double of the saved buffer (the st0 snapshot). If sub_58DE2C returns non-zero, calls SetByteFlag().
    // ASSIGNMENT: Save the x87 FPU state via fsave into the local buffer (save area begins at buffer offset 8). [source:raw]
    // CALL: Call sub_58DE2C(a2, a1, (int)v6), passing both source arguments and a pointer to the FPU save buffer. [callee:0x0058DE2C, source:raw]
    // RETURN: Restore the x87 FPU state via frstor from the buffer, then return v6[0], the first saved double. [source:raw]
    // GUARD: If sub_58DE2C returned non-zero, invoke SetByteFlag() before returning. [source:raw]

    // Conservative worker pseudocode:
    //   double __usercall sub_58DA35@<st0>(double a1@<st1>, double a2@<st0>) {
    //     double v6[15];
    //     __asm { fsave byte ptr [v6+8] }
    //     int v3 = sub_58DE2C(a2, a1, (int)v6);
    //     __asm { frstor byte ptr [v6+8] }
    //     if (v3) SetByteFlag();
    //     return v6[0];
    //   }
    // UNRESOLVED: Why the FPU state is saved/restored around sub_58DE2C (reentrancy or ABI isolation) is not established.
    // UNRESOLVED: SetByteFlag target and the meaning of the flag it raises are unknown.
    // UNRESOLVED: Semantics of sub_58DE2C's two FPU arguments and its return flag are unknown.
}
