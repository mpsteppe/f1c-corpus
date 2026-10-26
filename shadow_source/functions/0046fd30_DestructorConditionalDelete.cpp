// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046FD30
// Canonical corpus name: DestructorConditionalDelete
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorConditionalDelete_0046fd30.c

void UnknownObject::DestructorConditionalDelete()
{
    // Scalar-deleting-destructor idiom: runs InitWithVTableCleanup() teardown, then conditionally frees this via FreeWrapper_7bcf(this) when the delete flag a2 has its low bit set. Returns this in all paths.
    // CALL: Call InitWithVTableCleanup() with no arguments as the object teardown step. [callee:0x00487250]
    // GUARD: Guard: if (a2 & 1) != 0, i.e. the MSVC deleting-destructor flag is set. [source:raw]
    // CALL: Call FreeWrapper_7bcf(this) to free the object memory only when the delete flag is set. [callee:0x00587BCF]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   void *sub_46FD30(void *this, char a2) {
    //     InitWithVTableCleanup();
    //     if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Object type and its vtable are unknown; the teardown target of InitWithVTableCleanup is not identifiable from this packet.
    // UNRESOLVED: InitWithVTableCleanup is invoked without a this argument in the raw source; the object it operates on is ambiguous.
    // UNRESOLVED: No callers are recorded in the packet, so the delete-flag convention call site is unknown.
}
