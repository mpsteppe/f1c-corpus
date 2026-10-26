// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C7A0
// Canonical corpus name: FloatToShortViaFtol
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToShortViaFtol_0045c7a0.c

void UnknownObject::FloatToShortViaFtol()
{
    // Converts a float to a 16-bit unsigned value: scales the input by a float constant (flt_59E450) plus a rounding offset (flt_59F0BC), converts the result to integer via CRTFtol (ftol), stores it through the output word pointer a2, and returns the raw integer conversion result.
    // CALCULATION: Multiply input float a1 by float constant flt_59E450 (approximately 999.99994). [global:0x0059E450, source:raw]
    // CALCULATION: Add float constant flt_59F0BC (approximately 0.5) to the scaled value as a rounding offset. [global:0x0059F0BC, source:raw]
    // CALL: Call CRTFtol (0x00587BDC) to convert the accumulated float to an integer; result held in the return register. [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Store the integer conversion result into the 16-bit output pointed to by a2 (*a2 = result). [source:raw]
    // RETURN: Return the integer conversion result as the function return value. [source:raw]

    // Conservative worker pseudocode:
    //   int result = CRTFtol(a1 * flt_59E450 + flt_59F0BC);
    //   *a2 = result;
    //   return result;
    // UNRESOLVED: Mapping of the two float globals to the literals is not stated in the packet: flt_59E450 is taken to be the scale ~999.99994 and flt_59F0BC the rounding offset ~0.5, but the packet does not assign them explicitly.
    // UNRESOLVED: Whether *a2 is unsigned or signed 16-bit is not specified by the packet.
}
