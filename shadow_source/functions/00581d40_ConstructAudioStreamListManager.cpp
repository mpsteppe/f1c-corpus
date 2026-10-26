// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00581D40
// Canonical corpus name: sub_581D40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_581D40_00581d40.c

void UnknownObject::ConstructAudioStreamListManager()
{
    // Constructor for an audio-stream list manager. Zero-initializes the eight list fields (this[0..7], offsets 0x0-0x1C), allocates a 4-byte node wrapper and a 620-byte stream-manager buffer via OperatorNewNhMallocWrapper, runs NTimeCallbackLoopWithSEH_a6eb to construct two 308-byte audio stream objects using AudioStreamConstructWithVTableInit and SingleVTablePointerSet, appends the wrapper to list1 with LinkedListNodeAppend_6000, and pre-allocates two empty 308-byte nodes into list2 with LinkedListNodeAllocPrepend. Finishes by zeroing this[8] and byte this+40, setting this[9] to -1, and creating a mutex with CreateMutexA stored at this[8]; the flag byte at this+40 is set to 1 only when the mutex handle is non-null.
    // ASSIGNMENT: Zero-initialize the eight dword list fields this[0] through this[7] (offsets 0x0-0x1C): two heads, two tails, two cursors and two element counts. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // CALL: Allocate the 4-byte node wrapper with OperatorNewNhMallocWrapper; a local guard variable tracks the construction stage for the SEH frame (handler SEH_581D40) unwind cleanup. [callee:0x00587C03, global:0x0059CBA9]
    // CALL: Allocate the 620-byte stream-manager buffer with OperatorNewNhMallocWrapper; allocation failure leaves the wrapper node's link null. [callee:0x00587C03]
    // CALL: Initialize the buffer header (*v3 = 2) and construct two 308-byte audio stream objects via NTimeCallbackLoopWithSEH_a6eb using AudioStreamConstructWithVTableInit as the constructor callback and SingleVTablePointerSet as the vtable setup callback. [callee:0x0058A6EB, global:0x00581E80, global:0x0057BC70]
    // ASSIGNMENT: Link the constructed stream buffer pointer into the wrapper node (the 4-byte allocation's first dword). [source:raw]
    // CALL: Append the wrapper node to list1 with LinkedListNodeAppend_6000(node, 1). [callee:0x00586000]
    // LOOP: Pre-allocate two empty nodes into list2 with LinkedListNodeAllocPrepend for i in 0..616 stepping 308, positioning each at i plus the wrapper base. [callee:0x00583210, source:raw]
    // ASSIGNMENT: Reset the mutex-handle field this[8] (offset 0x20) and the initialized-flag byte this+40 (offset 0x28) to 0, and set this[9] (offset 0x24) to -1 before mutex creation. [field:this:0x00000020, field:this:0x00000028, field:this:0x00000024]
    // CALL: Create a mutex with CreateMutexA using a SECURITY_ATTRIBUTES configured with nLength 12, null security descriptor and inheritable handle, no owner and no name; store the returned handle at this[8] (offset 0x20). [global:0x0059E1AC, field:this:0x00000020]
    // STATE_TRANSITION: Mark the object initialized: set the flag byte at offset 0x28 to 1 only when the mutex handle is non-null; otherwise the object stays in the not-initialized state. [field:this:0x00000028, source:raw]
    // RETURN: Return this (the manager object) from all paths. [source:raw]

    // Conservative worker pseudocode:
    //   void *ConstructAudioStreamListManager(void *this) {
    //     for (int i = 0; i < 8; ++i) this[i] = 0;
    //     void *node = OperatorNewNhMallocWrapper(4);
    //     void *mgmt = 0;
    //     if (node) {
    //       mgmt = OperatorNewNhMallocWrapper(620);
    //       if (mgmt) {
    //         *(int *)mgmt = 2;
    //         NTimeCallbackLoopWithSEH_a6eb(mgmt + 4, 308, 2, AudioStreamConstructWithVTableInit, SingleVTablePointerSet);
    //         *(void **)node = mgmt + 4;
    //       } else {
    //         *(void **)node = 0;
    //       }
    //     }
    //     LinkedListNodeAppend_6000(node, 1);
    //     for (int i = 0; i < 616; i += 308)
    //       LinkedListNodeAllocPrepend(i + *(int *)node, 0);
    //     this[8] = 0;
    //     *(unsigned char *)this + 40 = 0;
    //     this[9] = -1;
    //     SECURITY_ATTRIBUTES sa = { 12, 0, 1 };
    //     HANDLE m = CreateMutexA(&sa, 0, 0);
    //     this[8] = m;
    //     if (m) *(unsigned char *)this + 40 = 1;
    //     return this;
    //   }
    // UNRESOLVED: Three byte_FF0000000000545x globals are reported as written but never appear as named operands in the decompiled body; they are likely IDA artifacts of the SEH frame (the LOBYTE(v12) stage writes), and their bit-level mapping is not established.
    // UNRESOLVED: The role split between the 4-byte wrapper node and the 620-byte manager buffer (two linked lists sharing one node) is inferred from LinkedListNodeAppend_6000 and LinkedListNodeAllocPrepend usage, not confirmed statically.
    // UNRESOLVED: The 308-byte stride and count 2 for NTimeCallbackLoopWithSEH_a6eb are taken verbatim from the raw source; the per-object layout inside the 620-byte buffer is not reconstructed here.
}
