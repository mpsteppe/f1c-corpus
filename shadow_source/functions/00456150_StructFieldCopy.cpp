// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456150
// Canonical corpus name: StructFieldCopy
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructFieldCopy_00456150.c

void UnknownObject::StructFieldCopy()
{
    // Copies three consecutive DWORDs from source a2 into this at offsets 0x24, 0x28 and 0x2C (elements this[9], this[10], this[11]) when a2 is non-null, then returns the third source DWORD a2[2]. When a2 is null the fields are untouched and a2 (null) is returned.
    // GUARD: Guard on a2 being non-null; the copy is skipped entirely when a2 is null. [source:raw]
    // ASSIGNMENT: Copy the first source DWORD: this[9] = a2[0] (offset 0x24). [source:raw, field:this:0x00000024]
    // ASSIGNMENT: Copy the second source DWORD: this[10] = a2[1] (offset 0x28). [source:raw, field:this:0x00000028]
    // ASSIGNMENT: Copy the third source DWORD: this[11] = a2[2] (offset 0x2C) and return it. [source:raw, field:this:0x0000002C]
    // RETURN: Return a2[2] as the result (or a2, which is null, when the guard fails). [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *StructFieldCopy(_DWORD *this, _DWORD *a2) {
    //     if (a2) {
    //       this[9]  = a2[0];
    //       this[10] = a2[1];
    //       this[11] = a2[2];
    //     }
    //     return a2 ? a2 + 2 : a2;
    //   }
    // UNRESOLVED: Field semantics of offsets 0x24/0x28/0x2C are unknown; callers include ComponentTransformInitializer (0x00459010) and SuspensionWheelForceCalculation (0x00459070), suggesting transform/vector-like data, but the owning struct is unknown.
}
