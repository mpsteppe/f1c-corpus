// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C40B0
// Canonical corpus name: ConditionalDispatch_40b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalDispatch_40b0_004c40b0.c

void UnknownObject::ConditionalDispatch_40b0()
{
    // Name-guarded vehicle dispatch. Defaults the result to 0; when the name argument a1 is non-null it performs a vehicle lookup by name via VehicleLookupByName (return value discarded) and then returns the current vehicle accessor. On null input returns the default 0.
    // ASSIGNMENT: Initialize result to 0 as the default return value before the guard. [source:raw]
    // GUARD: Guard on a1: the lookup/accessor path only runs when the name argument a1 is non-null. [function:0x004C40B0, source:raw]
    // CALL: VehicleLookupByName(a1): resolve the vehicle referenced by a1; the returned value is discarded. [callee:0x004C3F80, source:raw]
    // RETURN: CurrentVehicleAccessor(): return the current vehicle accessor result as the function value. Callers span vehicle-config lookup/insertion (LookUpVehicleConfigEntry, AddVehicleConfigEntryToLinkedList), netcomm session dispatch, particle spawn, season scene lookup and three unnamed paths. [callee:0x004C4080, caller:0x004339E0, caller:0x00433B60, caller:0x0045D890, caller:0x004607A0, caller:0x00476EC0, caller:0x0049CD80, caller:0x004A0490, caller:0x004F70C0, function:0x004C40B0, source:raw]
    // RETURN: Null path: when a1 is null, return the default result (0). [source:raw]

    // Conservative worker pseudocode:
    //   int ConditionalDispatch_40b0(int a1) {
    //     int result = 0;
    //     if (a1) {
    //       VehicleLookupByName(a1);
    //       return CurrentVehicleAccessor();
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The return value of VehicleLookupByName is discarded; the side effect of selecting the current vehicle is inferred from the accessor call that follows.
    // UNRESOLVED: The type of the a1 name argument (string pointer vs id) is not specified in the raw source.
    // UNRESOLVED: The LEGACY ABI lead provides no owner identity or additional semantic signal.
}
