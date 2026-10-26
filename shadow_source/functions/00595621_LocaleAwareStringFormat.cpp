// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00595621
// Canonical corpus name: LocaleAwareStringFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LocaleAwareStringFormat_00595621.c

void UnknownObject::LocaleAwareStringFormat()
{
    // Converts an 80-bit extended float argument into a fixed-width decimal string and packs the result into a caller-provided _DWORD output record a3. Unpacks the float with Float80ToFloat64Unpack into a two-dword pair, formats it through sub_5976E8 with a trailing-word parameter, length limit 17 and a null precision parameter into the character buffer v9, then writes the format length to a3[2], a first character to a3[0], the buffer value to a3[1], and the forwarded a4 value to a3[3]. Calls sub_58FCA0 before writing a3[3] and returns a3.
    // CALL: Call Float80ToFloat64Unpack(v11, &a1) to unpack the 80-bit extended float argument a1 into the two-dword pair v11. [callee:0x0059567D, source:raw]
    // ASSIGNMENT: Copy the trailing stack word v12 into v8 (a value carried through to the formatter call). [source:raw]
    // CALL: Call sub_5976E8(v11[0], v11[1], v8, 17, 0, &v9): formats the unpacked float value using the trailing word v8, a width/limit of 17 and a null precision argument, writing the resulting character data into the buffer v9 and returning a length in v4. [callee:0x005976E8, source:raw]
    // ASSIGNMENT: Store the formatter return value as the output record length: a3[2] = v4. [source:raw]
    // ASSIGNMENT: Store a first character from the stack into the output record: a3[0] = v10. [source:raw]
    // ASSIGNMENT: Store the formatted character buffer value into the output record: a3[1] = v9. [source:raw]
    // CALL: Call sub_58FCA0() with no arguments before the final output field is written. [callee:0x0058FCA0, source:raw]
    // ASSIGNMENT: Forward the caller argument into the output record: a3[3] = a4. [source:raw]
    // RETURN: Return the output record pointer a3. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_595621(char a1, int a2, _DWORD *a3, int a4) {
    //     Float80ToFloat64Unpack(v11, &a1);
    //     v8 = v12;
    //     v4 = sub_5976E8(v11[0], v11[1], v8, 17, 0, &v9);
    //     a3[2] = v4;
    //     a3[0] = v10;
    //     a3[1] = v9;
    //     sub_58FCA0();
    //     a3[3] = a4;
    //     return a3;
    //   }
    // UNRESOLVED: The exact role of the forwarded argument a2 and the trailing-word v12/v8 passed to the formatter is not established by this packet.
    // UNRESOLVED: The semantics of the no-argument call sub_58FCA0() (context/reset/cleanup) are unknown.
    // UNRESOLVED: The meaning of the width/limit constant 17 and the character buffer v9 layout are inferred from the formatter call signature, not independently evidenced.
    // UNRESOLVED: The legacy ABI label 'Locale_Aware_String_Format' suggests locale handling, but no locale-aware operation is visible in the raw source; treated as a naming lead only.
}
