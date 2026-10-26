// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051BAD1
// Canonical corpus name: FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT_0051bad1.c

void UnknownObject::AudioProcessingModeDispatch()
{
    // Per-object audio-processing dispatch. For each descriptor in the array at this+0xC4, selects a processing routine from the mode field: AudioSampleLookup (1), AudioFIRConvolutionFilter (2), FixedPointIDCT (4), or, for mode 8, a render-variant branch (RenderModeBranch, AudioMixing, or RenderingBranchOnDAT005d79dc selected by this+0x44). Writes the chosen routine pointer to the per-object output slot and, when the element flag permits and the stored mode differs, transforms the source buffer into the destination (plain word copy, FIR-style fixed-point pass, or double-precision convolution). Unsupported modes raise errors 6 and 47 through the error object.
    // GUARD: Skip processing entirely when the object count at this+0x20 is zero or negative. [guard:0, field:this:0x00000020, source:raw]
    // CALCULATION: Load the dispatch state from this+0x198 and the per-object mode field at this+0xE8. [field:this:0x00000198, field:this:0x000000E8, source:raw]
    // LOOP: Iterate the descriptor array at this+0xC4, stepping 84 bytes per object. [field:this:0x000000C4, source:raw]
    // STATE_TRANSITION: Mode 1 selects AudioSampleLookup. [guard:2, global:0x0052851D, source:raw]
    // STATE_TRANSITION: Mode 2 selects AudioFIRConvolutionFilter. [guard:3, global:0x0052835F, source:raw]
    // STATE_TRANSITION: Mode 4 selects FixedPointIDCT. [guard:4, global:0x0052804A, source:raw]
    // GUARD: Mode not 8 (and not 1/2/4): write error code 6 and the offending mode to obj+0x14 and obj+0x18, then dispatch through the obj vtable. [guard:1, field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000018, field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Mode 8 branches on this+0x44: zero selects RenderingBranchOnDAT005d79dc with counter 0, 1 selects RenderModeBranch with counter 1, 2 selects AudioMixing with counter 2, otherwise writes error code 47. [field:this:0x00000044, global:0x0052855A, global:0x005285A6, global:0x005285F2, field:obj:0x00000014, source:raw]
    // ASSIGNMENT: Write the selected routine pointer to the per-object output slot. [field:*(this+0x114):0x00000000, source:raw]
    // GUARD: If the flag byte at this+0xF4 is set and the stored mode at this+0x1C4 differs from the selected counter, run the buffer transformation. [field:this:0x000000F4, field:this:0x000001C4, source:raw]
    // LOOP: Counter 1: FIR-style fixed-point pass accumulating (word * word + 2048) >> 12 into 16-bit destinations, using source and destination pointers from this+0x110 and this+0x114, bounded by word_5B0588 with unk_5B0508 as the base. [field:this:0x00000110, field:this:0x00000114, global:0x005B0508, global:0x005B0588, source:raw]
    // LOOP: Counter 2: double-precision convolution accumulating scaled products of unsigned 16-bit source values against the dbl_5B05C8 coefficient tables into float destinations, bounded by dbl_5B05C8. [field:this:0x00000110, field:this:0x00000114, global:0x005B05C8, global:0x005B0588, source:raw]
    // ASSIGNMENT: Counter 0: plain word copy of 64 words from the source pointer (this+0x110) to the destination pointer (this+0x114). [field:this:0x00000110, field:this:0x00000114, source:raw]
    // RETURN: Return after all objects are processed. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_51BAD1(int this) {
    //     int* state = this->pState;
    //     if (this->count <= 0) return state;
    //     for (i = 0; i < this->count; ++i) {
    //       // mode = elem->mode (1 lookup, 2 fir, 4 idct, 8 render-variant)
    //       outSlot = selected_routine;
    //       if (elem->flag && state->mode != counter)
    //         transform(src, dst, counter); // copy | fixed-point | double-convolution
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The actual audio/render identities behind the corpus-labeled routine pointers (AudioSampleLookup, AudioFIRConvolutionFilter, FixedPointIDCT, RenderModeBranch, AudioMixing, RenderingBranchOnDAT005d79dc) are corpus labels, not runtime-proven behavior.
    // UNRESOLVED: The global buffers unk_5B0508, word_5B0588, and dbl_5B05C8 act as data or loop-boundary bases; their concrete allocation and meaning are unresolved.
    // UNRESOLVED: No static callers are recorded, so the entry path and concrete object type are unknown.
    // UNRESOLVED: The classification of this+0xE8-derived mode field and the render-variant selector at this+0x44 rest on the corpus field naming.
}
