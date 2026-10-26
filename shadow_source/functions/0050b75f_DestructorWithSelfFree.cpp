// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B75F
// Canonical corpus name: DestructorWithSelfFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithSelfFree_0050b75f.c

void UnknownObject::DestructorWithSelfFree()
{
    // Thiscall destructor: invokes a cleanup thunk on the object (ThunkToFUN00506ccc), then conditionally frees the object via FreeWrapper_7bcf when the low bit of flag a2 is set. Returns the this pointer. Standard MSVC deleting-destructor pattern; the flag bit selects self-free. Owning class unidentified.
    // CALL: Call cleanup thunk ThunkToFUN00506ccc with this as argument. [callee:0x0050B425, source:raw]
    // GUARD: Branch on (a2 & 1) != 0; only then free the object. [source:raw]
    // CALL: Conditionally call FreeWrapper_7bcf(this) to release the object allocation. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer. [function:0x0050B75F, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *__thiscall DestructorWithSelfFree(_DWORD *this, char a2)
    //   {
    //     ThunkToFUN00506ccc(this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Semantics of the cleanup performed by ThunkToFUN00506ccc are not in the packet; thunk target resolution is static-only.
    // UNRESOLVED: Bit-0-of-a2 as the deleting-destructor flag is a DERIVED interpretation; exact caller convention unverified.
    // UNRESOLVED: Owning class and object layout unknown (no fields in packet).
}
