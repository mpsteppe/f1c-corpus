// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055A790
// Canonical corpus name: sub_55A790
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55A790_0055a790.c

void UnknownObject::SceneInstanceLinkParser()
{
    // Parses one Instance block from a scene-file line buffer. Allocates a 264-byte node struct via OperatorNewNhMallocWrapper, initializes it through sub_548E20, stores the owning scene object pointer at node+0x0, then reads lines until the buffer reports end (status 1 or 3, with status 2 lines skipped). For each line it queries tokens Type, Instance, Light, Link and Adjacent through sub_559E20 and, when present, appends the value via StringListAppend, sub_5491D0, LinkedListStringInsert or StringCopyNodeAlloc respectively. The Type token selects a storage flag (64 for aStorage, 128 for aInstance), the name a2 is copied into the node with SelfCopyStringWithOffset, and the node is appended to the scene object's master linked list via LinkedListAppend_a270. Returns 0.
    // ASSIGNMENT: Initialize local storage flag v7 to 0 before parsing. [source:raw]
    // CALL: Allocate 264 bytes with OperatorNewNhMallocWrapper and, on success, initialize the node through sub_548E20, storing the result in v5. [callee:0x00548E20, callee:0x00587C03, source:raw]
    // ASSIGNMENT: Store the owning scene object pointer this at node+0x0. [source:raw]
    // LOOP: Read lines from the scene buffer while LineReaderFromBuffer(a3) does not return 1 (end-of-buffer). [callee:0x00559A70, source:raw]
    // GUARD: Break out of the line loop when the buffer status *a3 equals 3 (EOF); skip processing lines with status 2. [source:raw]
    // CALL: Query the Type token into v8 via sub_559E20(a3, aType, v8, 0); the result selects the storage flag later. [global:0x005DC274, callee:0x00559E20, source:raw]
    // CALL: If the Instance token is present, append its value string to the node with StringListAppend. [global:0x005CD620, callee:0x00559E20, callee:0x00549020, source:raw]
    // CALL: If the Light token is present, store its value in the node through sub_5491D0. [global:0x005DC298, callee:0x00559E20, callee:0x005491D0, source:raw]
    // CALL: If the Link token is present, insert its value string into the node's linked list with LinkedListStringInsert. [global:0x005DC290, callee:0x00559E20, callee:0x005492F0, source:raw]
    // CALL: If the Adjacent token is present, allocate a copy of its value string and attach it with StringCopyNodeAlloc. [global:0x005DC284, callee:0x00559E20, callee:0x005493B0, source:raw]
    // GUARD: Select the storage flag from the Type token: v7 = 64 when it equals aStorage, v7 = 128 when it equals aInstance. [global:0x005DC27C, global:0x005CD620, source:raw]
    // CALL: Copy the instance name a2 into the node with SelfCopyStringWithOffset, using the storage flag v7 as the type offset. [callee:0x00548E80, source:raw]
    // CALL: Append the completed node to the owning scene object's master list with LinkedListAppend_a270(this, v5). [callee:0x0054A270, source:raw]
    // RETURN: Return 0 always. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_55A790(SceneObj* this, char* name, Buffer* buf) {
    //     int storage = 0;
    //     Node* node = sub_548E20(OperatorNewNhMallocWrapper(264));
    //     node->owner = this;
    //     char typeName[16], value[256];
    //     while (LineReaderFromBuffer(buf) != 1) {
    //       if (*buf == 3) break;
    //       if (*buf == 2) continue;
    //       sub_559E20(buf, aType, typeName, 0);
    //       if (sub_559E20(buf, aInstance, value, 0)) StringListAppend(node, value);
    //       if (sub_559E20(buf, aLight, value, 0)) sub_5491D0(node, value);
    //       if (sub_559E20(buf, aLink, value, 0)) LinkedListStringInsert(node, value);
    //       if (sub_559E20(buf, aAdjacent, value, 0)) StringCopyNodeAlloc(node, value);
    //     }
    //     if (!strcmp(typeName, aStorage)) storage = 64;
    //     if (!strcmp(typeName, aInstance)) storage = 128;
    //     SelfCopyStringWithOffset(node, name, storage);
    //     LinkedListAppend_a270(this, node);
    //     return 0;
    //   }
    // UNRESOLVED: Meaning of LineReaderFromBuffer status codes 1/2/3 and the buffer state machine.
    // UNRESOLVED: Semantics of sub_559E20's token query and the exact structure of the 264-byte node.
    // UNRESOLVED: What the storage flag values 64 and 128 encode (derived: storage vs instance classification).
    // UNRESOLVED: Behaviors of sub_5491D0 (light) and sub_548E20 (node init) are unknown.
}
