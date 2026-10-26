// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056F818
// Canonical corpus name: sub_56F818
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_56F818_0056f818.c

void UnknownObject::DataPatternSequenceValidator()
{
    // Validates the zero/non-zero run-length pattern of a 40-by-41 triangular sweep over an array of double rows (a1 points to an array of row pointers; row i scans elements i..39 of row i). Walks the rows with a shrinking window, accumulating run lengths of consecutive equal zero-ness, and requires each completed run to equal the matching entry of a hardcoded 84-word pattern table. Returns true only when every expected transition was consumed and the final in-progress run length equals 194.
    // ASSIGNMENT: Initialize the 84-entry hardcoded run-length pattern table v5[0..83] with word literals from the data segment (values between 0 and 194). [source:raw, function:0x0056F818]
    // ASSIGNMENT: Reset the pattern index v7=0, the run-length accumulator v8=0, and the expected zero/non-zero flag v9=1 (starts expecting a non-zero element). [source:raw]
    // GUARD: Return false immediately when the row element count a2 != 40. [source:raw]
    // LOOP: Outer do-while walks the row-pointer array (reached through this+0x0 / *a1) for v2 from 1 while v2 < 41, i.e. 41 row slots. [field:this:0x00000000, source:raw]
    // LOOP: Inner do-while scans the current row's doubles starting at element index v2 (8-byte stride) while the element index < 40, producing a shrinking window per row. [field:this:0x00000000, source:raw]
    // CALCULATION: Compare the current element's zero-ness (*v11 != 0.0) with the expected flag v9 to detect whether the current run has transitioned. [source:raw]
    // GUARD: At a run transition, return false if the pattern index v7 has reached 83, meaning the expected pattern is exhausted early. [source:raw]
    // GUARD: Compare the completed run length v8 against the pattern entry v5[v7]; a mismatch returns false. [source:raw]
    // STATE_TRANSITION: Commit a validated run: advance the pattern index v7, reset the run-length accumulator v8=0, and flip the expected zero/non-zero flag v9=!v9. [source:raw]
    // CALCULATION: While the element's zero-ness still matches the expected flag, increment the run-length accumulator v8. [source:raw]
    // RETURN: Return true only when the pattern was fully consumed (v7 == 82) and the final in-progress run length equals 194. [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_56F818(_DWORD *rowPtrs, int expectedCountPerRow) {
    //     word pattern[84] = { 2,2,1,11,4,14,0,2,1,11,4,17,1,11,4,14,1,1,1,14,4,9,0,1,1,14,4,11,1,14,4,9,0,11,4,26,4,14,0,14,4,24,4,9,1,2,1,11,4,4,0,2,1,11,4,7,1,11,4,4,1,1,1,14,5,1,1,14,4,1,1,14,5,11,4,16,4,4,0,14,4,14,194 };
    //     int patIdx = 0, runLen = 0;
    //     bool expectNonZero = true;
    //     if (expectedCountPerRow != 40) return false;
    //     for (int row = 1; row < 41; ++row) {
    //       double *elem = (double*)rowPtrs[row] + row;
    //       for (int idx = row; idx < 40; ++idx, ++elem) {
    //         if ((*elem != 0.0) != expectNonZero) {
    //           if (patIdx >= 83) return false;
    //           if ((word)runLen != pattern[patIdx++]) return false;
    //           runLen = 0;
    //           expectNonZero = !expectNonZero;
    //         } else {
    //           ++runLen;
    //         }
    //       }
    //     }
    //     return patIdx == 82 && (word)runLen == 194;
    //   }
    // UNRESOLVED: The zero comparison constant dbl_59E430 (global 0x0059E430) is flagged by packet facts as read but never appears in the raw decompiled source (the comparison uses a literal 0.0); its role as a zero sentinel is unverifiable here.
    // UNRESOLVED: a1 is an array of row pointers (this+0x0); the row count (41) and element count (40) are inferred from the guard and loop bounds, and the 8-byte element stride from the double* access only.
    // UNRESOLVED: No static callers or callees exist; the purpose of the validated data (likely a load-time integrity check of a hardcoded matrix) is unknown.
}
