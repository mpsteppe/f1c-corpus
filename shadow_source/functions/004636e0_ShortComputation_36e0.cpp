// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004636E0
// Canonical corpus name: ShortComputation_36e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_36e0_004636e0.c

void UnknownObject::ShortComputation_36e0()
{
    // Double-indirected byte accessor: reads the DWORD pointer stored at this+0x0, then returns the BYTE at offset +0x20 of the pointed-to object. Structural twin of FieldAccessorAt0x20 (00404d10) per the DERIVED cluster prelabel; typical vtable/manager-object field read.
    // ASSIGNMENT: obj = *(_DWORD *)this; load the object pointer stored at this+0x0. [field:this:0x00000000, function:0x004636E0, source:raw]
    // RETURN: Return the BYTE at obj+0x20. [field:obj:0x00000020, function:0x004636E0, source:raw]

    // Conservative worker pseudocode:
    //   return *(BYTE *)(*(DWORD *)this + 0x20);
    // UNRESOLVED: Semantics of the byte at pointed-object +0x20 (flag/state?) are unknown.
    // UNRESOLVED: Caller ShortComputation_f070 (0049F070) exists but does not constrain the owner type.
}
