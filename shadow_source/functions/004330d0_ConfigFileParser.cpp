// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004330D0
// Canonical corpus name: ConfigFileParser
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConfigFileParser_004330d0.c

void UnknownObject::ConfigFileParser()
{
    // Serializes the auto-load entry linked list to the physics config file. Builds the physics file path into a 256-byte buffer, zero-inits a local file struct, opens the file (after toggling the read-only attribute on a 512-byte name buffer), then walks the linked list from this+0x24 head, writing each node through AutoLoadEntryWriter while advancing through next pointers at node+4; closes the file and runs conditional cleanup. Non-zero PhysicsFilePathBuild result short-circuits the whole write.
    // CALL: PhysicsFilePathBuild(a2, v8, 256) builds the physics file path into the 256-byte local buffer [callee:0x00432CF0, source:raw]
    // GUARD: PhysicsFilePathBuild result guards the whole write: when non-zero the function returns it immediately, skipping all file and list processing [callee:0x00432CF0, source:raw]
    // CALL: ZeroInitSmallStruct(v7) zero-initializes the local file-handle struct [callee:0x005668B0, source:raw]
    // CALL: sub_568620(512) sets the file buffer size on the file handle [callee:0x00568620, source:raw]
    // CALL: ToggleFileReadOnlyAttributeViaWin32API(FileName, 128) toggles the read-only attribute on the 512-byte FileName buffer [callee:0x0058BA36, source:raw]
    // GUARD: File open result from sub_566940(v8, 0, 1, 1) gates the list-write block: entries are only written while the file open succeeds [callee:0x00566940, source:raw]
    // ASSIGNMENT: pCurrent iterator at this+0x24 is seeded from pHead at this+0x1C before the walk begins [field:this:0x00000024, field:this:0x0000001C, source:raw]
    // GUARD: Node-validity gate: the walk proceeds only while the head node pointer and its data/flag word at offset 0 (this+0x28 data area) are non-zero [field:this:0x00000028, field:*(this+0x28):0x00000000, source:raw]
    // LOOP: do/while walk over the auto-load linked list: AutoLoadEntryWriter(v7) writes each node, then the iterator advances by reading the next pointer at node+4 into this+0x24, looping while the next node's data at offset 0 is non-zero [callee:0x00432BF0, field:this:0x00000024, field:*(this+0x28):0x00000000, source:raw]
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(v7) closes the file handle after the list write [callee:0x00566B90, source:raw]
    // RETURN: SubCallWithConditionalFieldFree(v7) performs conditional cleanup with field free and its result is returned; the early guard path returns the PhysicsFilePathBuild result directly [callee:0x005668D0, source:raw]
    // CALL: Invoked by AddVehicleConfigEntryToLinkedList (00433b60) and sub_4B0770 (004b0770) [caller:0x00433B60, caller:0x004B0770, source:raw]

    // Conservative worker pseudocode:
    //   path = PhysicsFilePathBuild(a2, v8, 256);
    //   if (path != 0) return path;
    //   ZeroInitSmallStruct(v7);
    //   sub_568620(512);
    //   ToggleFileReadOnlyAttributeViaWin32API(FileName, 128);
    //   if (sub_566940(v8, 0, 1, 1)) {
    //     node = this[0x24/4] = this[0x1C/4];
    //     if (node && *node) {
    //       do { AutoLoadEntryWriter(v7); next = this[0x24/4];
    //            if (!next) break;
    //            this[0x24/4] = *(next + 4);
    //            if (!this[0x24/4]) break; }
    //       while (*this[0x24/4]);
    //     }
    //     ConditionalFileHandleCloseWithFlagDispatch(v7);
    //   }
    //   return SubCallWithConditionalFieldFree(v7);
    // UNRESOLVED: The linked-list node element layout beyond node+0 (data/flag) and node+4 (next) is not defined by this packet
}
