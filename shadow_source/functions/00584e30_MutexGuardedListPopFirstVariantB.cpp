// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00584E30
// Canonical corpus name: sub_584E30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_584E30_00584e30.c

void UnknownObject::MutexGuardedListPopFirstVariantB()
{
    // Thread-safe pop/consume of the first node of a linked list guarded by a mutex; a variant of sub_584CD0 with different field offsets. Waits on the mutex handle at this+0x570 with the timeout at this+0x574, and only when the wait succeeds or returns WAIT_ABANDONED unlinks the head node (updating head 0x560, tail 0x564, iterator 0x568, and count 0x56C). If the node's flag byte at +8 is set, its data pointer is processed under SEH and freed, then the node itself is freed. The popped value is written to *a2 and returned as a bool (value != 0). Returns false immediately if the mutex handle is null or the list is empty.
    // ASSIGNMENT: Initialize result flag v3 = 0 (default false, returned when the mutex or list is unavailable) [source:raw]
    // GUARD: Read the mutex handle v4 = this[348] (this+0x570); if it is null, the entire guarded block is skipped and the function returns false [field:this:0x00000570, source:raw]
    // CALL: WaitForSingleObject(mutex, this[349]) i.e. this+0x574 timeout, the mutex acquire for the list access [global:0x0059E1A0, field:this:0x00000570, field:this:0x00000574, source:raw]
    // GUARD: Proceed only when the wait returned 0 (signaled) or 128 (WAIT_ABANDONED); a timeout/error blocks the pop [global:0x0059E1A0, source:raw]
    // ASSIGNMENT: Load the list head v6 = this[344] (this+0x560) and reset v7 = 0 [field:this:0x00000560, source:raw]
    // GUARD: If the head is null (empty list), jump to LABEL_9 which leaves v7 = 0 [field:this:0x00000560, source:raw]
    // ASSIGNMENT: Clear the removed node's flag byte at +8 and read the head value v7 = *v6 [field:this:0x00000560, source:raw]
    // GUARD: Enter the removal path only when the head value *v6 is non-zero and the head pointer is non-null [field:this:0x00000560, source:raw]
    // LOOP: Walk the singly-linked list from the head, tracking previous (v9) and current (v8) nodes, until the current node's value equals v7 or the list ends [field:this:0x00000560, source:raw]
    // STATE_TRANSITION: If the removed node v8 is the iterator/current pointer at this+0x568, advance it to v8->next [field:this:0x00000568, source:raw]
    // ASSIGNMENT: Unlink v8: previous node's next (v9->next) skips to v8->next, or when v9 is null the list head this+0x560 is set to v8->next [field:this:0x00000560, source:raw]
    // STATE_TRANSITION: If the removed node v8 is the tail at this+0x564, move the tail back to the previous node v9 [field:this:0x00000564, source:raw]
    // ASSIGNMENT: Decrement the node count at this+0x56C [field:this:0x0000056C, source:raw]
    // GUARD: When the removed node's flag byte at +8 is non-zero, its data must be cleaned up [source:raw]
    // ASSIGNMENT: Read the node's data pointer v12 = *v8 and continue only when it is non-null [source:raw]
    // CALL: SEHGuardedFunctionWithExceptionHandling(*v8) processes the node's data under SEH protection before the free [callee:0x005867B0, source:raw]
    // CALL: FreeWrapper_7bcf(v12) frees the node's data block [callee:0x00587BCF, source:raw]
    // CALL: FreeWrapper_7bcf(v8) frees the removed node itself [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Write the popped value *a2 = v7 and set the result flag v3 = (v7 != 0) [source:raw]
    // GUARD: Re-read the mutex handle v10 = this[348]; when non-null, ReleaseMutex(v10) releases it before returning [global:0x0059E1A4, field:this:0x00000570, source:raw]
    // RETURN: Return v3 (true when a node value was popped, false on null mutex, wait failure, or empty list) [source:raw]
    // CALL: Called by sub_585130 (0x00585130) and sub_5853B0 (0x005853B0), the static callers of this list pop [caller:0x00585130, caller:0x005853B0]

    // Conservative worker pseudocode:
    //   bool MutexGuardedListPopFirstVariantB(void *this, int *outValue) {
    //     bool result = false;
    //     void *mutex = *(void**)(this + 0x570);
    //     if (!mutex) return false;
    //     DWORD wait = WaitForSingleObject(mutex, *(DWORD*)(this + 0x574));
    //     if (wait == 0 || wait == 128) {
    //       int *head = *(int**)(this + 0x560);
    //       int value = 0;
    //       if (head) {
    //         *(BYTE*)(head + 8) = 0;
    //         value = *head;
    //         if (*head && head) {
    //           node *prev = 0, *cur = head;
    //           while (*cur != value) { prev = cur; cur = cur->next; if (!cur) { value = 0; goto done; } }
    //           if (cur == *(node**)(this + 0x568)) *(node**)(this + 0x568) = cur->next;
    //           if (prev) prev->next = cur->next; else *(node**)(this + 0x560) = cur->next;
    //           if (*(node**)(this + 0x564) == cur) *(node**)(this + 0x564) = prev;
    //           --*(int*)(this + 0x56C);
    //           if (*(BYTE*)cur + 8) {
    //             void *data = *(void**)cur;
    //             if (data) { SEHGuardedFunctionWithExceptionHandling(*(void**)cur); FreeWrapper_7bcf(data); }
    //           }
    //           FreeWrapper_7bcf(cur);
    //         } else { value = 0; }
    //       }
    //   done:
    //       *outValue = value;
    //       result = value != 0;
    //       if (mutex) ReleaseMutex(mutex);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Owner object identity is unknown; the packet only establishes a linked-list container with mutex and count fields at higher offsets (0x560-0x574) than the sibling pop sub_584CD0
    // UNRESOLVED: The node layout (value dword at +0, next pointer at +4, flag byte at +8) is read from the raw source text, not from field evidence
    // UNRESOLVED: The semantics of the node flag byte at +8 (whether its data needs SEH-guarded cleanup) is inferred, not documented
    // UNRESOLVED: 128 as WAIT_ABANDONED and the accept/reject of other wait codes are inferred from Windows API conventions
}
