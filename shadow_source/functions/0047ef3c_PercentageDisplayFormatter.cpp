// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047EF3C
// Canonical corpus name: PercentageDisplayFormatter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PercentageDisplayFormatter_0047ef3c.c

void UnknownObject::PercentageDisplayFormatter()
{
    // Formats the global UI percentage slider value flt_7D084C (0.0-1.0) as an integer percentage string using StringFormatWithBufferOverflowCheck with the "%0.0f%%" format string, multiplying the value by 100.0, then dispatches the formatted string through ConditionalCallWrapper and returns 0.
    // CALCULATION: Compute flt_7D084C * 100.0 to convert the 0.0-1.0 slider fraction held in the global into a percentage value. [global:0x007D084C, source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(v1, "%0.0f%%", flt_7D084C * 100.0) to format the percentage into the local buffer v1 using the percent format string at 0x005C74E0. [callee:0x0058815F, global:0x005C74E0, source:raw]
    // CALL: Dispatch the formatted percentage string through ConditionalCallWrapper((int)v1). [callee:0x0047E940, source:raw]
    // RETURN: Always return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int PercentageDisplayFormatter() {
    //       char v1[24];
    //       StringFormatWithBufferOverflowCheck(v1, "%0.0f%%", flt_7D084C * 100.0);
    //       ConditionalCallWrapper((int)v1);
    //       return 0;
    //   }
    // UNRESOLVED: The global flt_59E6F8 appears in the packet's global list but is not referenced by the raw source of this function; existing analysis notes it is referenced elsewhere in the same compilation unit.
    // UNRESOLVED: The behavior of ConditionalCallWrapper beyond 'dispatch the formatted string' is not established from this packet.
    // UNRESOLVED: Semantic role of flt_7D084C as a UI percentage slider is asserted by existing analysis (DERIVED) but not independently proven here.
}
