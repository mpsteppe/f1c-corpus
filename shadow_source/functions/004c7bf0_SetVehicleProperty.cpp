// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7BF0
// Canonical corpus name: PropertySetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PropertySetter_004c7bf0.c

void UnknownObject::SetVehicleProperty()
{
    // thiscall property setter. Stores argument a2 into this[4651] (dword at offset 0x48AC) and returns the value that was written. No guard - always writes. Existing analysis names it VehiclePropertySetter and reports the field is recalculated every frame (external poke does not persist). Called from sub_4B3400 and VehiclePhysicsTimeStep.
    // ASSIGNMENT: Store a2 into this[4651] (field at offset 0x48AC). [field:this:0x000048AC, source:raw]
    // RETURN: Return a2 (the stored value) as the function result. [function:0x004C7BF0, source:raw]

    // Conservative worker pseudocode:
    //   this[4651] = a2;
    //   return a2;
    // UNRESOLVED: Semantic identity of field 0x48AC beyond the DERIVED 'vehicle property/state field' from existing analysis.
    // UNRESOLVED: Existing analysis notes field 0x48AC is recalculated every frame, so an external poke does not persist; the recalc writer is not evidenced by this packet.
    // UNRESOLVED: Owner class unknown.
}
