// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042F260
// Canonical corpus name: SetupValueFormatWithOffset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetupValueFormatWithOffset_0042f260.c

void UnknownObject::SetupValueFormatWithOffset()
{
    // Formats a vehicle setup value (source struct a2) into the buffer at a2+30 with an optional indexed offset term. Computes the base value v3 = (double)*(a2+20) * *(double*)(a2+8) + *(double*)a2. When the offset argument a3 is non-zero, adds ((double)*(this+3204) * *(double*)(this+3192) + *(double*)(this+3184)) * *(double*)(this+6556) * a3 to v3 (fields 0xC84, 0xC78, 0xC70, 0x199C). Scales v7 = v3 * 100.0 and passes the unit suffix string at this+24. When the format flag this+4 is non-zero, calls StringFormatWithBufferOverflowCheck(a2+30, "%.3f %s", v7 * 0.3937007874015748, this+24) (inches conversion); otherwise calls it with "%.1f %s" and v7 unchanged (metric). Returns the format helper's result.
    // CALCULATION: Compute the base value v3 = (double)*(a2+20) * *(double*)(a2+8) + *(double*)a2. [function:0x0042F260, source:raw]
    // GUARD: Guard on the offset argument a3: when a3 is non-zero (comparison against the zero sentinel dbl_59E430), add the indexed offset term to v3. [global:0x0059E430, function:0x0042F260, source:raw]
    // CALCULATION: When a3 is non-zero, add ((double)*(this+3204) * *(double*)(this+3192) + *(double*)(this+3184)) * *(double*)(this+6556) * a3 to v3 (fields 0xC84, 0xC78, 0xC70, 0x199C). [field:this:0x00000C84, field:this:0x00000C78, field:this:0x00000C70, field:this:0x0000199C, function:0x0042F260, source:raw]
    // CALCULATION: Scale the value v7 = v3 * 100.0; set the destination buffer v4 = a2+30 and the unit suffix v6 = (const char*)(this+24). [function:0x0042F260, source:raw]
    // GUARD: Guard on the format flag at this+4: when non-zero select the inches format, otherwise the metric format. [field:this:0x00000004, function:0x0042F260, source:raw]
    // CALL: Inches branch: StringFormatWithBufferOverflowCheck(a2+30, "%.3f %s" (a3fS), v7 * 0.3937007874015748, this+24) and return its result. [callee:0x0058815F, global:0x005C3780, function:0x0042F260, source:raw]
    // CALL: Metric branch: StringFormatWithBufferOverflowCheck(a2+30, "%.1f %s" (a1fS), v7, this+24) and return its result. [callee:0x0058815F, global:0x005C36F4, function:0x0042F260, source:raw]
    // RETURN: Return the format helper result from either branch. [function:0x0042F260, source:raw]

    // Conservative worker pseudocode:
    //   int SetupValueFormatWithOffset(int this, int a2, double a3) {
    //       double v3 = (double)*(int*)(a2 + 20) * *(double*)(a2 + 8) + *(double*)a2;
    //       if (a3 != 0.0)
    //           v3 += ((double)*(int*)(this + 3204) * *(double*)(this + 3192) + *(double*)(this + 3184))
    //                 * *(double*)(this + 6556) * a3;
    //       double v7 = v3 * 100.0;
    //       const char* v6 = (const char*)(this + 24);
    //       if (*(int*)(this + 4))
    //           return StringFormatWithBufferOverflowCheck(a2 + 30, "%.3f %s", v7 * 0.3937007874015748, v6);
    //       else
    //           return StringFormatWithBufferOverflowCheck(a2 + 30, "%.1f %s", v7, v6);
    //   }
    // UNRESOLVED: The owning object type is unidentified; the format flag at this+4 and the offset-term field group (0xC70/0xC78/0xC84/0x199C) belong to an unknown setup-formatting class.
    // UNRESOLVED: The purpose of the a2+30 buffer and the exact unit string at this+24 are only implied by the format specifiers.
}
