// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053ACF0
// Canonical corpus name: ThinWrapperDropsA1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThinWrapperDropsA1_0053acf0.c

void UnknownObject::ThinWrapperDropsA1()
{
    // Thin __cdecl wrapper that discards its first argument a1 and forwards the remaining three (a2, a3, a4) unchanged to sub_55EE20, returning sub_55EE20's result directly.
    // CALL: Call sub_55EE20 with forwarded arguments a2, a3, a4; the original first argument a1 is dropped. [callee:0x0055EE20, source:raw]
    // RETURN: Return the value produced by sub_55EE20 unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_53ACF0(int a1, int a2, int a3, int a4) {
    //     return sub_55EE20(a2, a3, a4);
    //   }
    // UNRESOLVED: Purpose and ownership of the dropped first argument a1 are caller-supplied and unknown here.
    // UNRESOLVED: Semantics of sub_55EE20 and the meaning of a2, a3, a4 depend on its implementation.
}
