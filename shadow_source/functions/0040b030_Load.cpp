// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B030
// Canonical corpus name: StaticCameraSceneLoader
// Owner: StaticCameraSceneLoader [DERIVED]
// Raw source: functions/StaticCameraSceneLoader_0040b030.c

void StaticCameraSceneLoader::Load()
{
    // Loads static camera scene data. Initializes a stack-scratch transform array (128 entries, stride 160) and a small stream-state struct, searches the game-wide string table for "MainView" and stores the hit at this+0x4 if found, then opens the audio stream wrapper for file a2. On success it reads up to 128 "StaticCam"-matching entries via a dispatch loop, allocates a persistent array of 160*v6+4 bytes, initializes v6 entries, stores the array at this+0xC and the count at this+0x10 (and resets this+0x14 to 0), then copies the loaded scratch entries into the allocated storage. Both success and failure paths run a 128-entry stack cleanup (stride 40) and release the stream struct. Returns 0 on load success, 1 on skip/failure.
    // CALL: ZeroInitSmallStruct(v21) initializes the small stream/state struct used by the file helpers. [callee:0x005668B0, source:raw]
    // ASSIGNMENT: Local state init: v3=0 (success result), v28[384] zeroed via memset, stack struct fields v23/v25/v26/v27 = 0 and v24 = 1. [source:raw, function:0x0040B030]
    // LOOP: Initialize 128 temporary transform entries on the stack scratch buffer v30 (stride 160 each) via F_3DTransformObjectInit. [callee:0x004571E0, source:raw]
    // CALL: TwoLevelWideStringSearch(aMainview) searches for the "MainView" string. [callee:0x00544F50, global:0x005BE8E0, source:raw]
    // GUARD: If the "MainView" search result v7 is nonzero, store it into this[1] (this+0x4). [field:this:0x00000004, source:raw]
    // GUARD: If AudioStreamOpen(a2, 1) returns zero the load is aborted: run the stack cleanup loop, call SubCallWithConditionalFieldFree(v21) and return 1. [callee:0x00566B20, source:raw]
    // LOOP: Entry-read loop while ConditionalDispatchBasedOnFlag(v28, 384) stays nonzero: if !sub_5651B0(v22) and sub_565520(aStaticcam, v29, 0) matches a "StaticCam" entry and v6 < 128, call sub_4572B0(v21, v29) to consume it, increment count v6 and advance the scratch pointer by 160. [callee:0x00566CC0, callee:0x005651B0, callee:0x00565520, global:0x005BE928, callee:0x004572B0, source:raw]
    // GUARD: If the initial ConditionalDispatchBasedOnFlag(v28, 384) check fails, or no entries were read (v6 == 0), take the skip path (LABEL_27) and set result v3 = 1. [function:0x0040B030, source:raw]
    // CALCULATION: Computed allocation size = 160 * v6 + 4 (v6 loaded entries at stride 160 plus a count word). [source:raw]
    // CALL: OperatorNewNhMallocWrapper(160 * v6 + 4) allocates the persistent camera-entry array. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: If allocation succeeded: the first word of the allocation is set to the count v6 (header), and v6 entries starting at v12+1 are initialized with stride 40 via F_3DTransformObjectInit. [callee:0x004571E0, source:raw]
    // GUARD: If the allocation failed, the stored array pointer v15 is set to 0; otherwise it points at the initialized entry payload (v12+1). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Persist load result on the instance: this[3] = array pointer, this[4] = entry count v6, this[5] = 0 (reset current index). [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // LOOP: Copy the loaded scratch entries (stride 160) into the allocation with F_2DTransformStructCopy for v16 in 0..this[4]-1. [callee:0x00457B60, field:this:0x00000010, source:raw]
    // CALL: ConditionalFileHandleCloseWithFlagDispatch(v21) closes the underlying file handle after the read loop. [callee:0x00566B90, source:raw]
    // LOOP: Cleanup loop: for 128 iterations call ShortComputation_62a0 on consecutive stack frames stepping back by 40 bytes from the saved return-address area. [callee:0x004562A0, source:raw]
    // CALL: SubCallWithConditionalFieldFree(v21) releases the stream-state struct before returning. [callee:0x005668D0, source:raw]
    // RETURN: Return v3 (0 success, 1 skip/failure); the audio-open-failure branch returns 1 directly. [function:0x0040B030, source:raw]

    // Conservative worker pseudocode:
    //   state = ZeroInitSmallStruct();
    //   zero(scratch_state);
    //   init_transforms(temp[128], stride 160);
    //   hit = TwoLevelWideStringSearch("MainView");
    //   if (hit) this->main_view = hit;
    //   if (AudioStreamOpen(file, 1)) {
    //     if (dispatch_flag(scratch_state)) {
    //       for each entry while dispatch_flag(scratch_state):
    //         if (read_ok && matches("StaticCam", name_buf) && count < 128)
    //           consume_entry(state, name_buf), count++;
    //       if (count > 0) {
    //         alloc = OperatorNew(count * 160 + 4);
    //         if (alloc) { alloc->count = count; init_payload(alloc+1, stride 40); }
    //         this->entries = alloc ? alloc + 1 : 0;
    //         this->count = count;
    //         this->index = 0;
    //         copy_entries(temp, this->entries, this->count);
    //       } else result = 1;
    //     } else result = 1;
    //     close_file(state);
    //   } else return 1;
    //   cleanup_stack_transforms();
    //   free_stream(state);
    //   return result;
    // UNRESOLVED: Callee __alloca_probe (0x005881C0) is a compiler stack-probe artifact for the large frame, not an explicit semantic call.
    // UNRESOLVED: Global dword_8AFE88 (0x008AFE88) is read by callees but not referenced directly in this function body.
    // UNRESOLVED: Exact type of the stream-state struct v21 (ZeroInitSmallStruct / SubCallWithConditionalFieldFree) is unknown; it appears to wrap the file used by the read helpers.
    // UNRESOLVED: Layout of the persistent array at this+0xC is ambiguous: scratch entries are handled at stride 160 while the payload init loop uses stride 40.
    // UNRESOLVED: Purpose of the 384-byte scratch buffer v22 passed to sub_5651B0 is unknown.
    // UNRESOLVED: Destination of F_2DTransformStructCopy calls is inferred from the this[3] allocation; the copy loop reads from the v30 scratch buffer.
}
