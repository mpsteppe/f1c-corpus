// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00475920
// Canonical corpus name: SceneLoadAndNameMatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneLoadAndNameMatch_00475920.c

void UnknownObject::SceneLoadAndNameMatch()
{
    // Loads the current scene filename from the game command-dispatch interface (dword_7CD8C0), then walks a linked list of scene-name entries held on `this` to find the entry whose filename matches; stores the matching entry index in this[63] (offset 0xFC). Returns a residual character left over from the string comparison rather than an explicit status code.
    // CALL: Query the command-dispatch interface dword_7CD8C0: call virtual slot 28 with argument 3 to obtain the current scene list handle. [global:0x007CD8C0, source:raw]
    // CALL: GuardedAccessor(listHandle) returns a validated access index into the scene list. [callee:0x0048D360, source:raw]
    // CALL: FilenameFromLinkedList(list, index) extracts the current scene filename string from the list. [callee:0x004693E0, source:raw]
    // ASSIGNMENT: Read the number of entries to search from this[62] (offset 0xF8) into the loop bound. [field:this:0x000000F8]
    // LOOP: Iterate candidate index i from 0 while i < this[62]; each index is bounds-checked against this[61] (offset 0xF4) and must satisfy 0 <= i < this[61]. [field:this:0x000000F8, field:this:0x000000F4]
    // LOOP: Walk the linked list of filename entries starting at the head pointer stored in this[58] (offset 0xE8); advance node by node through the next-node pointer at node+4 (offset 0x4) until reaching candidate index i. [field:this:0x000000E8, field:*(this+0xE8):0x00000000, field:*(this+0xEC):0x00000004]
    // ASSIGNMENT: Read the entry filename string pointer from the node head (offset 0x0); when that pointer is null the fallback string byte_5EA438 is used. [field:*(*(this+0xE8)+0x0):0x00000000, global:0x005EA438]
    // CALCULATION: Compare the current scene filename against the candidate entry filename byte by byte, reading entry string bytes at offsets 0x0 and 0x1. [field:*(*(this+0xE8)+0x0):0x00000000, field:*(*(this+0xE8)+0x0):0x00000001]
    // STATE_TRANSITION: When the comparison yields equality, store the current index i into this[63] (offset 0xFC); the search does not break, so the last matching entry index wins. [field:this:0x000000FC]
    // RETURN: Return (char)v4, a byte left over from the final string comparison rather than an explicit success or failure code. [source:raw]

    // Conservative worker pseudocode:
    //   char* sceneName = FilenameFromLinkedList(GuardedAccessor(dispatch(3)), ...);
    //   int count = this[0xF8];
    //   for (int i = 0; i < count; ++i) {
    //     if (strcmp(sceneName, entryFilename(i, this[0xE8])) == 0) this[0xFC] = i;
    //   }
    // UNRESOLVED: Return value is the residual comparison byte, not an explicit match or status code; caller interpretation is unknown.
    // UNRESOLVED: The decompiler's LABEL_8 path sets the node pointer to null and still dereferences it; the original control flow that avoids the null dereference is not recoverable from this packet alone.
    // UNRESOLVED: Virtual slot 28 on the dword_7CD8C0 interface and the meaning of argument 3 are undocumented here.
    // UNRESOLVED: this[63] (0xFC) is written on every match without breaking, so only the last matching index is retained; whether that is intended is unclear.
}
