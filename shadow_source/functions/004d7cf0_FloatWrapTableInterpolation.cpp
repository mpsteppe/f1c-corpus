// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7CF0
// Canonical corpus name: FloatWrapTableInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatWrapTableInterpolation_004d7cf0.c

void UnknownObject::FloatWrapTableInterpolation()
{
    // Wraps float a2 into the range [0, this[9]) (the period stored at field offset 0x24), looks up the containing segment via FloatRangeIndexLookup, and returns the linear interpolation factor within that segment. Optionally stores the segment index into *a3.
    // GUARD: If a2 < 0.0, wrap upward into the positive range by repeatedly adding this[9], the wrap period stored at field offset 0x24. [field:this:0x00000024, source:raw]
    // LOOP: Add this[9] to the working value while it remains below 0.0. [field:this:0x00000024, source:raw]
    // GUARD: If the working value exceeds this[9], wrap downward by repeatedly subtracting this[9]. [field:this:0x00000024, source:raw]
    // LOOP: Subtract this[9] from the working value while it stays above this[9]. [field:this:0x00000024, source:raw]
    // CALL: Call FloatRangeIndexLookup(this, a2) to obtain the segment index v6 containing the wrapped value. [callee:0x004D7C10, source:raw]
    // CALCULATION: Compute the interpolation factor as (a2 - this[v6 + 6]) / (this[v6 + 9] - this[v6 + 6]) using the segment boundary values read from the table rows. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: If a3 is non-null, write the segment index v6 into *a3. [source:raw]
    // RETURN: Return the computed interpolation factor. [source:raw]

    // Conservative worker pseudocode:
    //   wrap = a2;
    //   if (wrap < 0.0)
    //       do { wrap += this[9]; } while (wrap < 0.0);
    //   if (wrap > this[9])
    //       do { wrap -= this[9]; } while (wrap > this[9]);
    //   a2 = wrap;
    //   v6 = FloatRangeIndexLookup(this, a2);
    //   factor = (a2 - this[v6 + 6]) / (this[v6 + 9] - this[v6 + 6]);
    //   if (a3) *a3 = v6;
    //   return factor;
    // UNRESOLVED: flt_59E440 is listed as a referenced global but does not appear in the raw decompilation of this function; its role here is unresolved.
    // UNRESOLVED: The table layout (segment boundary rows at this[v6 + 6] and this[v6 + 9]) is inferred from the interpolation arithmetic; segment-boundary semantics are not independently established.
    // UNRESOLVED: The type and meaning of the object behind 'this' are unknown.
}
