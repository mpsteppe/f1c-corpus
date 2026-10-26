// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00585040
// Canonical corpus name: sub_585040
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_585040_00585040.c

void UnknownObject::DrainQueuesAndReleaseMutex()
{
    // Drains two queues and releases the owning mutex. First pops values from a mutex-guarded queue via sub_584CD0 until it reports empty, dispatching each popped value through the vtable at +0x5C (92) as (*(*this + 92))(this, value). It then acquires the mutex at this+0x5A8 with timeout this+0x5AC via WaitForSingleObject (proceeding on result 0 or WAIT_TIMEOUT 128) and drains a second linked list: while the count at this+0x5A4 is positive, it walks from head *(this+0x598)+0x0, finds the node whose first dword equals the head node's key, unlinks it (updating the control-block +0x0/+0x4/+0x8 pointers and decrementing +0xC), and frees the node; if the node's byte flag at +0x8 is set, its first-dword payload is first handled by SEHGuardedFunctionWithExceptionHandling and freed. Finally, if the mutex handle this+0x5A8 is nonzero, it is released via ReleaseMutex. Called by AudioStreamingThreadShutdown (0x0057FDE0).
    // LOOP: While sub_584CD0(this, &v11) returns nonzero, pop the next value from the first (mutex-guarded) queue into v11. [callee:0x00584CD0]
    // CALL: Dispatch each popped value through the vtable at +0x5C (92): call (*(*this + 92))(this, v11). [field:obj:0x0000005C, field:this:0x00000000]
    // GUARD: Acquire the mutex at this+0x5A8 with timeout this+0x5AC via WaitForSingleObject; proceed with the second-list drain only when the result is 0 (signaled) or 128 (WAIT_TIMEOUT). [global:0x0059E1A0, field:this:0x000005A8, field:this:0x000005AC]
    // LOOP: Drain the second list while its node count (this+0x5A4, also the control block field at *(this+0x598)+0xC) is positive. [guard:0, field:this:0x000005A4, field:this:0x00000598, field:*(this+0x598):0x0000000C]
    // LOOP: Walk the list from the head pointer at *(this+0x598)+0x0, following each node's +0x4 link, until a node whose first dword equals the head node's key is found or the list ends. [field:*(this+0x598):0x00000000, source:raw]
    // ASSIGNMENT: Unlink the matched node: update the control-block head (+0x0), iterator (+0x4, this+0x59C), and tail (+0x8, this+0x5A0) pointers when they reference the removed node, and decrement the node count (+0xC). [field:*(this+0x598):0x00000000, field:*(this+0x598):0x00000004, field:*(this+0x598):0x00000008, field:this:0x0000059C, field:this:0x000005A0, field:*(this+0x598):0x0000000C]
    // CALL: If the removed node's byte flag at +0x8 is set, handle its first-dword payload via SEHGuardedFunctionWithExceptionHandling and then free that payload via FreeWrapper_7bcf. [callee:0x005867B0, callee:0x00587BCF, source:raw]
    // CALL: Free every removed node via FreeWrapper_7bcf. [callee:0x00587BCF]
    // CALL: If the mutex handle (this+0x5A8) is nonzero, release it via ReleaseMutex. [global:0x0059E1A4, field:this:0x000005A8]
    // RETURN: Return 0 when no mutex handle was held; otherwise ReleaseMutex is called on the way out. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_585040(DWORD* this) {
    //     int value;
    //     while (sub_584CD0(this, &value))
    //       (*(DWORD**)(*(DWORD*)this + 0x5C))(this, value);  // vtable dispatch at +0x5C
    //     DWORD* ctl = this + 0x598;
    //     if (this[0x5A8] && (WaitForSingleObject(this[0x5A8], this[0x5AC]) == 0 || WaitForSingleObject(this[0x5A8], this[0x5AC]) == 128))
    //       ; // keep ctl as the drain cursor
    //     else
    //       ctl = 0;
    //     while ((int)ctl[3] > 0) {
    //       DWORD* n = (DWORD*)*ctl;
    //       if (!n || !*n) break;
    //       DWORD key = *n;
    //       DWORD* prev = 0;
    //       while (*n != key) { prev = n; n = (DWORD*)n[1]; if (!n) goto drain; }
    //       if (n == (DWORD*)ctl[2]) ctl[2] = n[1];
    //       if (prev) prev[1] = n[1]; else *ctl = n[1];
    //       if ((DWORD*)ctl[1] == n) ctl[1] = prev;
    //       ctl[3]--;
    //       if (*((BYTE*)n + 8)) {
    //         void* payload = (void*)*n;
    //         if (*n) { SEHGuardedFunctionWithExceptionHandling(*n); FreeWrapper_7bcf(payload); }
    //       }
    //       FreeWrapper_7bcf(n);
    //     }
    //   drain:
    //     if (this[0x5A8]) ReleaseMutex(this[0x5A8]);
    //     return 0;
    //   }
    // UNRESOLVED: Node layout beyond the first-dword key and +0x4 link is unconfirmed; the +0x8 byte flag selects an SEH destroy path whose target semantics are unknown.
    // UNRESOLVED: Identity of the vtable +0x5C dispatch target is unknown.
    // UNRESOLVED: The +0x4 control-block field is written when the removed node is the current one; whether it is an iterator or tail pointer is ambiguous from the raw text, and the packet's skeleton labels differ from the raw unlink logic.
    // UNRESOLVED: The unlink walk compares each node's first dword against the head node's key; the meaning of that key value is unconfirmed.
}
