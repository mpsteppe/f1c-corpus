// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058F6C7
// Canonical corpus name: InPlaceDigitCharConversionStripSemicolons
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InPlaceDigitCharConversionStripSemicolons_0058f6c7.c

void UnknownObject::InPlaceDigitCharConversionStripSemicolons()
{
    // Walks a null-terminated char string in place. ASCII digit characters '0'-'9' (48..57) are overwritten with their nibble value (byte minus 48); semicolon characters (59) are removed by left-shifting the remaining characters over them; all other characters pass through unchanged. Used to fold a locale digit-grouping string such as "3;2;1" into a packed nibble array.
    // ASSIGNMENT: Initialize the walk pointer v1 to the start of the input string a1. [source:raw]
    // ASSIGNMENT: Seed the loop state with the first character of the string, result = *a1. [source:raw]
    // LOOP: Outer loop iterates while the current character *v1 is non-null; each iteration starts from the previously read character in result. [source:raw]
    // GUARD: Digit test: when result is in [48, 57] the character is an ASCII digit. [source:raw]
    // ASSIGNMENT: Overwrite the current byte with its nibble value: *v1 = result - 48. [source:raw, field:this:0x00000000]
    // GUARD: Non-digit branch: when result equals 59 (semicolon), enter the deletion path. [source:raw]
    // LOOP: Inner shift loop: starting at the semicolon position, copy each byte from the following position and advance, until a null terminator is copied; this removes the semicolon in place. [source:raw, field:this:0x00000000, field:this:0x00000001]
    // CALCULATION: Advance the walk pointer by one byte (++v1) after a digit conversion or a passthrough character. [source:raw]
    // RETURN: Return the last examined character (the terminating null at normal loop exit). [source:raw]

    // Conservative worker pseudocode:
    //   char sub_58F6C7(char *s) {
    //     char c = *s;
    //     char *p = s;
    //     while (*p) {
    //       if (c >= 48 && c <= 57) {
    //         *p = (char)(c - 48);
    //       } else if (c == 59) {
    //         char *q = p;
    //         do { *q = q[1]; ++q; } while (*q);
    //         continue;
    //       }
    //       ++p;
    //     }
    //     return c;
    //   }
    // UNRESOLVED: The meaning of the returned character is not consumed by this function; callers decide how it is used.
    // UNRESOLVED: The exact purpose of the digit-to-nibble conversion depends on the caller-provided grouping string and is not visible here.
}
