// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052704A
// Canonical corpus name: QuaternionProduct3DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuaternionProduct3DNow_0052704a.c

void UnknownObject::QuaternionProduct3DNow()
{
    // Computes a quaternion product using 3DNow! packed floating-point intrinsics. Reads the two packed float pairs of quaternions a2, a3 and a4, builds three cross-product-like terms (v7, v8, v9) from the component pairs of a3 and a4 via punpck/pfmul/pfsub, then assembles the two output halves of the product into a1[0] and a1[1] with pfmul/pfacc and sign-flip XOR against the packed negative-zero constant 0x8000000000000000 (backed by global qword_5AF980). MMX/3DNow state is cleared with _m_femms at entry and exit, and the output buffer pointer a1 is returned. The packet's ABI name QuaternionProduct3DNow is LEGACY-trusted.
    // CALL: Clear MMX/3DNow state via _m_femms before the arithmetic sequence. [source:raw]
    // CALCULATION: Load the second component pairs of the a3 and a4 inputs (v5 = a3[1], v6 = a4[1]). [field:this:0x00000008, source:raw]
    // CALCULATION: Build cross-product term v7 from the component pairs of a3 and a4 using punpckhdq/punpckldq, pfmul and pfsub. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Build cross-product term v8 from the component pairs of a3 and a4 using punpckhdq/punpckldq, pfmul and pfsub. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Build cross-product term v9 from the component pairs of a3 and a4 using punpckldq/punpckhdq, pfmul and pfsub. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Load the a2 quaternion component pairs (v10 = a2[1], m64_u64 = a2[0]) used to assemble the product. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Assemble the first output half from v7/v8/v9 and a2 via pfmul, sign-flip XOR against 0x8000000000000000 (packed negative-zero constant backed by global qword_5AF980), and pfacc. [global:0x005AF980, source:raw]
    // CALCULATION: Build the sign-flip masks v12 and v15 from 0x8000000000000000 using psrlqi/psllqi, and derive v13/v14 via pxor against v12. [global:0x005AF980, source:raw]
    // CALCULATION: Assemble the second output half from v7/v8/v9/v13/v14/v15 and a2 via pfmul, pfacc and sign-flip XOR masks. [source:raw]
    // ASSIGNMENT: Store the first 64-bit half of the quaternion product into a1 at offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Store the second 64-bit half of the quaternion product into a1 at offset 0x8. [field:this:0x00000008]
    // CALL: Clear MMX/3DNow state via _m_femms after the arithmetic sequence. [source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x0052704A, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   v5 = a3[1]; v6 = a4[1];
    //   v7 = cross_term(a3[0], a3[1], a4[0], a4[1]);
    //   v8 = cross_term(a3[0], a3[1], a4[0], a4[1]);
    //   v9 = cross_term(a3[0], a3[1], a4[0], a4[1]);
    //   a1[0] = quaternion_product_half(v7, v8, v9, a2[0], a2[1], sign_mask);
    //   a1[1] = quaternion_product_half(v7, v8, v9, a2[0], a2[1], sign_mask);
    //   femms();
    //   return a1;
    // UNRESOLVED: The exact binding between the immediate constant 0x8000000000000000 and global qword_5AF980 is DERIVED; the raw source uses the literal and the packet lists the global as a read.
    // UNRESOLVED: Which packed lanes correspond to w/x/y/z of each quaternion half is not recoverable from this function alone.
    // UNRESOLVED: The role of the third input quaternion a4 relative to the product semantics is unclear from this function alone.
    // UNRESOLVED: Owner is UNKNOWN; the packet carries no owner evidence and no static callers.
}
