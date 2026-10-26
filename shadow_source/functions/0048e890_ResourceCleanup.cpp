// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E890
// Canonical corpus name: ResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceCleanup_0048e890.c

void UnknownObject::ResourceCleanup()
{
    // Cleans up a mutex/semaphore resource on this: read the handle at this+0xE8; if non-null, release it via MutexSemaphoreCleanup and clear the handle; unconditionally zero the field at this+0xEC; return 1. Known callers are StateResetWithZero (0x004662E0) and Destructor_e670 (0x0048E670).
    // ASSIGNMENT: Read the mutex/semaphore handle at this+0xE8 (this[58]) into v2. [field:this:0x000000E8]
    // GUARD: If the handle v2 is non-null, proceed with cleanup; otherwise skip the release. [field:this:0x000000E8]
    // CALL: Release the mutex/semaphore object via MutexSemaphoreCleanup(v2). [callee:0x005461B0]
    // ASSIGNMENT: Clear the handle: this[58] (this+0xE8) = 0. [field:this:0x000000E8]
    // ASSIGNMENT: Unconditionally zero the secondary field: this[59] (this+0xEC) = 0. [field:this:0x000000EC]
    // RETURN: Return 1 (success indicator). [source:raw]

    // Conservative worker pseudocode:
    //   char ResourceCleanup(_DWORD *this) {
    //     int v2 = this[58];
    //     if (v2) {
    //       MutexSemaphoreCleanup(v2);
    //       this[58] = 0;
    //     }
    //     this[59] = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Global dword_8AFE64 (0x008AFE64) is listed as read in the packet but does not appear in the raw source text; its role here is unverified.
    // UNRESOLVED: Semantics of the field at this+0xEC (counter/state) beyond being zeroed are unknown.
}
