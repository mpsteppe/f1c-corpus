// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00495120
// Canonical corpus name: GlobalFieldReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalFieldReader_00495120.c

void UnknownObject::ReadRenderDeviceFields()
{
    // Reads two DWORD fields from the global object pointed to by dword_8B8DC8 (offsets +28/0x1C and +32/0x20) into caller-supplied output pointers and returns the global pointer itself. Existing analysis attributes the fields to a render device and interprets them as viewport/render-surface dimensions (DERIVED); the raw source proves only the two unconditional reads.
    // ASSIGNMENT: Write to *a1 the DWORD read at dword_8B8DC8 + 28 (0x1C). [global:0x008B8DC8, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write to *a2 the DWORD read at dword_8B8DC8 + 32 (0x20). [global:0x008B8DC8, source:raw]
    // RETURN: Return dword_8B8DC8, the global pointer itself. [global:0x008B8DC8, source:raw, function:0x00495120]

    // Conservative worker pseudocode:
    //   *a1 = *(DWORD*)(dword_8B8DC8 + 0x1C);
    //   *a2 = *(DWORD*)(dword_8B8DC8 + 0x20);
    //   return dword_8B8DC8;
    // UNRESOLVED: The meaning of the two fields at global+0x1C and global+0x20 as viewport/render-surface dimensions is taken from existing_analysis (DERIVED); only the unconditional reads are proven by the raw source. The global offsets 28 and 32 appear in the raw source only and have no packet field evidence_ref.
    // UNRESOLVED: dword_8B8DC8 is read but never validated before dereference in this function.
}
