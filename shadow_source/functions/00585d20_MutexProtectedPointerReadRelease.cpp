// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585D20
// Canonical corpus name: MutexProtectedPointerReadRelease
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedPointerReadRelease_00585d20.c

void UnknownObject::MutexProtectedPointerReadRelease()
{
    // Thread-safe read accessor for a shared pointer field: acquires a mutex handle from this+0x5B8 with a timeout from this+0x5BC, and when the wait succeeds (return 0 or 128) reads the pointer value at this+0x5B4 under protection, then releases the mutex. Returns the read pointer value. When the wait does not succeed or the handle is null, the raw code selects a null read pointer, so the subsequent dereference is a fault path.
    // CALCULATION: Load mutex handle v1 = *(this+0x5B8) and form pointer v2 = this + 0x5B4 (the protected pointer field). [field:this:0x000005B8, field:this:0x000005B4, source:raw]
    // GUARD: Guard: if v1 is non-null AND WaitForSingleObject(v1, timeout) returns 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED), v4 = v2 (valid read pointer); otherwise v4 = 0. [field:this:0x000005B8, field:this:0x000005BC, source:raw]
    // CALL: Call WaitForSingleObject(v1, *(this+0x5BC)) through the imported thunk at 0x0059E1A0. [global:0x0059E1A0, field:this:0x000005BC, source:raw]
    // ASSIGNMENT: Re-load mutex handle v5 = *(this+0x5B8) for the release and read the pointer value v6 = *v4 from this+0x5B4 under mutex protection. [field:this:0x000005B8, field:this:0x000005B4, source:raw]
    // GUARD: If v5 is non-null, call ReleaseMutex(v5) through the imported thunk at 0x0059E1A4. [field:this:0x000005B8, global:0x0059E1A4, source:raw]
    // CALL: Call ReleaseMutex(v5) to release the mutex after the protected read. [global:0x0059E1A4, source:raw]
    // RETURN: Return the pointer value read from this+0x5B4. [field:this:0x000005B4, source:raw]
    // CALL: Called by sub_57BF00 (0x0057BF00), sub_57E280 (0x0057E280), sub_580DE0 (0x00580DE0), sub_5813E0 (0x005813E0), sub_584230 (0x00584230) and sub_585870 (0x00585870) to read the shared pointer safely. [caller:0x0057BF00, caller:0x0057E280, caller:0x00580DE0, caller:0x005813E0, caller:0x00584230, caller:0x00585870, source:raw]

    // Conservative worker pseudocode:
    //   int sub_585D20(int *this) {
    //     void *mutex = (void *)this[366];  /* 0x5B8 * /
    //     int *v2 = this + 365;             /* 0x5B4 * /
    //     int *v4;
    //     if (mutex && (v3 = WaitForSingleObject(mutex, this[367])) == 0 || v3 == 128)
    //       v4 = v2;
    //     else
    //       v4 = 0;
    //     void *rel = (void *)v2[1];  /* 0x5B8 * /
    //     int v6 = *v4;               /* read 0x5B4 under lock; null v4 faults * /
    //     if (rel) ReleaseMutex(rel);
    //     return v6;
    //   }
    // UNRESOLVED: The object owning the mutex (0x5B8), pointer (0x5B4) and timeout (0x5BC) fields is unknown; packet marks owner as UnknownObject/UNKNOWN.
    // UNRESOLVED: When the handle is null or the wait fails, v4 is 0 and *v4 dereferences null (fault path in raw code); whether real callers guarantee a valid handle is not evidenced here.
}
