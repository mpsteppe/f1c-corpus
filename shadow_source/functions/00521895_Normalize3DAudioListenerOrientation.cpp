// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00521895
// Canonical corpus name: F_3DAudioListenerTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DAudioListenerTransform_00521895.c

void UnknownObject::Normalize3DAudioListenerOrientation()
{
    // Normalizes a 4-component 3D audio listener orientation vector using 3DNow! packed single-precision math. Reads the two 64-bit halves of the input a2, extracts the 4th component (high dword of a2[1]) and tests it against packed 1.0. When the 4th component is >= 1.0 the input is copied to the output unchanged. Otherwise it runs SquareRootApproximation and a 3DNow! helper, then, when the absolute 4th component exceeds a small threshold (0x34000000 packed), refines a reciprocal via pfrcp/pfrcpit1/pfrcpit2 (Newton-Raphson) and scales both input halves by it, finally masking the second half with a low-dword quad mask before writing the normalized result to a1.
    // CALCULATION: Flush MMX/3DNow! floating-point state (_m_femms) on entry and again before returning. [source:raw]
    // ASSIGNMENT: Read both 64-bit halves of the input orientation vector: m64_u64 = a2->m64_u64 and v4 = a2[1]. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Extract the 4th vector component: v5 = punpckhdq(v4, v4) duplicates the high dword of the second half into both lanes. [source:raw]
    // GUARD: Guard on pfcmpge(v5, packed 1.0, 0x3F8000003F800000): when the 4th component is >= 1.0 the normalization path is skipped and the input is copied through directly. [global:0x005AF988, source:raw]
    // CALL: Call SquareRootApproximation(0, a2) to obtain a reciprocal-square-root estimate of the vector magnitude; its return value is ignored. [callee:0x00529000, source:raw]
    // ASSIGNMENT: Save the low dword of the extracted component: v9 = cvtsi64_si32(v5). [source:raw]
    // CALL: Call sub_529700(), a 3DNow! helper that contributes to the orientation refinement; no arguments are passed per the raw source. [callee:0x00529700, source:raw]
    // ASSIGNMENT: Re-read both halves of the input a2 after the helper calls, refreshing m64_u64 and v4. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // GUARD: Guard on pfcmpge(pand(v5, absolute-value mask 0x7FFFFFFF7FFFFFFF), small threshold 0x3400000034000000): normalization scaling runs only when the absolute 4th component clears the threshold. [global:0x005AF940, global:0x005AF948, source:raw]
    // CALCULATION: Newton-Raphson reciprocal refinement: v7 = pfrcp(v5), then v8 = pfrcpit2(pfrcpit1(v5, v7), v7) folded through the low dword lane v6 = cvtsi32_si64(v9). [source:raw]
    // CALCULATION: Scale both halves of the orientation vector by the refined reciprocal v8: m64_u64 = pfrmul(m64_u64, v8) and v4 = pfrmul(v4, v8). [source:raw]
    // ASSIGNMENT: Write the result: result->m64_u64 = m64_u64 (output this+0x0) and result[1].m64_u64 = v4 AND 0xFFFFFFFF low-dword quad mask (output this+0x8). [field:this:0x00000000, field:this:0x00000008, global:0x005AF950, source:raw]
    // RETURN: Return the output pointer a1 (after the trailing _m_femms). [function:0x00521895, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   m64_u64 = a2[0]; v4 = a2[1];
    //   v5 = punpckhdq(v4, v4); /* 4th component in both lanes * /
    //   if (v5 < 1.0) { /* pfcmpge(1.0) false * /
    //     SquareRootApproximation(0, a2);
    //     v9 = low_dword(v5);
    //     sub_529700();
    //     m64_u64 = a2[0]; v4 = a2[1];
    //     if (abs(v5) >= 0x34000000) {
    //       v7 = pfrcp(v5);
    //       v8 = pfmul(dup32(v9), pfrcpit2(pfrcpit1(v5, v7), v7));
    //       m64_u64 = pfmul(m64_u64, v8);
    //       v4 = pfmul(v4, v8);
    //     }
    //   }
    //   a1[0] = m64_u64;
    //   a1[1] = v4 & 0xFFFFFFFF;
    //   femms();
    //   return a1;
    // UNRESOLVED: Globals qword_5AF940 / qword_5AF948 / qword_5AF950 / qword_5AF988 are the backing data for the literal mask/constant operands (abs mask, threshold, quad mask, packed 1.0) per the prior analysis; the exact literal-to-global pairing is DERIVED and unverified.
    // UNRESOLVED: The return value of SquareRootApproximation is discarded; whether sub_529700 mutates shared 3DNow! state that the subsequent re-read relies on is unknown.
    // UNRESOLVED: Owner and call context are unknown; no static callers were found for this function.
}
