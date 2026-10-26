// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055C9A0
// Canonical corpus name: MaskedFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MaskedFieldGetter_0055c9a0.c

void UnknownObject::MaskedFieldGetter()
{
    // Thiscall field getter with no side effects: reads the dword at offset 0x13A8 of `this` and returns it masked with 0xF1000. Called by D3DTextureCreation (0x00550080), likely to query a texture/resource capability or flag subset.
    // CALCULATION: Read the dword at this+0x13A8 (this[1258]) and mask it with 0xF1000 to isolate a flag subset. [field:this:0x000013A8, source:raw]
    // RETURN: Return the masked value; no other state is modified. [function:0x0055C9A0, source:raw]
    // CALL: Invoked by D3DTextureCreation (0x00550080) to read the masked flag field during texture creation. [caller:0x00550080]

    // Conservative worker pseudocode:
    //   int MaskedFieldGetter(_DWORD *this) {
    //     return this[1258] & 0xF1000;
    //   }
    // UNRESOLVED: Meaning of the specific bits isolated by 0xF1000 is not established here; it is consumed by D3DTextureCreation (0x00550080).
}
