// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A4110
// Canonical corpus name: sub_4A4110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A4110_004a4110.c

void UnknownObject::AIIncidentCooldownCheck()
{
    // Per-frame AI incident trigger check. Iterates the vehicle slot array (count dword_5C329C) with `this` treated as a float array of per-slot vehicle pointers; zeroes inactive slots, and blocks an incident for a vehicle whose speed delta against the player is in (-55.0, 0.0) while its state word at +17744 is non-zero, +17680 is not 4/5, and +17472 exceeds 2.0. Then guards on session type dword_7C56A4 (7 returns true) and race progress (a2+17800 vs a2+17888), computes a remaining-vehicle ratio v37 and a session-time progress v20 (flt_8ACF90/flt_8ACF94/dbl_8AFEA0), picks a probability multiplier v3 from a ladder of branches keyed on state flags (StateFlagsLookup) and a rank count at a2+18596, and fires the incident only when a cooldown timestamp at this+0x1A0 is expired — writing this+0x1A0 = current session time + 18.0 when it fires. A random roll (RandLCGRandomNumberGenerator modulo CRTFtol) additionally gates the fire path.
    // LOOP: Iterate slot array `this[0 .. dword_5C329C)`; each slot holds a vehicle pointer, and per-frame caller AIMainUpdate drives the check. [global:0x005C329C, caller:0x00424E70, source:raw]
    // GUARD: Per slot: when the vehicle pointer is non-null, branch on its state word at +17744 (decimal) to separate active from inactive vehicles. [source:raw]
    // ASSIGNMENT: For an inactive vehicle (state word at +17744 zero), write this[i] = 0.0 to clear the slot. [source:raw]
    // CALL: For an active vehicle, call AIDelegateCall on the vehicle pointer and then SpeedDeltaComputation(a2, vehicle) to obtain its speed delta relative to the player context. [callee:0x0042ADD0, callee:0x00426CC0, source:raw]
    // GUARD: When the speed delta is in (-55.0, 0.0) and the vehicle's state word at +17680 is not 4 or 5 and its value at +17472 is greater than 2.0, return 0 (block the incident for that vehicle). [source:raw]
    // GUARD: When session type dword_7C56A4 equals 7, return 1 immediately. [global:0x007C56A4, source:raw]
    // GUARD: When race-progress counter at a2+17800 (decimal) is <= the comparison value at a2+17888 (decimal), return 0. [source:raw]
    // LOOP: Second pass over dword_5C329C slots counting active (non-null) vehicle pointers, producing count v14. [global:0x005C329C, source:raw]
    // CALCULATION: Compute remaining-ratio v37 = 1.0 - activeCount * 0.090909094 for session types 3/4/5, else activeCount * 0.071428575; clamp the result to a minimum of 0.0099999998. [global:0x007C56A4, source:raw]
    // CALCULATION: Compute session-time progress v20 = (dbl_8AFEA0 - flt_8ACF90) / clamped window (flt_8ACF90 .. flt_8ACF94, floor 1.0). [global:0x008AFEA0, global:0x008ACF90, global:0x008ACF94, source:raw]
    // STATE_TRANSITION: Branch ladder on v20 (0.25 / 0.5 / 0.75) selecting probability multiplier v3 from StateFlagsLookup(a2) scaled values and a rank count at a2+18596 (decimal); candidate constants include 0.25, 0.69999999, 0.85000002, 0.80000001, 0.2, 0.1, 0.66000003, 0.40000001, 0.0099999998 and 1.0. [callee:0x0042AE90, global:0x007C56A4, source:raw]
    // CALCULATION: Compute cooldown interval v31 = v3 * v37 * 18.0 with a floor of 0.001 when zero, then v35 = 0.25 / v31 * session-time window width. [global:0x008ACF90, global:0x008ACF94, source:raw]
    // GUARD: When v35 < 1.0: if dbl_8AFEA0 is below the cooldown timestamp this+0x1A0 return 0; otherwise set this+0x1A0 = dbl_8AFEA0 + 18.0 and return 1. [field:this:0x000001A0, global:0x008AFEA0, source:raw]
    // CALL: Roll RandLCGRandomNumberGenerator; when session type is 7 or the roll modulo CRTFtol equals 0, repeat the this+0x1A0 cooldown comparison and return 1 when expired. [callee:0x005884ED, callee:0x00587BDC, global:0x007C56A4, field:this:0x000001A0, global:0x008AFEA0, source:raw]
    // RETURN: Default path returns 0 (no incident this frame). [source:raw]

    // Conservative worker pseudocode:
    //   char AIIncidentCooldownCheck(float* slots, void* race) {
    //     for (i = 0; i < dword_5C329C; i++) {
    //       veh = (int)slots[i];
    //       if (veh) {
    //         if (*(veh + 17744)) {
    //           if (SpeedDeltaComputation(race, AIDelegateCall(veh)) < 0.0
    //               && it > -55.0
    //               && *(veh + 17680) != 4 && *(veh + 17680) != 5
    //               && *(float*)(veh + 17472) > 2.0) return 0;
    //         } else {
    //           slots[i] = 0.0;
    //         }
    //       }
    //     }
    //     if (dword_7C56A4 == 7) return 1;
    //     if (*(race + 17800) <= *(race + 17888)) return 0;
    //     active = countActive(slots, dword_5C329C);
    //     ratio = 1.0 - active * (dword_7C56A4 in {3,4,5} ? 0.090909094 : 0.071428575);
    //     if (ratio < 0.0099999998) ratio = 0.0099999998;
    //     progress = clamp01((dbl_8AFEA0 - flt_8ACF90) / window(flt_8ACF90, flt_8ACF94));
    //     v3 = selectMultiplier(v20, StateFlagsLookup(race), *(race + 18596));
    //     interval = max(v3 * ratio * 18.0, 0.001);
    //     scale = 0.25 / interval * window(flt_8ACF90, flt_8ACF94);
    //     if (scale < 1.0) {
    //       if (dbl_8AFEA0 < slots[104]) return 0;      // this+0x1A0 cooldown
    //       slots[104] = dbl_8AFEA0 + 18.0;
    //       return 1;
    //     }
    //     if (dword_7C56A4 == 7 || RandLCGRandomNumberGenerator() % CRTFtol(scale) == 0)
    //       if (dbl_8AFEA0 >= slots[104]) { slots[104] = dbl_8AFEA0 + 18.0; return 1; }
    //     return 0;
    //   }
    // UNRESOLVED: Twenty-four physics/threshold globals (flt_59E43C..flt_59E9B8, flt_5ACB0C..flt_5ACB48) are listed by extraction as read here but never appear in the raw source text; their operation is not visible and could not be mapped.
    // UNRESOLVED: Packet ABI lead names this function AI_Overtaking_Aggression_Probability (LEGACY) while the existing-analysis title is AIIncidentCooldownCheck; the recovered flow fits the cooldown/trigger interpretation.
    // UNRESOLVED: Vehicle state semantics: +17744 (active), +17680 (driving-state enum 4/5 special values), +17472 (threshold > 2.0) are not named; exact enum meaning unknown.
    // UNRESOLVED: Race-context fields a2+17800, a2+17888, a2+16444, a2+16540, and rank count at a2+18596 (decimal) have unknown exact meaning.
    // UNRESOLVED: Origin of the -55.0 speed-delta bound and the 18.0-second cooldown constant is unknown.
}
