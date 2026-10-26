// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059C0AC
// Canonical corpus name: sub_59C0AC
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59C0AC_0059c0ac.c

void UnknownObject::CharToUpper()
{
    // Case-maps one character to uppercase. For 8-bit values (charCode <= 0xFF) uses the CRT ctype flag byte byte_8D47E1 (bit 0x20 = lowercase) and the precomputed uppercase table byte_8D46E0. For larger values the input is reassembled into a wide codepoint and, when byte_8D47E1 marks a lead byte (bit 0x4), locale-aware sub_591FA1 performs the mapping using locale handles dword_8D48E4 and dword_8D46BC. When no mapping applies the input is returned unchanged.
    // GUARD: charCode <= 0xFF selects the single-byte fast path; larger values take the multibyte/locale path. [source:raw]
    // GUARD: Ctype flag check: bit 0x20 of byte_8D47E1[charCode] set means the 8-bit character is lowercase and can be uppercased via the table. [global:0x008D47E1, source:raw]
    // RETURN: Return byte_8D46E0[charCode], the precomputed uppercase mapping from the 8-bit table. [global:0x008D46E0, global:0x008D47E1, source:raw]
    // CALCULATION: Reassemble the multibyte input into a 16-bit wide codepoint: BYTE2(charCode) = BYTE1(charCode) and HIBYTE(charCode) = low byte. The later lead-byte test reads byte_8D47E1 from the unmodified original value (BYTE1(v1)), not the reassembled one. [source:raw]
    // GUARD: Ctype lead-byte check: bit 0x4 of byte_8D47E1[BYTE1(v1)] (second byte of the unmodified input) must be set, and sub_591FA1 must return non-zero, for the mapped result to be used. [global:0x008D47E1, source:raw]
    // CALL: Call sub_591FA1 with locale handle dword_8D48E4, flag 0x200u, the reassembled 2-byte codepoint, destination buffer DestStr, and dword_8D46BC as a later argument; returns a success flag. [callee:0x00591FA1, global:0x008D48E4, global:0x008D46BC, source:raw]
    // RETURN: On locale-mapping success, compose the uppercased 16-bit result from DestStr bytes: DestStr[1] + (DestStr[0] << 8). [source:raw]
    // RETURN: Default path: return charCode unchanged when no uppercase mapping applies. [source:raw]

    // Conservative worker pseudocode:
    //   unsigned int CharToUpper(unsigned int charCode)
    //   {
    //     if (charCode <= 0xFF)
    //     {
    //       if ((byte_8D47E1[charCode] & 0x20) == 0x20)
    //         return (unsigned __int8)byte_8D46E0[charCode];
    //     }
    //     else
    //     {
    //       BYTE2(charCode) = BYTE1(charCode);
    //       HIBYTE(charCode) = (unsigned char)charCode;
    //       if ((byte_8D47E1[BYTE1(originalCharCode)] & 0x4) != 0 &&
    //           sub_591FA1(dword_8D48E4, 0x200u, (LPCSTR)&charCode + 2, 2, DestStr, 2, dword_8D46BC, 1))
    //         return (unsigned __int8)DestStr[1] + ((unsigned __int8)DestStr[0] << 8);
    //     }
    //     return charCode;
    //   }
    // UNRESOLVED: Meaning of the 0x200u flag passed to sub_591FA1 is unknown.
    // UNRESOLVED: Role of dword_8D46BC as a later argument to sub_591FA1 (locale vs LANGID) is unconfirmed.
    // UNRESOLVED: Exact encoding produced by the byte reassembly (MBCS lead+trail into a 16-bit codepoint) is inferred, not independently verified.
    // UNRESOLVED: Distinction between locale handles dword_8D48E4 and dword_8D46BC is unconfirmed.
}
