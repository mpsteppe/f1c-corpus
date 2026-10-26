// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058D04D
// Canonical corpus name: sub_58D04D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_58D04D_0058d04d.c

void UnknownObject::FormatOutputToStream()
{
    // Core printf-family formatter. Parses the format string a2 against a state machine indexed by byte_5B8D88, honouring flags, field width, precision, length modifiers and the d/i/u/o/x/X/c/s/S/C/p/n/e/E/f/F/g/G/Z conversions, reading arguments through the va-list pointer a3, and emitting formatted output to the stream a1 while tracking a character count v56. Serves as the shared engine behind six callers including SafeStringFormat, StringFormatWithNestedIO and FileWriteWrapperWithLock.
    // ASSIGNMENT: Initialize formatter state: zero the character count v56 and flag byte v60, read the first format character v4 = *a2 and set the advance pointer v61 = a2 + 1 [source:raw]
    // GUARD: If the first format character is NUL (empty format string), skip parsing entirely and return 0 [source:raw]
    // LOOP: Main format parse loop: classify each character with a lookup table (aIsprocessorfea, masked to 4 bits) and use it to index byte_5B8D88 for the state-machine transition nibble; dispatch on the resulting state [global:0x005B8D88]
    // GUARD: Abort when the character count v56 goes negative (buffer-overrun protection) and return v56 [source:raw]
    // STATE_TRANSITION: Literal/ordinary characters outside a conversion are tested against off_5E69C8 and emitted with StreamByteOutputWithBufferManagement [global:0x005E69C8, callee:0x0058D78E]
    // STATE_TRANSITION: Flags state: parse ' ', '#', '+', '-', '0' into flag byte v60 [source:raw]
    // STATE_TRANSITION: Width/precision state: parse either literal digits or '*' read from the va-list via IntPeekFromPointer; negative precision is clamped to -1 [callee:0x0058D82C]
    // STATE_TRANSITION: Length-modifier state: 'h', 'l', 'w' and 'I64' set size flags on v60 [source:raw]
    // STATE_TRANSITION: Integer conversions d/i/u/o/x/X/p: fetch the numeric argument (IntPeekFromPointer, or PointerAdvanceReadBack for the I64/64-bit path), apply sign handling, then generate digits via repeated sub_594FF0 (divide) and sub_596100 (modulo) into a local buffer, optionally prefixing with a base marker for hex/pointer output [callee:0x0058D82C, callee:0x0058D839, callee:0x00594FF0, callee:0x00596100]
    // STATE_TRANSITION: Float conversions e/E/f/F/g/G: read an 8-byte double argument, format it with off_5E6730, trim trailing zeros with off_5E6734 and apply precision with off_5E673C, then measure the produced string with Strlen [global:0x005E6730, global:0x005E6734, global:0x005E673C, callee:0x0058E1B0]
    // STATE_TRANSITION: String conversions s/S/Z: read a string pointer argument via IntPeekFromPointer, measure it with Strlen (or a wide char-pair scan), substituting the default placeholders off_5E6BE0 / off_5E6BE4 when the pointer is null [callee:0x0058D82C, callee:0x0058E1B0, global:0x005E6BE0, global:0x005E6BE4]
    // STATE_TRANSITION: Character conversions c/C and single wide characters: read a 1-byte or 2-byte argument (IntPeekFromPointer / Read2ByteValueFromStreamPointer) and convert it into the output buffer with sub_596030 [callee:0x0058D82C, callee:0x0058D849, callee:0x00596030]
    // STATE_TRANSITION: Conversion n: store the running character count v56 through an argument pointer [source:raw]
    // CALCULATION: Field output and padding: compute the pad count as width minus sign/prefix minus field length, emit leading fill via LoopWithSentinelTermination, the sign/prefix, the zero fill, then the field body via CharByCharStringProcessingWithTerminatorCheck, and trailing fill when left-justified [callee:0x0058D7C3, callee:0x0058D7F4]
    // LOOP: Wide-string output path (v52 set): each wide character is converted with sub_596030 into a local buffer and written with CharByCharStringProcessingWithTerminatorCheck [callee:0x00596030, callee:0x0058D7F4]
    // RETURN: Return the total character count v56 written to the stream [function:0x0058D04D]

    // Conservative worker pseudocode:
    //   int FormatOutputToStream(Stream* out, const char* fmt, va_list ap) {
    //       int count = 0;
    //       if (!*fmt) return 0;
    //       while (*fmt) {
    //           state = byte_5B8D88[classify(*fmt) * 8 + prev_state] >> 4;
    //           /* states: reset, flags, width, precision, length, conversion * /
    //           switch (conversion) { /* d/i/u/o/x/X/c/s/S/C/p/n/e/E/f/F/g/G/Z * / }
    //           emit_field(out, field, width, flags, &count);
    //           fmt = advance;
    //       }
    //       return count;
    //   }
    // UNRESOLVED: AmsgExitRuntimeError (callee 0x00595733) is declared in the packet but absent from the decompiled body; likely a runtime-error abort on a path not visible in Hex-Rays output.
    // UNRESOLVED: jpt_58D0BB (global 0x0058D76E) is the compiler-generated switch jump table for the state dispatch; it has no direct source reference.
    // UNRESOLVED: The character-classification table referenced in the body (aIsprocessorfea) has no packet evidence entry and its backing address is unverified.
    // UNRESOLVED: sub_594FF0 and sub_596100 are called as 64-bit divide/modulo helpers but their exact semantics are only inferred from usage.
}
