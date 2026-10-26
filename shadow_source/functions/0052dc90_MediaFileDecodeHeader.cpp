// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052DC90
// Canonical corpus name: MediaFileDecodeHeader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MediaFileDecodeHeader_0052dc90.c

void UnknownObject::MediaFileDecodeHeader()
{
    // DecodeHeader stage of an MPEG media file player. If the header-read-needed flag (this+0x2D3C) is set, reads a 4-byte sync word through the I/O interface vtable (read function at vtable+8 on the interface at this+0x2D34), byte-swaps it, and hands it to CMpegBase_ProcessHeader (0052DA30). When the processed frame size at this+0x2498 is under 4 or the follow-up raw read into this+0x24A4 does not return the expected byte count, reports a corrupted-header message, clears the frame-size field (this+0x24A8) and re-arms the header-read flag. I/O read failures report the waiting-for-CD string and return -1.
    // GUARD: Header read is skipped entirely when the flag byte at this+0x2D3C is clear (0 = a valid header is already present); execution falls through to the frame-size validation path [field:this:0x00002D3C, source:raw]
    // CALL: Invokes the I/O virtual read function at vtable+8 of the interface pointer *(this+0x2D34), reading 4 bytes into a stack variable (v4) [field:*(*(this+0x2D34)+0x0):0x00000008, field:*(this+0x2D34):0x00000000, field:this:0x00002D34, source:raw]
    // GUARD: If the read returned anything other than 4 bytes, the header is unavailable; error path is taken [source:raw]
    // CALL: FileOpWithGlobalBuffer (00588821) is called with the waiting-for-CD string (global 0x005DA65C) on the failed 4-byte read [callee:0x00588821, global:0x005DA65C, source:raw]
    // RETURN: Returns -1 immediately after reporting the CD-wait failure [source:raw]
    // CALL: CMpegBase_ProcessHeader (0052DA30) is called with the byte-swapped sync word; its result is returned on the failure path [callee:0x0052DA30, source:raw]
    // CALCULATION: Reads the frame size computed by the header parse from this+0x2498 into v3 [field:this:0x00002498, source:raw]
    // GUARD: Frame size v3 below 4 is treated as a corrupted MPEG header, routing to the error message and reset path [source:raw]
    // CALL: FileOpWithGlobalBuffer (00588821) is called with the corrupted-header format string (global 0x005DA5FC), the sync word and the frame size as arguments [callee:0x00588821, global:0x005DA5FC, source:raw]
    // CALL: I/O virtual read at vtable+8 fetches v3 bytes into the raw-header destination buffer at this+0x24A4 [field:this:0x000024A4, source:raw]
    // GUARD: If the follow-up read did not return exactly the expected v3 bytes, the header is rejected: flag this+0x2D3C cleared and -1 returned [field:this:0x00002D3C, source:raw]
    // ASSIGNMENT: Success/reset path writes frame-size field this+0x24A8 to 0 and re-arms the header-read flag this+0x2D3C to 1 [field:this:0x000024A8, field:this:0x00002D3C, source:raw]
    // RETURN: Returns 0 on the accepted/corruption-recovered paths; returns CMpegBase_ProcessHeader's -1 result on header failure; returns -1 when the raw read length mismatches [source:raw]

    // Conservative worker pseudocode:
    //   if (*(BYTE*)(this + 0x2D3C)) {
    //     v4 = 0;
    //     if (io->read4((void*)(this + 0x2D34), &v4, 4) != 4) {
    //       FileOpWithGlobalBuffer("waiting for CD...");
    //       return -1;
    //     }
    //     result = CMpegBase_ProcessHeader(this, byteswap(v4));
    //     if (result == -1) return result;
    //   }
    //   v3 = *(int*)(this + 0x2498);
    //   if (v3 < 4) {
    //     FileOpWithGlobalBuffer("corrupted mpeg header ...", v4, v3);
    //   } else if (io->read((void*)(this + 0x2D34), (void*)(this + 0x24A4), v3) == v3) {
    //     *(int*)(this + 0x24A8) = 0;
    //     *(BYTE*)(this + 0x2D3C) = 1;
    //     return 0;
    //   } else {
    //     *(BYTE*)(this + 0x2D3C) = 0;
    //     return -1;
    //   }
    //   *(int*)(this + 0x24A8) = 0;
    //   *(BYTE*)(this + 0x2D3C) = 1;
    //   return 0;
    // UNRESOLVED: The I/O interface (this+0x2D34) and its vtable layout are only partially described; only the read slot at vtable+8 is evidenced here
    // UNRESOLVED: The purpose of this+0x24A4 as a buffer is inferred from the read destination; the buffer's backing allocation is not evidenced in this packet
    // UNRESOLVED: Byteswap of the sync word and the meaning of the frame-size threshold 4 are read from the raw source but not cross-confirmed elsewhere in this packet
}
