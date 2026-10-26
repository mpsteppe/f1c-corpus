// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562C90
// Canonical corpus name: DeviceInitializationWithStateSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DeviceInitializationWithStateSetup_00562c90.c

void UnknownObject::DeviceInitializationWithStateSetup()
{
    // Initializes a device/session object a1 through a staged sequence of sub-calls. Returns 4 immediately when the object's first dword (offset 0x0) is already nonzero. Otherwise stores the state code a4 at dword index 36 (byte offset 0x90), runs sub_562D90(a1) then sub_562E30(a1, a3); when those succeed and a4 is 6 or 7, or SocketArrayCreate(a1) succeeds, zeroes dword indices 28 and 29 (byte offsets 0x70 and 0x74), stores SingleDelegationCall(a1) at dword index 38 (byte offset 0x98), sets dword index 343 (byte offset 0x55C) to -1, and when a2 is zero enters PollingLoopWithProcessCalls(a1). Returns 0 on success, otherwise the failing sub-call result.
    // GUARD: If the object's first dword (byte offset 0x0) is nonzero, return 4 immediately, treating the object as already initialized. [source:raw]
    // ASSIGNMENT: Store the state code a4 at dword index 36 (byte offset 0x90). [source:raw]
    // CALL: Call sub_562D90(a1); a zero result gates the rest of the initialization. [callee:0x00562D90, source:raw]
    // CALL: Call sub_562E30(a1, a3); a zero result gates the state-setup block. [callee:0x00562E30, source:raw]
    // GUARD: Proceed into the state-setup block when a4 is 6 or 7, or when SocketArrayCreate(a1) returns zero (success); otherwise propagate the failure result. [callee:0x00562D20, source:raw]
    // ASSIGNMENT: Zero dword indices 28 and 29 (byte offsets 0x70 and 0x74). [source:raw]
    // CALL: Store the result of SingleDelegationCall(a1) at dword index 38 (byte offset 0x98). [callee:0x00563EB0, source:raw]
    // ASSIGNMENT: Set dword index 343 (byte offset 0x55C) to -1. [source:raw]
    // CALL: When a2 is zero, enter PollingLoopWithProcessCalls(a1), a blocking processing loop. [callee:0x00563000, source:raw]
    // RETURN: Return 0 on success, otherwise the failing sub-call result. [function:0x00562C90, source:raw]
    // CALL: Invoked by InitWrapper (00562C80). [caller:0x00562C80]

    // Conservative worker pseudocode:
    //   if (*a1 != 0) return 4;
    //   a1[36] = a4;
    //   result = sub_562D90(a1);
    //   if (result == 0) {
    //     result = sub_562E30(a1, a3);
    //     if (result == 0 && (a4 == 6 || a4 == 7 || (result = SocketArrayCreate(a1)) == 0)) {
    //       a1[28] = 0;
    //       a1[29] = 0;
    //       a1[38] = SingleDelegationCall(a1);
    //       a1[343] = -1;
    //       if (a2 == 0) PollingLoopWithProcessCalls(a1);
    //       return 0;
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The roles of sub_562D90 and sub_562E30 are not documented; only that each returns zero on success.
    // UNRESOLVED: The semantics of the stored state at dword indices 36, 28, 29, 38 and 343 are not derivable from this packet.
    // UNRESOLVED: A cluster-copy prelabel flags a structural twin at 00405160, but that comparison is not analyzed in this packet.
    // UNRESOLVED: Owner object identity is not established by the packet.
}
