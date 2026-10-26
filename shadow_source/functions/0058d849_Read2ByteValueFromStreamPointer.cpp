// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058D849
// Canonical corpus name: Read2ByteValueFromStreamPointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Read2ByteValueFromStreamPointer_0058d849.c

void UnknownObject::Read2ByteValueFromStreamPointer()
{
    // Reads a 2-byte value from a caller-owned stream pointer and advances that pointer by 4 bytes. a1 points to a pointer slot; the slot value is incremented by 4 and the 16-bit value at its previous position is returned as a signed int. On-frame-path stream read helper.
    // ASSIGNMENT: Advance the caller-owned stream pointer by 4 bytes: *a1 += 4. [field:this:0x00000000, source:raw]
    // RETURN: Read the 2-byte value at the pointer's previous position (*(_WORD *)(*a1 - 4)) and return it as a signed 16-bit value. [field:this:0x00000000, source:raw]
    // CALL: Called by sub_58D04D (0x0058D04D) to consume 2-byte stream values from a shared stream pointer. [caller:0x0058D04D, source:raw]

    // Conservative worker pseudocode:
    //   int16 sub_58D849(uint32* streamPtr) {
    //     *streamPtr += 4;
    //     return *(int16*)(*streamPtr - 4);
    //   }
    // UNRESOLVED: 4-byte pointer advance paired with a 2-byte read: the read stride (2) differs from the pointer step (4), likely padding/alignment in the stream format.
    // UNRESOLVED: Owning stream class and the meaning of the 4-byte step are unknown; a1 points to a pointer slot owned by the caller.
}
