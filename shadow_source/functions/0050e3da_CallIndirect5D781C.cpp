// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E3DA
// Canonical corpus name: ThunkToFUN0050e3cd
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN0050e3cd_0050e3da.c

void UnknownObject::CallIndirect5D781C()
{
    // Return thunk that calls through the function pointer stored in the global off_5D781C (0x005D781C) with no arguments and returns its result unchanged. The packet records the pointer as read-only (R) and carries no callee-address evidence, so the dispatched target is resolved at runtime. Called by F_4x4MatrixReflectionTransform (0x0050F0BF) and sub_50F199 (0x0050F199), suggesting a shared indirect math dispatch.
    // CALL: Indirect call through the function pointer read from off_5D781C (global 0x005D781C); the decompiled source passes no arguments [global:0x005D781C, source:raw]
    // RETURN: Return the indirect call's result unchanged (return thunk) [function:0x0050E3DA, source:raw]
    // CALL: Invoked by F_4x4MatrixReflectionTransform (0x0050F0BF) and sub_50F199 (0x0050F199) [caller:0x0050F0BF, caller:0x0050F199, source:raw]

    // Conservative worker pseudocode:
    //   int CallIndirect5D781C()
    //   {
    //       return off_5D781C();
    //   }
    // UNRESOLVED: The identity and signature of the function whose address resides in global off_5D781C are outside this packet's evidence; it is read-only, so this is a dispatch/forward thunk.
    // UNRESOLVED: The 'ThunkToFUN0050e3cd' canonical name implies a companion at a lower address, but that address is not present as a hex literal in the packet and is not asserted here.
}
