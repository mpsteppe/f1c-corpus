// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x008D903C
// Canonical corpus name: nullsub_134
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/nullsub_134_008d903c.c

void UnknownObject::nullsub_134()
{
    // Null subroutine with an empty body that returns immediately. The Hex-Rays expression `return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)()` is an artifact of a bare return instruction, not a real indirect call.
    // RETURN: Function contains no body and returns immediately; canonical name nullsub_134 marks a no-op subroutine. [function:0x008D903C]
    // UNKNOWN: The `return MK_FP(*(_WORD *)retaddr, *(_DWORD *)retaddr)()` expression in the raw source is a Hex-Rays decompiler rendering artifact of a bare `ret`; no actual indirect call is performed. [source:raw]

    // Conservative worker pseudocode:
    //   return;  // empty body (null subroutine)
    // UNRESOLVED: True purpose of the null subroutine (which call site relies on it) is unknown; the packet records no callers.
}
