// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00588E4E
// Canonical corpus name: sub_588E4E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_588E4E_00588e4e.c

void UnknownObject::LocaleStringParser()
{
    // Parses a locale/configuration string and either returns the stored default locale or commits a matched named locale into the global locale state. A null input returns null. An input equal to the ASCII string "C" (byte 67 followed by a null terminator) is treated as the built-in default locale: it zeroes the optional word and dword outputs and returns the caller-provided output buffer. Otherwise the input is matched against the two stored locale compare strings via sub_58FB90; on a successful match the input is parsed into a local buffer (sub_588F8B), validated against the locale data block (sub_58FD90), and the parsed result is committed into the stored locale buffers (sub_589057 / sub_58FCA0) with the conversion dword updated from word_8D3E4C. The optional word output receives six bytes of the locale data block and the optional dword output receives four bytes of the conversion value; the output buffer is normalized before the stored compare-string buffer is returned.
    // GUARD: Early-out: a null input string pointer returns null immediately [source:raw]
    // GUARD: Default-locale fast path: when the first input byte equals 67 ('C') and the second byte is the null terminator, the input is the built-in default locale [guard:0, field:this:0x00000000, field:this:0x00000001, source:raw]
    // ASSIGNMENT: Writes the default-locale marker into the output buffer a2: a 'C' byte followed by a null terminator [source:raw]
    // ASSIGNMENT: When the optional word output a3 is non-null, zeroes its three words [source:raw]
    // ASSIGNMENT: When the optional dword output a4 is non-null, zeroes the dword it points at [source:raw]
    // RETURN: Returns the output buffer a2 on the default-locale path [source:raw]
    // CALL: Locale name matching: the input is compared against the stored compare string unk_5E6468 and the stored locale string unk_5E63E4 via sub_58FB90; both comparisons must succeed for the named-locale path [global:0x005E6468, global:0x005E63E4, callee:0x0058FB90, source:raw]
    // CALL: Parses the matched input into the local buffer v5 with sub_588F8B; a parse failure aborts the function [callee:0x00588F8B, source:raw]
    // CALL: Validates the parsed buffer against the locale data block unk_8D3E48 via sub_58FD90; a validation failure aborts the function [callee:0x0058FD90, global:0x008D3E48, source:raw]
    // ASSIGNMENT: Stores the low 16 bits of word_8D3E4C into dword_8D3E50 as the locale conversion result [global:0x008D3E4C, global:0x008D3E50, source:raw]
    // CALL: Commits the parsed locale into the stored compare string unk_5E6468 via sub_589057 and normalizes the stored locale buffer unk_5E63E4 via sub_58FCA0 [callee:0x00589057, callee:0x0058FCA0, global:0x005E6468, global:0x005E63E4, source:raw]
    // CALL: When the optional word output a3 is non-null, copies six bytes of the locale data block unk_8D3E48 into it via MemoryCopy_cc00 [callee:0x0058CC00, global:0x008D3E48, source:raw]
    // CALL: When the optional dword output a4 is non-null, copies four bytes of the conversion value dword_8D3E50 into it via MemoryCopy_cc00 [callee:0x0058CC00, global:0x008D3E50, source:raw]
    // CALL: Normalizes the output buffer a2 via sub_58FCA0 before returning [callee:0x0058FCA0, source:raw]
    // RETURN: Returns the stored compare string buffer unk_5E6468 as the parse result [global:0x005E6468, source:raw]

    // Conservative worker pseudocode:
    //   void* LocaleStringParser(input, out, words, dword) {
    //     if (!input) return 0;
    //     if (input[0] == 67 && input[1] == 0) {
    //       out[0] = 67; out[1] = 0;
    //       if (words) { words[0] = 0; words[1] = 0; words[2] = 0; }
    //       if (dword) *dword = 0;
    //       return out;
    //     }
    //     if (match(unk_5E6468, input) && match(unk_5E63E4, input)) {
    //       if (!parse(v5, input)) return 0;
    //       if (!validate(v5, &unk_8D3E48, v5)) return 0;
    //       dword_8D3E50 = (u16)word_8D3E4C;
    //       commit(unk_5E6468, v5);
    //       normalize(unk_5E63E4);
    //     }
    //     if (words) MemoryCopy(words, &unk_8D3E48, 6);
    //     if (dword) MemoryCopy(dword, &dword_8D3E50, 4);
    //     normalize(out);
    //     return &unk_5E6468;
    //   }
    // UNRESOLVED: The exact role and content layout of the two stored locale buffers unk_5E6468 and unk_5E63E4 are not defined here; one is the committed parse result and the other a comparison source, but their string encoding and lifetime are unknown
    // UNRESOLVED: The meaning of the word_8D3E4C-to-dword_8D3E50 conversion value (a numeric locale identifier or code page) is not evidenced by this packet
    // UNRESOLVED: Whether a1 is a NUL-terminated string or a fixed-length buffer is not evidenced; the 'C' fast path only probes the first two bytes
}
