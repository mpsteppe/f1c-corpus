// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004646F0
// Canonical corpus name: ConditionalDestructor_46f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDestructor_46f0_004646f0.c

void UnknownObject::ConditionalFreeObject()
{
    // Destructor-like conditional free: if the flag byte at this+0x8 is nonzero, frees the embedded pointer stored at this+0. Then, if parameter a2 bit 0 is set, frees the object itself (this). Returns this. Returns this regardless of either branch.
    // GUARD: Guard on the byte at this+0x8: the embedded-pointer free runs only when it is nonzero. [field:this:0x00000008, source:raw]
    // CALL: Free the embedded pointer read from this+0 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // GUARD: Guard on (a2 & 1) != 0: the self-free runs only when parameter bit 0 is set. [source:raw]
    // CALL: Free the object itself (this) via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return this unchanged. [source:raw, function:0x004646F0]

    // Conservative worker pseudocode:
    //   int __thiscall sub_4646F0(int this, char a2) {
    //     if (*(_BYTE*)(this + 8))
    //       FreeWrapper_7bcf(*(LPVOID*)this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf((LPVOID)this);
    //     return this;
    //   }
    // UNRESOLVED: The owning class and the meaning of the flag at this+0x8 are unknown; the flag likely tracks whether the embedded pointer at this+0 owns allocated memory.
    // UNRESOLVED: The meaning of a2 bit 0 (self-delete flag) as a convention across the three callers is not established.
    // UNRESOLVED: A2 bit mask 1 is read from the raw source; no dedicated packet guard evidence documents it.
}
