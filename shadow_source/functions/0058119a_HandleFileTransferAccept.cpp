// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058119A
// Canonical corpus name: NetworkFileTransferAcceptHandler
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NetworkFileTransferAcceptHandler_0058119a.c

void UnknownObject::HandleFileTransferAccept()
{
    // Accept/reject handler for a file transfer request: acquires the mutex handle at this+0x640 (with timeout this+0x644) if present, then evaluates the accept/reject condition via NegatedPredicate(a2, a3). On the reject branch it releases the mutex and returns 0; on the accept branch it increments a counter via CounterIncrementDecrementByFlag(1), releases the mutex, calls sub_57E280(this, 1.0) to initiate transfer processing, and returns 1. The mutex at this+0x640 is released on both paths.
    // GUARD: If the mutex handle at this+0x640 is non-null, acquire it via WaitForSingleObject with timeout value this+0x644 [field:this:0x00000640, field:this:0x00000644, global:0x0059E1A0, source:raw]
    // CALL: Evaluate the accept/reject condition via NegatedPredicate(a2, a3): true selects the reject branch, false selects the accept branch [callee:0x00587100, source:raw]
    // STATE_TRANSITION: Reject branch: release the mutex handle at this+0x640 with ReleaseMutex if non-null, then return 0 [global:0x0059E1A4, field:this:0x00000640, function:0x0058119A, source:raw]
    // CALL: Accept branch: increment the transfer counter via CounterIncrementDecrementByFlag(1) [callee:0x00587230, source:raw]
    // GUARD: Accept branch: release the mutex handle at this+0x640 with ReleaseMutex if non-null [global:0x0059E1A4, field:this:0x00000640, source:raw]
    // CALL: Accept branch: invoke sub_57E280(this, 1.0) to initiate transfer processing [callee:0x0057E280, source:raw]
    // RETURN: Return 1 on the accept branch, 0 on the reject branch [function:0x0058119A, source:raw]

    // Conservative worker pseudocode:
    //   char HandleFileTransferAccept(this, a2, a3) {
    //     void* mutex = (void*)this[400];            // this+0x640
    //     if (mutex)
    //       WaitForSingleObject(mutex, this[401]);   // this+0x644 timeout
    //     if (NegatedPredicate(a2, a3)) {
    //       if (mutex)
    //         ReleaseMutex(mutex);
    //       return 0;                                // reject
    //     } else {
    //       CounterIncrementDecrementByFlag(1);
    //       if (mutex)
    //         ReleaseMutex(mutex);
    //       sub_57E280(this, 1.0);
    //       return 1;                                // accept
    //     }
    //   }
    // UNRESOLVED: Hex-Rays reports a positive sp value at function exit, so the exact stack cleanup of the calls is uncertain
    // UNRESOLVED: The semantics of arguments a2/a3 and the NegatedPredicate accept/reject criterion are not established
    // UNRESOLVED: Owner is unconfirmed; the ABI lead names a network file transfer accept handler (LEGACY)
}
