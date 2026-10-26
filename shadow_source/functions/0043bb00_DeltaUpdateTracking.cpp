// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0043BB00
// Canonical corpus name: DeltaUpdateTracking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DeltaUpdateTracking_0043bb00.c

void UnknownObject::DeltaUpdateTracking()
{
    // Per-frame delta accumulator with smoothing. Computes the change between the incoming value a2 and the previously stored value at this+0x1428, stores a2 as the new previous value, scales the delta by the smoothing factor at this+0x1430, and adds the result into the accumulator at this+0xD4C. Returns void; the updated state is left in the this object.
    // CALCULATION: Compute the frame delta v2 = a2 - this[645] (previous value at this+0x1428). [field:this:0x00001428, source:raw]
    // ASSIGNMENT: Store the incoming value as the new previous value: this[645] = a2. [field:this:0x00001428, source:raw]
    // CALCULATION: Accumulate the smoothed delta: this+0xD4C += delta * this[646] (smoothing factor at this+0x1430). [field:this:0x00000D4C, field:this:0x00001430, source:raw]
    // RETURN: Void return; result is left in the accumulator field at this+0xD4C. [source:raw]
    // CALL: Invoked on the frame path by VehiclePhysicsInitializer (0x00439210) and SolverDispatch (0x0043B930). [caller:0x00439210, caller:0x0043B930, source:raw]

    // Conservative worker pseudocode:
    //   void sub_43BB00(double *this, double value) {
    //     double delta = value - this[645];
    //     this[645] = value;
    //     *(double *)((char *)this + 3404) = delta * this[646] + *(double *)((char *)this + 3404);
    //   }
    // UNRESOLVED: Identity and class of the owning object (physics solver context) is unknown.
    // UNRESOLVED: Semantic meaning of the smoothing factor at this+0x1430 and the accumulated output at this+0xD4C depends on the owner's domain use.
}
