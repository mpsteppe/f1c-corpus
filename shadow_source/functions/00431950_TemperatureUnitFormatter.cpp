// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00431950
// Canonical corpus name: SetupIntegerFormatDS
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupIntegerFormatDS_00431950.c

void UnknownObject::TemperatureUnitFormatter()
{
    // Formats a temperature for display. Converts the input Kelvin value a2 to Celsius (v5 = a2 - 273.16); when the unit-mode flag this[1] equals 1 the value is additionally converted to Fahrenheit ((v5 - -40.0) * 1.8 - 40.0) and the Fahrenheit unit-string pointer (byte_5C3738) is selected, otherwise the Celsius unit-string pointer (byte_5C3734) is used. The integer temperature and unit string are then formatted with the "%d %s" template via StringFormatWithBufferOverflowCheck into the destination buffer a3. Called by MenuCommandDispatcher (004674e0).
    // CALCULATION: Converts Kelvin to Celsius: v5 = a2 - 273.16 [source:raw]
    // GUARD: Branches on the unit-mode flag this[1]: equality with 1 selects the Fahrenheit path, any other value selects the Celsius path [guard:0, field:this:0x00000004, source:raw]
    // CALCULATION: Fahrenheit path: v5 = (v5 - -40.0) * 1.8 - 40.0 [source:raw]
    // ASSIGNMENT: Selects the unit string pointer: byte_5C3738 for Fahrenheit, byte_5C3734 for Celsius [global:0x005C3738, global:0x005C3734, source:raw]
    // CALL: Calls StringFormatWithBufferOverflowCheck with the destination buffer a3, the "%d %s" template, the integer temperature and the selected unit string [callee:0x0058815F, source:raw]
    // RETURN: Returns the result of the string formatting call [source:raw]
    // CALL: Invoked by MenuCommandDispatcher (004674e0), the only known caller in this packet [caller:0x004674E0, source:raw]

    // Conservative worker pseudocode:
    //   v5 = a2 - 273.16;
    //   if (this[1] == 1) {
    //     v3 = &byte_5C3738;
    //     v5 = (v5 - -40.0) * 1.8 - 40.0;
    //   } else {
    //     v3 = &byte_5C3734;
    //   }
    //   return StringFormatWithBufferOverflowCheck(a3, "%d %s", (int)v5, v3);
    // UNRESOLVED: The four read-only double globals at 0x59EAB0/0x59EAB8/0x59EAC0/0x59EAC8 are flagged by packet facts but never appear in the raw decompiled source (fill suggests linear-transform coefficients and a 273.15 offset, all unverifiable from this packet)
    // UNRESOLVED: The string global aDS at 0x5C3778 is flagged by packet facts but never appears in the raw decompiled source
    // UNRESOLVED: The exact unit-string contents of byte_5C3734 and byte_5C3738 are not visible in this packet
    // UNRESOLVED: The unit-mode flag semantics are only that equality with 1 selects Fahrenheit; the owning object type is unknown
}
