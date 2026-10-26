// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00599348
// Canonical corpus name: BufferTruncationShrink
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BufferTruncationShrink_00599348.c

void UnknownObject::BufferTruncateRemoveRange()
{
    // Removes a3 bytes of buffer content starting at offset a2: frees any previously held string data, caps the removed count to the available data (this[2] - a2), shifts the surviving tail left across the removed range via sub_58B130, validates the new end position with sub_599560, commits the new size into this[2], and null-terminates the buffer at the new end. Calls sub_59AF68 when the remove offset a2 exceeds the current size. Returns this.
    // GUARD: Guard: when the buffer size this[2] is smaller than the remove offset a2, call sub_59AF68 to handle the invalid truncation. [field:this:0x00000008, callee:0x0059AF68]
    // CALL: Call ConditionalStringFreeWithLengthCheck(this) to free previously held string data before reshaping the buffer. [callee:0x005995E5]
    // CALCULATION: Compute the surviving data length this[2] - a2 and cap the removed count v4 to it: v4 = min(a3, this[2] - a2). [field:this:0x00000008, source:raw]
    // GUARD: Guard: only shift and update the buffer when the effective removed count v4 is non-zero. [source:raw]
    // CALL: Call sub_58B130 to shift the buffer tail from a2 + this[1] by v4 bytes left, moving v5 - v4 bytes across the removed range. [callee:0x0058B130, field:this:0x00000004]
    // CALCULATION: Compute the new buffer size v6 = this[2] - v4. [field:this:0x00000008]
    // CALL: Call sub_599560(v6, 0) to validate the new buffer position before committing the size. [callee:0x00599560]
    // ASSIGNMENT: When sub_599560 returns non-zero, write the new size into this[2] and null-terminate the data at v6 + this[1]. [field:this:0x00000008, field:this:0x00000004]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_599348(_DWORD *this, unsigned int off, unsigned int count) {
    //     if (this[2] < off) sub_59AF68();
    //     ConditionalStringFreeWithLengthCheck(this);
    //     unsigned int remaining = this[2] - off;
    //     unsigned int remove = (remaining < count) ? remaining : count;
    //     if (remove) {
    //       sub_58B130(off + this[1], off + this[1] + remove, remaining - remove);
    //       unsigned int newsize = this[2] - remove;
    //       if ((unsigned __int8)sub_599560(newsize, 0)) {
    //         this[2] = newsize;
    //         *(_BYTE *)(newsize + this[1]) = 0;
    //       }
    //     }
    //     return this;
    //   }
    // UNRESOLVED: The buffer object type and the exact allocation policy behind this[1] (data pointer) and this[2] (size) are not established here.
    // UNRESOLVED: Meaning of the second argument 0 to sub_599560 is unknown from this function alone.
}
