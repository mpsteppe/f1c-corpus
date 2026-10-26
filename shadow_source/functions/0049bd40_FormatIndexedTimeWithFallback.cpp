// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BD40
// Canonical corpus name: sub_49BD40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BD40_0049bd40.c

void UnknownObject::FormatIndexedTimeWithFallback()
{
    // Writes the default string asc_5CCE18 into the output buffer, then selects a time source: when byte_7CFFF0 bit 0 is set, an index from sub_4D1B50(0) indexes a float table; otherwise the time is read from *(float*)(dword_7C54E0 + 16552). If the selected time is positive it is formatted as " MM:SS.FFF" into the previously written buffer, otherwise the default string remains.
    // CALL: Copy the default string asc_5CCE18 into the output buffer a1 with strcpy; the destination pointer is retained for later formatting. [global:0x005CCE18]
    // GUARD: Guard on byte_7CFFF0 bit 0 being set: if set, select the time via the index path, otherwise read it from the object behind dword_7C54E0. [global:0x007CFFF0]
    // CALL: Call sub_4D1B50 with argument 0 to obtain an index value. [callee:0x004D1B50]
    // GUARD: If the returned index is 255, return 0 immediately without formatting. [callee:0x004D1B50]
    // ASSIGNMENT: Read the time value from a float-table entry located at 4656 * index relative to the table base shown in the raw source. [source:raw]
    // ASSIGNMENT: Else branch: read the time value from *(float*)(dword_7C54E0 + 16552). [global:0x007C54E0]
    // ASSIGNMENT: Store the selected time value into a float temporary used for the formatting guard. [source:raw]
    // GUARD: Guard on the selected time being greater than 0.0; if not positive the default string already in the buffer is kept. [source:raw]
    // CALL: Call SpatialGridCell with the time value to derive minutes/seconds components into a local. [callee:0x0049B630]
    // CALL: Format " %.2d:%06.3f" into the retained destination via StringFormatWithBufferOverflowCheck using the derived components. [callee:0x0058815F]
    // RETURN: Return 0 at function end. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49BD40(char* out, int unused) {
    //     char* dest = strcpy(out, asc_5CCE18);
    //     float t;
    //     if ((byte_7CFFF0 & 1) != 0) {
    //       int idx = sub_4D1B50(0);
    //       if (idx == 255) return 0;
    //       t = float_table[4656 * idx];
    //     } else {
    //       t = *(float*)(dword_7C54E0 + 16552);
    //     }
    //     if (t > 0.0f) {
    //       int mins; SpatialGridCell(t, &mins, &t);
    //       StringFormatWithBufferOverflowCheck(dest, " %.2d:%06.3f", mins, t);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: flt_59E440, asc_5CCE24 (a2d063f_1) and dword_8ACEE0 are listed as referenced globals but do not appear in the raw decompiled body; their exact role is unresolved.
    // UNRESOLVED: The indexed float table (entry stride 4656 * index) has no named global in the packet evidence list; the table base is referenced only in the raw source text.
    // UNRESOLVED: Semantic meaning of the object field at dword_7C54E0 + 16552 is unresolved.
    // UNRESOLVED: Purpose of argument a2 is unknown.
}
