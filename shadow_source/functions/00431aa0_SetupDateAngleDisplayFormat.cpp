// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431AA0
// Canonical corpus name: SetupDateAngleDisplayFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupDateAngleDisplayFormat_00431aa0.c

void UnknownObject::SetupDateAngleDisplayFormat()
{
    // Telemetry display formatter that reads three consecutive floats from this + (3*a2 + 1851)*4 as Kelvin temperatures, converts each to Celsius by subtracting 273.16 into a local buffer, then either converts to Fahrenheit ((C - -40.0) * 1.8 - 40.0) or keeps Celsius depending on the unit flag this+4 (1 = Fahrenheit). Formats either the full triplet via "%3d/%3d/%3d %s" or the single value v13[a4] via the format string at off_5C3F70, calling StringFormatWithBufferOverflowCheck for safe formatting, then clears the byte at this + a2 + 7400 and returns the formatted-string result.
    // ASSIGNMENT: Read three consecutive floats starting at this + (3*a2 + 1851)*4, subtracting the Kelvin offset 273.16 into the local Celsius buffer v14[1..3]. [source:raw]
    // LOOP: do-while loop filling v14[1..3] with the Kelvin-to-Celsius differences. [source:raw]
    // GUARD: Guard: when the unit flag this+4 == 1, values are converted from Celsius to Fahrenheit. [field:this:0x00000004, guard:0, source:raw]
    // CALCULATION: Fahrenheit branch: v15 = (celsius - -40.0) * 1.8 - 40.0, truncated to int into v13[0..2]. [source:raw]
    // ASSIGNMENT: Fahrenheit branch selects suffix pointer byte_5C3738. [global:0x005C3738, source:raw]
    // CALCULATION: Celsius branch: truncate each of the three Celsius values from v14[1..3] into v13[0..2]. [source:raw]
    // ASSIGNMENT: Celsius branch selects suffix pointer byte_5C3734. [global:0x005C3734, source:raw]
    // GUARD: Guard: if the format selector a4 == 3, format the full triplet. [source:raw]
    // CALL: Format "%3d/%3d/%3d %s" with v13[0], v13[1], v14[0] and the selected suffix via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005C3F74, source:raw]
    // CALL: Otherwise format the single value v13[a4] with the format string at off_5C3F70 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005C3F70, source:raw]
    // ASSIGNMENT: Clear the flag byte at this + a2 + 7400 after formatting. [source:raw]
    // RETURN: Return the format result. Invoked by MenuCommandDispatcher (004674e0). [caller:0x004674E0, function:0x00431AA0, source:raw]

    // Conservative worker pseudocode:
    //   int FormatTemperatureData(void* this, int a2, char* dst, int a4) {
    //     float* src = (float*)&this[3*a2 + 1851];
    //     float celsius[4];
    //     int n = 0;
    //     do { ++n; celsius[n] = *src++ - 273.16; } while (n < 3);
    //     int values[3]; const char* suffix;
    //     if (this->unitFlag == 1) { /* this+4 * /
    //       suffix = byte_5C3738;
    //       for (int i = 0; i < 3; ++i) values[i] = (int)((celsius[i+1] - -40.0) * 1.8 - 40.0);
    //     } else {
    //       suffix = byte_5C3734;
    //       for (int j = 0; j < 3; ++j) values[j] = (int)celsius[j+1];
    //     }
    //     int result;
    //     if (a4 == 3)
    //       result = StringFormatWithBufferOverflowCheck(dst, "%3d/%3d/%3d %s", values[0], values[1], celsius[0], suffix);
    //     else
    //       result = StringFormatWithBufferOverflowCheck(dst, off_5C3F70, values[a4]);
    //     this->flagsByte[a2] = 0; /* byte at this + a2 + 7400 * /
    //     return result;
    //   }
    // UNRESOLVED: Four read-only double globals dbl_59EAB0/59EAB8/59EAC0/59EAC8 are flagged by packet facts but absent from the raw decompiled source; the conversion literals 273.16/1.8/-40.0 appear folded inline instead, so their mapping is unverifiable from this packet.
    // UNRESOLVED: The temperature array base this + (3*a2 + 1851)*4 and the reset byte this + a2 + 7400 are index-derived offsets not present in the packet field list; the owning object layout is unknown.
    // UNRESOLVED: Meaning of the a4 selector for values other than 3 (single-value format path) is not documented in this function.
}
