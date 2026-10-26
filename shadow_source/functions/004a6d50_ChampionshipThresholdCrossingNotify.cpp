// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A6D50
// Canonical corpus name: sub_4A6D50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A6D50_004a6d50.c

void UnknownObject::ChampionshipThresholdCrossingNotify()
{
    // In a championship session (global dword_7C56A4 == 7), checks whether the player's score plus one (obj+0x403C) matches any entry of a stride-2 threshold array rooted at this+0x164 with element count this+0x160. On a match, calls StateChangeNotify(this, 1) to trigger a championship state transition. Guards: enable flag at obj+0x4040 must be non-zero and at least one threshold entry must exist. Called on lap completion.
    // GUARD: Global session-type check: dword_7C56A4 must equal 7 (championship session) before anything else runs. [source:raw, global:0x007C56A4]
    // ASSIGNMENT: Dereference this+0x0 to obtain the player/championship data object pointer. [source:raw, field:this:0x00000000]
    // GUARD: Enable-flag check: the value at obj+0x4040 (via *this + 16448) must be non-zero for the threshold check to proceed. [source:raw, field:obj:0x00004040]
    // CALCULATION: Compute the next threshold target as the player's score (obj+0x403C, via *this + 16444) plus one. [source:raw, field:obj:0x0000403C]
    // GUARD: Element-count guard: this+0x160 must be greater than zero (at least one threshold entry exists) to enter the scan loop. [source:raw, field:this:0x00000160, guard:0]
    // LOOP: Iterate the stride-2 threshold array starting at this+0x164, comparing the even-indexed entries against the target score+1. [source:raw, field:this:0x00000164]
    // CALL: When an entry equals the target, call StateChangeNotify(this, 1) to signal the championship state transition. [callee:0x004A5C80]
    // RETURN: Function returns void; no value is produced when guards fail or no threshold matches. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_4A6D50(int *this) {
    //     if (dword_7C56A4 != 7) return;
    //     if (*(int *)(*this + 16448) == 0) return;
    //     int target = *(int *)(*this + 16444) + 1;
    //     for (int i = 0; i < this[0x160 / 4]; ++i) {
    //       if (this[0x164 / 4 + i * 2] == target)
    //         StateChangeNotify(this, 1);
    //     }
    //   }
    // UNRESOLVED: The exact meaning of the obj fields at +0x403C (score) and +0x4040 (enable flag) and of the threshold values is inferred from context and not independently confirmed.
    // UNRESOLVED: Whether StateChangeNotify may fire multiple times when several thresholds match the same target is unresolved.
}
