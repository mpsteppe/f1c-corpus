// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404D50
// Canonical corpus name: ResourceListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ResourceListCleanup_00404d50.c

void UnknownObject::ResourceListCleanup()
{
    // When a2 is non-zero, sets the byte flag at target+0x24 to a2, frees every node of the linked list rooted at target+0x40 (freeing each node's optional nested buffer via FreeWrapper_7bcf), zeroes the four list fields at 0x40..0x4C, allocates a default-valued struct, resolves a directory path (lpPathName, falling back to byte_5EA438), builds a filename via sub_565F80, then rebuilds the list by iterating directory entries with DirectoryEntryIterator and inserting non-empty entries, finally returning LinkedListDestructorWithChildCleanup result. When a2 is zero it only sets the flag and returns a2.
    // ASSIGNMENT: Write the byte flag at target+0x24 (reached by dereferencing this) = a2. [field:obj:0x00000024, field:this:0x00000000, source:raw]
    // GUARD: If a2 == 0, skip the entire rebuild path and return a2; otherwise proceed to free and rebuild the list. [field:obj:0x00000024, source:raw]
    // CALCULATION: Load the list head base v4 = target+0x40 and the first node v5 = *v4. [field:obj:0x00000040, field:*(obj+0x40):0x00000000, source:raw]
    // LOOP: While the current node v5 is non-null, read the node flag at +8 and save the next pointer at +4 before freeing the node. [field:*(obj+0x40):0x00000008, field:*(*(obj+0x40)+0x4):0x00000004, source:raw]
    // CALL: When the node flag at +8 is set, free the node's data: FreeWrapper_7bcf on the inner buffer (*v8) when present, then FreeWrapper_7bcf on the data pointer v8 itself. [field:*(*(obj+0x40)+0x0):0x00000000, callee:0x00587BCF, source:raw]
    // CALL: Free each node itself via FreeWrapper_7bcf(v6). [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: After the free loop, zero the four list fields at target+0x40, 0x44, 0x48, 0x4C. [field:obj:0x00000040, field:obj:0x00000044, field:obj:0x00000048, field:obj:0x0000004C, source:raw]
    // CALL: Call AllocateStructWithDefaultValues(&a2) to allocate/reinitialize a default-valued struct. [callee:0x00565DC0, source:raw]
    // CALCULATION: Resolve the directory path: v9 = lpPathName, or &byte_5EA438 when lpPathName is null. [global:0x005EC410, global:0x005EA438, source:raw]
    // CALL: Call sub_565F80(FileName, 1, v9, 0) to build the target file path from the resolved directory. [global:0x005BE714, callee:0x00565F80, source:raw]
    // CALL: Call LinkedListPopFront_5f50(&a2). [callee:0x00565F50, source:raw]
    // LOOP: Iterate directory entries with DirectoryEntryIterator(&a2); for each entry i, when strlen(i) is non-zero insert it via LinkedListNodeInsertion(i), and break when LinkedListNodePeek(&a2) returns zero. [callee:0x005662D0, callee:0x00404E60, callee:0x00565F20, source:raw]
    // RETURN: Return the result of LinkedListDestructorWithChildCleanup(&a2) as the rebuild path's return value. [callee:0x00565E20, function:0x00404D50, source:raw]
    // RETURN: When a2 == 0, return a2 directly. [function:0x00404D50, source:raw]

    // Conservative worker pseudocode:
    //   char ResourceListCleanup(void *this, char a2) {
    //       *(char *)(*(int *)this + 0x24) = a2;
    //       if (a2 == 0) return a2;
    //       int *head = (int *)(*(int *)this + 0x40);
    //       int node = *head;
    //       while (node) {
    //           int next = *(int *)(node + 4);
    //           char flag = *(char *)(node + 8);
    //           if (flag) {
    //               void **data = (void **)node;
    //               if (*data) {
    //                   if (**data) FreeWrapper_7bcf(**data);
    //                   FreeWrapper_7bcf(*data);
    //               }
    //           }
    //           FreeWrapper_7bcf((void *)node);
    //           node = next;
    //       }
    //       head[0] = 0; head[1] = 0; head[2] = 0; head[3] = 0;
    //       AllocateStructWithDefaultValues(&a2);
    //       const char *dir = lpPathName ? (const char *)lpPathName : (const char *)&byte_5EA438;
    //       sub_565F80(FileName, 1, (int)dir, 0);
    //       LinkedListPopFront_5f50(&a2);
    //       const char *e = DirectoryEntryIterator(&a2);
    //       for (; e; e = DirectoryEntryIterator(&a2)) {
    //           if (strlen(e)) LinkedListNodeInsertion(e);
    //           if (!LinkedListNodePeek(&a2)) break;
    //       }
    //       return LinkedListDestructorWithChildCleanup(&a2);
    //   }
    // UNRESOLVED: Passing the address of the char parameter a2 to AllocateStructWithDefaultValues and the list helpers is likely a decompiler artifact of a stack-allocated local struct; the real object identity is unevidenced.
    // UNRESOLVED: Semantics of the list fields at 0x44/0x48/0x4C beyond list bookkeeping are not evidenced.
    // UNRESOLVED: The rebuild's directory path resolution (lpPathName vs byte_5EA438 fallback) is clear, but why DirectoryEntryIterator reads from the same &a2 struct as the file-path build is unevidenced.
}
