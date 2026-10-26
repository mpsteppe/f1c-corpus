// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E3A10
// Canonical corpus name: VehicleWheelCountIterator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleWheelCountIterator_004e3a10.c

void UnknownObject::VehicleWheelCountIterator()
{
    // Iterates this[746] contiguous stride-0xBB0 sub-objects starting at element index 747 (byte offset +0xBAC), calling ConditionalRenderCall on each element with the float argument a2. Returns the count value last held in result, which the raw source re-reads from this[746] at the end of every iteration. The loop body runs only when the initial count is positive.
    // ASSIGNMENT: Read the element count into result from this[746] (field at +0xBA8) and initialize the loop counter v4 = 0. [source:raw, field:this:0x00000BA8]
    // GUARD: Enter the iteration only when the initial count this[746] > 0; otherwise skip the loop entirely. [source:raw, field:this:0x00000BA8]
    // LOOP: do-while loop running while v4 < result, incrementing v4 each pass; the bound result is re-read from this[746] at the end of every iteration. [source:raw, field:this:0x00000BA8]
    // CALL: Invoke ConditionalRenderCall(v5, a2) on the current element pointer, forwarding the float argument a2. [source:raw, callee:0x004DF0A0]
    // CALCULATION: Advance the element pointer v5 by 748 dword elements (stride 0xBB0 bytes) to the next sub-object. [source:raw]
    // RETURN: Return the count value last held in result after the loop (the final re-read of this[746]). [source:raw, field:this:0x00000BA8]
    // CALL: Reached from sub_4B3400 as a per-vehicle wheel render iteration. [caller:0x004B3400, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4E3A10(int *this, float a2) {
    //     int count = this[746];
    //     int i = 0;
    //     int *p = this + 747;
    //     if (count > 0) {
    //       do {
    //         ConditionalRenderCall(p, a2);
    //         count = this[746];
    //         ++i;
    //         p += 748;
    //       } while (i < count);
    //     }
    //     return count;
    //   }
    // UNRESOLVED: Identity and semantic meaning of the stride-0xBB0 sub-objects and of ConditionalRenderCall's float argument a2 are caller/render-context dependent.
    // UNRESOLVED: The re-read of this[746] inside the loop means the iteration count can drift if the field mutates concurrently; the raw source shows that behaviour but its intent is unproven.
}
