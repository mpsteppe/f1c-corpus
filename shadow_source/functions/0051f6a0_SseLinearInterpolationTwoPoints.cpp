// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F6A0
// Canonical corpus name: SSELinearInterpolationBetweenTwoPoints
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSELinearInterpolationBetweenTwoPoints_0051f6a0.c

void UnknownObject::SseLinearInterpolationTwoPoints()
{
    // SSE two-point linear interpolation helper. Loads the high 2-vector of a2 as the interpolation origin, then computes a1 = a2 + (a3 - a2)*a5 + (a4 - a2)*a6 using packed SSE multiply/add/sub on two-point vectors, where a5 and a6 are unsigned ints broadcast to a scalar via shuffle. Stores the high result back into a1 and returns a1. No fields, globals, guards, callees or callers are evidenced in the packet.
    // CALCULATION: Load high 2-vector of a2 into SSE register as the base value v6. [source:raw]
    // CALCULATION: Compute a2 + (a3 - a2)*a5 + (a4 - a2)*a6 via packed SSE sub/mul/add, broadcasting a5 and a6 as scalar weights. [source:raw]
    // RETURN: Store high 2-vector of the computed result into a1 and return a1. [function:0x0051F6A0, source:raw]

    // Conservative worker pseudocode:
    //   v6 = loadh(a2);
    //   result = v6 + (loadh(a3) - v6) * broadcast((float)a5) + (loadh(a4) - v6) * broadcast((float)a6);
    //   storeh(a1, result);
    //   return a1;
    // UNRESOLVED: a5/a6 are passed as unsigned ints and reinterpreted as floats via shuffle; the intended scalar type (uint-as-float vs raw bit pattern) is not determinable from raw source.
    // UNRESOLVED: Only the high half of each double is used (loadh/storeh), so the low halves of a1/a2/a3/a4 are unmodified and their meaning is unclear.
    // UNRESOLVED: No caller or callee evidence to confirm the two-point vectors encode e.g. positions or velocity.
}
