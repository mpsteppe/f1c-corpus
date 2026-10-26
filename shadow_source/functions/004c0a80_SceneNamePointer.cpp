// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0A80
// Canonical corpus name: SceneNamePointer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneNamePointer_004c0a80.c

void UnknownObject::SceneNamePointer()
{
    // Accessor that resolves the current vehicle's scene name pointer: reads the vehicle name string from this[2], falling back to a default string global if null, looks the vehicle up by name via VehicleLookupByName, then returns the current vehicle's scene name pointer (offset +124) via CurrentVehicleAccessor, or 0 if no vehicle was found.
    // ASSIGNMENT: Read the vehicle name string pointer from this[2] (byte offset 0x8 on the this object). [field:this:0x00000008]
    // GUARD: If the vehicle name is null, substitute the default string global byte_5EA438. [global:0x005EA438]
    // CALL: Resolve the vehicle by name through VehicleLookupByName using the (possibly defaulted) name string. [callee:0x004C3F80]
    // CALL: Query the current vehicle through CurrentVehicleAccessor, passing the vehicle file path buffer global unk_8AC388. [callee:0x004C4080, global:0x008AC388]
    // GUARD: If the current vehicle accessor returns null, the function returns 0. [source:raw]
    // RETURN: Return the scene name string pointer at offset +124 within the current vehicle object, or 0 when the vehicle is absent. [source:raw]

    // Conservative worker pseudocode:
    //   char *SceneNamePointer(_DWORD *this) {
    //     char *name = (char *)this[2];
    //     if (!name) name = byte_5EA438;
    //     VehicleLookupByName(name);
    //     int veh = CurrentVehicleAccessor(&unk_8AC388);
    //     return veh ? (char *)(veh + 124) : 0;
    //   }
    // UNRESOLVED: Ownership of this object is unconfirmed; the packet owner is UnknownObject.
    // UNRESOLVED: The exact meaning of byte_5EA438 (default application directory path per prior analysis) is DERIVED prose, not proven here.
}
