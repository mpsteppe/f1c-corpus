// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00536E90
// Canonical corpus name: sub_536E90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_536E90_00536e90.c

void UnknownObject::CRC32Compute()
{
    // Computes a CRC over a byte buffer using the dword_5B7860 lookup table, starting from a seed argument. An unrolled main loop processes 8 bytes per iteration, then a tail loop handles the remaining bytes one at a time. Returns the bitwise complement of the final CRC state. A null data pointer returns 0 immediately.
    // GUARD: If the data pointer argument a2 is null, return 0 immediately without computing a CRC. [function:0x00536E90, source:raw]
    // CALCULATION: Seed the CRC state from the initial value argument; the seed is referenced through the low byte (field 0x0) and the upper bits (field 0x2) of the initial value. [field:this:0x00000000, field:this:0x00000002, source:raw]
    // LOOP: Unrolled main loop: while at least 8 bytes remain, consume 8 bytes per iteration, updating the CRC state by XORing the shifted state with dword_5B7860 table entries keyed by the current byte XORed with the low byte of the state. [global:0x005B7860, source:raw]
    // LOOP: Tail loop: consume the remaining 0-7 bytes one at a time, each updating the CRC state through the dword_5B7860 table. [global:0x005B7860, source:raw]
    // RETURN: Return the bitwise complement of the final CRC state. [function:0x00536E90, source:raw]

    // Conservative worker pseudocode:
    //   unsigned crc32(unsigned seed, const unsigned char* data, unsigned len) {
    //     if (!data) return 0;
    //     unsigned crc = ~seed;
    //     while (len >= 8) { /* unrolled: 8 bytes per iteration over crc_table * /
    //       crc = crc_table[data[0] ^ (unsigned char)crc] ^ (crc >> 8);
    //       /* ... repeated for data[1]..data[7] ... * /
    //       len -= 8; data += 8;
    //     }
    //     while (len--) crc = crc_table[*data++ ^ (unsigned char)crc] ^ (crc >> 8);
    //     return ~crc;
    //   }
    // UNRESOLVED: dword_5B7860 is a byte-indexed 256-entry CRC table; its generator polynomial is not evidenced in this packet.
}
