// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00421B10
// Canonical corpus name: FileEnumerationByExtension
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FileEnumerationByExtension_00421b10.c

void UnknownObject::FileEnumerationByExtension()
{
    // Enumerates files matching the scene extension from a source directory and copies each file to a destination path. Builds two path buffers seeded from the default directory byte_5EA438, allocates a linked list, enumerates matching directory entries via sub_565F80 with the extension dword_5C2AB8, walks the list skipping hidden entries (flag bit 0x10) and the '.'/word_5BEB48 and '..' entries, formats '%s%s' source/destination paths with aSS, opens the source with the aRb mode string and the destination with unk_5C2AB0, copies the file in 512-byte chunks through ThreadSafeReadWrapper_803f and FileReadWrapperWithLock, closes both handles, and returns the linked-list destructor result. Called from ConfigIniParser (00421cd0).
    // ASSIGNMENT: Seed the local source and destination path buffers v12 and v15 from the default application-directory byte_5EA438. [global:0x005EA438, source:raw]
    // CALL: Allocate the linked-list container with AllocateStructWithDefaultValues. [callee:0x00565DC0, source:raw]
    // CALL: Enumerate directory entries matching the scene extension dword_5C2AB8 into the list via sub_565F80(dword_5C2AB8, 0, a1, 1). [callee:0x00565F80, global:0x005C2AB8, source:raw]
    // CALL: Pop the front node with LinkedListPopFront_5f50 to prime the list cursor. [callee:0x00565F50, source:raw]
    // LOOP: Iterate the list: fetch the current node data via LinkedListNodeDataPeek and advance to the next node with LinkedListNodePeek each pass, until the list is empty. [callee:0x00565ED0, callee:0x00565F20, source:raw]
    // GUARD: Skip entries whose flag byte has bit 0x10 set (hidden/system), skip the '.' entry word_5BEB48, and skip the '..' entry. [global:0x005BEB48, source:raw]
    // CALCULATION: When both source and destination prefixes are non-empty, build the source path v12 = '%s%s' (a1, node name at entry + 44) and destination v15 = '%s%s' (v10, node name) using StringFormatWithBufferOverflowCheck with the aSS format string. [callee:0x0058815F, global:0x005BE860, source:raw]
    // CALL: Open the source file with the aRb mode string and the destination file with the unk_5C2AB0 mode via sub_587DB0. [callee:0x00587DB0, global:0x005BE828, global:0x005C2AB0, source:raw]
    // LOOP: Copy loop: read 512-byte chunks from the source via ThreadSafeReadWrapper_803f and write each chunk to the destination with FileReadWrapperWithLock until a read returns at most zero bytes. [callee:0x0058803F, callee:0x00588678, source:raw]
    // CALL: Close both file handles with FileCloseWithLock after the copy completes. [callee:0x00587D02, source:raw]
    // RETURN: Destroy the linked list via LinkedListDestructorWithChildCleanup and return its result. [callee:0x00565E20, source:raw]
    // CALL: Invoked from ConfigIniParser (00421cd0) during configuration loading. [caller:0x00421CD0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_421B10(const char* srcDir, const char* dstDir) {
    //     char v12[1024]; memset(v12, 0, sizeof(v12)); v12[0] = byte_5EA438[0];
    //     char v15[1024]; memset(v15, 0, sizeof(v15)); v15[0] = byte_5EA438[0];
    //     void* list = AllocateStructWithDefaultValues(&node);
    //     sub_565F80(dword_5C2AB8, 0, srcDir, 1);
    //     LinkedListPopFront_5f50(&node);
    //     for (int p = LinkedListNodeDataPeek(&node); p; p = LinkedListNodeDataPeek(&node)) {
    //       if (!(*(char*)p & 0x10)) {
    //         const char* name = (const char*)(p + 44);
    //         if (strcmp(name, (const char*)&word_5BEB48) && strcmp(name, "..")) {
    //           if (strlen(srcDir) && strlen(dstDir)) {
    //             StringFormatWithBufferOverflowCheck(v12, "%s%s", srcDir, name);
    //             StringFormatWithBufferOverflowCheck(v15, "%s%s", dstDir, name);
    //             int src = sub_587DB0(v12, aRb);
    //             if (src) {
    //               int dst = sub_587DB0(v15, &unk_5C2AB0);
    //               if (dst) {
    //                 int n;
    //                 while ((n = ThreadSafeReadWrapper_803f(buf, 1, 512, src)) > 0)
    //                   FileReadWrapperWithLock(buf, 1, n, dst);
    //                 FileCloseWithLock(src);
    //                 FileCloseWithLock(dst);
    //               }
    //             }
    //           }
    //         }
    //       }
    //       LinkedListNodePeek(&node);
    //     }
    //     return LinkedListDestructorWithChildCleanup(&node);
    //   }
    // UNRESOLVED: Global asc_5C2AB4 is extracted as a read but does not appear in the decompiled body; role unknown.
    // UNRESOLVED: The exact contents of the file-mode strings aRb and unk_5C2AB0 are not asserted beyond their packet names.
    // UNRESOLVED: The extension-matching semantics of dword_5C2AB8 (scene extension) are unconfirmed.
}
