// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059086E
// Canonical corpus name: CRTFload
// Owner: CRT [DERIVED]
// Raw source: functions/CRTFload_0059086e.c

void CRT::CRTFloatLoad()
{
    // CRT double loader (__cdecl; ABI lead CRT___fload, LEGACY trust): returns the input double a1 unchanged unless its 11-bit exponent field is all-ones ((HIWORD(a1) & 0x7FF0) == 0x7FF0, the NaN/Inf exponent pattern). In that special case it recomposes a double v2 from the low 32 bits of a1 plus the top 11 bits (sign + exponent, bits 53..63) shifted down into bits 32..42, discarding the high mantissa bits. Used on the CRT float-display path.
    // GUARD: If (HIWORD(a1) & 0x7FF0) != 0x7FF0, i.e. the 11-bit exponent field is not all-ones, take the fast path and return the input double a1 unchanged. [source:raw]
    // RETURN: Fast path: return a1 unchanged for any value whose exponent field is not the all-ones special pattern. [source:raw]
    // CALCULATION: Special path: build v2 with LODWORD(v2) = LODWORD(a1) (low 32 bits) and HIDWORD(v2) = high dword of (*(_QWORD *)&a1 >> 21), which keeps a1 bits 53..63 (sign + exponent) at bit positions 32..42 and zeroes the high mantissa bits. [source:raw]
    // RETURN: Special path: return the recomposed double v2. [source:raw]
    // CALL: Invoked by sub_5906BB (0x005906BB) and Ctrandisp1CRTFloatDisplayFormat (0x0059083B) on the CRT float-display path. [caller:0x005906BB, caller:0x0059083B]

    // Conservative worker pseudocode:
    //   double sub_59086E(double a1) {
    //     if ((HIWORD(a1) & 0x7FF0) != 0x7FF0)  /* exponent != all-ones * /
    //       return a1;
    //     double v2;
    //     HIDWORD(v2) = (unsigned long long)a1 >> 21 >> 32;  /* keeps a1 bits 53..63 * /
    //     LODWORD(v2) = LODWORD(a1);                          /* keeps low 32 bits * /
    //     return v2;
    //   }
    // UNRESOLVED: Semantic purpose of the all-ones exponent special path (NaN/Inf re-normalization for a downstream display routine) is not established.
    // UNRESOLVED: The CRT___fload ABI lead is LEGACY trust only; no independent source confirms the exact CRT role of this helper.
}
