// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00562090
// Canonical corpus name: Base64Encode
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Base64Encode_00562090.c

void UnknownObject::Base64Encode()
{
    // Encodes a2 bytes from input buffer a1 into a Base64 string written to output buffer a3, using Base64IndexToCharEncoding (0x00564C40) as the 6-bit-index to character lookup. Input is consumed in 3-byte groups; a final partial group is padded with zero bytes. The output string is null-terminated. When a2 <= 0 only the null terminator is written.
    // GUARD: If input length a2 <= 0, write a single 0 terminator byte to output a3 and skip encoding. [source:raw]
    // LOOP: Loop over 3-byte groups of input; each group reads up to three bytes from a1, zero-padding when fewer than three bytes remain. [source:raw]
    // CALCULATION: Pack the three group bytes into four 6-bit indices (a3 low byte >> 2, high nibble/low 2 bits split, and 4-bit/low 6-bit splits via the byte-cast arithmetic). [source:raw]
    // CALL: For each of the four indices j, call Base64IndexToCharEncoding (0x00564C40) and store the resulting character into output a3. [callee:0x00564C40, source:raw]
    // LOOP: Continue group processing until all a2 input bytes are consumed. [source:raw]
    // RETURN: Null-terminate the output string at the last written character and return. [function:0x00562090, source:raw]

    // Conservative worker pseudocode:
    //   int sub_562090(char* src, int len, char* dst) {
    //     if (len <= 0) { *dst = 0; return dst; }
    //     for (int i = 0, out = 0; ; i += 3) {
    //       char trio[3] = { 0 };
    //       for (int k = 0; k < 3; ++k)
    //         if (i + k < len) trio[k] = src[i + k];
    //       unsigned v = (trio[0] << 16) | (trio[1] << 8) | trio[2];
    //       for (int j = 0; j < 4; ++j) dst[out++] = Base64IndexToCharEncoding((v >> (18 - 6*j)) & 0x3F);
    //       if (i + 3 >= len) break;
    //     }
    //     dst[out] = 0;
    //     return dst;
    //   }
    // UNRESOLVED: The packed 24-bit to 6-bit index expansion is expressed in the packet via byte casts of the output pointer a3; the exact bit layout above is recovered from standard Base64 semantics (DERIVED), not packet-confirmed.
    // UNRESOLVED: Partial final groups are zero-padded here; no '=' padding characters are written by this function.
    // UNRESOLVED: Decompiler aliasing of a3 (output buffer, 3-byte input staging, and index holder) cannot be fully separated from the packet alone.
}
