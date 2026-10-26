// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DAD30
// Canonical corpus name: SingleFunctionCallWrapper_ad30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SingleFunctionCallWrapper_ad30_004dad30.c

void UnknownObject::writeLapCountToVehicle()
{
    // Single-call wrapper: reads the value at this[9] (offset 0x24) and passes it to sub_4BC270 along with a destination pointer formed by a2 + 16436 (byte offset 0x4034). The destination is a caller-supplied structure; existing analysis interprets this as writing a lap/threshold counter into a vehicle struct.
    // ASSIGNMENT: Read the value stored at this[9] (byte offset 0x24). [field:this:0x00000024, source:raw]
    // CALL: Call sub_4BC270 with destination (a2 + 16436) and the value read from this[9]: stores that value into the caller-supplied structure at byte offset 0x4034. [callee:0x004BC270, source:raw]

    // Conservative worker pseudocode:
    //   sub_4BC270((void*)(a2 + 0x4034), this[9]);
    // UNRESOLVED: The destination structure at a2 + 16436 (0x4034) is caller-supplied; whether it is a vehicle struct is not independently confirmed.
    // UNRESOLVED: sub_4BC270's contract (stores an integer into a struct field at a given offset) is inferred from usage and the existing analysis, not from a recorded prototype.
    // UNRESOLVED: Purpose of this[9] as a lap/threshold counter is DERIVED from existing analysis, not confirmed by independent evidence.
}
