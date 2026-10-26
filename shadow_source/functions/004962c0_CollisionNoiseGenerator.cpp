// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004962C0
// Canonical corpus name: CollisionNoiseGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionNoiseGenerator_004962c0.c

void UnknownObject::CollisionNoiseGenerator()
{
    // Piecewise-linear lookup-table noise generator. Maps the input a2 to a table index v4 = floor(a2 * 16.0) via CRTFtol, issues an interrupt dispatch, and returns 1.0 when the index is out of the 16-entry table (v4 >= 16). Otherwise reads two adjacent float samples from the table embedded in this (samples at this[1419] and this[1420], i.e. float offset 0x162C; the next sample is 1.0 at the final index 15) and linearly interpolates between them with fraction a2 * 16.0. When the blend parameter a3 >= 0, both samples are first passed through the per-sample transform sub_5881F0.
    // CALCULATION: Compute the lookup index v4 = CRTFtol(a2 * 16.0). [callee:0x00587BDC, source:raw]
    // CALL: Call InterruptDispatch each noise sample to service runtime dispatch/interrupt checks. [callee:0x0058957A, source:raw]
    // GUARD: Out-of-range guard: if v4 >= 0x10 the index is outside the 16-entry table and the function returns 1.0. [source:raw]
    // ASSIGNMENT: Load the current table sample v9 = this[v4 + 1419]; load the next sample as v5 = 1.0 when v4 == 15 (table edge) else this[v4 + 1420]. [source:raw]
    // GUARD: Conditional transform guard: when a3 >= 0.0, apply sub_5881F0 to both samples before interpolating. [callee:0x005881F0, source:raw]
    // CALL: Run the per-sample transform: sub_5881F0(v9) on the current sample and sub_5881F0(v7) on the retained next-sample value. [callee:0x005881F0, source:raw]
    // RETURN: Return the linear interpolation result (v5 - v9) * (a2 * 16.0) + v9. [source:raw]
    // CALL: Invoked by sub_495DC0 (0x00495DC0) to produce per-sample noise for the collision damage system. [caller:0x00495DC0, source:raw]

    // Conservative worker pseudocode:
    //   double sub_4962C0(this, float a2, float a3) {
    //     v4 = (unsigned)CRTFtol(a2 * 16.0f);
    //     InterruptDispatch(a2);
    //     if (v4 >= 16) return 1.0;
    //     v9 = this[v4 + 1419];
    //     v5 = (v4 == 15) ? 1.0 : this[v4 + 1420];
    //     v7 = v5;
    //     if (a3 >= 0.0f) {
    //       sub_5881F0(v9);
    //       v5 = v7;
    //       sub_5881F0(v7);
    //     }
    //     return (v5 - v9) * (a2 * 16.0f) + v9;
    //   }
    // UNRESOLVED: The transform sub_5881F0 is called for its side effect on the sample values; its exact transformation is outside this function.
    // UNRESOLVED: The float table at this[1419] (float offset 0x162C) is an inline lookup table whose 16 entries are set up elsewhere.
    // UNRESOLVED: Four globals flagged by the packet (flt_59E43C, flt_59E440, flt_59EED0, dbl_5AC9D0) do not appear as literals in the raw decompiled text; existing analysis attributes them to the 16.0 scaling, the a3 zero-threshold and sub_5881F0's internal transform, but that mapping is not verifiable from this function alone.
    // UNRESOLVED: The IEEE-754 spelling of the 16.0 scale is taken from the raw source literal, not from dbl_5AC9D0.
}
