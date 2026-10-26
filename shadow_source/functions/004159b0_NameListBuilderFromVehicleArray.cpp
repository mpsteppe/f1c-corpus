// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004159B0
// Canonical corpus name: NameListBuilderFromVehicleArray
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NameListBuilderFromVehicleArray_004159b0.c

void UnknownObject::NameListBuilderFromVehicleArray()
{
    // Builds a deduplicated vehicle-name linked list from the global vehicle array (dword_8AC390 count, dword_8AC394 base, stride 1060), clears the existing commentary list at this[4..7], then allocates one 172-byte commentary node per unique name, initializes its sub-struct arrays and text-format block, copies the name string, counts matching vehicles, sets up commentary paths via sub_414A90, and appends each node to a doubly-linked list before freeing the temporary name list.
    // LOOP: Iterate the vehicle array from dword_8AC394 over dword_8AC390 entries using stride 1060, reading the name byte at entry+124 for dedup collection. [global:0x008AC390, global:0x008AC394, source:raw]
    // GUARD: Skip entries whose name byte at vehicle+124 is zero. [source:raw]
    // CALL: Compare the candidate name against each existing node's string via sub_588410, using byte_5EA438 as the null-pointer fallback string, to detect duplicates. [callee:0x00588410, global:0x005EA438]
    // ASSIGNMENT: For a new unique name, allocate an 8-byte node via OperatorNewNhMallocWrapper and copy the name string into it with StringCopyWithBufferRealloc. [callee:0x00587C03, callee:0x00566650]
    // ASSIGNMENT: Allocate a 12-byte list node wrapping the name node, set next to null and flag byte to 1, then link it into the name list (head, tail, counter). [callee:0x00587C03, source:raw]
    // LOOP: Traverse the existing commentary list from this[4] via the next pointer at node+4, destroying each node with MemoryAllocation_8c10(1), then zero this[4..7] (fields +0x10..+0x1C) as cleanup. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:*(this+0x14):0x00000004, callee:0x00418C10]
    // LOOP: For each of the name-list entries, allocate a 172-byte commentary node and initialize its sub-struct arrays via sub_401000 with SmallEntryStructInit, plus the text-format block via TextFormatStructInitializer_4d70. [callee:0x00587C03, callee:0x00401000, global:0x00415520, callee:0x00414D70]
    // ASSIGNMENT: Copy the i-th name string from the temporary name list into the commentary node with StringCopyWithBufferRealloc, using byte_5EA438 as the null fallback. [callee:0x00566650, global:0x005EA438]
    // LOOP: Count vehicles in the array whose +124 name matches the commentary node name via sub_588410 (with NullSafePointerDereference on the node) and store the count into the node's index field. [callee:0x00588410, callee:0x00415C30, global:0x008AC390, global:0x008AC394]
    // CALL: Set up the commentary PWS/TV paths via sub_414A90 for each new node and append the node to the output list with DoublyLinkedListAppend(node, 1). [callee:0x00414A90, callee:0x00434030]
    // LOOP: Free the temporary name list by walking the next pointers and calling DestructorWithDoubleFreePattern(1) on each node. [callee:0x00418D60]
    // RETURN: Return 0 to signal successful list rebuild. [function:0x004159B0, source:raw]

    // Conservative worker pseudocode:
    //   collect unique vehicle names from dword_8AC394[0..dword_8AC390) into a linked list (dedup via sub_588410)
    //   clear existing commentary list at this[4] and zero this[4..7]
    //   for each unique name: allocate 172-byte commentary node, init sub-structs and text-format block, copy name, count matching vehicles, call sub_414A90, append via DoublyLinkedListAppend
    //   free temporary name list
    //   return 0
    // UNRESOLVED: Purpose and layout of the 172-byte commentary node beyond sub-struct arrays and text-format block.
    // UNRESOLVED: What sub_414A90 writes into each commentary node (PWS/TV path fields are only described by its name).
    // UNRESOLVED: Significance of the constant argument 1 passed to MemoryAllocation_8c10 and DestructorWithDoubleFreePattern.
    // UNRESOLVED: Called from ShortComputation_5090 (0x00415090); role of the this+0x10..0x1C fields as list bookkeeping is inferred, not packet-confirmed.
}
