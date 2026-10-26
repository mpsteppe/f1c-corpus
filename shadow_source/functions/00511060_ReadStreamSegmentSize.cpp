// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00511060
// Canonical corpus name: StreamingDataReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StreamingDataReader_00511060.c

void UnknownObject::ReadStreamSegmentSize()
{
    // Reads a 2-byte big-endian segment size from a byte stream, dispatching it together with a stored value into a parameterized dispatcher object (state code 90), then skips the remaining segment bytes via a stream callback.
    // ASSIGNMENT: Load the stream state object from this+0x14 and its current read pointer and remaining-byte count from stream-state words 0 and 1. [field:this:0x00000014, field:*(this+0x14):0x00000000, source:raw]
    // GUARD: If the stream has no remaining bytes, refill via the stream refill callback and reload the read pointer and count. [field:this:0x00000014, field:*(this+0x14):0x00000000, source:raw]
    // CALL: Invoke the refill callback stored in stream-state word 3; if it returns false, abort with 0. [source:raw]
    // CALCULATION: Read the first byte as the high byte of a 16-bit value and advance the read pointer past it. [field:*(this+0x14):0x00000000, source:raw]
    // GUARD: If only one byte remained before the first read, refill again so the second byte can be read. [field:this:0x00000014, source:raw]
    // CALL: Second invocation of the stream refill callback (word 3) when the stream is short; returning false aborts with 0. [source:raw]
    // CALCULATION: Form the big-endian 16-bit size: second byte plus first byte shifted into the high byte. [field:*(this+0x14):0x00000000, source:raw]
    // ASSIGNMENT: Write dispatcher state: obj+0x14 = 90, obj+0x18 = stored value read from this+0x178, obj+0x1C = computed size. [field:this:0x00000000, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000178, field:obj:0x0000001C]
    // CALL: Dispatch obj vtable entry at obj+0x4 with argument 1 (parameterized state dispatch). [field:obj:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: Consume the two bytes from the stream: read pointer becomes the second-byte position plus 1, remaining count becomes the pre-decrement count minus 1. [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // CALL: Invoke the skip callback at stream-state plus 16 with the remaining segment byte count (size minus 2). [field:this:0x00000014, source:raw]
    // RETURN: Return 1 on success. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_511060(StreamReader* this) {
    //     StreamState* s = (StreamState*)this->state;            // this+0x14
    //     unsigned char* p = s->pos; int remaining = s->remaining;
    //     if (remaining == 0) { if (!refill(this)) return 0; p = s->pos; remaining = s->remaining; }
    //     int hi = *p++; --remaining;
    //     if (remaining == 0) { if (!refill(this)) return 0; p = s->pos; remaining = s->remaining; }
    //     int size = (*p) + (hi << 8);                          // big-endian 16-bit
    //     Dispatcher* obj = (Dispatcher*)*this;                  // this+0x0
    //     obj->state = 90; obj->stored = this->stored; obj->size = size;   // obj+0x14 / +0x18 / +0x1C
    //     obj->paramDispatch(this, 1);                          // obj+0x4
    //     s->pos = p + 1; s->remaining = remaining - 1;
    //     this->state->skip(this, size - 2);                    // stream-state + 16
    //     return 1;
    //   }
    // UNRESOLVED: Identity and semantics of the obj+0x4 dispatch and the stream-state plus 16 skip callback are caller-supplied.
    // UNRESOLVED: The backing store of the stream refill callback (stream-state word 3) is not defined in this function.
}
