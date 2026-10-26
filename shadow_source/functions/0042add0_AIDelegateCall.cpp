// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042ADD0
// Canonical corpus name: AIDelegateCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIDelegateCall_0042add0.c

void UnknownObject::AIDelegateCall()
{
    // Thin spatial-query delegate: reads a vehicle-like object's position and two search parameters, then forwards them to SpatialTreeNearestNeighborSearch on the scene's spatial tree with filter value 0, returning the resulting nearest-neighbor handle (or zero when none found).
    // CALCULATION: Resolve the position vector pointer at this + 13536 to use as the query position. [source:raw]
    // CALL: Call SpatialTreeNearestNeighborSearch with the spatial tree from dword_5EA2C0, the position pointer at this + 13536, the search parameter at this + 17236 (0x4354), the search parameter at this + 17744 (0x4550), and filter value 0. [callee:0x00403AA0, global:0x005EA2C0, field:this:0x00004354, field:this:0x00004550, source:raw]
    // RETURN: Return the nearest-neighbor search result: a handle to the nearest entity, or zero when none is found. [source:raw]
    // CALL: Invoked by sub_4A4110 and FindNearestVehicle to perform nearest-neighbor queries on behalf of AI callers. [caller:0x004A4110, caller:0x004A4710, source:raw]

    // Conservative worker pseudocode:
    //   int sub_42ADD0(int this) {
    //     return SpatialTreeNearestNeighborSearch(dword_5EA2C0,
    //         (float *)(this + 13536), *(_DWORD *)(this + 17236),
    //         *(_DWORD *)(this + 17744), 0);
    //   }
    // UNRESOLVED: Exact semantics of the search parameters at this + 17236 and this + 17744 (radius/count versus limit/filter) are not established by this function alone.
    // UNRESOLVED: The type of the object owning the position and search-parameter fields is unknown (UnknownObject).
}
