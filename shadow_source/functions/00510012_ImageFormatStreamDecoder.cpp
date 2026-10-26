// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00510012
// Canonical corpus name: ImageFormatStreamDecoder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ImageFormatStreamDecoder_00510012.c

void UnknownObject::ImageFormatStreamDecoder()
{
    // State-machine-driven frame decoder: consumes a byte stream through a refillable stream object (at a2+20) and parses an 8-byte header (big-endian 16-bit length, a metadata byte, big-endian 16-bit width and height, and an element count), then decodes count elements of a packed format (3 stream bytes per element) into a caller-allocated element array of 84-byte (21 dword) records, publishing each element's color vector into a current-color field. Header validity, width/height/count guards, and a length-vs-count consistency check route to vtable error handlers with distinct state codes; on success the stream position is persisted back into the stream object. Called from CommandDispatchStateMachine (0x0051126A).
    // ASSIGNMENT: Load the stream object v3 = *(a2 + 20) and snapshot its current buffer (v3[0]) and remaining count (v3[1]); store the two argument flag bytes at *(a2 + 200) = a1 and *(a2 + 201) = a3. [source:raw, function:0x00510012]
    // GUARD: Stream refill guard (repeatable): when the remaining count is zero, call the refill callback v3[3](a2); if it returns zero the decode fails returning 0, otherwise re-snapshot the new buffer and remaining count from the stream object. [source:raw]
    // CALCULATION: Read the header length as a big-endian 16-bit value: first stream byte shifted into the high byte (v40 = byte1 << 8) added to the second byte (v41 = byte2 + v40); derive the body length v42 = v41 - 8. [source:raw]
    // ASSIGNMENT: Read the third stream byte into the metadata field *(a2 + 192) = v9. [source:raw]
    // CALCULATION: Read width and height as big-endian 16-bit values: width *(a2 + 28) = (byte4 << 8) + byte5 and height *(a2 + 24) = (byte6 << 8) + byte7. [source:raw]
    // ASSIGNMENT: Read the eighth stream byte as the element count *(a2 + 32) = *v16. [source:raw]
    // ASSIGNMENT: Publish the header to the caller object: v18 at (*(a2)) + 24 receives [*(a2 + 376), *(a2 + 24), *(a2 + 28), *(a2 + 32)] (value, height, width, count); set the state code at (*(a2)) + 20 to 99 and notify via the vtable +4 call (a2, 1). [source:raw]
    // GUARD: Decoded-flag guard: when the byte at (*(a2 + 400)) + 81 is set, set the state code to 57 and invoke the vtable slot 0 handler (a2). [source:raw]
    // GUARD: Validity guard: when width or height is zero, or count <= 0, set the state code to 31 and invoke the vtable slot 0 handler (a2). [source:raw]
    // GUARD: Length consistency guard: when the body length v42 != 3 * count, set the state code to 9 and invoke the vtable slot 0 handler (a2). [source:raw]
    // GUARD: Buffer allocation: when *(a2 + 196) is null, allocate the element array through the allocator vtable at (a2 + 4) slot 0 with (a2, 1, 84 * count) and store the result at *(a2 + 196). [source:raw]
    // LOOP: Element decode loop: for index v28 in [0, count), write the index into the element record at v20[1], stream-read a byte into v20[0] (primary color), stream-read a byte split into v20[2] = (byte >> 4) & 0xF and v20[3] = byte & 0xF, stream-read a byte into v20[4], publish the element color vector into the current-color field (v27[0..3] at (*(a2)) + 24), set the state code to 100, notify via the vtable +4 call (a2, 1), and advance the element pointer by 21 dwords. [source:raw]
    // ASSIGNMENT: Finalize the decode: set the decoded flag byte at (*(a2 + 400)) + 81 to 1 and persist the stream position back into the stream object (v3[1] = remaining count, *v3 = current buffer). [source:raw]
    // RETURN: Return 1 on a completed decode; return 0 only when a stream refill callback fails. [source:raw, abi:lead]

    // Conservative worker pseudocode:
    //   int sub_510012(char a1, int a2, char a3) {
    //     v3 = *(void***)(a2 + 20);
    //     *(BYTE*)(a2 + 200) = a1; *(BYTE*)(a2 + 201) = a3;
    //     cur = v3[0]; rem = v3[1];
    //     if (!rem) { if (!v3[3](a2)) return 0; cur = v3[0]; rem = v3[1]; }
    //     len = (*cur++) << 8; rem--;
    //     if (!rem) { if (!v3[3](a2)) return 0; cur = v3[0]; rem = v3[1]; }
    //     len += *cur++; rem--;
    //     if (!rem) { if (!v3[3](a2)) return 0; cur = v3[0]; rem = v3[1]; }
    //     *(DWORD*)(a2 + 192) = *cur++; rem--;
    //     width = (*cur++ << 8);
    //     if (!rem) { if (!v3[3](a2)) return 0; cur = v3[0]; rem = v3[1]; }
    //     width += *cur++; rem--;
    //     height = (*cur++ << 8);
    //     if (!rem) { if (!v3[3](a2)) return 0; cur = v3[0]; rem = v3[1]; }
    //     height += *cur++; rem--;
    //     if (!rem) { if (!v3[3](a2)) return 0; cur = v3[0]; rem = v3[1]; }
    //     count = *cur++; rem--;
    //     body = len - 8;
    //     dst = (*(DWORD*)a2) + 24;
    //     dst[0] = *(DWORD*)(a2 + 376); dst[1] = height; dst[2] = width; dst[3] = count;
    //     *(DWORD*)((*(DWORD*)a2) + 20) = 99;
    //     (*(void(**)(int,int))(*(DWORD*)a2 + 4))(a2, 1);
    //     if (*(BYTE*)(*(DWORD*)(a2 + 400) + 81)) { *(DWORD*)(*(DWORD*)a2 + 20) = 57; (**(void(**)(int))(*(DWORD*)a2))(a2); }
    //     if (!width || !height || count <= 0) { *(DWORD*)(*(DWORD*)a2 + 20) = 31; (**(void(**)(int))(*(DWORD*)a2))(a2); }
    //     if (body != 3 * count) { *(DWORD*)(*(DWORD*)a2 + 20) = 9; (**(void(**)(int))(*(DWORD*)a2))(a2); }
    //     if (!*(DWORD*)(a2 + 196))
    //       *(DWORD*)(a2 + 196) = (**(int(**)(int,int,int))(a2 + 4))(a2, 1, 84 * count);
    //     elem = *(DWORD**)(a2 + 196);
    //     for (i = 0; i < count; ++i) {
    //       elem[1] = i;
    //       r = read_byte(); elem[0] = r;
    //       b = read_byte(); elem[2] = (b >> 4) & 0xF; elem[3] = b & 0xF;
    //       a = read_byte(); elem[4] = a;
    //       dst[0] = elem[0]; dst[1] = elem[2]; dst[2] = elem[3]; dst[3] = elem[4];
    //       *(DWORD*)(*(DWORD*)a2 + 20) = 100;
    //       (*(void(**)(int,int))(*(DWORD*)a2 + 4))(a2, 1);
    //       elem += 21;
    //     }
    //     *(BYTE*)(*(DWORD*)(a2 + 400) + 81) = 1;
    //     v3[1] = rem; *v3 = cur;
    //     return 1;
    //   }
    // UNRESOLVED: The stream refill callback (v3[3]), the vtable dispatch handlers at (*(a2)) slot 0 and +4, and the allocator vtable at (a2 + 4) slot 0 are indirect calls with no static callee addresses in evidence.
    // UNRESOLVED: The semantics of the metadata byte at *(a2 + 192), the source value at *(a2 + 376), and the decoded-flag object at (*(a2 + 400)) + 81 are inferred from usage only.
    // UNRESOLVED: The 84-byte (21 dword) element record stride and the 3-bytes-per-element packed stream layout are derived from the loop arithmetic; the underlying pixel format is not confirmed.
    // UNRESOLVED: Only element indices 0..4 of the 21-dword record are written; the role of the remaining 16 dwords is unknown.
    // UNRESOLVED: The state codes 99/57/31/9/100 written to (*(a2)) + 20 are treated as opaque protocol values.
}
