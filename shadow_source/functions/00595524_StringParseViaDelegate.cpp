// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595524
// Canonical corpus name: StringParseViaDelegate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringParseViaDelegate_00595524.c

void UnknownObject::StringParseViaDelegate()
{
    // Trivial __cdecl forwarder that delegates to sub_5953B8, forwarding the two caller arguments (an unsigned 16-bit input pointer and an unsigned 32-bit pointer) plus the global context pointer dword_5E99A0 as a third argument, and returns the callee's result unchanged. The packet's deterministic naming suggests a string-parse path routed through a global callback/context delegate.
    // CALL: Delegate: call sub_5953B8(a1, a2, dword_5E99A0), forwarding both caller arguments plus the global context pointer dword_5E99A0 as a third argument. [callee:0x005953B8, global:0x005E99A0, source:raw]
    // RETURN: Return the callee's return value unchanged. [function:0x00595524, callee:0x005953B8, source:raw]
    // CALL: Invoked by EncodingLocaleDetectionFromParseResult (0x0058E12E) and BufferFormatHelper (0x00595550). [caller:0x0058E12E, caller:0x00595550]

    // Conservative worker pseudocode:
    //   return sub_5953B8(a1, a2, dword_5E99A0);
    // UNRESOLVED: The role of the third argument dword_5E99A0 (a parser context, format selector, or callback) is not evident from the raw source; only its address is deterministic.
    // UNRESOLVED: Whether the two pointer arguments are input/output or input/input is inferred from their parameter types only.
}
