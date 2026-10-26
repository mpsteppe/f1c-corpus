// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C83B0
// Canonical corpus name: sub_4C83B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C83B0_004c83b0.c

void UnknownObject::AudioSceneReinit()
{
    // Audio scene reinitialisation. Destroys the playlist linked list (this[0] head): for each node, if its alive flag byte (obj+0x8) is non-zero it calls ConditionalFreeWithBit0Flag on the node's data pointer (obj+0x0), then always frees the node via FreeWrapper_7bcf, walking by the next pointer (obj+0x4). Clears this[0..3]. Rebuilds the .wav and .mp3 playlists by calling sub_4C84A0(aWav, dir) and sub_4C84A0(aMp3, dir), where dir is dword_5EC448 or the fallback byte_5EA438. If the new count (this[3]) is positive, picks a random starting track with RandLCGRandomNumberGenerator and walks the list to set the cursor this[2]. If no tracks exist and InitStatus (dword_8AC4C4) is set, stores the directory in off_5D325C and dispatches a scene-index load through the vtable at dword_8AC4C4+0x48 with dword_5D3254. Called by Sound_Enter.
    // LOOP: Walk the playlist linked list from this[0] (head), reading each node's next pointer (obj+0x4) and the following node's next pointer, until null. [field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000008, field:*(obj+0x4):0x00000004, source:raw]
    // GUARD: If the node's alive flag byte (obj+0x8) is non-zero (guard: alive flag equals 0 is the skip condition) and the node data pointer (obj+0x0) is non-null, call ConditionalFreeWithBit0Flag on the data pointer with flag 1. [guard:0, field:obj:0x00000000, field:obj:0x00000008, callee:0x00404F70, source:raw]
    // CALL: Free the node itself via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Clear the list state: this[0] head, this[1] tail, this[2] cursor and this[3] count are all zeroed. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Resolve the track directory as dword_5EC448 or the fallback byte_5EA438, and rebuild the .wav playlist via sub_4C84A0(aWav, dir). [global:0x005D3364, global:0x005EC448, global:0x005EA438, callee:0x004C84A0, source:raw]
    // CALL: Rebuild the .mp3 playlist via sub_4C84A0(aMp3, dir) using the same directory resolution. [global:0x005D335C, global:0x005EC448, global:0x005EA438, callee:0x004C84A0, source:raw]
    // GUARD: If the playlist count this[3] is positive, draw a random index with RandLCGRandomNumberGenerator and walk the rebuilt list from the head (this[0], advancing by node+0x4) to set the cursor this[2]; an out-of-range index clears the cursor instead. [field:this:0x0000000C, field:this:0x00000008, field:obj:0x00000004, callee:0x005884ED, source:raw]
    // GUARD: If no tracks were found (this[3] == 0) and InitStatus dword_8AC4C4 is non-null, store the resolved directory into off_5D325C and dispatch a scene-index load through the vtable at dword_8AC4C4+72 with argument dword_5D3254, returning the dispatch result. [field:this:0x0000000C, global:0x008AC4C4, global:0x005D325C, global:0x005D3254, global:0x005EC448, global:0x005EA438, source:raw]
    // RETURN: Return the last computed result (playlist-build result, or the scene-index dispatch result). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C83B0(this) {
    //     for (node = *this; node; node = node->next) {
    //       if (node->alive && node->data) ConditionalFreeWithBit0Flag(node->data, 1);
    //       FreeWrapper_7bcf(node);
    //     }
    //     *this = 0; this[1] = 0; this[2] = 0; this[3] = 0;
    //     dir = dword_5EC448 ? (char*)dword_5EC448 : byte_5EA438;
    //     sub_4C84A0(aWav, dir);
    //     result = sub_4C84A0(aMp3, dir);
    //     if (this[3] > 0) {
    //       idx = RandLCGRandomNumberGenerator(0) % this[3];
    //       if (idx < 0 || idx >= this[3]) this[2] = 0;
    //       else for (this[2] = *this; idx > 0; idx--) this[2] = this[2]->next;
    //     }
    //     if (this[3] == 0 && dword_8AC4C4) {
    //       off_5D325C[0] = dir;
    //       return (*(InitStatus->vtable + 72))(off_5D325C, dword_5D3254);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Caller Sound_Enter (0x004C8A20) context and frame-path frequency are not established.
    // UNRESOLVED: Exact class of the playlist node and its data object, and the meaning of the flag 1 passed to ConditionalFreeWithBit0Flag.
    // UNRESOLVED: Semantics of the scene-index vtable dispatch at dword_8AC4C4+72 and of the pair off_5D325C / dword_5D3254 are outside this packet.
}
