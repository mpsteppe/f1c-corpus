// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FBD70
// Canonical corpus name: CameraViewportRenderSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CameraViewportRenderSetup_004fbd70.c

void UnknownObject::CameraViewportRenderSetup()
{
    // Camera viewport render setup. Detects a session-type change (cached this+0x44 vs global dword_7C56A4) and runs the change handler sub_4FC550; refreshes a per-frame global computation and pulls three camera fields; re-centers the primary viewport (this+0x4/+0x8/+0xC) and three sub-viewport entries (16-byte stride from this+0x18) through ThreeFieldSetterWithSubCall; tracks a fade-state change against flt_8AFEC8. Two passes then update pit-crew animation offsets (primary this+0x70 area, secondary this+0xA4 area) scaled by dbl_8AFE98, and compute per-element alpha blends from a gradient range (this+0xB0 vs this+0xB4), packing the alpha into the top byte of each list element and flushing via OffsetDispatch.
    // GUARD: Session-type change detection: when the cached session id this+0x44 equals the current global dword_7C56A4, reset the cache to -1 and run the change handler sub_4FC550(0) [field:this:0x00000044, global:0x007C56A4, callee:0x004FC550, source:raw]
    // CALL: ShortComputation_c910(&dword_5EA510) refreshes the global computation value, then TripleFieldGetter_2460(&v37,&v38,&v39) pulls the three per-frame camera fields used to re-center viewports [callee:0x0040C910, callee:0x00542460, global:0x005EA510, source:raw]
    // GUARD: Primary viewport active when this+0x0 is non-zero: compute the X/Z re-centering deltas from viewport positions this+0x4 and this+0xC minus the getter outputs scaled by flt_7CF950, then push all three components (including this+0x8) through ThreeFieldSetterWithSubCall [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, global:0x007CF950, callee:0x0054B3B0, source:raw]
    // LOOP: Three sub-viewport entries at 16-byte stride starting at this+0x18: each entry whose enable word is non-zero has its offset float (this+0x18) minus the getter Y output passed together with the neighbor field this+0x1C into ThreeFieldSetterWithSubCall [field:this:0x00000018, field:this:0x0000001C, callee:0x0054B3B0, source:raw]
    // ASSIGNMENT: Fade-state change tracking: if the cached value this+0xB8 already equals flt_8AFEC8 set the change flag to 0, otherwise set the flag to 1 and refresh this+0xB8 from the global [field:this:0x000000B8, global:0x008AFEC8, source:raw]
    // LOOP: Primary viewport pass over this+0x48 viewports: when the pit-crew animation handle at this+0x70 is live and its offset floats this+0x74 / this+0x78 are non-zero, scale them by dbl_8AFE98 and forward to PitCrewAnimationOffsetUpdate [field:this:0x00000048, field:this:0x00000070, field:this:0x00000074, field:this:0x00000078, global:0x008AFE98, callee:0x0054BF60, source:raw]
    // CALCULATION: Fade factor derivation: with the render-state list from LinkedListIndexedAccessor_c230(0) and the fade-change flag set, compute v8 = 1.0 - flt_8AFEC8, clamped to 1.0 at 0.5 and doubled below it [callee:0x0054C230, global:0x008AFEC8, source:raw]
    // CALCULATION: Alpha byte v32 = CRTFtol(v8 * 254.0 + 0.5) << 24: convert the fade factor into an 8-bit alpha packed into the top byte of a dword [callee:0x00587BDC, source:raw]
    // CALL: FlagFieldBitManipulation sets the render-flag state for the derived alpha: (1,1,1,0) when the alpha byte is non-zero, else (0,0,1,0) [callee:0x0054C030, source:raw]
    // LOOP: Apply alpha to the packed array: iterate PackedArrayTotalSize(v6) entries via PackedArrayIndexLookup, clearing byte+27 on each and OR-ing the alpha dword into +24; then OffsetDispatch(0,0,0) flushes and bit 0x10000000 is cleared at +20 of the list [callee:0x0054E100, callee:0x0054E120, callee:0x0054B3F0, source:raw]
    // LOOP: Secondary viewport pass over this+0x7C entries: when the pit-crew animation handle at this+0xA4 is live and its offset floats this+0xA8 / this+0xAC are non-zero, scale them by dbl_8AFE98 and forward to PitCrewAnimationOffsetUpdate [field:this:0x0000007C, field:this:0x000000A4, field:this:0x000000A8, field:this:0x000000AC, global:0x008AFE98, callee:0x0054BF60, source:raw]
    // GUARD: Gradient window: only when the upper bound this+0xB0 is greater than the lower bound this+0xB4 is the alpha ramp computed, with reciprocal spread v34 = 1.0 / (this+0xB0 - this+0xB4) [field:this:0x000000B0, field:this:0x000000B4, source:raw]
    // CALCULATION: Ramp mapping: re-read the render-state list via LinkedListIndexedAccessor_c230(0); when the fade-change flag is set the factor v16 starts from flt_8AFEC8, is doubled (and offset by -1.0) when byte_7CF938 is set, else v31 = flt_8AFEC8, yielding the ramp v35 = v16 - v31 [callee:0x0054C230, global:0x007CF938, global:0x008AFEC8, source:raw]
    // CALL: FlagFieldBitManipulation flags the ramp direction: (1,1,1,0) when v16 or v31 is positive, else (0,0,1,0) [callee:0x0054C030, source:raw]
    // LOOP: Per-element alpha: for PackedArrayTotalSize(v15) entries from PackedArrayIndexLookup, map (element float - this+0xB4) * v34 * v35 + v31, clamp to [0,254] via CRTFtol, clear byte+27, and OR the alpha into +24 of each element [callee:0x0054E100, callee:0x0054E120, callee:0x00587BDC, field:this:0x000000B4, source:raw]
    // CALL: OffsetDispatch(0,0,0) flushes the alpha updates and bit 0x10000000 is cleared at +20 of the secondary list [callee:0x0054B3F0, source:raw]
    // RETURN: Return this[31] (the secondary viewport count at this+0x7C); this function is the camera viewport render setup called by RenderScreenSave (004B40A0) [field:this:0x0000007C, caller:0x004B40A0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0x44] == dword_7C56A4) { this[0x44] = -1; sub_4FC550(0); }
    //   ShortComputation_c910(&dword_5EA510); TripleFieldGetter_2460(&fx, &fy, &fz);
    //   if (this[0x0]) ThreeFieldSetterWithSubCall(this[0x4] - fx*flt_7CF950, this[0x8], this[0xC] - fz*flt_7CF950);
    //   for (3 sub-viewport entries, 16-byte stride from this+0x18):
    //     if (entry.enable) ThreeFieldSetterWithSubCall(entry.arg, entry.off - fy, entry.arg2);
    //   changed = (this[0xB8] == flt_8AFEC8) ? 0 : (this[0xB8] = flt_8AFEC8, 1);
    //   for (i = 0; i < this[0x48]; ++i):
    //     if (this[0x70] && (this[0x74] != 0.0f || this[0x78] != 0.0f))
    //       PitCrewAnimationOffsetUpdate(this[0x70], 0, dbl_8AFE98*this[0x74], dbl_8AFE98*this[0x78]);
    //     if (changed && (v6 = LinkedListIndexedAccessor_c230(0))) {
    //       v8 = max(1.0 - flt_8AFEC8, 0.5) == 1.0 ? 1.0 : 2.0*(1.0 - flt_8AFEC8);
    //       alpha = CRTFtol(v8*254.0 + 0.5) << 24;
    //       FlagFieldBitManipulation(alpha ? 1:0, 1, 1, 0);
    //       for (j = 0; j < PackedArrayTotalSize(v6); ++j):
    //         e = PackedArrayIndexLookup(j); *(byte*)(e+27) = 0; *(dword*)(e+24) |= alpha;
    //       OffsetDispatch(0,0,0); *(dword*)(v6+20) &= ~0x10000000;
    //     }
    //   for (k = 0; k < this[0x7C]; ++k):
    //     if (this[0xA4] && (this[0xA8] != 0.0f || this[0xAC] != 0.0f))
    //       PitCrewAnimationOffsetUpdate(this[0xA4], 0, dbl_8AFE98*this[0xA8], dbl_8AFE98*this[0xAC]);
    //     if (this[0xB0] > this[0xB4]):
    //       inv = 1.0 / (this[0xB0] - this[0xB4]);
    //       if (changed && (v15 = LinkedListIndexedAccessor_c230(0))) {
    //         v16 = flt_8AFEC8; v31 = (byte_7CF938 ? (v16 = 2.0*flt_8AFEC8, v16 - 1.0) : flt_8AFEC8);
    //         ramp = v16 - v31;
    //         FlagFieldBitManipulation((v16>0 || v31>0) ? 1:0, 1, 1, 0);
    //         for (n = 0; n < PackedArrayTotalSize(v15); ++n):
    //           e = PackedArrayIndexLookup(n);
    //           t = (*(float*)e - this[0xB4]) * inv * ramp + v31;
    //           a = t > 1.0 ? 254 : (t < 0.0 ? 0 : CRTFtol(t*254.0 + 0.5));
    //           *(byte*)(e+27) = 0; *(dword*)(e+24) |= a << 24;
    //         OffsetDispatch(0,0,0); *(dword*)(v15+20) &= ~0x10000000;
    //       }
    //   return this[0x7C];
    // UNRESOLVED: Four read-only globals flagged by packet facts (flt_59E43C, flt_59E440, flt_59E450, flt_5ACEC4) appear nowhere in the raw decompiled source; they may be reached through the called helpers but cannot be located in this function body
    // UNRESOLVED: The sub-viewport entry walk reads enable and argument words adjacent to the recorded fields this+0x18 / this+0x1C; those neighbor offsets are not in the packet field set
    // UNRESOLVED: The exact meaning of flag calls FlagFieldBitManipulation(1/0,1,1,0) and the 0x10000000 bit at list +20 is resolved only at the callee level
}
