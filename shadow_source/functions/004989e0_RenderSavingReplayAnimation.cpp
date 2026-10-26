// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004989E0
// Canonical corpus name: sub_4989E0
// Owner: SaveReplayUiRenderer [GUESS]
// Raw source: functions/sub_4989E0_004989e0.c

void SaveReplayUiRenderer::RenderSavingReplayAnimation()
{
    // Renders the "saving replay" overlay when a non-empty message string is supplied. Two paths: (1) if a saving-replay entry is found on the object, draw a static panel via F_10ParamForwarder with dimensions read from the entry, center and render the message string when the 'ftim28blk' wide-string node exists, then fill the panel surface; (2) otherwise, if a wide-string node exists at object offset +0x1538, run a ~0.45 s animation loop that draws a progress-scaled grayscale box through DelegationWrapper while elapsed time (QPC) is below 0.45 s, then render the message string centered on a nominal 800-by-600 region.
    // GUARD: Entire body is skipped unless a3 is non-null and strlen(a3) is non-zero [source:raw]
    // CALL: sub_497AD0(a1, aSavingreplay00, 0) looks up the 'saving replay' string entry (global 0x005CCB00) on the object; a non-zero result selects the static-display path [callee:0x00497AD0, global:0x005CCB00, source:raw]
    // CALCULATION: Read static panel dimensions from the found entry: sub-object at entry+12, width at +28 and height at +32 [source:raw]
    // CALL: GlobalAccessor_5150() retrieves the global render context object [callee:0x00495150, source:raw]
    // CALL: F_10ParamForwarder(sub_object, 0, 0, ctx, 0, 274, width, height, 0, 0) forwards the ten render parameters that draw the static saving-replay panel (height literal 274) [callee:0x00494A30, source:raw]
    // CALL: WideStringLinkedListSearch(aFtim28blk) searches the wide-string node list for the 'ftim28blk' token (global 0x005CCAF4); a non-null result enters the caption-positioning sub-path [callee:0x0053D1F0, global:0x005CCAF4, source:raw]
    // CALL: sub_498560(a1 pointer bits, aFtim28blk) consumes the 'ftim28blk' token with the object pointer [callee:0x00498560, global:0x005CCAF4, source:raw]
    // CALL: sub_5531F0(a3, &x, &y, 1) parses the message string into integer/float position outputs used to center the caption [callee:0x005531F0, source:raw]
    // CALCULATION: Caption centered horizontally: x = 400 - parsed_x / 2, with a fixed y of 281 [source:raw]
    // CALL: sub_553070(a3, x, 281, ctx) renders the message string at the centered caption position [callee:0x00553070, source:raw]
    // CALL: sub_495080() yields between render steps (once in the static path, once per animation frame) [callee:0x00495080, source:raw]
    // CALL: Accessor() returns the render-surface pointer, then RenderSurfaceFillCopy(ptr, 0, 274, width, height) fills the static panel background rectangle [callee:0x00490920, callee:0x004918D0, source:raw]
    // GUARD: When no saving-replay entry exists, the animated path is selected only if WideStringLinkedListSearch(a1 + 5432) finds a wide-string node on the object at byte offset +0x1538 [callee:0x0053D1F0, source:raw]
    // CALL: sub_5531F0(a3, &w, &h, 1) parses the message into width/height outputs; v31 = 400 - w/2 and v30 = 300 - h/2 center the animation on a nominal 800-by-600 region [callee:0x005531F0, source:raw]
    // CALL: GlobalAccessor_5150() supplies the render context stored for the animation loop [callee:0x00495150, source:raw]
    // CALL: Timer setup: StructZeroInit_8ba0 clears a 76-byte timer buffer, QPCTimerInitialization(1) primes the QPC subsystem, TimerResetUsingQueryPerformanceCounter resets the elapsed baseline [callee:0x00568BA0, callee:0x00568BE0, callee:0x00568C60, source:raw]
    // LOOP: Animation loop repeats while elapsed <= 0.44999999 s; each iteration re-reads elapsed via PerformanceCounterDiffWithScaling(timer), so the loop runs roughly 0.45 s [callee:0x00568D90, source:raw]
    // CALCULATION: Progress t = clamp(elapsed * 2.2222223, 0, 1); the 2.2222223 multiplier (~1/0.45) normalizes the 0.45 s window into a 0..1 fade, clamped twice into v25 then v16 [source:raw]
    // CALCULATION: Per-frame box geometry: width and height both 8 + trunc(t) via CRTFtol (t clamped to 0..1 so the box is 8 or 9 px), centered at (400 - size/2, 300 - size/2) [callee:0x00587BDC, source:raw]
    // CALCULATION: Packed color word: the truncated progress byte from CRTFtol duplicated across three bytes (low byte plus two 8-bit left shifts, fourth byte zero); with t clamped to 0..1 the packed value is 0 or 1 per byte [callee:0x00587BDC, source:raw]
    // CALL: DelegationWrapper(ctx, x, y, w, h, color) draws the animated box each frame with the progress-derived geometry and color [callee:0x00494BF0, source:raw]
    // CALL: sub_495080() yields between animation frames [callee:0x00495080, source:raw]
    // CALL: After the loop, sub_553070(a3, v31, v30, ctx) renders the message string at the centered animation position [callee:0x00553070, source:raw]
    // CALL: Final sub_495080() yield, then EmptyStub_0170(timer) tears the timer state down [callee:0x00495080, callee:0x004B0170, source:raw]
    // RETURN: Void function; control returns to the caller once either the static or animated path completes [function:0x004989E0, caller:0x00496E90, caller:0x004A0E70]

    // Conservative worker pseudocode:
    //   if (a3 && strlen(a3)) {
    //     entry = sub_497AD0(a1, "saving replay", 0);
    //     if (entry) {
    //       sub_obj = *(entry + 12); w = *(sub_obj + 28); h = *(sub_obj + 32);
    //       ctx = GlobalAccessor_5150();
    //       F_10ParamForwarder(sub_obj, 0, 0, ctx, 0, 274, w, h, 0, 0);
    //       node = WideStringLinkedListSearch("ftim28blk");
    //       sub_498560(a1, "ftim28blk");
    //       if (node) {
    //         parse(a3, &cx, &cy, 1);
    //         sub_553070(a3, 400 - cx/2, 281, ctx);
    //       }
    //       sub_495080();
    //       RenderSurfaceFillCopy(Accessor(), 0, 274, w, h);
    //     } else if (WideStringLinkedListSearch(a1 + 5432)) {
    //       parse(a3, &w2, &h2, 1);
    //       cx = 400 - w2/2; cy = 300 - h2/2;
    //       ctx = GlobalAccessor_5150();
    //       timer = TimerResetAfterZeroInit(1);
    //       do {
    //         elapsed = PerformanceCounterDiffWithScaling(timer);
    //         t = clamp(elapsed * 2.2222223, 0, 1);
    //         size = 8 + trunc(t);
    //         color = trunc(t) replicated into each of the three color bytes;
    //         DelegationWrapper(ctx, 400 - size/2, 300 - size/2, size, size, color);
    //         sub_495080();
    //       } while (elapsed <= 0.44999999);
    //       sub_553070(a3, cx, cy, ctx);
    //       sub_495080();
    //       EmptyStub_0170(timer);
    //     }
    //   }
    // UNRESOLVED: The a2 parameter is declared in the signature but never referenced anywhere in the raw decompiled body
    // UNRESOLVED: v28 = *(float *)&a1 is a decompiler artifact that reinterprets the a1 pointer as a float so sub_498560 receives the raw pointer bits; no floating-point arithmetic is performed on it
    // UNRESOLVED: The progress float is clamped to [0,1] twice (into v25, then again into v16) though the two results are identical; the redundancy appears to be a decompiler artifact
    // UNRESOLVED: Eight read-only globals (flt_59E43C, flt_59E440, flt_59E4DC, flt_59E8FC, flt_59FEC8, flt_5AC9E0, unk_7CDE00, dword_8AFE64) are flagged by packet facts but appear nowhere in the raw decompiled source
    // UNRESOLVED: The literal 274 is used both as the F_10ParamForwarder height and the RenderSurfaceFillCopy rectangle parameter, and 281 is the fixed static caption y; their screen-space meaning is not further evidenced
}
