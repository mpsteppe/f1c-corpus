// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00548620
// Canonical corpus name: sub_548620
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_548620_00548620.c

void UnknownObject::LoadMaterialLibrary()
{
    // Material library file lookup and texture resource creation. Tries three strategies in order: direct open of the given filename a2, then iterating registered entry path prefixes (byte_8B5A3C, stride 132, count dword_8B8E30), then walking a linked list from head dword_8B8F14. For each located file it calls D3DTextureResourceCreation and closes the handle. If a list-entry count mismatch (v9 != dword_8B6AC0) occurs it returns 0; if no file is located it formats and reports an "Unable to locate material lib" message via sub_53C590 and returns -1.
    // CALL: Attempt direct open of filename a2 with binary read mode from global aRb via sub_587DB0(a2, aRb). [callee:0x00587DB0, global:0x005BE828, source:raw]
    // GUARD: If the direct open returned a non-zero handle v3, proceed to texture creation path. [source:raw]
    // CALL: Call D3DTextureResourceCreation(this, 0) to create the texture resource from the opened file. [callee:0x00548190]
    // CALL: FileCloseWithLock(v3) closes the direct-open handle; on texture creation failure return -1. [callee:0x00587D02]
    // RETURN: Return 0 after closing the handle when texture creation succeeded. [callee:0x00587D02, source:raw]
    // LOOP: Iterate the registered entry path array byte_8B5A3C, count dword_8B8E30, advancing each entry by stride 132. [global:0x008B5A3C, global:0x008B8E30, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v11, "%s\\%s", entryPath, a2) builds the candidate full path. [callee:0x0058815F, source:raw]
    // CALL: sub_587DB0(v11, aRb) attempts to open each formatted candidate path. [callee:0x00587DB0, global:0x005BE828]
    // GUARD: First successful open in the loop breaks iteration. [source:raw]
    // CALL: For a loop-found file, D3DTextureResourceCreation(this, 0) then FileCloseWithLock(v7); return -1 on creation failure. [callee:0x00548190, callee:0x00587D02]
    // GUARD: When no registered path matched, compare entry count v5 to dword_8B8E30 and fall through to linked-list walk. [global:0x008B8E30, source:raw]
    // LOOP: Walk the linked list from head dword_8B8F14, advancing each node by 304 bytes, testing nodes with sub_560230(a2). [global:0x008B8F14, callee:0x00560230, source:raw]
    // CALL: D3DTextureResourceCreation(this, 0) for a matching list entry; return -1 on creation failure. [callee:0x00548190]
    // GUARD: If the visited count v9 does not equal dword_8B6AC0, return 0 immediately. [global:0x008B6AC0, source:raw]
    // RETURN: Early return 0 when the list-entry count does not match dword_8B6AC0. [source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v11, "Unable to locate material lib %s", a2) then sub_53C590(-1, v11) reports the failure. [callee:0x0058815F, global:0x005DBE70, callee:0x0053C590, source:raw]
    // RETURN: Return -1 after reporting that the material library could not be located. [source:raw]

    // Conservative worker pseudocode:
    //   int LoadMaterialLibrary(this, const char* name) {
    //     if (FILE* h = sub_587DB0(name, aRb)) {
    //       int r = D3DTextureResourceCreation(this, 0) ? -1 : 0;
    //       FileCloseWithLock(h);
    //       return r;
    //     }
    //     for (int i = 0; i < dword_8B8E30; ++i) {
    //       StringFormatWithBufferOverflowCheck(buf, "%s\\%s", byte_8B5A3C + i*132, name);
    //       if (FILE* h = sub_587DB0(buf, aRb)) {
    //         int r = D3DTextureResourceCreation(this, 0) ? -1 : 0;
    //         FileCloseWithLock(h);
    //         return r;
    //       }
    //     }
    //     int n = 0;
    //     int* node = dword_8B8F14;
    //     while (node && sub_560230(name)) { node = (int*)*((char*)node + 304); ++n; }
    //     if (node && D3DTextureResourceCreation(this, 0)) return -1;
    //     if (n != dword_8B6AC0) return 0;
    //     StringFormatWithBufferOverflowCheck(buf, "Unable to locate material lib %s", name);
    //     sub_53C590(-1, buf);
    //     return -1;
    //   }
    // UNRESOLVED: The exact role and stride layout of the entry path array byte_8B5A3C are derived from the array walk, not independently confirmed.
    // UNRESOLVED: The node meaning of the linked list headed at dword_8B8F14 and the semantics of the 304-byte link field are unknown.
    // UNRESOLVED: The semantics of the count comparison against dword_8B6AC0 (why a mismatch returns success 0) are not explained by the raw source.
}
