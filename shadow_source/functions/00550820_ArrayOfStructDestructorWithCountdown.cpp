// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550820
// Canonical corpus name: ArrayOfStructDestructorWithCountdown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfStructDestructorWithCountdown_00550820.c

void UnknownObject::ArrayOfStructDestructorWithCountdown()
{
    // Counted-array destructor for a fixed-size (8-byte) element array. Guards on the counted-array pointer stored at this+0x8; when non-null it reads the element count from the dword immediately before the array, walks the elements backward, destroying each one via sub_550810 (0x00550810), then releases the whole allocation including the count prefix through FreeWrapper_7bcf (0x00587BCF). Ends with an unconditional trailing stub call. Invoked from sub_550F70 (0x00550F70).
    // GUARD: Array destruction is skipped entirely when the counted-array pointer at this+0x8 is null [field:this:0x00000008, source:raw]
    // CALCULATION: Loads the element count from the dword immediately before the array pointer (v1-4) and derives the last-element pointer as the array base plus 8 times the count (element stride 8 bytes) [field:this:0x00000008, source:raw]
    // LOOP: Backward iteration over all elements, stepping the element pointer down by 2 dwords (8 bytes) per iteration and destroying each element via sub_550810 (0x00550810) [callee:0x00550810, source:raw]
    // CALL: FreeWrapper_7bcf (0x00587BCF) releases the whole allocation block including the count prefix at v1-4 [callee:0x00587BCF, source:raw]
    // CALL: Ends with an unconditional trailing no-op stub call whose target is not present in this packet's callee facts [source:raw]
    // CALL: Invoked by sub_550F70 (0x00550F70) [caller:0x00550F70, source:raw]

    // Conservative worker pseudocode:
    //   counted_array = this[2];
    //   if (counted_array) {
    //     count = *(counted_array - 4);
    //     element_ptr = counted_array + 8 * count;
    //     for (remaining = count; remaining > 0; --remaining) {
    //       element_ptr -= 2;
    //       sub_550810(element_ptr);
    //     }
    //     FreeWrapper_7bcf(counted_array - 4);
    //   }
    //   stub_call();
    // UNRESOLVED: The trailing stub call target is absent from the callee facts and its address is not evidenced in this packet
    // UNRESOLVED: The element layout destroyed by sub_550810 (8-byte stride) is not defined here
}
