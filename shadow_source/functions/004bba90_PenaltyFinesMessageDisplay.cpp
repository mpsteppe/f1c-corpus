// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BBA90
// Canonical corpus name: sub_4BBA90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BBA90_004bba90.c

void UnknownObject::PenaltyFinesMessageDisplay()
{
    // Displays a 'Fined US <amount> <name>' or 'Penalty <name>' message to the HUD. Guarded by this+0x30 (penalty-message-pending flag must be zero) and by the +13000 (0x32C8) flag of the penalty state object read at this+0x00. Depending on byte_7D0B10, either aFinedUs or aPenalty is resolved through the message table into the shared byte_5EC4CC buffer, the driver name a2 is looked up and copied in, the two token buffers are assembled with a fine amount (a3, integer-converted via CRTFtol) and rendered via TextLineWrappingAndRendering. The fine amount is accumulated into this[41] (this+0xA4).
    // GUARD: The penalty-message-pending flag at this+0x30 (DWORD index 12) must be zero for any message work; otherwise the function returns it unchanged [field:this:0x00000030, source:raw]
    // GUARD: Driver name argument a2 must be non-null before the penalty state object is dereferenced [source:raw]
    // GUARD: Penalty state object pointer is read from this+0x00; its +13000 (0x32C8) flag must be zero for the message to be displayed [field:this:0x00000000, field:obj:0x000032C8, source:raw]
    // GUARD: byte_7D0B10 selects the 'Fined US' message branch when non-zero, otherwise the 'Penalty' branch [global:0x007D0B10, source:raw]
    // CALL: Fined US branch: BinarySearchInStringTable resolves aFinedUs against the message table byte_5EC4C0 into the byte_5EC4CC buffer [callee:0x00423A00, global:0x005EC4C0, global:0x005D255C, global:0x005EC4CC]
    // LOOP: Character copy loop pushes aFinedUs bytes into byte_5EC4CC until the terminating NUL is copied [global:0x005D255C, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0 copies at most 63 bytes from byte_5EC4CC into the v11 stack buffer, which is then NUL-terminated [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: Driver name lookup: BinarySearchInStringTable resolves a2 against byte_5EC4C0; when found the byte_5EC4CC buffer is overwritten with strcpy(a2) [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0 copies at most 63 bytes from byte_5EC4CC into the v13 stack buffer, which is then NUL-terminated [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: CRTFtol converts the float fine amount a3 to an integer for message formatting [callee:0x00587BDC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck assembles the '%s%d %s' message from v11, the integer fine amount and v13 into the v15 buffer [callee:0x0058815F, source:raw]
    // CALL: Penalty branch: BinarySearchInStringTable resolves aPenalty against the message table byte_5EC4C0 into the byte_5EC4CC buffer [callee:0x00423A00, global:0x005EC4C0, global:0x005D2548, global:0x005EC4CC]
    // LOOP: Character copy loop pushes aPenalty bytes into byte_5EC4CC until the terminating NUL is copied [global:0x005D2548, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0 copies at most 63 bytes from byte_5EC4CC into the v11 stack buffer, which is then NUL-terminated [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: Driver name lookup: BinarySearchInStringTable resolves a2 against byte_5EC4C0; when found the byte_5EC4CC buffer is overwritten with strcpy(a2) [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0 copies at most 63 bytes from byte_5EC4CC into the v13 stack buffer, which is then NUL-terminated [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck assembles the '%s %s' message from v11 and v13 into the v15 buffer [callee:0x0058815F, source:raw]
    // CALL: TextLineWrappingAndRendering renders the formatted v15 message to the HUD via the resource at dword_7CD204 with arguments 3 and 16909060; its low byte becomes the return value [callee:0x0045BD10, global:0x007CD204, source:raw]
    // ASSIGNMENT: Accumulate the fine total: this[41] (this+0xA4) is set to a3 plus its previous value [field:this:0x000000A4, source:raw]
    // RETURN: Returns v4: the this+0x30 pending flag when message work was blocked, the render-result low byte when displayed, or zero; invoked by sub_4A5EA0, sub_4A5F20 and sub_4BCCC0 [function:0x004BBA90, caller:0x004A5EA0, caller:0x004A5F20, caller:0x004BCCC0, source:raw]

    // Conservative worker pseudocode:
    //   ret = *(int*)(this + 0x30);
    //   if (ret != 0) return ret;
    //   if (a2 != NULL) {
    //     obj = *(int*)this;
    //     if (*(int*)(obj + 13000) == 0) {
    //       if (byte_7D0B10 != 0) {
    //         if (BinarySearchInStringTable(byte_5EC4C0, aFinedUs, byte_5EC4CC)) copy aFinedUs into byte_5EC4CC;
    //         sub_587DD0(v11, byte_5EC4CC, 63);
    //         if (BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC)) strcpy(byte_5EC4CC, a2);
    //         sub_587DD0(v13, byte_5EC4CC, 63);
    //         StringFormatWithBufferOverflowCheck(v15, "%s%d %s", v11, CRTFtol(a3), v13);
    //       } else {
    //         if (BinarySearchInStringTable(byte_5EC4C0, aPenalty, byte_5EC4CC)) copy aPenalty into byte_5EC4CC;
    //         sub_587DD0(v11, byte_5EC4CC, 63);
    //         if (BinarySearchInStringTable(byte_5EC4C0, a2, byte_5EC4CC)) strcpy(byte_5EC4CC, a2);
    //         sub_587DD0(v13, byte_5EC4CC, 63);
    //         StringFormatWithBufferOverflowCheck(v15, "%s %s", v11, v13);
    //       }
    //       ret = (char)TextLineWrappingAndRendering(&dword_7CD204, v15, 3, 16909060);
    //     }
    //   }
    //   this[41] = a3 + this[41];
    //   return ret;
    // UNRESOLVED: Globals aSS_2 (0x005C5D30) and aSDS (0x005D2554) are flagged as referenced by the packet facts but appear nowhere in the raw decompiled source; their roles are not verifiable from this packet
    // UNRESOLVED: The meaning of the byte_7D0B10 flag (which message flavor is emitted) is not documented inside this function
    // UNRESOLVED: The +13000 (0x32C8) flag of the penalty state object and the caller semantics of this+0x30 are derived from the skeleton fill, not from this function's own code
}
