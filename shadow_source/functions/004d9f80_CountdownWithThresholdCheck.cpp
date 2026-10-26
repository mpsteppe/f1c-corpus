// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D9F80
// Canonical corpus name: sub_4D9F80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D9F80_004d9f80.c

void UnknownObject::CountdownWithThresholdCheck()
{
    // Countdown with threshold check: returns 1 early if the state timer this+0x10 is already negative; otherwise decrements it by the global delta dbl_8AFE98, refreshes vehicle state via VehicleStateUpdate when this+0x14 is negative, blocks (return 1) when TimerValueComparison(this) is false, and otherwise dispatches sub_4DA0D0(this) and returns 0.
    // GUARD: Block if state timer this[4] (this+0x10) is below 0.0: return 1. Countdown/threshold guard consistent with the legacy abi label. [field:this:0x00000010, abi:lead, source:raw]
    // CALCULATION: Decrement countdown timer: this[4] = this[4] - dbl_8AFE98 (global 0x008AFE98, per-call delta). [field:this:0x00000010, global:0x008AFE98, source:raw]
    // STATE_TRANSITION: If condition flag this[5] (this+0x14) is negative, call VehicleStateUpdate() to refresh the vehicle state. [field:this:0x00000014, callee:0x004D9FE0, source:raw]
    // GUARD: Block (return 1) if TimerValueComparison(this) evaluates to false/zero. [callee:0x004DA080, source:raw]
    // CALL: Dispatch to sub_4DA0D0(this) for the subsequent processing step once all guards pass. [callee:0x004DA0D0, source:raw]
    // RETURN: Return 0 on the success path (all guards passed and sub_4DA0D0 dispatched). [source:raw]

    // Conservative worker pseudocode:
    //   if (this[0x10] < 0.0) return 1
    //   this[0x10] -= dbl_8AFE98
    //   if (this[0x14] < 0.0) VehicleStateUpdate()
    //   if (!TimerValueComparison(this)) return 1
    //   sub_4DA0D0(this)
    //   return 0
    // UNRESOLVED: Packet lists global flt_59E440 (0x0059E440) as read, but the raw source text contains no reference to it; possibly a decompiler-omitted operand. Left unclaimed.
    // UNRESOLVED: Return-value semantics (1 = blocked, 0 = proceed) are inferred from control flow, not independently grounded.
    // UNRESOLVED: VehicleStateUpdate() is called with no explicit argument in the raw source.
    // UNRESOLVED: Meaning of the this+0x14 condition flag is unknown.
}
