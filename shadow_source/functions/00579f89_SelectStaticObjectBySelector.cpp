// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00579F89
// Canonical corpus name: sub_579F89
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_579F89_00579f89.c

void UnknownObject::SelectStaticObjectBySelector()
{
    // Small selector lookup: given an integer selector passed in the this register, returns one of two static object addresses, or a null pointer for any other value. Selector 0 maps to the object at 0x008D3984, selector 1 maps to the object at 0x008D3980, and any other value returns 0. Called by VehiclePhysicsJointSystemLoader, suggesting it selects a per-type static configuration object during vehicle joint-system loading.
    // GUARD: First selector test: when the selector value (this) is 0, the function returns the static object at 0x008D3984. [global:0x008D3984, source:raw]
    // GUARD: Second selector test: when the selector value (this) equals 1, the function returns the static object at 0x008D3980. [global:0x008D3980, source:raw]
    // RETURN: Fallback return of 0 (null pointer) for any selector value other than 0 or 1. [source:raw]
    // CALL: Invoked by VehiclePhysicsJointSystemLoader as the static object selector while building the vehicle physics joint system. [caller:0x0056D930, source:raw]

    // Conservative worker pseudocode:
    //   void* SelectStaticObjectBySelector(int selector) {
    //     if (selector == 0) return &unk_8D3984;
    //     if (selector == 1) return &unk_8D3980;
    //     return 0;
    //   }
    // UNRESOLVED: The types and contents of the two static objects at 0x008D3980 and 0x008D3984 are not described by this packet.
    // UNRESOLVED: Whether the selector is a joint-type enum or a configuration index depends on the caller's contract in VehiclePhysicsJointSystemLoader.
}
