// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005001D0
// Canonical corpus name: FieldCompareConstant
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FieldCompareConstant_005001d0.c

void UnknownObject::FieldCompareConstant()
{
    // Returns TRUE when the float field this[111] (offset 0x1BC) is not equal to the large negative sentinel -9.9999997e37 held in the global flt_5AD348 (0x005AD348), i.e. when the field has been initialized/written. Returns FALSE while the field still holds the uninitialized sentinel. A shared field-status check invoked by eight callers on a per-frame path.
    // GUARD: Compare this[111] (float field at offset 0x1BC) against the sentinel; the field counts as set only when it differs. [field:this:0x000001BC, source:raw]
    // ASSIGNMENT: Read the sentinel value -9.9999997e37 from the global float flt_5AD348 (0x005AD348) for the comparison. [global:0x005AD348, source:raw]
    // RETURN: Return the comparison result as a BOOL: TRUE when the field is set, FALSE when it still holds the sentinel. [source:raw]
    // CALL: Invoked as a field-initialized check by FloatComparisonListIteration (0x004B5380), ListWalkWithUserCancelCheck (0x004B5460), CollisionFilterAABBCull (0x004B5630), LinkedListIteratorWithStateUpdate (0x004B5760), sub_4B9000 (0x004B9000), sub_4B9AC0 (0x004B9AC0), AudioSampleCrossFadeInterpolation (0x004FF8F0) and CollisionTestWithThreshold (0x00500560). [caller:0x004B5380, caller:0x004B5460, caller:0x004B5630, caller:0x004B5760, caller:0x004B9000, caller:0x004B9AC0, caller:0x004FF8F0, caller:0x00500560, source:raw]

    // Conservative worker pseudocode:
    //   BOOL FieldCompareConstant(float *this) {
    //     return this[111] != flt_5AD348;  // sentinel -9.9999997e37
    //   }
    // UNRESOLVED: Purpose of field this[111] (offset 0x1BC) is caller-specific; the check only reports whether it differs from the shared sentinel.
}
