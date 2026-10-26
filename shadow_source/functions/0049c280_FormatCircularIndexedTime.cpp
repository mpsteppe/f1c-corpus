// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C280
// Canonical corpus name: sub_49C280
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C280_0049c280.c

void UnknownObject::FormatCircularIndexedTime()
{
    // Formats one of three recorded time values on the postProcessInput object (dword_7C54E0) into the caller's output buffer. Computes the next circular index (current + 1, wrapping 2 -> 0), reads the float time at that index, and when it is positive decomposes it and formats it as " MM:SS.FFF" into the output buffer after copying the asc_5CCE18 prefix. Always returns 0.
    // ASSIGNMENT: Compute the next circular index: v2 = *(dword_7C54E0 + 16448) + 1; the slot at offset 16448 holds the current index. [global:0x007C54E0, source:raw]
    // GUARD: Wrap the index: if *(dword_7C54E0 + 16448) == 2 then v2 = 0, so v2 cycles over 0..2. [global:0x007C54E0, source:raw]
    // ASSIGNMENT: Initialize the output buffer: v3 = strcpy(a1, asc_5CCE18) copies the constant prefix string so v3 points at the start of the caller's buffer. [global:0x005CCE18, source:raw]
    // ASSIGNMENT: Read the time value for the selected index: v4 = *(float *)(dword_7C54E0 + 4 * v2 + 16552). [global:0x007C54E0, source:raw]
    // GUARD: Only format when the time is positive: if (v4 > 0.0). [source:raw]
    // CALL: Decompose the time into its component fields for formatting: SpatialGridCell(time, &v6, &time). [callee:0x0049B630, source:raw]
    // CALL: Format into the output buffer: StringFormatWithBufferOverflowCheck(v3, " %.2d:%06.3f", v6, time), where the format literal is a2d063f_1 (0x005CCE24). [callee:0x0058815F, global:0x005CCE24, source:raw]
    // RETURN: Always return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatCircularIndexedTime(char* out, int unused) {
    //     int idx = *(int*)(dword_7C54E0 + 16448) + 1;
    //     if (*(int*)(dword_7C54E0 + 16448) == 2) idx = 0;
    //     char* p = strcpy(out, asc_5CCE18);
    //     float t = *(float*)(dword_7C54E0 + 4*idx + 16552);
    //     if (t > 0.0f) {
    //       SpatialGridCell(t, &field, &t);
    //       StringFormatWithBufferOverflowCheck(p, a2d063f_1, field, t);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Global flt_59E440 (0x0059E440) is listed in the packet globals but is not referenced by the raw source; its role here is unknown.
    // UNRESOLVED: The meaning of the three time slots (4*v2 + 16552, v2 in 0..2) on the postProcessInput object is owner-dependent.
    // UNRESOLVED: The caller UtilityFunction_d8b0 (0x0049D8B0) decides the destination buffer and the exact use of the formatted string.
}
