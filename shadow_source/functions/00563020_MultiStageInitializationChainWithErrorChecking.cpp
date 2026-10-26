// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00563020
// Canonical corpus name: MultiStageInitializationChainWithErrorChecking
// Owner: NetworkSocketManager [DERIVED]
// Raw source: functions/MultiStageInitializationChainWithErrorChecking_00563020.c

void NetworkSocketManager::MultiStageInitializationChainWithErrorChecking()
{
    // Multi-stage network-socket initialisation chain with error propagation. If the socket-array state is already initialised (first DWORD non-zero) it returns 4 immediately. Otherwise it creates the socket array, creates a UDP broadcast socket, and runs a follow-up setup stage; each stage returns early on failure. On full success it clears two state DWORDs at a1[28] and a1[29], and unless a2 is non-zero, enters PollingLoopWithProcessCalls.
    // GUARD: Guard: if *a1 is non-zero (socket-array state already initialised), return 4 immediately. [function:0x00563020, source:raw]
    // CALL: Call SocketArrayCreate(a1) and store the result as the chain status. [callee:0x00562D20]
    // GUARD: Guard: if the SocketArrayCreate result is non-zero, propagate that result as the return value. [callee:0x00562D20, source:raw]
    // CALL: Call CreateUdpBroadcastSocket(a1) and store the result as the chain status. [callee:0x00563080]
    // GUARD: Guard: if the CreateUdpBroadcastSocket result is non-zero, propagate that result as the return value. [callee:0x00563080, source:raw]
    // CALL: Call sub_5630D0(a1, a3, a4, a5) to run the follow-up setup stage and store its result. [callee:0x005630D0]
    // GUARD: Guard: if the sub_5630D0 result is non-zero, propagate that result as the return value. [callee:0x005630D0, source:raw]
    // ASSIGNMENT: Clear initialisation/state markers: a1[28] = 0 and a1[29] = 0 on the success path. [source:raw]
    // GUARD: Guard: if a2 is zero, call PollingLoopWithProcessCalls(a1); a non-zero a2 skips the polling loop. [callee:0x00563000, source:raw]
    // RETURN: Return 0 on the fully-successful path; otherwise return the stored non-zero stage result. [function:0x00563020, source:raw]

    // Conservative worker pseudocode:
    //   if (*a1) return 4;
    //   result = SocketArrayCreate(a1);
    //   if (!result) {
    //     result = CreateUdpBroadcastSocket(a1);
    //     if (!result) {
    //       result = sub_5630D0(a1, a3, a4, a5);
    //       if (!result) {
    //         a1[28] = 0;
    //         a1[29] = 0;
    //         if (!a2) PollingLoopWithProcessCalls(a1);
    //         return 0;
    //       }
    //     }
    //   }
    //   return result;
    // UNRESOLVED: Meaning of the early-return literal 4 and of a1[28]/a1[29] (state markers) is not resolved.
    // UNRESOLVED: Purpose of a2 (skips the polling loop when non-zero) is not established from this packet alone.
    // UNRESOLVED: sub_5630D0, SocketArrayCreate, CreateUdpBroadcastSocket and PollingLoopWithProcessCalls bodies are out of scope here.
}
