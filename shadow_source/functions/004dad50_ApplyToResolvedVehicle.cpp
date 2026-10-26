// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DAD50
// Canonical corpus name: ArithmeticComparison_ad50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_ad50_004dad50.c

void UnknownObject::ApplyToResolvedVehicle()
{
    // Resolves an index v2 by calling sub_4D1B50(dword_8ACEE0, 0), then applies this object to the array element at (int)&unk_5EC6D8 + 18624 * v2 by calling SingleFunctionCallWrapper_ad30(this, element). The 18624-byte element stride identifies the per-slot vehicle array; the wrapper writes this object's payload into the resolved element.
    // CALL: Call sub_4D1B50(dword_8ACEE0, 0) to resolve an index v2 from the global dword_8ACEE0. [callee:0x004D1B50, global:0x008ACEE0, source:raw]
    // CALCULATION: Compute the target element address as (int)&unk_5EC6D8 + 18624 * v2, indexing the array at unk_5EC6D8 with a 18624-byte element stride. [global:0x005EC6D8, source:raw]
    // CALL: Call SingleFunctionCallWrapper_ad30(this, element) with the resolved element address; the function is invoked by sub_4DA9E0 (004DA9E0). [callee:0x004DAD30, caller:0x004DA9E0, source:raw]

    // Conservative worker pseudocode:
    //   void ApplyToResolvedVehicle(int* this) {
    //     int v2 = sub_4D1B50((unsigned __int8*)dword_8ACEE0, 0);
    //     SingleFunctionCallWrapper_ad30(this, (int)&unk_5EC6D8 + 18624 * v2);
    //   }
    // UNRESOLVED: sub_4D1B50's contract (what dword_8ACEE0 holds and what the returned v2 selects) is not visible in this packet; the skeleton fill names the global ForceFeedbackBase but that role is not evidenced here.
    // UNRESOLVED: SingleFunctionCallWrapper_ad30's action on the resolved element (the fill claims a lap value written into the vehicle) is not visible in this packet.
}
