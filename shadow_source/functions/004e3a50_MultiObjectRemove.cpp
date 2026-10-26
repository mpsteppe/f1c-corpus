// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3A50
// Canonical corpus name: MultiObjectRemove
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiObjectRemove_004e3a50.c

void UnknownObject::MultiObjectRemove()
{
    // thiscall that removes every element in an object array. Reads the element count at this+0xBA8 (this[746]); when it is greater than zero, walks the array starting at this+747 (float) with stride 187 floats and calls sub_4DF110(element, a2, -1) for each element. The count at this+0xBA8 is re-read every iteration and drives the loop condition; the final count is returned. Structural twin of UIElementMultiDispatch (004e39d0) per cluster prelabel.
    // ASSIGNMENT: Read the element count from this+0xBA8 (this[746]) into result. [field:this:0x00000BA8, source:raw]
    // GUARD: Only enter the removal loop when the count at this+0xBA8 is greater than zero; otherwise return the count immediately. [field:this:0x00000BA8, source:raw]
    // LOOP: do-while loop over the count using counter v4, starting at the first element pointer this+747 (float). [source:raw]
    // CALL: Call sub_4DF110(element, a2, -1) for each element to remove it. [callee:0x004DF110, source:raw]
    // CALCULATION: Advance the element pointer v5 by 187 floats (748 bytes) between iterations to reach the next element. [source:raw]
    // ASSIGNMENT: Re-read the count at this+0xBA8 each iteration and re-compare it with the counter v4 to drive the loop condition. [field:this:0x00000BA8, source:raw]
    // RETURN: Return the last read count value. [source:raw]
    // CALL: Invoked from loading/teardown paths (LoadingPhase1, LoadingPhase2, sub_4B9B80) to remove a set of objects during phase transitions. [caller:0x004B87C0, caller:0x004B8940, caller:0x004B9B80]

    // Conservative worker pseudocode:
    //   int sub_4E3A50(float *this, float a2) {
    //     int result = this[746];
    //     int i = 0;
    //     if (result > 0) {
    //       float *v5 = this + 747;
    //       do {
    //         sub_4DF110(v5, a2, -1);
    //         result = this[746];
    //         ++i;
    //         v5 += 187;
    //       } while (i < result);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the removed element type and the meaning of the sub_4DF110 arguments (a2, -1) are unknown.
    // UNRESOLVED: The owner object holding the array at this+0xBA8 is unknown; the prelabel names it a structural twin of UIElementMultiDispatch (004e39d0).
}
