// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00541470
// Canonical corpus name: AudioBufferClear
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioBufferClear_00541470.c

void UnknownObject::AudioBufferClear()
{
    // Conditionally locks a 96-byte region of an audio buffer for writing. Reads the buffer base pointer at this+0x114C; if non-null, computes a sub-offset inside the buffer from this+0x1148 and calls BufferLockAllocate (00540F00) with (this, buffer_base + 36 * sub_index, 96, 0, 0). Returns 0 immediately when the buffer pointer is null. Invoked by sub_5613E0 (005613E0).
    // ASSIGNMENT: Default return value result = 0 is established before the buffer check. [source:raw]
    // GUARD: Guard on the buffer base pointer this[0x114C] (this[1107]): when null the function returns 0 immediately; the buffer is not allocated or not ready. [field:this:0x0000114C, source:raw]
    // CALCULATION: Lock target = buffer_base(this[0x114C]) + 36 * this[0x1148] (this[1106]); the sub-index at 0x1148 selects which 96-byte region of the buffer to address. [field:this:0x00001148, field:this:0x0000114C, source:raw]
    // CALL: Call BufferLockAllocate(this, computed_lock_target, 96, 0, 0) to lock (prepare for write) the 96-byte region. [callee:0x00540F00, source:raw]
    // RETURN: Return the BufferLockAllocate result when the buffer pointer was non-null, otherwise return 0. [source:raw]
    // CALL: Invoked by sub_5613E0 (005613E0) to clear a selected region of an audio buffer. [caller:0x005613E0, source:raw]

    // Conservative worker pseudocode:
    //   int AudioBufferClear(int* this) {
    //     int result = 0;
    //     int buf = this[1107];
    //     if (buf)
    //       return BufferLockAllocate(this, (void*)(buf + 36 * this[1106]), 96, 0, 0);
    //     return result;
    //   }
    // UNRESOLVED: BufferLockAllocate (00540F00) semantics and the meaning of its 96-byte region are not defined in this function
    // UNRESOLVED: The role of the sub-index at this+0x1148 and the structure of the audio buffer at this+0x114C are not verifiable from this function alone
}
