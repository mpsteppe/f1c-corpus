// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00456080
// Canonical corpus name: ShortComputation_6080
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_6080_00456080.c

void UnknownObject::CopyTwoFieldsNullable()
{
    // Copies two dword fields of the receiver to caller-provided output pointers. Field this[16] (byte offset 0x40) is written to *a2 and field this[17] (byte offset 0x44) to *a3, each guarded by a null check on the output pointer. Returns a3 (the second output pointer). Pure read/copy getter with no side effects; called from camera and car-selection paths.
    // GUARD: a2 is a nullable output pointer; the write to *a2 is skipped when a2 is null. [source:raw]
    // ASSIGNMENT: Copy this[16] (field at byte offset 0x40) into *a2. [field:this:0x00000040, source:raw]
    // GUARD: a3 is a nullable output pointer; the write to *a3 is skipped when a3 is null. [source:raw]
    // ASSIGNMENT: Copy this[17] (field at byte offset 0x44) into *a3. [field:this:0x00000044, source:raw]
    // RETURN: Return a3 (the second output pointer) as the result. [source:raw, function:0x00456080]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[16];   // this+0x40
    //   if (a3) *a3 = this[17];   // this+0x44
    //   return a3;
    // UNRESOLVED: The semantic meaning of the two fields at offsets 0x40 and 0x44 is not established by the packet; they are only known to be read and exported.
    // UNRESOLVED: Owner object is unknown; callers span camera (0x00408E20, 0x00409A00, 0x0040ADB0, 0x0040B710) and car-selection (0x00434460) paths, so the receiver type is not determined.
    // UNRESOLVED: The legacy name 'ShortComputation_456080' and the fill name 'FieldGetter_0x40_0x44' are consistent with a getter, but that is labeling, not independent evidence.
}
