// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537FE0
// Canonical corpus name: BitstreamEncoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitstreamEncoder_00537fe0.c

void UnknownObject::BitstreamEndBlockEncode()
{
    // Encodes an end-of-block marker into the bitstream shift register at this+0x16AB by OR-ing '2 << bitCount'. Accumulates bits while bitCount is small; when the register overflows, flushes two bytes to the output buffer (base this+0x8, offset this+0x14) and re-anchors the remaining bits. A capacity check on this+0x16A7 may force a second marker write and flush. Completes by calling BitStreamWriter and setting capacity this+0x16A7 to 7.
    // GUARD: Read bitCount at this+0x16AD. If bitCount <= 13, accumulate the marker; else flush the two-byte register. [field:this:0x000016AD, source:raw]
    // ASSIGNMENT: Append end-of-block marker bits: OR this+0x16AB with (2 << bitCount). [field:this:0x000016AB, source:raw]
    // STATE_TRANSITION: Accumulate path: bitCount at this+0x16AD becomes bitCount + 3. [field:this:0x000016AD, source:raw]
    // STATE_TRANSITION: Flush path: write low byte of this+0x16AB to buffer[base + offset] and high byte (this+0x16AC) to buffer[base + offset + 1] using base this+0x8 and offset this+0x14; advance offset by 2; bitCount -= 13; shift register this+0x16AB becomes (2 >> (16 - oldBitCount)). [field:this:0x00000008, field:this:0x00000014, field:this:0x000016AB, field:this:0x000016AC, field:this:0x000016AD, source:raw]
    // GUARD: Re-read bitCount at this+0x16AD; if bitCount <= 9, accumulate, else flush again. [field:this:0x000016AD, source:raw]
    // STATE_TRANSITION: Accumulate path: bitCount at this+0x16AD becomes bitCount + 7. [field:this:0x000016AD, source:raw]
    // STATE_TRANSITION: Second flush path: write low byte of this+0x16AB to buffer[base + offset] and high byte (this+0x16AC) to buffer[base + offset + 1]; advance offset this+0x14 by 2; bitCount -= 9; shift register this+0x16AB cleared to 0. [field:this:0x00000008, field:this:0x00000014, field:this:0x000016AB, field:this:0x000016AC, field:this:0x000016AD, source:raw]
    // CALL: Call BitStreamWriter(this) to write the completed bitstream block; return value retained as result. [callee:0x00539690, source:raw]
    // GUARD: Capacity check: if (capacity at this+0x16A7 - bitCount + 11) < 9, encode another end-of-block marker and flush. [field:this:0x000016A7, field:this:0x000016AD, source:raw]
    // STATE_TRANSITION: Marker-repeat branch mirrors the initial encode/flush: OR this+0x16AB with (2 << bitCount), accumulate or flush by the 13-bit threshold, then by the 9-bit threshold, and call BitStreamWriter again. [field:this:0x00000008, field:this:0x00000014, field:this:0x000016AB, field:this:0x000016AC, field:this:0x000016AD, callee:0x00539690, source:raw]
    // ASSIGNMENT: Set capacity this+0x16A7 to 7 on completion. [field:this:0x000016A7, source:raw]
    // RETURN: Return the retained result of BitStreamWriter(this). [callee:0x00539690, source:raw]

    // Conservative worker pseudocode:
    //   appendMarker(); // this+0x16AB |= 2 << bitCount; bitCount += 3 or flush
    //   if (!smallCapacityLeft()) { appendMarker(); flushIfFull(); }
    //   capacity = 7;
    //   return BitStreamWriter(this);
    // UNRESOLVED: Semantic role of this+0x16A7 as buffer capacity is derived from the existing analysis prose and the guard (capacity - bitCount + 11 < 9), not named in raw source.
    // UNRESOLVED: The codec meaning of the 3-bit and 7-bit accumulation increments is not established from evidence.
}
