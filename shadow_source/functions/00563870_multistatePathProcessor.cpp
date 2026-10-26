// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563870
// Canonical corpus name: sub_563870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_563870_00563870.c

void UnknownObject::multistatePathProcessor()
{
    // Three-state path-segment processor driven by the state field at a1+1460. State 0 initializes: PathBackslashCounter(3) validates the path shape, a sub-path is copied into a stack buffer with sub_587DD0, the global entry count dword_8CFA88 is set via SingleFunctionCallWrapper_7f59 and rejected if above 20, the state advances to 1, and the global entry array dword_8CFA90 is zeroed for the counted entries. State 1 extracts a segment with PathBackslashCounter(2) and sub_587DD0, heap-copies it with StringMallocCopy, runs the segment through FunctionPointerCallWithErrorHandling against a callback pointer from a1+148, then stores the returned pointer in the first free slot of dword_8CFA90; when the array becomes full the state advances to 2. State 2 calls PathBackslashCounter(dword_8CFA88 + 1), invokes QueryWithContextCleanup with the accumulated count and a context value from a1+144, appends a backslash (0x5C) to the path at a2+v7-1, and invokes an indirect callback at a1+120 with arguments (a1, 2, *(a1+124), v9, 0). Returns the last backslash index minus one, 0 on PathBackslashCounter failure, or -1 on invalid state and threshold errors.
    // GUARD: Dispatch on the state field at a1+1460: 0 runs initialization, 1 runs segment extraction/storage, 2 runs query and final callback, and any other value returns -1. [source:raw]
    // CALL: State 0: PathBackslashCounter(3) counts backslashes in the path to validate its shape; -1 returns 0 and a count below 12 returns -1. [callee:0x00563A70, source:raw]
    // CALL: State 0: sub_587DD0(v18, a2 + 12, v16 - 12) copies the sub-path beginning after the twelfth path character into the stack buffer v18. [callee:0x00587DD0, source:raw]
    // ASSIGNMENT: State 0: dword_8CFA88 is set to the result of SingleFunctionCallWrapper_7f59(v18), establishing the global entry count; a count above 20 returns -1. [global:0x008CFA88, callee:0x00587F59, source:raw]
    // ASSIGNMENT: State 0: the state field at a1+1460 is set to 1, advancing to the segment-extraction state. [source:raw]
    // ASSIGNMENT: State 0: when dword_8CFA88 is positive, the global entry array dword_8CFA90 is cleared with memset over 4 * dword_8CFA88 bytes. [global:0x008CFA90, global:0x008CFA88, source:raw]
    // CALL: State 1: PathBackslashCounter(2) locates the current segment boundary; a result of -1 returns 0. [callee:0x00563A70, source:raw]
    // CALL: State 1: sub_587DD0(v18, a2 + 1, v10 - 2) copies the path segment into the stack buffer v18. [callee:0x00587DD0, source:raw]
    // CALL: State 1: StringMallocCopy(v18) heap-allocates and copies the segment, producing v12. [callee:0x00564690, source:raw]
    // CALL: State 1: FunctionPointerCallWithErrorHandling(v13, &a3) invokes the callback stored at a1+148, passing the copied segment and receiving a result in a3. [callee:0x00564780, source:raw]
    // LOOP: State 1: scans dword_8CFA90 from index 0 for the first free (zero) slot; running past dword_8CFA88 entries returns -1. [global:0x008CFA90, global:0x008CFA88, source:raw]
    // ASSIGNMENT: State 1: the callback result a3 is stored into dword_8CFA90 at the first free slot; when that slot is the last one (dword_8CFA88 - 1) the state field at a1+1460 advances to 2. [global:0x008CFA90, global:0x008CFA88, source:raw]
    // CALL: State 2: PathBackslashCounter(dword_8CFA88 + 1) re-measures the path with the accumulated entry count; a result of -1 returns 0. [callee:0x00563A70, global:0x008CFA88, source:raw]
    // CALL: State 2: QueryWithContextCleanup(dword_8CFA88, a2, *(a1+144)) processes all accumulated entries with the context value from a1+144, producing v9. [callee:0x00563A30, global:0x008CFA88, source:raw]
    // ASSIGNMENT: State 2: a backslash byte (0x5C) is written into the path at a2 + v7 - 1, appending the separator. [source:raw]
    // CALL: State 2: the indirect callback at a1+120 is invoked with (a1, 2, *(a1+124), v9, 0). [source:raw]
    // RETURN: Returns the backslash index minus one on each successful state path, 0 when PathBackslashCounter reports failure, and -1 on invalid states and count-threshold errors. [function:0x00563870, source:raw]

    // Conservative worker pseudocode:
    //   int multistatePathProcessor(int a1, int a2, int a3) {
    //     int state = *(int*)(a1 + 1460);
    //     if (state == 0) {
    //       int n = PathBackslashCounter(3);
    //       if (n == -1) return 0;
    //       if (n < 12) return -1;
    //       sub_587DD0(v18, a2 + 12, n - 12);
    //       dword_8CFA88 = SingleFunctionCallWrapper_7f59(v18);
    //       if (dword_8CFA88 > 20) return -1;
    //       *(int*)(a1 + 1460) = 1;
    //       if (dword_8CFA88 > 0) memset(dword_8CFA90, 0, 4 * dword_8CFA88);
    //       return n - 1;
    //     }
    //     if (state == 1) {
    //       int n = PathBackslashCounter(2);
    //       if (n == -1) return 0;
    //       sub_587DD0(v18, a2 + 1, n - 2);
    //       int seg = StringMallocCopy(v18);
    //       FunctionPointerCallWithErrorHandling(*(int*)(a1 + 148), &seg);
    //       int i = 0;
    //       if (dword_8CFA88 <= 0) return -1;
    //       while (dword_8CFA90[i]) if (++i >= dword_8CFA88) return -1;
    //       dword_8CFA90[i] = seg;
    //       if (i == dword_8CFA88 - 1) *(int*)(a1 + 1460) = 2;
    //       return n - 1;
    //     }
    //     if (state != 2) return -1;
    //     int n = PathBackslashCounter(dword_8CFA88 + 1);
    //     if (n == -1) return 0;
    //     int v9 = QueryWithContextCleanup(dword_8CFA88, a2, *(int*)(a1 + 144));
    //     *(byte*)(a2 + n - 1) = 0x5C;
    //     ((int(__cdecl*)(int,int,int,int,int))*(void**)(a1 + 120))(a1, 2, *(int*)(a1 + 124), v9, 0);
    //     return n - 1;
    //   }
    // UNRESOLVED: The object behind a1 (state field at +1460, callback at +120, context values at +144 and +148) is not identified; the packet lists no fields for it.
    // UNRESOLVED: The meaning of the globals dword_8CFA88 (entry count) and dword_8CFA90 (entry array) as a socket/entry collection is inferred from the state machine flow, not confirmed by independent evidence.
    // UNRESOLVED: What QueryWithContextCleanup resolves and what the a1+120 callback consumes is not established beyond the argument shapes seen here.
    // UNRESOLVED: The stack buffers v17 and v18 are NUL-terminated around the copied segments, but their exact role (path reconstruction) is inferred from the surrounding path calls.
}
