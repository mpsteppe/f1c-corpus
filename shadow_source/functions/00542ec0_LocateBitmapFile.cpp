// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542EC0
// Canonical corpus name: sub_542EC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_542EC0_00542ec0.c

void UnknownObject::LocateBitmapFile()
{
    // Locates a bitmap filename across the registered data directories. Proceeds only when the argument a2 is non-null and the audio-init flag dword_8B8E28 is set. Copies the filename into a 765-byte stack buffer seeded from the default application directory byte_5EA438, normalizes it with sub_589901, and derives a 4-bit format mode v3 = (this+0x18) & 0xF. It checks the bare path with sub_543050, then each of the dword_8B8E30 registered directories (entries at byte_8B5A3C, stride 132) after formatting "%s\%s" via StringFormatWithBufferOverflowCheck with format string aSS_3; failure anywhere returns 0. When all directories are checked it walks the object list from dword_8B8F14 (next pointer +304) calling sub_560050, and if the final walk count equals dword_8B6AC0 it formats and logs "Could not locate bitmap file %s" through sub_53C590. Returns -1 at the end.
    // GUARD: Function proceeds only when argument a2 is non-null and global dword_8B8E28 is non-zero; otherwise it falls through to return -1. [global:0x008B8E28, source:raw]
    // ASSIGNMENT: Initialize both stack buffers SrcStr and v14: first byte copied from default application directory byte_5EA438, the remaining 0x2FC bytes zeroed by memset, with the trailing __int16 and char terminator fields cleared. [global:0x005EA438, source:raw]
    // GUARD: When strlen(a2) exceeds 0x300, truncate the source by zeroing the byte at a2+767, then strcpy the filename into SrcStr. [source:raw]
    // CALL: sub_589901(SrcStr) normalizes/processes the copied path string in place. [callee:0x00589901, source:raw]
    // CALCULATION: v3 = (this+0x18) & 0xF derives a 4-bit format mode from the low nibble of this+0x18. [field:this:0x00000018, source:raw]
    // CALL: First existence check: if !sub_543050(SrcStr, v3) return 0 (bare filename not found in the default directory). [callee:0x00543050, field:this:0x00000018, source:raw]
    // LOOP: For each of the dword_8B8E30 registered directories (array base byte_8B5A3C, stride 132): StringFormatWithBufferOverflowCheck(v14, "%s\\%s" via format string aSS_3, dir, SrcStr) then if !sub_543050(v14, v3) return 0. [global:0x008B8E30, global:0x008B5A3C, callee:0x0058815F, global:0x005C2D64, callee:0x00543050, field:this:0x00000018, source:raw]
    // LOOP: When all directories were visited (v6 == v5), walk the object linked list starting at global dword_8B8F14 following the +304 next pointer: while sub_560050(this, SrcStr) succeeds, advance v8 and count v9; a null node ends the walk at the failure label, and a failed sub_560050 returns 0. If the directory loop ended early, v9 is set to -1. [global:0x008B8F14, callee:0x00560050, source:raw]
    // GUARD: When the walked count v9 equals global dword_8B6AC0 (expected entry count), format "Could not locate bitmap file %s" via StringFormatWithBufferOverflowCheck with format string aCouldNotLocate and call sub_53C590(-1, message) to log the error. [global:0x008B6AC0, callee:0x0058815F, global:0x005DBD94, callee:0x0053C590, source:raw]
    // RETURN: Return -1 (not found). Called by sub_5429B0, which drives the bitmap lookup. [caller:0x005429B0, function:0x00542EC0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_542EC0(ResConfig* this, const char* filename) {
    //     if (!filename || !dword_8B8E28) return -1;
    //     char SrcStr[765]; char path[765];
    //     init_buf(SrcStr, byte_5EA438); init_buf(path, byte_5EA438);
    //     if (strlen(filename) > 0x300) *(BYTE*)(filename + 767) = 0;
    //     strcpy(SrcStr, filename);
    //     sub_589901(SrcStr);
    //     int mode = this->flags & 0xF;
    //     if (!sub_543050(SrcStr, mode)) return 0;
    //     int i = 0;
    //     while (i < dword_8B8E30) {
    //       StringFormatWithBufferOverflowCheck(path, "%s\\%s", &byte_8B5A3C[132*i], SrcStr);
    //       if (!sub_543050(path, mode)) return 0;
    //       ++i;
    //     }
    //     int count = i;
    //     int seen = (i == dword_8B8E30) ? 0 : -1;
    //     int node = dword_8B8F14;
    //     while (node && sub_560050(this, SrcStr)) { node = *(int*)(node + 304); ++seen; }
    //     if (node && !seen_ok) return 0;
    //     if (seen == dword_8B6AC0) {
    //       char msg[256];
    //       StringFormatWithBufferOverflowCheck(msg, "Could not locate bitmap file %s", path);
    //       sub_53C590(-1, msg);
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: What sub_543050 returns (file/resource existence test) and the meaning of the 4-bit mode this+0x18 & 0xF are inferred from call patterns, not proven.
    // UNRESOLVED: What sub_560050 checks against the linked list (resource container membership) is inferred from its position in the walk.
    // UNRESOLVED: Role of dword_8B8E28 (flagged as an audio-init condition in existing analysis) as a hard gate is DERIVED, not proven.
    // UNRESOLVED: Relationship between the linked-list walk count v9 and dword_8B6AC0 (expected count) is inferred.
    // UNRESOLVED: Meaning of returning 0 vs -1 on the different failure paths is unresolved.
}
