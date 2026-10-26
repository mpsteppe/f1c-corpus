// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045C0C0
// Canonical corpus name: sub_45C0C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_45C0C0_0045c0c0.c

void UnknownObject::FileScannerPopulate()
{
    // Iterates directory entries from a global iterator list, builds a full path for each entry, dispatches to a filter check selected by argument a4 (or a mode byte at this+1), and appends accepted entries as 12-byte linked-list nodes to the caller-supplied struct whose head/tail live at this+4 / this+8. Returns the last iterated entry pointer.
    // CALL: Initialize directory search: sub_565F80(lpFileName, 1, (int)a3, 1) sets up iteration over lpFileName with pattern prefix a3; return value ignored. [callee:0x00565F80]
    // CALL: Pop the front node from the directory-iterator linked list at global 0x008AD3B0. [callee:0x00565F50, global:0x008AD3B0]
    // LOOP: Iterate directory entries: while DirectoryEntryIterator(&unk_8AD3B0) returns a non-null result, process each entry; exit when it returns null. [callee:0x005662D0, global:0x008AD3B0]
    // CALL: Format the full path into the 512-byte stack buffer v13 with StringFormatWithBufferOverflowCheck(v13, "%s%s", a3, result), concatenating base path a3 with the current entry name; the format literal is the global string at 0x005BE860. [callee:0x0058815F, global:0x005BE860]
    // GUARD: If a4 == 1, run the file validation check sub_45C400(v13, &v12); a non-zero v6 accepts the entry. [callee:0x0045C400]
    // GUARD: Else if a4 == 2, run DataFileCheckSizeQuery(v13, &v12); a non-zero v6 accepts the entry. [callee:0x0045C650]
    // CALL: Fallback when a4 is neither 1 nor 2: UtilityFunction_8a60(*(unsigned byte)(this+1), &v12) selects behavior via the mode byte at this+1; a non-zero v6 accepts the entry. [callee:0x00568A60, field:this:0x00000001]
    // GUARD: If the selected check returned non-zero (v6), accept the entry: walk backward from the end of v13 while the byte at v7 is not 92 ('\\'), trimming to the final path component after the last backslash. [source:raw]
    // CALL: Allocate the 12-byte result node via OperatorNewNhMallocWrapper(12); on success initialize *v8 = 0, v8[1] = -1, copy the trimmed filename through StringCopyWithBufferRealloc(v7), then store the check output v10 = v12 at v9[2]; on allocation failure v9 = 0. [callee:0x00587C03, callee:0x00566650, source:raw]
    // CALL: If the result node v9 is non-null, allocate the 12-byte linked-list node v11 via OperatorNewNhMallocWrapper(12); on success set v11[0] = v9 (data), v11[1] = 0 (next), and byte v11[8] = 1 (flag); on allocation failure v11 = 0. [callee:0x00587C03, source:raw]
    // GUARD: Append v11 to the caller struct's linked list: if head (this+4) is null, set this+4 = v11 and cached tail this+12 = v11; otherwise link the previous tail's next pointer *(*(this+8) + 4) = v11. [field:this:0x00000004, field:this:0x0000000C, field:this:0x00000008, field:*(this+0x8):0x00000004]
    // ASSIGNMENT: Set the tail pointer this+8 = v11 (new last node). [field:this:0x00000008]
    // ASSIGNMENT: Increment the item count at this+16. [field:this:0x00000010]
    // CALL: Peek the next iterator node with LinkedListNodePeek(&unk_8AD3B0); break out of the loop if the peek returns null. [callee:0x00565F20, global:0x008AD3B0]
    // RETURN: Return the last DirectoryEntryIterator / LinkedListNodePeek result (null when the iterator list is exhausted, a node pointer otherwise). [function:0x0045C0C0, source:raw]

    // Conservative worker pseudocode:
    //   sub_565F80(lpFileName, 1, (int)a3, 1);
    //   LinkedListPopFront_5f50(&dirIteratorList);
    //   while ((entry = DirectoryEntryIterator(&dirIteratorList)) != NULL) {
    //     StringFormatWithBufferOverflowCheck(pathBuf, "%s%s", a3, entry);
    //     if (a4 == 1) ok = sub_45C400(pathBuf, &out);
    //     else if (a4 == 2) ok = DataFileCheckSizeQuery(pathBuf, &out);
    //     else ok = UtilityFunction_8a60(*(byte*)(this + 1), &out);
    //     if (ok) {
    //       trim pathBuf to the component after the last '\\';
    //       node = alloc(12);
    //       if (node) { node->f0 = 0; node->f1 = -1; copyComponent(node); node->f2 = out; }
    //       if (node) {
    //         listNode = alloc(12);
    //         if (listNode) { listNode->data = node; listNode->next = 0; listNode->flags = 1; }
    //         if (!head) { head = this + 4; tail = this + 12; } else { oldTail->next = listNode; }
    //         this + 8 = listNode;
    //         ++count;
    //       }
    //     }
    //     if (!LinkedListNodePeek(&dirIteratorList)) break;
    //   }
    //   return lastEntry;
    // UNRESOLVED: Exact meaning of sub_565F80's argument tuple (lpFileName, 1, a3, 1) and what state it establishes in the global iterator list at 0x008AD3B0.
    // UNRESOLVED: Semantics of the byref check output v12 (size, handle, or id) and why it is stored at v9[2].
    // UNRESOLVED: Meaning of the result-node initializers *v8 = 0 and v8[1] = -1, and StringCopyWithBufferRealloc's exact signature and destination.
    // UNRESOLVED: Role of the mode byte at this+1 in the fallback UtilityFunction_8a60 path.
    // UNRESOLVED: Whether the caller (FileScanner 0x0045C240) consumes the returned entry pointer or only the appended list.
    // UNRESOLVED: The value/meaning of the flag byte at v11[8] = 1 and the v11[1] = 0 next pointer initialization.
}
