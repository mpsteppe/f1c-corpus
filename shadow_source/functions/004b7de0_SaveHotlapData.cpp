// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B7DE0
// Canonical corpus name: sub_4B7DE0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B7DE0_004b7de0.c

void UnknownObject::SaveHotlapData()
{
    // Saves a hotlap (qualifying/record lap) data file to disk. Builds a .HOT file path from this[451] (base name), a player-vehicle lap time (dword_7C54E8+16540) and a helper float (dword_7C54E8+16564), appends the .HOT extension plus the message-buffer content and a FileName prefix, then opens the file via sub_566940, serializes vehicle physics state and a network buffer into the file context, and closes/cleans up. Returns 1 only when both serialization calls succeed; skips entirely when the lap time is -1.0 or non-positive.
    // GUARD: Skip the entire save when the lap-time float at dword_7C54E8+16540 equals -1.0 or is not greater than 0.0; result v2 stays 0. [source:raw, global:0x007C54E8]
    // ASSIGNMENT: Read v15 = float at dword_7C54E8+16564 and compute v16 = v15 + v14 (lap-time-related inputs passed to the serialization calls). [source:raw, global:0x007C54E8]
    // ASSIGNMENT: Select base name string: this[451] pointer, falling back to byte_5EA438 when null, then strcpy into local buffer v18. [source:raw, field:this:0x0000070C, global:0x005EA438]
    // CALCULATION: Truncate v18 at its last '.' character (strip any existing file extension) by walking back from the end; stops when '.' is found or the buffer start is reached. [source:raw]
    // ASSIGNMENT: Append the 16-bit word word_5C32D8 ('.HOT' extension literal) at the end of v18. [source:raw, global:0x005C32D8]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aHotLap, byte_5EC4CC); when it reports a hit, copy the aHotLap string into the byte_5EC4CC message buffer. [source:raw, callee:0x00423A00, global:0x005D2464, global:0x005EC4C0, global:0x005EC4CC]
    // CALL: strcat(v18, byte_5EC4CC) appends the (possibly hotlap-labelled) buffer content to the path. [source:raw, global:0x005EC4CC]
    // ASSIGNMENT: Prepend FileName (5 bytes: one DWORD plus one trailing CHAR) to v18 by copying it backward into the position just before the current end. [source:raw, global:0x005BE714]
    // CALL: ZeroInitSmallStruct(v17) zero-initializes the file-operation context struct v17. [source:raw, callee:0x005668B0]
    // CALCULATION: Map this[617] (session phase / file-type enum) to a file-type index: 0..3 pass through unchanged, any other value becomes 4. Compiled via jump table jpt_4B7F31. [source:raw, field:this:0x000009A4, global:0x004B8000]
    // CALL: sub_566940(v18, v9, 0, 1) opens/creates the hotlap file for the built path; a nonzero return permits the write phase, a zero return skips the write phase and leaves v2 0. [source:raw, callee:0x00566940]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aSavingHotlap, byte_5EC4CC); when it reports a hit, copy the aSavingHotlap string into the byte_5EC4CC message buffer. [source:raw, callee:0x00423A00, global:0x005D2454, global:0x005EC4C0, global:0x005EC4CC]
    // CALL: SessionTypeGuard(&unk_7CE24D, v10, byte_5EC4CC) validates the current session type permits hotlap saving (v10 is uninitialized in the decompiled source). [source:raw, callee:0x004A0E70, global:0x007CE24D, global:0x005EC4CC]
    // CALL: VehicleForceAerodynamicsComputation(this, v17, v15, v16) serializes vehicle physics state into the file context; a zero result marks failure. [source:raw, callee:0x004B6A10]
    // CALL: NetworkBufferRead(this, this+441, v17, v15, v16) fills the file context from the this+441 buffer; success sets v2=1, failure leaves/sets v2=0. [source:raw, callee:0x004B7C80]
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(v17) closes the opened file handle after the write phase. [source:raw, callee:0x00566B90]
    // CALL: SubCallWithConditionalFieldFree(v17) performs conditional cleanup/free of the file-operation context struct. [source:raw, callee:0x005668D0]
    // RETURN: Return v2: 1 when both VehicleForceAerodynamicsComputation and NetworkBufferRead succeeded, otherwise 0 (including all early-exit and file-open-failure paths). [source:raw]

    // Conservative worker pseudocode:
    //   char SaveHotlapData(void* this) {
    //       float lapTime = *(float*)(dword_7C54E8 + 16540);   // player vehicle lap time
    //       char result = 0;
    //       if (lapTime == -1.0f || lapTime <= 0.0f) return result;
    //       const char* base = this[451] ? (const char*)this[451] : byte_5EA438;
    //       char path[512]; strcpy(path, base);
    //       truncateAtLastDot(path);                 // strip existing extension
    //       *(WORD*)&path[strlen(path)] = word_5C32D8;  // append ".HOT"
    //       if (BinarySearchInStringTable(byte_5EC4C0, aHotLap, byte_5EC4CC))
    //           copyInto(byte_5EC4CC, aHotLap);
    //       strcat(path, byte_5EC4CC);
    //       prepend5Bytes(path, FileName);           // 1 DWORD + 1 CHAR prefix
    //       ZeroInitSmallStruct(&fileContext);
    //       int type = (this[617] >= 0 && this[617] <= 3) ? this[617] : 4;
    //       if (sub_566940(path, type, 0, 1)) {
    //           if (BinarySearchInStringTable(byte_5EC4C0, aSavingHotlap, byte_5EC4CC))
    //               copyInto(byte_5EC4CC, aSavingHotlap);
    //           SessionTypeGuard(&unk_7CE24D, v10, byte_5EC4CC);
    //           if (VehicleForceAerodynamicsComputation(this, &fileContext, v15, v16)
    //               && NetworkBufferRead(this, this + 441, &fileContext, v15, v16))
    //               result = 1;
    //           ConditionalFileHandleCloseWithFlagDispatch(&fileContext);
    //       }
    //       SubCallWithConditionalFieldFree(&fileContext);
    //       return result;
    //   }
    // UNRESOLVED: v10 passed to SessionTypeGuard is uninitialized in the decompiled source; likely a decompiler artifact of a missing read, actual argument indeterminate.
    // UNRESOLVED: Packet globals flt_59E440 and flt_59E670 are referenced in the packet but absent from the raw function body; roles unknown (analysis fill labels them ZeroThreshold / SentinelFlagConstant, both DERIVED).
    // UNRESOLVED: Packet global byte_5BE718 (analysis fill: HotlapDirPath, DERIVED) is absent from the raw function body.
    // UNRESOLVED: this+441 buffer passed to NetworkBufferRead has no field evidence ref in the packet; offset derives from this+441 (0x6E4) and is unverified.
    // UNRESOLVED: jpt_4B7F31 (0x004B8000) is the compiled switch jump table for the this[617] mapping; no separate semantic meaning beyond that switch.
}
