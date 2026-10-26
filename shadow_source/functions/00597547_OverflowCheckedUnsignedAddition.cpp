// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00597547
// Canonical corpus name: OverflowCheckedUnsignedAddition
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/OverflowCheckedUnsignedAddition_00597547.c

void UnknownObject::OverflowCheckedUnsignedAddition()
{
    // Unsigned overflow-checked addition. Computes v4 = a1 + a2, writes the sum through the caller's output pointer *a3, and returns 1 when a carry is detected (a1 + a2 < a1 or v4 < a2), otherwise 0. Three call sites: bitmap-size arithmetic (00595207), a CRT-style add (00597568), and sub_597AA0.
    // ASSIGNMENT: Initialize result to 0 (no-overflow default) [source:raw]
    // CALCULATION: v4 = a1 + a2 (wrapping unsigned addition) [source:raw]
    // GUARD: Overflow detection: if a1 + a2 < a1 (wrapped below the first operand) or v4 < a2, set result = 1 [source:raw]
    // ASSIGNMENT: *a3 = v4 — write the sum into the caller's output pointer [source:raw]
    // RETURN: return result (0 = no overflow, 1 = overflow) [function:0x00597547, source:raw]
    // CALL: Used by three callers: FAILOverviewSays96BitBitmapButSourceIsArbitraryS (00595207), CRTAdd12 (00597568), and sub_597AA0 — the protected arithmetic is shared allocation/sizing arithmetic [caller:0x00595207, caller:0x00597568, caller:0x00597AA0]

    // Conservative worker pseudocode:
    //   result = 0;
    //   v4 = a1 + a2;
    //   if (a1 + a2 < a1 || v4 < a2) result = 1;
    //   *a3 = v4;
    //   return result;
    // UNRESOLVED: The higher-level arithmetic each caller protects (bitmap allocation sizing vs. CRT buffer addition) differs per call site and is not resolvable from this packet alone
}
