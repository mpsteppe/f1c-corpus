// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005905DD
// Canonical corpus name: HexStringToIntParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HexStringToIntParser_005905dd.c

void UnknownObject::HexStringToIntParser()
{
    // Parses a NUL-terminated hex digit string (digits and a-f/A-F) into an integer by ASCII-normalized base-16 accumulation. Each character is loaded, letter digits are normalized (lowercase 'a'-'f' subtract 39, uppercase 'A'-'F' subtract 7), and the character is folded into the running result via the accumulation formula v3 + 16 * (result + 268435453). Returns the accumulated value. Used by LocaleEnumProc and three sibling parser helpers in the same module.
    // LOOP: Iterate over the characters of the input string a1, loading v3 = *a1 and advancing the pointer each pass, until the NUL terminator is reached [source:raw]
    // ASSIGNMENT: Initialize the accumulated result to 0 before the first character; each iteration loads the next character from the advancing string pointer [source:raw]
    // GUARD: Break the loop when the loaded character is zero (NUL terminator) [source:raw]
    // GUARD: Normalize the character: if it is a lowercase hex letter (97..102, 'a'-'f') subtract 39; else if it is an uppercase hex letter (65..70, 'A'-'F') subtract 7; decimal digits pass through unchanged [source:raw]
    // CALCULATION: Accumulate the normalized character into the running result as a base-16 shift: result = v3 + 16 * (result + 268435453) [source:raw]
    // RETURN: Return the accumulated parse result; invoked by LocaleEnumProc (0x0058FFEC) and the sibling parser helpers sub_590246, sub_59033A and sub_59045F [function:0x005905DD, caller:0x0058FFEC, caller:0x00590246, caller:0x0059033A, caller:0x0059045F, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   while ((v3 = *a1++) != 0) {
    //     if (v3 >= 97 && v3 <= 102) v3 -= 39;   /* 'a'-'f' * /
    //     else if (v3 >= 65 && v3 <= 70) v3 -= 7; /* 'A'-'F' * /
    //     result = v3 + 16 * (result + 268435453);
    //   }
    //   return result;
    // UNRESOLVED: The constant 268435453 in the accumulation is the compiled encoding of a '-48' digit bias; the reconstruction preserves the packet spelling and does not claim the literal's source-level meaning
    // UNRESOLVED: Whether the callers feed prefixed or signed hex strings is not evident from this function alone
}
