// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498720
// Canonical corpus name: CollisionSpeedSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionSpeedSetter_00498720.c

void UnknownObject::CollisionSpeedSetter()
{
    // Unconditional collision/physics parameter setter. Stores the global double dbl_8AFE90 into the float field at this+0xC0 (this[48]) on every call. No guards, no callees; the legacy ABI lead names it a collision speed setter and it is reached from UILargeRender (0x00496930).
    // ASSIGNMENT: Write the global double dbl_8AFE90 (0x008AFE90) into float field this[48] (offset 0xC0), the collision/physics parameter, unconditionally. [field:this:0x000000C0, global:0x008AFE90, source:raw]
    // RETURN: Return void; the setter performs no reads of this beyond the write and no branching. [function:0x00498720, source:raw]
    // CALL: Invoked from UILargeRender (0x00496930) as the sole caller. [caller:0x00496930]

    // Conservative worker pseudocode:
    //   void CollisionSpeedSetter(float *this) {
    //     this[48] = (float)dbl_8AFE90;  // offset 0xC0
    //   }
    // UNRESOLVED: The semantics of offset 0xC0 (speed, damping, or cooling-rate constant per existing analysis) are unconfirmed; the field name is a DERIVED label.
    // UNRESOLVED: Owner object identity is not established by the packet; owner retained as UnknownObject.
    // UNRESOLVED: The global dbl_8AFE90 is a double assigned into a float field; truncation semantics are per the raw source, not asserted further.
}
