// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005473C0
// Canonical corpus name: TwoCounterIncrements
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoCounterIncrements_005473c0.c

void UnknownObject::IncrementTwoAdjacentCounters()
{
    // Thiscall helper that increments two adjacent dword counters on the owner object: this[34] (this+0x88) first, then this[33] (this+0x84). No reads, guards, or side effects beyond the two increments; runs on the per-frame path from three callers.
    // CALCULATION: Increment the first counter: ++this[34] at this+0x88. [field:this:0x00000088, source:raw, function:0x005473C0]
    // CALCULATION: Increment the second counter: ++this[33] at this+0x84. [field:this:0x00000084, source:raw]

    // Conservative worker pseudocode:
    //   void sub_5473C0(void* this) {
    //     ((int*)this)[34]++;
    //     ((int*)this)[33]++;
    //   }
    // UNRESOLVED: Purpose and meaning of the two counters (this+0x84, this+0x88) are not established; the existing fill labels them adjacent counters incremented unconditionally on the frame path.
    // UNRESOLVED: The increment order (this[34] before this[33]) is preserved from the raw source but may not be meaningful.
    // UNRESOLVED: Relationship of this object to the TreeNodeAccumulator caller and the two other per-frame callers is unknown.
}
