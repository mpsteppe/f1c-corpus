// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415730
// Canonical corpus name: ShortComputation_5730
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5730_00415730.c

void UnknownObject::DriverLookupAndFlagSetter()
{
    // Resets the active flags of a format list, resolves the current vehicle from the global vehicle-file buffer, then finds or creates a format-list entry whose key is the current vehicle's driver name (string at vehicle+188) and marks the matching list node's active flag byte (node+12) as 1. Returns the fetched list node, or null when there is no current vehicle. The a2 argument is used both as the vehicle lookup name and as the secondary key for the format-list search.
    // CALL: sub_415700(this) resets the active flags in the format list before re-marking. [callee:0x00415700]
    // CALL: VehicleLookupByName(a2) looks up a vehicle record by the name string a2. [callee:0x004C3F80]
    // CALL: CurrentVehicleAccessor(&unk_8AC388) fetches the current vehicle record from the global vehicle-file buffer. [callee:0x004C4080, global:0x008AC388]
    // GUARD: Guard on the current vehicle result: when it is null there is no active vehicle and the whole body is skipped, returning null. [source:raw]
    // CALL: NamedEntryLookupInFormatList(this, vehicle+188, a2) finds or creates the format-list entry keyed by the current vehicle's driver name (char string at vehicle+188) with secondary key a2. [callee:0x00415230]
    // CALL: LinkedListIndexedAccessor(this, v4) fetches the list node at the index returned by the lookup. [callee:0x00415650]
    // ASSIGNMENT: If the node is non-null, set its active-flag byte at node+12 to 1. [source:raw]
    // RETURN: Return the fetched list node (or null when the lookup/index step produced no node). [source:raw]

    // Conservative worker pseudocode:
    //   int DriverLookupAndFlagSetter(void **this, int name) {
    //     sub_415700(this);
    //     VehicleLookupByName(name);
    //     int *veh = CurrentVehicleAccessor(&unk_8AC388);
    //     if (!veh) return 0;
    //     int idx = NamedEntryLookupInFormatList(this, (const char*)((char*)veh + 188), name);
    //     int node = LinkedListIndexedAccessor(this, idx);
    //     if (node) *(char*)(node + 12) = 1;
    //     return node;
    //   }
    // UNRESOLVED: Offset 188 (driver-name string inside the vehicle record) is used only as an offset from the current vehicle pointer; the owning vehicle type is not stated in this packet.
    // UNRESOLVED: The exact list layout this[0..3] (head/tail/first-node/count) is shared with NamedEntryLookupInFormatList (00415230) but not re-derived here.
    // UNRESOLVED: Why the active flag is only set and never cleared in this function is external context; sub_415700 is assumed to perform the clearing.
}
