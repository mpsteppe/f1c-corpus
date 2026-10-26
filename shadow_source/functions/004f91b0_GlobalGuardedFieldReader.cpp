// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F91B0
// Canonical corpus name: GlobalGuardedFieldReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalGuardedFieldReader_004f91b0.c

void UnknownObject::GlobalGuardedFieldReader()
{
    // Feature-gated field reader. When the global dword_8AFE68 is non-zero, resolves an object from a1 via sub_55BDE0 and copies four of its fields (dword[2], dword[3], dword[5], dword[6]) into the caller-supplied output pointers a2..a5, skipping any null output pointer. Does nothing when the global guard is zero.
    // GUARD: Guard on the global dword_8AFE68 being non-zero; when it is zero the whole body is skipped. [global:0x008AFE68, source:raw]
    // CALL: Call sub_55BDE0(a1) to resolve the source object v5 from the key argument a1. [callee:0x0055BDE0, source:raw]
    // GUARD: Guard on output pointer a2 being non-null before writing to it. [source:raw]
    // ASSIGNMENT: Write the resolved object's dword[2] into *a2 when a2 is non-null. [source:raw]
    // GUARD: Guard on output pointer a3 being non-null before writing to it. [source:raw]
    // ASSIGNMENT: Write the resolved object's dword[3] into *a3 when a3 is non-null. [source:raw]
    // GUARD: Guard on output pointer a4 being non-null before writing to it. [source:raw]
    // ASSIGNMENT: Write the resolved object's dword[5] into *a4 when a4 is non-null. [source:raw]
    // GUARD: Guard on output pointer a5 being non-null before writing to it. [source:raw]
    // ASSIGNMENT: Write the resolved object's dword[6] into *a5 when a5 is non-null. [source:raw]
    // CALL: Invoked by MultiTableCoordinateSearch (0x004F9240) and VidMan_Enter (0x004FA000). [caller:0x004F9240, caller:0x004FA000, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4F91B0(int a1, DWORD *a2, DWORD *a3, DWORD *a4, DWORD *a5) {
    //     if (dword_8AFE68) {
    //       v5 = (DWORD *)sub_55BDE0(a1);
    //       if (a2) *a2 = v5[2];
    //       if (a3) *a3 = v5[3];
    //       if (a4) *a4 = v5[5];
    //       if (a5) *a5 = v5[6];
    //     }
    //   }
    // UNRESOLVED: The type of the object returned by sub_55BDE0 and the semantics of its fields at dword[2]/[3]/[5]/[6] are unknown.
    // UNRESOLVED: The meaning and purpose of the enable global dword_8AFE68 and of the key argument a1 are unknown.
    // UNRESOLVED: Why the reader skips field dword[4] between the copied fields is unexplained by the packet.
}
