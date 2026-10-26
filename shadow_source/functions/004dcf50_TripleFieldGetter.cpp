// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DCF50
// Canonical corpus name: TripleFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldGetter_004dcf50.c

void UnknownObject::TripleFieldGetter()
{
    // Getter that copies three dword fields of the object (+0x08, +0x0C, +0x10) into output pointers a2, a3 and a4 respectively, skipping any null output pointer. Returns a4 as the result. __thiscall.
    // GUARD: Guard: if a2 is non-null, copy the field; otherwise skip the first output. [source:raw]
    // ASSIGNMENT: Copy this[2] at offset +0x08 into *a2. [field:this:0x00000008, source:raw]
    // GUARD: Guard: if a3 is non-null, copy the field; otherwise skip the second output. [source:raw]
    // ASSIGNMENT: Copy this[3] at offset +0x0C into *a3. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Seed the result with a4 before checking it for null. [source:raw]
    // GUARD: Guard: if a4 is non-null, copy the field; otherwise leave the third output untouched. [source:raw]
    // ASSIGNMENT: Copy this[4] at offset +0x10 into *a4. [field:this:0x00000010, source:raw]
    // RETURN: Return a4 as the function result. [source:raw]
    // CALL: Called by UICursorSelectionRectangleRenderWithInterpolatio (0x0045B660) and TextRenderDispatcher (0x004DD030) to fetch the X/Y/Z fields of the object. [caller:0x0045B660, caller:0x004DD030, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_4DCF50(_DWORD *self, _DWORD *a2, _DWORD *a3, _DWORD *a4) {
    //     if (a2) *a2 = self[2];
    //     if (a3) *a3 = self[3];
    //     if (a4) *a4 = self[4];
    //     return a4;
    //   }
    // UNRESOLVED: Object type is unknown; the meanings of +0x08/+0x0C/+0x10 (X, Y, Z/size per the skeleton) depend on the calling context.
}
