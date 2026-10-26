// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563260
// Canonical corpus name: NetworkConnection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkConnection_00563260.c

void UnknownObject::NetworkConnection()
{
    // Network session connection handling. Parses a server address string with inet_addr, then resolves a server entry by ID via TwoStepDispatch. When the socket array already exists (a1[0] != 0) it either counts a display-mode query (incrementing a1[38] when the array state is 1 or 2) or, on a valid entry lookup, retags the entry (stores a5 at +8, literal 9999 into the +6 word), clears a matched struct field in the a1[2] array, pushes to the audio stack, removes the entry from the array and decrements a1[28]. When the socket array does not exist it creates it with SocketArrayCreate, processes the server entry (conditional dispatch, or tag + removal + single-function call), recomputes a1[28] as the array count minus one, resets a1[29], signals state via AudioValueSetterCall(3), and enters the polling loop unless a4 is set.
    // CALL: Validate/convert the server address string a2 via inet_addr. [callee:0x00598666, source:raw]
    // CALL: v6 = a3; v7 = TwoStepDispatch(a1, a3) resolves the server entry by ID a3. [callee:0x005631A0, source:raw]
    // GUARD: Branch on *a1: non-zero means the socket array already exists (handling path); zero means initialization path. [source:raw]
    // CALL: Existing-array path, lookup failed (v7 == -1): DisplayModeQueryWrapper(v6, a1[28], a5) allocates a struct and pushes it to the display/audio queue. [callee:0x005633D0, source:raw]
    // STATE_TRANSITION: If *a1 == 1 or *a1 == 2, increment a1[38] (display-mode query counter) and return 0. [source:raw]
    // CALL: Existing-array path, lookup ok: v9 = LinearInterpolation(a1[1], v7) fetches the array element, v11 = *v9 is the entry address. [callee:0x005648B0, source:raw]
    // GUARD: Only process the entry when the resolved index v7 is below the live count a1[28]. [source:raw]
    // ASSIGNMENT: Tag the entry: *(_DWORD*)(v11 + 8) = a5 and *(_WORD*)(a3 + 6) = 9999. [source:raw]
    // CALL: v12 = ArrayOfStructStrideSearchByID(a1, a3); if v12 != -1 set *(_DWORD*)(a1[2] + 28 * v12 + 4) = 0 to clear the matched struct field. [callee:0x00563230, source:raw]
    // CALL: AudioStackPushWithOverflowRealloc(a1[28]), then ArrayElementRemovalWithShift(a1[1], v7) removes the entry and --a1[28] decrements the count. [callee:0x005648D0, callee:0x00564990, source:raw]
    // CALL: Initialization path: result = SocketArrayCreate(a1); if it fails (non-zero) return it immediately. [callee:0x00562D20, source:raw]
    // CALL: Initialization path, lookup failed: ConditionalNetworkUtility(a1, v6, a5) allocates and dispatches the network struct. [callee:0x00563160, source:raw]
    // CALL: Initialization path, lookup ok: a3 = *(_DWORD*)LinearInterpolation(a1[1], v7); tag it (+8 = a5, +6 word = 9999); ArrayElementRemovalWithShift(a1[1], v7); SingleFunctionCallWrapper_48c0(a1[1], &a3) invokes the entry's function pointer. [callee:0x005648B0, callee:0x00564990, callee:0x005648C0, source:raw]
    // ASSIGNMENT: a1[28] = sub_563E70(a1[1]) - 1 (array count minus one) and a1[29] = 0. [callee:0x00563E70, source:raw]
    // CALL: AudioValueSetterCall(a1, 3) signals a connection-state change with value 3. [callee:0x00562FE0, source:raw]
    // CALL: If a4 is zero, PollingLoopWithProcessCalls(a1) enters the network polling loop, then returns 0. [callee:0x00563000, source:raw]
    // RETURN: All paths ultimately return 0 (or the SocketArrayCreate failure result). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_563260(DWORD* a1, const char* a2, int a3, int a4, int a5) {
    //     inet_addr(a2);
    //     int v6 = a3;
    //     int v7 = TwoStepDispatch(a1, a3);
    //     if (*a1) {
    //       if (v7 == -1) {
    //         DisplayModeQueryWrapper(v6, a1[28], a5);
    //         if (*a1 == 1 || *a1 == 2) { ++a1[38]; return 0; }
    //       } else if (v7 < a1[28]) {
    //         int* v9 = (int*)LinearInterpolation(a1[1], v7);
    //         int v11 = *v9;
    //         *(DWORD*)(v11 + 8) = a5; *(WORD*)(v11 + 6) = 9999;
    //         int v12 = ArrayOfStructStrideSearchByID((int)a1, v11);
    //         if (v12 != -1) *(DWORD*)(a1[2] + 28 * v12 + 4) = 0;
    //         AudioStackPushWithOverflowRealloc(a1[28]);
    //         ArrayElementRemovalWithShift(a1[1], v7);
    //         --a1[28];
    //       }
    //     } else {
    //       int r = SocketArrayCreate(a1); if (r) return r;
    //       if (v7 == -1) ConditionalNetworkUtility(a1, v6, a5);
    //       else {
    //         int e = *(int*)LinearInterpolation(a1[1], v7);
    //         *(DWORD*)(e + 8) = a5; *(WORD*)(e + 6) = 9999;
    //         ArrayElementRemovalWithShift(a1[1], v7);
    //         SingleFunctionCallWrapper_48c0(a1[1], &e);
    //       }
    //       a1[28] = sub_563E70(a1[1]) - 1;
    //       a1[29] = 0;
    //       AudioValueSetterCall((int)a1, 3);
    //       if (!a4) { PollingLoopWithProcessCalls(a1); return 0; }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The packet carries no field or global evidence refs; the a1[] indices (0, 1, 2, 28, 29, 38) and the +8 / +6 / +28*v12+4 sub-fields are read directly from the decompiled body and their concrete struct roles are unverified.
    // UNRESOLVED: The semantics of the literals: 9999 stored into the entry +6 word and value 3 passed to AudioValueSetterCall are not established.
    // UNRESOLVED: The relationship between a1[28] (live count) and a1[1] (element array) plus sub_563E70's array-count role is inferred, not confirmed.
    // UNRESOLVED: Recorded single caller DirectoryStringProcessingWithDecode (00461ed0) and the legacy ABI Network_Connection_Session_Management; frame-path membership is NOT_FOUND.
}
