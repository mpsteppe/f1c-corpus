// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055BFF0
// Canonical corpus name: ArraySlotCheckConditionalCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArraySlotCheckConditionalCall_0055bff0.c

void UnknownObject::ArraySlotCheckConditionalCall()
{
    // Slot-indexed conditional delegator. Loads the element pointer at this dword index a2+2, returns -1 when it is null, forwards a3..a7 to sub_55BD20, returns -1 when that sub-call fails, otherwise records the slot index a2 back into this[0] and returns the sub-call result.
    // ASSIGNMENT: Load the element pointer v8 = *(int**)(this + 4*(a2+2)) from the slot array indexed by a2. [source:raw]
    // GUARD: If v8 is null, return -1 immediately without calling sub_55BD20. [source:raw]
    // CALL: Call sub_55BD20(v8, a3, a4, a5, a6, a7) and keep its return value. [callee:0x0055BD20, source:raw]
    // GUARD: If sub_55BD20 returned non-zero, return -1 on the failure path. [source:raw]
    // ASSIGNMENT: Store the slot index back into the first dword: this[0] (byte offset 0x0) = a2. [field:this:0x00000000, source:raw]
    // RETURN: Return the sub-call result (0 on the success path). [source:raw]

    // Conservative worker pseudocode:
    //   element = this->slots[a2 + 2];
    //   if (element == NULL) return -1;
    //   result = sub_55BD20(element, a3, a4, a5, a6, a7);
    //   if (result != 0) return -1;
    //   this->current_slot = a2;
    //   return result;
    // UNRESOLVED: Semantics of sub_55BD20 and the type of the slot array starting at this dword index 2 are unidentified.
    // UNRESOLVED: The relationship between the slot index a2 and the forwarded arguments a3..a7 is not established.
}
