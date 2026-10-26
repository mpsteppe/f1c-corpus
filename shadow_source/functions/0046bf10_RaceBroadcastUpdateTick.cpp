// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0046BF10
// Canonical corpus name: sub_46BF10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_46BF10_0046bf10.c

void UnknownObject::RaceBroadcastUpdateTick()
{
    // Race broadcast / AI overtake update tick. Derives a race-time budget from the session type (differential flt_8ACF94 - flt_8ACF90 for race sessions, 1000000000.0 for qualifying), acquires a session lock, then drains AI overtake events in a loop (AIOvertake) applying session updates, with an optional per-event update chain gated by argument a2. For qualifying (session type 7) it dispatches a sound-system vtable call, reinitializes an audio buffer and triggers race commentary. Releases the lock and runs a short computation before returning.
    // CALL: Delegation_e6f0 initializes the local 868-byte scratch buffer v7 before any use. [callee:0x004BE6F0]
    // ASSIGNMENT: Clear the loop-termination flag v5 = 0. [source:raw]
    // CALL: VirtualCallOnDAT008ac4c4_8d80 is invoked on &byte_8AC494 (scene/object structure). [callee:0x004C8D80, global:0x008AC494]
    // GUARD: Session-type guard: branch on dword_7C56A4 being greater than 0 to compute a time budget. [global:0x007C56A4]
    // CALCULATION: For session types 1..6 the budget is v6 = flt_8ACF94 - flt_8ACF90 (race-time delta). [global:0x008ACF94, global:0x008ACF90]
    // CALCULATION: For session type 7 (qualifying) the budget is the literal 1000000000.0, i.e. effectively unbounded. [global:0x007C56A4]
    // CALL: sub_4988C0(0) acquires the session/global lock before the overtake loop. [callee:0x004988C0]
    // LOOP: while (AIOvertake(&v5, v3)): process one AI overtake event; break when v5 is set; call sub_4A1830(&unk_7CE2A4) to update session data; when argument a2 is set, call sub_496880(this[16]) (field at this+0x40), ShortComputation_7250(1) and sub_496E90(1). [callee:0x004BEB10, callee:0x004A1830, global:0x007CE2A4, callee:0x00496880, field:this:0x00000040, callee:0x00497250, callee:0x00496E90]
    // GUARD: Qualifying finalization when dword_7C56A4 == 7: if dword_5EB10C (sound system pointer) is non-null, invoke its vtable method at offset 12; then BufferInitWith10fDefaults(flt_5EA618) and RaceCommentary(). [global:0x007C56A4, global:0x005EB10C, global:0x005EA618, callee:0x004186A0, callee:0x0041D630]
    // CALL: sub_4988C0(1) releases the session/global lock after the overtake loop. [callee:0x004988C0]
    // CALL: ShortComputation_7250(1) runs after the lock is released. [callee:0x00497250]
    // RETURN: EmptyStub_0170(&v7) tears down the scratch buffer and the function returns its result. [callee:0x004B0170]

    // Conservative worker pseudocode:
    //   Delegation_e6f0(&scratch);
    //   flag = 0;
    //   VirtualCallOnDAT008ac4c4_8d80(&byte_8AC494);
    //   if (dword_7C56A4 > 0) {
    //     if (dword_7C56A4 <= 6) budget = flt_8ACF94 - flt_8ACF90;
    //     else if (dword_7C56A4 == 7) budget = 1000000000.0;
    //   }
    //   sub_4988C0(0);
    //   while (AIOvertake(&flag, budget)) {
    //     if (flag) break;
    //     sub_4A1830(&unk_7CE2A4);
    //     if (a2) { sub_496880(this[16]); ShortComputation_7250(1); sub_496E90(1); }
    //   }
    //   if (dword_7C56A4 == 7) {
    //     if (dword_5EB10C) vtable[12](dword_5EB10C);
    //     BufferInitWith10fDefaults(flt_5EA618);
    //     RaceCommentary();
    //   }
    //   sub_4988C0(1);
    //   ShortComputation_7250(1);
    //   return EmptyStub_0170(&scratch);
    // UNRESOLVED: dword_5EB978 is packet-listed as a read global but has no occurrence in the raw source text.
    // UNRESOLVED: Exact meaning of the a2 argument and of the structure returned by AIOvertake is caller-supplied and unknown here.
    // UNRESOLVED: The qualifying (session 7) audio buffer reinit and commentary sequence is semantically inferred from callee names.
}
