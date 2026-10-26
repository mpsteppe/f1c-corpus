// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050210E
// Canonical corpus name: sub_50210E
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50210E_0050210e.c

void UnknownObject::InitializeMediaSurfaceFromStream()
{
    // Initializes a media-surface context from a binary stream: validates the input with a bounded compare, creates a versioned subsystem ("1.0.5") plus a calloc-like working buffer under a setjmp error frame, parses format metadata (dimensions, pixel depth, format identifier) that maps to a codec identifier, upgrades it to FOURCC-style literals for the 16-bpp case, negotiates a mode selector and row stride, allocates the pixel-data buffer and row-pointer table, and for the paletted format builds a 256-entry RGBA colour-conversion table with optional gamma correction.
    // GUARD: Input validation: if BoundedMemcmpAgainstReference(a2, 0, a3) returns nonzero, fail immediately with -2147467259 [callee:0x00513C38, source:raw]
    // CALL: Create the versioned subsystem: v3 = sub_5118E6("1.0.5", 0, AssertFailHandler, nullsub_4); on failure jump to the cleanup path [callee:0x005118E6, global:0x00502102, global:0x0051DFCA, source:raw]
    // CALL: Allocate the working parse buffer: v56 = CallocLikeAllocator(v3); on failure jump to the cleanup path [callee:0x00513D3D, source:raw]
    // CALL: Install an MSVC setjmp error frame: Setjmp3MSVCJmpBufSave(v57, 0, v39); the parse body runs only on the initial (return 0) invocation [callee:0x0058A7EC, source:raw]
    // CALL: Parse the stream: v42[0]=a2, v42[1]=a3 then sub_513BF9(v57, v42, StreamBinaryRead) reads the byte stream through the StreamBinaryRead callback [callee:0x00513BF9, global:0x005020BF, source:raw]
    // CALL: Process the parsed data into the working buffer: sub_5119E9(v57, v56) [callee:0x005119E9, source:raw]
    // CALL: Read format metadata: sub_5121AE(v57, v56, &v46, &v52, &v49, &v47, 0, 0, 0) yields width v46, height v52, pixel depth v49, and format identifier v47 [callee:0x005121AE, source:raw]
    // ASSIGNMENT: Map the raw format identifier to this[0]: case 2 -> 20, case 3 -> 41, case 4 -> 51, case 6 -> 21, otherwise -> 50 [field:this:0x00000000, source:raw]
    // GUARD: 16-bpp path: if v49 == 16, call AnimationStateFlagSet(v57) and upgrade this[0] to a FOURCC literal: 20 -> 909201952, 21 -> 909201985, 50 -> 909200416, 51 -> 909200449; an unmapped identifier returns -2147467259 [callee:0x00512322, field:this:0x00000000, source:raw]
    // GUARD: Low-depth path: if v49 < 8, call DriverStateFlagSet(v57); additionally if v47 is zero call sub_5124D5(v57) [callee:0x00512334, callee:0x005124D5, source:raw]
    // CALL: Optional scalar setting: if FlagGuardedByteReader(v57, v56, &v44) succeeds call FlagSetterWithGuard_3b36(v57, v56, v44); otherwise GuardedFloatToDoubleConversion reads a double into v41 and CameraRotationStateSetter(v57, 2.2, v41[0]) is invoked [callee:0x00512183, callee:0x00513B36, callee:0x0051215A, callee:0x0051249F, source:raw]
    // GUARD: Codec upgrade: if this[0] != 41 and MaskedReadAt8(v57, v56, 16) succeeds, call sub_5124D5 and upgrade this[0]: 20 -> 21, 50 -> 51, 909200416 -> 909200449, 909201952 -> 909201985 [guard:0, callee:0x00512114, callee:0x005124D5, field:this:0x00000000, source:raw]
    // GUARD: RGB-family flag: if this[0] is 20, 909201952, 21 or 909201985, call BitFlagSetter_2319(v57) [guard:2, callee:0x00512319, source:raw]
    // STATE_TRANSITION: Finalize RGB: if this[0] == 20, call StateFlagSetter_2366(v57, 255, 1) and write 22 into this[0] [guard:2, callee:0x00512366, field:this:0x00000000, source:raw]
    // CALL: Finalize the remaining parse: ConditionalDispatchWithGuard(v57, v56) [callee:0x00511B5C, source:raw]
    // CALCULATION: Dispatch chain on this[0]: values greater than 51 are treated as FOURCC literals and decoded via offset arithmetic into mode selector v55 (1/3/4); 51 yields 2; 20/21/22/41 are decoded via small-subtraction chain into v55 [guard:1, guard:4, source:raw]
    // CALL: Mode validation: v13 = ShortComputation_2144(v57, v56); if v55 != v13 the format does not match the parse result and the function fails to the cleanup path [callee:0x00512144, source:raw]
    // ASSIGNMENT: Commit dimensions and valid flag: this[3] = v46 (width), this[4] = v52 (height), this[5] = 1 [field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, source:raw]
    // CALL: Compute the row stride: v18 = ShortComputation_212e(v57, v56); this[12] = v18 and this[13] = 0 [callee:0x0051212E, field:this:0x00000030, field:this:0x00000034, source:raw]
    // GUARD: Allocation precondition: buffer/palette allocation proceeds only when this[16] (evaluated as this[16] == 0) is nonzero [guard:5, field:this:0x00000040, source:raw]
    // CALL: Allocate the pixel-data buffer: v20 = OperatorNewNhMallocWrapper(v52 * v18) stored at this[1]; on failure jump to cleanup; this[14] is set to 1 [callee:0x00587C03, field:this:0x00000004, field:this:0x00000038, source:raw]
    // CALL: Allocate the row-pointer table: v51 = OperatorNewNhMallocWrapper(4 * v52); on failure jump to cleanup [callee:0x00587C03, source:raw]
    // LOOP: Build row pointers: for i in [0, v52) set v51[i] = this[1] + i * this[12] [source:raw]
    // CALL: Register the row-pointer table with the subsystem: sub_511F23(v57, v51) [callee:0x00511F23, source:raw]
    // GUARD: Paletted path: when this[0] == 41, read the colour/alpha tables and build the 256-entry RGBA conversion table [guard:3, source:raw]
    // CALL: Read the 24-bit colour field: if MaskedReadAt8(v57, v56, 8) succeeds, GuardedFieldReader(v57, v56, &v54, &v50) reads the colour source and entry count [callee:0x00512114, callee:0x0051227F, source:raw]
    // CALL: Read the alpha/RGB table: if MaskedReadAt8(v57, v56, 16) succeeds, MediaFormatQuery(v57, v56, &v43, &v48, 0) reads the alpha source and entry count [callee:0x00512114, callee:0x005122B2, source:raw]
    // GUARD: Gamma precondition: if the float at v57+304 or v57+308 is <= 0.000001, build an identity table v40[j]=j; otherwise build a gamma-corrected table [source:raw]
    // LOOP: Gamma table build: v41[1] = 1.0 / (v57+308 float * v57+304 float); for j in [0, 256) call sub_5881F0((double)j * 0.00392156862745098) then store CRTFtol(v23 * 255.0 + 0.5) into v40[j] [callee:0x005881F0, callee:0x00587BDC, source:raw]
    // CALL: Allocate the palette buffer: this[2] = OperatorNewNhMallocWrapper(1024); on failure jump to cleanup; this[15] is set to 1 [callee:0x00587C03, field:this:0x00000008, field:this:0x0000003C, source:raw]
    // LOOP: Palette fill 1: for entries up to v48, write 4 bytes per entry (three gamma-table indices from v54/v43 plus the alpha byte from v43) [source:raw]
    // LOOP: Palette fill 2: for entries from v48 up to v50, write three gamma-table indices with alpha forced to 255 [source:raw]
    // LOOP: Palette fill 3: for any remaining entries up to a full 256 (1024 bytes), write four opaque-white bytes each [source:raw]
    // RETURN: Success and cleanup: on success return 0; on any failure return -2147467259 or -2147024882; the shared cleanup path calls ThreeObjectCleanupChain(&v57, &v56, 0) when v57 is set and FreeWrapper_7bcf(v51) when v51 is set [callee:0x00512093, callee:0x00587BCF, source:raw]

    // Conservative worker pseudocode:
    //   if (BoundedMemcmpAgainstReference(a2, 0, a3)) return -2147467259;
    //   v57 = sub_5118E6("1.0.5", 0, AssertFailHandler, nullsub_4);
    //   if (!v57) goto cleanup;
    //   v56 = CallocLikeAllocator(v57);
    //   if (!v56) goto cleanup;
    //   if (!Setjmp3MSVCJmpBufSave(v57, 0, &jmp)) {
    //       parse(a2, a3) into v56 via StreamBinaryRead;
    //       read width v46, height v52, depth v49, format v47;
    //       this[0] = (v47==2)?20 : (v47==3)?41 : (v47==4)?51 : (v47==6)?21 : 50;
    //       if (v49 == 16) { AnimationStateFlagSet(v57); this[0] = fourcc[this[0]] or fail; }
    //       if (v49 < 8) DriverStateFlagSet(v57);
    //       if (!v47 && v49 < 8) sub_5124D5(v57);
    //       if (FlagGuardedByteReader(v57, v56, &v44)) FlagSetterWithGuard_3b36(v57, v56, v44);
    //       else if (GuardedFloatToDoubleConversion(v57, v56, &v41)) CameraRotationStateSetter(v57, 2.2, v41[0]);
    //       if (this[0] != 41 && MaskedReadAt8(v57, v56, 16)) { sub_5124D5(v57); upgrade this[0] (20->21, 50->51, fourcc pairs); }
    //       if (this[0] in {20, 909201952, 21, 909201985}) BitFlagSetter_2319(v57);
    //       if (this[0] == 20) { StateFlagSetter_2366(v57, 255, 1); this[0] = 22; }
    //       ConditionalDispatchWithGuard(v57, v56);
    //       v55 = dispatch(this[0]);
    //       if (v55 != ShortComputation_2144(v57, v56)) return -2147467259;
    //       this[3] = v46; this[4] = v52; this[5] = 1;
    //       this[12] = ShortComputation_212e(v57, v56); this[13] = 0;
    //       if (this[16]) {
    //           this[1] = OperatorNewNhMallocWrapper(v52 * this[12]);
    //           if (!this[1]) goto cleanup;
    //           this[14] = 1;
    //           v51 = OperatorNewNhMallocWrapper(4 * v52);
    //           if (!v51) goto cleanup;
    //           for (i = 0; i < v52; ++i) v51[i] = this[1] + i * this[12];
    //           sub_511F23(v57, v51);
    //           if (this[0] == 41) {
    //               if (MaskedReadAt8(v57, v56, 8)) GuardedFieldReader(v57, v56, &v54, &v50);
    //               if (MaskedReadAt8(v57, v56, 16)) MediaFormatQuery(v57, v56, &v43, &v48, 0);
    //               if (v57+304 <= 0.000001 || v57+308 <= 0.000001) identity table v40[j]=j;
    //               else gamma table v40[j] = CRTFtol(sub5881(v57+308*v57+304, j) * 255.0 + 0.5);
    //               this[2] = OperatorNewNhMallocWrapper(1024);
    //               if (!this[2]) goto cleanup;
    //               this[15] = 1;
    //               expand v54/v43 RGB+alpha entries through v40 into this[2], pad to 256 opaque entries;
    //           }
    //       }
    //       return 0;
    //   }
    //   cleanup:
    //       if (v57) ThreeObjectCleanupChain(&v57, &v56, 0);
    //       if (v51) FreeWrapper_7bcf(v51);
    //       return error;
    // UNRESOLVED: Seven read-only globals (dbl_59E420, dbl_59E880, dbl_5ADB58, dbl_5ADB60, dbl_5ADB68, dbl_5ADB70, a105) are flagged by packet facts but appear nowhere in the raw decompiled source text
    // UNRESOLVED: The ABI lead name Graphics_Driver_Hardware_Cap_Detection (LEGACY) conflicts with the media-surface/stream semantics of this function and is treated as a stale label
    // UNRESOLVED: The exact meaning of mode selector v55 and its match against ShortComputation_2144 output is inferred from the dispatch/compare pattern only
    // UNRESOLVED: The floats at v57+304 and v57+308 (gamma scale parameters) are read via raw offsets with no named field references
    // UNRESOLVED: The CameraRotationStateSetter name does not obviously match a call passing 2.2 and a converted double; the name may be stale
}
