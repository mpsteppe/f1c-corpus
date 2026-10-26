// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005124DE
// Canonical corpus name: PacketFieldEncoding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PacketFieldEncoding_005124de.c

void UnknownObject::PacketFieldEncoding()
{
    // Configures and encodes an output packet's format fields (encoding type byte, bit depth byte, per-pixel stride byte, and total DWORD size) from session/state flag bits at this+0x60 and this+0x61, copying camera rotation DWORD at this+0x130 into the packet when the video flag is set.
    // GUARD: Reads flags byte at this+0x61; bit 0x10 enables the packet-format block that rewrites the encoding type byte and bit depth byte of the output packet. [field:this:0x00000061]
    // ASSIGNMENT: When the encoding byte at a2+25 equals 3, rewrites it as 4 * (WORD at this+0x10A is non-zero ? 1 : 0) + 2, collapsing the type to 2 or 6 depending on that WORD. [field:this:0x0000010A, guard:1]
    // ASSIGNMENT: Otherwise, when WORD at this+0x10A is non-zero, ORs bit 4 into the encoding byte at a2+25; then, when the bit depth byte at a2+24 is below 8, forces it to 8, and always zeroes the WORD at a2+22. [field:this:0x0000010A, guard:1]
    // ASSIGNMENT: When bit 0x20 of the flags byte at this+0x61 is set, copies the DWORD at this+0x130 (camera rotation data) into the packet DWORD at a2+40. [field:this:0x00000130]
    // ASSIGNMENT: When bit 0x4 of the flags byte at this+0x61 is set and the packet bit depth byte at a2+24 is 16, downgrades the bit depth to 8. [field:this:0x00000061]
    // ASSIGNMENT: When bit 0x40 of the flags DWORD at this+0x60 is set, the encoding byte at a2+25 is 2 or 6, the DWORD at this+0x174 is non-zero, and the packet bit depth at a2+24 is 8, sets the encoding byte to 3. [field:this:0x00000060, field:this:0x00000174]
    // ASSIGNMENT: When bit 0x4 of the flags DWORD at this+0x60 is set and the packet bit depth byte at a2+24 is below 8, raises the bit depth to 8. [field:this:0x00000060]
    // ASSIGNMENT: Computes the per-sample stride byte at a2+29 from the encoding byte at a2+25: 1 when the encoding is 3 or lacks bit 2, else 3; increments the stride when bit 4 of the encoding is set; increments again when the sign bit of this+0x61 is set and the encoding is 2 or 0. [guard:0, field:this:0x00000061]
    // CALCULATION: Multiplies the stride byte at a2+29 by the bit depth byte at a2+24, storing the total bytes-per-sample product in the byte at a2+30. [function:0x005124DE, source:raw]
    // RETURN: Computes result = (DWORD at a2 * bytes-per-sample product + 7) >> 3, stores it in the DWORD at a2+12, and returns it as the encoded packet field size. [function:0x005124DE, source:raw]

    // Conservative worker pseudocode:
    //   if ((state->flags61 & 0x10) != 0) {
    //       if (packet->encoding == 3) packet->encoding = 4 * (state->word10A != 0) + 2;
    //       else { if (state->word10A != 0) packet->encoding |= 4;
    //              if (packet->bitDepth < 8) packet->bitDepth = 8; }
    //       packet->word22 = 0;
    //   }
    //   if ((state->flags61 & 0x20) != 0) packet->dword40 = state->dword130;
    //   if ((state->flags61 & 0x4) != 0 && packet->bitDepth == 16) packet->bitDepth = 8;
    //   if ((state->flags60 & 0x40) != 0 && (packet->encoding == 2 || packet->encoding == 6)
    //       && state->dword174 != 0 && packet->bitDepth == 8) packet->encoding = 3;
    //   if ((state->flags60 & 0x4) != 0 && packet->bitDepth < 8) packet->bitDepth = 8;
    //   packet->stride = (packet->encoding == 3 || (packet->encoding & 2) == 0) ? 1 : 3;
    //   if (packet->encoding & 4) packet->stride++;
    //   if ((char)state->flags61 < 0 && (packet->encoding == 2 || packet->encoding == 0)) packet->stride++;
    //   packet->byte30 = packet->stride * packet->bitDepth;
    //   packet->size = (packet->dword0 * packet->byte30 + 7) >> 3;
    // UNRESOLVED: The output packet object at a2 is not part of the packet evidence; the exact layout and semantics of a2+0, a2+12, a2+22, a2+24, a2+25, a2+29, a2+30, and a2+40 are inferred from the raw source text only.
    // UNRESOLVED: The encoded meaning of the encoding-type values (2, 3, 6) and bit-depth values (8, 16) is not grounded in packet evidence.
    // UNRESOLVED: The owning class of this is unknown; a1 is only shown to carry flag bytes at 0x60/0x61 and configuration at 0x10A, 0x130, and 0x174.
    // UNRESOLVED: Why bit 0x4 of this+0x60 and bit 0x4 of this+0x61 both modify the same bit-depth byte is unexplained.
}
