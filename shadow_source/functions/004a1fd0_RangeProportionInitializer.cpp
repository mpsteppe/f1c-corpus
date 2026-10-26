// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A1FD0
// Canonical corpus name: RangeProportionInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RangeProportionInitializer_004a1fd0.c

void UnknownObject::RangeProportionInitializer()
{
    // Initializes a float min/max range pair and precomputes the inverse range used for linear proportion lookups. Stores argument a2 as the range minimum (field 0x0) and a3 as the range maximum (field 0x4), then stores 1/(a3 - a2) in field 0x8 when the range is positive, otherwise 0.0, guarding against division by zero for empty or inverted ranges. On the frame path per the packet.
    // CALCULATION: Compute the range width v3 = a3 - a2 as a double before any field writes. [source:raw]
    // ASSIGNMENT: Store the range minimum: *this = a2, i.e. field 0x0 receives argument a2. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the range maximum: this[1] = a3, i.e. field 0x4 receives argument a3. [field:this:0x00000004, source:raw]
    // GUARD: Guard on the computed range width: if v3 (a3 - a2) is <= 0.0 the range is empty or inverted. [source:raw]
    // ASSIGNMENT: When the range is not positive, field 0x8 is set to 0.0 (no valid proportion scale). [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Otherwise field 0x8 is set to 1.0 / v3, the precomputed inverse range (1/(max-min)). [field:this:0x00000008, source:raw]
    // CALL: Called by sub_4A35F0 (0x004A35F0), PhysicsChannelProcessingWithLocals (0x004A3820), PitCrewAnimationMASSetup (0x004A3910) and sub_4D0110 (0x004D0110) to set up a min/max/inverse-range triple before per-frame proportion lookups. [caller:0x004A35F0, caller:0x004A3820, caller:0x004A3910, caller:0x004D0110, source:raw]

    // Conservative worker pseudocode:
    //   void RangeProportionInitializer(float *self, float a2, float a3) {
    //     double width = a3 - a2;
    //     self[0] = a2;
    //     self[1] = a3;
    //     self[2] = (width <= 0.0) ? 0.0f : (float)(1.0 / width);
    //   }
    // UNRESOLVED: Packet lists globals flt_59E43C and flt_59E440 as read, but the raw source body references no globals; the references may live in caller/inlined context the raw text does not show, or the packet's global list is stale. Both are parked in unresolved_evidence_refs rather than asserted.
    // UNRESOLVED: Object type owning fields 0x0/0x4/0x8 is unknown; only the float-triple layout is evidenced.
    // UNRESOLVED: Whether the inverse range is consumed as float or double by callers is not evidenced here.
}
