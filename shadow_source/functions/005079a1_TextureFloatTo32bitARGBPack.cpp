// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005079A1
// Canonical corpus name: TextureFloatTo32bitARGBPack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureFloatTo32bitARGBPack_005079a1.c

void UnknownObject::TextureFloatTo32bitARGBPack()
{
    // Structural twin of VertexColorFloatToByte (005078B5). Converts four floats per source element into one packed 32-bit color. Optionally runs DirectXVertexBufferFormatConversion when the format flag at this+0x1048 is set, computes the source base from this+0x2C, calls UtilityFunction_7473, then for each of this+0x1058 entries scales four floats by 255.0 and packs them into a single 32-bit word. Returns the conversion-state global dword_8B009C.
    // GUARD: If this[1042] (this+0x1048) is non-zero, convert the vertex buffer format before processing. [field:this:0x00001048]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4) and replace a4 with the converted format. [callee:0x00506CE2, field:this:0x00001048]
    // CALCULATION: Compute the source base v5 = this[11] (this+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)). [field:this:0x0000002C]
    // CALL: Unconditional call to UtilityFunction_7473 before the packing loop. [callee:0x00507473]
    // LOOP: do-while loop over this[1046] (this+0x1058) entries: for each, read four floats from the source quad (indexed by v7 & 3), add the base offset, scale each by 255.0, and pack the four bytes into one 32-bit word (v11 | ((v12 | ((v9 | (v16 << 8)) << 8)) << 8)) written through the output cursor; advance the source cursor 16 bytes and the output cursor one dword per entry. [field:this:0x00001058]
    // RETURN: Return the conversion-state global dword_8B009C. [global:0x008B009C]

    // Conservative worker pseudocode:
    //   // this+0x1048: format-conversion flag; this+0x1058: entry count; this+0x2C: source data base
    //   if (this[1042] != 0)
    //       a4 = DirectXVertexBufferFormatConversion(this, a4);
    //   src = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   out = <output pointer>;              // v6, uninitialized in decompiled text
    //   v7 = 0; v8 = 0;
    //   if (this[1046] != 0) {
    //       do {
    //           base = *(float*)(src + 4 * (v7 & 3));
    //           c0 = (int)(*(float*)(v8 + a4 + 0)  * 255.0 + base);
    //           c1 = (int)(*(float*)(v8 + a4 + 4)  * 255.0 + base);
    //           c2 = (int)(*(float*)(v8 + a4 + 8)  * 255.0 + base);
    //           c3 = (int)(*(float*)(v8 + a4 + 12) * 255.0 + base);
    //           *out++ = c2 | ((c1 | ((c0 | (c3 << 8)) << 8)) << 8);
    //           v8 += 16; ++v7;
    //       } while (v7 < this[1046]);
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: Global flt_59FEC8 is read but never appears in the raw pseudocode; it likely supplies the 255.0 scale constant, but that mapping is not evidenced.
    // UNRESOLVED: Output pointer v6 is uninitialized in the decompiled text; the true destination buffer is not evidenced.
    // UNRESOLVED: The shift order (v9 | (v16 << 8), then v12, then v11) fixes the relative byte order of the four channels, but which source float maps to which color channel is not confirmed statically.
}
