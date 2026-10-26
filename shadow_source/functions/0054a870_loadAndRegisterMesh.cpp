// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A870
// Canonical corpus name: sub_54A870
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_54A870_0054a870.c

void UnknownObject::loadAndRegisterMesh()
{
    // Loads and registers a mesh file named by string a2. The name is copied into SrcStr and normalized via sub_589901, then validated as non-empty and prefixed with "mts_" by sub_587C20 against aMts_0. The file is opened directly with the "rb" mode string aRb via sub_587DB0; on failure the registered search-path array byte_8B5A3C (count dword_8B8E30, stride 132) is walked, and as a final fallback a linked list at dword_8B8F14 is searched. The located file is read through sub_54AC70 into a mesh context buffer v16. On success this is stored at v16+312, sub_54B4D0 receives the mesh dimensions read from v16+256..276 (or zeros) depending on bit 0x10 of this+0x3C, sub_54B570 and LinkedListAppend_abe0 register the mesh, bit 0x8000 of this+0x3C is cleared, and 0 is returned. Every failure path formats an error message and reports it through sub_53C590 before returning -1.
    // CALL: strcpy(SrcStr, a2) copies the input name into the local buffer, then sub_589901(SrcStr) normalizes or otherwise post-processes the copy. [source:raw, callee:0x00589901]
    // GUARD: If SrcStr is empty or sub_587C20(SrcStr, aMts_0) fails to match the "mts_" prefix, format "Illegal mesh file name %s" into v18 via StringFormatWithBufferOverflowCheck, report it through sub_53C590(-1, v18) and return -1. [source:raw, callee:0x00587C20, global:0x005D359C, global:0x005DBEF0, callee:0x0058815F, callee:0x0053C590]
    // CALL: Direct open attempt: sub_587DB0(SrcStr, aRb) opens the file with the "rb" mode string aRb; a nonzero handle continues to the read/register path. [source:raw, callee:0x00587DB0, global:0x005BE828]
    // LOOP: If the direct open fails, walk the registered search-path array byte_8B5A3C (count dword_8B8E30, element stride 132), formatting each candidate as "%s\\%s" into v21 with StringFormatWithBufferOverflowCheck and attempting sub_587DB0(v21, aRb), breaking on the first success. [source:raw, global:0x008B5A3C, global:0x008B8E30, callee:0x0058815F, callee:0x00587DB0, global:0x005BE828]
    // CALCULATION: Measure the file: capture the initial size with FileSizeQueryWrapper, seek to the end via sub_587F64(fd, 0, 2), re-query the size to get the tail length, then restore the position with sub_587F64(fd, initial, 0). [source:raw, callee:0x0058ACE6, callee:0x00587F64]
    // CALL: sub_54AC70(fd, size, &v16, 0) reads the located file into the mesh context buffer v16. On failure FileCloseWithLock closes the handle and the shared error path (StringRelocationCopy(0, v18), " for file %s" suffix into v20) runs; on success the handle is also closed and loading continues. [source:raw, callee:0x0054AC70, callee:0x00587D02, callee:0x0053C5B0, global:0x005DBF2C, callee:0x0058815F]
    // LOOP: Fallback search: when no path succeeded, walk the linked list at dword_8B8F14 through the +76-dword next pointers. Nodes for which sub_560230(SrcStr) is nonzero are skipped; otherwise sub_54AC70(v12[4], *(v12[73]<<8 + v12[74] + 8), &v16, v12) attempts the read, breaking on a 0 return, jumping to the error path on -1, and otherwise continuing to the next node. [source:raw, global:0x008B8F14, callee:0x00560230, callee:0x0054AC70]
    // GUARD: If the fallback node counter v13 equals dword_8B6AC0, format "Could not locate mesh file %s" into v18 via StringFormatWithBufferOverflowCheck, report it through sub_53C590(-1, v18) and return -1. [source:raw, global:0x008B6AC0, global:0x005DBF0C, callee:0x0058815F, callee:0x0053C590]
    // CALL: Shared file-read error path: StringRelocationCopy(0, v18) prepares the base error message, StringFormatWithBufferOverflowCheck writes " for file %s" into v20, strcat(v18, v20) appends it, then sub_53C590(-1, v18) reports and the function returns -1. [source:raw, callee:0x0053C5B0, callee:0x0058815F, callee:0x0053C590]
    // ASSIGNMENT: On a successful read the owner/context pointer this is stored into the mesh context at v16+312. [source:raw]
    // CALL: If bit 0x10 of the flags byte this[60] (this+0x3C) is set, sub_54B4D0 receives the mesh dimensions read from v16+256, v16+260, v16+264, v16+268, v16+272, v16+276; otherwise sub_54B4D0(0, 0, 0, 0.0, 0.0, 0.0) is called with zeros. [source:raw, field:this:0x0000003C, callee:0x0054B4D0]
    // CALL: sub_54B570(0, v16) initializes or registers the loaded mesh context, and LinkedListAppend_abe0(v16) appends the node to the global mesh list. [source:raw, callee:0x0054B570, callee:0x0054ABE0]
    // STATE_TRANSITION: Bit 0x8000 (bit 15) of this+0x3C is cleared via *((_DWORD *)this + 15) &= ~0x8000u, marking the mesh as successfully loaded. [source:raw, field:this:0x0000003C]
    // RETURN: Returns 0 after the mesh context is stored and registered. [source:raw]
    // RETURN: Returns -1 on each failure path after reporting through sub_53C590. [source:raw]

    // Conservative worker pseudocode:
    //   strcpy(SrcStr, a2); sub_589901(SrcStr);
    //   if (!SrcStr[0] || !sub_587C20(SrcStr, aMts_0)) { StringFormatWithBufferOverflowCheck(v18, "Illegal mesh file name %s", SrcStr); sub_53C590(-1, v18); return -1; }
    //   v3 = sub_587DB0(SrcStr, aRb);
    //   if (!v3) {
    //     v7 = 0;
    //     while (v7 < dword_8B8E30) { StringFormatWithBufferOverflowCheck(v21, "%s\\%s", byte_8B5A3C + v7 * 132, SrcStr); v9 = sub_587DB0(v21, aRb); if (v9) break; ++v7; }
    //     if (v9) { v11 = FileSizeQueryWrapper(v9); sub_587F64(v10, 0, 2); v17 = FileSizeQueryWrapper(v10); sub_587F64(v10, v11, 0);
    //              if (sub_54AC70(v10, v17, &v16, 0)) { FileCloseWithLock(v10); goto read_error; } FileCloseWithLock(v10); }
    //     if (v7 == dword_8B8E30) { for (v12 = dword_8B8F14; v12; v12 = v12[76]) {
    //         if (!sub_560230(SrcStr)) { v14 = sub_54AC70(v12[4], *(v12[73]<<8 + v12[74] + 8), &v16, v12); if (!v14) break; if (v14 == -1) goto read_error; } ++v13; } }
    //     else { v13 = -1; }
    //     if (v13 == dword_8B6AC0) { StringFormatWithBufferOverflowCheck(v18, "Could not locate mesh file %s", SrcStr); sub_53C590(-1, v18); return -1; }
    //   } else {
    //     v5 = FileSizeQueryWrapper(v3); sub_587F64(v4, 0, 2); v6 = FileSizeQueryWrapper(v4); sub_587F64(v4, v5, 0);
    //     if (sub_54AC70(v4, v6, &v16, 0)) { FileCloseWithLock(v4); goto read_error; } FileCloseWithLock(v4);
    //   }
    //   read_error: StringRelocationCopy(0, v18); StringFormatWithBufferOverflowCheck(v20, " for file %s", SrcStr); strcat(v18, v20); sub_53C590(-1, v18); return -1;
    //   *(_DWORD *)(v16 + 312) = this;
    //   if (this[60] & 0x10) sub_54B4D0(*(v16+256), *(v16+260), *(v16+264), *(float*)(v16+268), *(float*)(v16+272), *(float*)(v16+276));
    //   else sub_54B4D0(0, 0, 0, 0.0, 0.0, 0.0);
    //   sub_54B570(0, v16); LinkedListAppend_abe0(v16);
    //   *((_DWORD *)this + 15) &= ~0x8000u;
    //   return 0;
    // UNRESOLVED: The global aSS_3 (0x005C2D64) is listed in the packet but does not appear anywhere in the decompiled body; its role in this function is unknown.
    // UNRESOLVED: The exact exhaustion semantics of the fallback list walk are ambiguous: after both the search-path fallthrough (v13 = -1) and the list walk, v13 is compared against dword_8B6AC0, but whether that global is a -1 sentinel or a list-length count is not resolved from the raw code.
    // UNRESOLVED: The meaning of the intermediate (non-0, non-1) return values of sub_54AC70 that cause the fallback walk to continue to the next node is unknown.
    // UNRESOLVED: The semantics of the sub_560230 exclusion predicate on each fallback node are unknown.
    // UNRESOLVED: Ownership of the mesh context v16 and the meaning of the dimensions passed to sub_54B4D0 are inherited from callee contracts, not independently verified here.
}
