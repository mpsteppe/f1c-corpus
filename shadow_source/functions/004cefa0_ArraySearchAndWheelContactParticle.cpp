// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CEFA0
// Canonical corpus name: sub_4CEFA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4CEFA0_004cefa0.c

void UnknownObject::ArraySearchAndWheelContactParticle()
{
    // Searches a strided array owned by the receiver for the first entry whose element field at +4 equals a3, then spawns a wheel contact particle effect at that entry via WheelContactParticle. The array element count is read from this+0x10 and the pointer to the first element from this+0x14; entries are 108 bytes apart. Returns the matched entry index (0-based), or the element count when no entry matches and the search runs out, or 0 when the array is empty. Called by AIWaypointPathCheckerRenderer.
    // ASSIGNMENT: Initialize result to 0 before the count check. [source:raw]
    // GUARD: Guard on the array element count at this+0x10 being greater than zero; when it is <= 0 the function returns the initial result 0 immediately. [field:this:0x00000010]
    // LOOP: Linear search starting at the first element pointer stored at this+0x14, advancing the entry pointer by a 108-byte stride each iteration. [field:this:0x00000014, source:raw]
    // GUARD: Per-iteration exit guard: if the incremented result reaches the element count at this+0x10, stop searching and return the count. [field:this:0x00000010, source:raw]
    // CALCULATION: Compare the entry field at +4 (matching slot/ID) against a3 to decide whether to keep scanning. [field:*(this+0x14):0x00000004]
    // CALL: On match, call WheelContactParticle with the matched entry and the raw arguments a2, a4, a5 to spawn the wheel contact particle effect. [callee:0x004CD6C0]
    // RETURN: Return WheelContactParticle's result on match, the element count when the scan exhausts, or 0 for an empty array. [callee:0x004CD6C0, source:raw]
    // CALL: Invoked by AIWaypointPathCheckerRenderer (0x004024F0) during render-time contact-particle lookup. [caller:0x004024F0]

    // Conservative worker pseudocode:
    //   int sub_4CEFA0(void* self, double a2, int a3, int a4, int a5) {
    //     int count = *(int*)((char*)self + 0x10);
    //     int result = 0;
    //     if (count > 0) {
    //       char* entry = *(char**)((char*)self + 0x14);
    //       while (*(int*)(entry + 4) != a3) {
    //         if (++result >= count) return result;
    //         entry += 108;
    //       }
    //       return WheelContactParticle(entry, a2, a4, a5);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Element layout beyond the +4 matching slot is unknown; the 108-byte stride structure is not described by the packet.
    // UNRESOLVED: Semantic meaning of a2, a4, a5 passed to WheelContactParticle depends on that callee's signature.
}
