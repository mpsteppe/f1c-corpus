// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004636E0
// Canonical corpus name: ShortComputation_36e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_36e0_004636e0.c

void UnknownObject::getByteField0x20()
{
    // Dereferences the pointer stored at this+0x0 and returns the byte at offset +0x20 of the pointed-to object. Structural twin of FieldAccessorAt0x20 (00404d10); called by ShortComputation_f070 (0x0049F070).
    // CALCULATION: obj = *(DWORD*)this — load the pointer stored at this+0x0. [field:this:0x00000000, source:raw]
    // RETURN: return *(BYTE*)(obj + 0x20) — byte field at +0x20 of the pointed-to object. [field:obj:0x00000032, source:raw]
}
