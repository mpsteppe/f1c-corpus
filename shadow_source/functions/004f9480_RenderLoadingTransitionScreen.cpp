// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9480
// Canonical corpus name: sub_4F9480
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4F9480_004f9480.c

void UnknownObject::RenderLoadingTransitionScreen()
{
    // Renders the loading transition screen. Builds the track-preview LOD bitmap and logo bitmap filenames from the current track path (dword_7CE5D0, falling back to byte_5EA438) and packs name suffixes from the 0x005D6E2C..0x005D6E4C constant block, loads them through MemoryAllocation_cb20 into dword_8AFEB0/dword_8AFEB4/dword_8AFEB8, and renders them via ClippedRenderRegion/RenderDrawOperationWithClipping. Reads the track name via TrackNameReader into SrcStr and draws it as a large-font title at y=117 (font aFtim28wht) and a small-font sub-title from byte_5D6DF8 at y=515 (font aFtim18wht), both right-aligned against x=780. While the loading progress value a2 stays below the threshold v37 = (double)dword_5C329C * 1.5 + 113.0 it draws a progress bar whose fill width is v40 = CRTFtol((*(float*)&a2 * 800.0) / threshold), gated on dword_8AFEBC + 3, and plays a loading sound via SoundAudioPlayback with volume from sub_556730(0). When loading completes it frees all three bitmaps with sub_53CB90, dispatches via GlobalVTableDispatchByParam(0), then stores a2 through FieldSetterWithGuardedCall into dword_7CD8C0. Returns 0. Called by DynMan_Init (0042c1a0) and VidMan_Init (004fa320).
    // GUARD: Null-check on `this`; when null the entire loading-screen body is skipped and the function falls through to the progress update at the end. [function:0x004F9480, source:raw]
    // ASSIGNMENT: Copy the current track path string into local buffer v55: source is dword_7CE5D0 if non-zero, else the static byte_5EA438. Copy runs through the null terminator. [global:0x007CE5D0, global:0x005EA438, source:raw]
    // LOOP: Scan backward from the end of v55 for a '.' (0x2E) and truncate the file extension by writing a null there, stopping if the scan runs off the start of the buffer. [source:raw]
    // ASSIGNMENT: Reset dword_8AFEBC to -999, the progress-bar redraw watermark. [global:0x008AFEBC, source:raw]
    // ASSIGNMENT: Scan backward to the last '\\' (0x5C) in v55 and truncate there, leaving the directory part; then append a name suffix packed from dword_5D6E44, dword_5D6E48 and byte_5D6E4C to form the track-preview bitmap filename in v55. [global:0x005D6E44, global:0x005D6E48, global:0x005D6E4C, source:raw]
    // CALL: Load the track-preview LOD bitmap: MemoryAllocation_cb20(&dword_8AFEB0, v55, 0, 1) and MemoryAllocation_cb20(&dword_8AFEB0, aDfLodBmp, 0, 1). If both calls succeed, dword_8AFEB0 is cleared to 0. [callee:0x0053CB20, global:0x008AFEB0, global:0x005D6E38, source:raw]
    // CALL: When the preview load did not clear dword_8AFEB0 and it is non-zero, read its +28 and +32 fields and render it: GlobalAccessor_5150() then ClippedRenderRegion(0, 0, <w>, 0, 0, <+28>, <+32>, -1, 0), GlobalAccessor_5150() then RenderDrawOperationWithClipping(0, 0, 800, 102, 0), finishing with sub_495080(). [callee:0x00495150, callee:0x00543250, callee:0x00543440, callee:0x00495080, global:0x008AFEB0, source:raw]
    // ASSIGNMENT: Repeat the backward directory scan on v55 and append a second name suffix packed from dword_5D6E2C, dword_5D6E30, word_5D6E34 and byte_5D6E36 to form the second (fallback) LOD bitmap filename. [global:0x005D6E2C, global:0x005D6E30, global:0x005D6E34, global:0x005D6E36, source:raw]
    // CALL: Load the second LOD bitmap: MemoryAllocation_cb20(&dword_8AFEB4, v55, 0, 1) && MemoryAllocation_cb20(&dword_8AFEB4, aDfLod2Bmp, 0, 1); if both succeed, dword_8AFEB4 is cleared to 0. [callee:0x0053CB20, global:0x008AFEB4, global:0x005D6E20, source:raw]
    // CALL: Load the logo LOD bitmap: MemoryAllocation_cb20(&dword_8AFEB8, aLogoLodBmp, 0, 1); if it succeeds, dword_8AFEB8 is cleared to 0. [callee:0x0053CB20, global:0x008AFEB8, global:0x005D6E10, source:raw]
    // GUARD: If byte_7CF29C == 1, run the loading-message setup block. [global:0x007CF29C, source:raw]
    // CALL: Inside the byte_7CF29C == 1 block: if dword_5EB10C is non-zero call its vtable slot +12 (indirect thiscall); then BufferInitWith10fDefaults(flt_5EA618), PositionBasedMessageDisplay(1) and TextOverlayDisplayTimer(flt_5EA618). [callee:0x004186A0, callee:0x0041C4C0, callee:0x004186F0, global:0x005EB10C, global:0x005EA618, source:raw]
    // CALL: TrackNameReader(SrcStr, 255): read the current track name into the 256-byte SrcStr buffer. [callee:0x004C5920, source:raw]
    // CALL: sub_589901(SrcStr): post-process the track-name string. [callee:0x00589901, source:raw]
    // LOOP: Repeated pattern: BinarySearchInStringTable(byte_5EC4C0, SrcStr, byte_5EC4CC); when it returns non-zero, copy SrcStr into byte_5EC4CC up to and including the null terminator. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: ConditionalFontSurfaceCall(aFtim28wht, byte_5EC4CC, &v54, &v53): measure the main-title text (large font) into v54/v53. [callee:0x0053D310, global:0x005D6E04, global:0x005EC4CC, source:raw]
    // CALCULATION: v25 = 780 - v54: right-align the main title against the 800-wide bar area (780 is the text anchor x). [source:raw]
    // CALL: Re-run the BinarySearch/copy of SrcStr into byte_5EC4CC, then sub_53D2E0(aFtim28wht, byte_5EC4CC, v25, 117, GlobalAccessor_5150()): draw the main track-name title at y=117. [callee:0x0053D2E0, callee:0x00495150, callee:0x00423A00, global:0x005D6E04, global:0x005EC4CC, source:raw]
    // LOOP: Copy the sub-title text from byte_5D6DF8 into SrcStr up to and including its null terminator. [global:0x005D6DF8, source:raw]
    // CALL: BinarySearch/copy SrcStr into byte_5EC4CC again, then ConditionalFontSurfaceCall(aFtim18wht, byte_5EC4CC, &v54, &v53): measure the sub-title text (small font) into v54/v53. [callee:0x00423A00, callee:0x0053D310, global:0x005D6DEC, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALCULATION: v33 = 780 - v54: right-align the sub-title text. [source:raw]
    // CALL: Re-run the BinarySearch/copy, then sub_53D2E0(aFtim18wht, byte_5EC4CC, v33, 515, GlobalAccessor_5150()): draw the sub-title at y=515. [callee:0x0053D2E0, callee:0x00495150, callee:0x00423A00, global:0x005D6DEC, global:0x005EC4CC, source:raw]
    // CALCULATION: v37 = (double)dword_5C329C * 1.5 + 113.0: compute the loading-complete threshold from the vehicle count dword_5C329C. [global:0x005C329C, source:raw]
    // CALL: sub_5895A2(v37): transform/clamp the threshold value. [callee:0x005895A2, source:raw]
    // GUARD: If v37 > *(float *)&a2, loading is still in progress (a2 below threshold): run the progress-bar update block. Otherwise run the loading-complete/cleanup block. [source:raw]
    // CALL: sub_44F150(byte_7CA594, 0.0): clear the loading state structure at byte_7CA594. [callee:0x0044F150, global:0x007CA594, source:raw]
    // CALL: If PackedFlagRead(byte_7CA594, 57) is true, re-run the message setup: vtable slot +12 on dword_5EB10C when non-zero, then BufferInitWith10fDefaults(flt_5EA618). [callee:0x0044F460, callee:0x004186A0, global:0x007CA594, global:0x005EB10C, global:0x005EA618, source:raw]
    // CALCULATION: v53 = *(float *)&a2 * 800.0; v39 = (double)dword_5C329C * 1.5 + 113.0; sub_5895A2(v39); v40 = CRTFtol(v53 / v39): compute the progress-bar fill width in pixels (progress fraction of 800, truncated to int). [callee:0x005895A2, callee:0x00587BDC, global:0x005C329C, source:raw]
    // GUARD: If v40 >= dword_8AFEBC + 3 the bar advanced by at least 3 px since the last redraw; only then draw the new bar segment. [global:0x008AFEBC, source:raw]
    // ASSIGNMENT: dword_8AFEBC = v40: record the current bar width as the redraw watermark. [global:0x008AFEBC, source:raw]
    // CALL: If dword_8AFEB0 is non-zero, render the bar fill: GlobalAccessor_5150() then ClippedRenderRegion(0, 0, <w>, 0, 0, v40, 102, -1, 0), then sub_4A1830(). [callee:0x00495150, callee:0x00543250, callee:0x004A1830, global:0x008AFEB0, source:raw]
    // CALL: GlobalAccessor_5150() then RenderDrawOperationWithClipping(v40, 0, 800 - v40, 102, 0): draw the unfilled remainder of the bar. [callee:0x00495150, callee:0x00543440, source:raw]
    // CALL: If dword_8AFEB8 is non-zero, render the logo bitmap at the bar: GlobalAccessor_5150() then ClippedRenderRegion(0, 0, <w>, 0, 0, <+28>, <+32>, 0, 0). [callee:0x00495150, callee:0x00543250, global:0x008AFEB8, source:raw]
    // CALL: sub_495080(): finalize the bar frame render. [callee:0x00495080, source:raw]
    // CALL: ConditionalRatioCompute(&byte_8AC494, 1.0): prepare the loading-sound ratio state. [callee:0x004C88A0, global:0x008AC494, source:raw]
    // CALL: v52 = sub_556730(0): fetch the per-frame ratio used as the sound volume. [callee:0x00556730, source:raw]
    // CALL: SoundAudioPlayback(&byte_8AC494, v52): play the loading audio with the computed volume. [callee:0x004C8650, global:0x008AC494, source:raw]
    // STATE_TRANSITION: Loading-complete branch: if dword_8AFEB4 is non-zero, render it (GlobalAccessor_5150 + ClippedRenderRegion + sub_495080), free it with sub_53CB90(dword_8AFEB4) and set dword_8AFEB4 = 0; likewise free dword_8AFEB0 and dword_8AFEB8 with sub_53CB90 and zero them; then GlobalVTableDispatchByParam(0) hands off to the next game state. [callee:0x0053CB90, callee:0x00495150, callee:0x00543250, callee:0x00495080, callee:0x004C8D90, global:0x008AFEB4, global:0x008AFEB0, global:0x008AFEB8, source:raw]
    // CALL: FieldSetterWithGuardedCall((_DWORD *)dword_7CD8C0, a2): store the loading progress value a2 into the structure at dword_7CD8C0 through the guarded setter. [callee:0x004970E0, global:0x007CD8C0, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (!this) goto finish;
    //   copy_track_path(dword_7CE5D0 ? dword_7CE5D0 : byte_5EA438, v55);
    //   strip_extension(v55); dword_8AFEBC = -999;
    //   trim_to_last_backslash(v55); append_suffix(v55, dword_5D6E44, dword_5D6E48, byte_5D6E4C);
    //   if (MemoryAllocation_cb20(&dword_8AFEB0, v55, 0, 1) && MemoryAllocation_cb20(&dword_8AFEB0, aDfLodBmp, 0, 1)) dword_8AFEB0 = 0;
    //   else if (dword_8AFEB0) { render(dword_8AFEB0, 0, 0, 800, 102); sub_495080(); }
    //   trim_to_last_backslash(v55); append_suffix(v55, dword_5D6E2C, dword_5D6E30, word_5D6E34, byte_5D6E36);
    //   if (MemoryAllocation_cb20(&dword_8AFEB4, v55, 0, 1) && MemoryAllocation_cb20(&dword_8AFEB4, aDfLod2Bmp, 0, 1)) dword_8AFEB4 = 0;
    //   if (MemoryAllocation_cb20(&dword_8AFEB8, aLogoLodBmp, 0, 1)) dword_8AFEB8 = 0;
    //   if (byte_7CF29C == 1) { if (dword_5EB10C) call_vtable_12(dword_5EB10C); BufferInitWith10fDefaults(flt_5EA618); PositionBasedMessageDisplay(1); TextOverlayDisplayTimer(flt_5EA618); }
    //   TrackNameReader(SrcStr, 255); sub_589901(SrcStr);
    //   title_text = SrcStr; lookup_to(byte_5EC4CC, SrcStr);
    //   ConditionalFontSurfaceCall(aFtim28wht, byte_5EC4CC, &v54, &v53); sub_53D2E0(aFtim28wht, byte_5EC4CC, 780 - v54, 117, GlobalAccessor_5150());
    //   subtitle_text = byte_5D6DF8; copy_to(SrcStr, byte_5D6DF8); lookup_to(byte_5EC4CC, SrcStr);
    //   ConditionalFontSurfaceCall(aFtim18wht, byte_5EC4CC, &v54, &v53); sub_53D2E0(aFtim18wht, byte_5EC4CC, 780 - v54, 515, GlobalAccessor_5150());
    //   threshold = (double)dword_5C329C * 1.5 + 113.0; sub_5895A2(threshold);
    //   if (threshold > *(float *)&a2) {
    //     sub_44F150(byte_7CA594, 0.0);
    //     if (PackedFlagRead(byte_7CA594, 57)) { if (dword_5EB10C) call_vtable_12(dword_5EB10C); BufferInitWith10fDefaults(flt_5EA618); }
    //     width = CRTFtol((*(float *)&a2 * 800.0) / threshold);
    //     if (width >= dword_8AFEBC + 3) {
    //       dword_8AFEBC = width;
    //       if (dword_8AFEB0) { ClippedRenderRegion(0, 0, GlobalAccessor_5150(), 0, 0, width, 102, -1, 0); sub_4A1830(); }
    //       RenderDrawOperationWithClipping(width, 0, 800 - width, 102, 0);
    //       if (dword_8AFEB8) ClippedRenderRegion(0, 0, GlobalAccessor_5150(), 0, 0, *(+28), *(+32), 0, 0);
    //       sub_495080();
    //     }
    //     ConditionalRatioCompute(&byte_8AC494, 1.0); SoundAudioPlayback(&byte_8AC494, sub_556730(0));
    //   } else {
    //     if (dword_8AFEB4) { render(dword_8AFEB4); sub_495080(); sub_53CB90(dword_8AFEB4); dword_8AFEB4 = 0; }
    //     if (dword_8AFEB0) { sub_53CB90(dword_8AFEB0); dword_8AFEB0 = 0; }
    //     if (dword_8AFEB8) { sub_53CB90(dword_8AFEB8); dword_8AFEB8 = 0; }
    //     GlobalVTableDispatchByParam(0);
    //   }
    //   FieldSetterWithGuardedCall((_DWORD *)dword_7CD8C0, a2);
    //   finish:
    //   return 0;
    // UNRESOLVED: The packet lists eight read-only globals (flt_59E8A4, flt_59E9D4, flt_5AD270, dword_5EB978, unk_7CDE00, unk_7CE2A4, unk_8AC368, dword_8AFE64) with no textual use in the raw function body; they are likely spurious cross-references. Their evidence refs are recorded in unresolved_evidence_refs.
    // UNRESOLVED: The MemoryAllocation_cb20 resource-load contract appears inverted relative to the resource pointers: when both preview loads succeed, dword_8AFEB0 is cleared to 0, and the 'else if (dword_8AFEB0)' branch renders a non-null bitmap. The exact success semantics are unknown.
    // UNRESOLVED: The 8-9 byte suffix appended to the track path (dword_5D6E44/dword_5D6E48/byte_5D6E4C and the second set) is decoded from raw text only; the exact filename encoding (digit/index pair) is unknown.
    // UNRESOLVED: The indirect thiscall through vtable slot +12 on dword_5EB10C has unknown callee identity.
    // UNRESOLVED: dword_5C329C (vehicle count) feeds the loading-complete threshold, but its exact relationship to total load work is inferred, not proven.
    // UNRESOLVED: The two static callers (DynMan_Init at 0x0042C1A0, VidMan_Init at 0x004FA320) and the absence of a frame-path marker are contextual; the function is reached during the loading transition.
    // UNRESOLVED: sub_5895A2, sub_589901, sub_556730, sub_53D2E0, sub_495080, sub_4A1830, sub_44F150 and sub_53CB90 have fixed names from packet facts only; their precise semantics are not established here.
}
