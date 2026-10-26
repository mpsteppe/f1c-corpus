// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C28D0
// Canonical corpus name: TrackSceneNodeAdd
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TrackSceneNodeAdd_004c28d0.c

void UnknownObject::TrackSceneNodeAdd()
{
    // Registers a named track scene node in the scene list. Dedup-checks by name via LinkedListSearchByName; when absent, parses the scene data (SceneDataParser), resolves the current scene entry from the scene array (base dword_8AC490, index dword_8AC48C, stride 396), allocates and initializes a 24-byte scene node block, copies two strings out of the scene entry, wraps the block in a 12-byte list node, appends the node to the head/tail list at this+0x10/+0x14/+0x18, increments the node count at this+0x1C, and returns the node found by name (the newly inserted one).
    // GUARD: Dedup guard: if LinkedListSearchByName(this, a2) already finds a node with the requested name, the entire insertion block is skipped. [callee:0x004C2860, source:raw]
    // CALL: SceneDataParser(a2) parses the scene data referenced by the name a2. [callee:0x004C5690, source:raw]
    // CALCULATION: Resolve the current scene data entry: base dword_8AC490 plus 396 times the scene index dword_8AC48C (array stride 396). [global:0x008AC48C, global:0x008AC490, source:raw]
    // GUARD: Only proceed when the resolved scene data entry pointer is non-null. [source:raw]
    // CALL: Allocate a 24-byte scene node block with OperatorNewNhMallocWrapper and initialize it via AlternatingInit when the allocation succeeded. [callee:0x004C03A0, callee:0x00587C03, source:raw]
    // CALL: Copy the scene entry name string (entry+260) into the new node with StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // CALL: Copy the scene entry secondary string (entry+4) with StringCopyWithBufferRealloc. [callee:0x00566650, source:raw]
    // GUARD: Only link the node when the 24-byte scene block was actually allocated and initialized. [source:raw]
    // CALL: Allocate a 12-byte list node with OperatorNewNhMallocWrapper; initialize its payload pointer to the scene node, forward link to 0 and a byte flag to 1. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the new list node: when the list head this+0x10 is non-null, point the previous tail's link (this+0x14 dereferenced at +4) at the new node; otherwise set head this+0x10 and secondary pointer this+0x18 to the new node. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Advance the list tail this+0x14 to the new node and increment the node count this+0x1C. [field:this:0x00000014, field:this:0x0000001C, source:raw]
    // RETURN: Return LinkedListSearchByName(this, a2), resolving to the newly inserted node or to the pre-existing node when the dedup guard skipped insertion. [callee:0x004C2860, source:raw]
    // CALL: Called by SeasonScoringInfoUpdater (0x004C2A80) as part of its scene management. [caller:0x004C2A80, source:raw]

    // Conservative worker pseudocode:
    //   int TrackSceneNodeAdd(NodeList* this, const char* name) {
    //     if (LinkedListSearchByName(this, name)) return LinkedListSearchByName(this, name);
    //     SceneDataParser(name);
    //     entry = dword_8AC490 + 396 * dword_8AC48C;
    //     if (entry) {
    //       sceneNode = OperatorNewNhMallocWrapper(24);
    //       sceneNode = sceneNode ? AlternatingInit(sceneNode) : 0;
    //       StringCopyWithBufferRealloc(entry + 260);
    //       StringCopyWithBufferRealloc(entry + 4);
    //       if (sceneNode) {
    //         listNode = OperatorNewNhMallocWrapper(12);
    //         if (listNode) { *listNode = sceneNode; *(listNode + 4) = 0; *(listNode + 8) = 1; } else listNode = 0;
    //         if (this[4]) *(this[5] + 4) = listNode; else { this[4] = listNode; this[6] = listNode; }
    //         this[5] = listNode; ++this[7];
    //       }
    //     }
    //     return LinkedListSearchByName(this, name);
    //   }
    // UNRESOLVED: Read-only global unk_8AC368 is flagged by packet facts but does not appear in the raw decompiled source; its role here is unknown.
    // UNRESOLVED: The two strings copied out of the scene entry (entry+260 and entry+4) are unnamed; their meaning depends on the scene data layout.
    // UNRESOLVED: The object type of this and the exact list node layout are not defined by this packet.
}
