// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8140
// Canonical corpus name: VehicleListCountGetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleListCountGetter_004b8140.c

void UnknownObject::VehicleListCountGetter()
{
    // Trivial getter: returns the dword at this[435], i.e. field this+0x6CC. No side effects, no guards, no callees. The vehicle list count interpretation comes from the legacy ABI name and the getter prelabel; the raw source only reads the field.
    // RETURN: Returns the value of field this+0x6CC (this[435]) [field:this:0x000006CC, source:raw]

    // Conservative worker pseudocode:
    //   int VehicleListCountGetter(this) {
    //     return this[435];
    //   }
    // UNRESOLVED: The meaning of the field at this+0x6CC as a vehicle-list count rests on the ABI name and getter prelabel (DERIVED), not on the raw source in this packet
    // UNRESOLVED: No callers are recorded, so the consumer of this count is not evidenced
    // UNRESOLVED: The receiver object type and the element type the count indexes are unknown
}
