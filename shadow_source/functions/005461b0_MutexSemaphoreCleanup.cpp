// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005461B0
// Canonical corpus name: MutexSemaphoreCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexSemaphoreCleanup_005461b0.c

void UnknownObject::MutexSemaphoreCleanup()
{
    // Cleans up a mutex/semaphore-style object. If ResourceCleanupDestructionForDirectXObjects fails (non-zero return), aborts immediately returning -1. Otherwise unlinks the object from its doubly linked list, and if non-null releases its scene node and frees it via FreeWrapper_7bcf. Then clears global dword_8B8F28 to 0 and returns 0.
    // GUARD: Guard on ResourceCleanupDestructionForDirectXObjects(a1): if it returns non-zero (DirectX cleanup failure), abort by returning -1. [callee:0x00543BF0, function:0x005461B0, source:raw]
    // CALL: DoublyLinkedListUnlink(a1): remove the object from its doubly linked list. [callee:0x0053C630, source:raw]
    // GUARD: If a1 is non-null, call ReleaseSceneNode(a1) then FreeWrapper_7bcf(a1) to release the scene node and free the object. [callee:0x005437E0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: dword_8B8F28 = 0: clear the global UI/context pointer after cleanup. [global:0x008B8F28, source:raw]
    // RETURN: return 0 on successful cleanup. [function:0x005461B0, source:raw]

    // Conservative worker pseudocode:
    //   if (ResourceCleanupDestructionForDirectXObjects(a1)) return -1;
    //   DoublyLinkedListUnlink(a1);
    //   if (a1) {
    //     ReleaseSceneNode(a1);
    //     FreeWrapper_7bcf(a1);
    //   }
    //   dword_8B8F28 = 0;
    //   return 0;
    // UNRESOLVED: Owning object type, and what dword_8B8F28 holds (UI root context per existing analysis), are unconfirmed.
    // UNRESOLVED: Which DirectX resource fails in ResourceCleanupDestructionForDirectXObjects and why a failure aborts the whole cleanup are unknown.
}
