// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586320
// Canonical corpus name: sub_586320
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_586320_00586320.c

void UnknownObject::InitializeDoubleLinkedListWithSEHCallbackNodes()
{
    // Builds two intrusive linked lists on the receiver. First allocates a 4-byte wrapper, then a 2100-byte buffer whose head dword is set to 2 and whose payload is handed to NTimeCallbackLoopWithSEH_a6eb with BufferedCharIOInit as the init callback and EmptyStub_0170 as the loop callback. One flag=1 node is linked into list 1 (head/tail/working/count at this+0x0/0x4/0x8/0xC) pointing at the buffer payload. A two-step loop (offsets 0 and 1048 into the buffer) then links flag=0 nodes into list 2 (head/tail/working/count at this+0x10/0x14/0x18/0x1C). Called once by sub_584130.
    // ASSIGNMENT: Allocate the 4-byte wrapper object with OperatorNewNhMallocWrapper; on failure the wrapper pointer is nulled [callee:0x00587C03, source:raw]
    // CALL: Allocate the 2100-byte buffer, set its first dword to 2, then run NTimeCallbackLoopWithSEH_a6eb over the buffer payload (size 1048, count 2) with BufferedCharIOInit as the initialization callback and EmptyStub_0170 as the no-op loop callback; the wrapper then stores the buffer payload pointer [callee:0x0058A6EB, callee:0x00587C03, global:0x005876F0, global:0x004B0170, source:raw]
    // ASSIGNMENT: Create the first list-1 node (12 bytes): payload pointer at +0, next link zeroed at +4, flag byte set to 1 at +8; link it as the sole head/tail and bump the count, also recording the working pointer for the first insert [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // LOOP: Two-step loop over byte offsets 0 and 1048 of the buffer payload: each step computes the target address from the payload base, allocates a 12-byte node whose payload points there, sets flag 0 at +8, and appends it to list 2, updating head/tail/working and the count at this+0x10/0x14/0x18/0x1C [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, callee:0x00587C03, source:raw]
    // RETURN: Return the last accumulated count; the function is invoked once by sub_584130 to install the two linked-list structures [caller:0x00584130, function:0x00586320, source:raw]

    // Conservative worker pseudocode:
    //   wrapper = malloc(4);
    //   if (wrapper) {
    //     buffer = malloc(2100);
    //     if (buffer) {
    //       buffer[0] = 2;
    //       NTimeCallbackLoopWithSEH_a6eb(buffer+4, 1048, 2, BufferedCharIOInit, EmptyStub_0170);
    //     }
    //     wrapper[0] = buffer ? buffer+4 : 0;
    //   }
    //   if (wrapper[0]) {
    //     node = alloc_list_node(wrapper[0], flag=1);
    //     insert_list1_head_tail(node, &this+0x0/0x4/0x8/0xC);
    //   }
    //   for (v5 = 0; v5 < 2096; v5 += 1048) {
    //     target = v5 + wrapper[0];
    //     node = alloc_list_node(target, flag=0);
    //     insert_list2(node, &this+0x10/0x14/0x18/0x1C);
    //   }
    //   return this+0x1C;
    // UNRESOLVED: The exact relationship between the two lists (list 1 nodes reference the buffer payload, list 2 nodes reference two interior 1048-byte regions) is described only by the skeleton fill, not provable from the raw decompiled source
    // UNRESOLVED: Global SEH_586320 (0x0059D166) is flagged as read but never appears in the raw decompiled source; it is the function's SEH registration target and its role is unverifiable from this packet
}
