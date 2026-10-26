// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051512C
// Canonical corpus name: sub_51512C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_51512C_0051512c.c

void UnknownObject::DecompressDxt5AlphaBlock()
{
    // DXT5/BC3-style block decompression. First delegates the colour half of the block to KeyframeQuadInterpolationWithBitPackedSelector(a1, a2+4); if that returns a negative error code the failure is propagated. Otherwise two packed dwords are unpacked into 16 alpha values: the first dword at a2 yields 8 four-bit nibbles written as scaled floats (nibble * 0.06666667) into the float4 alpha slots starting at a1+3 with a 4-float stride, and the second dword at a2+4 yields the remaining 8 nibbles written into the slots starting at a1+35. Returns 0 on success.
    // CALL: Colour-block decompression: KeyframeQuadInterpolationWithBitPackedSelector(a1, a2+4) processes the colour half; its return value gates the alpha path [callee:0x00514FEE, source:raw]
    // GUARD: On a negative return from the colour decompressor, propagate the error result immediately instead of unpacking alpha [callee:0x00514FEE, source:raw]
    // LOOP: Unpack the first 8 nibbles from the dword at a2: each nibble (v3 & 0xF) is shifted out of the dword and written as float (nibble * 0.06666667) into the alpha slot at a1+3 with a 4-float stride across 8 float4 entries [field:this:0x0000000C, global:0x005AC108, source:raw]
    // LOOP: Unpack the next 8 nibbles from the dword at a2+4: each nibble (v7 & 0xF) is shifted out and written as float (nibble * 0.06666667) into the alpha slot at a1+35 with a 4-float stride across the second 8 float4 entries [field:this:0x0000008C, global:0x005AC108, source:raw]
    // RETURN: Return 0 on the completed alpha unpack path; the colour-decompressor error result is returned on the failure path [source:raw]
    // CALL: Invoked by FileOpenAndValidate as part of texture/block loading [caller:0x00515869, source:raw]

    // Conservative worker pseudocode:
    //   int r = KeyframeQuadInterpolationWithBitPackedSelector(a1, a2 + 4);
    //   if (r < 0) return r;
    //   unsigned int v3 = *(dword*)a2;
    //   for (i = 0; i < 8; ++i) { a1[i * 4 + 3] = (float)(v3 & 0xF) * 0.06666667f; v3 >>= 4; }
    //   unsigned int v7 = *(dword*)(a2 + 4);
    //   for (i = 0; i < 8; ++i) { a1[8 * 4 + i * 4 + 3] = (float)(v7 & 0xF) * 0.06666667f; v7 >>= 4; }
    //   return 0;
    // UNRESOLVED: global flt_5ADB14 (0x005ADB14) is listed in the packet facts but appears nowhere in the raw decompiled source for this function
    // UNRESOLVED: The class owning the block-decompressor method is unidentified; caller FileOpenAndValidate invokes it for block data but the object layout is not evidenced here
    // UNRESOLVED: The exact colour-block interpretation performed by KeyframeQuadInterpolationWithBitPackedSelector is out of scope for this packet
}
