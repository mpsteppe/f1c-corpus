// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404030
// Canonical corpus name: ZeroVectorCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroVectorCheck_00404030.c

void UnknownObject::ZeroVectorCheck()
{
    // Pure boolean test over two vectors (a1 with X and Z tested, a2 with X, Y and Z tested): returns TRUE when any of the five tested float components is non-zero, FALSE only when all five are exactly 0.0. Used to detect a non-zero-initialized compound vector/point pair. Per-frame path, called by sub_4C6F10.
    // RETURN: return (*a1 != 0.0) || (a1[2] != 0.0) || (*a2 != 0.0) || (a2[1] != 0.0) || (a2[2] != 0.0) — TRUE if any tested component is non-zero [field:this:0x00000000, field:this:0x00000008, function:0x00404030, source:raw]
    // GUARD: Short-circuit OR chain: returns FALSE only when all five checked components are exactly 0.0 [source:raw]
    // CALL: Consumed by sub_4C6F10 (004C6F10) to test whether the vector pair holds a non-zero value [caller:0x004C6F10]

    // Conservative worker pseudocode:
    //   return (a1[0] != 0.0f) || (a1[2] != 0.0f) || (a2[0] != 0.0f) || (a2[1] != 0.0f) || (a2[2] != 0.0f);
    // UNRESOLVED: Global flt_59E440 (ZeroThreshold) is listed as referenced but the raw source compares against the literal 0.0; its exact role is not resolvable from this packet
    // UNRESOLVED: The meaning of the tested component layout (a1 skipping Y at +0x4) depends on the caller's data structure, which this packet does not establish
    // UNRESOLVED: Owner class unknown; likely a geometry/math helper but no evidence in this packet
}
