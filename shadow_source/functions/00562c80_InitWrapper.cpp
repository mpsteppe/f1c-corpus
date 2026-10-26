// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562C80
// Canonical corpus name: InitWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InitWrapper_00562c80.c

void UnknownObject::InitWrapper()
{
    // Trivial forwarding stub: calls DeviceInitializationWithStateSetup(0, 5) and returns its result verbatim. No arguments, no fields, no globals. Called from StartNetworkUpdate (0x00461DE0).
    // CALL: Call DeviceInitializationWithStateSetup (0x00562C90) with constant arguments device index 0 and state 5. Recorded caller is StartNetworkUpdate (0x00461DE0). [callee:0x00562C90, caller:0x00461DE0, function:0x00562C80, source:raw]
    // RETURN: Return the result of DeviceInitializationWithStateSetup unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int InitWrapper() {
    //       return DeviceInitializationWithStateSetup(0, 5);
    //   }
    // UNRESOLVED: Semantics of the state parameter literal 5 are not established.
    // UNRESOLVED: What 'device' the literal 0 selects is not established.
}
