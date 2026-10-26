// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004895B0
// Canonical corpus name: sub_4895B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4895B0_004895b0.c

void UnknownObject::SelectionIndexAddWithClamp()
{
    // Increments a selection/accumulator counter by a fixed step and clamps it to a ceiling. The sum of this+0x164 (step) and this+0x14C (counter) is stored back at this+0x14C, then capped to this+0x160 (maximum). After the update the UI object emits a change notification through virtual slot +44 with argument 1, then refreshes list state via sub_489D00 and converts the internal float position to an integer via FloatToIntConversion. Returns 0. Called by UIScrollbarThumbDragHandler (0048A650).
    // CALL: Emits the change notification by dispatching through virtual slot +44 of the object pointed to by this (slot stored at obj+0x2C), passing argument 1 [field:obj:0x0000002C, field:this:0x00000000, source:raw]
    // CALCULATION: Computes the new accumulator as the sum of this[89] (this+0x164, step) and this[83] (this+0x14C, counter) [field:this:0x00000164, field:this:0x0000014C, source:raw]
    // ASSIGNMENT: Writes the unclamped sum back to this[83] (this+0x14C) [field:this:0x0000014C, source:raw]
    // GUARD: Clamp ceiling: when the maximum read at this[88] (this+0x160) is smaller than the sum, the sum is replaced by that maximum [field:this:0x00000160, field:this:0x0000014C, source:raw]
    // ASSIGNMENT: Writes the clamped result back to this[83] (this+0x14C) as the final counter value [field:this:0x0000014C, source:raw]
    // CALL: Refreshes the scroll list visual state by calling sub_489D00 on this [callee:0x00489D00, source:raw]
    // CALL: Converts the internal float position to an integer via FloatToIntConversion [callee:0x00489E90, source:raw]
    // RETURN: Returns constant 0 to the caller [source:raw]
    // CALL: Invoked by UIScrollbarThumbDragHandler (0048A650) to update the selection index after a scrollbar thumb drag [caller:0x0048A650, source:raw]

    // Conservative worker pseudocode:
    //   emit virtual slot +44 (this, 1);
    //   sum = this[0x164/4] + this[0x14C/4];
    //   this[0x14C/4] = sum;
    //   max = this[0x160/4];
    //   if (max < sum) sum = max;
    //   this[0x14C/4] = sum;
    //   sub_489D00(this);
    //   FloatToIntConversion(this);
    //   return 0;
    // UNRESOLVED: The target of the virtual slot +44 dispatch is not identified; it is an indirect vtable call
    // UNRESOLVED: The semantic roles of the counter (this+0x14C), step (this+0x164) and maximum (this+0x160) are inferred from the clamp pattern and the scrollbar caller; no runtime evidence ties them to a selection index
    // UNRESOLVED: FloatToIntConversion is called without an explicit argument in the raw source; its operand and output are not established here
}
