// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052765A
// Canonical corpus name: sub_52765A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_52765A_0052765a.c

void UnknownObject::ResourceStateResetCallback()
{
    // Reset/state-clear routine for a resource state struct (a1). Optionally reports the previous callback slot to a3, dispatches type-specific handlers through a context object a2 when the state field is 4/5 (indirect call at a2+36 with a2+40 and a1+0xC) or 6 (IndirectCallDispatch with a1+0x4 and a2), copies the value at a1+0x28 into tracking slots a1+0x30/a1+0x34, clears state fields a1+0x0/a1+0x1C/a1+0x20, and finally, if the callback pointer at a1+0x38 is non-null, invokes it with (0,0,0) and stores its result into a1+0x3C and a2+48. Returns the final callback result (or the saved a1+0x38 pointer when it was null).
    // GUARD: If output pointer a3 is non-null, writes the previous callback slot a1[15] (this+0x3C) to *a3 [field:this:0x0000003C, source:raw]
    // GUARD: If the state field this+0x0 equals 4 or 5, calls the handler pointer stored at (a2+36) with (*(a2+40), a1[3]=this+0xC) [guard:0, guard:1, field:this:0x00000000, field:this:0x0000000C, source:raw]
    // CALL: If the state field this+0x0 equals 6, invokes IndirectCallDispatch with a1[1]=this+0x4 and the context a2 [guard:2, field:this:0x00000000, field:this:0x00000004, callee:0x0052A090, source:raw]
    // ASSIGNMENT: Copies the source value this+0x28 into both tracking slots this+0x30 and this+0x34 [field:this:0x00000028, field:this:0x00000030, field:this:0x00000034, source:raw]
    // ASSIGNMENT: Clears the state fields this+0x0, this+0x1C and this+0x20 to 0 [field:this:0x00000000, field:this:0x0000001C, field:this:0x00000020, source:raw]
    // CALL: If the final callback pointer this+0x38 is non-null, invokes it with (0, 0, 0) and stores the result into this+0x3C and into *(a2+48) [field:this:0x00000038, field:this:0x0000003C, source:raw]
    // RETURN: Returns the final callback result, or the uninvoked this+0x38 pointer when the callback was null [source:raw]
    // CALL: Invoked by ResourceResetWithCounter (00517963), sub_517ADC, sub_5276C5 and sub_527EED [caller:0x00517963, caller:0x00517ADC, caller:0x005276C5, caller:0x00527EED, source:raw]

    // Conservative worker pseudocode:
    //   if (a3) *a3 = a1[15];
    //   if (a1[0] == 4 || a1[0] == 5) (*(a2+36))(*(a2+40), a1[3]);
    //   if (a1[0] == 6) IndirectCallDispatch(a1[1], a2);
    //   a1[12] = a1[13] = a1[10];
    //   result = a1[14];
    //   a1[0] = 0; a1[7] = 0; a1[8] = 0;
    //   if (result) { result = result(0, 0, 0); a1[15] = result; *(a2+48) = result; }
    //   return result;
    // UNRESOLVED: a2's type is unknown; it is only observed as a callback-table holder (a2+36/+40) and a result slot (a2+48)
    // UNRESOLVED: The concrete meaning of the type/state values 4, 5 and 6 on this+0x0 is not established beyond the dispatch behavior shown here
    // UNRESOLVED: The indirect calls at (a2+36) and a1+0x38 have no static callee targets in the packet
}
