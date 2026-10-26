// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584F30
// Canonical corpus name: MutexProtectedFunctionCallWithWait
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MutexProtectedFunctionCallWithWait_00584f30.c

void UnknownObject::AppendToMutexGuardedListWithWait()
{
    // Mutex-gated linked-list append. Reads the mutex handle at this+0x5A8 and the wait timeout at this+0x5AC, waits on the mutex with WaitForSingleObject, appends the caller's node to a linked list via LinkedListNodeAppend_6000, then releases the mutex. Returns 1 when the append succeeded, 0 otherwise. Thread-safe list insertion guarded by a Windows mutex.
    // GUARD: Proceed only when the mutex handle stored at this+0x5A8 is non-null; otherwise skip straight to the return of 0 [field:this:0x000005A8, source:raw]
    // CALL: WaitForSingleObject(handle at this+0x5A8, timeout at this+0x5AC): acquire the mutex before touching the list [global:0x0059E1A0, field:this:0x000005A8, field:this:0x000005AC, source:raw]
    // GUARD: Only enter the append section when the wait returned 0 (signaled) or 128 (WAIT_ABANDONED); a timeout or error blocks the append [source:raw]
    // CALL: LinkedListNodeAppend_6000(list head at dword index 358 past this, a2, 0): append the caller payload; a non-zero result sets the success flag v4 [callee:0x00586000, source:raw]
    // CALL: ReleaseMutex on the handle stored at this+0x5A8 (read back through the list object) when it is non-null, always after the append attempt [global:0x0059E1A4, field:this:0x000005A8, source:raw]
    // RETURN: Return 1 when the append succeeded, else 0 [function:0x00584F30, source:raw]

    // Conservative worker pseudocode:
    //   v4 = 0;
    //   if (this[362] != 0) {
    //     v5 = WaitForSingleObject(this[362], this[363]);
    //     if (v5 == 0 || v5 == 128) {
    //       if (LinkedListNodeAppend_6000(this + 358, a2, 0)) v4 = 1;
    //       v6 = (this + 358)[4];
    //       if (v6) ReleaseMutex(v6);
    //     }
    //   }
    //   return v4;
    // UNRESOLVED: The container type of the list headed at dword index 358 past this is not evidenced; the append flag third argument to LinkedListNodeAppend_6000 is unexplained
    // UNRESOLVED: The same handle is waited on and then released as a mutex while the append operates on the adjacent list object; the owner relationship between this+0x5A8 and the list is not evidenced here
    // UNRESOLVED: The timeout literal semantics of this+0x5AC (a DWORD in wait milliseconds) are not verified against a caller
}
