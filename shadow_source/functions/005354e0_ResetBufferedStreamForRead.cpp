// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005354E0
// Canonical corpus name: sub_5354E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5354E0_005354e0.c

void UnknownObject::ResetBufferedStreamForRead()
{
    // Resets a buffered file stream context back to read mode: validates the mode byte at this+0x5C equals 'r' (114), resets buffer state fields, reinitializes the allocator, then either seeks to the data size at this+0x5D or closes the handle. Returns -1 on null this or wrong mode. Part of the file/audio-stream I/O system, called by AudioStreamBufferRead.
    // GUARD: Null check on this: when this is null the function exits early returning -1. [source:raw]
    // GUARD: Mode validation: the byte at this+0x5C must equal 114 ('r'); otherwise return -1. [guard:0, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Save the stream/handle value at this+0x44 into local v2 before the buffer state is reset. [field:this:0x00000044, source:raw]
    // ASSIGNMENT: Clear the remaining-bytes field at this+0x38 to 0. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Clear the EOF/error-flag field at this+0x3C to 0. [field:this:0x0000003C, source:raw]
    // ASSIGNMENT: Clear the field at this+0x4 to 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Reset the buffer-position field at this+0x0 to the saved handle value v2. [field:this:0x00000000, source:raw]
    // CALL: Reinitialize the allocator object: this+0x4C = sub_536E90(0). [callee:0x00536E90, field:this:0x0000004C, source:raw]
    // GUARD: Branch on the data-size field at this+0x5D: a non-zero value selects the seek path, zero selects the close path. [field:this:0x0000005D, source:raw]
    // CALL: Reset/init context state fields via ArithmeticComparison_5620(this). [callee:0x00535620, source:raw]
    // CALL: Seek the stream to the data position: sub_587F64(value at this+0x40, data size at this+0x5D, 0). [callee:0x00587F64, field:this:0x00000040, field:this:0x0000005D, source:raw]
    // RETURN: Return the result of the seek call on the seek path. [source:raw]
    // CALL: Close the file handle via sub_58AFE1(value at this+0x40) when no seek is needed. [callee:0x0058AFE1, field:this:0x00000040, source:raw]
    // RETURN: Return 0 on the no-seek/close path. [source:raw]
    // CALL: Invoked from AudioStreamBufferRead (0x00535390). [caller:0x00535390, source:raw]

    // Conservative worker pseudocode:
    //   int sub_5354E0(char *this) {
    //     if (!this || this[0x5C] != 114) return -1;
    //     int handle = *(int *)(this + 0x44);
    //     *(int *)(this + 0x38) = 0;
    //     *(int *)(this + 0x3C) = 0;
    //     *(int *)(this + 0x4) = 0;
    //     *(int *)(this + 0x0) = handle;
    //     *(int *)(this + 0x4C) = sub_536E90(0);
    //     if (*(int *)(this + 0x5D)) {
    //       ArithmeticComparison_5620(this);
    //       return sub_587F64(*(int *)(this + 0x40), *(int *)(this + 0x5D), 0);
    //     } else {
    //       sub_58AFE1(*(int *)(this + 0x40));
    //       return 0;
    //     }
    //   }
    // UNRESOLVED: Identity and layout of the this object (buffered stream context) are UNKNOWN.
    // UNRESOLVED: Semantics of the callee return values (sub_536E90 allocator creation, sub_587F64 seek result, sub_58AFE1 close) are unresolved here.
    // UNRESOLVED: Mode byte value 114 interpreted as ASCII 'r' is DERIVED from the literal; the exact stream mode encoding is not confirmed.
}
