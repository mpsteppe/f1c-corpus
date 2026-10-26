// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00513D63
// Canonical corpus name: F_16BitColorToFloat4Decoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_16BitColorToFloat4Decoder_00513d63.c

void UnknownObject::Decode16BitColorToFloat4()
{
    // Decodes one 16-bit packed color value (RGB 5:6:5) into four floats written through the result pointer: R and B use the 0.032258064 scale, G uses the 0.015873017 scale, and alpha is forced to 1.0. Free helper with no instance state; the callers are texture filtering and keyframe quad interpolation.
    // ASSIGNMENT: Decode red channel: result[0] = ((unsigned __int16)a2 >> 11) * flt_5ACCD4 (5-bit red scaled by 0.032258064). [source:raw, field:this:0x00000000, global:0x005ACCD4]
    // ASSIGNMENT: Decode green channel: result[1] = ((a2 >> 5) & 0x3F) * flt_5ACCDC (6-bit green scaled by 0.015873017). [source:raw, field:this:0x00000004, global:0x005ACCDC]
    // ASSIGNMENT: Decode blue channel: result[2] = (a2 & 0x1F) * flt_5ACCD4 (5-bit blue scaled by 0.032258064). [source:raw, field:this:0x00000008, global:0x005ACCD4]
    // ASSIGNMENT: Set alpha channel: result[3] = 1.0, always opaque. [source:raw, field:this:0x0000000C]
    // RETURN: Return the result pointer for chaining. [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_513D63(float* result, unsigned a2) {
    //     result[0] = (float)((unsigned short)a2 >> 11) * 0.032258064f;
    //     result[1] = (float)((a2 >> 5) & 0x3F) * 0.015873017f;
    //     result[2] = (float)(a2 & 0x1F) * 0.032258064f;
    //     result[3] = 1.0f;
    //     return result;
    //   }
    // UNRESOLVED: Exact struct type of the float4 destination is not evidenced; only the four sequential float slots at this+0x0..this+0xC are known.
}
