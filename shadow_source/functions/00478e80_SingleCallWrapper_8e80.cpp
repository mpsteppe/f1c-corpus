// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00478E80
// Canonical corpus name: SingleCallWrapper_8e80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleCallWrapper_8e80_00478e80.c

void UnknownObject::SingleCallWrapper_8e80()
{
    // Single-call passthrough wrapper. It forwards its one argument a1 unchanged to ObjectFieldInitWithIndirectLookup and returns that call's result directly. The legacy ABI note names the delegate target FUN_00499b80. Called from FilePathResolverWithExtensionAppend (0x004793EC), placing it on a file-path resolution path.
    // CALL: Delegate to ObjectFieldInitWithIndirectLookup(a1), forwarding the argument unchanged; the legacy ABI note identifies the delegate as FUN_00499b80. [abi:lead, function:0x00478E80, source:raw]
    // RETURN: Return the delegate's result directly (tail-call style); no post-processing occurs. [source:raw]
    // CALL: Invoked by FilePathResolverWithExtensionAppend (0x004793EC) as part of file-path resolution. [caller:0x004793EC]

    // Conservative worker pseudocode:
    //   int sub_478E80(int a1) {
    //     return ObjectFieldInitWithIndirectLookup(a1);
    //   }
    // UNRESOLVED: Identity and behavior of the delegate ObjectFieldInitWithIndirectLookup / FUN_00499b80 are not documented in the packet (no callee facts).
    // UNRESOLVED: The object field being initialized and the meaning of a1 depend entirely on the delegate and the caller's object state.
}
