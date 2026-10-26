// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C940
// Canonical corpus name: ShortComputation_c940
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_c940_0047c940.c

void UnknownObject::DifferenceFromLifetimeAverage()
{
    // Short computation of a time/measurement difference. Delegates on the shared global dword_8AB6EC via Delegation, truncates the caller-supplied double argument to float, then returns that float minus the value produced by VehicleLifetimeAverageAccessor reading the same global. Linear control flow; no branches. ABI LEGACY label is Short_Computation_Time_Difference.
    // CALL: Delegation(&dword_8AB6EC): perform the shared delegation/update step on the global dword_8AB6EC before reading the average. [callee:0x004B9CE0, global:0x008AB6EC, source:raw]
    // ASSIGNMENT: v2 = a1: truncate the double argument a1 to float and store it in the local v2. [source:raw]
    // CALL: VehicleLifetimeAverageAccessor(&dword_8AB6EC): read the vehicle lifetime average value held in the same global dword_8AB6EC. [callee:0x004B9CB0, global:0x008AB6EC, source:raw]
    // CALCULATION: Return v2 - VehicleLifetimeAverageAccessor(&dword_8AB6EC): the float argument minus the accessed lifetime average. [source:raw]
    // RETURN: Return the computed float difference. [source:raw]

    // Conservative worker pseudocode:
    //   double DifferenceFromLifetimeAverage(double a1) {
    //     Delegation(&dword_8AB6EC);
    //     float v2 = (float)a1;
    //     return v2 - VehicleLifetimeAverageAccessor(&dword_8AB6EC);
    //   }
    // UNRESOLVED: Semantics of Delegation and of the shared global dword_8AB6EC are not established by this packet.
    // UNRESOLVED: Whether the deliberate truncation of the double argument to float is intentional precision loss or a decompiler artifact is unknown.
    // UNRESOLVED: Caller context and what quantity the result represents are not established from this packet.
}
