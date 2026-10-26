// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058E4D2
// Canonical corpus name: sub_58E4D2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58E4D2_0058e4d2.c

void UnknownObject::FormattedInputScanFromIO()
{
    // vfscanf-style formatter that parses input characters from a buffered I/O context (a1) against a format string (a2), writing converted values through a variable-argument pointer (a3). Supports integer conversions (%d/%i/%u/%o/%x/%p), float conversions (%f/%e/%g), string (%s) and character-set (%{...}) scans, assignment suppression ('*'), width limits, length modifiers (h/l/w/I64), and %n. Returns the count of successful conversions, or -1 on EOF with no conversions.
    // CALL: Character classification: for each pending format/input char, look up cbMultiByte (charset mode) to choose either the direct off_5E69C8 charset table or CharacterEncodingConvertViaLookupTableFallback; bit masks 8 (whitespace) and 4 (digit) drive whitespace-skip and digit accumulation [global:0x005E6BD4, global:0x005E69C8, callee:0x0058C674, source:raw]
    // LOOP: Whitespace skip: while the classified char is whitespace, consume the next format byte and skip matching input via sub_589BF3, tracking each consumed byte through IncrementWrapperAroundCallLoop and ConditionalFreeIfHandleNot1 on the context refcount [callee:0x00589BF3, callee:0x0058EF5F, callee:0x0058EF48, source:raw]
    // GUARD: Non-conversion branch: when the next format char is not '%', read one input byte (BufferedByteReader), compare it to the expected literal, and on mismatch unwind the refcount via ConditionalFreeIfHandleNot1 and break the scan loop [callee:0x0058EF2E, callee:0x0058EF48, source:raw]
    // LOOP: Format-prefix parse: consume width digits into v74, handle '*' (suppress assignment), 'N'/'F' flags, the 'I64' modifier (advances v61, zeroes v63), and h/l/w length modifiers until a non-prefix char appears [source:raw]
    // ASSIGNMENT: Unless assignment is suppressed ('*'), consume one destination pointer from the argument list (a3 advances by 4) into v62 for the current conversion [source:raw]
    // CALL: First input read: for %c and %{ a BufferedByteReader call increments the consumed count, otherwise IncrementWrapperAroundCallLoop acquires the context; the read char is staged in the CharType slot [callee:0x0058EF2E, callee:0x0058EF5F, source:raw]
    // GUARD: Width guard: if a width was specified (v64 set) but is zero (v74 == 0), push the read char back with ConditionalFreeIfHandleNot1 and break the scan [callee:0x0058EF48, source:raw]
    // CALCULATION: Integer conversions (%o/%u/%x/%p/%d/%i): accumulate digits using Allmul (x10 on the 64-bit accumulator), CRTAllshl (x8 octal, x16 hex, x4 when accumulating base-4), and sub_58EEF7 for hex-digit decoding; handle leading 0x/0X and octal prefixes, sign flags, width exhaustion and, on completion, store to v62 as QWORD (v61 set), DWORD (v73 length) or WORD [callee:0x0058C6F0, callee:0x00596840, callee:0x0058EEF7, callee:0x0058EF2E, source:raw]
    // CALL: String and char conversions (%s, %S, %c): in wide mode (v68) convert each input byte to a wide char via sub_596716 before storing, using asc_5E6D50 as the wide-string format source and asc_5E6D58 for the %c path; otherwise store bytes directly through v62, NUL-terminating non-%c results [callee:0x00596716, callee:0x0058EF2E, global:0x005E6D50, global:0x005E6D58, global:0x005E6BD4, source:raw]
    // CALL: Scan-set conversion (%{...}): zero the 32-byte bit table v54 with sub_58BB10, expand character ranges and a leading '^' negation into bits, then read matching input bytes, honoring width and optional per-char wide conversion, until a non-matching byte is pushed back [callee:0x0058BB10, callee:0x0058EF2E, source:raw]
    // CALL: Float conversions (%f/%e/%g): accumulate digit/exponent characters into a stack buffer, honoring the decimal separator byte_5E6BD8 and an e/E exponent with optional sign, then NUL-terminate and convert through the off_5E6738 function pointer, storing the result into the destination [callee:0x0058EF2E, global:0x005E6BD8, global:0x005E6738, source:raw]
    // STATE_TRANSITION: %n conversion: store the current consumed-input count v76 into the destination argument instead of parsing input [source:raw]
    // RETURN: On EOF (staged CharType == -1) return -1 when no conversions and no advances occurred; otherwise return the conversion count v60. Invoked by StrlenFormatCallWrapper (005887ED) [function:0x0058E4D2, caller:0x005887ED, source:raw]

    // Conservative worker pseudocode:
    //   count = 0; consumed = 0;
    //   for (pos = format; *pos; ) {
    //     skip_whitespace(&pos, &consumed);
    //     if (*pos != '%') { read literal, compare, else break; continue; }
    //     parse width/digits, '*', 'N'/'F', 'I64', h/l/w modifiers;
    //     if (!suppressed) dst = *args++;
    //     switch (tolower(*pos)) {
    //       case 'c': case '{': read one input char; break;
    //     }
    //     if (width_specified && width == 0) break;
    //     switch (conv) {
    //       case 'o': case 'u': case 'x': case 'p': case 'd': case 'i':
    //         accumulate digits (base 8/10/16, hex decode, sign, 0x prefix) into acc;
    //         store acc to dst (8/4/2 bytes by length);
    //       case 'f': case 'e': case 'g':
    //         build numeric string (digits, separator byte_5E6BD8, exponent), convert via off_5E6738;
    //       case 's': case 'S': case 'c':
    //         read chars into dst, wide-convert if needed, NUL-terminate unless %c;
    //       case '{': build scan-set bits, read matching chars;
    //       case 'n': store consumed count into dst;
    //     }
    //     if (converted) count++;
    //   }
    //   return (EOF && !count) ? -1 : count;
    // UNRESOLVED: Packet lists a callee AmsgExitRuntimeError (0x00595733) but it appears nowhere in the raw decompiled source; likely a fatal-error/abort path not represented in this decompilation, unverifiable here
    // UNRESOLVED: The wide-string globals asc_5E6D50 and asc_5E6D58 are referenced only as label pointers in the raw source; their actual contents and the full wide/char-mode semantics are outside this packet
}
