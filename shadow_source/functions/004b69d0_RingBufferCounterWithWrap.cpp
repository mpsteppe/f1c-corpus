// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B69D0
// Canonical corpus name: RingBufferCounterWithWrap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RingBufferCounterWithWrap_004b69d0.c

void UnknownObject::RingBufferCounterWithWrap()
{
    // Advances a circular-buffer read index by one with modulo wrap. Reads the read index (this+0x9BC) and compares it with the write index (this+0x9B8); when they are equal the buffer is treated as empty and the read index is returned unchanged. Otherwise computes the wrapped successor v2 = (read+1) % size, stores it into the read index slot (this+0x9BC), where size is this+0x9B4, and returns the wrap quotient (read+1) / size. Called by sub_4B7860 (004B7860).
    // ASSIGNMENT: Read the current read index from this[623] (this+0x9BC) into result. [field:this:0x000009BC, source:raw]
    // GUARD: If the read index equals the write index this[622] (this+0x9B8), the buffer is empty: skip the advance and return the read index unchanged. [field:this:0x000009B8, field:this:0x000009BC, source:raw]
    // CALCULATION: Compute the wrapped successor v2 = (result+1) % this[621] (modulus this+0x9B4) and the wrap quotient result = (result+1) / this[621]. [field:this:0x000009B4, source:raw]
    // ASSIGNMENT: Write the wrapped successor v2 back into the read index slot this[623] (this+0x9BC). [field:this:0x000009BC, source:raw]
    // RETURN: Return the read index unchanged when write equals read, or the wrap quotient (read+1)/size after an advance. [field:this:0x000009BC, source:raw]
    // CALL: Invoked by sub_4B7860 (004B7860) as part of its buffer management. [caller:0x004B7860, source:raw]

    // Conservative worker pseudocode:
    //   int RingBufferCounterWithWrap(int* this) {
    //     int read = this[623];
    //     if (read == this[622]) return read;
    //     int next = (read + 1) % this[621];
    //     this[623] = next;
    //     return (read + 1) / this[621];
    //   }
    // UNRESOLVED: Element type and capacity meaning of this+0x9B4 are not defined here; it is only used as the wrap modulus.
    // UNRESOLVED: Equality of read and write index is read as buffer empty per the skeleton fill, but the full/empty convention of the ring buffer is not established by this packet.
    // UNRESOLVED: Consumption pattern of the returned wrap quotient by the caller sub_4B7860 (004B7860) is outside this function.
}
