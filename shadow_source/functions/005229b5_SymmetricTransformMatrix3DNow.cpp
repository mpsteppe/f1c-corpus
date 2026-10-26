// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005229B5
// Canonical corpus name: SymmetricTransformMatrix3DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SymmetricTransformMatrix3DNow_005229b5.c

void UnknownObject::SymmetricTransformMatrix3DNow()
{
    // 3DNow!/MMX construction of a symmetric 4x4 transformation matrix: converts parameter a2 to a packed __m64 (cvtsi32_si64), masks the low dword into v4 (pand 0xFFFFFFFF) and extracts the high dword into v5 (psrlqi 32), then fills eight matrix slots in a1. The low dword appears symmetrically at a1[0] and a1[5], the high dword at a1[4] and negated (pxor 0x80000000) at a1[1], and identity elements (0x3F80000000000000 = 1.0) at a1[2]/a1[7] with zeros at a1[3]/a1[6]. PackedFloatingPointMath() is called for setup and MMX state is cleared with _m_femms() on entry and exit; returns a1.
    // STATE_TRANSITION: Clear MMX/3DNow! state with _m_femms() on entry. [source:raw]
    // CALL: Call PackedFloatingPointMath() for packed-math setup before matrix construction. [source:raw, callee:0x005295E0]
    // CALCULATION: Convert parameter a2 to __m64 v3 via cvtsi32_si64; mask the low dword into v4 with pand 0xFFFFFFFF; extract the high dword into v5 with psrlqi 32. [source:raw]
    // ASSIGNMENT: Write a1[2] (field this+0x10) = 0x3F80000000000000 (1.0 identity) and a1[3] (field this+0x18) = 0. [source:raw, field:this:0x00000010, field:this:0x00000018]
    // ASSIGNMENT: Write a1[6] (field this+0x30) = 0 and a1[7] (field this+0x38) = 0x3F80000000000000 (1.0 identity). [source:raw, field:this:0x00000030, field:this:0x00000038]
    // ASSIGNMENT: Write a1[4] (field this+0x20) = v5 (high dword of the parameter). [source:raw, field:this:0x00000020]
    // ASSIGNMENT: Write a1[0] (field this+0x0) = v4 and a1[5] (field this+0x28) = v4, placing the parameter low dword symmetrically. [source:raw, field:this:0x00000000, field:this:0x00000028]
    // ASSIGNMENT: Write a1[1] (field this+0x8) = negate(v5) via pxor 0x80000000. [source:raw, field:this:0x00000008]
    // CALCULATION: Read four packed qword globals (5AF950, 5AF978, 5AF9C0, 5AF9C8) as SIMD constants for the matrix construction; their contents are not present in the packet. [global:0x005AF950, global:0x005AF978, global:0x005AF9C0, global:0x005AF9C8]
    // STATE_TRANSITION: Clear MMX/3DNow! state with _m_femms() before returning. [source:raw]
    // RETURN: Return a1, the pointer to the filled symmetric transformation matrix. [source:raw]

    // Conservative worker pseudocode:
    //   m64 *sub_5229B5(m64 *a1 /* out 4x4 matrix * /, uint a2 /* packed parameter * /) {
    //     _m_femms();
    //     PackedFloatingPointMath();
    //     lo = a2 & 0xFFFFFFFF;  hi = a2 >> 32;
    //     // a1[0]=lo, a1[1]=-hi, a1[2]=1.0, a1[3]=0, a1[4]=hi, a1[5]=lo, a1[6]=0, a1[7]=1.0
    //     _m_femms();
    //     return a1;
    //   }
    // UNRESOLVED: Owner/class of the function is UNKNOWN (no callers in packet; packet owner trust UNKNOWN).
    // UNRESOLVED: Exact contents of the four global packed constants are not in the packet; only that they are read.
    // UNRESOLVED: The caller's semantics for the packed parameter a2 (how the high/low dwords are derived) are unconfirmed.
}
