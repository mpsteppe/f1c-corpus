// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585470
// Canonical corpus name: sub_585470
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585470_00585470.c

void UnknownObject::ThreadCreateWithMutexStateInit()
{
    // Creates a worker thread through CreateThread with creation flags 4 (CREATE_SUSPENDED) when the slot's thread-handle is still NULL and the StartAddress global is set. Before creating the thread, two mutex-protected state bytes inside the 40-byte slot are initialized: the first state byte (v3+12) is cleared to 0 and the second (v3+28) is set to 1, each guarded by its own mutex (WaitForSingleObject with status 0 or 128 accepted, then ReleaseMutex). On success the thread handle is stored back into the slot and the thread priority is raised to 1 via SetThreadPriority. Returns the thread handle (NULL when the guard fails). Called from NetworkConnectionThread (0x0057FC80); likely part of network connection thread setup.
    // LOOP: Single-iteration loop (i from 0 to < 1) over the slot array with stride 40 bytes per slot, so only slot 0 is processed. Slot layout expressed in the raw source as dword indices: +1 thread handle, +2 thread id, +4/+5 first mutex handle and its wait timeout, +8/+9 second mutex handle and its wait timeout. [source:raw]
    // ASSIGNMENT: Read the thread-handle slot at dword index +1 into result; this handle decides whether the thread was already created. [source:raw]
    // GUARD: Guard: thread-handle slot must be NULL, i must be 0, and the StartAddress global must be non-null before the thread is created. [global:0x00583D90, source:raw]
    // GUARD: When the first mutex handle at dword index +4 is non-null, WaitForSingleObject(mutex, timeout at dword index +5) must return 0 (signaled) or 128 (abandoned) for the following state-byte write to proceed. [global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Write byte value 0 into the state slot at v3+12 (state byte cleared while holding the first mutex). [source:raw]
    // CALL: Release the first mutex via ReleaseMutex when the handle at dword index +4 is non-null. [global:0x0059E1A4, source:raw]
    // GUARD: When the second mutex handle at dword index +8 is non-null, WaitForSingleObject(second mutex, timeout at dword index +9) must return 0 or 128 for the following state-byte write to proceed. [global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Write byte value 1 into the state slot at v3+28 (state byte set while holding the second mutex). [source:raw]
    // CALL: Release the second mutex via ReleaseMutex when the handle at dword index +8 is non-null. [global:0x0059E1A4, source:raw]
    // CALL: CreateThread with start routine StartAddress, passing lpParameter, creation flags 4 (CREATE_SUSPENDED) and writing the thread id to dword index +2; store the returned handle into the thread-handle slot at dword index +1. [global:0x0059E200, global:0x00583D90, source:raw]
    // CALL: When the new thread handle is non-null, SetThreadPriority(handle, 1) raises the thread priority. [global:0x0059E204, source:raw]
    // RETURN: Return the thread handle; NULL when the guard failed, otherwise the value stored back into dword index +1. [source:raw]
    // CALL: Invoked by NetworkConnectionThread (0x0057FC80) to initialize the connection thread. [caller:0x0057FC80, function:0x00585470, source:raw]

    // Conservative worker pseudocode:
    //   HANDLE sub_585470(char *slotArray) {
    //     char *slot = &slotArray[40 * 0];
    //     HANDLE h = *(DWORD *)(slot + 4);
    //     if (h == NULL && StartAddress) {
    //       HANDLE m1 = *(DWORD *)(slot + 16);
    //       if (m1) {
    //         DWORD s1 = WaitForSingleObject(m1, *(DWORD *)(slot + 20));
    //         if (s1 == 0 || s1 == 128) *(BYTE *)(slot + 12) = 0;
    //         ReleaseMutex(m1);
    //       }
    //       HANDLE m2 = *(DWORD *)(slot + 32);
    //       if (m2) {
    //         DWORD s2 = WaitForSingleObject(m2, *(DWORD *)(slot + 36));
    //         if (s2 == 0 || s2 == 128) *(BYTE *)(slot + 28) = 1;
    //         ReleaseMutex(m2);
    //       }
    //       h = CreateThread(0, 0, StartAddress, slotArray, 4, (LPDWORD)(slot + 8));
    //       *(DWORD *)(slot + 4) = h;
    //       if (h) SetThreadPriority(h, 1);
    //     }
    //     return h;
    //   }
    // UNRESOLVED: Purpose of the two state bytes at v3+12 (cleared) and v3+28 (set) and of their two mutexes is caller- and context-specific; existing analysis ties it to network connection thread setup (DERIVED only).
    // UNRESOLVED: The 40-byte slot array is processed only at index 0 here (loop bound i < 1); how other slots are used elsewhere is unknown.
    // UNRESOLVED: Identity of the StartAddress thread-start routine (global 0x00583D90) is not resolvable from this function.
}
