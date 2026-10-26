// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553070
// Canonical corpus name: sub_553070
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_553070_00553070.c

void UnknownObject::FontStringRender()
{
    // Renders a text string character by character through the per-glyph step sub_552910, which accumulates an advance into the in/out cursor a3. When the this+0x24 flags have bit 0x20000 set it takes a hardware path: it derives a byte count from the string length, locks a vertex buffer through BufferLockAllocate (reusing the current buffer at this+0x8 when it fits within 768 bytes, otherwise resetting the offset and reallocating), stores the buffer pointer at this+0x10, renders each character, finalizes via ArithmeticComparison_0f90, and configures the buffer with AudioBufferFormatSetup using the font texture this+0x868 and render-state fields this+0x4C/+0x50/+0x58; VTableGetterWrapper/VTableDispatchGetter wrap the format step when dword_8B8DF0 is clear. When bit 0x20000 is clear it takes a direct software path that renders the characters through sub_552910 with no buffer setup.
    // GUARD: The function body only runs when the input string a2 is non-empty. [source:raw]
    // GUARD: Branch on flags this+0x24: bit 0x20000 selects the hardware vertex-buffer path; when clear, a direct software render path is taken. [field:this:0x00000024, source:raw]
    // CALCULATION: Measure the string length with a null-character scan (v8 ends at -(len + 2)) and derive the vertex-buffer byte count: 3 vertices per character, byte count = 2 * (3 * len). [source:raw]
    // GUARD: Fit check: when the derived byte count is <= 768 minus the current write offset this+0x8, the existing buffer is reused. [field:this:0x00000008, source:raw]
    // CALL: BufferLockAllocate(dword_8B78A0, this+0xC descriptor, 32, this+0x8 write offset, byte count) locks the region of the existing vertex buffer. [callee:0x00540F00, global:0x008B78A0, field:this:0x0000000C, field:this:0x00000008, source:raw]
    // CALL: Overflow path: the write offset this+0x8 is reset to 0 and the buffer is reallocated via BufferLockAllocate(dword_8B78A0, this+0xC descriptor, 96, 0, byte count). [callee:0x00540F00, global:0x008B78A0, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Store the buffer pointer returned by BufferLockAllocate at this+0x10. [field:this:0x00000010, callee:0x00540F00, source:raw]
    // GUARD: Character rendering and buffer finalization only run when the buffer pointer this+0x10 is non-null. [field:this:0x00000010, source:raw]
    // LOOP: Per-character loop over a2: a3 accumulates the advance returned by sub_552910(this, a2[v15], a3, a4, a5) for each character. [callee:0x00552910, source:raw]
    // CALL: ArithmeticComparison_0f90(dword_8B78A0, this+0xC descriptor) finalizes the locked vertex-buffer region after character rendering. [callee:0x00540F90, global:0x008B78A0, field:this:0x0000000C, source:raw]
    // GUARD: When dword_8B8DF0 is clear, VTableGetterWrapper(dword_8B78A0) is invoked before the buffer format call. [global:0x008B8DF0, callee:0x005550A0, global:0x008B78A0, source:raw]
    // CALL: AudioBufferFormatSetup(dword_8B78A0, dword_8B8F28, this+0xC descriptor, i, v19, this+0x868, this+0x4C, this+0x50, this+0x58, 0) configures the buffer with the font texture and render-state fields. [callee:0x00541120, global:0x008B78A0, global:0x008B8F28, field:this:0x0000000C, field:this:0x00000868, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000058, source:raw]
    // GUARD: When dword_8B8DF0 is clear, VTableDispatchGetter(dword_8B78A0) is invoked after the buffer format call. [global:0x008B8DF0, callee:0x005550C0, global:0x008B78A0, source:raw]
    // STATE_TRANSITION: Software path: after the length scan, when the guard -v8 != 2 holds (string is non-empty), each character is rendered directly through sub_552910 with no vertex-buffer setup. [callee:0x00552910, source:raw]

    // Conservative worker pseudocode:
    //   if (*a2 == 0) return;
    //   flags = this[9];                         // this+0x24
    //   if (flags & 0x20000) {
    //       len = strlen(a2); bytes = 2 * (3 * len);
    //       if (bytes <= 768 - this[2])
    //           buf = BufferLockAllocate(g, this[3], 32, this[2], bytes);
    //       else { this[2] = 0; buf = BufferLockAllocate(g, this[3], 96, 0, bytes); }
    //       this[4] = buf;
    //       if (buf) {
    //           for (ch = 0; ch < strlen(a2); ++ch)
    //               a3 += sub_552910(this, a2[ch], a3, a4, a5);
    //           ArithmeticComparison_0f90(g, this[3]);
    //           if (!dword_8B8DF0) VTableGetterWrapper(g);
    //           AudioBufferFormatSetup(g, dword_8B8F28, this[3], i, v19, this[538], this[19], this[20], this[22], 0);
    //           if (!dword_8B8DF0) VTableDispatchGetter(g);
    //       }
    //   } else {
    //       // length scan duplicated by the compiler; then direct software render:
    //       if (string non-empty)
    //           do { a3 += sub_552910(this, a2[v16++], a3, a4, a5); } while (v16 < strlen(a2));
    //   }
    //   // g = dword_8B78A0
    // UNRESOLVED: The meaning of the flags bits at this+0x24 beyond 0x20000 and the exact semantics of the render-state fields this+0x4C/+0x50/+0x58 as passed to AudioBufferFormatSetup are not defined in this function.
    // UNRESOLVED: sub_552910 is a per-character glyph step; the claim that its return advances the cursor a3 is inferred from the accumulation pattern only.
    // UNRESOLVED: The two identical null-character length scans (one per branch) are compiler duplication; both measure a2.
}
