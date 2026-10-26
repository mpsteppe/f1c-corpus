// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499690
// Canonical corpus name: sub_499690
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_499690_00499690.c

void UnknownObject::recursiveDeleteFiles()
{
    // Recursively deletes files under a directory path. Validates the path argument, normalizes a trailing backslash (word_5C2AAC), appends a file search pattern pointed to by dword_5C2AB8 to the path, then enumerates with FindFirstFileA/FindNextFileA. For each file entry it clears the read-only attribute (ToggleFileReadOnlyAttributeViaWin32API) and deletes it (FileDeleteWithErrorHandling); the first successful file deletion aborts the whole walk and returns false. Directory entries (dwFileAttributes & 0x10) are skipped when they are ".." or match word_5BEB48, otherwise the function recurses into the subdirectory. When enumeration ends without a successful deletion, the handle is closed and the function returns (sub_59B9F3(path) == 0). Called by ProfileAlreadyExistsPageHandler (0x0046CB50), consistent with profile/save scene file cleanup.
    // GUARD: Return false when the path argument is null or empty (strlen == 0). [source:raw]
    // GUARD: Return false when the path length (strlen + 1) reaches the 1024-byte FileName buffer limit. [source:raw]
    // CALCULATION: Append the backslash separator word_5C2AAC to the path when it does not already end in a backslash. [source:raw, global:0x005C2AAC]
    // ASSIGNMENT: Copy the normalized directory path into the v12 prefix buffer so the directory part survives search-pattern append. [source:raw]
    // CALCULATION: Append the file search pattern pointed to by dword_5C2AB8 (dword read at strlen offset) to FileName to form the FindFirstFileA search path. [source:raw, global:0x005C2AB8]
    // CALL: Call FindFirstFileA(FileName, &FindFileData) to begin directory enumeration with the constructed pattern. [source:raw, global:0x0059E0E0]
    // GUARD: Return false when FindFirstFileA returns INVALID_HANDLE_VALUE (no matches or invalid path). [source:raw]
    // LOOP: Iterate over search results via FindNextFileA until enumeration is exhausted. [source:raw, global:0x0059E0E4]
    // CALL: Build the full entry path v11 with StringFormatWithBufferOverflowCheck(v11, "%s%s", v12, cFileName) using the "%s%s" format string at 0x005BE860. [source:raw, callee:0x0058815F, global:0x005BE860]
    // GUARD: Branch to directory handling when dwFileAttributes has FILE_ATTRIBUTE_DIRECTORY (0x10) set. [source:raw]
    // CALL: Clear the read-only attribute on the file via ToggleFileReadOnlyAttributeViaWin32API(v11, 128) before deletion. [source:raw, callee:0x0058BA36]
    // CALL: Delete the file via FileDeleteWithErrorHandling(v11). [source:raw, callee:0x0058986E]
    // STATE_TRANSITION: A successful file deletion aborts the entire walk: close the find handle and return false. [source:raw]
    // GUARD: For directory entries, skip ".." and the name matching word_5BEB48 (strcmp); otherwise recurse into the subdirectory. [source:raw, global:0x005BEB48]
    // CALL: Recursive self-call sub_499690(v11) on the subdirectory full path; a nonzero result continues enumeration, a zero result aborts the walk and returns false. [source:raw, callee:0x00499690, function:0x00499690]
    // CALL: Close the enumeration handle with FindClose when the loop ends. [source:raw, global:0x0059E0E8]
    // CALL: On exhaustion without a successful deletion, call sub_59B9F3(v1) on the original path and return (sub_59B9F3(v1) == 0). [source:raw, callee:0x0059B9F3]
    // RETURN: Return false on every early-exit path (null/empty path, oversized path, FindFirstFileA failure, immediate successful file delete, recursion abort). [source:raw]

    // Conservative worker pseudocode:
    //   bool recursiveDeleteFiles(const char* path) {
    //     if (!path || path[0] == 0) return false;
    //     char search[1024];
    //     if (strlen(path) + 1 >= 1024) return false;
    //     strcpy(search, path);
    //     if (last char of search != '\\') append word_5C2AAC;
    //     copy search to dirPrefix;
    //     append pattern from *dword_5C2AB8 to search;
    //     HANDLE h = FindFirstFileA(search, &fd);
    //     if (h == INVALID_HANDLE_VALUE) return false;
    //     do {
    //       build fullPath = dirPrefix + fd.cFileName;
    //       if (fd.dwFileAttributes & DIRECTORY) {
    //         if (name != ".." && strcmp(name, word_5BEB48) != 0)
    //           if (recursiveDeleteFiles(fullPath) == 0) { FindClose(h); return false; }
    //         continue;
    //       }
    //       clearReadOnly(fullPath);
    //       if (deleteFile(fullPath)) { FindClose(h); return false; }
    //     } while (FindNextFileA(h, &fd));
    //     FindClose(h);
    //     return sub_59B9F3(path) == 0;
    //   }
    // UNRESOLVED: Purpose and exact return semantics of sub_59B9F3 (likely removes the now-empty directory after enumeration) are not evidenced in this packet.
    // UNRESOLVED: Global asc_5C2AB4 (0x005C2AB4) is not referenced in the decompiled body; it is adjacent to the pattern pointer dword_5C2AB8 and is likely the extension/pattern string it points to, but that linkage is unproven.
    // UNRESOLVED: The final return inverts the helper result: true is returned only when sub_59B9F3 returns zero.
    // UNRESOLVED: The extension pattern content (e.g. "*.gdb") referenced by existing analysis is not present in this packet's raw source and was not introduced.
    // UNRESOLVED: byte_FF00000000005391 / byte_FF00000000005396 / byte_FF0000000000539E appear to be decompiler artifacts (out-of-range addresses absent from the body) and were not used.
}
