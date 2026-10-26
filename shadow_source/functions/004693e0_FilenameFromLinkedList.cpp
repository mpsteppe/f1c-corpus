// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004693E0
// Canonical corpus name: FilenameFromLinkedList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FilenameFromLinkedList_004693e0.c

void UnknownObject::FilenameFromLinkedList()
{
    // Resolves the a2-th filename from a linked list rooted at this+0x444, guarded by the element count at this+0x450. Bounds or walk failures return the byte_5EA438 fallback. On success the leaf string is copied into a stack/object buffer at this+836, truncated at the first '.' (extension), then the pointer is advanced past the last '\' so the result points at the bare filename.
    // GUARD: Bounds guard: return byte_5EA438 when a2 < 0 or a2 >= the element count at this+0x450. [source:raw, field:this:0x00000450, global:0x005EA438]
    // ASSIGNMENT: Start the walk at the list head stored at this+0x444. [source:raw, field:this:0x00000444]
    // LOOP: When a2 > 0, follow node next pointers at node+4 until a2 nodes have been skipped; if the list ends first, return byte_5EA438. [source:raw, field:*(*(this+0x444)+0x4):0x00000004, global:0x005EA438]
    // GUARD: Guard: return byte_5EA438 if the reached node v4 is NULL or if the inner pointer stored at node+0 is NULL. [source:raw, field:*(*(this+0x444)+0x4):0x00000000, global:0x005EA438]
    // ASSIGNMENT: Dereference the leaf string pointer; when the string is empty use byte_5EA438 as the source instead. [source:raw, field:*(*(*(this+0x444)+0x4)+0x0):0x00000000, global:0x005EA438]
    // CALL: Copy the resolved string into the buffer at this+836 via strcpy. [source:raw]
    // CALCULATION: Scan backwards from the buffer end for the first '.' (0x2E) and null-terminate there, stripping the file extension; stop at the buffer base. [source:raw]
    // CALCULATION: Scan backwards from the buffer end for the last '\\' (0x5C); return a pointer just past it, giving the bare filename. If none found, return the buffer start. [source:raw]
    // RETURN: Return a pointer into the this+836 buffer: the bare filename after path/extension stripping, or byte_5EA438 on any failure. [source:raw, global:0x005EA438]

    // Conservative worker pseudocode:
    //   char *sub_4693E0(int this, int a2) {
    //     int v3 = a2;
    //     if (a2 < 0 || a2 >= *(int*)(this + 1104)) return byte_5EA438;
    //     int v4 = *(int*)(this + 1092);
    //     if (a2 > 0) {
    //       while (v4) {
    //         v4 = *(int*)(v4 + 4);
    //         if (--v3 <= 0) goto L6;
    //       }
    //       return byte_5EA438;
    //     }
    //   L6:
    //     if (!v4) return byte_5EA438;
    //     const char **v5 = *(const char***)v4;
    //     if (!v5) return byte_5EA438;
    //     const char *v6 = *v5;
    //     if (!*v5) v6 = byte_5EA438;
    //     strcpy((char*)(this + 836), v6);
    //     char *p = (char*)strlen((char*)(this + 836)) + this + 836;
    //     if ((unsigned)p > this + 836) {
    //       while (*p != '.') { if ((unsigned)--p <= this + 836) break; }
    //       *p = 0;
    //     }
    //     p = (char*)strlen((char*)(this + 836)) + this + 836;
    //     if ((unsigned)p > this + 836) {
    //       while (*p != '\\') { if ((unsigned)--p <= this + 836) return p; }
    //       ++p;
    //     }
    //     return p;
    //   }
    // UNRESOLVED: Buffer base at this+836 and element count/head offsets (this+0x450, this+0x444) belong to the owning object, which is unnamed; exact struct layout unknown.
    // UNRESOLVED: byte_5EA438 fallback string content unknown from the packet.
}
