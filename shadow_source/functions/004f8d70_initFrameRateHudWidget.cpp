// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8D70
// Canonical corpus name: sub_4F8D70
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F8D70_004f8d70.c

void UnknownObject::initFrameRateHudWidget()
{
    // Initializes a frame-rate HUD display widget: writes display-state and position fields, allocates and constructs a 76-byte backing sub-object via OperatorNewNhMallocWrapper/sub_556220, computes screen layout values from the resolution globals dword_8B8DD4/dword_8B8DD8, registers a font path string, loads the Font.MAS font and FTFRAMERATE.BMP surface, and only marks the widget active (this+0x0 = 2) when both the font lookup and bitmap surface load succeed. Called once from sub_4FA7E0.
    // ASSIGNMENT: this[1] (offset 0x4) = 2: widget type/version identifier [field:this:0x00000004]
    // ASSIGNMENT: this[2] (offset 0x8) = 0: frame counter accumulator reset [field:this:0x00000008]
    // ASSIGNMENT: this[3] (offset 0xC) = 0: secondary counter reset [field:this:0x0000000C]
    // ASSIGNMENT: this[4] (offset 0x10) = 1176255488 (9999.0f): display duration/timeout sentinel [field:this:0x00000010]
    // ASSIGNMENT: this[5] (offset 0x14) = 0: value accumulator / last frame time reset [field:this:0x00000014]
    // CALL: v4 = OperatorNewNhMallocWrapper(76): allocate 76 bytes for backing sub-object [callee:0x00587C03]
    // GUARD: If v4 non-null: v5 = sub_556220(v4) construct sub-object; else v5 = 0 [callee:0x00556220, callee:0x00587C03]
    // ASSIGNMENT: this[6] (offset 0x18) = v5: store constructed sub-object pointer [field:this:0x00000018]
    // CALL: sub_556260(1): one-argument companion call (exact purpose unresolved) [callee:0x00556260]
    // ASSIGNMENT: *(this+44) (offset 0x2C) = 0: byte ready/initialized flag cleared [field:this:0x0000002C]
    // CALCULATION: v11 = (double)dword_8B8DD4 * 0.0009765625: width-scaled screen value [global:0x008B8DD4]
    // CALCULATION: v6 = (double)dword_8B8DD8: screen-height value read [global:0x008B8DD8]
    // ASSIGNMENT: this[7] (offset 0x1C) = 900: X screen-position offset [field:this:0x0000001C]
    // ASSIGNMENT: this[8] (offset 0x20) = 2: font size index / alignment mode [field:this:0x00000020]
    // ASSIGNMENT: this[9] (offset 0x24) = 640: Y screen-position offset [field:this:0x00000024]
    // ASSIGNMENT: this[10] (offset 0x28) = 20: line height / text spacing [field:this:0x00000028]
    // CALCULATION: v10 = v6 * 0.0013020834: height-scaled screen value [global:0x008B8DD8]
    // ASSIGNMENT: v7 = (char*)dword_5EC408; if dword_5EC408 is 0 then v7 = byte_5EA438: pick font path string (override pointer or fallback) [global:0x005EC408, global:0x005EA438]
    // CALL: StringRegistry(v7): register the resolved font path string [callee:0x0053C800, global:0x005EC408, global:0x005EA438]
    // ASSIGNMENT: v9 = 0: initialize font-handle out-parameter [source:raw]
    // GUARD: If sub_53CBC0(&v9, aFontMas) returns 0: font 'Font.MAS' lookup succeeded [callee:0x0053CBC0, global:0x005D6D94]
    // GUARD: If sub_53CFE0(0, aFtframerateBmp, 0x20000) returns 0: 'FTFRAMERATE.BMP' surface load succeeded [callee:0x0053CFE0, global:0x005D6D84]
    // CALL: FontSurfaceLookupDispatch(aFtframerate, 0xFFFFFF, 0, 64, 0, 2): bind frame-rate string to font surface [callee:0x0053D260, global:0x005D6D78]
    // CALL: GuardedDelegation(aFtframerate, LODWORD(v11), LODWORD(v10)): position frame-rate text using scaled screen values [callee:0x0053D2B0, global:0x005D6D78, global:0x008B8DD4, global:0x008B8DD8]
    // ASSIGNMENT: *this (offset 0x0) = 2: mark widget active/visible, only after font + bitmap load succeed [field:this:0x00000000]
    // CALL: PhysicsObjectLinkedListRemoval(v9): release the font handle obtained from sub_53CBC0 [callee:0x0053CE40]
    // RETURN: return 0 [source:raw]

    // Conservative worker pseudocode:
    //   int initFrameRateHudWidget(this, a2, a3) {
    //     this[1] = 2; this[2] = 0; this[3] = 0;
    //     this[4] = 9999.0f; this[5] = 0;
    //     this[6] = sub_556220(OperatorNewNhMallocWrapper(76)) or 0;
    //     sub_556260(1);
    //     *(this+44) = 0;
    //     v11 = dword_8B8DD4 / 1024.0f;  // width scale
    //     v10 = dword_8B8DD8 * 0.0013020834f;  // height scale
    //     this[7] = 900; this[8] = 2; this[9] = 640; this[10] = 20;
    //     path = dword_5EC408 ? dword_5EC408 : byte_5EA438;
    //     StringRegistry(path);
    //     v9 = 0;
    //     if (sub_53CBC0(&v9, aFontMas) == 0) {
    //       if (sub_53CFE0(0, aFtframerateBmp, 0x20000) == 0) {
    //         FontSurfaceLookupDispatch(aFtframerate, 0xFFFFFF, 0, 64, 0, 2);
    //         GuardedDelegation(aFtframerate, v11, v10);
    //         this[0] = 2;
    //       }
    //       PhysicsObjectLinkedListRemoval(v9);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Globals flt_5ACF38, flt_5AD26C, dword_8AFE64 appear in the packet globals list but are not visible in the raw .c text; likely decompiler-inlined float constants or fact-table reads. Purpose unconfirmed.
    // UNRESOLVED: Unused parameters a2 and a3 are not referenced in the body.
    // UNRESOLVED: Purpose of the sub_556260(1) one-argument call is unresolved.
    // UNRESOLVED: Semantics of FontSurfaceLookupDispatch/GuardedDelegation arguments (0xFFFFFF, 64, 0x20000) are not resolved.
    // UNRESOLVED: Owner type is UnknownObject with UNKNOWN trust; no class evidence in the packet.
}
