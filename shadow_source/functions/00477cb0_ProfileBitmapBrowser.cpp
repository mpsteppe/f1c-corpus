// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477CB0
// Canonical corpus name: ProfileBitmapBrowser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ProfileBitmapBrowser_00477cb0.c

void UnknownObject::ProfileBitmapBrowser()
{
    // Rebuilds a scrollable profile-icon bitmap list: frees every existing linked-list item (optionally invoking the item's first vtable method), zeroes the list and layout state, enumerates BMP files in the profile icon directory, and for each entry builds a full path, strips the filename to its extension-less base name, loads the bitmap, allocates a UI widget, copies the path and base-name strings into it, and appends it to the list. Falls back to the default icon when a bitmap cannot be loaded. Recalculates the viewport layout and returns 0.
    // CALL: Call UIDimensionCapture() to record the UI dimensions before rebuilding the list. [callee:0x0048EBD0, source:raw]
    // ASSIGNMENT: Read the list head pointer from this+0xF0 (this[60]) into v2. [field:*(this+0xF0):0x00000000, source:raw]
    // LOOP: Walk the linked list while v2 is non-null; for each node read the byte at node+12 and capture the node next-pointer at node+4 into the new v2 before freeing. [field:*(this+0xF4):0x00000004, source:raw]
    // GUARD: If the node byte at +12 is non-zero and the node's vtable pointer (*v3) is non-null, invoke the first vtable method with argument 1 on the node. [field:*(*(this+0xF0)+0x0):0x00000000, source:raw]
    // CALL: Call FreeWrapper_7bcf(v3) to free each node. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Zero the list state: this[60] (0xF0), this[61] (0xF4), this[62] (0xF8), this[63] (0xFC) and the layout flag this[93] (0x174). [field:this:0x000000F0, field:this:0x000000F4, field:this:0x000000F8, field:this:0x000000FC, field:this:0x00000174, source:raw]
    // ASSIGNMENT: Write aProfileiconDft into the global lpExistingFileName; select the source string v5 as dword_5EC3F8, falling back to byte_5EA438 when dword_5EC3F8 is null. [global:0x005C6658, global:0x005C66F8, global:0x005EC3F8, global:0x005EA438, source:raw]
    // LOOP: Copy the selected source string character-by-character into the v16 path buffer until the NUL terminator is copied. [source:raw]
    // CALL: Call sub_565F80(aBmp_0, 1, v16, 1) to enumerate files matching the aBmp_0 pattern under the path in v16. [callee:0x00565F80, global:0x005C715C, source:raw]
    // CALL: Call sub_566380(0) to reset the enumeration context. [callee:0x00566380, source:raw]
    // LOOP: Iterate directory entries: for each, set i = DirectoryEntryIterator(&unk_8AD3B0); loop while i is non-null, calling DirectoryEntryIterator again at each step. [callee:0x005662D0, global:0x008AD3B0, source:raw]
    // CALCULATION: Scan backward from the end of i to the last backslash (0x5C = 92) to isolate the filename portion v9. [source:raw]
    // CALCULATION: Copy the filename into v15, then scan backward to the last dot (0x2E = 46) and replace it with a NUL terminator to strip the extension. [source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck(v17, aSS, v16, v9) with the aSS format string ("%s%s") to build the full directory+filename path. [callee:0x0058815F, global:0x005BE860, source:raw]
    // CALL: Call sub_497AD0(v17, 0) to load the bitmap for the full path; store the result in v11. [callee:0x00497AD0, source:raw]
    // GUARD: Branch into the create-item path when the bitmap load v11 is non-null. [source:raw]
    // CALL: Call OperatorNewNhMallocWrapper(60) to allocate the widget, then UIObjectConstructor_fc50 on the result (or use a null widget when allocation failed). [callee:0x00587C03, callee:0x0048FC50, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(v17) to store the full path string into the widget. [callee:0x00566650, source:raw]
    // CALL: Call StructFieldCopy_fc80(v11) to copy the loaded bitmap into the widget. [callee:0x0048FC80, source:raw]
    // CALL: Call StringCopyWithBufferRealloc(v15) to store the extension-less base name into the widget. [callee:0x00566650, source:raw]
    // CALL: Call DoublyLinkedListAppend_f5d0(v13, 1) to append the new widget to the list. [callee:0x0048F5D0, source:raw]
    // CALL: On the else path (bitmap load failed), call sub_497AD0(aProfileiconDft, 0) to retry with the default profile icon. [callee:0x00497AD0, global:0x005C66F8, source:raw]
    // CALL: Call LinkedListNodePeek(&unk_8AD3B0) to advance the directory enumeration. [callee:0x00565F20, global:0x008AD3B0, source:raw]
    // CALL: After the loop, call sub_565EB0(&unk_8AD3B0) to reset the enumeration context. [callee:0x00565EB0, global:0x008AD3B0, source:raw]
    // CALL: Call UIViewportLayoutCalculator(this) to recompute the layout of the rebuilt list. [callee:0x0048F640, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   UIDimensionCapture();
    //   v2 = this[0xF0];
    //   while (v2) {
    //     v3 = v2;
    //     v4 = (*(BYTE*)(v2 + 12) == 0);
    //     v2 = *(DWORD*)(v2 + 4);
    //     if (!v4 && *v3)
    //       (**(void (__thiscall ***)(_DWORD, int))*v3)(*v3, 1);
    //     FreeWrapper_7bcf(v3);
    //   }
    //   this[0xF0] = 0; this[0xF4] = 0; this[0xF8] = 0; this[0xFC] = 0; this[0x174] = 0;
    //   lpExistingFileName = aProfileiconDft;
    //   v5 = dword_5EC3F8 ? (char*)dword_5EC3F8 : byte_5EA438;
    //   copy_string(v5, v16);
    //   sub_565F80(aBmp_0, 1, (int)v16, 1);
    //   sub_566380(0);
    //   for (i = DirectoryEntryIterator(&unk_8AD3B0); i; i = DirectoryEntryIterator(&unk_8AD3B0)) {
    //     v9 = &i[strlen(i)];
    //     if (v9 > i) { while (*v9 != '\\') if (--v9 <= i) break; ++v9; }
    //     strcpy(v15, v9);
    //     v10 = &v15[strlen(v15)];
    //     if (v10 > v15) { while (*v10 != '.') if (--v10 <= v15) break; *v10 = 0; }
    //     StringFormatWithBufferOverflowCheck(v17, aSS, v16, v9);
    //     v11 = sub_497AD0(v17, 0);
    //     if (v11) {
    //       v12 = OperatorNewNhMallocWrapper(60);
    //       v13 = v12 ? UIObjectConstructor_fc50(v12) : 0;
    //       StringCopyWithBufferRealloc(v17);
    //       StructFieldCopy_fc80(v11);
    //       StringCopyWithBufferRealloc(v15);
    //       DoublyLinkedListAppend_f5d0(v13, 1);
    //     } else {
    //       sub_497AD0(aProfileiconDft, 0);
    //     }
    //     LinkedListNodePeek(&unk_8AD3B0);
    //   }
    //   sub_565EB0(&unk_8AD3B0);
    //   UIViewportLayoutCalculator(this);
    //   return 0;
    // UNRESOLVED: The packet carries a guard on this+0xFC == 0 (guard:0), but the raw source only writes this[63] = 0 and never reads it back; the guard may encode a list-initialized flag convention enforced elsewhere.
    // UNRESOLVED: The meaning of the node byte at +12 (checked for zero before the vtable call) and the exact role of the first vtable method invoked with argument 1 are unknown.
    // UNRESOLVED: Behavior of sub_497AD0 (bitmap load), sub_565F80 (file enumeration), sub_566380, sub_565EB0 and LinkedListNodePeek is not independently verified; the item-creation flow is inferred from the surrounding string/append calls.
    // UNRESOLVED: The aSS global (0x005BE860) is assumed to back the inline "%s%s" format literal; the association is not stated literally in the source.
    // UNRESOLVED: Owning object type is unknown; this+0xF0..0x174 list and layout fields are only proven on this instance.
}
