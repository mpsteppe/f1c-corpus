// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00464F50
// Canonical corpus name: DivisionWithCapComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DivisionWithCapComputation_00464f50.c

void UnknownObject::DivisionWithCapComputation()
{
    // Computes an integer division whose dividend comes from the callee ConditionalDelegateBasedOnCounter and whose divisor is clamped to at least 1, then caps the result at a second value read from the same unresolved base. Reads the divisor candidate from byte offset 58380 (0xE40C) of the unresolved base v3, forms divisor = max(1, candidate - 1), computes result = dividend / divisor, reads the cap from byte offset 684 (0x2AC) plus 560 (0x230) times index a2, and returns the smaller of the cap and the quotient. Recorded as a helper called by EntityVisibilityGridManager during visibility-grid updates.
    // CALL: v2 = ConditionalDelegateBasedOnCounter(this): delegate to callee 0x00464EE0 to obtain the dividend. [callee:0x00464EE0, source:raw]
    // ASSIGNMENT: v4 = *(_DWORD *)(v3 + 58380): read the divisor candidate field at byte offset 58380 (0xE40C) from the unresolved base v3. [source:raw]
    // CALCULATION: Clamp the divisor floor: v5 = 1 by default; when v4 > 1, v5 = v4 - 1, so v5 = max(1, v4 - 1). [source:raw]
    // CALCULATION: result = v2 / v5: integer division of the delegate dividend by the clamped divisor. [source:raw]
    // ASSIGNMENT: v7 = *(_DWORD *)(560 * a2 + v3 + 684): read the cap value at byte offset 684 (0x2AC) plus 560 (0x230) times index a2 from the unresolved base v3. [source:raw]
    // GUARD: if (v7 <= result) return v7: the cap wins when it is at most the computed quotient. [source:raw]
    // RETURN: return result: otherwise return the quotient, so the function returns min(v7, v2 / max(1, v4 - 1)). [source:raw]
    // CALL: Call-context: the packet records a single caller, EntityVisibilityGridManager at 0x00465460; this routine is a helper invoked from the visibility-grid update path. [caller:0x00465460, function:0x00464F50]

    // Conservative worker pseudocode:
    //   int sub_464F50(int *this, int a2) {
    //       int dividend = ConditionalDelegateBasedOnCounter(this);
    //       int divisor = *(_DWORD *)(v3 + 58380);   // base v3 unresolved
    //       int d = (divisor > 1) ? divisor - 1 : 1;
    //       int result = dividend / d;
    //       int cap = *(_DWORD *)(560 * a2 + v3 + 684); // base v3 unresolved
    //       return (cap <= result) ? cap : result;
    //   }
    // UNRESOLVED: The base pointer v3 (ecx) is uninitialized in the decompiled view, so the owning object and the meaning of the reads at +58380 and +684 + 560*a2 cannot be established from this packet.
    // UNRESOLVED: The semantic role of a2 (an index scaling the cap field read by 560 bytes) is unknown.
    // UNRESOLVED: The semantic role of the divisor candidate v4 (a counter-derived quantity, given the callee name) is not evidenced here.
    // UNRESOLVED: Owner class is unknown; no ownership evidence is present in the packet.
}
