// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415090
// Canonical corpus name: ShortComputation_5090
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5090_00415090.c

void UnknownObject::BuildAllListData()
{
    // Sequential list-construction chain: calls VehicleListBuilderFromGlobalArray (0x00415780), then NameListBuilderFromVehicleArray (0x004159B0) with this, then SceneListBuilderFromGlobalArray (0x00415C40) with this. Returns 1 as soon as any builder returns nonzero; returns 0 only when all three return zero. Called from LazyRendererAudioInitCheck (0x004184F0) as part of lazy init.
    // CALL: Call VehicleListBuilderFromGlobalArray (0x00415780) with no argument. [callee:0x00415780, source:raw]
    // GUARD: If the vehicle list build returned nonzero, return 1 immediately. [callee:0x00415780, source:raw]
    // CALL: Call NameListBuilderFromVehicleArray (0x004159B0) passing this. [callee:0x004159B0, source:raw]
    // GUARD: If the name list build returned nonzero, return 1 immediately. [callee:0x004159B0, source:raw]
    // CALL: Call SceneListBuilderFromGlobalArray (0x00415C40) passing this and store the result. [callee:0x00415C40, source:raw]
    // GUARD: If the scene list build returned nonzero, return 1. [callee:0x00415C40, source:raw]
    // RETURN: Return the scene builder result (zero) as the overall fallthrough value. [source:raw, function:0x00415090]
    // CALL: Invoked by caller LazyRendererAudioInitCheck (0x004184F0). [caller:0x004184F0]

    // Conservative worker pseudocode:
    //   if (VehicleListBuilderFromGlobalArray()) return 1;
    //   if (NameListBuilderFromVehicleArray(this)) return 1;
    //   int result = SceneListBuilderFromGlobalArray(this);
    //   if (result) return 1;
    //   return result;
    // UNRESOLVED: The list data each builder constructs and the object meaning of this are not established by this packet; this is passed only to the name and scene builders.
    // UNRESOLVED: Why the caller LazyRendererAudioInitCheck runs these builders as part of init is outside this packet's scope.
}
