// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058EF48
// Canonical corpus name: ConditionalFreeIfHandleNot1
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFreeIfHandleNot1_0058ef48.c

void UnknownObject::ConditionalFreeIfHandleNot1()
{
    // Cdecl helper that forwards to sub_596888(a1, a2) only when the handle argument a1 is not -1, matching the canonical name ConditionalFreeIfHandleNot1. The -1 sentinel therefore marks an invalid/absent handle for which the resource teardown must be skipped; on the -1 path the function falls through to a bare return whose result variable is left uninitialized in the decompiled text.
    // GUARD: If a1 != -1, call sub_596888(a1, a2); the -1 sentinel test is what the canonical name ConditionalFreeIfHandleNot1 describes. [function:0x0058EF48, source:raw]
    // CALL: Call sub_596888(a1, a2) with the forwarded arguments on the non-sentinel path. [callee:0x00596888, source:raw]
    // RETURN: Return the result of sub_596888(a1, a2) when the handle is valid; on the a1 == -1 path the function returns with the result variable uninitialized (decompiler artifact). [source:raw]

    // Conservative worker pseudocode:
    //   if (a1 != -1) {
    //     return sub_596888(a1, a2);
    //   }
    //   return;  // sentinel path: result uninitialized in raw source
    // UNRESOLVED: The uninitialized `result` on the a1 == -1 path is a Hex-Rays rendering artifact of a bare fall-through return; no real value is produced.
    // UNRESOLVED: The exact semantics of sub_596888 (resource teardown vs other handling) and the meaning of a2 are not evidenced beyond the call forwarding.
    // UNRESOLVED: Owner class is unknown; the packet records no owning type.
}
