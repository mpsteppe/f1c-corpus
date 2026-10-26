// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00547240
// Canonical corpus name: sub_547240
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_547240_00547240.c

void UnknownObject::SetDimensionsAndUpdateFlag()
{
    // Validates and stores two WORD dimension fields on `this`: a2 into this+0xAC and a3 into this+0xAE, each only when in the inclusive range [1,8]. Unless the specific pair (a2==2 && a3==1) is present, sets flag bit 5 (0x20) at this+0x9C. Returns a3 as the result value.
    // GUARD: Guard on a2 in [1,8]; only then write WORD a2 at this+0xAC. [field:this:0x000000AC, source:raw]
    // ASSIGNMENT: Initialize result to a3 before validation. [source:raw]
    // GUARD: Guard on a3 in [1,8]; only then write WORD a3 at this+0xAE. [field:this:0x000000AE, source:raw]
    // GUARD: Guard on NOT (a2==2 && a3==1): when the pair is anything else, OR bit 5 (0x20) into the DWORD flag at this+0x9C. [field:this:0x0000009C, source:raw]
    // RETURN: Return a3. Called by DirectXMeshVertexBufferParsingAndLoading (00547B40), D3DTextureResourceCreation (00548190) and sub_557CE0. [source:raw, caller:0x00547B40, caller:0x00548190, caller:0x00557CE0]

    // Conservative worker pseudocode:
    //   int __thiscall sub_547240(int this, int a2, int a3) {
    //     if (a2 >= 1 && a2 <= 8) *(WORD *)(this + 0xAC) = a2;
    //     int result = a3;
    //     if (a3 >= 1 && a3 <= 8) *(WORD *)(this + 0xAE) = a3;
    //     if (a2 != 2 || a3 != 1) *(DWORD *)(this + 0x9C) |= 0x20;
    //     return result;
    //   }
    // UNRESOLVED: Class identity of `this` and the meaning of the [1,8] dimension range are unproven; the D3D/mesh callers suggest texture or mesh resource sizing but that is not confirmed.
    // UNRESOLVED: Semantics of the (2,1) dimension pair that suppresses the 0x20 flag are not documented.
    // UNRESOLVED: The 0x20 flag bit at this+0x9C has no known consumer here.
}
