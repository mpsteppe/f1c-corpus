// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044F7F0
// Canonical corpus name: CollisionResponseCompute
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionResponseCompute_0044f7f0.c

void UnknownObject::CollisionResponseCompute()
{
    // Query a device object stored at this+0x80 through its vtable method at +0x14 with a command block, then compute collision-response mapping values: range endpoints, inverse-range scaling, and an interpolated position written to the a3..a8 outputs. All computation is skipped when the device pointer is null or the query fails.
    // GUARD: If the device pointer stored at this+0x80 is null, skip all response computation and return. [field:this:0x00000080, source:raw]
    // ASSIGNMENT: Build a request block on the stack: v15[0]=24, v15[1]=16, v15[2]=a2, v15[3]=1. [source:raw]
    // CALL: Invoke the device vtable method at +0x14 (5th method) with (v10, 4, v15); continue only when it returns zero. [field:*(this+0x80):0x00000014, source:raw]
    // CALCULATION: Read the two range endpoints from the returned block: v11 from v15[4] and v12 from v15[5]. [source:raw]
    // ASSIGNMENT: Store the lower endpoint into *a7 and the inverse of (v12 - v11) into *a6, or 0.0 when the endpoints are equal. [source:raw]
    // CALCULATION: Compute the interpolated position *a3 = a10 * (v12 - v11) + v11. [source:raw]
    // CALCULATION: Compute the half-span *a8 = (v12 - v11) * a9 * 0.5. [source:raw]
    // ASSIGNMENT: Compute inverse-range factors *a4 and *a5 from the mid-span positions (v13 + v11 and v12 - *a8), defaulting each to 0.0 when the denominator would be zero. [source:raw]

    // Conservative worker pseudocode:
    //   v10 = this[0x80];
    //   if (v10) {
    //       v15[0] = 24; v15[1] = 16; v15[2] = a2; v15[3] = 1;
    //       if ((*vtable(v10, 0x14))(v10, 4, v15) == 0) {
    //           v11 = v15[4]; v12 = v15[5];
    //           *a7 = v11;
    //           *a6 = (v11 != v12) ? 1.0f / (v12 - v11) : 0.0f;
    //           *a3 = a10 * (v12 - v11) + v11;
    //           *a8 = (v12 - v11) * a9 * 0.5f;
    //           mid1 = *a8 + v11; mid2 = v12 - *a8;
    //           *a4 = (*a3 != mid1) ? 1.0f / (*a3 - mid1) : 0.0f;
    //           *a5 = (mid2 != *a3) ? 1.0f / (mid2 - *a3) : 0.0f;
    //       }
    //   }
    // UNRESOLVED: Globals flt_59E43C and flt_59E450 are listed in the packet but do not appear in the raw source body; their role in this function is unresolved.
    // UNRESOLVED: The command id 4 and request block layout (24 and 16 byte fields) are opaque without the device object's interface contract.
    // UNRESOLVED: Semantic meaning of a9 and a10 (scaling factors) is not independently confirmed.
}
