// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00537F30
// Canonical corpus name: BitstreamWriteBits
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BitstreamWriteBits_00537f30.c

void UnknownObject::BitstreamShiftWrite()
{
    // Accumulates bits into the bitstream shift register this+0x16AB: ORs (a3 << bitCount) and raises bitCount at this+0x16AD by 3. When bitCount exceeds 13, flushes the two-byte register to the output buffer (base this+0x8, offset this+0x14), advances the offset by 2, decrements bitCount by 13, and re-anchors the register to (uint16)a3 >> (16 - oldBitCount). Always calls ChecksummedBufferWriter(a2, 1) and returns its result.
    // GUARD: Read bitCount at this+0x16AD; if bitCount <= 13 accumulate, else flush the two-byte register. [field:this:0x000016AD, source:raw]
    // STATE_TRANSITION: Accumulate path: bitCount this+0x16AD becomes bitCount + 3 and this+0x16AB is OR-ed with (a3 << bitCount). [field:this:0x000016AB, field:this:0x000016AD, source:raw]
    // STATE_TRANSITION: Flush path: write low byte of this+0x16AB to buffer[base + offset] and high byte (this+0x16AC) to buffer[base + offset + 1] using base this+0x8 and offset this+0x14; advance offset by 2; bitCount -= 13; shift register this+0x16AB becomes (uint16)a3 >> (16 - oldBitCount). [field:this:0x00000008, field:this:0x00000014, field:this:0x000016AB, field:this:0x000016AC, field:this:0x000016AD, source:raw]
    // CALL: Call ChecksummedBufferWriter(a2, 1) for output/checksum tracking; return value is the function result. [callee:0x005397A0, source:raw]
    // RETURN: Return the result of ChecksummedBufferWriter(a2, 1). [callee:0x005397A0, source:raw]

    // Conservative worker pseudocode:
    //   if (bitCount <= 13) { bitCount += 3; shiftReg |= a3 << bitCount; }
    //   else { flushTwoBytes(); bitCount -= 13; shiftReg = (uint16)a3 >> (16 - oldBitCount); }
    //   return ChecksummedBufferWriter(a2, 1);
    // UNRESOLVED: The meaning of the +3 accumulation step and the 13-bit flush threshold (whether the unit is 3 bits per call) is derived from source patterns and existing analysis prose, not named in evidence.
}
