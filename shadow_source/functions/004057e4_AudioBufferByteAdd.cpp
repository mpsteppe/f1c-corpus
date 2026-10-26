// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004057E4
// Canonical corpus name: AudioBufferByteAdd
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioBufferByteAdd_004057e4.c

void UnknownObject::AudioBufferByteAdd()
{
    // Small __usercall helper with a custom register-based ABI: adds the 5th byte of the 64-bit result register pair (BYTE5(result), i.e. bits 32..39 of the returned value) into the byte pointed to by a2, zeroes the byte at offset 112 of the object a3, and returns result unchanged. Operates on an audio-buffer-style object per the ABI lead; the helper returns the same value it was passed.
    // CALCULATION: *a2 += BYTE5(result): add the 5th byte (bits 32..39) of the 64-bit result value into the byte pointed to by a2. [source:raw]
    // ASSIGNMENT: *(_BYTE *)(a3 + 112) = 0: clear the byte at offset 112 of the object a3. [source:raw]
    // RETURN: Return result unchanged, keeping the original 64-bit value intact. [source:raw]

    // Conservative worker pseudocode:
    //   __int64 sub_4057E4(__int64 result, _BYTE *a2, int a3) {
    //     *a2 += BYTE5(result);
    //     *(_BYTE *)(a3 + 112) = 0;
    //     return result;
    //   }
    // UNRESOLVED: The __usercall signature carries nonstandard register placement (result via edx:eax, a2 via ebx, a3 via esi); the caller and the meaning of these registers are not known.
    // UNRESOLVED: Semantics of BYTE5(result) as an addend (e.g. a data byte embedded in a status/return value) are inferred from the raw source, not from named evidence.
    // UNRESOLVED: Meaning of the byte cleared at a3 + 112 is unknown; the packet lists no fields for the audio buffer object.
    // UNRESOLVED: The decompiler warns 'positive sp value has been detected, the output may be wrong!', so the exact instruction sequence may differ from this rendering.
    // UNRESOLVED: The helper appears to mutate the byte at a2 and the flag byte at a3+112 without allocating or reading anything else; full audio-buffer contract is unresolved.
}
