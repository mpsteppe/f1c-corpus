// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0057FDE0
// Canonical corpus name: AudioStreamingThreadShutdown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStreamingThreadShutdown_0057fde0.c

void UnknownObject::AudioStreamingThreadShutdown()
{
    // Shuts down the audio streaming thread and its sockets: returns 8 if the init flag at +0xA74 is clear; otherwise invokes the virtual shutdown callback (vtable slot +0x74), terminates the thread, closes both streaming sockets, tears down streaming buffers, waits on the list mutex and frees every node of the linked list headed at +0xAC8 via virtual release plus FreeWrapper_7bcf, zeroes the list fields, releases the mutex, and runs full network cleanup. Returns 0 on success, 9 when network cleanup fails.
    // GUARD: If the WSAStartup/init flag at +0xA74 is clear, return 8 without doing anything. [field:this:0x00000A74, source:raw]
    // RETURN: Return 8 on the not-initialized path. [source:raw]
    // CALL: Dispatch the virtual shutdown callback through the vtable (field +0x0) slot at +0x74. [field:this:0x00000000, field:obj:0x00000074, source:raw]
    // CALL: Terminate the streaming thread and wait for its cleanup. [callee:0x00585550, source:raw]
    // CALL: Gracefully close both streaming sockets in sequence (first with 0, then with 1). [callee:0x0057C8E0, source:raw]
    // CALL: Tear down the streaming buffer structures via sub_585040 and sub_585130. [callee:0x00585040, callee:0x00585130, source:raw]
    // GUARD: When a mutex handle is present at +0xAD8, wait on it using the timeout stored at +0xADC. [field:this:0x00000AD8, field:this:0x00000ADC, global:0x0059E1A0, source:raw]
    // GUARD: Proceed to list destruction only when the wait succeeded or timed out (status 0 or 128). [source:raw]
    // LOOP: Walk the singly linked list headed at +0xAC8, advancing through each node's embedded next pointer. [field:this:0x00000AC8, field:*(this+0xAC8):0x00000000, source:raw]
    // GUARD: For each node whose byte flag (+0x8) and data pointer are both set, invoke the data object's virtual release (first vtable slot) with the flag 1. [field:*(this+0xAC8):0x00000008, field:*(*(this+0xAC8)+0x0):0x00000000, field:*(*(*(this+0xAC8)+0x0)+0x0):0x00000000, source:raw]
    // CALL: Free each visited list node with FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list head/tail/cursor/count fields at +0xAC8, +0xACC, +0xAD0 and +0xAD4 after the list is destroyed. [field:this:0x00000AC8, field:this:0x00000ACC, field:this:0x00000AD0, field:this:0x00000AD4, source:raw]
    // CALL: Release the mutex when it had been acquired. [field:this:0x00000AD8, global:0x0059E1A4, source:raw]
    // GUARD: If the full network cleanup fails, return 9. [callee:0x0057FBE0, source:raw]
    // RETURN: Return 0 on success, or 9 when network cleanup failed. [source:raw]

    // Conservative worker pseudocode:
    //   int AudioStreamingThreadShutdown(AudioStreamingThread* this) {
    //     if (!this->init_flag_0xA74) return 8;
    //     this->vtable_shutdown(this);
    //     ThreadTerminationWithWaitCleanup(this);
    //     SocketGracefulClose(&this->sockets[591], 0);
    //     SocketGracefulClose(&this->sockets[590], 1);
    //     sub_585040(this); sub_585130(this);
    //     int result = 0;
    //     HANDLE mutex = this->mutex_0xAD8;
    //     if (mutex) {
    //       DWORD status = WaitForSingleObject(mutex, this->mutex_timeout_0xADC);
    //       if (status == 0 || status == 128) {
    //         ListNode* node = this->list_head_0xAC8;
    //         while (node) {
    //           ListNode* next = node->next;
    //           if (node->flag_8 && node->data) {
    //             node->data->vtable[0](node->data, 1);
    //           }
    //           FreeWrapper_7bcf(node);
    //           node = next;
    //         }
    //         this->list_head_0xAC8 = 0;
    //         this->list_tail_0xACC = 0;
    //         this->list_cursor_0xAD0 = 0;
    //         this->list_count_0xAD4 = 0;
    //         if (this->mutex_0xAD8) ReleaseMutex(this->mutex_0xAD8);
    //       }
    //     }
    //     if (!NetworkCleanup_fbe0(this)) return 9;
    //     return result;
    //   }
    // UNRESOLVED: Identity of the virtual shutdown callback at vtable slot +0x74 is not resolvable from this packet.
    // UNRESOLVED: The payload object stored in each list node is opaque here; only its byte flag and first DWORD are observed.
    // UNRESOLVED: Semantics of sub_585040 and sub_585130 (streaming buffer teardown) are inferred from naming only.
    // UNRESOLVED: The SOCKET array indices (590 and 591 as dword indices) have no dedicated packet field references.
}
