// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00564C40
// Canonical corpus name: Base64IndexToCharEncoding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Base64IndexToCharEncoding_00564c40.c

void UnknownObject::Base64IndexToCharEncoding()
{
    // Standard Base64 alphabet encoder: maps a 6-bit index in [0,63] to its ASCII character. Index ranges 0-25 map to 'A'-'Z' (index+65), 26-51 to 'a'-'z' (index+71), 52-61 to '0'-'9' (index-4), 62 to '+', and 63 to '/'. Any index >= 64 returns 0 (no valid mapping). Called by Base64Encode (00562090) and by PadOutputWithSpacesUpToLengthLimit (00564B80).
    // GUARD: Guard on a1 < 26 (0x1A); first range of the alphabet. [source:raw]
    // RETURN: Return a1 + 65, mapping indices 0-25 to ASCII 'A'-'Z'. [source:raw]
    // GUARD: Guard on a1 < 52 (0x34); second range of the alphabet. [source:raw]
    // RETURN: Return a1 + 71, mapping indices 26-51 to ASCII 'a'-'z'. [source:raw]
    // GUARD: Guard on a1 < 62 (0x3E); digit range. [source:raw]
    // RETURN: Return a1 - 4, mapping indices 52-61 to ASCII '0'-'9'. [source:raw]
    // GUARD: Guard on a1 == 62, the '+' index. [source:raw]
    // RETURN: Return 43, the ASCII '+' for index 62. [source:raw]
    // RETURN: Final fallback: return 47 (0x2F), the ASCII '/', when a1 == 63, otherwise return 0 for any out-of-range index. [source:raw]
    // CALL: Invoked by Base64Encode (00562090) to encode each 6-bit group, and by PadOutputWithSpacesUpToLengthLimit (00564B80). [caller:0x00562090, caller:0x00564B80, source:raw]

    // Conservative worker pseudocode:
    //   char sub_564C40(unsigned char idx) {
    //     if (idx < 26) return idx + 65;   /* A-Z * /
    //     if (idx < 52) return idx + 71;   /* a-z * /
    //     if (idx < 62) return idx - 4;    /* 0-9 * /
    //     if (idx == 62) return 43;        /* '+' * /
    //     return idx != 63 ? 0 : 47;       /* '/' or invalid * /
    //   }
    // UNRESOLVED: The return 0 path for a1 >= 64 is dead for well-formed Base64 input (only 64 index values exist); its purpose in the caller context is unverified.
    // UNRESOLVED: Why PadOutputWithSpacesUpToLengthLimit (00564B80) invokes the alphabet encoder is unclear from this packet; the caller's padding semantics are not reconstructed here.
}
