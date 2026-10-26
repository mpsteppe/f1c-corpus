// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051588C
// Canonical corpus name: sub_51588C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51588C_0051588c.c

void UnknownObject::FileOpenAndValidate_51588C()
{
    // Validate-and-clamp wrapper: calls sub_5151AF(a1, a2), and only when it returns a non-negative status calls BatchClampToMax(a1); if that also returns non-negative the function returns 0, otherwise it propagates the failing status code. a1 is a float buffer, a2 an unsigned short parameter whose role is not established. The proposed name is inferred from the identical control-flow skeleton of a sibling function, not from packet evidence.
    // CALL: Call sub_5151AF(a1, a2) with the float buffer and unsigned short argument; store the returned status in result [callee:0x005151AF, source:raw, function:0x0051588C]
    // GUARD: Only proceed when result is >= 0 (sub_5151AF succeeded) [source:raw, function:0x0051588C]
    // CALL: Call BatchClampToMax(a1) to clamp the float buffer; store the returned status in result [callee:0x00513DAF, source:raw, function:0x0051588C]
    // GUARD: When BatchClampToMax also returned >= 0, return success constant 0 [source:raw, function:0x0051588C]
    // RETURN: Return 0 when both calls succeeded [source:raw, function:0x0051588C]
    // RETURN: Return the failing status code (from sub_5151AF or BatchClampToMax) when either call returned negative [source:raw, function:0x0051588C]

    // Conservative worker pseudocode:
    //   int FileOpenAndValidate_51588C(float *a1, unsigned __int16 *a2) {
    //     int result = sub_5151AF(a1, a2);
    //     if (result >= 0) {
    //       result = BatchClampToMax(a1);
    //       if (result >= 0)
    //         return 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Semantics of sub_5151AF (candidate: file/stream open and parse into the float buffer) are outside this packet
    // UNRESOLVED: Semantics of BatchClampToMax and what maximum it applies are outside this packet
    // UNRESOLVED: Proposed name is a structural-inference GUESS from a sibling function's skeleton; no packet evidence names this function
    // UNRESOLVED: Role of the unsigned short pointer a2 and the object owner are unknown; packet has no owner evidence
}
