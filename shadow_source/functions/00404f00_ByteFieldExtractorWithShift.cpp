// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404F00
// Canonical corpus name: ByteFieldExtractorWithShift
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteFieldExtractorWithShift_00404f00.c

void UnknownObject::ByteFieldExtractorWithShift()
{
    // Indirect byte reader: reads the target pointer stored at this+0x0, then returns the byte at offset 20 (0x14) of the pointed-to object. A thiscall helper exposing a single flag/status byte from a referenced structure; no guards, no other side effects.
    // CALCULATION: Read the target pointer stored at this+0x0; the returned byte lives in the object it points to. [field:this:0x00000000, source:raw]
    // RETURN: Return *(BYTE*)(*(DWORD*)this + 20), the byte at offset 20 (0x14) of the dereferenced object. [field:obj:0x00000014, source:raw]

    // Conservative worker pseudocode:
    //   return *(BYTE*)(*(DWORD*)this + 20);
    // UNRESOLVED: The identity and semantics of the target structure behind field obj+0x14 are unknown; existing analysis calls it a flag/status byte but that is unverified.
    // UNRESOLVED: Whether this+0x0 points at a distinct object or into a larger containing structure is not established.
}
