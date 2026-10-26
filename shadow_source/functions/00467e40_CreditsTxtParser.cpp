// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00467E40
// Canonical corpus name: CreditsTxtParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CreditsTxtParser_00467e40.c

void UnknownObject::CreditsTxtParser()
{
    // Builds the full path to "credits.txt" (using the override path pointer dword_5EC408 when set, otherwise the default directory byte_5EA438), opens it with AudioStreamOpen, then reads it line-by-line into a 256-byte stack buffer. Each line is truncated at the first occurrence of the delimiter (asc_5C30B0), turned into a string node and a list node via the allocation helper, and appended to a singly linked list whose head, tail, current and count live at this+0xF8, this+0xFC, this+0x100 and this+0x104. Returns the result of the stack-struct cleanup helper over the 28-byte local v8. Called from MenuLayoutCalculator.
    // CALL: ZeroInitializeSmallStruct(v8): zero-initialize the 28-byte stack struct v8 used later by the cleanup helper. [callee:0x005668B0, source:raw]
    // ASSIGNMENT: Seed the 32-byte path buffer: v9[0] = byte_5EA438[0] and memset the remaining 29 bytes to 0; the 256-byte line buffer v10 is cleared at index 0. [global:0x005EA438, source:raw]
    // ASSIGNMENT: Choose the path base: v2 = dword_5EC408 (override path pointer); when dword_5EC408 is null the default directory byte_5EA438 is used instead. [global:0x005EC408, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v9, "%s%s" (aSS), v2, aCreditsTxt): compose the full path to credits.txt from the chosen base and the "credits.txt" suffix. [global:0x005BE860, global:0x005C6734, callee:0x0058815F, source:raw]
    // GUARD: Enter the parse loop only if AudioStreamOpen(v9, 1) succeeds AND the first line read through ConditionalDispatchBasedOnFlag(v10, 256) succeeds. [callee:0x00566B20, callee:0x00566CC0, source:raw]
    // LOOP: Repeat per line: process the current line and re-read via ConditionalDispatchBasedOnFlag(v10, 256); the loop continues while that read returns true. [callee:0x00566CC0, source:raw]
    // CALL: sub_587C20(v10, asc_5C30B0): locate the delimiter within the line; when a pointer v3 is returned, set *v3 = 0 to truncate the line at the delimiter. [callee:0x00587C20, global:0x005C30B0, source:raw]
    // CALL: OperatorNewNhMallocWrapper(8): allocate an 8-byte string node; when allocation succeeds initialize v4[0] = 0 and v4[1] = -1. [callee:0x00587C03, source:raw]
    // CALL: StringCopyWithBufferRealloc(v10): copy the truncated line into string storage; the return value is discarded in this decompiled body. [callee:0x00566650, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12): allocate a 12-byte list node; when allocation succeeds set v6[0] = v5 (pointer to the 8-byte string node), v6[4] = 0 (next pointer) and the byte at v6+8 = 1; otherwise v6 is treated as 0. [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Append the new list node: when this+0xF8 (head) already exists, set the current tail this+0xFC next pointer (+4) to v6; otherwise this+0xF8 = v6 and this+0x100 = v6. Then this+0xFC = v6 and increment this+0x104 (count). [field:this:0x000000F8, field:this:0x000000FC, field:this:0x00000100, field:this:0x00000104, source:raw]
    // RETURN: Return the result of SubCallWithConditionalFieldFree(v8), the cleanup helper over the 28-byte stack struct. [callee:0x005668D0, source:raw]

    // Conservative worker pseudocode:
    //   char path[32];
    //   path[0] = byte_5EA438[0]; memset(&path[1], 0, 29);
    //   ZeroInitSmallStruct(v8);
    //   const char* base = dword_5EC408 ? (const char*)dword_5EC408 : byte_5EA438;
    //   char line[256]; line[0] = 0;
    //   StringFormatWithBufferOverflowCheck(path, "%s%s", base, aCreditsTxt);
    //   if (AudioStreamOpen(path, 1) && ConditionalDispatchBasedOnFlag(line, 256)) {
    //       do {
    //           char* delim = sub_587C20(line, asc_5C30B0);
    //           if (delim) *delim = 0;
    //           node8 = OperatorNewNhMallocWrapper(8);
    //           if (node8) {
    //               node8[0] = 0; node8[1] = -1;
    //               StringCopyWithBufferRealloc(line);
    //               node12 = OperatorNewNhMallocWrapper(12);
    //               if (node12) { node12[0] = node8; node12[1] = 0; ((char*)node12)[8] = 1; }
    //               else node12 = 0;
    //               if (this[62]) this[63][1] = node12;
    //               else { this[62] = node12; this[64] = node12; }
    //               this[63] = node12;
    //               ++this[65];
    //           }
    //       } while (ConditionalDispatchBasedOnFlag(line, 256));
    //   }
    //   return SubCallWithConditionalFieldFree(v8);
    // UNRESOLVED: Packet metadata flags this+0x104 as read-only (rw "R") while the decompiled body executes ++this[65]; the discrepancy between the increment and the R label is unresolved.
    // UNRESOLVED: StringCopyWithBufferRealloc(v10) returns a value that is discarded in the decompiled body; whether the truncated line is copied into the 8-byte node, the 12-byte node, or a separately allocated string is unresolved.
    // UNRESOLVED: The 8-byte node layout (v4[0] = 0, v4[1] = -1) has no packet-explainable meaning; its exact role in the credits text storage is unresolved.
    // UNRESOLVED: The 12-byte node tail field set through this[63] + 4 and the byte flag at v6 + 8 (= 1) are only partially understood; the flag meaning is unresolved.
    // UNRESOLVED: dword_5EC408 is treated as an override path pointer (preferred over byte_5EA438) but the source and lifecycle of that override are not evidenced in this packet.
    // UNRESOLVED: The mode argument 1 passed to AudioStreamOpen and the exact behavior of the file/line read helper ConditionalDispatchBasedOnFlag are unresolved from this body alone.
    // UNRESOLVED: The 28-byte stack struct v8 passed to SubCallWithConditionalFieldFree has an unknown type and cleanup role; only its zero-initialization is evidenced.
}
