// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058EF5F
// Canonical corpus name: IncrementWrapperAroundCallLoop
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/IncrementWrapperAroundCallLoop_0058ef5f.c

void UnknownObject::IncrementWrapperAroundCallLoop()
{
    // Increment-and-read loop: repeatedly increments the caller-owned counter at offset 0 of a1, reads the next value via BufferedByteReader(a2), and continues while the predicate sub_589BF3(v2) is true. Returns the last value read. Structure is a documented twin of MultiFieldPointerFree (00414380). Called by sub_58E4D2.
    // LOOP: do-while loop that increments the counter at offset 0 of a1 and reads through the buffer until the predicate sub_589BF3 returns false. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: ++*a1: increment the caller-owned counter stored at offset 0 of the a1 pointer. [field:this:0x00000000, source:raw]
    // CALL: v2 = BufferedByteReader(a2): read the next value from the buffered byte reader each iteration. [callee:0x0058EF2E, source:raw]
    // GUARD: Loop continuation guard: while sub_589BF3(v2) is non-zero, keep incrementing and reading. [callee:0x00589BF3, source:raw]
    // RETURN: Return v2, the last value produced by BufferedByteReader. [function:0x0058EF5F, source:raw]
    // CALL: Invoked by sub_58E4D2 as part of its byte-reading path. [caller:0x0058E4D2, source:raw]

    // Conservative worker pseudocode:
    //   int IncrementWrapperAroundCallLoop(_DWORD *a1, int a2) {
    //     int v2;
    //     do {
    //       ++*a1;
    //       v2 = BufferedByteReader(a2);
    //     } while (sub_589BF3(v2));
    //     return v2;
    //   }
    // UNRESOLVED: Purpose of the sub_589BF3 predicate and the meaning of its return value is not established here.
    // UNRESOLVED: Semantics of the caller-owned counter at offset 0 of a1 and the data read by BufferedByteReader are caller-defined.
}
