// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005599D0
// Canonical corpus name: sub_5599D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5599D0_005599d0.c

void UnknownObject::LookupResource()
{
    // Resource lookup indirection: when the global object dword_8B8F2C is non-null, forward (a1, a2, a3) to sub_5594B0 on that object and return its result. When the global object is missing, report the 'Could not find re...' message literal aCouldNotFindRe through sub_53C590 and return -1.
    // GUARD: If the global object pointer dword_8B8F2C is non-null, take the delegation path. [global:0x008B8F2C]
    // CALL: Delegate: call sub_5594B0((int*)dword_8B8F2C, a1, a2, a3) and return its result (returned by this function). [global:0x008B8F2C, source:raw]
    // RETURN: Return the delegated sub_5594B0 result on the success path. [source:raw]
    // CALL: Missing-object path: report the 'Could not find re...' message literal aCouldNotFindRe via sub_53C590(-1, aCouldNotFindRe). [callee:0x0053C590, global:0x005DC1D8]
    // RETURN: Return -1 when the global object dword_8B8F2C is missing. [source:raw]
    // CALL: Called by Steward_Setup (0x004D36D0) on the setup/startup path. [caller:0x004D36D0]

    // Conservative worker pseudocode:
    //   int LookupResource(const char* a1, int a2, int a3) {
    //     if (dword_8B8F2C)
    //       return sub_5594B0((int*)dword_8B8F2C, a1, a2, a3);
    //     sub_53C590(-1, "Could not find re...");
    //     return -1;
    //   }
    // UNRESOLVED: The delegated target sub_5594B0 appears in the raw source but is absent from the packet's callee list, so it cannot be cited as evidence here; its semantics are unknown.
    // UNRESOLVED: The full text of aCouldNotFindRe is truncated to 'Could not find re...' by the symbol; the completed message is not known from the packet.
    // UNRESOLVED: What dword_8B8F2C points to (the looked-up resource owner) is unknown.
}
