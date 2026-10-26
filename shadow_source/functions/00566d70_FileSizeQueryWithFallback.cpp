// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566D70
// Canonical corpus name: FileSizeQueryWithFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileSizeQueryWithFallback_00566d70.c

void UnknownObject::FileSizeQueryWithFallback()
{
    // Dispatches a 2-byte size query on an object, choosing between AudioStreamBufferRead and sub_587F64 based on a flag at this+0x10 (this[4]). Returns true iff the chosen read reports success (0). Used by QueuePop and NetworkBufferRead, suggesting an audio-stream vs network-buffer dual-path reader.
    // GUARD: Select the read path from the flag at this+0x10 (this[4]); non-zero routes to AudioStreamBufferRead, zero to sub_587F64. [field:this:0x00000010, source:raw]
    // CALL: Audio path: call AudioStreamBufferRead(*this, 0, 2) and test the result against 0. [callee:0x00535390, field:this:0x00000000, source:raw]
    // CALL: Fallback path: call sub_587F64(*this, 0, 2) and test the result against 0. [callee:0x00587F64, field:this:0x00000000, source:raw]
    // RETURN: Return true iff the selected read function returned 0. [source:raw, function:0x00566D70]

    // Conservative worker pseudocode:
    //   bool FileSizeQueryWithFallback(int *this) {
    //     if (this[4])
    //       return AudioStreamBufferRead(*this, 0, 2) == 0;
    //     return sub_587F64(*this, 0, 2) == 0;
    //   }
    // UNRESOLVED: Semantics of the this+0x10 flag selecting between the two readers is unknown; callers QueuePop and NetworkBufferRead imply audio-stream vs network-buffer contexts.
}
