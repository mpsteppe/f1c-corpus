// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052156F
// Canonical corpus name: Media3DNowMathOperation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Media3DNowMathOperation_0052156f.c

void UnknownObject::LookupScaled3DNowTransform()
{
    // Straight-line 3DNow! transform builder. Queries a 12-byte precomputed entry through sub_5262C2 using selector a2, scales the input float a3 by 0.5 via the packed constant 0x3F0000003F000000, expands the scaled value across both lanes with PackedFloatingPointMath, then multiplies the lookup entry halves by the lane-expanded components and writes the two resulting packed values into the output __m64 pair a1[0] and a1[1].
    // CALL: Reset MMX/3DNow state with _m_femms at function entry [source:raw]
    // CALL: sub_5262C2 fills the local lookup entry (v7 m64 pair plus trailing v8 scalar) from index a2 [callee:0x005262C2, source:raw]
    // CALCULATION: Scale a3 by 0.5: _m_pfmul of the converted a3 against the packed constant 0x3F0000003F000000 (0.5 in both 32-bit halves) [source:raw]
    // CALL: PackedFloatingPointMath performs component setup/expansion for the 3DNow arithmetic [callee:0x005295E0, source:raw]
    // CALCULATION: Lane expansion: v5 = _m_punpckhdq(v3, v3) spreads the high lane into both lanes; v6 = _m_punpckldq(_m_pfmul(convert(v8), v5), v3) combines the trailing lookup scalar multiplied by v5 with v3 [source:raw]
    // ASSIGNMENT: Multiply the first lookup m64 (v7) by v5 and store into the first output element a1[0] [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Store the combined v6 value into the second output element a1[1] [field:this:0x00000008, source:raw]
    // CALL: Reset MMX/3DNow state with a trailing _m_femms before returning [source:raw]
    // RETURN: Return the output pointer a1 [function:0x0052156F]

    // Conservative worker pseudocode:
    //   femms();
    //   sub_5262C2(&v7, a2);   // fills 12-byte lookup entry (v7 pair + v8 scalar)
    //   v3 = pfmul(convert_i32_to_m64(a3), 0x3F0000003F000000);  // a3 * 0.5 in both lanes
    //   PackedFloatingPointMath();
    //   v5 = punpckhdq(v3, v3);
    //   v6 = punpckldq(pfmul(convert_i32_to_m64(v8), v5), v3);
    //   a1[0] = pfmul(v7, v5);
    //   a1[1] = v6;
    //   femms();
    //   return a1;
    // UNRESOLVED: Global qword_5AF990 appears in the deterministic packet facts but is absent from the raw decompiled source, so its exact role cannot be attributed from this packet
    // UNRESOLVED: The layout and producer of the 12-byte lookup entry (which transform data it encodes) is not documented by this function
    // UNRESOLVED: The side effects of PackedFloatingPointMath beyond component expansion are not visible here
    // UNRESOLVED: The semantic meaning of the this+0x8 field versus the a1[1] element write is not resolved from the packet field list
}
