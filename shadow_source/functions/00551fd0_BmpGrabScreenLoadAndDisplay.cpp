// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00551FD0
// Canonical corpus name: sub_551FD0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_551FD0_00551fd0.c

void UnknownObject::BmpGrabScreenLoadAndDisplay()
{
    // Loads a GRAB_<seq>.BMP screenshot file from disk (under a config directory), reads its 14-byte file header and 40-byte info header, allocates a 3-bytes-per-pixel staging buffer and an aligned intermediate buffer, creates and configures a render surface whose format depends on this[12], renders it through ClippedRenderRegion, converts the BMP pixel data (RGB555/565/24/32 per this[12]) into the locked surface buffer, then tears the surface down, re-flips the image rows bottom-up, reads the pixel payload directly into the flipped buffer, closes the file and frees temporary allocations. Uses the global counter dword_8CBF48 to make filenames unique. Returns 0 on success, -1 on file-open or surface-setup failure.
    // ASSIGNMENT: Increment global grab counter dword_8CBF48 and snapshot the prior value into v31 for use in the filename sequence number. [global:0x008CBF48]
    // GUARD: If a6 (optional path prefix) is non-null, the format string is "%sGRAB_%.3d.BMP" (prefixed); otherwise it is "GRAB_%.3d.BMP". Both branches produce v56 via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, source:raw]
    // CALL: sub_587DB0 opens the formatted filename v56 relative to the config directory unk_5C2AB0; a non-zero return is stored in v39 as the file handle. [callee:0x00587DB0, global:0x005C2AB0]
    // GUARD: If v39 (file handle) is null: format "Error opening bitmap file %s" with v56 into v57, log it via sub_53C590(-1, v57), and return -1. [callee:0x0058815F, callee:0x0053C590, global:0x005DBDEC]
    // CALCULATION: Compute v7 = a5 * a4 (total pixel count) and v8 = a5 * ((a4 + 3) & ~3) (pixel count using a 4-byte-row-aligned width). [source:raw]
    // ASSIGNMENT: Allocate 3 * a5 * a4 bytes into v40 (BMP pixel buffer) and 3 * v8 bytes into v41 (row-aligned intermediate buffer) via OperatorNewNhMallocWrapper. [callee:0x00587C03]
    // ASSIGNMENT: Fill the local BMP structures (v42..v55): 0x4D42 'BM' signature (v42), file size 3*v8+54 (v43), 54-byte pixel-data offset (v46), 40-byte BITMAPINFOHEADER (v47[0]), width a4 (v47[1]), height a5 (v47[2]), 1 plane (v48), 24 bits per pixel (v49), zero compression/size/resolution fields. [source:raw]
    // CALL: FileReadWrapperWithLock reads the 14-byte BMP file header from handle v39 into the v42 structure. [callee:0x00588678]
    // CALL: FileReadWrapperWithLock reads the 40-byte BMP info header from handle v39 into the v47 structure. [callee:0x00588678]
    // ASSIGNMENT: Allocate a 60-byte surface object via OperatorNewNhMallocWrapper, initialize it with AudioEmitterCreate into v38, then configure it via UtilityFunction_2950(v38, a4, a5, this[12], 17); the fallback path passes a null surface object to UtilityFunction_2950. [callee:0x00587C03, callee:0x005426A0, callee:0x00542950, field:this:0x00000030]
    // GUARD: If UtilityFunction_2950 returns non-zero: log the allocation-error message aErrorAllocatin_0 via sub_53C590(-1, ...) and return -1. [callee:0x0053C590, global:0x005DC0C0]
    // CALL: ClippedRenderRegion(this, a2, a3, v38, 0, 0, a4, a5, -2, 0) renders the configured surface into the requested clipped region. [callee:0x00543250]
    // CALL: ThunkWithArgReorder(v38, flags, 0) locks the surface and returns the pixel buffer pointer, which is stored into v38[0]. [callee:0x00543210]
    // LOOP: Pixel-data conversion switch on this[12]: case 5 converts RGB555, case 6 RGB565, case 7 RGB24, case 8 RGBA32. Each loop converts a5*a4 pixels from the BMP stream into the locked surface buffer, skipping per-row padding using the surface pitch v38[10] at each row boundary. [field:this:0x00000030]
    // CALL: ArgumentReorderWrapper_3230(v38, 0, 0) unlocks the surface after the pixel conversion. [callee:0x00543230]
    // ASSIGNMENT: Teardown of the surface object: clear v38[0], call sub_542E50(v38), EmptyStub_7470(v38), then free it with FreeWrapper_7bcf(v38). [callee:0x00542E50, callee:0x00557470, callee:0x00587BCF]
    // LOOP: Vertical row flip: for each of the a5 rows, qmemcpy 3*a4 bytes from v40 (starting at the last row, bottom-up BMP order) into v41, advancing v29 by the 4-byte-aligned row stride (v28+3)&~3. [source:raw]
    // CALL: FileReadWrapperWithLock(v41, 1, 3*a5*a4, v39) reads the BMP pixel payload directly into the flipped buffer v41. [callee:0x00588678]
    // CALL: FileCloseWithLock(v39) closes the bitmap file. [callee:0x00587D02]
    // ASSIGNMENT: Free the temporary buffers v40 and v41 with FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Return 0 on the success path. [source:raw]
    // RETURN: Return -1 on failure paths: bitmap file could not be opened, or the render surface could not be set up. [source:raw]

    // Conservative worker pseudocode:
    //   seq = dword_8CBF48++;
    //   if (a6) Format(filename, "%sGRAB_%.3d.BMP", a6, seq); else Format(filename, "GRAB_%.3d.BMP", seq);
    //   fh = open_file(filename, &config_dir);
    //   if (!fh) { Format(err, "Error opening bitmap file %s", filename); Log(-1, err); return -1; }
    //   read_file(fh, &file_header, 14); read_file(fh, &info_header, 40);
    //   bmp = alloc(3*w*h); tmp = alloc(3*h*align4(w));
    //   surf = new_surface(); if (init_surface(surf, w, h, this[12], 17)) { Log(-1, alloc_err); return -1; }
    //   render_surface(this, x, y, surf, 0, 0, w, h, -2, 0);
    //   buf = lock_surface(surf, fmt_flags, 0); surf->pixels = buf;
    //   convert_pixels_per_format(this[12], buf, bmp, w, h, surf->pitch);
    //   unlock_surface(surf, 0, 0); surf->pixels = 0;
    //   release_surface(surf);
    //   flip_rows_bottom_up(bmp, tmp, w, h);
    //   read_file(fh, tmp, 3*w*h); close_file(fh);
    //   free(bmp); free(tmp); return 0;
    // UNRESOLVED: Globals aSgrab3dBmp (0x005DC0E8) and aGrab3dBmp (0x005DC0F8) are listed as read globals but their literal strings do not appear in the decompiled body; their role (alternate bitmap filenames) is inferred from the skeleton analysis and is not grounded in the raw text.
    // UNRESOLVED: Callee labels (AudioEmitterCreate, UtilityFunction_2950, ClippedRenderRegion, ThunkWithArgReorder, ArgumentReorderWrapper_3230, EmptyStub_7470) are IDA-proposed names; their semantic roles here are DERIVED, not confirmed.
    // UNRESOLVED: The this[12] pixel-format mapping (5=RGB555, 6=RGB565, 7=RGB24, 8=RGBA32) is derived from the switch structure; the enum semantics are not independently confirmed.
    // UNRESOLVED: Caller RenderScreenSave (0x004B40A0) is a static-callgraph relationship only; no runtime confirmation that this path executes.
}
