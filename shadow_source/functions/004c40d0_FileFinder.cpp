// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C40D0
// Canonical corpus name: FileFinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileFinder_004c40d0.c

void UnknownObject::FileFinder()
{
    // File search that probes several candidate paths for a file. Appends extension a2 to a1 when a1 does not already end with the path separator word_5BEB48 (checked via sub_587C20). When a custom directory a3 is supplied, formats a1 as "a3 + a1" and attempts to open it for reading (sub_587DB0 with mode token aR). Otherwise builds candidate paths from the season directory dword_5EC3D8 / season name dword_5EC428 (falling back to byte_5EA438), then a "common" subdirectory variant. On the first successful open it closes the handle (FileCloseWithLock), copies the resolved path (StringCopyWithBufferRealloc), and returns 0. When no candidate opens, it logs a debug message (guarded by session type dword_7C569C != 5, via StringSplitLoop and DebugLogWrite) and returns -1.
    // GUARD: When sub_587C20(a1, &word_5BEB48) is false (path does not end with the separator), strcat a2 onto a1 to append the file extension. [callee:0x00587C20, global:0x005BEB48, source:raw]
    // GUARD: When custom directory a3 is non-null, format "%s%s" (a3 + a1) into the stack buffer via StringFormatWithBufferOverflowCheck and attempt to open it with sub_587DB0(v9, aR). [callee:0x0058815F, callee:0x00587DB0, global:0x005BE860, global:0x005C36F0, source:raw]
    // CALCULATION: Select season directory v6 = dword_5EC3D8 when non-null else byte_5EA438, and season name v5 = dword_5EC428 when non-null else byte_5EA438. [global:0x005EC3D8, global:0x005EC428, global:0x005EA438, source:raw]
    // CALL: Format "%s%s%s" (v6 + v5 + a1) and attempt to open it with sub_587DB0(v9, aR). [callee:0x0058815F, callee:0x00587DB0, global:0x005C6784, global:0x005C36F0, source:raw]
    // CALL: Format "%scommon\\%s" (dword_5EC3D8-or-byte_5EA438 + a1) and attempt to open it with sub_587DB0(v9, aR). [callee:0x0058815F, callee:0x00587DB0, global:0x005D30B4, global:0x005EC3D8, global:0x005EA438, global:0x005C36F0, source:raw]
    // STATE_TRANSITION: On the first successful open: FileCloseWithLock the handle, StringCopyWithBufferRealloc the resolved path buffer, and return 0. [callee:0x00587D02, callee:0x00566650, source:raw]
    // GUARD: When no candidate opened and session type dword_7C569C is not 5, run StringSplitLoop(1, aDDevF119992002_8, 704); when it returns true, write DebugLogWrite(&dword_8AD25C, aCouldNotFindS). [callee:0x004D7A50, callee:0x004D7AA0, global:0x007C569C, global:0x005D3044, global:0x008AD25C, global:0x005D30A0, source:raw]
    // RETURN: Return -1 when the file was not found in any candidate path. [caller:0x004C3200, caller:0x004F4270, source:raw]

    // Conservative worker pseudocode:
    //   int FileFinder(char* path, const char* ext, const char* customDir, int unused) {
    //     char buf[256];
    //     if (!sub_587C20(path, &word_5BEB48)) strcat(path, ext);
    //     if (customDir) {
    //       StringFormatWithBufferOverflowCheck(buf, "%s%s", customDir, path);
    //       if (sub_587DB0(buf, aR)) goto found;
    //     }
    //     StringFormatWithBufferOverflowCheck(buf, "%s%s%s", seasonDir(), seasonName(), path);
    //     if (sub_587DB0(buf, aR)) goto found;
    //     StringFormatWithBufferOverflowCheck(buf, "%scommon\\%s", seasonDir(), path);
    //     if (sub_587DB0(buf, aR)) {
    //     found:
    //       FileCloseWithLock(handle);
    //       StringCopyWithBufferRealloc(buf);
    //       return 0;
    //     }
    //     if (dword_7C569C != 5 && StringSplitLoop(1, aDDevF119992002_8, 704))
    //       DebugLogWrite(&dword_8AD25C, aCouldNotFindS);
    //     return -1;
    //   }
    // UNRESOLVED: The format-string globals aSS (0x005BE860), aSSS_0 (0x005C6784) and aScommonS (0x005D30B4) are mapped by extraction as read here; their association with the inlined literals "%s%s", "%s%s%s" and "%scommon\\%s" is inferred from the existing analysis (DERIVED) and not pinned in the raw source.
    // UNRESOLVED: The extra argument a4 is unused by the visible body.
    // UNRESOLVED: The name sub_587DB0 is unresolved; behavior (file open attempt with mode token aR) is inferred from context.
    // UNRESOLVED: byte_5EA438 fallback directory semantics are unknown.
}
