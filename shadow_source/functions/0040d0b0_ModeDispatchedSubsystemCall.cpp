// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040D0B0
// Canonical corpus name: ModeDispatchedSubsystemCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeDispatchedSubsystemCall_0040d0b0.c

void UnknownObject::ModeDispatchedSubsystemCall()
{
    // Dispatches a subsystem call: reads the object pointer at this+0x18 and, if non-null, calls UtilityFunction_a610(v1, mode) where mode is selected by a switch on global dword_7CFDC4 (case 1->1, case 2->0, case 3->3, default->2). Returns the call result, or 0 when the object pointer is null.
    // GUARD: Load the object pointer from this+0x18; if it is null, skip the dispatch and fall through to the 0 result. [function:0x0040D0B0, field:this:0x00000018, source:raw]
    // CALCULATION: Switch on the dispatch mode selector dword_7CFDC4 using the jump table jpt_40D0C3; each case selects the second argument passed to UtilityFunction_a610 (1->1, 2->0, 3->3, default->2). [global:0x007CFDC4, global:0x0040D0EC, function:0x0040D0B0, source:raw]
    // CALL: Call UtilityFunction_a610(v1, mode) with the object pointer and the mode-selected argument; store its return value as result. [callee:0x0040A610, abi:lead, field:this:0x00000018, source:raw]
    // RETURN: Return the UtilityFunction_a610 result, or 0 when the object pointer at this+0x18 was null. [function:0x0040D0B0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40D0B0(int *this) {
    //     int *obj = (int *)this[6];
    //     if (!obj) return 0;
    //     switch (dword_7CFDC4) {
    //       case 1: return UtilityFunction_a610(obj, 1);
    //       case 2: return UtilityFunction_a610(obj, 0);
    //       case 3: return UtilityFunction_a610(obj, 3);
    //       default: return UtilityFunction_a610(obj, 2);
    //     }
    //   }
    // UNRESOLVED: Identity of the subsystem object at this+0x18 is unknown.
    // UNRESOLVED: Meaning of the mode argument (0-3) and the dispatch mode selector dword_7CFDC4 is unknown.
}
