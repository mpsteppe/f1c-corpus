// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00539690
// Canonical corpus name: BitStreamWriter
// Owner: Bit_Stream_Writer [DERIVED]
// Raw source: functions/BitStreamWriter_00539690.c

void Bit_Stream_Writer::BitstreamFlushRegister()
{
    // Flushes the accumulated bitstream shift register to the output buffer. If the bit count is exactly 16, writes both bytes to the buffer, advances the buffer index by 2, and resets the accumulator and bit count to 0. If the bit count is between 8 and 15, writes the low byte, promotes the high byte into the accumulator, advances the index by 1, and decrements the bit count by 8. Returns the remaining bit count.
    // ASSIGNMENT: Read the current bit count from this+5805 into result. [field:this:0x000016AD, source:raw]
    // GUARD: If bit count == 16, perform a full two-byte flush. [field:this:0x000016AD, source:raw]
    // ASSIGNMENT: Write the low accumulator byte (this+5803) to output buffer at index this+20. [field:this:0x000016AB, field:this:0x00000008, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Write the high accumulator byte (this+5804) to output buffer at index+1 and advance the buffer index by 2. [field:this:0x000016AC, field:this:0x00000008, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Clear the 16-bit accumulator (this+5803) and reset the bit count (this+5805) to 0. [field:this:0x000016AB, field:this:0x000016AD, source:raw]
    // GUARD: Else if bit count >= 8, perform a single-byte flush. [field:this:0x000016AD, source:raw]
    // ASSIGNMENT: Write the low accumulator byte to the output buffer at index this+20; promote the high byte (this+5804) into the accumulator; advance the buffer index by 1. [field:this:0x00000008, field:this:0x00000014, field:this:0x000016AB, field:this:0x000016AC, source:raw]
    // CALCULATION: Decrement the bit count by 8 (this+5805 -= 8). [field:this:0x000016AD, source:raw]
    // RETURN: Return the remaining bit count to the caller BitstreamEncoder. [source:raw, caller:0x00537FE0]

    // Conservative worker pseudocode:
    //   int sub_539690(int this) {
    //     int bits = *(this + 5805);
    //     if (bits == 16) {
    //       buffer[index] = accumulatorLow; buffer[index+1] = accumulatorHigh;
    //       index += 2; accumulator = 0; bits = 0;
    //     } else if (bits >= 8) {
    //       buffer[index] = accumulatorLow;
    //       accumulator = accumulatorHigh; bits -= 8; index += 1;
    //     }
    //     return bits;
    //   }
    // UNRESOLVED: Bit ordering (MSB-first vs LSB-first) of the accumulator at this+5803/5804 is not determinable from static evidence.
    // UNRESOLVED: Ownership and capacity of the output buffer referenced by this+8 are caller-provided.
    // UNRESOLVED: The policy of clearing the accumulator only on a full 16-bit flush while partial flushes keep residual bits is a design detail not further constrained here.
}
