// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545670
// Canonical corpus name: CameraPositionGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraPositionGetter_00545670.c

void UnknownObject::CameraPositionGetter()
{
    // Reads three fields of the receiver (this+0x11C, this+0x124, this+0x12C) and writes each to a caller-supplied output pointer (a2, a3, a4), skipping any output pointer that is null. Returns a4, the third output pointer. Invoked by sub_4FCEE0 (004FCEE0).
    // GUARD: Null-check a2; the write to *a2 is skipped when a2 is null. [source:raw]
    // ASSIGNMENT: Write this[0x11C] into *a2 when a2 is non-null. [field:this:0x0000011C, source:raw]
    // GUARD: Null-check a3; the write to *a3 is skipped when a3 is null. [source:raw]
    // ASSIGNMENT: Write this[0x124] into *a3 when a3 is non-null. [field:this:0x00000124, source:raw]
    // GUARD: Null-check a4; the write to *a4 is skipped when a4 is null. [source:raw]
    // ASSIGNMENT: Write this[0x12C] into *a4 when a4 is non-null. [field:this:0x0000012C, source:raw]
    // RETURN: Return a4 (the third output pointer) regardless of whether it was written. [source:raw]
    // CALL: Invoked by sub_4FCEE0 (004FCEE0) to read receiver state into caller-owned output slots. [caller:0x004FCEE0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* CameraPositionGetter(_DWORD* this, _DWORD* a2, _DWORD* a3, _DWORD* a4) {
    //     if (a2) *a2 = this[71];
    //     if (a3) *a3 = this[73];
    //     if (a4) *a4 = this[75];
    //     return a4;
    //   }
    // UNRESOLVED: The meaning of the three fields (0x11C, 0x124, 0x12C) and the object type of the receiver are not established; only the read/copy pattern is certain
}
