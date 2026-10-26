// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058A6D5
// Canonical corpus name: StreamMagicNumberCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamMagicNumberCheck_0058a6d5.c

void UnknownObject::StreamMagicNumberCheck()
{
    // Magic-number dispatch check on a double-indirect pointer: dereferences a1 to obtain an object pointer (this:0x0), compares the object's first DWORD (obj:0x0) against magic -529697949 (0xE06D7363). On match it dispatches to an SEH wrapper handler function and returns its result; otherwise returns 0. Called by stream-parse and SEH-aware virtual call dispatch paths.
    // GUARD: Double-dereference a1: object pointer read from this:0x0, then compare the object's first DWORD at obj:0x0 for equality with magic -529697949 (0xE06D7363). [guard:0, field:this:0x00000000, field:obj:0x00000000, source:raw]
    // CALL: On magic match, dispatch to the SEH wrapper handler function and return its result (call target not statically resolved in this packet). [function:0x0058A6D5, source:raw]
    // RETURN: Return 0 when the magic check fails (no dispatch). [source:raw]

    // Conservative worker pseudocode:
    //   if (**a1 == 0xE06D7363)
    //       return SEHWrapperDispatchingToHandlerFunction();
    //   return 0;
    // UNRESOLVED: Call target of SEHWrapperDispatchingToHandlerFunction is not present as a callee in the packet; the dispatch is source-backed only.
    // UNRESOLVED: obj:0x0 and this:0x0 alias at the same offset because of the double dereference; the base split is inferred from the source text.
}
