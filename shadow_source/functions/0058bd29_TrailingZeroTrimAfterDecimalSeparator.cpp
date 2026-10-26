// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058BD29
// Canonical corpus name: sub_58BD29
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58BD29_0058bd29.c

void UnknownObject::TrailingZeroTrimAfterDecimalSeparator()
{
    // Trims trailing zeros from the fractional part of a formatted floating-point string, then re-joins the exponent tail. Scans the input string forward for the decimal separator character (byte_5E6BD8); if found, scans forward to the exponent marker 'e' (101) or 'E' (69) or end-of-string, removes trailing '0' characters (48) immediately before the marker, drops the decimal separator too if it became the last character before the marker, then shifts the exponent tail left to close the gap. Returns a pointer past the end of the modified string. Free function; the only external data it touches is the read-only decimal-separator global byte_5E6BD8.
    // LOOP: Forward scan from a1 (first character at this+0x0): advance v1 while the current character is non-null, breaking when the character equals the decimal separator byte_5E6BD8; the scan therefore stops at the separator if one exists, otherwise at the null terminator. [field:this:0x00000000, global:0x005E6BD8, source:raw]
    // ASSIGNMENT: Read v3 = *v1 (the character at the scan stop, either the separator or the null terminator) and set result = v1 + 1, pointing one past that position. [source:raw]
    // GUARD: If v3 is non-null, a real decimal separator was found; proceed with fractional trimming and exponent-tail handling. Otherwise the scan hit end-of-string and nothing is modified. [source:raw, function:0x0058BD29]
    // LOOP: Forward scan from result: advance while the current character is non-null and not 'e' (101) and not 'E' (69); v6 ends at the exponent marker or at the null terminator. [source:raw]
    // LOOP: Backward trim of trailing zeros: while the character at result equals '0' (48), decrement result. The first affected position is at this+0x1, the start of the fractional-tail region. [guard:0, field:this:0x00000001, source:raw]
    // GUARD: If the character now at result equals the decimal separator byte_5E6BD8, decrement result so the now-trailing separator is removed along with the trimmed zeros. [global:0x005E6BD8, source:raw]
    // LOOP: Left-shift of the exponent tail: copy characters from v6 (exponent marker onward, including the terminating null) into the positions after result, closing the gap left by the trim. Writes land in the trimmed region starting at this+0x1. [field:this:0x00000001, source:raw]
    // RETURN: Return result, the pointer one past the last written character of the modified string. [function:0x0058BD29, source:raw]

    // Conservative worker pseudocode:
    //   char *TrailingZeroTrimAfterDecimalSeparator(char *a1) {
    //       char *p = a1;
    //       while (*p && *p != byte_5E6BD8) ++p;
    //       char sep = *p;
    //       char *out = p + 1;
    //       if (sep) {
    //           char *exp = out;
    //           while (*exp && *exp != 'e' && *exp != 'E') ++exp;
    //           --out;
    //           while (*out == '0') --out;
    //           if (*out == byte_5E6BD8) --out;
    //           do { ++out; *out = *exp++; } while (*out);
    //       }
    //       return out;
    //   }
    // UNRESOLVED: The concrete character stored in the decimal-separator global byte_5E6BD8 is not provided by the packet; only its sentinel role is known.
    // UNRESOLVED: The owning object is unknown: this is a free helper, most plausibly a float-to-string formatting stage, but its caller is outside this packet.
    // UNRESOLVED: The exponent-tail shift assumes the exponent marker 'e'/'E' or null follows the fraction; handling of an empty fractional part (no digits between separator and marker) is implied by the raw flow but not separately evidenced.
}
