// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005119E9
// Canonical corpus name: sub_5119E9
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5119E9_005119e9.c

void UnknownObject::PNGFile_ParseChunks()
{
    // PNG image parser that first validates the 8-byte PNG signature (reading any missing header bytes through CallbackDispatchWithNullGuard and comparing against a reference with BoundedMemcmpAgainstReference), then iteratively reads 4-byte chunk lengths and 4-byte chunk types, dispatching IHDR, PLTE, IEND, gAMA, sRGB, tRNS and unknown chunks to per-chunk handlers. Terminates the loop on IDAT, then validates the chunk-state flags (color type 3 requires PLTE before IDAT) and records the IDAT chunk size. Uses longjmp-based error reporting (GuardedCallWithLongjmp) for signature, PLTE and IHDR violations.
    // GUARD: Signature stage: read the byte counter v3 = this+284 and proceed only while fewer than 8 signature bytes have been consumed. [field:this:0x0000011C, source:raw]
    // CALL: CallbackDispatchWithNullGuard(a1, a2 + 32 + v3, 8 - v3): fetch the missing signature bytes into the input buffer. [callee:0x00513BD1, source:raw]
    // ASSIGNMENT: Mark all 8 signature bytes as consumed: this+284 = 8. [field:this:0x0000011C, source:raw]
    // CALL: BoundedMemcmpAgainstReference(a2 + 32, v4, v5): compare the received signature against the expected PNG signature; a non-zero result is a mismatch. [callee:0x00513C38, source:raw]
    // GUARD: On signature mismatch, GuardedCallWithLongjmp reports 'Not a PNG file' when fewer than 4 signature bytes were present, otherwise 'PNG file corrupted by ASCII conversion'. [callee:0x00511869, global:0x005AF350, global:0x005AF378, source:raw]
    // LOOP: Chunk iteration loop: repeatedly read a 4-byte length, decode the chunk type into the buffer at this+268 and dispatch to a per-chunk handler until an IDAT chunk terminates the loop. [field:this:0x0000010C, source:raw]
    // CALL: CallbackDispatchWithNullGuard(v2, &a1, 4): read the 4-byte chunk length field into the local buffer. [callee:0x00513BD1, source:raw]
    // CALL: ByteArrayToInt(&a1): decode the 4-byte length into the chunk length v7. [callee:0x00517F35, source:raw]
    // CALL: AnimationHandleAlloc(v2): allocate/refresh the per-chunk scratch state. [callee:0x00513CD8, source:raw]
    // CALL: sub_517F58(v2, v2 + 268, 4): copy the 4-byte chunk type tag into the chunk-type buffer at this+268. [callee:0x00517F58, field:this:0x0000010C, source:raw]
    // GUARD: Dispatch the chunk type tag at this+268: when it equals 'IHDR', call sub_5188B4(v2, a2, v7) to parse the header chunk. [callee:0x005188B4, field:this:0x0000010C, global:0x005AF264, source:raw]
    // GUARD: Dispatch on the chunk type tag: when it equals 'PLTE', call sub_518AAA(v2, a2, v7) to parse the palette chunk. [callee:0x00518AAA, global:0x005AF27C, source:raw]
    // GUARD: Dispatch on the chunk type tag: when it equals 'IEND', call sub_518BD4(v2, a2, v7) to handle the end marker. [callee:0x00518BD4, global:0x005AF274, source:raw]
    // GUARD: Dispatch on the chunk type tag: 'IDAT' terminates the loop; otherwise 'gAMA' -> sub_518C1E, 'sRGB' -> sub_518D29, 'tRNS' -> sub_518E18, and any other tag -> sub_518FCF(v2, a2, v7). [callee:0x00518C1E, callee:0x00518D29, callee:0x00518E18, callee:0x00518FCF, global:0x005AF26C, global:0x005AF284, global:0x005AF28C, global:0x005AF294, source:raw]
    // GUARD: Post-loop chunk-state validation: read the flags at this+88; when bit 0 (IHDR seen) is set and the color type at this+278 equals 3 (indexed) while bit 1 (PLTE seen) is clear, GuardedCallWithLongjmp reports 'Missing PLTE before IDAT'; otherwise it reports 'Missing IHDR before IDAT'. [callee:0x00511869, field:this:0x00000058, field:this:0x00000116, global:0x005AF318, global:0x005AF334, guard:0, source:raw]
    // ASSIGNMENT: Record chunk parse state: set bit 2 of the flags word (this+88 |= 4) and store the IDAT chunk length into this+252. [field:this:0x00000058, field:this:0x000000FC, source:raw]
    // RETURN: Return the flags word after validation. [source:raw]

    // Conservative worker pseudocode:
    //   if (*(this+284) < 8) {
    //       CallbackDispatchWithNullGuard(this, a2 + 32 + *(this+284), 8 - *(this+284));
    //       *(this+284) = 8;
    //       if (BoundedMemcmpAgainstReference(a2 + 32, v4, v5)) {
    //           if (v4 < 4 && BoundedMemcmpAgainstReference(a2 + 32, v4, v5 - 4))
    //               GuardedCallWithLongjmp(this, "Not a PNG file");
    //           else
    //               GuardedCallWithLongjmp(this, "PNG file corrupted by ASCII conversion");
    //       }
    //   }
    //   loop {
    //       CallbackDispatchWithNullGuard(this, &a1, 4);
    //       v7 = ByteArrayToInt(&a1);
    //       AnimationHandleAlloc(this);
    //       sub_517F58(this, this + 268, 4);
    //       if (*v6 == 'IHDR') { sub_5188B4(this, a2, v7); continue; }
    //       if (*v6 == 'PLTE') { sub_518AAA(this, a2, v7); continue; }
    //       if (*v6 == 'IEND') { sub_518BD4(this, a2, v7); continue; }
    //       if (*v6 == 'IDAT') break;
    //       if (*v6 == 'gAMA') sub_518C1E(this, a2, v7);
    //       else if (*v6 == 'sRGB') sub_518D29(this, a2, v7);
    //       else if (*v6 == 'tRNS') sub_518E18(this, a2, v7);
    //       else sub_518FCF(this, a2, v7);
    //   }
    //   result = *(this+88);
    //   if (result & 1) {
    //       if (*(this+278) == 3 && !(result & 2))
    //           GuardedCallWithLongjmp(this, "Missing PLTE before IDAT");
    //   } else
    //       GuardedCallWithLongjmp(this, "Missing IHDR before IDAT");
    //   *(this+88) |= 4;
    //   *(this+252) = v7;
    //   return result;
    // UNRESOLVED: The eight per-chunk handler functions (sub_517F58, sub_5188B4, sub_518AAA, sub_518BD4, sub_518C1E, sub_518D29, sub_518E18, sub_518FCF) are separate functions not analyzed here; their internal behavior is out of scope for this packet.
    // UNRESOLVED: The globals named aIhdr, aIdat, aIend, aPlte, aGama, aSrgb, aTrns, aMissingPlteBef, aMissingIhdrBef, aPngFileCorrupt and aNotAPngFile are treated as the 4-byte chunk tags and error strings shown in the raw source; the actual byte contents of the strings are not in the packet.
    // UNRESOLVED: The sole static caller sub_50210E (0x0050210E) is not examined here; the enclosing object type is UnknownObject.
    // UNRESOLVED: The fill names this function PNGFile_ParseChunks; the chunk-tag comparisons in the raw source use immediate string constants ('IHDR', 'PLTE', etc.) which the extractor has attributed to the a* globals.
}
