// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005836E0
// Canonical corpus name: CounterAssignment
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CounterAssignment_005836e0.c

void UnknownObject::incrementCounterAndStore()
{
    // Counter assignment helper: stores a3 into this[1] (offset 0x4) and a4 into this[2] (offset 0x8), increments the counter at this[0] by 1, writes the incremented counter through the output pointer a2, and returns a2. Structural twin of TripleFieldSetter (00456280) per the packet's cluster_copy prelabel. Called by AnimationTimingUpdateWithParamSet (0057A5A0).
    // ASSIGNMENT: Store a3 into this[1] at offset 0x4 [field:this:0x00000004, source:raw]
    // CALCULATION: Compute v4 as the current counter at this[0] plus 1 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store a4 into this[2] at offset 0x8 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write the incremented counter v4 back to this[0] at offset 0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the incremented counter value through the output pointer a2 [source:raw]
    // RETURN: Return the output pointer a2 [source:raw]
    // CALL: Invoked by AnimationTimingUpdateWithParamSet (0057A5A0) to update the counter and latched values [caller:0x0057A5A0]

    // Conservative worker pseudocode:
    //   this[1] = a3;
    //   v4 = *this + 1;
    //   this[2] = a4;
    //   *this = v4;
    //   *a2 = v4;
    //   return a2;
    // UNRESOLVED: The roles of the two latched values a3/a4 and the purpose of the counter at this[0] are not established; the counter may track animation/timing ticks in caller 0057A5A0
    // UNRESOLVED: The cluster_copy association with TripleFieldSetter (00456280) is structural only and does not prove identical semantics
}
