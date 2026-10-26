// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B170
// Canonical corpus name: ThreeFieldAccessor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreeFieldAccessor_0053b170.c

void UnknownObject::ThreeFieldBatchGetter()
{
    // Reads three consecutive DWORD fields of the receiver object (offsets 0x4, 0x8, 0xC) and writes each into a caller-provided output pointer. Each write is individually gated: the field is only stored when its output pointer is non-null. Returns the a4 output pointer. There is no early return; the three null-checks are independent.
    // GUARD: Skips the first field write when output pointer a2 is null [source:raw]
    // ASSIGNMENT: Writes this[1] (offset 0x4) into *a2 when a2 is non-null [field:this:0x00000004, source:raw]
    // GUARD: Skips the second field write when output pointer a3 is null [source:raw]
    // ASSIGNMENT: Writes this[2] (offset 0x8) into *a3 when a3 is non-null [field:this:0x00000008, source:raw]
    // GUARD: Skips the third field write when output pointer a4 is null [source:raw]
    // ASSIGNMENT: Writes this[3] (offset 0xC) into *a4 when a4 is non-null [field:this:0x0000000C, source:raw]
    // RETURN: Returns the a4 output pointer [source:raw]
    // CALL: Invoked by sub_558E70 (00558E70) [caller:0x00558E70, source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[1];
    //   if (a3) *a3 = this[2];
    //   if (a4) *a4 = this[3];
    //   return a4;
    // UNRESOLVED: The receiver type and the meaning of the three consecutive read fields (offsets 0x4, 0x8, 0xC) are unknown
    // UNRESOLVED: Why the function returns the a4 output pointer to the caller is not established
}
