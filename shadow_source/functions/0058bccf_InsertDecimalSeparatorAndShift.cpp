// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BCCF
// Canonical corpus name: sub_58BCCF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BCCF_0058bccf.c

void UnknownObject::InsertDecimalSeparatorAndShift()
{
    // In-place formatter that overwrites the first non-digit character of a numeric string with the locale decimal separator byte_5E6BD8 and left-shifts the remaining tail by one byte, returning the character displaced out the end (normally the string terminator). Character classification is single-byte (off_5E69C8 lookup) or multi-byte (CharacterEncodingConvertViaLookupTableFallback) depending on cbMultiByte.
    // ASSIGNMENT: Set v1 = a1 so the scan starts at the first byte of the string. [source:raw]
    // GUARD: If sub_58B465(*a1) already returns 101 the first character is digit-class and no scan runs; otherwise scan forward from v1. [callee:0x0058B465, field:this:0x00000000, source:raw]
    // LOOP: Advance v1 while the current character classifies as digit-class: when cbMultiByte <= 1 read the flag v2 = off_5E69C8[0][*v1] & 4 from the char-type table, otherwise use the multi-byte classifier CharacterEncodingConvertViaLookupTableFallback(*v1, 4). [callee:0x0058C674, global:0x005E69C8, global:0x005E6BD4, source:raw]
    // ASSIGNMENT: Save result = *v1 (the first non-digit character, or the terminator) and overwrite the character at v1 with the decimal separator byte_5E6BD8. [global:0x005E6BD8, field:this:0x00000000, source:raw]
    // LOOP: Left-shift the string tail starting at v4 = v1 + 1 (the second byte when v1 is the string head at this:0x0): repeatedly store result into *v4, read *v4 as the new result, and advance v4 while the byte just read is non-zero. [field:this:0x00000001, source:raw]
    // RETURN: Return the final displaced character (the string terminator carried out of the end of the shift). [function:0x0058BCCF, source:raw]

    // Conservative worker pseudocode:
    //   char sub_58BCCF(char *a1) {
    //     char *v1 = a1;
    //     if (sub_58B465(*a1) != 101) {
    //       do {
    //         ++v1;
    //         int v2 = (cbMultiByte <= 1) ? (off_5E69C8[0][*v1] & 4)
    //                                     : CharacterEncodingConvertViaLookupTableFallback(*v1, 4);
    //       } while (v2);
    //     }
    //     char result = *v1;
    //     *v1 = byte_5E6BD8;
    //     char *v4 = v1 + 1;
    //     do { char v5 = *v4; *v4 = result; result = v5; } while (*v4++);
    //     return result;
    //   }
    // UNRESOLVED: The digit-class contract of sub_58B465 (return value 101) is inferred from the loop condition only.
    // UNRESOLVED: The meaning of bit 4 in the off_5E69C8 char-type table entry is inferred to be a digit-class flag.
    // UNRESOLVED: The exact locale value of the separator byte_5E6BD8 is external.
    // UNRESOLVED: No static callers are present in this packet.
}
