// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BBF70
// Canonical corpus name: ArrayShiftConditionalDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayShiftConditionalDispatch_004bbf70.c

void UnknownObject::ArrayShiftConditionalDispatch()
{
    // Decrements the entry count of a fixed-size array of DWORD pairs, shifts the remaining pairs one slot toward the front, then reports emptiness through ArithmeticComparison_5660 using a comparison base located at parent-object + 13004.
    // GUARD: If the entry count this[15] (this+0x3C) is not greater than 0, skip the decrement and shift and jump straight to status reporting. [field:this:0x0000003C]
    // ASSIGNMENT: Decrement the entry count: this[15] = this[15] - 1 (this+0x3C). [field:this:0x0000003C]
    // LOOP: Shift every remaining DWORD pair one slot toward the front while the copy index is below the new count: slot i type/value (this+0x40 / this+0x44) are overwritten with slot i+1 type/value (this+0x48 / this+0x4C onward). [field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C]
    // CALCULATION: Compute the status-report base pointer as the parent object at (this+0x0) advanced by 13004 bytes. [field:this:0x00000000]
    // CALL: Call ArithmeticComparison_5660 with that base pointer and flag 0 when the count is <= 0 (empty) or 1 when the count is > 0 (has entries). [callee:0x004A5660, field:this:0x0000003C, field:this:0x00000000]
    // RETURN: Return the result of the ArithmeticComparison_5660 call. [callee:0x004A5660]

    // Conservative worker pseudocode:
    //   if (this[15] > 0) {
    //     this[15] = this[15] - 1;
    //     for (i = 0; i < this[15]; i++) { slot[i].type = slot[i+1].type; slot[i].value = slot[i+1].value; }
    //   }
    //   return ArithmeticComparison_5660((char*)this[0] + 13004, this[15] > 0 ? 1 : 0);
    // UNRESOLVED: Identity and layout of the parent container object and the meaning of the 13004-byte offset are not established; only the count-guard and shift semantics are evident.
    // UNRESOLVED: The pair semantics (type + value per slot) are inferred from the shift pattern; the entry meaning is unknown.
    // UNRESOLVED: Caller sub_4B3400 invokes this as a dequeue step; the trigger context at the call site was not analyzed.
}
