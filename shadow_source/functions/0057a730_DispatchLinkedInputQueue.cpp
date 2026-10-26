// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057A730
// Canonical corpus name: sub_57A730
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_57A730_0057a730.c

void UnknownObject::DispatchLinkedInputQueue()
{
    // Two-step dispatch helper. First walks a linked structure with LinkedListWalkWithInputDispatch, passing the incoming argument a2; then queues an async procedure call on the handle stored at this+0x0 with a null argument, and returns the result of that APC-queue call. Invoked by InputCommandDispatchToEntities, TeamRadioNetworkMessageProcessing and sub_463CA0.
    // CALL: LinkedListWalkWithInputDispatch(a2): walks a linked list and dispatches the incoming argument a2 [callee:0x00585320, source:raw]
    // CALL: QueueUserAPCAsyncProcedureCall(*this, 0): reads the APC target pointer from this+0x0 and queues it with a null second argument [callee:0x00585DE0, field:this:0x00000000, source:raw]
    // RETURN: Returns the result of the QueueUserAPCAsyncProcedureCall call [source:raw]
    // CALL: Used by InputCommandDispatchToEntities, TeamRadioNetworkMessageProcessing and sub_463CA0 as a two-step sub-call before returning [caller:0x0045F4A0, caller:0x0045F710, caller:0x00463CA0, abi:lead]

    // Conservative worker pseudocode:
    //   LinkedListWalkWithInputDispatch(a2);
    //   return QueueUserAPCAsyncProcedureCall(*this, 0);
    // UNRESOLVED: The purpose of the null second argument to the APC-queue call is unknown
    // UNRESOLVED: The owner class of this, and the meaning of the APC target stored at this+0x0, are unknown
}
