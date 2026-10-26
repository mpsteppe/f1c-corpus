// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542520
// Canonical corpus name: DoubleFieldGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleFieldGetter_00542520.c

void UnknownObject::DoubleFieldGetter()
{
    // __thiscall getter that reads two dword fields of the object (this+0x4 and this+0x8) and writes them through two independent output pointers a2 and a3. Each output pointer is individually null-guarded, so a null pointer causes that field to be skipped. Returns a3.
    // GUARD: Guard a2: only write the first field when the output pointer a2 is non-null. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Copy the dword at this+0x4 into *a2. [field:this:0x00000004, source:raw]
    // GUARD: Guard a3: only write the second field when the output pointer a3 is non-null. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Copy the dword at this+0x8 into *a3. [field:this:0x00000008, source:raw]
    // RETURN: Return the a3 output pointer as the function result. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_542520(_DWORD *this, _DWORD *a2, _DWORD *a3) {
    //     if (a2) *a2 = this[1];
    //     if (a3) *a3 = this[2];
    //     return a3;
    //   }
    // UNRESOLVED: Meaning of the two fields at this+0x4 / this+0x8 depends on the object type, unknown here.
    // UNRESOLVED: Callers (CameraViewSystem 0x00408E20, sub_5550E0) determine which two quantities are queried.
}
