// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058D78E
// Canonical corpus name: StreamByteOutputWithBufferManagement
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamByteOutputWithBufferManagement_0058d78e.c

void UnknownObject::StreamByteOutputWithBufferManagement()
{
    // Buffered single-byte stream output used by the printf-family engine: decrements the remaining-buffer count a2[1]; when the count goes negative the byte is handed to the low-level writer sub_58CF35(a1, a2), otherwise it is stored at *a2 and the write pointer advances. If the emit result is -1 (error sentinel) the running count *a3 is set to -1, otherwise it is incremented. Returns the count pointer a3.
    // GUARD: Decrement the remaining-buffer count a2[1] and test its sign; a negative value indicates the current buffer is exhausted. [source:raw]
    // CALL: When the buffer is exhausted, emit byte a1 through the underlying writer sub_58CF35(a1, a2) and capture its return value. [callee:0x0058CF35, source:raw]
    // ASSIGNMENT: Otherwise store a1 at the current write pointer (*a2) and advance the pointer (*a2)++. [source:raw]
    // GUARD: Branch on whether the emit result is -1: set *a3 = -1 on error, else increment the running count (*a3)++. [source:raw]
    // RETURN: Return a3, the stream byte-count pointer. [source:raw]

    // Conservative worker pseudocode:
    //   int StreamByteOutputWithBufferManagement(unsigned char ch, int* buf, int* count) {
    //     int res;
    //     if (--buf[1] < 0) res = sub_58CF35(ch, buf);
    //     else { *buf[0]++ = ch; res = ch; }
    //     if (res == -1) *count = -1; else ++*count;
    //     return (int)count;
    //   }
    // UNRESOLVED: The a2 buffer layout (a2[0] write pointer, a2[1] remaining count) is inferred from usage; the overflow/flush semantics of the low-level writer sub_58CF35 are outside this packet's evidence.
    // UNRESOLVED: Callers LoopWithSentinelTermination and CharByCharStringProcessingWithTerminatorCheck treat this as the low-level byte sink of the printf engine; that role is inferred from the call graph only.
}
