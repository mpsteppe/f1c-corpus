// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B17B0
// Canonical corpus name: sub_4B17B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B17B0_004b17b0.c

void UnknownObject::SeasonDataFreeAtHalfDistance()
{
    // Session-phase-gated season-data free. Proceeds only when the global session type dword_7C56A4 is 5 (race) or 7 (qualifying). Within that branch, inspects the session phase field this+0x1F78 (this[2014]): when the phase is not 3 and then equals 4, and the half-distance flag byte_8ACFA0 is set, calls ConditionalSeasonDataFree(1) and returns its result; otherwise the accumulated phase-difference value or flag value is returned.
    // GUARD: Session-type gate: dword_7C56A4 must equal 5 or 7 to enter the phase-check branch. [global:0x007C56A4, source:raw]
    // GUARD: Phase field this+0x1F78 (this[2014]) must not equal 3 (guard:0) to continue toward the phase-4 check. [guard:0, field:this:0x00001F78, source:raw]
    // GUARD: Phase field this+0x1F78 (this[2014]) must equal 4 (guard:1) for the half-distance free path. [guard:1, field:this:0x00001F78, source:raw]
    // GUARD: Half-distance flag byte_8ACFA0 must be non-zero for ConditionalSeasonDataFree to run. [global:0x008ACFA0, source:raw]
    // CALL: ConditionalSeasonDataFree(1) frees season data with literal argument 1 when session type is 5/7, the phase is 4 and the half-distance flag is set; its result is returned. [callee:0x004C2830, source:raw]
    // RETURN: When the free is not performed, the return value is the accumulated phase-difference value (this[2014]-3 or this[2014]-4) or the byte_8ACFA0 flag value (cast to unsigned byte). [field:this:0x00001F78, global:0x008ACFA0, source:raw]
    // CALL: Invoked by sub_4A0760 (0x004A0760), the callers list entry. [caller:0x004A0760, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7C56A4 == 5 || dword_7C56A4 == 7) {
    //     if (this[2014] != 3) {
    //       if (this[2014] == 4) {
    //         if (byte_8ACFA0) return ConditionalSeasonDataFree(1);
    //       }
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The legacy ABI label 'HotlapRecordingCheck' (abi:lead) is inconsistent with the raw source, which frees season data when the half-distance flag is set; the proposed name follows the existing analysis fill (SeasonDataFreeAtHalfDistance) at DERIVED trust.
    // UNRESOLVED: The exact numeric meaning of session phase 3 vs 4 in this+0x1F78 and of the ConditionalSeasonDataFree literal argument 1 is not established from this packet alone.
    // UNRESOLVED: dword_7C56A4 == 5/7 is read as race/qualifying session types from the existing fill (FACT-flagged session type), which is adopted as context but not independently re-proven here.
}
