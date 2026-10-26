// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567900
// Canonical corpus name: StructInitWithConditionalDefaultRead
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithConditionalDefaultRead_00567900.c

void UnknownObject::StructInitWithConditionalDefaultRead()
{
    // Initializes an 11-dword structure. Stores the incoming pointer a2 at this+0x0, zeroes this+0x4 through this+0x10 and this+0x18, this+0x24, this+0x28, and writes sentinel values -1 at this+0x14 and this+0x1C. If a2 is non-null, reads a value through FieldGetter_79d0(a2) into this+0x20, otherwise this+0x20 keeps the default -1. Returns the initialized this pointer. Called by FileDataProcessor, suggesting file/data-processing setup.
    // ASSIGNMENT: Seed the local default v3 with -1 before any conditional read. [source:raw]
    // ASSIGNMENT: Write the incoming pointer a2 into the first field at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the field at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the field at this+0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the field at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the field at this+0x10. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write the sentinel value -1 at this+0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zero the field at this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write the sentinel value -1 at this+0x1C. [field:this:0x0000001C, source:raw]
    // GUARD: Guard: the conditional field read runs only when a2 is non-null. [field:this:0x00000000, source:raw]
    // CALL: Call FieldGetter_79d0(a2) to read a value from the referenced object and store it in v3. [callee:0x004979D0, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write v3 (the field-get result, or the default -1 when a2 was null) at this+0x20. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Zero the field at this+0x24. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Zero the field at this+0x28. [field:this:0x00000028, source:raw]
    // RETURN: Return the initialized this pointer. [function:0x00567900, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_567900(_DWORD *this, _DWORD *a2) {
    //     int v3 = -1;
    //     this[4] = 0; this[5] = -1; this[6] = 0; this[7] = -1;
    //     *this = a2; this[1] = 0; this[2] = 0; this[3] = 0;
    //     if (a2) v3 = FieldGetter_79d0(a2);
    //     this[8] = v3; this[9] = 0; this[10] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The meaning of the sentinel -1 fields at this+0x14 and this+0x1C (e.g. default index or end marker) is not determinable from this function alone.
    // UNRESOLVED: What FieldGetter_79d0 reads from a2 and what this+0x20 represents depends on the owner class, only evidenced as called from FileDataProcessor.
    // UNRESOLVED: The exact semantics of the zeroed fields (counters, cursors, flags) are inferred from structure only.
}
