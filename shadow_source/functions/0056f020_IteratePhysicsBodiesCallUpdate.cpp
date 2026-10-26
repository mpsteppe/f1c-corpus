// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056F020
// Canonical corpus name: IteratePhysicsBodiesCallUpdateFunction
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IteratePhysicsBodiesCallUpdateFunction_0056f020.c

void UnknownObject::IteratePhysicsBodiesCallUpdate()
{
    // Iterates a fixed-stride element array owned by the this object and calls the update routine sub_569C10 on every element. The element count is the dword at this+0x0 and the array base pointer is the dword at this+0x4. Elements are 580 bytes apart. The loop runs only when the count at this+0x0 is positive, and returns the count read back from this+0x0 after iteration.
    // ASSIGNMENT: Read the element count from this[0] and seed the loop counter, plus base index for the element pointer starting at this[1]. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // GUARD: Guard on this[0] > 0; a non-positive count skips the loop entirely. [guard:0, field:this:0x00000000, source:raw]
    // LOOP: do-while loop that runs while the iteration counter is below the count at this[0]. [guard:0, field:this:0x00000000, source:raw]
    // CALL: Call sub_569C10(this[1] + v5, a2) on each element, passing the caller-supplied double argument a2. [callee:0x00569C10, field:this:0x00000004, source:raw]
    // CALCULATION: Advance the element offset by the fixed stride of 580 bytes each iteration. [source:raw]
    // RETURN: Return the count re-read from this[0] after the loop (or the initial read when the loop never ran). [field:this:0x00000000, source:raw]
    // CALL: Called by WheelDataCopy (0x004414D0) to run the per-body update over the vehicle physics body array. [caller:0x004414D0, abi:lead, function:0x0056F020, source:raw]

    // Conservative worker pseudocode:
    //   int sub_56F020(int *this, double a2) {
    //     int count = this[0];
    //     int result = count;
    //     if (count > 0) {
    //       int off = 0;
    //       int i = 0;
    //       do {
    //         sub_569C10((char *)this[1] + off, a2);
    //         result = this[0];
    //         ++i;
    //         off += 580;
    //       } while (i < this[0]);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Type and layout of the array at this+0x4 are caller-defined; the 580-byte stride is taken from the raw source.
    // UNRESOLVED: Purpose of the caller-supplied double argument a2 passed through to sub_569C10 is unknown.
}
