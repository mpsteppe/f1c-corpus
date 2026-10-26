// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C320
// Canonical corpus name: SceneFileMatchByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneFileMatchByName_0045c320.c

void UnknownObject::SceneFileMatchByName()
{
    // Searches a linked list of scene-file entries for a node whose name matches the filename portion of path a2. Initializes an iterator at this+0xC from the list head at this+0x4, then walks nodes: each node's string pointer (fallback to the global byte_5EA438 when null) is compared against the filename part of a2 via sub_588410 (0 means match). On a match the node's data at +8 is written to output a3 and 1 is returned; on list exhaustion or an empty tail, a3 is set to 0 and 0 is returned.
    // ASSIGNMENT: Initialize the iterator at this+0xC from the list head stored at this+0x4. [field:this:0x0000000C, field:this:0x00000004, source:raw]
    // GUARD: Guard on the head at this+0x4 being non-null and its first dword being non-zero; otherwise fall through to the no-match path. [field:this:0x00000004, source:raw]
    // CALCULATION: Locate the end of path a2 via strlen, then scan backwards for the backslash separator (92) to isolate the filename portion into v6. [source:raw]
    // CALCULATION: Select the comparison string: the current node's string pointer at *(node); when it is null, fall back to the global byte_5EA438. [global:0x005EA438, source:raw]
    // GUARD: Call sub_588410(filename v6, node string v7); when it returns 0 the names match and the loop breaks. [callee:0x00588410, source:raw]
    // ASSIGNMENT: Advance the iterator: this+0xC becomes the next node pointer stored at (current node + 4). [field:this:0x0000000C, source:raw]
    // GUARD: Guard on the next node being non-null and its first dword being non-zero; otherwise exit to the no-match path. [source:raw]
    // ASSIGNMENT: On match, write the matched node's data at +8 into the output a3. [field:*(this+0xC):0x00000008, source:raw]
    // RETURN: Return 1 on match. [source:raw]
    // RETURN: Return 0 and write 0 to output a3 when no node matches or the list is exhausted. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_45C320(this, const char* path, void** out) {
    //     void* node = *(this + 0x4);
    //     *(this + 0xC) = node;
    //     if (node && *node) {
    //       while (1) {
    //         const char* filename = backslash-separated tail of path;
    //         const char* name = *(node) ? *(node) : byte_5EA438;
    //         if (sub_588410(filename, name) == 0) {
    //           *out = *(node + 8);
    //           return 1;
    //         }
    //         *(this + 0xC) = *(node + 4);
    //         node = *(this + 0xC);
    //         if (!node || !*node) break;
    //       }
    //     }
    //     *out = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of the returned data at node +8 (payload type unknown).
    // UNRESOLVED: Meaning of the field at this+0x10 is not visible in the decompilation.
    // UNRESOLVED: Identity and exact behavior of the string comparison sub_588410 is assumed from the zero-on-match return contract.
}
