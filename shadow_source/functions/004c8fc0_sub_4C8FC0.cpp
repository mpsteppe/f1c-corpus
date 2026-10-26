// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8FC0
// Canonical corpus name: sub_4C8FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C8FC0_004c8fc0.c

void UnknownObject::sub_4C8FC0()
{
    // Decrements a float counter (this+0x18) by the global delta dbl_8AFE98; when the counter drops to <= 0.0 and the secondary ArithmeticComparison_9000 gate passes, resets the counter from its initial value (this+0x14) and dispatches an indirect vtable callback at offset 12.
    // CALCULATION: v2 = this[6] (this+0x18) - dbl_8AFE98: decrement the counter by the global delta. [global:0x008AFE98, field:this:0x00000018]
    // ASSIGNMENT: Store the decremented value back into the counter this[6] (this+0x18). [field:this:0x00000018]
    // GUARD: Fire only when the decremented counter is <= 0.0 and ArithmeticComparison_9000() returns non-zero. [field:this:0x00000018, callee:0x004C9000]
    // STATE_TRANSITION: Reset the counter from its initial value this[5] (this+0x14). [field:this:0x00000014, field:this:0x00000018]
    // CALL: Indirect call through the object vtable at offset 12, using the vtable pointer at this+0x0; the result becomes the return value. [field:this:0x00000000]
    // RETURN: Return the vtable callback result when the gate fired, otherwise 0. [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   this[6] = this[6] - dbl_8AFE98;
    //   if (this[6] <= 0.0 && ArithmeticComparison_9000()) {
    //     this[6] = this[5];
    //     return (*(int (__thiscall **)(void))(*(_DWORD*)this + 12))(this);
    //   }
    //   return 0;
    // UNRESOLVED: Role of obj+0xC is unknown; it is not directly referenced in the visible body and may be consumed inside ArithmeticComparison_9000.
    // UNRESOLVED: flt_59E440 (0059E440) is listed as a global read but does not appear in the raw source of this function; its involvement is unresolved.
    // UNRESOLVED: Semantics of ArithmeticComparison_9000's arguments/return and of the vtable+12 callback are unknown.
    // UNRESOLVED: Caller sub_4C7DE0's call context was not analyzed.
}
