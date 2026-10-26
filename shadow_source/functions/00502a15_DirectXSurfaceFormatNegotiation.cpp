// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00502A15
// Canonical corpus name: DirectXSurfaceFormatNegotiation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DirectXSurfaceFormatNegotiation_00502a15.c

void UnknownObject::DirectXSurfaceFormatNegotiation()
{
    // Texture format auto-detection and decoding dispatcher. Tries seven image decoders in a fixed priority order (BMP, TGA/generic, DDS-header, unknown sub_50210E, DDS-surface, PPM, DDS-validate) on the raw buffer a2/a3, recording the active candidate in the object at this+0x44/this+0x48 and the caller payload at this+0x40. On the first candidate whose decoder returns a non-negative status it stops; on failure it frees buffers and surface nodes owned by this, resets ownership flags, and retries the next candidate. After success it optionally fills an output descriptor a4 (width/height/depth/FourCC/format/surface-count from this+0xC..this+0x48) and finalizes the linked surface list rooted at this+0x4C/this+0x50. Returns 0 on success, -2005529767 when all candidates fail.
    // ASSIGNMENT: Initialize the local format-priority table v21 = {0, 5, 4, 1, 3, 2, 6} and candidate counter v22 = 0. [source:raw]
    // LOOP: do-while retry loop over the seven format candidates; exits early when a candidate succeeds (v5 >= 0) or continues until all seven are tried. [source:raw]
    // ASSIGNMENT: Each iteration records the caller payload a5 at this+0x40, the candidate index at this+0x48, and the constant format code 3 at this+0x44. [field:this:0x00000040, field:this:0x00000048, field:this:0x00000044, source:raw]
    // CALL: Candidate 0: validate BMP header via BMPHeaderValidation(this, a2, a3). [callee:0x005029E5, source:raw]
    // CALL: Candidate 1: decompress image texture via ImageTextureDecompressor(this, a2, a3). [callee:0x00501722, source:raw]
    // CALL: Candidate 2: parse DDS header via DDSHeaderParsing(this, a2, a3). [callee:0x00501992, source:raw]
    // CALL: Candidate 3: call the unnamed decoder sub_50210E(this, a2, a3). [callee:0x0050210E, source:raw]
    // CALL: Candidate 4: create the DDS texture surface via DDSTextureSurfaceCreation(this, a2, a3). [callee:0x005026A4, source:raw]
    // CALL: Candidate 5: decode the PPM P6 image via PPMP6ImageDecoder(this, a2, a3). [callee:0x00501E39, source:raw]
    // CALL: Candidate 6: validate/decoding via DDSTextureFormatValidationDecoding(this, a2, a3). [callee:0x00500FCA, source:raw]
    // ASSIGNMENT: Store the selected decoder's return value as the candidate status v5. [source:raw]
    // GUARD: If the candidate status v5 is >= 0, the decode succeeded and the retry loop is exited. [source:raw]
    // CALL: On failure, if the buffer-1 pointer this+0x4 and its ownership flag this+0x38 are both set, free buffer 1 via FreeWrapper_7bcf; likewise free buffer 2 when this+0x8 and this+0x3C are set. [callee:0x00587BCF, field:this:0x00000004, field:this:0x00000038, field:this:0x00000008, field:this:0x0000003C, source:raw]
    // CALL: On failure, release the surface head node this+0x4C and the next-surface pointer this+0x50 via ShortComputation_0fae(node, 1) when each is non-null. [callee:0x00500FAE, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Reset decoder state for the next candidate: zero this+0x4, this+0x8, this+0x38, this+0x3C, this+0x4C and this+0x50, then increment the candidate counter v22. [field:this:0x00000004, field:this:0x00000008, field:this:0x00000038, field:this:0x0000003C, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // RETURN: If all seven candidates failed (v22 == 7), return -2005529767. [source:raw]
    // GUARD: If the output descriptor a4 is non-null, populate it from the decoded object. [source:raw]
    // CALL: Derive the output FourCC code from this+0x0 via FourCCDecoder. [callee:0x005006A4, field:this:0x00000000]
    // ASSIGNMENT: Zero the 0x1C-byte output descriptor a4, then fill width from this+0xC, height from this+0x10, depth from this+0x14, base surface count 1, format from this+0x44 and the candidate index from this+0x48. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000044, field:this:0x00000048, source:raw]
    // LOOP: Count the surfaces in the linked list rooted at this+0x4C by walking each node's next pointer (node+0x4C) and incrementing the surface count a4[3]. [field:*(this+0x4C):0x0000004C, source:raw]
    // LOOP: Finalize each surface node in the chain: copy node+0xC to node+0x20 and node+0x10 to node+0x24, save node+0x14 into node+0x2C, zero node+0x18, node+0x1C and node+0x28, then advance through node+0x4C and to the next surface at this+0x50. [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // RETURN: Return 0 after successful decode and surface finalization. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_502A15(this, a2, a3, a4, a5) {
    //     int fmt[7] = {0, 5, 4, 1, 3, 2, 6};
    //     int idx = 0;
    //     int status;
    //     do {
    //       *(this+0x40) = a5; *(this+0x48) = fmt[idx]; *(this+0x44) = 3;
    //       status = decoder[fmt[idx]](this, a2, a3);
    //       if (status >= 0) break;
    //       if (*(this+0x4) && *(this+0x38)) FreeWrapper_7bcf(*(this+0x4));
    //       if (*(this+0x8) && *(this+0x3C)) FreeWrapper_7bcf(*(this+0x8));
    //       if (*(this+0x4C)) ShortComputation_0fae(*(this+0x4C), 1);
    //       if (*(this+0x50)) ShortComputation_0fae(*(this+0x50), 1);
    //       *(this+0x4)=0; *(this+0x8)=0; *(this+0x38)=0; *(this+0x3C)=0; *(this+0x4C)=0; *(this+0x50)=0;
    //     } while (++idx < 7);
    //     if (idx == 7) return -2005529767;
    //     if (a4) {
    //       memset(a4, 0, 0x1C);
    //       a4[0] = *(this+0xC); a4[1] = *(this+0x10); a4[2] = *(this+0x14);
    //       a4[3] = 1;
    //       a4[4] = FourCCDecoder(*(this+0x0)); a4[5] = *(this+0x44); a4[6] = *(this+0x48);
    //       for (i = *(this+0x4C); *i; i = *i + 0x4C) ++a4[3];
    //     }
    //     do {
    //       for (v19 = this; v19; v19 = v19[0x4C]) {
    //         v19[0x20] = v19[0xC]; v19[0x24] = v19[0x10]; v19[0x2C] = v19[0x14];
    //         v19[0x18] = 0; v19[0x1C] = 0; v19[0x28] = 0;
    //       }
    //       this = *(this+0x50);
    //     } while (this);
    //     return 0;
    //   }
    // UNRESOLVED: The semantics of the fields at this+0x18/this+0x1C/this+0x28 (format flags, mip count, stride) are only grounded as being zeroed during finalization.
    // UNRESOLVED: Candidate 3 (sub_50210E) has no name and its decode role is unknown.
    // UNRESOLVED: Field this+0x98 is read somewhere in the function's disassembly but no access is visible in the decompiled body; treated as an unresolved read.
    // UNRESOLVED: The relationship between this+0x4C (surface head) and this+0x50 (next surface) chains is not fully resolved.
}
