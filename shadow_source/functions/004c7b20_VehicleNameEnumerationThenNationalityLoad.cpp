// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C7B20
// Canonical corpus name: TwoCallDelegation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TwoCallDelegation_004c7b20.c

void UnknownObject::VehicleNameEnumerationThenNationalityLoad()
{
    // Two-step delegation helper (thiscall): enumerates vehicle names from the supplied config path, then loads nationality/career driver information for the current object using the enumerated vehicle index global dword_8AC38C. Both calls always execute; no guard path exists. Used by network, vehicle-load and driver-entry setup paths.
    // CALL: Call VehicleNameEnumeration(a2) to enumerate vehicle names from the config path argument a2. [callee:0x004C3FE0, source:raw]
    // CALL: Call NationalityDriverInfoLoader(this, dword_8AC38C) passing the this object and the enumerated-vehicle index global dword_8AC38C to load nationality/career driver information. [callee:0x004C78F0, global:0x008AC38C, source:raw]
    // RETURN: Return the result of NationalityDriverInfoLoader to the caller. [source:raw]
    // CALL: Invoked by NetCommPlayerSlotSync (0045FC50), LoadVehicleEntries (004B70B0) and ProcessDriverEntries (004B8DA0) to enumerate vehicles and load driver data during session/entry setup. [caller:0x0045FC50, caller:0x004B70B0, caller:0x004B8DA0, source:raw]

    // Conservative worker pseudocode:
    //   VehicleNameEnumeration(a2);
    //   return NationalityDriverInfoLoader((int)this, dword_8AC38C);
    // UNRESOLVED: dword_8AC38C is read here as the enumerated vehicle index; its producer is not visible in this function.
    // UNRESOLVED: unk_8AC388 is flagged by packet facts as read but appears nowhere in the raw source text; its role is not verifiable here.
    // UNRESOLVED: The type of a2 (config path) and the exact nationality-loading behavior of NationalityDriverInfoLoader are not documented in this function.
}
