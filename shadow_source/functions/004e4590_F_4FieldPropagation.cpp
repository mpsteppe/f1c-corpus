// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E4590
// Canonical corpus name: F_4FieldPropagation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4FieldPropagation_004e4590.c

void UnknownObject::F_4FieldPropagation()
{
    // Propagate integer argument a2 into four mirrored fields of the this object at offsets 0x0, 0x6E4, 0x8 and 0x32C0, then return a2. Unconditional; synchronizes one value across four sub-structure slots (offsets 0x0 and 0x8 are directly indexed by the decompiler as this[0]/this[2], 0x6E4 as this[441], 0x32C0 as this[3248]).
    // ASSIGNMENT: result = a2: capture the input value for the return value. [source:raw]
    // ASSIGNMENT: *this = a2: write a2 into the field at offset 0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: this[441] = a2: write a2 into the field at offset 0x6E4 (441 * 4 bytes). [field:this:0x000006E4, source:raw]
    // ASSIGNMENT: this[2] = a2: write a2 into the field at offset 0x8 (2 * 4 bytes). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: this[3248] = a2: write a2 into the field at offset 0x32C0 (3248 * 4 bytes). [field:this:0x000032C0, source:raw]
    // RETURN: Return the original a2 value as the result. [function:0x004E4590, source:raw]
    // CALL: Called by LargeStructFieldSetterWithStoredReference (0x00424040) to propagate a stored reference/int across the four related fields. [caller:0x00424040, source:raw]

    // Conservative worker pseudocode:
    //   int F_4FieldPropagation(int this, int a2) {
    //     *(int*)this = a2;
    //     *(int*)(this + 0x6E4) = a2;
    //     *(int*)(this + 0x8) = a2;
    //     *(int*)(this + 0x32C0) = a2;
    //     return a2;
    //   }
    // UNRESOLVED: Semantic meaning of the four fields (offsets 0x0, 0x8, 0x6E4, 0x32C0) and why they mirror one value is not established here; existing analysis suggests sub-structure synchronization within a physics/tire subsystem.
    // UNRESOLVED: Meaning of a2 (whether an index, a reference, or a state value) depends on the caller at 0x00424040.
}
