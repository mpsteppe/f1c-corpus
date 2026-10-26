// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00517F35
// Canonical corpus name: ByteArrayToInt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteArrayToInt_00517f35.c

void UnknownObject::ByteArrayBEToInt()
{
    // Assembles a 4-byte big-endian byte array into a single 32-bit integer by shifting each unsigned byte into place. Pure utility with no guards, globals, or calls.
    // CALCULATION: Combine the four bytes at a1[0..3] as a big-endian integer: a1[0] is the most significant byte, a1[3] the least significant, via chained left shifts and additions of unsigned byte reads. [field:this:0x00000000, field:this:0x00000001, field:this:0x00000002, field:this:0x00000003, source:raw]
    // RETURN: Return the assembled integer value. [function:0x00517F35, source:raw]

    // Conservative worker pseudocode:
    //   return a1[3] + ((a1[2] + ((a1[1] + ((unsigned)a1[0] << 8)) << 8)) << 8);
}
