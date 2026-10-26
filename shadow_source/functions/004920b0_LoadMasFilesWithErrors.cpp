// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004920B0
// Canonical corpus name: sub_4920B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4920B0_004920b0.c

void UnknownObject::LoadMasFilesWithErrors()
{
    // Reads up to 33 text lines through sub_491FB0, extracts a filename from each with sub_5654A0 using the aSourceMas token global, and attempts to load each file as a bitmap via BitmapLoader. Failures are formatted as 'Could Not Load MAS file %s (line %d)' into the byte_7CDCF0 UI buffer (line number read from this+0x18C) and reported through sub_493C80. The audio stream buffer is flushed before and after the pass; the function always returns 0.
    // CALL: Flush the audio stream buffer with AudioStreamBufferRead(0) before the load pass. [callee:0x00535390, source:raw]
    // GUARD: Only enter the pass when sub_491FB0(this) supplies a first line. [callee:0x00491FB0, source:raw]
    // LOOP: Iterate up to 33 lines (countdown v2 from 32 down to 0 inclusive), continuing while sub_491FB0(this) still returns a line. [callee:0x00491FB0, source:raw]
    // CALL: Extract a filename from the current line into the local 256-byte buffer with sub_5654A0 against the aSourceMas token global. [callee:0x005654A0, global:0x005CC524, source:raw]
    // CALL: Attempt to load the extracted filename as a bitmap through BitmapLoader; success is indicated by a non-zero return. [callee:0x004979F0, source:raw]
    // GUARD: On a load failure, format the aCouldNotLoadMa 'Could Not Load MAS file %s (line %d)' message into the byte_7CDCF0 buffer, substituting the filename and the line number this+0x18C via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, field:this:0x0000018C, global:0x005CC4FC, global:0x007CDCF0, source:raw]
    // CALL: Report the formatted error through sub_493C80(1, byte_7CDCF0). [callee:0x00493C80, source:raw]
    // CALL: Flush the audio stream buffer again with AudioStreamBufferRead(0) after the pass. [callee:0x00535390, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int LoadMasFilesWithErrors(this) {
    //     AudioStreamBufferRead(0);
    //     int remaining = 32;
    //     if (sub_491FB0(this)) {
    //       do {
    //         char filename[256];
    //         if (sub_5654A0(aSourceMas, filename) && !BitmapLoader(filename)) {
    //           StringFormatWithBufferOverflowCheck(byte_7CDCF0, aCouldNotLoadMa, filename, this->line_number);
    //           sub_493C80(1, byte_7CDCF0);
    //         }
    //         --remaining;
    //       } while (remaining >= 0 && sub_491FB0(this));
    //     }
    //     AudioStreamBufferRead(0);
    //     return 0;
    //   }
    // UNRESOLVED: Global 0x007CD9D8 is recorded as read by this function but does not appear in the decompiled body; its role is unknown.
    // UNRESOLVED: The exact behavior of AudioStreamBufferRead when given 0 is not established from this function alone.
}
