// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049DB00
// Canonical corpus name: sub_49DB00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49DB00_0049db00.c

void UnknownObject::FormatTemperatureValue()
{
    // Formats a temperature value into the buffer a2 as an integer with a unit suffix, choosing between Celsius and Fahrenheit formatting based on the global CostDisplayMode flag. When dword_7D0450 equals 1 the Celsius value a1 is converted to Fahrenheit using the linear transform before formatting; otherwise the raw value is formatted.
    // GUARD: Branch on global dword_7D0450: when it is not equal to 1 the Celsius path is taken. [global:0x007D0450]
    // CALCULATION: Convert Celsius to Fahrenheit: v3 = (a1 - -40.0) * 1.8 - 40.0 (linear scale about the -40 degree coincidence point). [global:0x0059EAB0, global:0x0059EAB8, global:0x0059EAC0]
    // CALL: Celsius path: StringFormatWithBufferOverflowCheck(a2, "%4d %s", (int)a1, &byte_5C3734), writing the integer value followed by the Celsius unit suffix buffer. [callee:0x0058815F, global:0x005C3734, global:0x005CCED0]
    // CALL: Fahrenheit path: StringFormatWithBufferOverflowCheck(a2, "%4d %s", (int)v3, &byte_5C3738), writing the converted integer value followed by the Fahrenheit unit suffix buffer. [callee:0x0058815F, global:0x005C3738, global:0x005CCED0]
    // RETURN: Return the result of the selected StringFormatWithBufferOverflowCheck call. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatTemperatureValue(int dst, float celsius) {
    //     if (dword_7D0450 != 1)
    //       return StringFormatWithBufferOverflowCheck(dst, "%4d %s", (int)celsius, &byte_5C3734);
    //     float f = (celsius - -40.0) * 1.8 - 40.0;
    //     return StringFormatWithBufferOverflowCheck(dst, "%4d %s", (int)f, &byte_5C3738);
    //   }
    // UNRESOLVED: Semantic meaning of the three transform globals dbl_59EAB0/dbl_59EAB8/dbl_59EAC0: only their combined linear-transform role is evidenced.
    // UNRESOLVED: The global a4dS string's exact contents are not evidenced here beyond being the format string "%4d %s".
    // UNRESOLVED: Which unit suffix strings byte_5C3734 and byte_5C3738 hold is only inferred from the branch; not evidenced byte-wise.
}
