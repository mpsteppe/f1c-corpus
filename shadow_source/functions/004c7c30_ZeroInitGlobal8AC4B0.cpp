// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7C30
// Canonical corpus name: SingleFunctionCallWrapper_7c30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_7c30_004c7c30.c

void UnknownObject::ZeroInitGlobal8AC4B0()
{
    // One-call wrapper that zero-initializes four consecutive dwords at the global flt_8AC4B0 via ZeroInit4Ints and returns the resulting pointer.
    // CALL: Invoke ZeroInit4Ints on the address of the global flt_8AC4B0. [function:0x004C7C30, global:0x008AC4B0, source:raw]
    // RETURN: Return the pointer returned by ZeroInit4Ints (the zero-initialized global region). [function:0x004C7C30, source:raw]

    // Conservative worker pseudocode:
    //   return ZeroInit4Ints(&flt_8AC4B0);
    // UNRESOLVED: ZeroInit4Ints is invoked by the raw source but is not present in the packet callees list; its semantics are inferred from its name only.
    // UNRESOLVED: Whether flt_8AC4B0 is an actual float value or a reinterpreted dword region is unknown from the packet alone.
}
