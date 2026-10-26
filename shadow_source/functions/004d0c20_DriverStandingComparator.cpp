// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D0C20
// Canonical corpus name: DriverStandingComparator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DriverStandingComparator_004d0c20.c

void UnknownObject::DriverStandingComparator()
{
    // qsort-style comparator for two drivers addressed by the index bytes at this+0x0 into the 18624-byte-per-driver array base unk_5F070C. A driver whose status dword at +12 equals 3 (retired) sorts after an active driver; otherwise the integer rank dword at +11 is compared, then the float time/gap at +26 against the zero threshold flt_59E440, then the slot pointer addresses as a stable tiebreaker. Invoked by PitStopOrderRank (004D1BC0).
    // CALCULATION: Slot base pointers: v2 = unk_5F070C + 18624 * a1_driver_index and v3 = unk_5F070C + 18624 * a2_driver_index, where each driver index is the byte read from field this+0x0 and the array stride is 18624 bytes per driver [field:this:0x00000000, global:0x005F070C, source:raw]
    // GUARD: Retired-first branch: when the status dword at v2 + 12 equals 3 (retired) and the status dword at v3 + 12 (v4) is not 3, return 1 so the retired driver sorts after the active one [source:raw]
    // GUARD: Retired-vs-retired rank compare: when both status dwords equal 3, compare the rank dwords at +11 and return -1 when the first driver's rank (v6) is below the second driver's (v5) [source:raw]
    // GUARD: Active-first branch: when the driver at v2 is not retired (status dword at +12 != 3) but the driver at v3 is retired (v4 == 3), return -1 so the active driver sorts first [source:raw]
    // CALCULATION: Active-vs-active float compare at dword +26 (byte offset 104): return -1 when the float at v2 + 26 is not below the zero threshold flt_59E440, return 1 when it is strictly below zero, and otherwise compare the second driver's +26 float against the first's, returning -1 when greater and 1 when less [global:0x0059E440, source:raw]
    // GUARD: Rank tiebreak: v12 = the dword at v3 + 11 and v13 = the dword at v2 + 11; return -1 when the first driver's rank (v13) is below the second driver's (v12) [source:raw]
    // RETURN: Common tail: if the equality flag v7 (a1 rank <= a2 rank, set by the last rank comparison) is false return 1; otherwise return -1 when the v3 pointer exceeds v2, else return the boolean v3 < v2 as the final stable tiebreaker [function:0x004D0C20, source:raw]
    // CALL: Invoked by PitStopOrderRank (004D1BC0) as a sorting comparator over driver indexes [caller:0x004D1BC0]

    // Conservative worker pseudocode:
    //   v2 = unk_5F070C + 18624 * a1_driver_index;
    //   v3 = unk_5F070C + 18624 * a2_driver_index;
    //   if (status_dword(v2 + 12) == 3) {
    //     if (status_dword(v3 + 12) != 3) return 1;
    //     if (rank_dword(v2 + 11) < rank_dword(v3 + 11)) return -1;
    //   } else {
    //     if (status_dword(v3 + 12) == 3) return -1;
    //     if (time_gap_float(v2 + 26) >= 0.0) return -1;
    //     if (time_gap_float(v2 + 26) < 0.0) return 1;
    //     if (time_gap_float(v3 + 26) > time_gap_float(v2 + 26)) return -1;
    //     if (time_gap_float(v3 + 26) < time_gap_float(v2 + 26)) return 1;
    //     if (rank_dword(v2 + 11) < rank_dword(v3 + 11)) return -1;
    //   }
    //   if (!(a1_rank <= a2_rank)) return 1;
    //   if (v3 > v2) return -1;
    //   return v3 < v2;
    // UNRESOLVED: The gating registers v10/v11 in the active-vs-active branch are Hex-Rays artifacts of a float comparison (condition-code bytes); the effective test is the sign of the float at dword +26, but the original expression shape is ambiguous
    // UNRESOLVED: Status value 3 is interpreted as retired and the +11 dword as rank and +26 float as time/gap from existing_analysis; those semantics are DERIVED, not confirmed by this packet alone
}
