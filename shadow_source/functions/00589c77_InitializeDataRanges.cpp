// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589C77
// Canonical corpus name: sub_589C77
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589C77_00589c77.c

void UnknownObject::InitializeDataRanges()
{
    // Module-level initializer called by sub_58A19E. Calls the function pointer at off_5E63A4 if it is non-null (optional callback), then calls UtilityFunction_9d7d twice over two adjacent data ranges (unk_5BE3C0..unk_5BE3D8 and unk_5BE000..unk_5BE3BC) and returns the result of the second range call. The two ranges sit in the same global block, consistent with initializing/registering static module data.
    // GUARD: Guard: read off_5E63A4; if non-null, call the callback function pointer before the range initializations. [global:0x005E63A4, source:raw]
    // CALL: Call UtilityFunction_9d7d(&unk_5BE3C0, &unk_5BE3D8) to initialize the first (short) data range. [callee:0x00589D7D, global:0x005BE3C0, global:0x005BE3D8, source:raw]
    // CALL: Call UtilityFunction_9d7d(&unk_5BE000, &unk_5BE3BC) to initialize the second (long) data range; its return value is the function result. [callee:0x00589D7D, global:0x005BE000, global:0x005BE3BC, source:raw]
    // RETURN: Return the result of the second UtilityFunction_9d7d call. [callee:0x00589D7D, global:0x005BE000, global:0x005BE3BC, source:raw]

    // Conservative worker pseudocode:
    //   int sub_589C77() {
    //     if (off_5E63A4)
    //       off_5E63A4();
    //     UtilityFunction_9d7d(&unk_5BE3C0, &unk_5BE3D8);
    //     return UtilityFunction_9d7d(&unk_5BE000, &unk_5BE3BC);
    //   }
    // UNRESOLVED: Callee 0x00587B7F appears in the packet callee list but is not called by the raw source; no call site is visible in this function.
    // UNRESOLVED: Exact semantics of UtilityFunction_9d7d over these ranges (CRT/locale/static init) are not proven by this packet alone.
    // UNRESOLVED: Role of the off_5E63A4 callback and its callee identity are unknown.
    // UNRESOLVED: Owner type unknown; UNKNOWN and unproposed.
}
