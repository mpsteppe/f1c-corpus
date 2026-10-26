// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040B850
// Canonical corpus name: MainView
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MainView_0040b850.c

void UnknownObject::LoadMainViewCameras()
{
    // Loads the main-view camera set. Zero-initializes a 128-entry temporary camera array (stride 208) and scratch state, searches for the 'MainView' string via TwoLevelWideStringSearch(dword_8AFE88, aMainview) and stores the result into this+4, then opens an audio stream. While ConditionalDispatchBasedOnFlag(v22, v29, 384) is true it matches 'TrackingCam' entries (sub_5651B0, sub_565520) and copies each match (up to 128) into the temp array via sub_4585E0. If any entries were loaded, OperatorNewNhMallocWrapper(208*v6+4) allocates a persistent array that is stored into this+12 with the count in this+16 and an index of 0 in this+20, and the temp entries are copied into it via sub_459330. On failure or empty result the temporary objects are disposed via VTableInitCallChain and SubCallWithConditionalFieldFree and the function returns 1; on success it returns 0.
    // CALL: ZeroInitSmallStruct(v22) initializes the local context object and memset(v29, 0, 384) clears the scratch buffer [callee:0x005668B0, source:raw]
    // LOOP: Initializes the 128 temporary camera entries (stride 208) in v31 via F_3DTransformObjectInit_83b0 on each entry [callee:0x004583B0]
    // CALL: v7 = TwoLevelWideStringSearch(dword_8AFE88, aMainview) searches for the 'MainView' string; when non-null the handle is stored into this+4 [callee:0x00544F50, global:0x008AFE88, global:0x005BE8E0, field:this:0x00000004]
    // GUARD: AudioStreamOpen(v22, a2, 1) opens the stream; on failure 128 entries are disposed with VTableInitCallChain (stride 52) and SubCallWithConditionalFieldFree(v22) releases the context before returning 1 [callee:0x00566B20, callee:0x004584A0, callee:0x005668D0]
    // LOOP: Entry loop: while ConditionalDispatchBasedOnFlag(v22, v29, 384) is true, if sub_5651B0(v23) is false and sub_565520(v23, aTrackingcam, v30, 0) matches and v6 < 128, sub_4585E0 copies the match into temp entry v10 (stride 208) and increments v6 [callee:0x00566CC0, callee:0x005651B0, callee:0x00565520, global:0x005BE934, callee:0x004585E0]
    // GUARD: Empty-result guard: when v6 <= 0, 128 entries are disposed with VTableInitCallChain, SubCallWithConditionalFieldFree(v22) releases the context, and the function returns 1 [callee:0x004584A0, callee:0x005668D0]
    // ASSIGNMENT: v11 = OperatorNewNhMallocWrapper(208*v6 + 4) allocates the persistent array with a count header; when non-null the header stores v6 and v6 entries are initialized with F_3DTransformObjectInit_83b0 (stride 208); the array pointer is stored into this+12, the count into this+16 and 0 into this+20 [callee:0x00587C03, callee:0x004583B0, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014]
    // LOOP: Persist loop: for v3 from 0 while v3 < this+16, sub_459330(v15 + this+12, &v31[v15]) copies each temp entry (stride 208) into the persistent array [callee:0x00459330, field:this:0x0000000C, field:this:0x00000010]
    // CALL: Success cleanup: 128 entries are disposed with VTableInitCallChain (stride 52), SubCallWithConditionalFieldFree(v22) releases the context, and the function returns 0 [callee:0x004584A0, callee:0x005668D0]
    // CALL: __alloca_probe is invoked for the large local frame (v31 is 26624 bytes), establishing the stack-probe guard pages [callee:0x005881C0]

    // Conservative worker pseudocode:
    //   ZeroInitSmallStruct(v22);
    //   memset(v29, 0, 384);
    //   init 128 temp camera entries in v31 via F_3DTransformObjectInit_83b0 (stride 208);
    //   if (v7 = TwoLevelWideStringSearch(dword_8AFE88, aMainview)) this[1] = v7;
    //   if (!AudioStreamOpen(v22, a2, 1)) { dispose temp objects; SubCallWithConditionalFieldFree(v22); return 1; }
    //   while (ConditionalDispatchBasedOnFlag(v22, v29, 384))
    //     if (!sub_5651B0(v23) && sub_565520(v23, aTrackingcam, v30, 0) && v6 < 128)
    //       { sub_4585E0(temp_entry, v22, v30); v6++; }
    //   if (v6 <= 0) { dispose temp objects; SubCallWithConditionalFieldFree(v22); return 1; }
    //   v11 = OperatorNewNhMallocWrapper(208*v6 + 4);
    //   *v11 = v6; init v6 entries via F_3DTransformObjectInit_83b0;
    //   this[3] = v11 + 1; this[4] = v6; this[5] = 0;
    //   for (i = 0; i < this[4]; i++) sub_459330(this[3] + i*208, &v31[i*208]);
    //   dispose temp objects; SubCallWithConditionalFieldFree(v22);
    //   return 0;
    // UNRESOLVED: The matching semantics of TwoLevelWideStringSearch and sub_565520 against the 'MainView'/'TrackingCam' literals (aMainview 0x005BE8E0, aTrackingcam 0x005BE934) are not established by this packet.
    // UNRESOLVED: The per-entry layout of the 208-byte camera record and the copy performed by sub_4585E0/sub_459330 are DERIVED from the stride and this+12 array placement, not confirmed.
    // UNRESOLVED: dword_8AFE88 is a global handle passed to TwoLevelWideStringSearch; its type and meaning are not established here.
}
