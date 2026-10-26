// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00432E70
// Canonical corpus name: AutoLoadEntryListLoader
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AutoLoadEntryListLoader_00432e70.c

void UnknownObject::AutoLoadEntryListLoader()
{
    // Loads an auto-load entry list from the config file at byte_7CE498. Frees the existing entry linked list (destroying physics objects for nodes flagged as having content), resets the head/tail/first/count fields, builds a physics file path, and when AudioStreamOpen succeeds reads lines via ConditionalDispatchBasedOnFlag. Each line passing the sub_5651B0/sub_588410 filters becomes a 28-byte session-config object (init by SessionConfigDefaultInit); TrackSessionClassesReader rejects objects are freed, accepted ones are wrapped in a 12-byte node (data, next=0, flag=1) and appended to the list. Closes the file handle, finalizes via SubCallWithConditionalFieldFree, sets this+0x18 completion flag to 1, and returns. Called by LookUpVehicleConfigEntry and PlayerFileInit.
    // CALL: sub_432DF0((const char**)this, &byte_7CE498) reads the auto-load config from the path stored at byte_7CE498. [callee:0x00432DF0, global:0x007CE498, source:raw]
    // LOOP: Traverse the existing list starting at this+0x1C: for each node read its data pointer (node+0), flag (node+8) and next pointer (node+4). [field:this:0x0000001C, field:*(this+0x1C):0x00000000, field:*(this+0x1C):0x00000008, field:*(*(this+0x1C)+0x4):0x00000004, source:raw]
    // CALL: If the node flag is set and its data pointer is non-null, PhysicsObjectDestructor(data) then FreeWrapper_7bcf(data) releases the physics object. [callee:0x00433090, callee:0x00587BCF, source:raw]
    // CALL: FreeWrapper_7bcf(node) frees each list node itself during the cleanup walk. [callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Reset the list fields: this+0x1C (head), this+0x20 (tail), this+0x24 (first), this+0x28 (count) all set to 0. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, source:raw]
    // CALL: result = PhysicsFilePathBuild(&byte_7CE498, v18, 256) builds the physics file path; guard: on non-zero result skip the whole load block. [callee:0x00432CF0, global:0x007CE498, source:raw]
    // CALL: ZeroInitSmallStruct(v10) resets the parse state; if AudioStreamOpen(v18, 1) succeeds, begin reading. [callee:0x005668B0, callee:0x00566B20, source:raw]
    // LOOP: Zero v17 with memset, initialize the local parse fields (v13=1), and loop while ConditionalDispatchBasedOnFlag(v17, 384) reads the next entry. [callee:0x00566CC0, source:raw]
    // GUARD: Skip the entry unless both sub_5651B0(v11) and sub_588410(v17, off_5C3F88[0]) return false. [callee:0x005651B0, callee:0x00588410, global:0x005C3F88, source:raw]
    // CALL: v7 = OperatorNewNhMallocWrapper(28); on success init its fields (0, -1, 0, -1, 0, -1) then SessionConfigDefaultInit(v7) fills defaults. [callee:0x00587C03, callee:0x00432CC0, source:raw]
    // CALL: If TrackSessionClassesReader(v8, v10) succeeds: re-init via SessionConfigDefaultInit(v8), free v8[5], v8[2] and *v8, then FreeWrapper_7bcf(v8) discards the object. [callee:0x00432A70, callee:0x00432CC0, callee:0x00587BCF, source:raw]
    // ASSIGNMENT: Otherwise allocate a 12-byte node v9: data = v8, next = 0, flag byte = 1. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Append the node to the list: if head this+0x1C is non-empty set tail's next (*(this+0x20)+0x4) = v9, else set head this+0x1C and first this+0x24 = v9; then tail this+0x20 = v9 and increment count this+0x28. [field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:*(this+0x20):0x00000004, source:raw]
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(v10) closes the open file handle. [callee:0x00566B90, source:raw]
    // CALL: result = SubCallWithConditionalFieldFree(v10) finalizes the parse state and produces the result. [callee:0x005668D0, source:raw]
    // ASSIGNMENT: *(this+0x18) = 1 sets the completion flag; return result. [field:this:0x00000018, source:raw]

    // Conservative worker pseudocode:
    //   sub_432DF0(this, &byte_7CE498);
    //   for (node = *(int*)(this+0x1C); node; node = next) {
    //       next = *(int*)(node+4);
    //       if (*(char*)(node+8) && *(void**)node) {
    //           PhysicsObjectDestructor(*(void**)node);
    //           FreeWrapper_7bcf(*(void**)node);
    //       }
    //       FreeWrapper_7bcf(node);
    //   }
    //   *(int*)(this+0x1C) = *(int*)(this+0x20) = *(int*)(this+0x24) = *(int*)(this+0x28) = 0;
    //   result = PhysicsFilePathBuild(&byte_7CE498, v18, 256);
    //   if (!result) {
    //       ZeroInitSmallStruct(v10);
    //       if (AudioStreamOpen(v18, 1)) {
    //           while (ConditionalDispatchBasedOnFlag(v17, 384)) {
    //               if (!sub_5651B0(v11) && !sub_588410(v17, off_5C3F88[0])) {
    //                   obj = OperatorNewNhMallocWrapper(28);
    //                   if (obj) {
    //                       init_fields(obj);
    //                       SessionConfigDefaultInit(obj);
    //                       if (TrackSessionClassesReader(obj, v10)) {
    //                           SessionConfigDefaultInit(obj);
    //                           free_and_drop(obj);
    //                       } else {
    //                           node = OperatorNewNhMallocWrapper(12);
    //                           if (node) { *(void**)node = obj; *(int*)(node+4) = 0; *(char*)(node+8) = 1; }
    //                           append_node(this, node);
    //                       }
    //                   }
    //               }
    //           }
    //           ConditionalFileHandleCloseWithFlagDispatch(v10);
    //       }
    //       result = SubCallWithConditionalFieldFree(v10);
    //   }
    //   *(char*)(this+0x18) = 1;
    //   return result;
    // UNRESOLVED: abi:lead names this function AutoLoadEntry_List_Loader (LEGACY); canonical name AutoLoadEntryListLoader retained.
    // UNRESOLVED: off_5C3F88 is labeled Off_ButtonBinding by the existing analysis but that labeling is not grounded in this function's raw source.
    // UNRESOLVED: The exact parse-state contracts of ConditionalDispatchBasedOnFlag / sub_588410 and the 28-byte session-config object layout are unknown.
    // UNRESOLVED: The relationship between this+0x24 (first) and this+0x1C (head) is transcribed from source but their distinct meanings are not independently confirmed.
}
