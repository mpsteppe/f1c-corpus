// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00596245
// Canonical corpus name: sub_596245
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_596245_00596245.c

void UnknownObject::CRTStringToFloatParser()
{
    // State-machine string-to-float parser (CRT strtod-style). Skips leading whitespace, then parses an optional sign, integer and fraction digit runs, and an optional decimal exponent, dispatching states through the jump table jpt_5962A8. Digit classification uses the char-type table off_5E69C8 (bit 4) or CharacterEncodingConvertViaLookupTableFallback when cbMultiByte exceeds 1; byte_5E6BD8 is the decimal separator. Collected digits fill a 25-entry buffer (cap 0x19) with overflow count v47; leading zeros and exponent combine into a base-10 exponent v23 (bounds +/-5200) adjusted by format scales a5/a6. sub_597621 packs the digit buffer into a 96-bit value across v34/v35/v36, and BitPackedDataDecodeViaLookupTable applies the exponent. The 96-bit result is written to the output (low word at a1+0, mid dword at a1+2, high dword at a1+6, sign-or-exponent word at a1+10) and a classification code v44 is returned: 4 for no digits parsed, 2 on overflow, 1 on underflow, else 0. The end-of-parse pointer is stored to *a2.
    // LOOP: Skip leading whitespace (space 32, tab 9, newline 10, carriage return 13) until a non-whitespace byte is reached [source:raw]
    // LOOP: State-machine parse loop over the input bytes driven by state v8; the dispatch reads the jump table jpt_5962A8 [global:0x005966E6, source:raw]
    // ASSIGNMENT: Sign handling: '+' clears the sign flag v39, '-' sets v39 to 0x8000 (negative bit) [source:raw]
    // GUARD: Digit classification: char-type table off_5E69C8 bit 4 decides digit vs non-digit, or CharacterEncodingConvertViaLookupTableFallback when cbMultiByte exceeds 1 [global:0x005E69C8, global:0x005E6BD4, callee:0x0058C674, source:raw]
    // LOOP: Collect integer digits into the 25-entry (0x19) buffer v32 through v46, incrementing the overflow count v47 once the cap is exceeded [source:raw]
    // GUARD: Decimal separator: byte_5E6BD8 switches the parser from integer collection (state 3) to fraction collection (state 4) [global:0x005E6BD8, source:raw]
    // LOOP: Collect fraction digits, stripping leading zeros by decrementing v47; the digit count v48 caps at 24 with a rounding bump tracked in v33 [source:raw]
    // ASSIGNMENT: Exponent handling: the exponent sign sets v43 to 1 or -1, and v42 accumulates the decimal exponent, capped at 5201 [source:raw]
    // CALCULATION: Combine digit count v47, sign-adjusted exponent v42, and format scales a5/a6 into the base-10 exponent v23, bounds-checked to +/-5200 [source:raw]
    // CALL: sub_597621(v32, v48, v34) converts the collected digit buffer into a 96-bit packed value spanning v34/v35/v36 [callee:0x00597621, source:raw]
    // CALL: BitPackedDataDecodeViaLookupTable(v34, v23, a4) applies the base-10 exponent to the 96-bit value [callee:0x00597CC0, source:raw]
    // ASSIGNMENT: Write the 96-bit result into the output: low word at a1+0, mid dword at a1+2, high dword at a1+6, and the sign-or-exponent word at a1+10 [field:this:0x00000000, field:this:0x00000002, field:this:0x00000006, field:this:0x0000000A, source:raw]
    // STATE_TRANSITION: Result classification v44: 4 when no digits were parsed (v45 clear), 2 on overflow (v38), 1 on underflow (v37), else 0; *a2 stores the end-of-parse pointer [function:0x00596245, source:raw]
    // RETURN: Returns the classification code v44 [source:raw]
    // CALL: Called by EncodingLocaleDetectionFromParseResult, BufferFormatHelper and StringParseWithFormat [caller:0x0058E12E, caller:0x00595550, caller:0x0059557D, source:raw]

    // Conservative worker pseudocode:
    //   skip leading whitespace;
    //   v8 = 0; v39 = 0; v43 = 1; v44 = 0; v40 = v41 = v42 = v47 = v48 = 0;
    //   while ((v10 = *p++)) {
    //     switch (v8) {   /* dispatch via jpt_5962A8 * /
    //       /* sign / integer / fraction / exponent states * /
    //     }
    //   }
    //   v20 = (v45 == 0); *a2 = p;
    //   if (v20) v44 = 4;
    //   else {
    //     cap digit count v48 at 24;
    //     sub_597621(v32, v48, v34);
    //     v22 = (v43 < 0) ? -v42 : v42;
    //     v23 = v47 + v22 + (v41 ? 0 : a5) - (v40 ? 0 : a6);
    //     if (v23 > 5200) v38 = 1;
    //     else if (v23 >= -5200) BitPackedDataDecodeViaLookupTable(v34, v23, a4);
    //     else v37 = 1;
    //     if (v38) v44 = 2; else if (v37) v44 = 1;
    //   }
    //   *(WORD*)a1 = v27; *(DWORD*)(a1+2) = v24; *(DWORD*)(a1+6) = v25; *(WORD*)(a1+10) = v39 | v26;
    //   return v44;
    // UNRESOLVED: The jpt_5962A8 jump-table dispatch is rendered as a switch by Hex-Rays; the state-id to meaning mapping (states 0-11) is only partially recoverable and several transitions are inferred
    // UNRESOLVED: The exact 96-bit layout produced by sub_597621 and the transform applied inside BitPackedDataDecodeViaLookupTable are not documented in this packet
    // UNRESOLVED: Format scale arguments a5/a6 (added/subtracted into the exponent when the integer/fraction flags are clear) have caller-dependent meaning
    // UNRESOLVED: The classification codes 0-4 semantics are DERIVED from the existing analysis, not independently proven
    // UNRESOLVED: The relationship between the output fields at a1+0/2/6/10 and the canonical 96-bit long-double representation is DERIVED
}
