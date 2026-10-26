// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059553A
// Canonical corpus name: DelegationWithStaticData
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DelegationWithStaticData_0059553a.c

void UnknownObject::DelegationWithStaticData()
{
    // Thin __cdecl delegation wrapper: forwards a1 and a2 to sub_5953B8 together with a third argument read from global dword_5E99B8, returning the callee's result unchanged.
    // CALL: Call sub_5953B8(a1, a2, dword_5E99B8) and return its value. [callee:0x005953B8, global:0x005E99B8, source:raw]
    // RETURN: Return the result of the delegated call unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_59553A(unsigned __int16 *a1, unsigned int *a2) {
    //     return sub_5953B8(a1, a2, dword_5E99B8);
    //   }
    // UNRESOLVED: Semantics of the delegate sub_5953B8 and the meaning of dword_5E99B8 are unknown from this packet alone.
    // UNRESOLVED: Caller StringParseWithFormat (0x0059557D) suggests a string-parsing context, but the protocol is unresolved here.
    // UNRESOLVED: Return type int is an artifact of the decompiler signature; actual value semantics depend on sub_5953B8.
}
