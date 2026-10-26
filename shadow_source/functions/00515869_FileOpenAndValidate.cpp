// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00515869
// Canonical corpus name: FileOpenAndValidate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileOpenAndValidate_00515869.c

void UnknownObject::FileOpenAndValidate()
{
    // Sequential open/parse plus clamp-with-validation: first calls sub_51512C(a1, a2) and only if it returns a non-negative status calls BatchClampToMax(a1); if that also returns non-negative the function returns 0 (success), otherwise it propagates the failing status code. a1 is a float buffer, a2 an unsigned short parameter whose role is not established.
    // CALL: Call sub_51512C(a1, a2) with the float buffer and unsigned short argument; store the returned status in result [callee:0x0051512C, source:raw, function:0x00515869]
    // GUARD: Only proceed when result is >= 0 (sub_51512C succeeded) [source:raw, function:0x00515869]
    // CALL: Call BatchClampToMax(a1) to clamp the float buffer; store the returned status in result [callee:0x00513DAF, source:raw, function:0x00515869]
    // GUARD: When BatchClampToMax also returned >= 0, return success constant 0 [source:raw, function:0x00515869]
    // RETURN: Return 0 when both calls succeeded [source:raw, abi:lead, function:0x00515869]
    // RETURN: Return the failing status code (from sub_51512C or BatchClampToMax) when either call returned negative [source:raw, function:0x00515869]

    // Conservative worker pseudocode:
    //   int FileOpenAndValidate(float *a1, unsigned __int16 *a2) {
    //     int result = sub_51512C(a1, a2);
    //     if (result >= 0) {
    //       result = BatchClampToMax(a1);
    //       if (result >= 0)
    //         return 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of sub_51512C (candidate: file/stream open and parse into the float buffer) are outside this packet
    // UNRESOLVED: Semantics of BatchClampToMax (clamping a batch of floats to a maximum) and what maximum it applies are outside this packet
    // UNRESOLVED: Role of the unsigned short pointer a2 and the object owner are unknown; packet has no owner evidence
}
