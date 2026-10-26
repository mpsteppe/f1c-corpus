// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004CF040
// Canonical corpus name: RepeatedCallLoop_f040
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RepeatedCallLoop_f040_004cf040.c

void UnknownObject::RepeatedCallLoop()
{
    // Iterates a strided array owned by `this` and calls sub_4CB5E0 once per element. The element count is read from this+0x10; the first element pointer is read from this+0x14; consecutive elements are 108 bytes apart. When the count is not positive the loop is skipped and the function returns the count.
    // ASSIGNMENT: Read the element count from this+0x10 into result and seed the loop counter. [source:raw, field:this:0x00000010]
    // GUARD: Proceed only when the count is positive; otherwise the loop body never runs. [source:raw]
    // LOOP: do-while loop that runs until the per-iteration counter reaches the element count. [source:raw, field:this:0x00000010]
    // CALL: Call sub_4CB5E0 on each element: base pointer from this+0x14 plus the current strided index. [callee:0x004CB5E0, field:this:0x00000014]
    // CALCULATION: Advance the element index by 108 bytes after each call. [source:raw]
    // RETURN: Return the element count read from this+0x10. [source:raw]

    // Conservative worker pseudocode:
    //   int RepeatedCallLoop(DWORD *this) {
    //     int count = this[4];
    //     int i = 0;
    //     if (count > 0) {
    //       int off = 0;
    //       do { sub_4CB5E0(this[5] + off); off += 108; ++i; } while (i < count);
    //     }
    //     return count;
    //   }
    // UNRESOLVED: Identity and purpose of the owner object are unknown.
    // UNRESOLVED: Element type and semantics of the 108-byte stride depend on the caller's array layout.
    // UNRESOLVED: Purpose and behavior of callee sub_4CB5E0 are unknown here.
}
