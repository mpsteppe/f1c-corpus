// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049CA00
// Canonical corpus name: CockpitDashboardLEDGaugeSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CockpitDashboardLEDGaugeSetup_0049ca00.c

void UnknownObject::CockpitDashboardLEDGaugeSetup()
{
    // One-shot initialization of the cockpit dashboard LED-gauge HUD widget. Guarded by a byte init flag at this+0x0; on first call it creates five LED sub-elements via sub_49CD80, resolves two control strings and ten UI-manager handles via sub_548890 when the UI manager is live, builds a cmaps archive path from global directory pointers, loads three BMP textures into this+0x4/0x8/0xC, allocates animation-control memory into this+0x18/0x1C, then sets the init flag and returns an accumulated success flag. Subsequent calls skip the setup body and return the stored flag.
    // ASSIGNMENT: Initialize the success flag v2 to 1 (assume success until a load fails). [source:raw]
    // GUARD: One-shot init guard: when the byte at this+0x0 is zero (not yet initialized) run the setup body; otherwise skip everything and return the flag. [field:this:0x00000000, source:raw]
    // CALL: Create five LED sub-elements via sub_49CD80: element structs at this+0x60/0xAC/0xF8/0x144/0x190 with id slots at this+0x4C/0x50/0x54/0x58/0x5C, bound to off_5CCB70 (scale literals 1.0, 1.0, 1133969408, 1118437376) and off_5CCB74/off_5CCB78/off_5CCB7C/off_5CCB80 (scale literals 0.5, 0.5, 1129447424, 1134886912). [callee:0x0049CD80, global:0x005CCB70, global:0x005CCB74, global:0x005CCB78, global:0x005CCB7C, global:0x005CCB80, source:raw]
    // GUARD: When the UI-manager handle dword_8AFE88 is non-null, attempt control-string and resource resolution. [global:0x008AFE88, source:raw]
    // GUARD: Guard the control-string resolution on ValueGetter(dword_8AFE88) being non-zero. [callee:0x00545F40, global:0x008AFE88, source:raw]
    // ASSIGNMENT: Resolve control strings: this[4] = StringSearchInLinkedList(off_5CCB5C[0]) and this[5] = StringSearchInLinkedList(off_5CCB68[0]). [callee:0x00547920, global:0x005CCB5C, global:0x005CCB68, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALCULATION: When this[4] resolved but this[5] is null, set v2 = (this[5] == 0): a resolved primary control with a missing secondary control marks setup failure. [field:this:0x00000010, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Resolve ten UI-manager handles into this[8]..this[18] via sub_548890 on off_5CCB88/off_5CCB8C/off_5CCB90/off_5CCB94/off_5CCB98/off_5CCB9C/off_5CCBA0/off_5CCBA4/off_5CCBA8/off_5CCBAC/off_5CCBB0. [callee:0x00548890, global:0x005CCB88, global:0x005CCB8C, global:0x005CCB90, global:0x005CCB94, global:0x005CCB98, global:0x005CCB9C, global:0x005CCBA0, global:0x005CCBA4, global:0x005CCBA8, global:0x005CCBAC, global:0x005CCBB0, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, source:raw]
    // ASSIGNMENT: Build the archive path prefix: v5 = dword_5EC428 (falling back to byte_5EA438 when null) and v6 = dword_5EC3D8 (falling back to byte_5EA438 when null). [global:0x005EC428, global:0x005EC3D8, global:0x005EA438, source:raw]
    // CALL: Format the cmaps path into v10: StringFormatWithBufferOverflowCheck(v10, "%s%s%s", v6, v5, aCmapsMas) using the format literal aSSS_0. [callee:0x0058815F, global:0x005C6784, global:0x005CCEB0, source:raw]
    // CALL: Open the cmaps archive: sub_53CBC0(&v8, v10) stores the resolved archive handle in v8. [callee:0x0053CBC0, source:raw]
    // GUARD: When v8 (the archive handle) is non-null, load the texture and animation-control resources. [source:raw]
    // CALL: Load three BMP textures: for off_5CCB58/off_5CCB60/off_5CCB64 format "%s.BMP" (aSBmp) into v9, then sub_53CFE0(this+1..this+3, v9, 67585); mark failure (v2 = 1) when a texture handle at this+0x4/0x8/0xC is null. [callee:0x0058815F, callee:0x0053CFE0, global:0x005CCEA8, global:0x005CCB58, global:0x005CCB60, global:0x005CCB64, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: When this[5] (the secondary control string) resolved, allocate the animation-control memory. [field:this:0x00000014, source:raw]
    // CALL: Allocate animation-control memory: MemoryAllocation_cb20(this+6, off_5CCB68[0], 0, 1) and MemoryAllocation_cb20(this+7, off_5CCB6C[0], 0, 1); mark failure when this+0x18 or this+0x1C is null. [callee:0x0053CB20, global:0x005CCB68, global:0x005CCB6C, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // CALL: Release the archive handle: PhysicsObjectLinkedListRemoval(v8). [callee:0x0053CE40, source:raw]
    // STATE_TRANSITION: Set the init flag: *(_BYTE*)this = 1 so subsequent calls skip the setup body. [field:this:0x00000000, source:raw]
    // RETURN: Return the accumulated success flag v2. [source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_49CA00(_DWORD *this) {
    //     BOOL v2 = 1;
    //     if (!*(_BYTE*)this) {
    //       sub_49CD80((int)(this + 24), (int)(this + 19), off_5CCB70, 1.0, 1.0, 1133969408, 1118437376);
    //       sub_49CD80((int)(this + 43), (int)(this + 20), off_5CCB74, 0.5, 0.5, 1129447424, 1134886912);
    //       sub_49CD80((int)(this + 62), (int)(this + 21), off_5CCB78, 0.5, 0.5, 1129447424, 1134886912);
    //       sub_49CD80((int)(this + 81), (int)(this + 22), off_5CCB7C, 0.5, 0.5, 1129447424, 1134886912);
    //       sub_49CD80((int)(this + 100), (int)(this + 23), off_5CCB80, 0.5, 0.5, 1129447424, 1134886912);
    //       if (dword_8AFE88 && ValueGetter(dword_8AFE88)) {
    //         this[4] = StringSearchInLinkedList(off_5CCB5C[0]);
    //         this[5] = StringSearchInLinkedList(off_5CCB68[0]);
    //         if (this[4]) v2 = (this[5] == 0);
    //         this[8] = sub_548890(off_5CCB88[0]);
    //         this[9] = sub_548890(off_5CCB8C[0]);
    //         this[10] = sub_548890(off_5CCB90[0]);
    //         this[11] = sub_548890(off_5CCB94[0]);
    //         this[12] = sub_548890(off_5CCB98[0]);
    //         this[13] = sub_548890(off_5CCB9C[0]);
    //         this[14] = sub_548890(off_5CCBA0[0]);
    //         this[15] = sub_548890(off_5CCBA4[0]);
    //         this[16] = sub_548890(off_5CCBA8[0]);
    //         this[17] = sub_548890(off_5CCBAC[0]);
    //         this[18] = sub_548890(off_5CCBB0[0]);
    //       }
    //       v8 = 0;
    //       v5 = dword_5EC428 ? (const char *)dword_5EC428 : byte_5EA438;
    //       v6 = dword_5EC3D8 ? (const char *)dword_5EC3D8 : byte_5EA438;
    //       StringFormatWithBufferOverflowCheck(v10, "%s%s%s", v6, v5, aCmapsMas);
    //       sub_53CBC0(&v8, v10);
    //       if (v8) {
    //         StringFormatWithBufferOverflowCheck(v9, "%s.BMP", off_5CCB58[0]);
    //         sub_53CFE0(this + 1, v9, 67585);
    //         if (!this[1]) v2 = 1;
    //         StringFormatWithBufferOverflowCheck(v9, "%s.BMP", off_5CCB60[0]);
    //         sub_53CFE0(this + 2, v9, 67585);
    //         if (!this[2]) v2 = 1;
    //         StringFormatWithBufferOverflowCheck(v9, "%s.BMP", off_5CCB64[0]);
    //         sub_53CFE0(this + 3, v9, 67585);
    //         if (!this[3]) v2 = 1;
    //         if (this[5]) {
    //           MemoryAllocation_cb20(this + 6, off_5CCB68[0], 0, 1);
    //           if (!this[6]) v2 = 1;
    //           MemoryAllocation_cb20(this + 7, off_5CCB6C[0], 0, 1);
    //           if (!this[7]) v2 = 1;
    //         }
    //         PhysicsObjectLinkedListRemoval(v8);
    //       }
    //       *(_BYTE*)this = 1;
    //     }
    //     return v2;
    //   }
    // UNRESOLVED: dword_8AFE64 is listed as a read global in the packet but does not appear in the decompiled body; its role is unverified.
    // UNRESOLVED: The exact sub-element layout at this+0x60/0xAC/0xF8/0x144/0x190 and the meaning of the float bit-pattern literals (1133969408, 1118437376, 1129447424, 1134886912) passed to sub_49CD80 are unverified.
    // UNRESOLVED: The concrete contracts of sub_49CD80, sub_53CBC0, sub_53CFE0 and sub_548890 are grounded only in the corpus naming signal; their exact semantics are not established.
    // UNRESOLVED: The texture load flag 67585 and the purpose of the ten UI-manager handles stored at this[8]..this[18] are unresolved.
    // UNRESOLVED: Callers NetCommPlayerSlotSync (0x0045FC50) and OnScreen_Init (0x0049EFA0) are recorded; the function is not on a frame path (NOT_FOUND).
}
