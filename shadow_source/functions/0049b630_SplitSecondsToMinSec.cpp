// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049B630
// Canonical corpus name: SpatialGridCell
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialGridCell_0049b630.c

void UnknownObject::SplitSecondsToMinSec()
{
    // Pure time-unit conversion: truncates the input a1 to a whole value, divides it by 60 (scaled by 0.016666668) to obtain whole minutes, stores the minutes into *a2, computes the remaining seconds as a1 minus minutes*60.0 into *a3, and returns the minutes. Called by eleven collision/session-grid callers, indicating a shared formatting or grid-decomposition helper.
    // CALL: Truncate input a1 to a whole integer v4 via CRTFtol. [callee:0x00587BDC]
    // CALCULATION: Scale the truncated value by 0.016666668 (approximately 1/60) to convert the unit. [source:raw]
    // CALL: Truncate the scaled value to whole minutes via CRTFtol. [callee:0x00587BDC]
    // ASSIGNMENT: Store the whole minutes into the output pointed to by a2. [source:raw]
    // CALCULATION: Compute the remainder as a1 minus minutes * 60.0. [source:raw]
    // ASSIGNMENT: Store the remainder seconds into the output pointed to by a3. [source:raw]
    // RETURN: Return the whole minutes value. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49B630(float a1, int* a2, float* a3) {
    //     int whole = CRTFtol(a1);
    //     int minutes = CRTFtol((double)whole * 0.016666668);
    //     *a2 = minutes;
    //     *a3 = a1 - (double)minutes * 60.0;
    //     return minutes;
    //   }
    // UNRESOLVED: The units and scale of input a1 (assumed seconds) cannot be proven from this function alone.
    // UNRESOLVED: Globals flt_59E9C0 and flt_59F118 are listed as read but do not appear in the decompiled text; they may back the 0.016666668 / 60.0 constants in the binary.
    // UNRESOLVED: The caller-dependent meaning of the minute/second decomposition (grid cell, lap timing, or geometry) is unknown; the legacy ABI name SpatialGridCell is not trusted.
}
