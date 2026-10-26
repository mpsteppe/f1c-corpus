// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C84A0
// Canonical corpus name: sub_4C84A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C84A0_004c84a0.c

void UnknownObject::ScanDirectoryIntoPlaylist()
{
    // Scans a directory for files matching an extension filter and appends each hit to a caller-owned linked list. Initializes an iterator state struct (AllocateStructWithDefaultValues), starts file enumeration with sub_565F80(lpFileName, 0, a3, 0), then loops DirectoryEntryIterator until no entry remains. Each iteration allocates an 8-byte node (OperatorNewNhMallocWrapper(8), initialized {0, -1}), copies the filename via StringCopyWithBufferRealloc, allocates a 12-byte list entry (initialized {node, 0, 1}) and appends it to the list anchored on this: head this[0], tail this[1], cursor this[2], count this[3]++. The loop breaks when LinkedListNodePeek reports no further entry, and LinkedListDestructorWithChildCleanup tears down the iterator before returning.
    // CALL: AllocateStructWithDefaultValues(v9): allocate/initialize the directory iterator state struct on the stack. [callee:0x00565DC0, source:raw]
    // CALL: sub_565F80(lpFileName, 0, a3, 0): initialize file enumeration over the given directory with the extension filter carried by arguments a3. [callee:0x00565F80, source:raw]
    // LOOP: Loop over DirectoryEntryIterator(v9); the loop continues while the iterator yields a next matching entry and exits when it yields none. [callee:0x005662D0, source:raw]
    // CALL: OperatorNewNhMallocWrapper(8): allocate an 8-byte node for the current directory entry. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the node: first dword set to 0, second dword set to -1. [source:raw]
    // CALL: StringCopyWithBufferRealloc(i): copy the iterator's current filename into the node with buffer reallocation as needed. [callee:0x00566650, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12): allocate a 12-byte list entry linking to the node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the list entry: first dword points to the node, second dword set to 0, third byte set to 1. [source:raw]
    // STATE_TRANSITION: Append the entry to the caller's list: if head this[0] is set, link the old tail (this[1]+4) to the new entry; otherwise set head this[0] and cursor this[2] to it; always update tail this[1] to the new entry and increment count this[3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: LinkedListNodePeek(v9): if no further directory entry is pending, break out of the iteration loop. [callee:0x00565F20, source:raw]
    // CALL: LinkedListDestructorWithChildCleanup(v9): destroy the iterator's internal list and child allocations. [callee:0x00565E20, source:raw]
    // RETURN: Return the result of the iterator cleanup call. [function:0x004C84A0, source:raw]

    // Conservative worker pseudocode:
    //   AllocateStructWithDefaultValues(&it);
    //   sub_565F80(lpFileName, 0, a3, 0);
    //   while ((name = DirectoryEntryIterator(&it)) != 0)
    //       node = OperatorNewNhMallocWrapper(8);
    //       node[0] = 0; node[1] = -1;
    //       StringCopyWithBufferRealloc(name);
    //       entry = OperatorNewNhMallocWrapper(12);
    //       entry[0] = node; entry[1] = 0; ((char*)entry)[8] = 1;
    //       if (*this) *(this[1] + 4) = entry; else { *this = entry; this[2] = entry; }
    //       this[1] = entry;
    //       ++this[3];
    //       if (!LinkedListNodePeek(&it)) break;
    //   return LinkedListDestructorWithChildCleanup(&it);
    // UNRESOLVED: The owning object class is not established by the packet; owner stays UnknownObject/UNKNOWN.
    // UNRESOLVED: Whether the list is a music/sound playlist or some other filename collection is unconfirmed; the caller sub_4C83B0 context is not in the packet.
    // UNRESOLVED: The meaning of the entry's third byte set to 1, and of the node's -1 second dword, is unconfirmed.
    // UNRESOLVED: sub_565F80's third argument a3 semantics (extension filter) is described from the caller's perspective only.
}
