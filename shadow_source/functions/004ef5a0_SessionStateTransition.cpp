// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EF5A0
// Canonical corpus name: SessionStateTransition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SessionStateTransition_004ef5a0.c

void UnknownObject::SessionStateTransition()
{
    // Updates the session state pointer at this+0x32BC with the incoming state a2, then runs session-type-gated side effects. When a3 is set, the old state is non-NULL and the new state is NULL (exit transition), it records the vehicle position and race elapsed time via transform helpers and sub_447780. When the old state is not 1 and the new state is 1 (entry to state 1), it queries PositionChangeMonitor, clears session cleanup flags, adjusts the AI speed delta, and zeroes two fields at +17236/+17240 of the session object. A dword_7C569C value of 5 skips the position-recording path.
    // ASSIGNMENT: Store the incoming state pointer a2 into this+0x32BC (the session state pointer) and remember the prior value v5; result is a2. [source:raw, field:this:0x000032BC]
    // GUARD: When a3 is zero, and also at the bottom of the exit path, return early if dword_7C569C (session type) is not 5. [source:raw, global:0x007C569C]
    // GUARD: Exit-transition guard: requires a3 set, dword_7C569C == 5, new state a2 NULL and prior state v5 non-NULL to enter the position-recording path. [source:raw, field:this:0x000032BC, global:0x007C569C]
    // CALL: Call F_3DTransformWithMatrixMultiplication on two stack vectors v10/v9 to build the position transform. [source:raw, callee:0x004EFB20]
    // CALL: Call AIVehiclePathPositionTracking on the same vectors v10/v9. [source:raw, callee:0x004EF7C0]
    // ASSIGNMENT: Read the three position components from this+0x34EC, this+0x34F0 and this+0x34F4 into v11. [source:raw, field:this:0x000034EC, field:this:0x000034F0, field:this:0x000034F4]
    // CALL: Call sub_447780 with the address of dbl_7C7428 and the position vector v11; its result becomes the return value. [source:raw, callee:0x00447780, global:0x007C7428]
    // GUARD: Entry-to-state-1 guard: proceed only when the prior state v5 is not 1 and the new state at this+0x32BC equals 1. [source:raw, guard:0, field:this:0x000032BC]
    // CALL: Call PositionChangeMonitor(this); if it returns non-NULL, read the dword at its +300 offset into v6. [source:raw, callee:0x004E9630]
    // CALL: Call SessionCleanupFlagClear with the session object at *this. [source:raw, callee:0x0042ADB0, field:this:0x00000000]
    // CALL: Call AISpeedDeltaSetter with the session object at *this and the position-monitor value v6; its result becomes the return value. [source:raw, callee:0x0042ACA0, field:this:0x00000000]
    // ASSIGNMENT: Zero the two dwords at +17236 and +17240 of the session object pointed to by *this. [source:raw, field:this:0x00000000]
    // RETURN: Return the last computed result (the stored state a2, or the value from sub_447780 or AISpeedDeltaSetter). [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int sub_4EF5A0(float *this, _DWORD *a2, char a3) {
    //     result = (unsigned int)a2;
    //     v5 = *((_DWORD *)this + 3247);
    //     *((_DWORD *)this + 3247) = a2;
    //     if (a3 == 0) goto L6;
    //     if (dword_7C569C != 5) return result;
    //     if (a2 == NULL && v5 != NULL) {
    //       F_3DTransformWithMatrixMultiplication(v10, v9);
    //       AIVehiclePathPositionTracking(v10, v9);
    //       v11[0] = this[3387]; v11[1] = this[3388]; v11[2] = this[3389];
    //       result = sub_447780((int)&dbl_7C7428, v11);
    //     }
    //   L6:
    //     if (dword_7C569C != 5) return result;
    //   L7:
    //     if (v5 != (_DWORD*)1 && *((_DWORD *)this + 3247) == 1) {
    //       v6 = 0;
    //       v7 = PositionChangeMonitor(this);
    //       if (v7) v6 = *(_DWORD *)(v7 + 300);
    //       SessionCleanupFlagClear(*(_DWORD *)this);
    //       result = AISpeedDeltaSetter(*(_DWORD **)this, v6);
    //       *(_DWORD *)(*(_DWORD *)this + 17236) = 0;
    //       *(_DWORD *)(*(_DWORD *)this + 17240) = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of state identifiers (NULL exit, 1 entry) and the session state enum is not specified in the packet.
    // UNRESOLVED: Offsets +17236/+17240 and v7+300 belong to objects not in the packet field table; semantics of those writes unknown.
    // UNRESOLVED: dword_7C569C == 5 branch semantics (session type value) not grounded beyond the raw guard.
}
