// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585CD0
// Canonical corpus name: ThreadSafeWriteWithMutex
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThreadSafeWriteWithMutex_00585cd0.c

void UnknownObject::ThreadSafeWriteWithMutex()
{
    // Mutex-protected field write. Guards on the mutex handle at offset 0x5B8 being non-null and WaitForSingleObject(handle, timeout at 0x5BC) returning either 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED); on success writes a2 through a pointer to the integer field at offset 0x5B4, then releases the mutex via ReleaseMutex when the handle at offset 0x5B8 is present, and returns the pointer to the written field. When the guard fails the selected result pointer is null, so the unconditional store at 0x5B4 dereferences null (a latent crash path).
    // GUARD: Proceed only when the mutex handle at offset 0x5B8 is non-null and WaitForSingleObject with timeout at offset 0x5BC returns 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED); otherwise select the null pointer as the write target. [field:this:0x000005B8, field:this:0x000005BC, global:0x0059E1A0, source:raw]
    // ASSIGNMENT: On guard success select the pointer to the protected field at offset 0x5B4 as the write target. [field:this:0x000005B4, source:raw]
    // ASSIGNMENT: On guard failure select the null pointer as the write target. [source:raw]
    // ASSIGNMENT: Store argument a2 through the selected pointer into the field at offset 0x5B4; this unconditional store also executes when the null pointer was selected, which is a null-dereference crash path. [field:this:0x000005B4, source:raw]
    // CALL: When the mutex handle at offset 0x5B8 is non-null, release it with ReleaseMutex after the write completes. [field:this:0x000005B8, global:0x0059E1A4, source:raw]
    // RETURN: Return the pointer to the written field at offset 0x5B4 (or the ReleaseMutex result when that path ran). [field:this:0x000005B4, source:raw]

    // Conservative worker pseudocode:
    //   int* sub_585CD0(int* this, int value) {
    //     void* h = (void*)this[366];
    //     int* target = this + 365;
    //     if (h && ((v = WaitForSingleObject(h, this[367])) == 0 || v == 128))
    //       target = this + 365;
    //     else
    //       target = 0;
    //     *target = value;
    //     if (this[366]) ReleaseMutex(this[366]);
    //     return target;
    //   }
    // UNRESOLVED: Identity of the owning object and the semantics of the guarded field at offset 0x5B4 are unknown; callers at 0x0057BF00, 0x005804A0 and 0x00584230 may clarify them.
    // UNRESOLVED: Whether the null-target crash path is reachable in practice or always guarded by callers is unverified.
}
