// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB3D0
// Canonical corpus name: NodeDataFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NodeDataFree_004bb3d0.c

void UnknownObject::NodeDataFree()
{
    // Node data teardown called from GameDataFileIO; structural twin of LinkedListNodeDestructor_a900 (004ba900). Reads the byte flag at this+0xC and returns it in every path. When the flag is non-zero the data block is torn down: the primary data pointer at this+0x0 is freed, and its secondary pointer at obj+0x4 is freed first if non-null. Unlike the twin, this function never frees the node buffer itself and returns the original flag value, not the node pointer.
    // ASSIGNMENT: Read the byte flag at this+0xC into result. [field:this:0x0000000C, source:raw]
    // GUARD: Data teardown runs only when the byte flag at this+0xC is non-zero. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Load the primary data block pointer from this+0x0 into v2. [field:this:0x00000000, source:raw]
    // GUARD: Proceed with the teardown only when the pointer at this+0x0 is non-null. [field:this:0x00000000, source:raw]
    // GUARD: Free the secondary pointer only when the data block's dword at obj+0x4 is non-null. [field:obj:0x00000004, source:raw]
    // CALL: Free the secondary data pointer v2[1] via FreeWrapper_7bcf. [callee:0x00587BCF, field:obj:0x00000004]
    // CALL: Free the primary data block v2 via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x00000000]
    // RETURN: Return the original byte flag value (this[12]) in all paths. [field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   char NodeDataFree(char *this) {
    //     char flag = this[12];
    //     if (flag) {
    //       void **data = *(void ***)this;
    //       if (data) {
    //         if (data[1]) FreeWrapper_7bcf(data[1]);
    //         FreeWrapper_7bcf(data);
    //       }
    //     }
    //     return flag;
    //   }
    // UNRESOLVED: Owner class and the concrete layout of the data block (primary and secondary pointers) are unknown.
    // UNRESOLVED: Whether obj+0x4 belongs to the same object as this is not proven; only an equal-offset reading is used.
    // UNRESOLVED: Semantics of the flag at this+0xC beyond enabling the data teardown are unknown.
    // UNRESOLVED: Why the node buffer itself is not freed here (unlike the twin at 004ba900) is unresolved; the caller GameDataFileIO may own it.
}
