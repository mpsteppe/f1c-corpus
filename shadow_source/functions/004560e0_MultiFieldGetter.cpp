// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004560E0
// Canonical corpus name: MultiFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldGetter_004560e0.c

void UnknownObject::MultiFieldGetter()
{
    // Conditional multi-field getter. Copies three consecutive dword fields of the `this` object at offsets 0x64, 0x68 and 0x6C into the caller-provided output pointers a2, a3 and a4 respectively, each write guarded by its output pointer being non-null. Returns a4 (the third output pointer) regardless of whether any write occurred.
    // GUARD: Guard on output pointer a2 being non-null before the first write. [source:raw]
    // ASSIGNMENT: Copy the field at offset 0x64 (this[25]) into *a2. [field:this:0x00000064, source:raw]
    // GUARD: Guard on output pointer a3 being non-null before the second write. [source:raw]
    // ASSIGNMENT: Copy the field at offset 0x68 (this[26]) into *a3. [field:this:0x00000068, source:raw]
    // ASSIGNMENT: Initialize the return value to a4. [source:raw]
    // GUARD: Guard on output pointer a4 being non-null before the third write. [source:raw]
    // ASSIGNMENT: Copy the field at offset 0x6C (this[27]) into *a4. [field:this:0x0000006C, source:raw]
    // RETURN: Return the a4 output pointer. [source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_4560E0(Obj *this, DWORD *out64, DWORD *out68, DWORD *out6C) {
    //     if (out64) *out64 = this[25];
    //     if (out68) *out68 = this[26];
    //     if (out6C) *out6C = this[27];
    //     return out6C;
    //   }
    // UNRESOLVED: Semantic meaning of the three consecutive fields at offsets 0x64/0x68/0x6C is not determinable from this function alone.
    // UNRESOLVED: Owner object behind `this` is unknown; six callers suggest a shared transform-like object but that is not established by this packet.
}
