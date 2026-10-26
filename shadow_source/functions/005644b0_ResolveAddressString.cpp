// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005644B0
// Canonical corpus name: sub_5644B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5644B0_005644b0.c

void UnknownObject::ResolveAddressString()
{
    // Resolves a network address or hostname into a string form. If the input name equals the aHostaddr literal (0x005E5064), the in_addr is formatted directly via IPAddressToString; otherwise the address is resolved through DoubleCallWrapper and the char* stored at offset 4 of its result object is returned, falling back to the a3 argument when that result is null.
    // GUARD: if (!strcmp(a2, aHostaddr)) — name equals the host-address literal [global:0x005E5064, source:raw]
    // RETURN: return IPAddressToString(a1) — format the in_addr as a string [callee:0x00564490, source:raw]
    // CALL: v4 = DoubleCallWrapper(a1) — resolve through the wrapper [callee:0x005644F0, source:raw]
    // GUARD: if (v4 != 0) — wrapper produced a non-null object [source:raw]
    // RETURN: return *(char **)(v4 + 4) — read the string pointer stored at offset 4 of the wrapper result [source:raw]
    // RETURN: return (char *)a3 — fall back to the caller-provided pointer [source:raw]

    // Conservative worker pseudocode:
    //   if (strcmp(a2, aHostaddr) == 0) return IPAddressToString(a1);
    //   v4 = DoubleCallWrapper(a1);
    //   if (v4) return *(char **)(v4 + 4);
    //   return (char *)a3;
    // UNRESOLVED: DoubleCallWrapper (0x005644F0) return type and the object layout at offset 4 are unknown
    // UNRESOLVED: aHostaddr (0x005E5064) literal contents and the comparison semantics are unknown
    // UNRESOLVED: a3 int being reinterpreted as a char* return value is unexplained
}
