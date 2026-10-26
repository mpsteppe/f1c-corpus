// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052E350
// Canonical corpus name: MPEGBuffer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MPEGBuffer_0052e350.c

void UnknownObject::MpegBufferFill()
{
    // Fills an output buffer with decoded MPEG data. Loops while fewer than a3 requested bytes have been produced, tracking a byte residual at this+0x24E8 and a frame size at this+0x249C. When the residual equals the frame size it decodes a fresh frame into the caller output buffer via sub_52DF10; otherwise it decodes into the internal buffer at this+0x1244 and copies the available residual bytes out with qmemcpy. Decode failures are reported through FileOpWithGlobalBuffer using the 'mpeg fail 1'/'mpeg fail 2' format strings and the failed frame region is zeroed. On completion the accumulated byte position at this+0x24B4 is recomputed and the total produced byte count is returned.
    // GUARD: Guard on the requested byte count a3: the fill loop runs only while a3 > 0; otherwise control jumps straight to the final position update. Function is invoked by GuardedFunctionCall (caller 0x0052D970). [source:raw, caller:0x0052D970]
    // LOOP: Fill loop iterates while produced bytes (v4) are below the requested count a3; each pass produces one chunk of decoded data. [source:raw, function:0x0052E350]
    // GUARD: Compare residual at this+0x24E8 against frame size at this+0x249C. When equal, a fresh frame is decoded into the output buffer; when different, the residual internal-buffer path is taken instead. [field:this:0x000024E8, field:this:0x0000249C]
    // GUARD: Guard on the remaining requested bytes (a3 - v4): if fewer than the frame size at this+0x249C remain, the decode-new-frame branch is skipped and the function falls through to a partial residual copy instead. [field:this:0x0000249C, source:raw]
    // CALL: Decode one MPEG frame via sub_52DF10 directly into the caller output buffer at (a2 + v4). [callee:0x0052DF10]
    // GUARD: If the frame decode returns non-zero (failure), report 'mpeg fail 1 %d' through FileOpWithGlobalBuffer using the aMpegFail1D format string (global 0x005DA700) and memset the frame region at (a2 + v4) to zero. [callee:0x00588821, global:0x005DA700]
    // ASSIGNMENT: On successful decode, add the frame size to the produced-total v15, advance v4 by the frame size, and increment the frame count at this+0x24E4. [field:this:0x000024E4, source:raw]
    // CALL: Residual path: decode a new frame via sub_52DF10 into the internal buffer at this+0x1244, reset the residual counter this+0x24E8 to 0, and increment the frame count at this+0x24E4. On failure report 'mpeg fail 2 %d' through FileOpWithGlobalBuffer using the aMpegFail2D format string (global 0x005DA6F0) and memset the internal buffer to zero. [callee:0x0052DF10, callee:0x00588821, global:0x005DA6F0, field:this:0x000024E8, field:this:0x000024E4]
    // CALCULATION: Compute the byte count to copy as the residual available (frame size at this+0x249C minus residual at this+0x24E8), clamped to the remaining requested bytes (a3 - v4). [field:this:0x0000249C, field:this:0x000024E8, source:raw]
    // ASSIGNMENT: Copy the residual bytes from the internal buffer at this+0x1244 to the output buffer: qmemcpy for the aligned dword portion plus a trailing byte copy, then advance v4 and the residual counter this+0x24E8 by the copied count and add it to the produced-total v15 on the success path. [field:this:0x000024E8, source:raw]
    // ASSIGNMENT: Final byte-position update: this+0x24B4 = residual at this+0x24E8 + buffer size at this+0x248C multiplied by (frame count at this+0x24E4 minus 1). The ABI owner tag is MPEG_Buffer (abi:lead, LEGACY). [field:this:0x000024B4, field:this:0x0000248C, field:this:0x000024E4, field:this:0x000024E8, abi:lead]
    // RETURN: Return the total number of bytes successfully produced into the output buffer. [function:0x0052E350, source:raw]

    // Conservative worker pseudocode:
    //   int MpegBufferFill(this, outBuffer, requested) {
    //     int produced = 0;
    //     while (produced < requested) {
    //       int residual = this->residual24E8;
    //       if (residual != this->frameSize249C) break;
    //       if (requested - produced < this->frameSize249C) break;
    //       if (sub_52DF10(this, outBuffer + produced)) {
    //         FileOpWithGlobalBuffer("mpeg fail 1 %d\n", this->frameSize249C);
    //         memset(outBuffer + produced, 0, this->frameSize249C);
    //       } else {
    //         produced += this->frameSize249C;
    //       }
    //       this->frameCount24E4++;
    //       if (produced >= requested) goto done;
    //       residual = this->residual24E8;
    //       if (residual == this->frameSize249C) continue;
    //       if (residual < this->frameSize249C) {
    //         if (sub_52DF10(this, this->internalBuf1244)) {
    //           FileOpWithGlobalBuffer("mpeg fail 2 %d\n", this->frameSize249C);
    //           memset(this->internalBuf1244, 0, this->frameSize249C);
    //         }
    //         this->residual24E8 = 0;
    //         this->frameCount24E4++;
    //       }
    //       int n = this->frameSize249C - this->residual24E8;
    //       if (n > requested - produced) n = requested - produced;
    //       qmemcpy(outBuffer + produced, this->internalBuf1244 + this->residual24E8, n);
    //       this->residual24E8 += n;
    //       produced += n;
    //     }
    //   done:
    //     this->position24B4 = this->residual24E8 + this->bufferSize248C * (this->frameCount24E4 - 1);
    //     return produced;
    //   }
    // UNRESOLVED: The semantics of sub_52DF10 (codec decode dispatch) come from existing analysis prose and are DERIVED, not deterministic evidence.
    // UNRESOLVED: The meaning of the final byte-position formula this+0x24B4 is inferred from the field naming in existing analysis (accumulated total byte position); the relation to audio playback is not independently confirmed.
    // UNRESOLVED: Owner class remains UnknownObject; the MPEG_Buffer ABI tag is LEGACY trust and is not a CONFIRMED owner.
}
