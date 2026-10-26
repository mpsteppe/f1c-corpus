// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E1B0
// Canonical corpus name: Strlen
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Strlen_0058e1b0.c

void UnknownObject::Strlen()
{
    // Standard C string-length computation over a byte buffer. Returns the number of bytes from the start pointer to (but not including) the first null byte. Uses an alignment check followed by a byte-wise probe loop, then a word-wise zero-byte detection trick ((word + 2130640639) ^ ~word tested against 0x81010100) for aligned words, with per-byte fallback to locate the exact null position. The packet's ABI lead identifies it as strlen; the prelabel marks it as a DERIVED structural twin of StringLengthCheckDispatch (0045d4e0).
    // GUARD: If the input pointer is 4-byte aligned (low two bits zero), skip the byte-wise alignment loop and proceed directly to word-wise scanning. [source:raw]
    // LOOP: Scan the buffer one byte at a time while the address is not 4-byte aligned; if a byte read (offset 0x0 / 0x1 from the current position) is zero, return the offset of that byte from the string start. [source:raw, field:this:0x00000000, field:this:0x00000001]
    // CALCULATION: Read a 4-byte word and detect any zero byte within it using the expression (value + 2130640639) ^ ~value, checking the mask 0x81010100; if no zero byte is present, advance to the next word and repeat. [source:raw]
    // CALCULATION: When a zero byte is detected in a word, examine each byte of that word (byte 0, byte 1, mask 0xFF0000 for byte 2, mask 0xFF000000 for byte 3) to locate the exact null position and compute the returned length from the pointer difference. [source:raw]
    // RETURN: Return the difference between the final pointer (one past the null byte) and the original string pointer, i.e. the string length. [source:raw]

    // Conservative worker pseudocode:
    //   ptr = arg;
    //   if ((ptr & 3) != 0) { scan bytes until aligned; if zero, return offset; }
    //   while (true) {
    //     word = *ptr;
    //     if ((word + 2130640639) ^ ~word & 0x81010100) != 0 {
    //       locate zero byte in word; return its offset;
    //     }
    //     ptr += 1 word;
    //   }
    // UNRESOLVED: Caller-side contract (buffer validity, encoding, max length) is not present in the packet; all callers use the value as a string length, consistent with the strlen ABI lead.
}
