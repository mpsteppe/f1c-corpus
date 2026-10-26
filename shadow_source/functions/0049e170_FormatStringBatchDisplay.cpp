// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049E170
// Canonical corpus name: FormatStringBatchDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FormatStringBatchDisplay_0049e170.c

void UnknownObject::FormatStringBatchDisplay()
{
    // Batch renders single characters at fixed 2-row grid positions. After nested guards on the format context (this+0xC) and display context (this+0x14) and on a non-zero sub-field at offset +84 of the display context, it reads eleven indexed character-source globals (each with a small decimal offset), formats each into a local buffer as a "%c" via StringFormatWithBufferOverflowCheck, and places each character at a fixed (x, row) position through sub_553070. Row 0 holds seven characters at x=0..210 (row 11); row 1 holds five characters at x=20..188 (row 65). Returns the result of the final sub_553070 call.
    // GUARD: Guard: this[3] (field this+0xC, format context) must be non-zero before proceeding. [field:this:0x0000000C, source:raw]
    // GUARD: Guard: this[5] (field this+0x14, display context) must be non-zero before proceeding. [field:this:0x00000014, source:raw]
    // GUARD: Guard: the DWORD at offset +84 of the display context must be non-zero (sub-data present) before any rendering. [field:this:0x00000014, source:raw]
    // CALL: Slot 0 (row 0, x=0, y=11): format character dword_7CE6AC + 33 as "%c" into local buffer v3, then sub_553070(v3, 0, 11, display+84). [global:0x007CE6AC, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 1 (row 0, x=42, y=11): format character dword_7CE7CC + 36 as "%c", then sub_553070(v3, 42, 11, display+84). [global:0x007CE7CC, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 2 (row 0, x=84, y=11): format character dword_7CE718 + 39 as "%c", then sub_553070(v3, 84, 11, display+84). [global:0x007CE718, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 3 (row 0, x=126, y=11): format character dword_7CE7F0 + 42 as "%c", then sub_553070(v3, 126, 11, display+84). [global:0x007CE7F0, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 4 (row 0, x=168, y=11): format character dword_7CE760 + 45 as "%c", then sub_553070(v3, 168, 11, display+84). [global:0x007CE760, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 5 (row 0, x=210, y=11): format character dword_7CE784 + 48 as "%c", then sub_553070(v3, 210, 11, display+84). [global:0x007CE784, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 6 (row 1, x=20, y=65): format character dword_7CE8A4 + 62 as "%c", then sub_553070(v3, 20, 65, display+84). [global:0x007CE8A4, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 7 (row 1, x=62, y=65): format character dword_7CE6F4 + 52 as "%c", then sub_553070(v3, 62, 65, display+84). [global:0x007CE6F4, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 8 (row 1, x=104, y=65): format character dword_7CE73C + 55 as "%c", then sub_553070(v3, 104, 65, display+84). [global:0x007CE73C, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 9 (row 1, x=146, y=65): format character dword_7CE7A8 + 58 as "%c", then sub_553070(v3, 146, 65, display+84). [global:0x007CE7A8, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // CALL: Slot 10 (row 1, x=188, y=65): format character dword_7CE850 + 60 as "%c", then sub_553070(v3, 188, 65, display+84); its return value becomes the function result. [global:0x007CE850, global:0x005CCEF0, callee:0x0058815F, callee:0x00553070, source:raw]
    // RETURN: Return the result of the last sub_553070 call (slot 10); when any guard fails, return the guarded field value instead. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatStringBatchDisplay(int this) {
    //     int ctx = *(int*)(this+0xC);
    //     int disp = *(int*)(this+0x14);
    //     if (ctx && disp && *(int*)(disp+84)) {
    //       char v3[16];
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE6AC + 33);
    //       sub_553070(v3, 0, 11, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE7CC + 36);
    //       sub_553070(v3, 42, 11, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE718 + 39);
    //       sub_553070(v3, 84, 11, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE7F0 + 42);
    //       sub_553070(v3, 126, 11, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE760 + 45);
    //       sub_553070(v3, 168, 11, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE784 + 48);
    //       sub_553070(v3, 210, 11, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE8A4 + 62);
    //       sub_553070(v3, 20, 65, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE6F4 + 52);
    //       sub_553070(v3, 62, 65, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE73C + 55);
    //       sub_553070(v3, 104, 65, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE7A8 + 58);
    //       sub_553070(v3, 146, 65, *(int*)(disp+84));
    //       StringFormatWithBufferOverflowCheck(v3, "%c", dword_7CE850 + 60);
    //       return sub_553070(v3, 188, 65, *(int*)(disp+84));
    //     }
    //     return ctx;
    //   }
    // UNRESOLVED: Field this+0x68 is listed in the packet but has no access in the decompiled source text.
    // UNRESOLVED: Meaning of the small decimal offsets (33..62) added to the source dwords - likely per-slot indices into config/control data.
    // UNRESOLVED: Semantics of sub_553070 (assumed text/render placement helper) and of the display-context field at +84.
    // UNRESOLVED: Whether this renders a control scheme / steering-assist indicator for the HUD.
}
