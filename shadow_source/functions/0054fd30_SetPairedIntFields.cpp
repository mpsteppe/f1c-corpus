// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054FD30
// Canonical corpus name: ShortComputation_fd30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_fd30_0054fd30.c

void UnknownObject::SetPairedIntFields()
{
    // Trivial __thiscall setter: stores two integer parameters into consecutive dword fields at this+0x78 and this+0x7C and returns the first parameter unchanged. No guard, no branches, no calls. The five callers are render-state / vertex-buffer setup routines, consistent with a paired state-parameter setter used during graphics path setup.
    // ASSIGNMENT: Store first parameter a2 into this+0x78 (dword index 30). [source:raw, field:this:0x00000078]
    // ASSIGNMENT: Store second parameter a3 into this+0x7C (dword index 31). [source:raw, field:this:0x0000007C]
    // RETURN: Return a2 unchanged (kept in eax as the result of the previous store). [source:raw]
    // CALL: Applied by five setup callers to write paired state fields: sub_546F70, sub_546FE0, ConditionalRenderStateSetup, GuardedRenderStateSet and DirectXMeshVertexBufferParsingAndLoading. [caller:0x00546F70, caller:0x00546FE0, caller:0x00547040, caller:0x005470A0, caller:0x00547B40, source:raw]

    // Conservative worker pseudocode:
    //   int sub_54FD30(_DWORD* self, int a2, int a3) {
    //     int result = a2;
    //     self[30] = a2;   /* this+0x78 * /
    //     self[31] = a3;   /* this+0x7C * /
    //     return result;
    //   }
    // UNRESOLVED: The object type owning the this+0x78 / this+0x7C pair is unknown.
    // UNRESOLVED: Semantic meaning of a2 and a3 (what the paired values represent) depends on each caller's render-state usage.
    // UNRESOLVED: Why the first parameter is returned (chain value for the caller) is caller-dependent and not established.
}
