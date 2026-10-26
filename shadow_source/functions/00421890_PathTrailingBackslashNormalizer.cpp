// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421890
// Canonical corpus name: PathTrailingBackslashNormalizer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PathTrailingBackslashNormalizer_00421890.c

void UnknownObject::PathTrailingBackslashNormalizer()
{
    // Path-string helper: for a non-null, non-empty input a1 it reads the last character; when that character is not a backslash (92) it writes the two-byte value word_5C2AAC at a1[strlen(a1)], appending a trailing separator plus NUL terminator, and result becomes the low byte of that value (92). Returns the final character (92 when a trailing separator was already present or was appended, 0 for an empty string). On a null input the decompiled body is skipped entirely and result is left uninitialized.
    // GUARD: Null guard on a1: if a1 is null the whole body is skipped and the decompiled result stays uninitialized. [source:raw]
    // ASSIGNMENT: Initialize result to 0 for a non-null a1. [source:raw]
    // GUARD: Guard on a non-empty string: proceed only when strlen(a1) is non-zero. [source:raw]
    // CALCULATION: Compute the index of the final character as strlen(a1) - 1. [source:raw]
    // CALCULATION: Read the last character a1[strlen(a1) - 1] into result. [source:raw]
    // GUARD: If the last character is not 92 (backslash), append a trailing separator. [source:raw]
    // ASSIGNMENT: Write the two-byte value word_5C2AAC at a1[strlen(a1)] (trailing separator plus NUL terminator); result becomes the low byte (92). [source:raw, global:0x005C2AAC]
    // RETURN: Return result: 92 when a trailing separator was present or appended, 0 for an empty string. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_421890(const char *a1) {
    //     char result;
    //     if (a1) {
    //       result = 0;
    //       if (strlen(a1)) {
    //         result = a1[strlen(a1) - 1];
    //         if (result != 92) {
    //           result = word_5C2AAC;
    //           *(_WORD *)&a1[strlen(a1)] = word_5C2AAC;
    //         }
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: word_5C2AAC is expected to be a backslash (92) plus NUL terminator as a two-byte unit, but its actual value is not present in the packet.
    // UNRESOLVED: strlen is inlined by the compiler; no callee evidence is recorded in the packet.
    // UNRESOLVED: The buffer is caller-owned (callers 0x004218D0..0x00421AF0 are a chain of path-registration helpers); spare capacity is assumed, not verified.
    // UNRESOLVED: Null-input return value is a decompiler artifact (uninitialized char); the packed callers never rely on it.
}
