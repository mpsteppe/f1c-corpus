// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042DE10
// Canonical corpus name: GearRatioConfigFileReader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GearRatioConfigFileReader_0042de10.c

void UnknownObject::GearRatioConfigFileReader()
{
    // Gear-ratio configuration file reader. Opens a2 with mode aR, frees prior state via ScoreSlotDeallocator, then scans the file line by line for the "[GearRatios]" and "[FinalDrive]" sections, counting ratio tokens (sub_565760 with aRatio) into this[0] (gear count) and this[2] (final-drive count). It then allocates two buffers (this[1] and this[3], 8 bytes per entry) and rewinds the file (sub_587F64) for a second pass that fills the buffers with ratio value pairs, plus a bevel scalar via aBevel into this[4]/this[5] during the FinalDrive section, and arranges each filled buffer with sub_5890AA using element size 8 and the loc_42DC1F+1 callback. Returns the file-close result.
    // ASSIGNMENT: Zero the 384-byte line buffer v23 and reset per-line state locals v18/v20/v21/v22, with v19 = 1. [source:raw]
    // CALL: Release any previously allocated ratio/final-drive buffers: ScoreSlotDeallocator(this). [callee:0x0042DDD0, source:raw]
    // CALL: Open the config file: result = sub_587DB0(a2, aR). [callee:0x00587DB0, global:0x005C36F0, source:raw]
    // GUARD: When the file handle is null (result == 0), return the null result immediately. [source:raw]
    // LOOP: First pass: read lines via FileReadUntilNewline(v23, 384, handle); for lines that sub_5651B0 reports as value tokens, match section headers with sub_587C20. [callee:0x00587CA0, callee:0x005651B0, callee:0x00587C20, source:raw]
    // ASSIGNMENT: On matching aGearRatios, reset the gear count: *this = 0. [global:0x005C36E0, field:this:0x00000000, source:raw]
    // LOOP: Count gear ratios: while lines remain, sub_5651B0 values 1 or 4 terminate the section; a value token parsed by sub_565760(aRatio, v15, v16, 0, 0) increments *this. [global:0x005C36D8, callee:0x00565760, field:this:0x00000000, source:raw]
    // ASSIGNMENT: On matching aFinalDrive, reset the final-drive count: this[2] = 0. [global:0x005C36C8, field:this:0x00000008, source:raw]
    // LOOP: Count final-drive ratios the same way, incrementing this[2]. [global:0x005C36D8, callee:0x00565760, field:this:0x00000008, source:raw]
    // CALL: Allocate the gear buffer: this[1] = OperatorNewNhMallocWrapper(8 * *this). [callee:0x00587C03, field:this:0x00000004, field:this:0x00000000, source:raw]
    // CALL: Allocate the final-drive buffer: this[3] = OperatorNewNhMallocWrapper(8 * this[2]). [callee:0x00587C03, field:this:0x0000000C, field:this:0x00000008, source:raw]
    // CALL: Rewind/reseat the file for the second pass: sub_587F64(handle, 0, 0). [callee:0x00587F64, source:raw]
    // LOOP: Second pass: re-read lines; on the aGearRatios section, parse value pairs with sub_565760(aRatio, v8 + this[1], v8 + this[1] + 4, 0, 0) advancing v8 by 8 per successful pair; on aFinalDrive, also parse the bevel scalar with sub_565760(aBevel, this + 4, this + 5, 0, 0). [callee:0x00587CA0, callee:0x005651B0, global:0x005C36E0, global:0x005C36C8, global:0x005C36D8, global:0x005C36C0, callee:0x00565760, field:this:0x00000004, field:this:0x0000000C, source:raw]
    // CALL: After each section fill, arrange the buffer: sub_5890AA(buffer, count, 8, (char*)&loc_42DC1F + 1). [callee:0x005890AA, source:raw]
    // RETURN: Return FileCloseWithLock(handle). [callee:0x00587D02, source:raw]

    // Conservative worker pseudocode:
    //   int GearRatioConfigFileReader(int* this, char* a2) {
    //     char line[384] = {0};
    //     ScoreSlotDeallocator(this);
    //     int f = sub_587DB0(a2, aR);
    //     if (!f) return f;
    //     if (FileReadUntilNewline(line, 384, f)) {
    //       do {
    //         if (!sub_5651B0(buf)) {
    //           if (sub_587C20(line, aGearRatios)) {
    //             this[0] = 0;
    //             while (FileReadUntilNewline(line, 384, f)) {
    //               t = sub_5651B0(buf); if (t == 1 || t == 4) break;
    //               if (!t && sub_565760(aRatio, &x, &y, 0, 0)) ++this[0];
    //             }
    //           } else if (sub_587C20(line, aFinalDrive)) {
    //             this[2] = 0;
    //             while (FileReadUntilNewline(line, 384, f)) {
    //               t = sub_5651B0(buf); if (t == 1 || t == 4) break;
    //               if (!t && sub_565760(aRatio, &x, &y, 0, 0)) ++this[2];
    //             }
    //           }
    //         }
    //       } while (FileReadUntilNewline(line, 384, f));
    //     }
    //     this[1] = OperatorNewNhMallocWrapper(8 * this[0]);
    //     this[3] = OperatorNewNhMallocWrapper(8 * this[2]);
    //     sub_587F64(f, 0, 0);
    //     while (FileReadUntilNewline(line, 384, f)) {
    //       if (!sub_5651B0(buf)) {
    //         if (sub_587C20(line, aGearRatios)) {
    //           while (FileReadUntilNewline(line, 384, f)) {
    //             t = sub_5651B0(buf); if (t == 1 || t == 4) break;
    //             if (!t && sub_565760(aRatio, this[1]+off, this[1]+off+4, 0, 0)) off += 8;
    //           }
    //           sub_5890AA(this[1], this[0], 8, &loc_42DC1F + 1);
    //         } else if (sub_587C20(line, aFinalDrive)) {
    //           while (FileReadUntilNewline(line, 384, f)) {
    //             t = sub_5651B0(buf); if (t == 1 || t == 4) break;
    //             if (!t) {
    //               sub_565760(aBevel, this + 4, this + 5, 0, 0);
    //               if (sub_565760(aRatio, this[3]+off, this[3]+off+4, 0, 0)) off += 8;
    //             }
    //           }
    //           sub_5890AA(this[3], this[2], 8, &loc_42DC1F + 1);
    //         }
    //       }
    //     }
    //     return FileCloseWithLock(f);
    //   }
    // UNRESOLVED: Global byte_42DC20 appears in the packet global list but is not a named reference in the decompiled body; existing analysis labels it the section-start token.
    // UNRESOLVED: The loc_42DC1F+1 callback passed to sub_5890AA is a code-adjacent string/byte pointer; the operation sub_5890AA performs (arrange/sort vs normalization) is unverified.
    // UNRESOLVED: sub_565760's return semantics (success boolean vs parsed count) is inferred from the ++count pattern and not independently established.
    // UNRESOLVED: The bevel scalar written via sub_565760(aBevel, this + 4, this + 5, 0, 0) lands at this[4]/this[5], which are beyond the four packet-documented fields (this 0x0/0x4/0x8/0xC are the documented dword fields this[0..3]).
}
