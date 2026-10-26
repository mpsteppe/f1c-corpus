// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058D7C3
// Canonical corpus name: LoopWithSentinelTermination
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LoopWithSentinelTermination_0058d7c3.c

void UnknownObject::loopWithSentinelTermination()
{
    // Iterates a stream-output operation over a descending dword pointer i that starts one dword before a2. Each iteration calls StreamByteOutputWithBufferManagement(a1, a3, a4) and then checks the sentinel *a4 == -1; a hit terminates the loop immediately. Otherwise result is set to the current i and i decrements by one dword; the loop condition continues while (int)result > 0. Returns the last accepted pointer (a2 if the loop never ran, otherwise the final i).
    // ASSIGNMENT: Initialize result = a2; result carries the current accepted pointer and the return value. [source:raw]
    // ASSIGNMENT: Initialize loop pointer i to one dword before a2: i = a2 - 1 (as char arithmetic). [source:raw]
    // LOOP: Descending loop over i: continues while the integer value of result is > 0; i decrements by one dword each pass. [source:raw]
    // CALL: Call StreamByteOutputWithBufferManagement(a1, a3, a4) each iteration, assigning its result. [callee:0x0058D78E]
    // GUARD: Sentinel termination: if the dword at a4 equals -1, break out of the loop. [source:raw]
    // ASSIGNMENT: If not terminated, result = i (the current pointer), then i steps back one dword. [source:raw]
    // RETURN: Return result: a2 if the loop never executed or terminated early, else the last accepted i. [source:raw]

    // Conservative worker pseudocode:
    //   result = a2;
    //   for (i = a2 - 1; (int)result > 0; i = i - 1) {
    //     result = StreamByteOutputWithBufferManagement(a1, a3, a4);
    //     if (*a4 == -1) break;
    //     result = i;
    //   }
    //   return result;
    // UNRESOLVED: What StreamByteOutputWithBufferManagement writes and what the -1 sentinel signifies in the a4 output dword are not established.
    // UNRESOLVED: The unsigned a1 byte role in the stream output call is unconfirmed.
    // UNRESOLVED: Why the initial pointer is a2-1 rather than a2 is unresolved; likely a pre-decrement idiom.
}
