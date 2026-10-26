// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005910A1
// Canonical corpus name: DoubleArithmeticWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoubleArithmeticWrapper_005910a1.c

void UnknownObject::CallExtendedPrecisionDivisionFixup()
{
    // Trivial double-forwarding wrapper with no recorded callers: stores its two x87-register double arguments into local extended-precision (TBYTE) scratch buffers and calls ExtendedPrecisionDivisionWithOverflowFixup (0x005908B0) with pointers to those buffers. Void return, no guards, no globals.
    // ASSIGNMENT: Store the first double argument a1 (x87 st1) into the local TBYTE scratch buffer v3 [source:raw, function:0x005910A1]
    // ASSIGNMENT: Store the second double argument a2 (x87 st0) into the local TBYTE scratch buffer v2 [source:raw, function:0x005910A1]
    // CALL: Call ExtendedPrecisionDivisionWithOverflowFixup (0x005908B0) with pointers to the two filled scratch buffers (v2, then v3) [callee:0x005908B0, source:raw]
    // RETURN: Return implicitly after the helper call; the wrapper itself produces no value [function:0x005910A1, source:raw]

    // Conservative worker pseudocode:
    //   void CallExtendedPrecisionDivisionFixup(double a1, double a2)
    //   {
    //       TBYTE bufB, bufA;
    //       *(double*)&bufB = a1;
    //       *(double*)&bufA = a2;
    //       ExtendedPrecisionDivisionWithOverflowFixup(&bufA, &bufB);
    //   }
    // UNRESOLVED: The two doubles are materialized into 10-byte extended-precision scratch buffers before the call, but the exact role of each argument (numerator versus denominator) inside the division-with-overflow-fixup routine is not evidenced
    // UNRESOLVED: The callee's side effects and where any result lands are unknown; the packet records no callers for this function
}
