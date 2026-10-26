// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059A221
// Canonical corpus name: sub_59A221
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59A221_0059a221.c

void UnknownObject::FormattedInputReadWithBufferSetup()
{
    // Formatted input read with buffer setup and fallback. Saves arguments, then tries a read pipeline on the stream object at this[20] (+0x50): FileIOForwardingWrapper(this[20], &v15) forwards the stream's file I/O, a non-null a3 triggers sub_587F64(this[20], v10, 1) as a filter/check, and StringStreamReadWithMaskCheck(this[20], &v15) performs the masked string-stream read. If the stream is null or any stage fails, the failure path calls sub_59942B(&a3, -1) to build a default/fallback result. On success, if the buffer object at this[17] (+0x44) exists, this[16] (+0x40) is set to a7 and the buffer is reset via BufferTruncationShrink(v12, 0, 0xFFFFFFFF); the result record is assembled (a3 = 0, a5 = v15, a6 = v16, a7 = this[16]). The 0x18-byte result struct is copied into output buffer a2 and a2 is returned.
    // ASSIGNMENT: Save incoming arguments: v15 = a5, v16 = a6, v10 = a3; capture the stream pointer v11 = this[20]. [field:this:0x00000050, function:0x0059A221, source:raw]
    // GUARD: If this[20] (stream at +0x50) is null, select the failure path and generate a default result. [field:this:0x00000050, source:raw]
    // CALL: FileIOForwardingWrapper(this[20], &v15) forwards/prepares the stream's file I/O; a non-zero return selects the failure path. [callee:0x0059BAE8, field:this:0x00000050, source:raw]
    // GUARD: If a3 (v10) is non-zero and sub_587F64(this[20], v10, 1) returns non-zero, select the failure path (stream filter/check stage). [callee:0x00587F64, field:this:0x00000050, source:raw]
    // CALL: StringStreamReadWithMaskCheck(this[20], &v15) reads the formatted record from the string stream into v15/v16; a non-zero return selects the failure path. [callee:0x0058801D, field:this:0x00000050, source:raw]
    // CALL: Failure path: v13 = sub_59942B(&a3, -1) builds the default/fallback result struct. [callee:0x0059942B, source:raw]
    // GUARD: Success path: if this[17] (buffer object at +0x44) is non-null, set this[16] (+0x40) = a7 and reset the buffer via BufferTruncationShrink(v12, 0, 0xFFFFFFFF). [field:this:0x00000044, field:this:0x00000040, callee:0x00599348, source:raw]
    // ASSIGNMENT: Success path: assemble the result record with a3 = 0, a5 = v15, a6 = v16, a7 = this[16]; v13 = &a3. [field:this:0x00000040, source:raw]
    // RETURN: qmemcpy(a2, v13, 0x18) copies the 0x18-byte result struct into output buffer a2 and returns a2. [function:0x0059A221, source:raw]

    // Conservative worker pseudocode:
    //   v15 = a5; v16 = a6; v10 = a3;
    //   if (this[20] == 0 || FileIOForwardingWrapper(this[20], &v15) || (v10 && sub_587F64(this[20], v10, 1)) || StringStreamReadWithMaskCheck(this[20], &v15))
    //       v13 = sub_59942B(&a3, -1);
    //   else {
    //       if (this[17]) { this[16] = a7; BufferTruncationShrink(this[17], 0, 0xFFFFFFFF); }
    //       a3 = 0; a5 = v15; a6 = v16; a7 = this[16]; v13 = &a3;
    //   }
    //   qmemcpy(a2, v13, 0x18);
    //   return a2;
    // UNRESOLVED: Global dword_5B9C38 is listed as a read global in the packet but never appears in the raw source text; its exact role (likely a setup constant for one of the callees) is unplaceable from this packet.
}
