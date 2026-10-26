// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BBB0
// Canonical corpus name: sub_49BBB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BBB0_0049bbb0.c

void UnknownObject::FormatElapsedTimeWithFallback()
{
    // Formats elapsed session time as " MM:SS.FFF" into the output buffer, or writes a default string when the preconditions (time threshold, lap/count guard, mode value, flag) are not satisfied. Time is computed as session time minus the elapsed base field on the object behind dword_7C54E0; the format helper is reached through two different guarded paths.
    // ASSIGNMENT: Load the base object pointer from dword_7C54E0 into a local used for all field offsets. [global:0x007C54E0]
    // CALCULATION: Compute elapsed time as dbl_8AFEA0 minus *(float*)(base + 16536) and store the result into a float temporary. [global:0x008AFEA0, global:0x007C54E0]
    // GUARD: Guard on elapsed < flt_5CCC0C: only when the computed time is below the threshold does the first formatting path execute. [global:0x005CCC0C]
    // GUARD: Read *(int*)(base + 16444) and only continue the first path when it is greater than 0. [global:0x007C54E0]
    // CALL: Call ArithmeticComparison_c2a0 with (value at base + 16444) minus 1 and store its result as a float temporary. [callee:0x004BC2A0]
    // GUARD: Guard on the comparison result being greater than 0.0; if not, execution falls through to the fallback guard with base reloaded from dword_7C54E0. [source:raw, global:0x007C54E0]
    // CALL: Call SpatialGridCell with the positive time value to derive minutes/seconds components into a local and update the elapsed temporary. [callee:0x0049B630]
    // CALL: Format " %.2d:%06.3f" into the output buffer a1 via StringFormatWithBufferOverflowCheck using the derived minutes/seconds and the elapsed temporary. [callee:0x0058815F]
    // RETURN: Return 0 from the early success path. [source:raw]
    // GUARD: Fallback guard on the object at base: if *(int*)(base + 16532) is not 2, or the elapsed temporary is below 0.0, or *(int*)(base + 16484) is non-zero, the default string is written instead of formatted time. [global:0x007C54E0]
    // CALL: Copy the default string asc_5CCE18 into the output buffer a1 with strcpy. [global:0x005CCE18]
    // RETURN: Return 0 after the default-string path. [source:raw]
    // CALL: Else branch: call SpatialGridCell with the elapsed temporary to derive minutes/seconds components into a local. [callee:0x0049B630]
    // CALL: Format " %.2d:%06.3f" into the output buffer a1 via StringFormatWithBufferOverflowCheck with the derived components. [callee:0x0058815F]
    // RETURN: Return 0 at function end. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49BBB0(char* out, int unused) {
    //     int base = dword_7C54E0;
    //     float elapsed = (float)(dbl_8AFEA0 - *(float*)(base + 16536));
    //     if (elapsed < flt_5CCC0C) {
    //       int n = *(int*)(base + 16444);
    //       if (n > 0) {
    //         float t = ArithmeticComparison_c2a0(n - 1);
    //         if (t > 0.0f) {
    //           int mins; SpatialGridCell(t, &mins, &elapsed);
    //           StringFormatWithBufferOverflowCheck(out, " %.2d:%06.3f", mins, elapsed);
    //           return 0;
    //         }
    //         base = dword_7C54E0;
    //       }
    //     }
    //     if (*(int*)(base + 16532) != 2 || elapsed < 0.0f || *(int*)(base + 16484)) {
    //       strcpy(out, asc_5CCE18);
    //       return 0;
    //     }
    //     int mins; SpatialGridCell(elapsed, &mins, &elapsed);
    //     StringFormatWithBufferOverflowCheck(out, " %.2d:%06.3f", mins, elapsed);
    //     return 0;
    //   }
    // UNRESOLVED: flt_59E440 and asc_5CCE24 (a2d063f_1) are listed as referenced globals but do not appear in the raw decompiled body; their exact role is unresolved.
    // UNRESOLVED: Semantic meaning of the object fields at base + 16536, +16444, +16532 and +16484 (elapsed base, count, mode value, flag) is unresolved.
    // UNRESOLVED: Purpose of argument a2 is unknown.
}
