// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005550E0
// Canonical corpus name: sub_5550E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5550E0_005550e0.c

void UnknownObject::UpdateRenderDisplayState()
{
    // Per-frame render-state dispatcher for a multi-slot graphics display. Resets the session-ID cache (this+0x13CC), reads two field pairs from the camera/audio object a3, one-time-initializes the render context (this+0x1100) via a vtable+200 dispatch guarded by this+0x13C4, and optionally emits a camera-list sub-render when StructFieldGetter(this) is true. Computes a packed RGB blend value from a2+380/384/388 via CRTFtol, writes it to a2+340 and, when it changes, pushes it to the context through vtable+200 (command 60). Then iterates 4 display slots (switch via jpt_55527D), picking per-slot base/count from a2+436..464 and calling ModeStateSetterThroughVtable; for each slot it walks the element groups, runs rich (v14[39]&0x400) and plain element paths that dispatch sprite draw commands through context vtable+340/+284/+200, update camera/sound state (TwoFieldSetterCall, CameraProjectionUpdate, SoundInstanceUpdate), log session changes (LogSessionEvent) when the element ID differs from this+0x13CC, and chain-init display slots. Finishes with a vehicle sync block when the a2+236 bitmask is clean and a2+348 list is non-empty, dispatching command 47 or restoring two fields on a3, and returns the camera update result.
    // ASSIGNMENT: Reset the session/object ID cache: this[1267] (this+0x13CC) = 0. [field:this:0x000013CC, function:0x005550E0, source:raw]
    // CALL: DoubleFieldGetter(a3, &v86, &v84) reads two double/float fields from the camera/audio object into locals used later to restore the projection. [callee:0x00542520, function:0x005550E0, source:raw]
    // CALL: TwoFieldGetter(a3, &v102, &v103) reads a second field pair from a3. [callee:0x005424C0, function:0x005550E0, source:raw]
    // GUARD: guard:0 - one-time render-context init: if this[1265] (this+0x13C4) != 1, set it to 1 and dispatch (vtable+200)(context, 136, 1) on the context at this[1088] (this+0x1100), storing the result in this[0]. [guard:0, field:this:0x000013C4, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // GUARD: If StructFieldGetter(this) (0x0055C9B0) is true and the a2+236 byte-1 bitmask has bit 0x80 clear, enter the vehicle-camera sub-render block. [callee:0x0055C9B0, function:0x005550E0, source:raw]
    // LOOP: Traverse the linked list starting at a2+348 (count guard a2+316 > 0, next link at +52): for each node whose +36 flag has bit 2 set, call sub_560FE0(0, 0). [callee:0x00560FE0, function:0x005550E0, source:raw]
    // CALL: After the camera list walk, CameraProjectionUpdate(a3, 14). [callee:0x00541B70, function:0x005550E0, source:raw]
    // CALL: ResourceFactoryViaVTableDispatch(this, a3, 0) creates/initializes the primary render resource through the context vtable. [callee:0x00554B20, function:0x005550E0, source:raw]
    // CALL: PropertyValueSetterWithRefreshOnChange(this, 0) sets property slot 0 and refreshes the display on change. [callee:0x00554700, function:0x005550E0, source:raw]
    // GUARD: If the a2+236 flag word has bit 0x10000 set, clear it (a2+236 &= 0xFFFEFFFF) and call GraphicsDisplayStateSyncWithVehicle(a2). [callee:0x00556040, function:0x005550E0, source:raw]
    // GUARD: If this[1340] (this+0x14F0) is non-zero, dispatch (vtable+200)(context, 28, 1) to push an extra render state, storing the result in this[0]. [field:this:0x000014F0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // CALCULATION: Compute the packed color blend v9 = CRTFtol(a2+388 * -255.0) - ((CRTFtol(a2+384 * 255.0) + (-256 * CRTFtol(a2+380 * -255.0))) << 8) + 0xFFFFFF and store it at a2+340. [callee:0x00587BDC, function:0x005550E0, source:raw]
    // GUARD: Change-detection: if this[1266] (this+0x13C8) != v9, cache v9 and dispatch (vtable+200)(context, 60, v9), storing the result in this[0]. [field:this:0x000013C8, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // LOOP: Outer loop over the 4 display slots (i = 0..3), dispatched through the switch jump table jpt_55527D. [global:0x00555E40, function:0x005550E0, source:raw]
    // STATE_TRANSITION: Per-slot selection: slot 0 reads base a2+440 / count a2+436; slot 1 reads a2+456 / a2+452; slot 2, when a2+436 + a2+452 > 0, calls ResourceFactoryViaVTableDispatch(this, a3, 1), then uses base a2+448 / count a2+444; slot 3 reads a2+464 / a2+460. Each selected slot goes through ModeStateSetterThroughVtable(this, mode) with mode 1 for slot 0 and mode 0 for slots 1/3. [callee:0x00554BE0, callee:0x00554B20, function:0x005550E0, source:raw]
    // GUARD: If the selected slot count v85 > 0, enter the per-slot element-group processing loop. [function:0x005550E0, source:raw]
    // LOOP: Per-slot element-group loop: iterate v91 = v85 times, advancing the element base v76 and header v81 by 132 per group; each pass loads the group header v14 = *(*(v81+1) + 12). [function:0x005550E0, source:raw]
    // GUARD: When this[1270] (this+0x13D8) is non-zero, copy 17 element values from v14 into the local vector v92 and dispatch (vtable+168)(context, &v92), storing the result in this[0]. [field:this:0x000013D8, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000A8, function:0x005550E0, source:raw]
    // GUARD: Branch on the group header flag: when (v14[39] & 0x400) != 0 run the rich per-element path; otherwise run the plain path. [function:0x005550E0, source:raw]
    // LOOP: Rich path - inner loop over element entries starting at v81[1] (entry stride 4): load v46 = entry[1], v47 = entry[2], v48 = entry[0]. [function:0x005550E0, source:raw]
    // GUARD: When this[1268] (this+0x13D0) is non-zero, dispatch (vtable+200)(context, 23, 2) to enter element-display mode, storing the result in this[0]. [field:this:0x000013D0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // CALL: sub_554790(this, *v76, v80[43], *(v80[42] + 132)) - dispatch the element command through the display mode setter. [callee:0x00554790, function:0x005550E0, source:raw]
    // GUARD: Session change detection: if v48 != this[1267] (this+0x13CC), cache this[1267] = v48 and call LogSessionEvent(v48). [field:this:0x000013CC, callee:0x0054B9E0, function:0x005550E0, source:raw]
    // CALL: Audio path gated on this[1270] (this+0x13D8) and the v50 = *(v48 + 60) flag bit 0x10: when both set, SoundInstanceUpdate(this, v46[67], v46[68]), then dispatch (vtable+200)(context, 137, 1) and (vtable+200)(context, 141, 1 or 0 depending on v46[5] bit 0x400000); when the flag is clear, SoundInstanceUpdate(this, 0, 0) and (vtable+200)(context, 137, 0). When this[1270] is clear but the bit is set, sub_55D720(a3, 1) instead. [field:this:0x000013D8, callee:0x00541810, callee:0x0055D720, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // CALL: PropertyValueSetterWithRefreshOnChange(this, *(v47 + 28)) - set the element's property value and refresh on change. [callee:0x00554700, function:0x005550E0, source:raw]
    // LOOP: Per-sub-element loop (counters v52/j, bounded by the group count v80[41] and this[1260] (this+0x13B0) max): IndexedArrayLookupWithBoundsCheck(v80, *(v89 + 52), v52); when sub_554F80(this, a2, v54) accepts the element, store v54 into slot v75[11] and MultiFieldSetterDispatchingTo7SubSetters; afterward StateFieldSetWithChainedInit seals the slot. [callee:0x005504D0, callee:0x00554F80, callee:0x005546A0, callee:0x00553FA0, field:this:0x000013B0, function:0x005550E0, source:raw]
    // GUARD: When v88[63] <= 4, TwoFieldSetterCall(a3, 1065353216, 1176256512) followed by CameraProjectionUpdate(a3, 4) - restore default projection for the element. [callee:0x005423C0, callee:0x00541B70, function:0x005550E0, source:raw]
    // CALL: Dispatch (vtable+340)(context, *(*(v47 + 36) + 24), *(v47 + 44)) to draw the element, storing the result in this[0]. [field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x00000154, function:0x005550E0, source:raw]
    // CALCULATION: Camera draw dispatch via (vtable+284)(context, mode, 0, *(v47 + 8), *(v47 + 48), stride): mode 5 with stride v58 - 2 when v88[5] byte-1 bit 0x80 is clear, else mode 4 with stride v58 / 3; result stored in this[0]. [field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x0000011C, function:0x005550E0, source:raw]
    // CALL: When v88[63] <= 4, TwoFieldSetterCall(v57, v86, v84) followed by CameraProjectionUpdate(v57, 4) to restore the projection fields read at the top. [callee:0x005423C0, callee:0x00541B70, function:0x005550E0, source:raw]
    // GUARD: Termination/finalize in the rich path: if this[1268] (this+0x13D0) is set, break the sub-element loop; otherwise evaluate v60 = v76[16*v52 + 9] and, when it is 4 or 2, dispatch sub_554790(this, *v76 | 0x800, 65545 or 131074, 0); then dispatch (vtable+200)(context, 23, 4). [field:this:0x000013D0, callee:0x00554790, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // LOOP: Plain path (v14[39] & 0x400) == 0: sub_554790(this, *v76, v14[43], *(v14[42] + 132)), then loop v32 = v14[41] times over sub-elements (IndexedArrayLookupWithBoundsCheck(v80, 0, v15), sub_554F80 gate, MultiFieldSetterDispatchingTo7SubSetters or StateFieldSetWithChainedInit), followed by a per-entry pass identical to the rich path: default projection restore, LogSessionEvent on ID change, the SoundInstanceUpdate/137/141 audio path, PropertyValueSetterWithRefreshOnChange, (vtable+340)/(vtable+284) draw dispatches, optional (vtable+200)(context, 23, 4)/(8, 2)/(8, 3) commands when v35[5] bit 0x800 is set, final sub_554790(this, *v76 | 0x800, 65545, 0) and (vtable+200)(context, 23, 4) after each pass. [callee:0x00554790, callee:0x005504D0, callee:0x00554F80, callee:0x005546A0, callee:0x00553FA0, callee:0x005423C0, callee:0x00541B70, callee:0x0054B9E0, callee:0x00541810, callee:0x0055D720, callee:0x00554700, field:this:0x000013CC, field:this:0x000013D0, field:this:0x000013D8, field:this:0x000013B0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x00000154, field:*(this+0x1100):0x0000011C, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // GUARD: After the per-slot loop, when this[1268] (this+0x13D0) is set, dispatch (vtable+200)(context, 23, 2) to re-enter element-display mode, storing the result in this[0]. [field:this:0x000013D0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // GUARD: After the 4-slot loop, when this[1340] (this+0x14F0) is non-zero, dispatch (vtable+200)(context, 28, 0) to pop the extra render state, storing the result in this[0]. [field:this:0x000014F0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // GUARD: Vehicle sync block: enter only when (BYTE1(a2+236) & 0x80) == 0, a2+348 != 0 and a2+316 > 0. [function:0x005550E0, source:raw]
    // GUARD: Mode branch: when this[1258] (this+0x13A8) bit 0x100 is set dispatch (vtable+200)(context, 47, 1); otherwise compute v71 = v84 * 0.15000001 + v84 and call TwoFieldSetterCall(a3, v86, v71). [field:this:0x000013A8, callee:0x005423C0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // CALL: Dispatch (vtable+200)(context, 23, 4) then chain-init three display state slots with StateFieldSetWithChainedInit using ids 1, 2, 3. [callee:0x00553FA0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // LOOP: Vehicle list walk from a2+348 (next link +52): for nodes with flag & 2 set, when !StructFieldGetter(this) call sub_560FE0(0, 0) and, if flag bit 8 is also set, CameraProjectionUpdate(a3, 14); when flag bit 8 is set, clear it (k+36 &= 0xFFFFFFF7) and, if sub_554F80(this, a2, *(k+16)) accepts, run the element (re)init: StructInitWithDefaultValues(v92), set sentinel values (12/2/car/1/1), MultiFieldSetterDispatchingTo7SubSetters(this+1118, v92, 0), sub_554790(this, 2304, 262145, 0), sub_5613E0(k), dispatch (vtable+148)(context, 256, this + 1283), reset this[1267] (this+0x13CC) = 0, and when *(k+4) is non-zero PropertyValueSetterWithRefreshOnChange(this, this[1107] + 36*this[1106]) plus (vtable+280)(context, 4, 0, *(k+4) / 3). [callee:0x0055C9B0, callee:0x00560FE0, callee:0x00541B70, callee:0x00554F80, callee:0x00553DB0, callee:0x005546A0, callee:0x00554790, callee:0x005613E0, callee:0x00554700, field:this:0x000013CC, field:this:0x00001148, field:this:0x0000114C, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x00000094, field:*(this+0x1100):0x00000118, function:0x005550E0, source:raw]
    // CALL: Close the vehicle sync block: dispatch (vtable+200)(context, 23, 2); then, when this[1258] (this+0x13A8) bit 0x100 is set, dispatch (vtable+200)(context, 47, 0), otherwise TwoFieldSetterCall(a3, v86, v84). [field:this:0x000013A8, callee:0x005423C0, field:this:0x00001100, field:this:0x00000000, field:*(this+0x1100):0x000000C8, function:0x005550E0, source:raw]
    // RETURN: Return the result of CameraProjectionUpdate(a3, 14). [callee:0x00541B70, function:0x005550E0, source:raw]

    // Conservative worker pseudocode:
    //   this->sessionId = 0;                       // this+0x13CC
    //   DoubleFieldGetter(a3, &twoA, &twoB);       // save projection pair
    //   TwoFieldGetter(a3, &dummy1, &dummy2);
    //   if (this->initGuard != 1) {                // this+0x13C4
    //     this->initGuard = 1;
    //     this[0] = ctxVtbl200(this->ctx, 136, 1); // one-time context init
    //   }
    //   if (StructFieldGetter(this) && !(byte1(a2[+236]) & 0x80)) {
    //     for (n = a2[+348]; n && a2[+316] > 0; n = n[+52])
    //       if (n[+36] & 2) sub_560FE0(0, 0);
    //     CameraProjectionUpdate(a3, 14);
    //   }
    //   ResourceFactoryViaVTableDispatch(this, a3, 0);
    //   PropertyValueSetterWithRefreshOnChange(this, 0);
    //   if (a2[+236] & 0x10000) { a2[+236] &= 0xFFFEFFFF; GraphicsDisplayStateSyncWithVehicle(a2); }
    //   if (this[+0x14F0]) this[0] = ctxVtbl200(this->ctx, 28, 1);
    //   blend = CRTFtol(a2[+388] * -255.0)
    //           - ((CRTFtol(a2[+384] * 255.0) + (-256 * CRTFtol(a2[+380] * -255.0))) << 8)
    //           + 0xFFFFFF;
    //   a2[+340] = blend;
    //   if (this->blendCache != blend) { this->blendCache = blend; this[0] = ctxVtbl200(this->ctx, 60, blend); }
    //   for (i = 0; i < 4; i++) {                 // 4 display slots (jpt_55527D switch)
    //     switch (i) {
    //       case 0: base = a2[+440]; cnt = a2[+436]; mode = 1; break;
    //       case 1: base = a2[+456]; cnt = a2[+452]; mode = 0; break;
    //       case 2: if (a2[+436] + a2[+452] > 0) ResourceFactoryViaVTableDispatch(this, a3, 1);
    //               base = a2[+448]; cnt = a2[+444]; mode = 1; break;
    //       case 3: base = a2[+464]; cnt = a2[+460]; mode = 0; break;
    //     }
    //     ModeStateSetterThroughVtable(this, mode);
    //     if (cnt <= 0) continue;
    //     for (slot = 0; slot < cnt; slot++, base += 132, hdr += 132) {
    //       v14 = *(*(hdr + 1) + 12);            // group header
    //       if (this[+0x13D8]) { copy v14[17..31] into v92; this[0] = ctxVtbl168(this->ctx, &v92); }
    //       if (v14[39] & 0x400) {
    //         for (entry = hdr[1]; entries) {
    //           if (this[+0x13D0]) this[0] = ctxVtbl200(this->ctx, 23, 2);
    //           sub_554790(this, *base, v14[43], *(v14[42] + 132));
    //           if (v48 != this->sessionId) { this->sessionId = v48; LogSessionEvent(v48); }
    //           playAudio(this, v46, v50);      // SoundInstanceUpdate + 137/141 commands or sub_55D720
    //           PropertyValueSetterWithRefreshOnChange(this, *(v47 + 28));
    //           for (j = 0; j < v14[41] && j < this[+0x13B0]; j++) {
    //             v54 = IndexedArrayLookupWithBoundsCheck(v80, *(v89 + 52), j);
    //             if (sub_554F80(this, a2, v54)) { slot[11] = v54; MultiFieldSetter(v77, slot, j); }
    //           }
    //           StateFieldSetWithChainedInit(slotChain, j);
    //           if (v88[63] <= 4) { TwoFieldSetterCall(a3, 1.0f, 15.0f); CameraProjectionUpdate(a3, 4); }
    //           this[0] = ctxVtbl340(this->ctx, *(*(v47+36)+24), *(v47+44));
    //           this[0] = ctxVtbl284(this->ctx, mode5or4, 0, *(v47+8), *(v47+48), stride);
    //           if (v88[63] <= 4) { TwoFieldSetterCall(a3, twoA, twoB); CameraProjectionUpdate(a3, 4); }
    //           if (!this[+0x13D0]) break;
    //           switch (v76[16*v52+9]) { case 4: sub_554790(this, *base|0x800, 65545, 0); break;
    //                                    case 2: sub_554790(this, *base|0x800, 131074, 0); break; }
    //           this[0] = ctxVtbl200(this->ctx, 23, 4);
    //         }
    //       } else {
    //         sub_554790(this, *base, v14[43], *(v14[42] + 132));
    //         for (m = 0; m < v14[41]; ) {
    //           ... same sub-element fill + per-entry audio/draw pass ...
    //           if (!this[+0x13D0]) goto done;
    //           sub_554790(this, *base|0x800, 65545, 0);
    //           this[0] = ctxVtbl200(this->ctx, 23, 4);
    //         }
    //       }
    //       if (this[+0x13D0]) this[0] = ctxVtbl200(this->ctx, 23, 2);
    //     }
    //   }
    //   if (this[+0x14F0]) this[0] = ctxVtbl200(this->ctx, 28, 0);
    //   if (!(byte1(a2[+236]) & 0x80) && a2[+348] && a2[+316] > 0) {
    //     if (this[+0x13A8] & 0x100) this[0] = ctxVtbl200(this->ctx, 47, 1);
    //     else TwoFieldSetterCall(a3, v86, v84 * 0.15000001f + v84);
    //     this[0] = ctxVtbl200(this->ctx, 23, 4);
    //     StateFieldSetWithChainedInit(this + 1135, 1);
    //     StateFieldSetWithChainedInit(this + 1152, 2);
    //     StateFieldSetWithChainedInit(this + 1169, 3);
    //     for (k = a2[+348]; k; k = k[+52]) {
    //       if (k[+36] & 2) {
    //         if (!StructFieldGetter(this)) {
    //           sub_560FE0(0, 0);
    //           if (k[+36] & 8) CameraProjectionUpdate(a3, 14);
    //         }
    //         if (k[+36] & 8) {
    //           k[+36] &= 0xFFFFFFF7;
    //           if (sub_554F80(this, a2, *(k+16))) {
    //             StructInitWithDefaultValues(v92);
    //             v92[1..4] = { 12, 2, *(k+16), 1 };  v92[5] = 1;
    //             MultiFieldSetter(this + 1118, v92, 0);
    //             sub_554790(this, 2304, 262145, 0);
    //             sub_5613E0(k);
    //             this[0] = ctxVtbl148(this->ctx, 256, this + 1283);
    //             this->sessionId = 0;
    //             if (*(k+4)) {
    //               PropertyValueSetterWithRefreshOnChange(this, this[+0x114C] + 36 * this[+0x1148]);
    //               this[0] = ctxVtbl280(this->ctx, 4, 0, *(k+4) / 3);
    //             }
    //           }
    //         }
    //       }
    //     }
    //     this[0] = ctxVtbl200(this->ctx, 23, 2);
    //     if (this[+0x13A8] & 0x100) this[0] = ctxVtbl200(this->ctx, 47, 0);
    //     else TwoFieldSetterCall(a3, v86, v84);
    //   }
    //   return CameraProjectionUpdate(a3, 14);
    // UNRESOLVED: The owning class of this render-display dispatcher is unidentified; the packet lists owner type UnknownObject with UNKNOWN trust.
    // UNRESOLVED: Globals flt_59E868, flt_59FEC8 and flt_5B8980 are listed as read by this function but do not appear in the raw source text; they may be used inside the callees.
    // UNRESOLVED: The display slot element arrays (base pointers at a2+440/448/456/464 and group headers at a2+444/452/460) and the element-group structs (v14 at *(*hdr+1)+12 with fields at +39/+41/+42/+43) have no identified concrete types; sub-element slot chains (this+1118 onward, stride 17) are evidenced only in the raw source.
    // UNRESOLVED: The two known callers (SceneRenderTransform 0x00548C20, sub_556E70 0x00556E70) provide no additional ownership signal.
    // UNRESOLVED: The vtable dispatch indices (148/168/200/280/284/340) map to context command slots whose runtime meanings are not established by this packet.
}
