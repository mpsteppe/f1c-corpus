// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005508A0
// Canonical corpus name: sub_5508A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5508A0_005508a0.c

void UnknownObject::LoadMeshFileWithPathSearch()
{
    // Loads a mesh/animation file a2 into an output struct. Zeros the struct, normalizes the file name, validates it against the off_5DC050 extension table, attempts a direct open, then searches the registered path directory list (dword_8B8E30 entries of stride 132 starting at byte_8B5A3C), and finally walks the MAS linked-animation list (dword_8B8F14). The located file is handed to MeshVertexIndexBufferLoader; each failure mode reports a specific error string and returns -1, while a successfully loaded mesh returns 0.
    // ASSIGNMENT: Zero the entire output struct: dwords at this+0x0 through this+0x18 and the byte at this+0x1C (this[28] = 0). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // CALL: Copy a2 into a local buffer and normalize it via sub_589901, then validate the file type against the off_5DC050 table with sub_587C20(SrcStr, &off_5DC050). [callee:0x00589901, callee:0x00587C20, global:0x005DC050]
    // GUARD: If the normalized name is empty or the extension check fails, format the aIllegalMeshFil message "Illegal mesh file name %s" through StringFormatWithBufferOverflowCheck, report it via sub_53C590(-1, message), and return -1. [callee:0x0058815F, global:0x005DBEF0, callee:0x0053C590]
    // CALL: Attempt a direct open of the file with sub_587DB0(SrcStr, aRb) using the binary-read mode string. [callee:0x00587DB0, global:0x005BE828]
    // GUARD: Direct-open success path: call MeshVertexIndexBufferLoader(v2, 0); on success close the handle via FileCloseWithLock and return 0; on failure report "Error loading animation file %s" (aErrorLoadingAn) and fall through to the shared error exit. [callee:0x00550AD0, callee:0x00587D02, global:0x005DC030]
    // LOOP: When the direct open fails, search the dword_8B8E30 registered path directories beginning at byte_8B5A3C (entry stride 132): format each candidate path with aSS_3 ("%s\\%s"), open it via sub_587DB0(v13, aRb), and stop at the first success or when the directory count is exhausted. [global:0x008B8E30, global:0x008B5A3C, callee:0x0058815F, global:0x005C2D64, callee:0x00587DB0, global:0x005BE828]
    // GUARD: When a path-directory open succeeds, call MeshVertexIndexBufferLoader(v7, 0); on failure close the handle and report "Error loading animation file %s" (aErrorLoadingAn); on success close the handle and continue. [callee:0x00550AD0, callee:0x00587D02, global:0x005DC030]
    // GUARD: If the file was not located in any path directory (v5 == dword_8B8E30), walk the MAS linked-animation list headed by dword_8B8F14: iterate while sub_560230(SrcStr) matches, advancing via the +304 link, then call MeshVertexIndexBufferLoader(entry + 16, entry); failure reports "Error loading MAS animation file %s" (aErrorLoadingMa). [global:0x008B8F14, callee:0x00560230, callee:0x00550AD0, global:0x005DC00C]
    // GUARD: If no MAS candidate was found (v10 == dword_8B6AC0), format the aCouldNotLocate_0 message "Could not locate mesh file %s" via StringFormatWithBufferOverflowCheck; otherwise return 0 for the successful load. [global:0x008B6AC0, callee:0x0058815F, global:0x005DBF0C]
    // RETURN: On any load error, report the accumulated message via sub_53C590(-1, message) and return -1. [callee:0x0053C590]

    // Conservative worker pseudocode:
    //   int LoadMeshFileWithPathSearch(_BYTE *this, const char *name) {
    //     memset(this, 0, 0x20);
    //     strcpy(SrcStr, name); sub_589901(SrcStr);
    //     if (!SrcStr[0] || !sub_587C20(SrcStr, &off_5DC050)) { report("Illegal mesh file name %s"); return -1; }
    //     int h = sub_587DB0(SrcStr, aRb);
    //     if (h) {
    //       if (!MeshVertexIndexBufferLoader(h, 0)) { FileCloseWithLock(h); return 0; }
    //       FileCloseWithLock(h); report("Error loading animation file %s"); return -1;
    //     }
    //     int i = 0;
    //     if (dword_8B8E30 > 0) {
    //       char *dir = byte_8B5A3C;
    //       for (;;) {
    //         sprintf(cand, "%s\\%s", dir, SrcStr);
    //         int h2 = sub_587DB0(cand, aRb);
    //         if (h2) {
    //           if (MeshVertexIndexBufferLoader(h2, 0)) { FileCloseWithLock(h2); report("Error loading animation file %s"); return -1; }
    //           FileCloseWithLock(h2);
    //           break;
    //         }
    //         ++i; dir += 132;
    //         if (i >= dword_8B8E30) break;
    //       }
    //     }
    //     if (i == dword_8B8E30) {
    //       int node = dword_8B8F14; int n = 0;
    //       while (dword_8B8F14 && sub_560230(SrcStr)) {
    //         node = *(int*)(node + 304); ++n;
    //         if (!node) break;
    //       }
    //       if (n != dword_8B6AC0) {
    //         if (!MeshVertexIndexBufferLoader(*(int*)(node + 16), node)) return 0;
    //         report("Error loading MAS animation file %s"); return -1;
    //       }
    //     }
    //     if (i != dword_8B8E30 && dword_8B8F14 == 0) report("Could not locate mesh file %s");
    //     return 0;
    //   }
    // UNRESOLVED: Layout of the registered path-directory table (stride 132 at byte_8B5A3C) and of the MAS animation list nodes (+304 link, +16 payload) is DERIVED from decompilation; the packet carries no field table for these globals.
    // UNRESOLVED: The sentinel semantics of dword_8B6AC0 and the meaning of the MAS counter comparison are DERIVED, not directly evidenced.
    // UNRESOLVED: Error-string globals aIllegalMeshFil, aErrorLoadingAn, aErrorLoadingMa and aCouldNotLocate_0 are interpreted by their format text only.
}
