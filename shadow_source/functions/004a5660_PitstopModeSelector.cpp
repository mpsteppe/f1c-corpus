// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A5660
// Canonical corpus name: ArithmeticComparison_5660
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_5660_004a5660.c

void UnknownObject::PitstopModeSelector()
{
    // Selects a two-mode operation state on the object based on the input flag a2. With a2 zero it resets mode (this+0x28) to 1 and clears both selector flags (this+0x2C, this+0x30). With a2 non-zero it transitions mode to 2 and sets both flags to 1, but only when the mode is not already 2. Every path then dispatches through ConditionalDispatch_55e0 and returns its result.
    // GUARD: Branch on the input flag a2: non-zero takes the active mode path, zero takes the reset path. [source:raw]
    // GUARD: Transition to mode 2 only when the current mode at this+0x28 is not already 2. [guard:0]
    // STATE_TRANSITION: On the active path set the mode at this+0x28 to 2 and both selector flags (this+0x2C, this+0x30) to 1. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030]
    // CALL: Dispatch through ConditionalDispatch_55e0 after the mode-2 transition and return its result. [callee:0x004A55E0]
    // STATE_TRANSITION: On the reset path (a2 == 0) set the mode at this+0x28 to 1 and both selector flags (this+0x2C, this+0x30) to 0. [field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030]
    // CALL: Dispatch through ConditionalDispatch_55e0 on the reset and redundant-mode paths; its return value is returned to the caller. [callee:0x004A55E0]
    // RETURN: Return the result of ConditionalDispatch_55e0. [function:0x004A5660]

    // Conservative worker pseudocode:
    //   int PitstopModeSelector(unsigned* this, char flag) {
    //     if (flag) {
    //       if (this[10] != 2) {
    //         this[10] = 2; this[11] = 1; this[12] = 1;
    //         return ConditionalDispatch_55e0(this);
    //       }
    //     } else {
    //       this[10] = 1; this[11] = 0; this[12] = 0;
    //     }
    //     return ConditionalDispatch_55e0(this);
    //   }
    // UNRESOLVED: The exact mode meanings chosen inside ConditionalDispatch_55e0 and the purpose of the two selector flags (this+0x2C, this+0x30) are not established here.
    // UNRESOLVED: The semantics of the a2 flag (active vs reset) are derived from the call context and are not independently proven.
}
