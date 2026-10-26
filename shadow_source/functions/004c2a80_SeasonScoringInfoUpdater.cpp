// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2A80
// Canonical corpus name: SeasonScoringInfoUpdater
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SeasonScoringInfoUpdater_004c2a80.c

void UnknownObject::SeasonScoringInfoUpdater()
{
    // Updates season scoring statistics from the player vehicle during a race session: gated by ScoringGateCheck, adds the player's lap count into the current track scene node, records the player's minimum speed, feeds the lap count into the Accumulator, and in Race session mode applies a moving-average filter and increments a counter. In championship modes 3/4 it evaluates the 90%-race-distance completion criterion (with an audio stop and a season-scoring data read) before returning an arithmetic comparison result.
    // CALL: ScoringGateCheck() gates the whole update; if it returns false the function returns immediately. [callee:0x0042BC10, source:raw]
    // GUARD: If dword_8AB6E4 (0x008AB6E4) equals 2 the update is skipped and the gate result is returned. [global:0x008AB6E4, source:raw]
    // CALCULATION: Compute the current scene record address v3 = dword_8AC490 (0x008AC490) + 396 * dword_8AC48C (0x008AC48C). [global:0x008AC490, global:0x008AC48C, source:raw]
    // CALL: TrackSceneNodeAdd(this, v3 + 4) obtains the track scene node v4 when v3 is non-null; otherwise v4 falls back to the uninitialized local v11. [callee:0x004C28D0, source:raw]
    // ASSIGNMENT: Accumulate the player's lap count into the scene node: *(v4 + 16) += laps at dword_7C54E8 (0x007C54E8) + 16444. [global:0x007C54E8, source:raw]
    // ASSIGNMENT: Minimum-speed tracking: when the player's speed at dword_7C54E8 + 16540 is positive and below the node's stored value at v4 + 20 (or that field is unset), copy it into *(v4 + 20). [global:0x007C54E8, source:raw]
    // CALL: Accumulator(this, laps at dword_7C54E8 + 16444) feeds the lap count into the accumulator object. [callee:0x004C2BE0, global:0x007C54E8, source:raw]
    // GUARD: Race-session branch: only when dword_7C56A4 (0x007C56A4) equals 7. [global:0x007C56A4, source:raw]
    // CALL: MovingAverageFilterWithClamp(this, v6) applies a running average where v6 = dword_7C54E8 + 16480, and SimpleCounterIncrement(this) runs when v6 == 1. [callee:0x004C2CB0, callee:0x004C2C20, global:0x007C54E8, source:raw]
    // GUARD: Championship-mode branch: only when dword_7D0410 (0x007D0410) is 3 or 4. [global:0x007D0410, source:raw]
    // GUARD: Race-completion criterion: the vehicle state at dword_7C54E8 + 16484 must differ from 3, the laps at dword_7C54E8 + 16444 must reach CRTFtol(0.89999998 * dword_8ACF8C) (90% of the race distance at 0x008ACF8C), and AudioChannelStop(dword_8AD3B4 at 0x008AD3B4, aSeasonscoringi at 0x005D2804) must succeed. [global:0x007C54E8, global:0x008ACF8C, global:0x008AD3B4, global:0x005D2804, callee:0x00587BDC, callee:0x00568210, source:raw]
    // CALL: When the criterion passes, NullCheckWrapper(v6 - 1) guards a DataEntryAccessor(...) / sub_587ECE(...) read chain that computes the return value v8. [callee:0x005679A0, callee:0x00567970, callee:0x00587ECE, source:raw]
    // RETURN: Returns ArithmeticComparison_2c00(this, v8) in championship mode, otherwise the earlier Accumulator result. [callee:0x004C2C00, source:raw]

    // Conservative worker pseudocode:
    //   result = ScoringGateCheck();
    //   if (!result || dword_8AB6E4 == 2) return result;
    //   v3 = dword_8AC490 + 396 * dword_8AC48C;
    //   v4 = v3 ? TrackSceneNodeAdd(this, v3 + 4) : v11;
    //   if (v4) {
    //     v4[16] += player_laps;
    //     if (player_speed > 0.0 && (player_speed < v4[20] || v4[20] <= 0.0)) v4[20] = player_speed;
    //   }
    //   result = Accumulator(this, player_laps);
    //   if (dword_7C56A4 == 7) {
    //     v6 = player_field_16480;
    //     MovingAverageFilterWithClamp(this, v6);
    //     if (v6 == 1) SimpleCounterIncrement(this);
    //     result = dword_7D0410;
    //     if (dword_7D0410 == 4 || dword_7D0410 == 3) {
    //       if (state_16484 != 3 && laps >= (int)CRTFtol(0.89999998 * dword_8ACF8C) && AudioChannelStop(dword_8AD3B4, aSeasonscoringi)) {
    //         v9 = NullCheckWrapper(v6 - 1);
    //         if (v9) v8 = sub_587ECE(DataEntryAccessor(v9));
    //       }
    //       return ArithmeticComparison_2c00(this, v8);
    //     }
    //   }
    //   return result;
    // UNRESOLVED: The read-only globals flt_59E440 (0x0059E440), flt_59E824 (0x0059E824) and unk_5EC6D0 (0x005EC6D0) are not directly referenced in the raw function body (the threshold renders the literal 0.0 and the 90% factor renders as 0.89999998); they are left unassigned.
    // UNRESOLVED: The local v11 is read uninitialized on the v3 == 0 path (v4 = v11); the raw source preserves this, so the uninitialized fallback is not resolved here.
    // UNRESOLVED: The semantics of sub_587ECE (0x00587ECE) and DataEntryAccessor (0x00567970) are not documented; the season-scoring data read chain is described at call level only.
}
