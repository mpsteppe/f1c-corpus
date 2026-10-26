// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8450
// Canonical corpus name: sub_4D8450
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D8450_004d8450.c

void UnknownObject::UpdateHudMessageDisplay()
{
    // Per-tick HUD display manager. Renders the HUD flag overlay first, advances timed HUD messages (message index this+0x0 with a float countdown timer at this+0xDC), expires broadcast messages (index this+0x4), and dispatches the display sub-objects they point at. Then scans an input action map (word_7CB21C, dword_7CB218 entries) to toggle broadcast display (dword_7CF638) and HUD on/off (dword_7CF788), resolving the matching display string through the string table into byte_5EC4CC and rendering it. Ends with a gated audio-device handoff dispatch when this+0xEC is set and the pointer at this+0xD8 is non-null.
    // CALL: Render HUD flag overlay: HUDFlagRendererMain(this) runs first on every tick. [callee:0x004D82D0, function:0x004D8450, source:raw]
    // GUARD: Message display block runs only when this+0x0 != 0xFFFFFFFF (-1, an active message exists) AND global flt_5EA4E8 <= 0.0. [guard:0, field:this:0x00000000, global:0x005EA4E8]
    // GUARD: Timer check on this+0xDC (float, init 1056964608 = 0.5f): if <= 0.0 the active message expires; otherwise decrement this+0xDC by dbl_8AFE98 each tick. [field:this:0x000000DC, global:0x008AFE98]
    // CALL: Message expiry path: dispatch the sub-object pointer at this+16+4*this+0x0 via VTableDispatchChain_7e00. [field:this:0x00000000, callee:0x004D7E00]
    // STATE_TRANSITION: When the dispatched sub-object returns 1, clear this+0x0 to -1 and reset timer this+0xDC to 1056964608 (0.5f); when the sub-object pointer is null, clear this+0x0 to -1. [field:this:0x00000000, field:this:0x000000DC, guard:0]
    // STATE_TRANSITION: Broadcast message index this+0x4: if != 0xFFFFFFFF (-1) and VTableDispatchChain_7e00(sub-object pointer at this+116+4*this+0x4) returns 1, clear this+0x4 to -1. [field:this:0x00000004, callee:0x004D7E00]
    // CALL: HUD on/off state index this+0x8: if != -1, dispatch sub-object pointer at this+12+4*this+0x8 via VTableDispatchChain_7e00 (return value ignored). [field:this:0x00000008, callee:0x004D7E00]
    // LOOP: Scan input action map word_7CB21C over dword_7CB218 entries; advance until an entry equals 3 (scan terminator) or the entry counter reaches dword_7CB218. An entry equal to 4 is the broadcast-toggle action. [global:0x007CB218, global:0x007CB21C]
    // STATE_TRANSITION: Toggle broadcast display flag: dword_7CF638 = (dword_7CF638 == 0). [global:0x007CF638]
    // STATE_TRANSITION: Broadcast OFF branch (flag became 0): call sub_4D8760(-1, 0); resolve aBroadcastDispl_0 via BinarySearchInStringTable(byte_5EC4C0, aBroadcastDispl_0, byte_5EC4CC) and copy it into byte_5EC4CC; format via sub_587DD0(v20, byte_5EC4CC, 127); render TextLineWrappingAndRendering(&dword_7CD204, v20, 3, 16909060). [callee:0x004D8760, callee:0x00423A00, global:0x005D4AA8, global:0x005EC4C0, global:0x005EC4CC, callee:0x00587DD0, callee:0x0045BD10, global:0x007CD204]
    // STATE_TRANSITION: Broadcast ON branch (flag became 1): resolve aBroadcastDispl via BinarySearchInStringTable(byte_5EC4C0, aBroadcastDispl, byte_5EC4CC), copy into byte_5EC4CC, format via sub_587DD0(v20, byte_5EC4CC, 127), render TextLineWrappingAndRendering(&dword_7CD204, v20, 3, 16909060). [callee:0x00423A00, global:0x005D4AC0, global:0x005EC4C0, global:0x005EC4CC, callee:0x00587DD0, callee:0x0045BD10, global:0x007CD204]
    // STATE_TRANSITION: After the action scan (terminated by entry value 3), toggle HUD display flag: dword_7CF788 = (dword_7CF788 == 0). [global:0x007CF788]
    // STATE_TRANSITION: HUD ON branch (flag became 1): resolve aHudOn via BinarySearchInStringTable(byte_5EC4C0, aHudOn, byte_5EC4CC), copy into byte_5EC4CC, format via sub_587DD0(v22, byte_5EC4CC, 127), render TextLineWrappingAndRendering(&dword_7CD204, v22, 3, 16909060). [callee:0x00423A00, global:0x005D4AA0, global:0x005EC4C0, global:0x005EC4CC, callee:0x00587DD0, callee:0x0045BD10, global:0x007CD204]
    // STATE_TRANSITION: HUD OFF branch (flag became 0): call IndexValidationSetter(-1); resolve aHudOff via BinarySearchInStringTable(byte_5EC4C0, aHudOff, byte_5EC4CC), copy into byte_5EC4CC, format via sub_587DD0(v22, byte_5EC4CC, 127), render TextLineWrappingAndRendering(&dword_7CD204, v22, 3, 16909060). [callee:0x004D8880, callee:0x00423A00, global:0x005D4A98, global:0x005EC4C0, global:0x005EC4CC, callee:0x00587DD0, callee:0x0045BD10, global:0x007CD204]
    // CALL: Audio-device handoff: if byte this+0xEC is set and pointer this+0xD8 is non-null, and dword_5EA518 != dword_5EA528 (or the object at dword_5EA528 + 52 != 1), return VTableDispatchChain_7e00(pointer at this+0xD8). [field:this:0x000000EC, field:this:0x000000D8, global:0x005EA518, global:0x005EA528, callee:0x004D7E00]
    // RETURN: Fall-through return of dword_7CB218 (the input action count). [global:0x007CB218]

    // Conservative worker pseudocode:
    //   HUDFlagRendererMain(this);
    //   if (this->msgIndex != -1 && flt_5EA4E8 <= 0.0) {
    //     if (timer(this+0xDC) <= 0.0) {
    //       ptr = subobject[this->msgIndex];
    //       if (ptr) { if (VTableDispatchChain_7e00(ptr) == 1) { this->msgIndex = -1; timer = 1056964608; } }
    //       else this->msgIndex = -1;
    //     } else timer(this+0xDC) -= dbl_8AFE98;
    //   }
    //   if (this->bcastIndex != -1 && VTableDispatchChain_7e00(subobject[this->bcastIndex]) == 1) this->bcastIndex = -1;
    //   if (this->hudIndex != -1) VTableDispatchChain_7e00(subobject[this->hudIndex]);
    //   v7 = word_7CB21C; v6 = 0;
    //   while (*v7 != 3) {
    //     if (*v7 == 4) {
    //       dword_7CF638 = (dword_7CF638 == 0);
    //       if (!dword_7CF638) { sub_4D8760(-1, 0); resolve aBroadcastDispl_0; }
    //       else { resolve aBroadcastDispl; }
    //       sub_587DD0(buffer, byte_5EC4CC, 127);
    //       TextLineWrappingAndRendering(&dword_7CD204, buffer, 3, 16909060);
    //     }
    //     ++v6; ++v7;
    //     if (v6 >= dword_7CB218) goto done;
    //   }
    //   dword_7CF788 = (dword_7CF788 == 0);
    //   if (dword_7CF788) { resolve aHudOn; }
    //   else { IndexValidationSetter(-1); resolve aHudOff; }
    //   sub_587DD0(buffer, byte_5EC4CC, 127);
    //   TextLineWrappingAndRendering(&dword_7CD204, buffer, 3, 16909060);
    //   done:
    //   if (this+0xEC && this+0xD8 && (dword_5EA518 != dword_5EA528 || *(dword_5EA528 + 52) != 1))
    //     return VTableDispatchChain_7e00(this+0xD8);
    //   return dword_7CB218;
    // UNRESOLVED: Global flt_59E440 (0x0059E440) is listed in the packet globals but absent from the raw source of this function; its role here is unknown.
    // UNRESOLVED: Global dword_5ACF34 (0x005ACF34) is listed in the packet globals but absent from the raw source; role unknown.
    // UNRESOLVED: The sub-object pointer arrays based at this+16, this+116 and this+12 (indexed by this+0x0, this+0x4, this+0x8) are not exposed as fields in the packet; exact object layout of those pointer arrays is unresolved.
    // UNRESOLVED: The object pointed to by dword_5EA528 and its +52 state field (compared against 1) belong to an external object not described by this packet.
}
