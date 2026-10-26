// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491E10
// Canonical corpus name: ConditionalResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalResourceCleanup_00491e10.c

void UnknownObject::ConditionalResourceCleanup()
{
    // Conditional resource cleanup: when the flag byte at this+0x8 is nonzero and the DWORD pointer at this+0 is non-null, frees the embedded pointer via FreeWrapper_7bcf. Then, if parameter a2 bit 0 is set, frees the object itself (this). Returns this unchanged in every path. Structural twin of ConditionalDestructor_46f0 (004646f0).
    // GUARD: Guard on the byte at this+0x8 being nonzero combined with the DWORD at this+0 being non-null; the embedded-pointer free runs only when both hold. [field:this:0x00000008, field:this:0x00000000, source:raw]
    // CALL: Free the embedded pointer stored at this+0 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // GUARD: Guard on (a2 & 1) != 0: the self-free runs only when parameter bit 0 is set. [source:raw]
    // CALL: Free the object itself (this) via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return this unchanged. [source:raw, function:0x00491E10]

    // Conservative worker pseudocode:
    //   int __thiscall sub_491E10(int this, char a2) {
    //     if (*(_BYTE*)(this + 8) && *(_DWORD*)this)
    //       FreeWrapper_7bcf(*(LPVOID*)this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf((LPVOID)this);
    //     return this;
    //   }
    // UNRESOLVED: The owning class and the meaning of the flag byte at this+0x8 are unknown; the flag likely tracks whether the embedded pointer at this+0 owns allocated memory.
    // UNRESOLVED: The meaning of a2 bit 0 (self-delete flag) as a convention across the two callers is not established.
    // UNRESOLVED: A2 bit mask 1 is read from the raw source; no dedicated packet guard evidence documents it.
}
