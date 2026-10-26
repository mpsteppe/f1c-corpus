// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464EF0
// Canonical corpus name: FloatFractionFromInt
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatFractionFromInt_00464ef0.c

void UnknownObject::FloatFractionFromInt()
{
    // Accumulator fraction processing. Adds incoming float a2 to the accumulator at this[26] (offset 0x68), converts the sum to its integer part v4 via CRTFtol (0x00587BDC), iterates 104 records starting at this+35 with a 560-byte stride calling sub_464B10 (0x00464B10) with v4 for each, then stores the fractional remainder (v3 - v4 * 0.0049999999) back into the accumulator. Returns the last sub_464B10 result. Called from ResourceManagerFrameCleanup (0x004651C0).
    // CALCULATION: Accumulate: v3 = a2 + this[26], reading the float accumulator at offset 0x68 as a double. [field:this:0x00000068, source:raw]
    // CALL: Convert the accumulated sum v3 to its integer part v4 with CRTFtol (0x00587BDC). [callee:0x00587BDC]
    // LOOP: do-while loop over exactly 104 records: element pointer starts at this+35 and advances 560 bytes each iteration; a counter seeded from 104 counts down to zero. [source:raw]
    // CALL: Each iteration call sub_464B10 (0x00464B10) on the current record pointer with the integer part v4, storing its return value as result. [callee:0x00464B10, source:raw]
    // ASSIGNMENT: Write the fractional remainder back: this[26] = v3 - v4 * 0.0049999999, keeping the leftover in the accumulator. [field:this:0x00000068, source:raw]
    // RETURN: Return the last result produced by sub_464B10. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_464EF0(float *this, float a2) {
    //     double v3 = a2 + this[26];
    //     int v4 = CRTFtol(v3);
    //     float *p = this + 35;
    //     int n = 104;
    //     int result;
    //     do { result = sub_464B10(p, v4); p += 560; --n; } while (n);
    //     this[26] = (float)(v3 - (double)v4 * 0.0049999999);
    //     return result;
    //   }
    // UNRESOLVED: Global flt_59F138 (0x0059F138) is listed as read by the compiled function but does not appear in the decompiled listing; its role is not established.
    // UNRESOLVED: The 104 records of 560 bytes starting at this+35 form an array of unknown element type.
    // UNRESOLVED: Semantics of the accumulator and the 0.0049999999 scaling (suggesting a fractional distribution scheme) are guessed, not confirmed.
}
