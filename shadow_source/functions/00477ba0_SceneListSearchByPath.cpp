// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00477BA0
// Canonical corpus name: SceneListSearchByPath
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SceneListSearchByPath_00477ba0.c

void UnknownObject::SceneListSearchByPath()
{
    // Walks a scene list (this+0xF0 head, count at this+0xFC). For each node it dereferences the node value, then a sub-object pointer at value+0x3C, and compares the sub-object's path string (offset 0x104) against dword_7CE5EC, falling back to byte_5EA438 when the global is null. On the first match it stores the index at this+0x174, then calls TrackSceneLoader with the node's name string (value+0x4, defaulting to byte_5EA438) and returns AIW(0). If no match is found and the list is non-empty it falls back to the first entry: this+0x174 = 0, loads the first node's name, and returns AIW(0). Called by GameFilterSetup and GameContentFilterCheck.
    // CALCULATION: Load list count from this[63] (offset 0xFC) as the loop bound. [field:this:0x000000FC, source:raw]
    // LOOP: Iterate index i from 0 while i is below the list count. [field:this:0x000000FC, source:raw]
    // GUARD: Bounds-check i (i >= 0 and i < this[63]) before indexing the list. [field:this:0x000000FC, source:raw]
    // ASSIGNMENT: Load list head pointer from this[60] (offset 0xF0) as the starting node. [field:this:0x000000F0, source:raw]
    // LOOP: Walk the linked list through each node's next pointer (v4[1]) until the i-th node is reached. [source:raw]
    // GUARD: Require the current node and its value (*(this+0xF0)) to be non-null. [field:*(this+0xF0):0x00000000, source:raw]
    // GUARD: Require the node value's sub-object pointer at offset 0x3C to be non-null. [field:*(this+0xF0):0x0000003C, source:raw]
    // CALCULATION: Select compare path: dword_7CE5EC when non-null, otherwise fall back to byte_5EA438. [global:0x007CE5EC, global:0x005EA438, source:raw]
    // GUARD: Match when strcmp of the sub-object's path string at offset 0x104 against the compare path equals zero. [source:raw]
    // ASSIGNMENT: On match, store the matching index i at this[93] (offset 0x174). [field:this:0x00000174, source:raw]
    // ASSIGNMENT: Take the node value's name string at offset 0x4 as the loader path, defaulting to byte_5EA438 when null. [field:*(this+0xF0):0x00000004, global:0x005EA438, source:raw]
    // CALL: Call TrackSceneLoader with the selected name string. [callee:0x004C55B0, source:raw]
    // RETURN: Call AIW(0) and return its result (finalization after scene load). [callee:0x004C54F0, source:raw]
    // STATE_TRANSITION: No match found: reset this[93] (offset 0x174) to 0 to select the fallback (first entry). [field:this:0x00000174, source:raw]
    // ASSIGNMENT: Fallback: take the first node value's name string at offset 0x4 as the loader path. [field:*(this+0xF0):0x00000004, source:raw]
    // CALL: Fallback: call TrackSceneLoader with the first node's name string. [callee:0x004C55B0, source:raw]
    // RETURN: Fallback: call AIW(0) and return its result. [callee:0x004C54F0, source:raw]

    // Conservative worker pseudocode:
    //   count = this[0xFC / 4];
    //   for (i = 0; i < count; i++) {
    //       node = this[0xF0 / 4];           // list head
    //       walk node through next pointers to the i-th node;
    //       if (node && node->value) {
    //           sub = node->value + 0x3C;
    //           if (sub) {
    //               path = dword_7CE5EC ? dword_7CE5EC : byte_5EA438;
    //               if (strcmp(sub + 0x104, path) == 0) {
    //                   this[0x174 / 4] = i;
    //                   name = node->value + 0x4 ? node->value + 0x4 : byte_5EA438;
    //                   TrackSceneLoader(name);
    //                   return AIW(0);
    //               }
    //           }
    //       }
    //   }
    //   // no match: fall back to the first entry
    //   this[0x174 / 4] = 0;
    //   name = first_node_value + 0x4 ? first_node_value + 0x4 : byte_5EA438;
    //   TrackSceneLoader(name);
    //   return AIW(0);
    // UNRESOLVED: this+0xF8 (field:this:0x000000F8) is listed as a read field but no reference to this[62] appears in the raw decompiled source; its role (suggested traversal cursor) is unproven.
    // UNRESOLVED: global:0x008AC368 (unk_8AC368) is absent from the raw decompiled source for this function; its read is not grounded in the packet text.
    // UNRESOLVED: The precise node/value/sub-object struct types and the meaning of the sub-object path string at offset 0x104 are not established beyond the comparison semantics.
}
