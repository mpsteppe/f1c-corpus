// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005261CE
// Canonical corpus name: F_3DNow44MatrixMultiplyWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DNow44MatrixMultiplyWrapper_005261ce.c

void UnknownObject::MmxFlushedMatrixMultiply()
{
    // Stdcall 3DNow!-oriented wrapper that flushes MMX state (_m_femms), runs the core routine sub_525E9A(a1, a2, a3), flushes MMX state again, and returns the destination pointer a1.
    // CALL: Emits _m_femms() before the computation to clear 3DNow!/MMX state. [source:raw]
    // CALL: Calls sub_525E9A(a1, a2, a3), the core computation routine operating on the three operands. [callee:0x00525E9A, source:raw]
    // CALL: Emits _m_femms() after the computation to clear MMX state before returning to non-MMX code. [source:raw]
    // RETURN: Returns the destination pointer a1. [source:raw, function:0x005261CE]

    // Conservative worker pseudocode:
    //   _m_femms();
    //   sub_525E9A(a1, a2, a3);
    //   _m_femms();
    //   return a1;
    // UNRESOLVED: Semantics of sub_525E9A (0x00525E9A) and whether it performs a 4x4 matrix multiply are outside this packet.
    // UNRESOLVED: The _DWORD * type of a2 and the intended element counts of the __m64 operands are unknown.
}
