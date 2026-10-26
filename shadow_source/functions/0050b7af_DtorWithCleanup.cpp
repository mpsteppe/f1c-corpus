// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050B7AF
// Canonical corpus name: DtorWithCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DtorWithCleanup_0050b7af.c

void UnknownObject::DtorWithCleanup()
{
    // Destructor-style cleanup routine: calls cleanup thunk ThunkToFUN00506fd9 with argument a2, then conditionally frees the object (a1) via FreeWrapper_7bcf when the low bit of flag a3 is set. Returns the object pointer a1. Decompiler shows an unusual __userpurge ABI with a2@<ebp>. Owning class unidentified.
    // CALL: Call cleanup thunk ThunkToFUN00506fd9 with a2 as argument. [callee:0x0050B82B, source:raw]
    // GUARD: Branch on (a3 & 1) != 0; only then free the object. [source:raw]
    // CALL: Conditionally call FreeWrapper_7bcf(a1) to release the object allocation. [callee:0x00587BCF, source:raw]
    // RETURN: Return the object pointer a1. [function:0x0050B7AF, source:raw]

    // Conservative worker pseudocode:
    //   void *__userpurge DtorWithCleanup(void *a1, int a2, char a3)
    //   {
    //     ThunkToFUN00506fd9(a2);
    //     if ((a3 & 1) != 0)
    //       FreeWrapper_7bcf(a1);
    //     return a1;
    //   }
    // UNRESOLVED: a2@<ebp> and the __userpurge convention look like decompiler artifacts; the real calling convention is unconfirmed.
    // UNRESOLVED: Semantics of the cleanup performed by ThunkToFUN00506fd9 are not in the packet.
    // UNRESOLVED: Bit-0-of-a3 as the deleting-destructor flag is a DERIVED interpretation; exact caller convention unverified.
    // UNRESOLVED: Owning class and object layout unknown (no fields in packet).
}
