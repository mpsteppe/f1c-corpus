// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005105BF
// Canonical corpus name: JPEGMarkerParsing
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/JPEGMarkerParsing_005105bf.c

void UnknownObject::JPEGMarkerParsing()
{
    // Parses a JFIF (JPEG File Interchange Format) APP0 marker segment from a byte stream. The stream state is read from this+0x14 (buffer read pointer at stream+0x0, bytes remaining at stream+0x4, refill callback at stream+0xC); the two big-endian length bytes are merged into a segment data length (minus 2), then at least 14 header bytes are consumed into a stack buffer. When the header starts with the "JFIF\0" signature, the parser stores the density units byte, big-endian X and Y densities, and thumbnail dimensions into this+0x100/0x101/0x102/0x104 and the dispatcher object at obj+0x18/0x1C/0x20, driving a state machine through obj+0x14 (states 76, 86, 87, 88, 89, 115) and issuing parameterized dispatch calls through the obj+0x4 callback. Non-JFIF or too-short segments take state 76. The stream read position is persisted back to stream+0x0/stream+0x4 and any unconsumed bytes are skipped before returning 1.
    // ASSIGNMENT: Load the byte stream state struct v2 from a1[5] (this+0x14); it holds the buffer read pointer at stream+0x0, the bytes-remaining count at stream+0x4, and a refill callback at stream+0xC. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Read stream[0] as the current buffer read pointer and stream[1] as the number of bytes remaining. [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // GUARD: Guard: if no bytes remain, invoke the refill callback at stream+0xC (v2[3])(a1); on a zero result the function returns 0, then re-read the buffer pointer and remaining count. [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // CALCULATION: Build the high byte of the segment length: v29 = (*v3 << 8), placing the current byte in the big-endian high position; advance the read pointer by 1. [field:*(this+0x14):0x00000000, source:raw]
    // GUARD: Guard: if decrementing the remaining count left nothing, refill again via the stream+0xC callback; on failure return 0, then reload the buffer pointer and remaining count. [field:this:0x00000014, source:raw]
    // CALCULATION: Merge the second byte: v29 = (byte0 << 8) + byte1 - 2, i.e. the two big-endian length bytes minus the 2 marker-length bytes, giving the remaining segment data length; advance the read pointer by 1. [field:*(this+0x14):0x00000000, source:raw]
    // GUARD: Guard: when the computed segment data length is below 14, the segment is too short for a JFIF header; set the dispatcher state obj+0x14 = 76 and obj+0x18 = v29 (remaining length) and skip the JFIF path. [field:this:0x00000000, field:obj:0x00000014, field:obj:0x00000018, source:raw]
    // LOOP: Loop: consume up to 14 header bytes into the stack buffer v19, refilling through the stream+0xC callback whenever the local remaining count hits zero; on refill failure return 0. [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // CALCULATION: After the header loop, subtract the 14 consumed bytes from the segment data length (v29 -= 14). [source:raw]
    // GUARD: Guard: JFIF signature check — the first five header bytes must be 74('J'), 70('F'), 73('I'), 70('F'), 0. [source:raw]
    // GUARD: Guard (major version 1 path): when the major version byte v20 equals 1 and the minor version byte v21 is greater than 2, set obj+0x14 = 88, obj+0x18 = 1, obj+0x1C = v21 and dispatch through the obj+0x4 callback with argument 1. [field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, source:raw]
    // STATE_TRANSITION: Else (major version not 1): set obj+0x14 = 115, obj+0x18 = v20, obj+0x1C = v21 and dispatch through the obj+0x4 callback with argument -1. [field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, source:raw]
    // ASSIGNMENT: Store the JFIF density bytes: this+0x100 = 1 (density-present flag) and this+0x101 = v22 (density units byte). [field:this:0x00000100, field:this:0x00000101, source:raw]
    // CALCULATION: Compute the big-endian X density word (v23 << 8) + v24 and store it at this+0x102. [field:this:0x00000102, source:raw]
    // CALCULATION: Compute the big-endian Y density word (v25 << 8) + v26 and store it at this+0x104. [field:this:0x00000104, source:raw]
    // ASSIGNMENT: Mirror the parsed values onto the dispatcher object: obj+0x18 = X density, obj+0x1C = Y density, obj+0x20 = density units byte. [field:this:0x00000000, field:obj:0x00000018, field:obj:0x0000001C, field:obj:0x00000020, source:raw]
    // STATE_TRANSITION: Set obj+0x14 = 86 (densities accepted) and dispatch through the obj+0x4 callback with argument 1. [field:obj:0x00000004, field:obj:0x00000014, source:raw]
    // GUARD: Guard: when the thumbnail dimension word v27 is non-zero, set obj+0x14 = 89, obj+0x18 = low byte of v27 (thumbnail width), obj+0x1C = high byte of v27 (thumbnail height) and dispatch through the obj+0x4 callback with argument 1. [field:obj:0x00000004, field:obj:0x00000014, field:obj:0x00000018, field:obj:0x0000001C, source:raw]
    // GUARD: Guard: when the remaining segment length equals 3 * width * height (3 bytes per thumbnail pixel, using the low and high bytes of v27), jump to the finish label; otherwise set obj+0x14 = 87 (thumbnail data mismatch). [field:obj:0x00000014, source:raw]
    // STATE_TRANSITION: Non-JFIF branch: when the signature check fails, set obj+0x14 = 76 and obj+0x18 = v29 + 14 (restore the full segment length). [field:obj:0x00000014, field:obj:0x00000018, source:raw]
    // CALL: Final dispatch through the obj+0x4 callback with argument 1 before persisting the stream position. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Persist the stream read position: stream[0] = current buffer read pointer, stream[1] = remaining count, so later parsing resumes where this marker ended. [field:*(this+0x14):0x00000000, field:this:0x00000014, source:raw]
    // GUARD: Guard: when v29 is still positive, skip the remaining v29 bytes by calling the stream skip callback at a1[5] + 16 with argument v29. [field:this:0x00000014, source:raw]
    // RETURN: Return 1 (success) after the segment was parsed and the stream position was updated. [function:0x005105BF, source:raw]

    // Conservative worker pseudocode:
    //   // v2 = stream struct at a1[5] (this+0x14); v2[0]=read ptr, v2[1]=remaining, v2[3]=refill(a1)
    //   stream = *(void***)(this + 0x14);
    //   read_ptr = stream[0]; remaining = stream[1];
    //   if (!remaining && !stream[3](this)) return 0;
    //   len = (read_ptr[0] << 8) | read_ptr[1];  // two big-endian length bytes
    //   len -= 2;                                 // drop the 2 marker-length bytes
    //   if (len < 14) {
    //     obj_14 = 76; obj_18 = len;              // too short: state 76
    //   } else {
    //     read 14 header bytes into hdr[0..13] with stream[3] refill as needed;
    //     len -= 14;
    //     if (hdr[0]=='J' && hdr[1]=='F' && hdr[2]=='I' && hdr[3]=='F' && hdr[4]==0) {
    //       if (major == 1 && minor > 2) { obj_14=88; obj_18=1; obj_1C=minor; dispatch(1); }
    //       else if (major != 1)        { obj_14=115; obj_18=major; obj_1C=minor; dispatch(-1); }
    //       this+0x100 = 1; this+0x101 = units;
    //       this+0x102 = (x_density_hi << 8) | x_density_lo;
    //       this+0x104 = (y_density_hi << 8) | y_density_lo;
    //       obj_18 = this+0x102; obj_1C = this+0x104; obj_20 = units;
    //       obj_14 = 86; dispatch(1);
    //       if (thumb_dims) { obj_14=89; obj_18=thumb_w; obj_1C=thumb_h; dispatch(1); }
    //       if (len != 3 * thumb_w * thumb_h) obj_14 = 87;
    //     } else {
    //       obj_14 = 76; len += 14;               // non-JFIF: state 76, full length
    //     }
    //     obj_18 = len;
    //   }
    //   dispatch(1);
    //   stream[0] = read_ptr; stream[1] = remaining;
    //   if (len > 0) skip(stream, len);           // a1[5] + 16
    //   return 1;
    // UNRESOLVED: this+0x18, this+0x20 and this+0x24 are listed as accessed in the skeleton analysis but are not referenced anywhere in the raw source text; their roles (buffer position cache, table entry count, constant/limit) are not grounded in this packet.
    // UNRESOLVED: The refill callback at stream+0xC (v2[3]) and the skip callback at a1[5]+16 are indirect calls with no static callee address, so their implementations are unknown.
    // UNRESOLVED: The buffer backing the 14-byte header read is declared as _BYTE v19[5] in Hex-Rays with the trailing bytes aliased onto the separate locals v20..v26; the exact byte-to-local mapping beyond the JFIF signature is decompiler aliasing, not a proven layout.
    // UNRESOLVED: The interpretation of the thumbnail dimension word v27's low byte as width and high byte as height is DERIVED from the 3 * width * height remaining-length check, not independently confirmed.
    // UNRESOLVED: The meaning of the dispatch argument (1 versus -1) passed through the obj+0x4 callback is inferred from the call sites; the callback itself is opaque.
    // UNRESOLVED: States 87, 88, 89 and 115 are distinct state codes set before dispatch but their downstream semantics are handled by the dispatcher, which is outside this function.
}
