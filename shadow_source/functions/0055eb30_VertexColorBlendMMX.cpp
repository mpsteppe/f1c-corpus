// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055EB30
// Canonical corpus name: sub_55EB30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55EB30_0055eb30.c

void UnknownObject::VertexColorBlendMMX()
{
    // Per-vertex MMX color blend over a fixed vertex count. For each vertex reads a source color dword at (this+0xC)+stride and a destination color dword at (this+0x20)+stride, unpacks both to words against qword_8B6C20, adds the blend offset qword_8B8E40, multiplies, shifts right by 8, packs back to bytes, and stores the result into the destination buffer. Clears MMX state with _m_empty() and returns the vertex count.
    // GUARD: Read vertex count at this+0x8; if not greater than zero, skip the blend loop. [field:this:0x00000008]
    // LOOP: Iterate once per vertex while the vertex index is below the count at this+0x8; source stride advances by 48 and destination stride by 64 per vertex. [field:this:0x00000008]
    // ASSIGNMENT: Read source color dword at (this+0xC)+source_offset+24. [field:this:0x0000000C]
    // ASSIGNMENT: Read destination color dword at (this+0x20)+dest_offset+24. [field:this:0x00000020]
    // CALCULATION: Unpack source and destination color bytes to words using the zero word-mask qword_8B6C20. [global:0x008B6C20]
    // CALCULATION: Add the blend offset word qword_8B8E40 to the packed source words. [global:0x008B8E40]
    // CALCULATION: Multiply source and destination word lanes, shift right by 8, and pack back to bytes using qword_8B6C20. [global:0x008B6C20]
    // ASSIGNMENT: Store the blended color dword back into the destination buffer at (this+0x20)+dest_offset+24. [field:this:0x00000020]
    // STATE_TRANSITION: Clear MMX state via _m_empty() after the loop. [function:0x0055EB30]
    // RETURN: Return the vertex count. [field:this:0x00000008]

    // Conservative worker pseudocode:
    //   count = this->vertex_count;
    //   if (count > 0) {
    //       for (i = 0; i < count; i++) {
    //           src = *(dword*)(this->src + i*48 + 24);
    //           dst = *(dword*)(this->dst + i*64 + 24);
    //           blended = packuswb(psrlwi(pmullw(paddw(punpcklbw(src, zero), qword_8B8E40),
    //                                     punpcklbw(dst, zero)), 8), zero);
    //           *(dword*)(this->dst + i*64 + 24) = blended;
    //       }
    //   }
    //   _m_empty();
    //   return count;
    // UNRESOLVED: Semantics of the two word constants qword_8B6C20 and qword_8B8E40 (zero/unpack mask versus fixed-point blend offset) are interpreted from the MMX idiom, not from a labeled source.
}
