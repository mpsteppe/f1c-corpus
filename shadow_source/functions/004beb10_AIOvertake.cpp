// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BEB10
// Canonical corpus name: AIOvertake
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIOvertake_004beb10.c

void UnknownObject::AIOvertake()
{
    // AI overtaking behavior step. Clears an output flag, copies the total race laps and session type into the behavior object, decides whether an overtake/behavior update is allowed by comparing the accumulated time at +0x354 against the threshold at +0x358, scans the vehicle array for human drivers when the session is qualifying type 7, then calls AIBehaviorInitialization when the activation flag at +0x342 is clear. Accumulates the time increment at +0x350 into +0x354 and tail-jumps into the rest of the behavior update.
    // ASSIGNMENT: Write 0 to the caller output byte *a2 (overtake-allowed flag). [source:raw]
    // ASSIGNMENT: Read accumulated-time threshold at this+0x358 into v4, store total race laps dword_8ACF8C into this+0x35C, capture vehicle count dword_5C329C into v5, store session type dword_7C56A4 into this+0x360, and initialize locals v7=1, v8=0. [field:this:0x00000358, field:this:0x0000035C, field:this:0x00000360, global:0x008ACF8C, global:0x005C329C, global:0x007C56A4]
    // GUARD: Guard: if the threshold at this+0x358 is <= 0.0, or the accumulated time at this+0x354 is below the threshold at this+0x358, take the scan branch; otherwise set v8=1 (allowed) and v7=0. [field:this:0x00000354, field:this:0x00000358]
    // GUARD: Guard on session type dword_7C56A4 == 7 (qualifying): scan for a human-controlled vehicle before allowing the behavior branch. [global:0x007C56A4]
    // LOOP: Loop i from 0 to vehicle count dword_5C329C over the vehicle pointer array dword_7C54F0; if vehicle +16484 == 1 set v8=1 (a human driver present in qualifying). [global:0x005C329C, global:0x007C54F0]
    // GUARD: Guard on the activation flag at this+0x342: when clear, call AIBehaviorInitialization(a3, v8) to (re)initialize the AI behavior with the computed allow flag. [field:this:0x00000342, callee:0x004BF0A0]
    // CALCULATION: Accumulate the time increment at this+0x350 into the accumulator at this+0x354. [field:this:0x00000350, field:this:0x00000354]
    // STATE_TRANSITION: Control-flow dispatch by v7: when v7 is set and vehicle count is positive, tail-jump to 0x4BEC10; when v7 is set and no vehicles exist, tail-jump to 0x4BEEF2; otherwise tail-jump to 0x4BEF10 into the remaining behavior logic. [source:raw]

    // Conservative worker pseudocode:
    //   void AIOvertake(this, output_flag, a3) {
    //     *output_flag = 0;
    //     float threshold = this->field_0x358;
    //     this->field_0x35C = totalRaceLaps;  // dword_8ACF8C
    //     this->field_0x360 = sessionType;    // dword_7C56A4
    //     int count = vehicleCount;           // dword_5C329C
    //     char allow = 0;
    //     char branch = 1;
    //     if (threshold <= 0.0f || this->field_0x354 < this->field_0x358) {
    //       if (sessionType == 7)
    //         for (i = 0; i < count; ++i)
    //           if (vehiclePtrArray[i]->field_0x4064 == 1) allow = 1;
    //     } else { allow = 1; branch = 0; }
    //     if (!this->field_0x342) AIBehaviorInitialization(a3, allow);
    //     this->field_0x354 += this->field_0x350;
    //     // tail continues at 0x4BEC10 / 0x4BEEF2 / 0x4BEF10 per 'branch'
    //   }
    // UNRESOLVED: The tail behavior logic at 0x4BEC10 / 0x4BEEF2 / 0x4BEF10 is reached by JUMPOUT and is not present in the packet source.
    // UNRESOLVED: The semantics of the per-vehicle +16484 field read in the qualifying scan are unknown.
    // UNRESOLVED: The identity of the behavior object (this) and its owner class are unknown.
    // UNRESOLVED: dword_8ACF8C copied to this+0x35C is described elsewhere as TotalRaceLaps, but that role is not independently confirmed here.
}
