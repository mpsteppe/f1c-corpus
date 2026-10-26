// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004694B0
// Canonical corpus name: FilenameFromLinkedList_94b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilenameFromLinkedList_94b0_004694b0.c

void UnknownObject::FilenameFromLinkedList()
{
    // Looks up a filename by index a2 in a linked list reached through this+0x444, bounded by the count at this+0x450. Copies the found string into the destination buffer at this+0x344, strips a single trailing backslash, and returns a pointer to that buffer. Any out-of-range, missing-node, or null-string case returns the shared empty-string fallback byte_5EA438.
    // GUARD: Bounds guard on index a2: if a2 < 0 or a2 >= *(this + 0x450) (the element count), return the fallback empty string byte_5EA438. [field:this:0x00000450, global:0x005EA438, source:raw]
    // LOOP: Walk the linked list starting from the head *(this + 0x444), advancing through the next pointer at node+4 for index a2 steps; if the list ends early, return the fallback byte_5EA438. [field:this:0x00000444, field:*(*(this+0x444)+0x4):0x00000004, global:0x005EA438, source:raw]
    // GUARD: Guard on the selected node: if the node is null, or its first dword (a pointer to a string array) is null, or the first string it points to is null, return the fallback byte_5EA438. [field:*(*(this+0x444)+0x4):0x00000000, field:*(*(*(this+0x444)+0x4)+0x0):0x00000000, global:0x005EA438, source:raw]
    // ASSIGNMENT: Copy the resolved filename into the destination buffer at this + 0x344 via strcpy. [source:raw]
    // CALCULATION: Scan the copied string from its end and overwrite one trailing backslash character ('\\', 0x5C) with a NUL terminator. [source:raw]
    // RETURN: Return a pointer to the destination buffer at this + 0x344. [source:raw]

    // Conservative worker pseudocode:
    //   char *sub_4694B0(void *this, int index) {
    //     if (index < 0 || index >= *(int*)((char*)this + 0x450)) return byte_5EA438;
    //     void *node = *(void**)((char*)this + 0x444);
    //     for (int i = 0; i < index && node; ++i) node = *(void**)((char*)node + 4);
    //     if (!node) return byte_5EA438;
    //     const char **strs = *(const char***)node;
    //     if (!strs) return byte_5EA438;
    //     const char *s = strs[0];
    //     if (!s) s = byte_5EA438;
    //     char *dst = (char*)this + 0x344;
    //     strcpy(dst, s);
    //     int n = strlen(dst);
    //     while (n > 0 && dst[n-1] == '\\') dst[--n] = 0;
    //     return dst;
    //   }
    // UNRESOLVED: Linked-list node layout is inferred from dereferences only: node+0 holds a pointer to a string array (element 0 is used) and node+4 holds the next link; ownership and lifetime are unknown.
    // UNRESOLVED: Destination buffer at this + 0x344 and element count at this + 0x450 are read but their backing storage/lifetime is unverified.
    // UNRESOLVED: The shared fallback string byte_5EA438 has unknown contents and length.
}
