// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499620
// Canonical corpus name: ShortComputation_9620
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_9620_00499620.c

void UnknownObject::ConditionalFreeInnerAndSelf()
{
    // Conditional teardown helper. When the byte flag at this+0xC is non-zero, frees the inner heap block stored at this+0. When bit 0 of a2 is set, frees the container object itself. Returns the original this pointer unchanged. Called by sub_495300 during object/container teardown.
    // GUARD: Test the byte flag at this+0xC; when non-zero, the inner block is freed. [field:this:0x0000000C, source:raw]
    // CALL: Free the inner heap block: FreeWrapper_7bcf(*(void**)this). [callee:0x00587BCF, field:this:0x00000000, source:raw]
    // GUARD: Test bit 0 of a2 ((a2 & 1) != 0); when set, the container object itself is freed. [source:raw]
    // CALL: Free the container object: FreeWrapper_7bcf(this). [callee:0x00587BCF, source:raw]
    // RETURN: Return this unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_499620(void* this, char a2) {
    //     if (*(char*)((char*)this + 0xC) != 0)
    //       FreeWrapper_7bcf(*(void**)this);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return (int)this;
    //   }
    // UNRESOLVED: Semantics of the flag at this+0xC (owner-side ownership marker) is not established.
    // UNRESOLVED: Whether a2 is a destructor flag or an explicit free request depends on the caller sub_495300.
}
