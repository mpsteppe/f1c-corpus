// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A55E0
// Canonical corpus name: ConditionalDispatch_55e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatch_55e0_004a55e0.c

void UnknownObject::PitstopTransitionSelector()
{
    // Pitstop phase selector (sub_4A55E0, legacy ABI name Conditional_Dispatch_4a55e0). Reads the selector flag at this[11] (offset 0x2C); when non-zero it calls PitstopStateTransition on this[4] (offset 0x10), otherwise on this[3] (offset 0xC). Returns the result of the selected transition.
    // GUARD: Read the selector flag this[11] (offset 0x2C): non-zero selects this[4], zero selects this[3]. [field:this:0x0000002C, source:raw]
    // CALL: When the flag is zero, advance the state machine with PitstopStateTransition(this[3]) using the candidate pointer at offset 0xC. [callee:0x004A5600, field:this:0x0000000C, source:raw]
    // CALL: When the flag is non-zero, advance the state machine with PitstopStateTransition(this[4]) using the candidate pointer at offset 0x10. [callee:0x004A5600, field:this:0x00000010, source:raw]
    // RETURN: Return the result of the selected PitstopStateTransition call; the selected call is not null-guarded. [source:raw]
    // CALL: Called from ArithmeticComparison_5660 (0x004A5660), UtilityFunction_5750 (0x004A5750), IndexDecrementWithBoundsWrap (0x004A57A0) and AIStateMachineWithModeDispatch (0x004A5D10) as a pitstop state phase selector. [caller:0x004A5660, caller:0x004A5750, caller:0x004A57A0, caller:0x004A5D10, source:raw]

    // Conservative worker pseudocode:
    //   if (this[11])
    //       return PitstopStateTransition(this[4]);
    //   else
    //       return PitstopStateTransition(this[3]);
    // UNRESOLVED: Whether this[11] is a boolean selector or a mode/state value is only evidenced as zero versus non-zero.
    // UNRESOLVED: The pitstop state machine phases advanced by PitstopStateTransition are owned by the callee and not evidenced here.
}
